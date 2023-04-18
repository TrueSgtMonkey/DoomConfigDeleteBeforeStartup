#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

int main()
{
    // replace user_name with your Windows User Name
    // without angle brackets of course
    char* savedPath = "C:\\Users\\<user_name>\\\"Saved Games\"\\\"id Software\"\\DOOMEternal\\base\\*";

    printf("Initializing Vectors\n");

    VectorChar deleteCommand;
    VectorChar runCommand;
    deleteCommand.arr = NULL;
    runCommand.arr = NULL;
    if (initVectorChar(&deleteCommand)) {
        printf("Delete Config Command Bad\n");
        return 1;
    }
    if (initVectorChar(&runCommand)) {
        printf("Run command Bad\n");
        return 2;
    }

    printf("Deleting Configs\n");

    // Deleting stupid config files before starting Doom Eternal up
    deleteCommand.pusharr(&deleteCommand, "del /F /Q ");
    deleteCommand.pusharr(&deleteCommand, savedPath);
    system(deleteCommand.arr);

    printf("Starting Doom\n");

    runCommand.pusharr(&runCommand, "DOOMEternalx64vk.exe");
    system(runCommand.arr);

    printf("Done!\n");

    deleteCommand.delete(&deleteCommand);
    runCommand.delete(&runCommand);
    return 0;
}