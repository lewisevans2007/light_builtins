/* Light builtins's (C version)
 * cp - copy files and directories
 * A lightweight repository of useful shell commands
 * GitHub: https://www.github.com/awesomelewis2007/light_builtins
 * License: GNU General Public License v3.0
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char *argv[])
{
    FILE *fp1, *fp2;
    int c;
    char *file1, *file2;

    if (argc == 1) {
        printf("cp: usage: cp [file1] [file2]");
        exit(1);
    } else if (argc == 2) {
        printf("cp: usage: cp [file1] [file2]");
        exit(1);
    } else if (argc == 3) {
        file1 = argv[1];
        file2 = argv[2];
        if ((fp1 = fopen(file1, "r")) == NULL) {
            printf("cp: can't open %s", file1);
            exit(1);
        } else if ((fp2 = fopen(file2, "w")) == NULL) {
            printf("cp: can't open %s", file2);
            exit(1);
        } else {
            while ((c = getc(fp1)) != EOF)
                putc(c, fp2);
            fclose(fp1);
            fclose(fp2);
        }
    }
    return 0;
}