#include<stdio.h>
#include <fstream>
#include<stdlib.h>

int main()
{
    int n;
    printf("Enter The Numbers Of Random Number : ");
    scanf("%d",&n);
    freopen("output.txt","w",stdout);
    for(int i=0;i<n;i++)
    {
        printf("%d ",rand());
    }



return 0;

}

