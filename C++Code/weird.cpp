#include <stdio.h>
char A[123][123];
int main()
{
    void *p1=(A+1);
    void *p2=*(A+1);
    if (p1==p2) printf("yes\n");
}