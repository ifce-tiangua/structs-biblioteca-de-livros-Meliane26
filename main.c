#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[100];
    char isbn[20];
    float preco;
    int score;
    char editora[100];
} Livro;

typedef Livro* pLivro;

pLivro livro_aloc(int qtde) {
    return (pLivro)malloc(qtde * sizeof(Livro));
}

void livro_ler(pLivro livros, int qtde) {
    for (int i = 0; i < qtde; i++) {
        printf("Nome: ");
        getchar(); // Limpa o buffer
        fgets(livros[i].nome, sizeof(livros[i].nome), stdin);
        livros[i].nome[strcspn(livros[i].nome, "\n")] = '\0';

        printf("ISBN: ");
        fgets(livros[i].isbn, sizeof(livros[i].isbn), stdin);
        livros[i].isbn[strcspn(livros[i].isbn, "\n")] = '\0';

        printf("Preço: ");
        scanf("%f", &livros[i].preco);

        printf("Score (0-10): ");
        scanf("%d", &livros[i].score);
        getchar(); // Limpa o buffer após a entrada de número

        printf("Editora: ");
        fgets(livros[i].editora, sizeof(livros[i].editora), stdin);
        livros[i].editora[strcspn(livros[i].editora, "\n")] = '\0';
    }
}

void livro_exibe(pLivro livros, int qtde) {
    for (int i = 0; i < qtde; i++) {
        printf("\nLivro %d:\n", i + 1);
        printf("Nome: %s\n", livros[i].nome);
        printf("ISBN: %s\n", livros[i].isbn);
        printf("Preço: R$ %.2f\n", livros[i].preco);
        printf("Score: %d\n", livros[i].score);
        printf("Editora: %s\n", livros[i].editora);
    }
}

void livro_desaloca(pLivro livros) {
    free(livros);
}

int main() {
    int qtde;
    scanf("%d", &qtde);

    if (qtde <= 0) {
        printf("Número de livros inválido.\n");
        return 0;
    }

    pLivro livros = livro_aloc(qtde);
    if (livros == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    livro_ler(livros, qtde);
    livro_exibe(livros, qtde);
    livro_desaloca(livros);

    return 0;
}
