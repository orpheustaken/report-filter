#include <stdio.h>
#include <stdlib.h>

#define REPORT_LENGTH 8

int main(int argc, char** argv)
{
    if (argc < 2)
    {
        printf("generatelist: missing quantity operand\n");
        return 1;
    }

    int report_quantity = (int) strtol(argv[1], (char **) NULL, 10);
    
    if (report_quantity <= 0)
    {
        printf("generatelist: invalid quantity operand\n");
        printf("Argument must be a positive integer.\n");
        return 2;
    }

    char random_digit;

    FILE* list = fopen("report_list", "w");
    
    for (int i = 0; i < report_quantity; i++)
    {
        fputs("./YYYY-MM-DD/", list);

        for (int j = 0; j < REPORT_LENGTH; j++)
        {
            random_digit = rand() % 10 + '0';

            fputc(random_digit, list);
        }

        fputs(".json", list);

        random_digit = '\n';
        fputc(random_digit, list);
    }

    fclose(list);

    return 0;
}
