
#include<stdio.h>
  
int main()
{
    int  num;
    int count=0,count1=-1;

    printf("Enter the number\n");
    scanf("%d",&num);
    int org=num;
    while(num!=0)
    {
        if((num&1)==1)
        {
            count++;
        }
        num=num>>1;
        count1++;

    }

    if(count==1)
    {
        printf("enter number is power of 2: 2^%d=%d",count1,org);

    }
    else
    {
        printf("enter number is not the power of 2");
    }
    
}

/*
Enter the number
4
enter number is power of 2: 2^2=4
PS C:\Users\manju\Desktop> cd "c:\Users\manju\Desktop\" ; if ($?) { gcc Untitled-1.c -o Untitled-1 } ; if ($?) { .\Untitled-1 }
Enter the number
8
enter number is power of 2: 2^3=8
*/


