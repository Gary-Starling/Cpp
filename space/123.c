#include <stdio.h>

int main()
{

    unsigned int nn = 0;
    int res = 0;

    scanf("%d", &nn);

    res = nn % 10;

    printf("%d ", nn);

    if (nn == 11 || nn == 12 || nn == 13 || nn == 14)
    {
        printf("программистов\n");
    }
    else
    {
        switch (res)
        {
        case 0:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
            printf("программистов\n");
            break;
        case 1:
            printf("программист\n");
            break;
        case 2:
        case 3:
        case 4:
            printf("программиста\n");
            break;
        }
    }

    return 0;
}