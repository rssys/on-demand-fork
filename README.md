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

### Build
We provide the complete source code of the ODF implementation, which is based on Linux kernel v6.0.6. We recommend using the included configuration file `.config` that we tested our implementation with, but you can change it to suit your needs.

Compile the kernel as you normally would, then install the kernel image and modules. Boot your system using this version of the kernel (refer to the documentation of your bootloader).

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
- userfaultfd
- THP
- soft-dirty
- KSM
- shmem
- mprotect() and madvise()
