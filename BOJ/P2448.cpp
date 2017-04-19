#include <stdio.h>
#include <stdlib.h>

void recursive(int , char **, int , int );

int main()
{
    int n, i, j;
    char **c;

    scanf("%d", &n);

    c = (char **)malloc(sizeof(char*)*n);
    for(i=0; i<n; i++)
        c[i] = (char *)malloc(sizeof(char)*(2*(i+1)-1));

    for(i=0; i<n; i++)
        for(j=0; j<2*i+1; j++)
            c[i][j] = ' ';

    recursive(n, c, 0, 0);

    for(i=0; i<n; i++)
    {
        for(j=0; j<n-i-1; j++)
            printf(" ");
        for(j=0; j<2*i+1; j++)
            printf("%c", c[i][j]);
        for(j=0; j<n-i-1; j++)
            printf(" ");
        printf("\n");
    }

    free(c);
    return 0;
}

void recursive(int n, char **c, int x, int y)
{
    if(n == 3)
    {
        c[x][y] = '*';
        c[x+1][y] = '*';
        c[x+1][y+2] = '*';
        c[x+2][y] = '*';
        c[x+2][y+1] = '*';
        c[x+2][y+2] = '*';
        c[x+2][y+3] = '*';
        c[x+2][y+4] = '*';
        return;
    }
    else
    {
        recursive(n/2, c, x    , y  );
        recursive(n/2, c, x+n/2, y  );
        recursive(n/2, c, x+n/2, y+n);
        return;
    }
}
