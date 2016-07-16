#include<stdio.h>
#include<ctype.h>

int main(int argc, char *argv[]) {
    unsigned char dados[16];
    FILE *fd;
    int i, num_bytes, pos = 0, num_linhas = 0;

    if (argc < 2) {
        printf("Erro: numero de argumentos invalido.\n");
        return 1;
    }
    if ((fd = fopen(argv[1], "r")) == NULL) {
        printf("Erro: nao foi possivel abrir o arquivo.\n");
        return 1;
    }
    while (!feof(fd)) {
        num_linhas++;
        printf("%04d ", pos);
        num_bytes = fread(dados, 1, 16, fd);
        pos += num_bytes;
        for (i=0; i<num_bytes; i++)
            printf("%02X ", dados[i]);
        if (num_bytes < 16)
            for (i=num_bytes; i<16; i++)
                printf("   ");
        printf("\t");
        for (i=0; i<num_bytes; i++)
            if (isprint(dados[i]))
                printf("%c", dados[i]);
            else
                printf(".");
        if (num_bytes < 16)
            for (i=num_bytes; i<16; i++)
                printf(" ");
        if (num_linhas % 25 == 0)
            getchar();
        printf("\n");
    }
    return 0;
}