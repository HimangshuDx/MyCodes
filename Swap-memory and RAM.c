//Program to Display Swap-Memory and RAM using sysinfo()
/*
#include<stdio.h>
#include<sys/sysinfo.h>

int main()
{
    struct sysinfo info;
    if(sysinfo(&info) == 0)
    {
        printf("\nMEMORY INFORMATION\n");
        printf("\nTotal RAM: %lu MB", (unsigned long)(info.totalram*info.mem_unit/(1024*1024)));
        printf("\nFree RAM: %lu MB", (unsigned long)(info.freeram*info.mem_unit/(1024*1024)));
        printf("\nTotal Swap-Memory: %lu MB", (unsigned long)(info.totalswap*info.mem_unit/(1024*1024)));
        printf("\nFree Swap-Memoy: %lu MB", (unsigned long)(info.freeswap*info.mem_unit/(1024*1024)));
    }
    else
    {
        perror("\nSysinfo Failed");
        return 1;
    }
    return 0;
}
*/

// Program to Display Swap-Memory and RAM in Windows

#include <stdio.h>
#include <windows.h>

int main()
{
    MEMORYSTATUSEX info;
    info.dwLength = sizeof(info);

    if (GlobalMemoryStatusEx(&info))
    {
        printf("\nMEMORY INFORMATION\n");

        
        printf("\nTotal RAM: %lu MB",(unsigned long)(info.ullTotalPhys / (1024 * 1024)));
        printf("\nFree RAM: %lu MB",(unsigned long)(info.ullAvailPhys / (1024 * 1024)));
        printf("\nTotal Swap-Memory: %lu MB",(unsigned long)(info.ullTotalPageFile / (1024 * 1024)));
        printf("\nFree Swap-Memory: %lu MB\n",(unsigned long)(info.ullAvailPageFile / (1024 * 1024)));
    }
    else
    {
        printf("Error: Unable to retrieve memory information.\n");
        return 1;
    }

    return 0;
}
/*
Linix Program ---------------Windows Program 
_________________________________________________
#include <sys/sysinfo.h>	#include <windows.h>
struct sysinfo info         MEMORYSTATUSEX info
sysinfo(&info)	            GlobalMemoryStatusEx(&info)
info.totalram	            info.ullTotalPhys
info.freeram	            info.ullAvailPhys
info.totalswap	            info.ullTotalPageFile
info.freeswap	            info.ullAvailPageFile
*/