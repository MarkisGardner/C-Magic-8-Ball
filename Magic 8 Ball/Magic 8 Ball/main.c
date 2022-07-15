#include <stdio.h>
#include <stdlib.h>

void print_help()
{
    printf("Welcome to Magic 8 Ball!\n\n");
    printf("This is modeled ofter the Magic 8 Ball game that you asked a question and shook the ball and the answer would appear.\n");
    printf("So, ask your question and wait for your answer to appear!\n\n");
    printf("With no arguments the responses will be nice.\n");
    printf("With the argument m, the responses will be mean.\n");
    printf("With the argument a, the responses will be randomly choses from nice and mean.\n");
    printf("With the argument h, this help will be printed.\n");
    return;
}
int main(int argc, char** argv)
{
    if (argc > 2)
    {
        fprintf(stderr, "ERROR: Wrong number of arguments - try sending h as a command line argument for help!");
        return EXIT_FAILURE;
    }
    if (*argv[1] == 'h' || *argv[1] == 'H')
    {
        print_help();
    }

}
