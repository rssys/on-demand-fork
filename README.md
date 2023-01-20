On-demand-fork
------------

On-demand-fork (ODF) is a fast implementation of the fork system call specifically designed for applications with large memory footprints and a requirement for low fork latency.

ODF improves the latency of fork by deferring the work of copying page tables to the page fault handler, and increases efficiency of fork by selectively copying page tables on-demand.

The On-demand-fork paper is published at EuroSys 2021 as:

> **On-Demand-Fork: A Microsecond Fork for Memory-Intensive and Latency-Sensitive Applications**\
Kaiyang Zhao, Sishuai Gong, and Pedro Fonseca.

You can find the paper at this [link](https://doi.org/10.1145/3447786.3456258). The BibTex citation of the work is
```
@inproceedings{10.1145/3447786.3456258,
author = {Zhao, Kaiyang and Gong, Sishuai and Fonseca, Pedro},
title = {On-Demand-Fork: A Microsecond Fork for Memory-Intensive and Latency-Sensitive Applications},
year = {2021},
isbn = {9781450383349},
publisher = {Association for Computing Machinery},
address = {New York, NY, USA},
url = {https://doi.org/10.1145/3447786.3456258},
doi = {10.1145/3447786.3456258},
booktitle = {Proceedings of the Sixteenth European Conference on Computer Systems},
pages = {540–555},
numpages = {16},
location = {Online Event, United Kingdom},
series = {EuroSys '21}
}
```

### Version
This branch is **the patch set version**. For the paper version please see the [link](https://github.com/rssys/on-demand-fork/tree/main). The following is the difference from the paper version.

- **Last-Level Page Table Lifecycle.**
    - If the shared PTE table's refcount is one, the process that triggers the fault will reuse the shared PTE table. Otherwise, the process will decrease the refcount, copy the information to a new PTE table or dereference all the information and change the owner if it has the shared PTE table.
- **Process Memory state and The Last-level Page Table Sharing.**
    - To handle the page table state of each process that has a shared PTE table, the patch introduces the concept of COW PTE table ownership. This implementation uses the address of the PMD index to track the ownership of the PTE table. This helps maintain the state of the COW PTE tables, such as the RSS and pgtable_bytes.
    - Some PTE tables (e.g., pinned pages that reside in the table) still need to be copied immediately for consistency with the current COW logic. As a result, a flag, COW_PTE_OWNER_EXCLUSIVE, indicating whether a PTE table is exclusive (i.e., only one task owns it at a time), is added to the table’s owner pointer. Every time a PTE table is copied during the fork, the owner pointer (and thus the exclusive flag) will be checked to determine whether the PTE table can be shared across processes.
    - Because the fork uses the Virtual-Memory-Area (VMA) to traverse the page tables and the VMA may overlap the multiple last-level page tables (PTE tables). In such a situation, One PTE table might have multiple VMAs. And, since the fork uses the VMA to traverse the page table, the fork may do COW multiple times on the same PTE. The shareable range of PTE of the paper version is restricted by the virtual address space, which means that PTE fully covered by the single VMA can be shared. To allow more PTEs to be shared, the patch set version uses the ownership instead of address range of VMA to solve the overlapping situation.

### Build
We provide the complete source code of the ODF implementation, which is based on Linux kernel v6.0.6. We recommend using the `x86_64_defconfig` that we tested our implementation with, but you can change it to suit your needs.

Compile the kernel as you normally would, and then install the kernel image and modules. Boot your system using this version of the kernel (refer to the documentation of your bootloader).

For added convenience, here is a snippet of commands to compile the kernel and install it on Debian-like systems:
```
make -j12 bindeb-pkg
cd ..
sudo dpkg -i linux-image-6.0.6*
```

### Usage
Use ODF in one of the following ways:

- In your application, call `prctl(65, 0, 0, 0, 0)` before `fork()` to invoke ODF.

- Transparently switch to ODF implementation of fork in your application by setting `/proc/<pid>/use_odf` to `1`. When a new process is created, the process inherits the flag from its parent. Read from `/proc/<pid>/use_odf` to determine the current implementation of fork in use: `1` means ODF provides `fork()`, while `0` means the traditional fork  provides `fork()`.

    To use ODF transparently right from the start of a program, take advantage of the inheritance of the flag by having a shell script like this:
    ```
    #!/bin/bash
    echo 1 > /proc/self/use_odf
    /path/to/your/program args
    ```

### Warning
We don't support the following features with odf.
- Soft-dirty
- Any feature depends on the actual refcount/mapcount of the mapped page.
