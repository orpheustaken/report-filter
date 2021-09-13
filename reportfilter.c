#include <stdio.h>
#include "reportfilter.h"

int main(int argc, char** argv)
{
    if (argc < 2)
    {
        printf("reportfilter: missing file operand\n");
        return 1;
    }

    FILE* source = fopen(argv[1], "r");
    if (source == NULL)
    {
        printf("reportfilter: cannot stat '%s': No such file\n", argv[1]);
        return 2;
    }

    FILE* destination = fopen("report_result", "w");

    char c;
    unsigned short count_c = 0;

    while ((c = fgetc(source)) != EOF)
    {
        if (count_c == NEW_LINE) { count_c = 0; }

        if (count_c > START_REPORT && count_c < END_REPORT) { fputc(c, destination); }

        if (count_c == NEW_LINE_ES) { fputc(c, destination); }
       
        count_c++;
    }

    fclose(source);
    fclose(destination);

    return 0;
}

