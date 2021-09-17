
#include<stdio.h>
  
int main()
{
    int  num;
    int count=0;

    printf("Enter the number\n");
    scanf("%d",&num);
    while(num!=0)
    {
        if((num&1)==1)
        {
            count++;
        }
        num=num>>1;
    }

    printf("number bits set is %d\n",count);
    
}


/*
Enter the number
10
number bits set is 2
PS C:\Users\manju\Desktop> cd "c:\Users\manju\Desktop\" ; if ($?) { gcc Untitled-1.c -o Untitled-1 } ; if ($?) { .\Untitled-1 }
Enter the number
4 
number bits set is 1

*/

