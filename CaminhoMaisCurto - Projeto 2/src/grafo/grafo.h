#if !defined(GRAFO_H)
#define GRAFO_H
#define vertex int

/* Representação de um grafo por matriz de adjacências */
struct grafo
{
    int n_vertices;
    int n_arcos;
    int **adj; // ponteiro para a matriz de adjacências do grafo
};

typedef struct grafo *Grafo; // TODO Entender porque é um ponteiro

/* Cria um grafo com n vértices e nenhum arco */
Grafo criar_grafo(int n_vertices);

/* Função privada (static) que cria uma matriz de n_linhas por n_colunas e coloca um valor em todos os elementos */
// static int **criar_matriz(int n_linhas, int n_colunas, int val); // Static é pra deixar privado ao module

/* Insere um arco src-dst no grafo G. */
void inserir_arco(Grafo G, vertex src, vertex dest);

/* Remove o arco v1-v2 do grafo G*/
void remover_arco(Grafo G, vertex v1, vertex v2);

#endif // GRAFO_H
