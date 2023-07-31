#include <unistd.h>
#include <stdio.h>

int main()
{
    char *tab[2];
    tab[0] = "ls";
    tab[1] = NULL;
    execve("/bin/li", tab, NULL);
    printf("jjsjjjs");
}