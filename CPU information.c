// program to  display the CPU information using sysconf() function.

/*
#include<stdio.h>
#include<unistd.h>

int main()
{
    printf("\nCPU INFORMATION\n");
    printf("\nNumber of Online CPUs: %ld", sysconf(_SC_NPROCESSOR_ONLIN));
    printf("\nNumber of Configured CPUs: %ld", sysconf(_SC_NPROCESSOR_CONF));
    printf("\nPage Size: %ld Bytes", sysconf(_SC_PAGESIZE));
    printf("\nClock Ticks per Second: %ld", sysconf(_SC_CLK_TICK));

    return 0;
}
*/
// sysconf() function aru _SC_NPROCESSORS_ONLN nisina constants-bilak Linux/Unix-specific. so WINDOWS t solale ERROR ahibo.
// #include <unistd.h> dileu Windows native GCC/MinGW compiler-e ei constants-bilak support nokoribo pare.
// practical-t specifically sysconf() use koribole dise jodi, Ubuntu ba WSL (Windows Subsystem for Linux)-t code-tu run koribi.


#include <stdio.h>
#include <windows.h>

int main()
{
    SYSTEM_INFO sys_info;

    GetSystemInfo(&sys_info);

    printf("\nCPU INFORMATION\n");
    printf("--------------------------\n");

    printf("\nNumber of Processors: %lu",
           (unsigned long)sys_info.dwNumberOfProcessors);

    printf("\nProcessor Architecture: ");

    switch (sys_info.wProcessorArchitecture)
    {
        case PROCESSOR_ARCHITECTURE_AMD64:
            printf("x64 (64-bit)");
            break;

        case PROCESSOR_ARCHITECTURE_INTEL:
            printf("x86 (32-bit)");
            break;

        #ifdef PROCESSOR_ARCHITECTURE_ARM64
        case PROCESSOR_ARCHITECTURE_ARM64:
            printf("ARM64");
            break;
        #endif
        default:
            printf("Unknown");
    }

    printf("\nPage Size: %lu bytes\n",
           (unsigned long)sys_info.dwPageSize);

    return 0;
}

//GetSystemInfo() — Windows API function.
//SYSTEM_INFO — system configuration store kora structure.
//dwNumberOfProcessors — logical processors-r number diye.
//wProcessorArchitecture — processor architecture diye.
//dwPageSize — memory page size bytes-t diye. 
