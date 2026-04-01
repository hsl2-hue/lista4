#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int m, n;
    //l� as entradas
    scanf("%d %d", &m, &n);
    
    //cria matrizes com o limite estabelecido 
    char praca[100][100]; 
    char resultado[100][100];

    //le a matriz original e inicializa a matriz de resultado
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf(" %c", &praca[i][j]);
            resultado[i][j] = praca[i][j]; //come�a senod igual ao original
        }
    }

    //ve cada posi��o para encontrar postes 'P'
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (praca[i][j] == 'P') {
                
                //verifica os vizinhos ao redor do poste
                for (int di = -1; di <= 1; di++) {
                    for (int dj = -1; dj <= 1; dj++) {
                        int ni = i + di; //nova linha
                        int nj = j + dj; //nova coluna

                        //verifica se o vizinho est� dentro dos limites e n�o � o pr�prio poste
                        if (ni >= 0 && ni < m && nj >= 0 && nj < n && praca[ni][nj] == '-') {
                            
                            // regra pras diagonais
                            if (di != 0 && dj != 0) {
                                //coloca 'x' se a posi��o ainda for vazia
                                if (resultado[ni][nj] == '-') {
                                    resultado[ni][nj] = 'x';
                                }
                            } 
                            //regra pras 4 posi��es
                            else if (di != 0 || dj != 0) {
                                //'+' sempre prevalece sobre o 'x'
                                resultado[ni][nj] = '+';
                            }
                        }
                    }
                }
            }
        }
    }

    //imprime a matriz resultante
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%c", resultado[i][j]);
        }
        printf("\n");
    }

    return 0;
}