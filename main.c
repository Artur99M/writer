#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>


int main ()
{
    key_t k = fork();

    if (k == 0)
    {
        system ("./reader");
    }
    else
    {
        system ("./writer");
    }
}
