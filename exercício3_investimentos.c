#include <stdio.h>

int main() {
    int x = 0;
    int y = 0;
    
    // Cria um vetor para armazenar toda a linha digitada (100 caracteres de espaço)
    char linha[100]; 
    
    // Variável para garantir que só vamos contar 20 movimentos reais
    int passos_lidos = 0; 

    // Lê a linha inteira do teclado (stdin) e guarda na variável 'linha'
    fgets(linha, sizeof(linha), stdin);

    // Percorre a linha letra por letra até o fim ('\0') ou até contar 20 passos
    for (int i = 0; linha[i] != '\0' && passos_lidos < 20; i++) {
        char movimento = linha[i];

        // Se o caractere for um espaço ou uma quebra de linha (Enter), nós ignoramos
        if (movimento == ' ' || movimento == '\n') {
            continue; // O 'continue' pula imediatamente para o próximo caractere
        }

        // Se chegou aqui, é uma letra válida. Aumentamos a contagem de passos.
        passos_lidos++;

        // Aplica o movimento na matriz
        switch (movimento) {
            case 'c': y--; break; // Cima
            case 'b': y++; break; // Baixo
            case 'e': x--; break; // Esquerda
            case 'd': x++; break; // Direita
        }
    }

    // Saída final com o esconderijo
    printf("Coordenada X: %d, Y: %d\n", x, y);

    return 0;
}