#include <stdio.h>
#include <stdlib.h>


void avlTree(int *bst, int n)
{
    int height[250];
    memset(height, 0, sizeof(height));
    int x = 0;
    int i = 0;
    for (i = 0; i < n; i++)
    {
        x = i;
        if(bst[x] != -1)
        {
            while(1) 
            {
                height[x] = ((height[2*x + 1] > height[2*x + 2])? (height[2*x + 1]) : (height[2*x + 2])) + 1;

                if(x == 0)
                {
                    break;
                }

                x = (x - 1) / 2;
            }
        }
    }

    for (x = 0; x < n; x++)
    {
        if(abs(height[2*x + 1] - height[2*x + 2]) > 1)
        {
            printf("F\n");
            return;
        }
    }
    printf("T\n");
}

int main(int argc, char const *argv[])
{
    int tests;
    int n;
    int i;
    int bst[200];
    scanf("%d", &tests);
    while(tests--) 
    {
        scanf("%d", &n);
        for (i = 0; i < n; i++) 
        {
            scanf("%d", &bst[i]);
        }
        avlTree(bst, n);
    }
    return 0;
}
