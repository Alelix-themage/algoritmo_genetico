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
int equacao(int x, int a,int b,int c,int d,int e, int f){
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


//Função que realiza o crossover entre dois binários
int crossover(int pai, int mae) {
    // Realiza o crossover combinando parte dos genes do pai e da mãe
    int genes_pai = sizeof(int) * 8; //Pega o tamanho de inteiro e multiplica por 8
    int genes_mae = genes_pai / 2;
    int metade_pai = pai & ((1 << genes_mae) - 1); // Máscara para pegar os bits menos significativos
    int metade_mae = mae >> genes_mae; // Desloca os bits da metade mais significativa para a direita
    int filho = (metade_mae << genes_mae) | metade_pai; // Combina os genes para formar o filho
    cout<< "\nEsse e o pai: "  << pai << endl;
    cout << "Esse e o da mae: " << mae << endl;
    cout << "Esse e o filho: " << filho << endl;
    return filho;
}


void populacaoInicial(int tamanho, int populacao[]) {
    Individuos ind;
    char opc;
    //Para 10 Indivíduos o recomendado é: max/min [40,-40]
    //Para 100 Indivíduos o recomendado é: max/min [60,-60]
    //Para 1000 Indivíduos o recomendado é: max/min [70,-100]
    int max = 40; 
    int min = -40;

    int a=1;
    int b=2, c=3, d=4, e=5, f=6;
    //Forneça valores pequenos para os coeficientes(a, b,c, d,e f), para conseguirmos uma solução satisfatória
    cout << "Forneca os valores que serao utilizados na nossa equacao: " << endl;
    cout<< "Digite o valor de a, sendo a diferente de 0" << endl;
    cin >> a;
    if (a==0){
        cout << "O 'a' tem que ser difrente de 0!" << endl;
    }
    cout << "Deseja gerar uma populacao aleatoria? (s/n)" << endl;
    cin >> opc;
    cout << "\nEstes sao os individuos : " << endl;
    for (int i = 0; i < tamanho; i++) {
        int individuo_aleatorio = min + rand() % (max - min + 1);

        // criar individuos geneticamente diferentes 
        if (opc == 's') {
            populacao[i] = individuo_aleatorio;
            cout << populacao[i] << endl;
            ind.individuo = populacao[i];
            cout << "Representacao binaria: ";
            retornaBin(populacao[i]);
            cout << "\n" << endl;


            ind.resultado = equacao(ind.individuo, a,b,c,d,e,f);

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
    int tam_cross = 8; //tamanho de 8, pois vamos deixar os dois melhores de fora
    for(int i = 0; i< tam_cross; i++){
        crossover(populacao[]);
    }
}
    


int main() {
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
            cout<< "Digite o valor da taxa de mutacao: " << endl;
            int taxa_de_mutacao;
            cin>>taxa_de_mutacao;            
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