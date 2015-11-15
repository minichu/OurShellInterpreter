#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
int main(int argc, char** argv)
{
        char ch;
        int fd;

        if ( argc != 2 )
        {
                printf( "argument error\n" );
                printf( " usage : ./test.out filename\n");
                exit( -1 );
        }

        fd = open(argv[1], O_RDONLY );

        while( read( fd, &ch, 1 ) )
                write( 1, &ch, 1 );
        close(fd);
        return 0;
}
