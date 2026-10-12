//Program to display system and Os information.

/*
#include<stdio.h>
#include<sys/utsname.h>

int main()
{
    struct username sys_info;
    if(uname(&sys_info)==0)
    {
        printf("\nOperating System: %s",sys_infp.sysname);
        printf("\nKernel Version: %s", sys_info.version);
    }
    else
    {
        perror("\nERROR: Retrieving OS details.");
        return 1;
    }
    return 0;
}
*/

//#include<sys/utsname.h>  --> Eitu Linux/Ubuntu r header file. Jodi windows native compiller (MinGW)t code tu run koru, tetia header file tu available nathakibo pare.
//Windows't OS information display koribole Windows API use koribo pari. Kintu jodi tor practical-t specifically uname() function use koribole dise, tenehole WSL (Windows Subsystem for Linux) ba Ubuntu environment use koribo lagibo.

//Jodi Windows't simple C program likhi OS information display koribo bisaro, ei code-tu use kor:

#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("\nOperating System Information\n");
    printf("----------------------------\n");

    printf("\nWindows Version:");
    system("ver");

    printf("\nKernel Information:\n");
    system("systeminfo | findstr /B /C:\"OS Name\" /C:\"OS Version\" /C:\"OS Build Type\"");

    return 0;
}

//system("ver"); — Windows version display kore.
//system("systeminfo ..."); — system information-r pora OS name, OS version aru OS build type filter kori display kore.
//findstr — Windows command, jeitu specified text match kori lines display kore.
//system(): C language-or stdlib.h header file-t thoka function. Eitu operating system-or command execute kore.
//systeminfo: Eitu Windows command. Computer-or system information display kore, jemon OS name, version, RAM, processor information etc.
// | (Pipe operator): systeminfo-r output-tu next command findstr-loi pathai diye.  (systeminfo | findstr ...) Mane, first command-or output second command-e input hisape pai.
// (/B) -- Line-or beginning-t match bisare.
// (/C:"OS Name") --Exact search string hisape "OS Name" use kore.
// (/C:"OS Version")	--"OS Version" thoka line bisare.
// (/C:"OS Build Type")  --"OS Build Type" thoka line bisare.
// \" kio use kora hoise? -- C language-t string enekoi start aru end hoi: (/C:\"OS Name\")
// \" = string-r bhitorot literal double quote (") likha.
// \\ = string-r bhitorot literal backslash (\) likha.