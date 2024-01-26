#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

#define BUFFER_SIZE 4096

int main(int argc, char *argv[]) {
    if (argc != 3) {
        write(STDERR_FILENO, "Use: <input file> <output file>\n", 31);
        return EXIT_FAILURE; 
    }

    const char *inputfilename = argv[1];
    const char *outputfilename = argv[2];

    int inputfile = open(inputfilename, O_RDONLY);

    if (inputfile == -1) 
    {
        write(STDERR_FILENO, "error open input file\n", 23);
        return EXIT_FAILURE;
    }

    int outputfile = open(outputfilename, O_WRONLY | O_CREAT | O_EXCL);

    if (outputfile == -1) 
    {
        write(STDERR_FILENO, "error open output file\n", 24);
        close(inputfile);
        return EXIT_FAILURE;
    }

    char *buffer = (char *)malloc(BUFFER_SIZE);
    if (buffer == NULL) {
        write(STDERR_FILENO, "memory error\n",14);
        close(inputfile);
        close(outputfile);
        return EXIT_FAILURE;
    }

    ssize_t bytesread, byteswrite; 

    if (bytesread = read(inputfile, buffer, BUFFER_SIZE)) {
        if (byteswrite = write(outputfile, buffer, bytesread)) {
            write(STDOUT_FILENO, "good\n", 5);
        }
        else {
            write(STDERR_FILENO, "write error\n", 13);
            close(inputfile);
            close(outputfile);
            free(buffer);
            return EXIT_FAILURE;
        }
    }

    close(inputfile);
    close(outputfile);
    free(buffer);
    write(STDOUT_FILENO, "copy done\n", 9);

    return EXIT_SUCCESS;
}