#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printZigzag(char *s, int numRows)
{
    if (numRows == 1 || numRows >= strlen(s))
    {
        printf("%s\n", s);
        return;
    }

    char **rows = (char **)malloc(numRows * sizeof(char *));
    for (int i = 0; i < numRows; i++)
    {
        rows[i] = (char *)calloc(strlen(s) + 1, sizeof(char));
    }

    int curRow = 0, goingDown = 0;
    for (int i = 0; s[i] != '\0'; i++)
    {
        strncat(rows[curRow], &s[i], 1);
        if (curRow == 0 || curRow == numRows - 1)
            goingDown = !goingDown;
        curRow += goingDown ? 1 : -1;
    }

    // Print rows in zigzag format
    for (int i = 0; i < numRows; i++)
    {
        printf("%s\n", rows[i]);
        free(rows[i]);
    }
    free(rows);
}

int main()
{
    char s[] = "PAYPALISHIRING";
    int numRows = 4;
    printZigzag(s, numRows);
    return 0;
}
