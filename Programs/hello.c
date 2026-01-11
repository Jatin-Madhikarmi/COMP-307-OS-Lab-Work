#include <stdio.h>
#include <unistd.h>

int main()
{
    printf("This demonstrates the fork\n");
    fork(); // First fork
    fork(); // Second fork
    printf("Hello world\n");
    return 0;
}