#include<ctype.h>
#include<stdio.h>
void *test(char *b, int c)
{
    for(int i = 0 ; i < ; i++)
    {
        b[i] = c;
    }
    return (b);
}

int main()
{
    char s[6] = "ooooo";
    printf("this is before : %s", s);
    test(s,'l');
    printf("this is after : %s", s);
}