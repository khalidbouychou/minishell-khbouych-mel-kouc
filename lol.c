#include <unistd.h>
#include <libc.h>

int main(int ac, char *av[], char *envp[])
{
    char *s = malloc(100000);
    if (s == NULL)
        perror("main");
    // char *tab[3];
    // tab[0] = "cat";
    // tab[1] = "jdjdjdj";
    // tab[2] = NULL;
    // execve("/bin/cat", tab, envp);
}