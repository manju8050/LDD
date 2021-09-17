
#include<stdio.h>
  
int main()
{
    int  num,n,new_num;
    

    printf("Enter the number\n");
    scanf("%d",&num);

    printf("Enter the position\n");
    scanf("%d",&n);
    
    new_num=(1<<n)^num;

    printf("number before toggle %d\n",num);
    printf("number after toggle %d\n",new_num);
    
    
}

/*
Enter the number
10
Enter the position
0
number before toggle 10
number after toggle 11
PS C:\Users\manju\Desktop> cd "c:\Users\manju\Desktop\" ; if ($?) { gcc Untitled-1.c -o Untitled-1 } ; if ($?) { .\Untitled-1 }
Enter the number
10
Enter the position
2
number before toggle 10
number after toggle 14

*/



