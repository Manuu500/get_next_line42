#include "get_next_line.h"

int main(int argc, char **argv)
{
    int fd;
    char buffer[1024];
    char *line;

    // Abre el archivo en modo lectura
    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
    {
        perror("Error al abrir el archivo");
        return 1;
    }

    // Llama a la función read_line
    line = get_next_line(fd);
    if (line)
    {
        printf("Linea leida: %s\n", line);
    }
    else
    {
        printf("No se pudo leer la linea\n");
    }

    // Cierra el archivo
    close(fd);
    return 0;
}