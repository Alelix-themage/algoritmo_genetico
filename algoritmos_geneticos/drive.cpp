// Alessandro Luis Pinheiro da Rocha Junior Código: 2230837
// Mateus Tiraboschi de Castro              Código: 2200040
// Igor Luis Dias Morais                     Código: 2199713


#include <iostream>
#include <cmath>
#include <algorithm> 
using namespace std;

//struct com o individuo e o array de individuo
struct Individuos {
    int individuo = 0;
    int resultado =0;
    static const int MAX_TAMANHO_POPULACAO = 1000; // declaração do tamanho max da população
    int individuos_para_mutar[MAX_TAMANHO_POPULACAO];
    int resultado_mutacao[MAX_TAMANHO_POPULACAO];
    int avaliando_mutacao = 0;
};

//Utilizamos a função bitwise porque ela trabalha bit a bit, assim fica mais fácil de mudar o "bit" genético
void retornaBin(int a) {
    //Converte um valor decimal em binario
    int bit = 0;
    for (int i = 31; i >= 0; i--) { //vai passar bit a bit o numero que passamos com sentido a direita, sempre analisando se deveria ser 1 ou 0
        bit = (a >> i) & 1;
        cout << bit;
    }
}

// Equação matemática
int equacao(int x){
    int a = 1s; //tem que ser diferente de 0
    int b = 1, c = 2, d = 3, e = 4, f = 3;
    // Forneça valores pequenos para os coeficientes(a, b, c, d, e, f), para conseguirmos uma solução satisfatória
    // Utiliza-se a função pow para realizar contas exponenciais
   int calculo = pow(x, 5)*a + pow(x, 4)*b + pow(x, 3)*c + pow(x, 2)*d + pow(x, 1)*e + f;
   cout << "-----------------------------------------" << endl;
   cout << "Nosso 'x' e: " << x << endl;
   cout << "\nO valor do calculo e : " << calculo << endl;
   return calculo;
}

bool ordenarIndividuos(int a, int b) {
    return abs(a) < abs(b);
}


// Função que realiza o crossover entre dois binários
int crossover(int peoples[], int tamanho, int filhos[]) {
    Individuos ind;

    int contador_filhos = 0;
    // Realiza o crossover combinando parte dos genes do pai e da mãe
    for (int i = 2; i < tamanho; i += 2) {
        int genes_pai = sizeof(int) * 8; // Pega o tamanho de inteiro e multiplica por 8
        int genes_mae = genes_pai / 2;
         int metade_pai = peoples[i] & ((1 << genes_mae) - 1); //  pegar os bits menos significativos, pegando metade
         int metade_mae = peoples[i + 1] >> genes_mae; // Desloca os bits da metade mais significativa para a direita
        int filho = (metade_mae << genes_mae) | metade_pai; // Combina os genes para formar o filho
        cout << "\nEsse e o pai: " << peoples[i] << endl;
        cout << "Esse e o da mae: " << peoples[i + 1] << endl;
        cout << "Esse e o filho: " << filho << endl;
        filhos[contador_filhos++] = filho; //Armazena os filho no contador fihlhos, o ++ serve para armazenar o próximo filho no próximo indice
    }
    return contador_filhos;
}


void substituirPaisPorFilhos(int populacao[], int filhos[], int contador_filhos) {
    // Substitui todos os pais pelos filhos gerados
    for (int i = 0; i < contador_filhos; i++) {
        populacao[i + 2] = filhos[i];
    }
}


/*void avaliapopulacao(int x){
    Individuos ind;
    int limitePosi = 2; // Parametro de satisfação do calculo
    int limiteNeg = -2;
    ind.avaliando_mutacao = equacao(x);
    if (ind.avaliando_mutacao >= limiteNeg && ind.avaliando_mutacao <= limitePosi) {
        cout << "Valor satisfatorio!" << endl;
    }  
    else {
        cout << "Valor insatisfatorio!" << endl;
    }
}*/


void populacaoInicial(int tamanho, int populacao[]){
    Individuos ind;
    char opc;
    // Para 10 Indivíduos o recomendado é: max/min [40,-40]
    // Para 100 Indivíduos o recomendado é: max/min [60,-60]
    // Para 1000 Indivíduos o recomendado é: max/min [70,-100] O RECOMENDADO
    int max = 20;
    int min = -20;

    cout << "Deseja gerar uma populacao aleatoria? (s/n)" << endl;
    cin >> opc;
    cout << "\nEstes sao os individuos : " << endl;
    for (int i = 0; i < tamanho; i++) {
        int individuo_aleatorio = min + rand() % (max - min + 1);

        // Criar individuos geneticamente diferentes
        if (opc == 's') {
            populacao[i] = individuo_aleatorio;
            cout << populacao[i] << endl;
            ind.individuo = populacao[i];
            cout << "Representacao binaria: ";
            retornaBin(populacao[i]);
            cout << "\n" << endl;

            ind.resultado = equacao(ind.individuo);
            
            int limitePosi = 2;
            int limiteNeg = -2;

            if (ind.individuo >= limiteNeg && ind.individuo <= limitePosi){
                cout << "Valor satisfatorio!" << endl;
            }           
            else{
            cout << "Valor insatisfatorio!" << endl;
            }


        }   
        
    }
     // colocar o ind.individuo em um vetor estatico que atualiza toda hora, setar o tamanho  pela variavel tamanho
    cout << "------------------------------------------------------------------" << endl;

    std::sort(populacao, populacao + tamanho, ordenarIndividuos);

    cout << "Ranking de Individuos" << std::endl;
    for (int i = 0; i < tamanho; i++) {
        //os melhores resultados fica na posição 1 e 2
        cout << "Posicao " << i + 1<< ": " << populacao[i] << std::endl; 
    }  

    // Copia a população ordenada para um novo array
    //ordenando a nova população e armazenando num novo array
    int novaPopulacao[tamanho];
    for (int i = 0; i < tamanho; i++) {
        novaPopulacao[i] = populacao[i];
    }

    // Substitui a população original pela nova população (ordena para a posição feita no ranking)
    for (int i = 0; i < tamanho; i++) {
        populacao[i] = novaPopulacao[i];
    }

    cout<< "----------------------------------------------------------------------------------------------"<< endl;
    char solucao;
    cout<< "A solucao e boa? " << endl;
    cin >> solucao;

    if(solucao == 's'){
        cout<< "Voce achou a solucao satisfatoria!" << endl;
    }
    else{
        cout<<"Iniciando o cruzamento" << endl;
    }


    int tam_cross = 10; // tam _cross serve para cruzar indvivíduos, deixando intactos os melhores
    //tem que trocar para o tamanho da população que deseja
    int filhos[tam_cross];
   
    int contador_filhos = crossover(populacao, tam_cross, filhos);

      // Adiciona os filhos gerados à população existente a partir da segunda posição
    substituirPaisPorFilhos(populacao, filhos, contador_filhos);
    //Coloca os filhos tira os pais, e deixa só os novos com o índice 0 e 1
    //Caso a população seja 10--> i < 6
    // Caso a população seja 100 --> i < 60
    //Caso a população seja 1000 --> i < 600
    cout<< "\nNovos Individuos: " << endl;
    for(int i = 0; i < 6; i++){
        cout << "Inviduo: "<< populacao[i] << endl;
        ind.individuos_para_mutar[i] = populacao[i];
    }
    cout<< "Tamanho " << sizeof(populacao) << endl;

}

void mutacao(int individuos_para_mutar[], int tamanho){
    Individuos ind;
    int individuos_mutados[tamanho]; // Array para armazenar os individuos mutados
    int flip = rand() % 2;
    if(tamanho == 10){
        tamanho = 6;
    }
    else if(tamanho == 100){
        tamanho=60;
    }
    else if(tamanho == 1000){
        tamanho =600;
    }
    
    cout<< "---------------------------------------------------------------" << endl;

    for(int i =0; i< tamanho; i++){
        cout<< "Individuo: " << individuos_para_mutar[i] << endl;
    }
    cout<< "---------------------------------------------------------------" << endl;
    cout<<"Individuos que sofreram mutacao: " << endl;
    //A mutação é aleatória de 50% para todos indivíduos, ou seja, todos podem sofrer mutação, ou não, como se fosse na natureza

    for(int i = 0; i < tamanho; i++){
        int taxa_de_mutacao = rand() % 2; // taxa de mutação
        if(taxa_de_mutacao == 0){ // 50% de chance de mutação //Lógica do flip moeda
            int bit_aleatorio = rand() % 32; // Escolhe um bit aleatório
            individuos_mutados[i] = individuos_para_mutar[i] ^ (1 << bit_aleatorio); // Altera o bit aleatório do indivíduo com bitwise
            cout << individuos_mutados[i] << endl; // Exibe o indivíduo mutado
        }
        else {
            individuos_mutados[i] = individuos_para_mutar[i]; // Se não houver mutação, o indivíduo permanece o mesmo
        }
    }

    // Substitui os indivíduos originais pelos indivíduos mutados
    cout<< "----------------------------------------------------------------------------" << endl;
    cout<< "Nova populacao com individuos mutados" << endl;
    for(int i = 0; i < tamanho; i++) {
        individuos_para_mutar[i] = individuos_mutados[i];
        cout<< individuos_para_mutar[i]<< endl; //indivíduos mutados junto com os não mutados
    }
    for(int i = 0; i < tamanho; i++){
        avaliapopulacao(individuos_para_mutar[i]);
    }
}



int main() {
    Individuos ind;
    srand(time(NULL));
    char op;
    int tamanho_da_populacao = 0;

    const int MAX_TAMANHO_POPULACAO = 1000; // declaração do tamanho max da população
    int populacao[MAX_TAMANHO_POPULACAO]; //atribuição do tamanho maximo da população para sofrer o crossover
    

    cout << "Deseja iniciar o programa? (s/n)" << endl;
    cin >> op;
    if (op == 's') {
        cout << "Escolha o tamanho da sua populacao: {10, 100, 1000}" << endl;
        cin >> tamanho_da_populacao;
        if (tamanho_da_populacao == 10 || tamanho_da_populacao == 100 || tamanho_da_populacao == 1000) {
            populacaoInicial(tamanho_da_populacao, populacao); // armazenar individuos gerados
            cout<< "Iniciando Mutacao " << endl;
            mutacao( populacao, tamanho_da_populacao);       
            cout << "----------------------------------------------------------------" << endl;  
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