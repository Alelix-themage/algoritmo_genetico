// Alessandro Luis Pinheiro da Rocha Junior Código: 2230837


#include <iostream>
#include <cmath>
using namespace std;
//Utilizamos a função bitwise porque ela trabalha bit a bit, assim fica mais fácil de mudar o "bit" genético

//struct com o individuo e o array de individuo
struct Individuos {
    int individuo = 0;
};


void retornaBin(int a) {
    //Converte um valor decimal em binario
    int bit = 0;
    for (int i = 31; i >= 0; i--) { //vai passar bit a bit o numero que passamos com sentido a direita, sempre analisando se deveria ser 1 ou 0
        bit = (a >> i) & 1;
        cout << bit;
    }

}

// Equação matemática
double equacao(double a, double b, double c, double d, double e, double f, double x){
    // Utiliza-se a função pow para realizar contas exponenciais
   double calculo = pow(x, 5)*a + pow(x, 4)*b + pow(x, 3)*c + pow(x, 2)*d + pow(x, 1)*e + f;
   cout << "O valor do calculo e : " << calculo << endl;

   return calculo;
}

//Função que realiza o crossover entre dois binários
int crossover(int pai, int mae) {
    // Realiza o crossover combinando parte dos genes do pai e da mãe
    int genes_pai = sizeof(int) * 8; //Pega o tamanho de inteiro e multiplica por 8
    int genes_mae = genes_pai / 2;
    int metade_pai = pai & ((1 << genes_mae) - 1); // Máscara para pegar os bits menos significativos
    int metade_mae = mae >> genes_mae; // Desloca os bits da metade mais significativa para a direita
    int filho = (metade_mae << genes_mae) | metade_pai; // Combina os genes para formar o filho
    
    return filho;
}


void populacaoInicial(int tamanho, int populacao[]) {
    Individuos ind;
    srand(time(0));
    char opc;
    int max = 2000;
    int min = -2000;

    cout << "Deseja gerar uma populacao aleatoria? (s/n)" << endl;
    cin >> opc;
    for (int i = 0; i < tamanho; i++) {
        int individuo_aleatorio = min + rand() % (max - min + 1);

        // criar dois individuos geneticamente diferentes 
        if (opc == 's') {
            cout << "\nEstes sao os individuos : " << endl;
            populacao[i] = individuo_aleatorio;
            cout << populacao[i] << endl;
            cout << "Representacao binaria: ";
            retornaBin(populacao[i]);
            cout << "\n" << endl;
        }
    }
}

void realizarCross(int tamanho, int populcao[]) {
    char opCross = 's';
    // realizar crossover em pares de individuos criado para resultar em um individuo novo 

    if (opCross == 's' && tamanho >= 2) {
        for (int i = 0; i < tamanho - 1; i += 2) {
            int filho = crossover(populcao[i], populcao[i + 1]);
            cout << "Individuo resultante do crossover entre" << i + 1 << " e " << i + 2 << ": " << filho << endl;
            cout << "Representacao binaria: ";
            retornaBin(filho);
            cout << "\n" << endl;
        } // as variaveis pai e mae são usadas para fazer o crossover ex: individuo 1 e 2
    }
}

int main() {
    srand(time(0));
    char op;
    int tamanho_da_populacao = 0;
    double a=1;
    double b, c, d, e, f = 0;


    const int MAX_TAMANHO_POPULACAO = 1000; // declaração do tamanho max da população
    int populacao[MAX_TAMANHO_POPULACAO]; //atribuição do tamanho maximo da população para sofrer o crossover
    
    //Forneça valores pequenos para x, para conseguirmos uma solução satisfatória
    cout << "Forneca os valores que serao utilizados na nossa equacao: " << endl;
    cout<< "Digite o valor de a, sendo a diferente de 0" << endl;
    cin >> a;
    if (a==0){
        cout << "O 'a' tem que ser difrente de 0!" << endl;
        return 0;
    }
    cout << "Digite o valor de 'b':" << endl;
    cin >> b;

    cout << "Digite o valor de 'c':" << endl;
    cin>> c;

    cout << "Digite o valor de 'd':" << endl;
    cin >> d;

    cout << "Digite o valor de 'e':" << endl;
    cin>> e;

    cout << "Digite o valor de 'f':" << endl;
    cin >> f;
   
    

    cout << "Deseja iniciar o programa? (s/n)" << endl;
    cin >> op;
    if (op == 's') {
        cout << "Escolha o tamanho da sua populacao: {10, 100, 1000}" << endl;
        cin >> tamanho_da_populacao;
        if (tamanho_da_populacao == 10 || tamanho_da_populacao == 100 || tamanho_da_populacao == 1000) {
            populacaoInicial(tamanho_da_populacao, populacao); // armazenar individuos gerados
            realizarCross(tamanho_da_populacao, populacao); // armazenar individuos gerados apos o crossover 
            
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