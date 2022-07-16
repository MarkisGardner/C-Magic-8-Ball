#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define NUM_LINES 10  //At first only allocate enough space for 10 lines of data then realloc for more.
#define BUFFER_SIZE 4096  // Temporary storage size

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

// We need the char *** instead of char ** because we are going to need the info back to the calling function!
int check_files(char* good, char* bad, char*** array, int* count)
{
    *array = malloc(NUM_LINES*sizeof(char*));// array of pointers to characters
    int num_of_lines=0;
    int length=0;

    if (*array == NULL)
    {
        fprintf(stderr,"ERROR:  Unable to allocate space for %d lines of data - returning %d!\n",NUM_LINES, EXIT_FAILURE);
        return EXIT_FAILURE;
    }

    if (good != NULL)
    {
        FILE* f=fopen(good,"r");
        if (f==NULL)
        {
            fprintf(stderr,"Could not open GOOD file - %s\n",good);
            return EXIT_FAILURE;
        }

        char buffer[BUFFER_SIZE];
        while (!feof(f) && !ferror(f))
        {
            if (fgets(buffer, BUFFER_SIZE,f) != NULL)
            {
                length=strlen(buffer);
                buffer[length-1]='\0';  //because fgets add \n to the string.
                // Need the (*array) in parenthesis because of order of operations.
                (*array)[num_of_lines]=malloc(length*sizeof(char));  // normally would do length+1 but length includes the \n that we got rid of.
                strcpy((*array)[num_of_lines],buffer);
                //printf("Found %s\n",buffer);
                num_of_lines++;
                if (num_of_lines%10 == 0)  // every 10 lines I will add 10 more spaces.
                {
                    *array = realloc(*array,(num_of_lines+10)*sizeof(char*));
                }
            }
        }
        printf("We are ready to print the list out!\n");
        for (int i=0; i<num_of_lines;i++)
        {
            printf("line %d is %s\n",i,(*array)[i]);
        }

    }
    if (bad != NULL)
    {
        FILE* f=fopen(bad,"r");
        if (f==NULL)
        {
            fprintf(stderr,"Could not open GOOD file - %s\n",bad);
            return EXIT_FAILURE;
        }
        char buffer[BUFFER_SIZE];
        while (!feof(f) && !ferror(f))
        {
            if (fgets(buffer, BUFFER_SIZE,f) != NULL)
            {
                length=strlen(buffer);
                buffer[length-1]='\0';  //because fgets add \n to the string.
                (*array)[num_of_lines]=malloc(length*sizeof(char));  // normally would do length+1 but length includes the \n that we got rid of.
                strcpy((*array)[num_of_lines],buffer);
                //printf("Found %s\n",buffer);
                num_of_lines++;
                if (num_of_lines%10 == 0)  // every 10 lines I will add 10 more spaces.
                {
                    *array = realloc((*array),(num_of_lines+10)*sizeof(char*));
                }
            }
        }
        printf("We are ready to print the total list out!\n");
        for (int i=0; i<num_of_lines;i++)
        {
            printf("line %d is %s\n",i,(*array)[i]);
        }
    }
    *count=num_of_lines;
    return EXIT_SUCCESS;
}
void play_game(char*** array, int count)
{
    printf("Ready to play game with %d items!\n",count);
    printf("Item 1 is %s\n",(*array)[0]);
    for (int i=0; i<count; i++)
    {
        printf("Item %d is %s\n",i,(*array)[i]);
    }
    srand(time(NULL));
    //char in[BUFFER_SIZE];
    char buffer[BUFFER_SIZE];
    printf("\n Welcome to the Magic 8 Ball\n\n");
    printf("Enter your yes/no question and get a magical answer!\n");
    printf("Just hit enter without a question to quit the game!\n");
    while (fgets(buffer, BUFFER_SIZE,stdin) != NULL)
    {
        //printf("The length is %zu\n",strlen(buffer));
        if (strlen(buffer)==1)
        {
            break;
        }
        printf("You asked %s\n",buffer);
        printf("My magical insights tell me %s\n", (*array)[(rand()%count)]);
    }
}
int main(int argc, char** argv)
{
    char* good=NULL;
    char* bad=NULL;
    int count=0;
    // process the arguments
    for (int i=1; i<argc; i++)
    {
        if (argv[i][0] == 'h' || argv[i][0] == 'H')
        {
            print_help();
            return EXIT_SUCCESS;
        }
        if (argv[i][0] == 'g' || argv[i][0]=='G')
        {
            i++;
            good=argv[i];
        }
        if (argv[i][0] == 'b' || argv[i][0]=='B')
        {
            i++;
            bad=argv[i];
        }
        //Note: For this program I am not checking for other or invalid arguments.
    }
    printf("Good Filename is %s\n",good);
    printf("Bad Filename is %s\n",bad);
    char **array=NULL;
    if (check_files(good,bad,&array, &count))
    {
        printf("I have %d for number of items\n",count);
        return EXIT_FAILURE;
    }
    printf("I have %d for number of items\n",count);
    printf("First item is %s\n",array[0]);
    play_game(&array,count);
    return EXIT_SUCCESS;
}
