// Alessandro Luis Pinheiro da Rocha Junior Código: 2230837
// Felipe Julien Rocha Pinho Código: 2241480
// Mateus Tiraboschi de Castro              Código: 2200040
// Igor Luis Dias Morais                     Código: 2199713
#include <iostream>
#include <cmath>
#include <algorithm>
#include <ctime>
using namespace std;

// Estrutura para representar indivíduos
struct Individuos {
    int individuo = 0; // Valor do indivíduo
    int resultado = 0; // Resultado da equação para o indivíduo
    static const int MAX_TAMANHO_POPULACAO = 1000; // Tamanho máximo da população
    int individuos_para_mutar[MAX_TAMANHO_POPULACAO]; // Array de indivíduos para mutação
    int resultado_mutacao[MAX_TAMANHO_POPULACAO]; // Resultado da mutação para cada indivíduo
    int individuos[MAX_TAMANHO_POPULACAO]; // Array de indivíduos
    int avaliando_mutacao = 0; // Resultado da avaliação da mutação
};

// Função para converter decimal em binário
void retornaBin(int a) {
    for (int i = 31; i >= 0; i--) {
        int bit = (a >> i) & 1;
        cout << bit;
    }
}

// Função para calcular a equação matemática
int equacao(int x){
    int a = 1;
    int b = 1, c = 2, d = 3, e = 4, f = 5;
    long long calculo = pow(x, 5)*a + pow(x, 4)*b + pow(x, 3)*c + pow(x, 2)*d + pow(x, 1)*e + f;
    return abs(calculo);
}

// Função para ordenar os indivíduos
bool ordenarIndividuos(int a, int b) {
    return abs(a) < abs(b);
}

// Função para realizar o crossover entre dois indivíduos
int crossover(int peoples[], int tamanho, int filhos[]) {
    const int NUM_BITS = 16;
    int contador_filhos = 0;
    for (int i = 2; i < tamanho; i += 2) {
        int genes_pai = NUM_BITS;
        int genes_mae = NUM_BITS;
        int metade_pai = peoples[i] & ((1 << genes_pai) - 1);
        int metade_mae = peoples[i + 1] >> genes_mae;
        int filho = (metade_mae << genes_mae) | metade_pai;
        filhos[contador_filhos++] = filho;
    }
    return contador_filhos;
}

// Função para substituir pais por filhos na população
void substituirPaisPorFilhos(int populacao[], int filhos[], int contador_filhos) {
    for (int i = 0; i < contador_filhos; i++) {
        populacao[i + 2] = filhos[i];
    }
}

// Função para avaliar a população
void avaliapopulacao(int x){
    int limitePosi = 2;
    int limiteNeg = -2;
    int avaliando_mutacao = equacao(x);
    if (avaliando_mutacao >= limiteNeg && avaliando_mutacao < limitePosi) {
        cout << "Valor satisfatorio!" << endl;
    }  
    else {
        cout << "Valor insatisfatorio!" << endl;
    }
}

// Função para inicializar a população
void populacaoInicial(int tamanho, int populacao[]){
    char opc;
    int max = 70;
    int min = -70;
    cout << "Deseja gerar uma populacao aleatoria? (s/n)" << endl;
    cin >> opc;
    cout << "\nEstes sao os individuos : " << endl;
    cout << "-----------------------------------------" << endl;    
    for (int i = 0; i < tamanho; i++) {
        int individuo_aleatorio = min + rand() % (max - min + 1);
        if (opc == 's') {
            populacao[i] = individuo_aleatorio;
            cout << populacao[i] << endl;
            cout << "Representacao binaria: ";
            retornaBin(populacao[i]);
            cout << "\n" << endl;
            avaliapopulacao(populacao[i]);
        }   
    }
    std::sort(populacao, populacao + tamanho, ordenarIndividuos);
    cout << "Ranking de Individuos" << endl;
    for (int i = 0; i < tamanho; i++) {
        cout << "Posicao " << i + 1<< ": " << populacao[i] << endl; 
    }  
}

// Função para ordenar a população
void ordernarPopulacao(int tamanho, int populacao[]) {
    int novaPopulacao[Individuos::MAX_TAMANHO_POPULACAO];
    for (int i = 0; i < tamanho; i++) {
        novaPopulacao[i] = populacao[i];
    }
    std::sort(novaPopulacao, novaPopulacao + tamanho, ordenarIndividuos);
    for (int i = 0; i < tamanho; i++) {
        populacao[i] = novaPopulacao[i];
    }
}

// Função principal para realizar o cruzamento
void cruzamento(int tamanho, int populacao[]){
    int tam_cross = 10;
    int filhos[tam_cross];
    int contador_filhos = crossover(populacao, tam_cross, filhos);
    int melhores[20];
    for (int i = 0; i < 10; i++) {
        melhores[i] = populacao[i];
        melhores[i + 10] = filhos[i];
    }
    std::sort(melhores, melhores + 20, ordenarIndividuos);
    cout << "\nMelhores Individuos:" << endl;
    for (int i = 0; i < 10; i++) {
        cout << "Posicao " << i + 1 << ": " << melhores[i] << endl;
    }
}

// Função para realizar a mutação
void mutacao(int individuos_para_mutar[], int tamanho){
    int individuos_mutados[tamanho];
    cout << "---------------------------------------------------------------" << endl;
    for(int i = 0; i < tamanho; i++){
        cout << "Individuo: " << individuos_para_mutar[i] << endl;
    }
    cout << "---------------------------------------------------------------" << endl;
    cout << "Individuos que sofreram mutacao: " << endl;
    for(int i = 0; i < tamanho; i++){
        int taxa_de_mutacao = rand() % 2;
        if(taxa_de_mutacao == 0){
            int bit_aleatorio = rand() % 32;
            individuos_mutados[i] = individuos_para_mutar[i] ^ (1 << bit_aleatorio);
            cout << individuos_mutados[i] << endl;
        } else {
            individuos_mutados[i] = individuos_para_mutar[i]; // Não houve mutação
        }
    }
    // Substitui os indivíduos originais pelos indivíduos mutados
    for(int i = 0; i < tamanho; i++) {
        individuos_para_mutar[i] = individuos_mutados[i];
        avaliapopulacao(individuos_para_mutar[i]); // Avalia o resultado da mutação
    }
}

int main() {
    srand(time(NULL));
    char op;
    int tamanho_da_populacao = 0;
    int geracao = 0;

    const int MAX_TAMANHO_POPULACAO = 1000;
    int populacao[MAX_TAMANHO_POPULACAO];

    cout << "Deseja iniciar o programa? (s/n)" << endl;
    cin >> op;
    if (op == 's') {
        cout << "Escolha o tamanho da sua populacao: {10, 100, 1000}" << endl;
        cin >> tamanho_da_populacao;
        cout << "Quantas geracoes deseja realizar?" << endl;
        cin >> geracao;
        if (tamanho_da_populacao == 10 || tamanho_da_populacao == 100 || tamanho_da_populacao == 1000) {
            populacaoInicial(tamanho_da_populacao, populacao);
            for(int i = 0; i < geracao; i++){
                ordernarPopulacao(tamanho_da_populacao, populacao);
                char solucao;
                cout << "A solucao e boa? " << endl;
                cin >> solucao;
                if (solucao == 's') {
                    cout << "Voce achou a solucao satisfatoria!" << endl;
                    return 0;
                } else {
                    cout << "Iniciando o cruzamento" << endl;
                    cruzamento(tamanho_da_populacao, populacao);
                }
                cout << "----------------------------------------------------------------" << endl;
                cout<< "Iniciando Mutacao " << endl;
                mutacao( populacao, tamanho_da_populacao);       
                cout << "----------------------------------------------------------------" << endl;
                ordernarPopulacao(tamanho_da_populacao, populacao);
                // Imprime a população ordenada novamente
                cout << "Populacao ordenada apos a mutacao:" << endl;
                for (int i = 0; i < tamanho_da_populacao; i++) {
                    cout << "Posicao " << i + 1 << ": " << populacao[i] << endl;
                }
            }
        }
        else {
            cout << "Nao sao permitidas populacoes que nao tenham tamanho de 10, 100 ou 1000!" << endl;
            return 0;
        }
    }
    else {
        cout << "O programa sera encerrado!" << endl;
        return 0;
    }
}
