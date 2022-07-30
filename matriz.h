#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#define MAX 10

typedef int matriz[MAX][MAX];

void inicializarMatriz(matriz);
void gotoxy(int, int);
void dibujarMatriz(matriz);
void cargarMatriz(matriz);


void inicializarMatriz(matriz nueva_matriz) {
    int i, j;

    for (i = 0; i < MAX; i++) {
        for (j = 0; j < MAX; j++) {
            nueva_matriz[i][j] = 0;
        }
    }
}

//FUCION PARA MOVER CURSOR A SITIO DESEADO
void gotoxy(int x, int y) {

    COORD CRD;
    CRD.X = x;
    CRD.Y = y;

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), CRD);
}

void dibujarMatriz(matriz nueva_matriz) {
    int i, j;

    for (i = 0; i < MAX; i++) {
        for (j = 0; j < MAX; j++) {
            printf("%d ",nueva_matriz[i][j]);
        }
        printf("\n");
    }
}

void cargarMatriz(matriz nueva_matriz) {
    int i, j;
    int n = 0;
    int x = 0;
    while (x < 1000) {
        for (i = 0; i < MAX; i++) {
            for (j = 0; j < MAX; j++) {

                if (x == 0) {
                    nueva_matriz[i][j] = j;
                    n = j;
                }
                else  {
                    if (nueva_matriz[i][j] < MAX - 1) {
                        nueva_matriz[i][j] = nueva_matriz[i][j] + 1;
                    }
                    else {
                        nueva_matriz[i][j] = 0;
                    }
                }

                printf("%d ",nueva_matriz[i][j]);
                Sleep(50);

            }

        printf("\n");
        
        }

        x = x + 1;
        gotoxy(0,0);
    }
    
}
