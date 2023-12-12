#include <stdio.h>
#include <unistd.h>
/**
 * main - PPID - Parent Process IDentifier
 * Description: A program that prints the parent process ID
 * Return: Always 0.
 */
int main(void)
{
    pid_t my_ppid;

    my_ppid = getppid();
    printf("%u\n", my_ppid);
    return (0);
}