ON-DEMAND-FORK
------------
ON-DEMAND-FORK (ODF) is a fast implementation of the fork system call specifically designed for applications with large memory footprints and a requirement for low fork latency. 

ODF improves the latency of fork by deferring the work of copying page tables to the page fault handler, and increases efficiency of fork by selectively copying page tables on-demand. 

ON-DEMAND-FORK appeared on EuroSys 2021. You can find the paper at this [link](https://doi.org/10.1145/3447786.3456258). Cite the work as
```
Kaiyang Zhao, Sishuai Gong, and Pedro Fonseca. 2021. On-demand-fork: a microsecond fork for memory-intensive and latency-sensitive applications.
In Proceedings of the Sixteenth European Conference on Computer Systems (EuroSys '21). Association for Computing Machinery, New York, NY, USA, 540–555.
DOI:https://doi.org/10.1145/3447786.3456258
```

### Build
We provide the complete source code of the ODF implementation, which is based on Linux kernel v5.6.19. We recommend using the included configuration file `.config` that we tested our implementation with, but you can change it to suit your needs. 

Compile the kernel as you normally would, then install the kernel image and modules. Boot your system using this version of the kernel (refer to the documentation of your bootloader).

For added convenience, here is a snippet of commands to compile the kernel and install it on Debian-like systems:
```
make -j12 bindeb-pkg
cd ..
sudo dpkg -i linux-image-5.6.19*
```

### Usage
Use ODF in one of the following ways:

- In your application, replace `fork()` with `syscall(439)` to invoke ODF.

- Automatically redirect all `fork()` calls to ODF in your application by setting `/proc/<pid>/use_odf` to `1`. When a new process is created, the process inherits the flag from its parent. Read from `/proc/<pid>/use_odf` to determine the current fork-to-ODF redirection setting: `1` means the redirection is on, while `0` means the rediction is off.

    To redirect fork to ODF right from the start of a program, take advantage of the inheritance of the flag by having a shell script like this:
    ```
    #!/bin/bash
    echo 1 > /proc/self/use_odf
    /path/to/your/program args
    ```
