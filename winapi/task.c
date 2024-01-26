#include <stdio.h>
#include <windows.h>

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        fprintf(stderr, "Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }
    const char *inputfilename = argv[1];
    const char *outputfilename = argv[2];

    HANDLE inputfile = CreateFileA(inputfilename, GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    if (inputfile == INVALID_HANDLE_VALUE)
    {
        printf("error: %d\n", GetLastError());
        return 1;
    }

    HANDLE outputfile = CreateFileA(outputfilename, GENERIC_WRITE, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    if (outputfile == INVALID_HANDLE_VALUE)
    {
        printf("error: %d\n", GetLastError());
        return 1;
    }

    const DWORD buffersize = 4096;
    char buf[buffersize];
    DWORD dwBytesRead, dwBytesWrite;

    if (ReadFile(inputfile, buf, sizeof(buf), &dwBytesRead, NULL))
    {
        if (WriteFile(outputfile, buf, dwBytesRead, &dwBytesWrite, NULL))
        {
            printf("good\n");
        }
        else
        {
            printf("error in if: %d\n", GetLastError());
            return 1;
        }
    }


    CloseHandle(inputfile);
    CloseHandle(outputfile);

    WriteConsole(GetStdHandle(STD_OUTPUT_HANDLE), "Copy completed successfully\n", 29, NULL, NULL);

    return 0;

    // MessageBoxW(0, L"Hello!", L"MsgBox", 0);
    // ExitProcess(0);
}