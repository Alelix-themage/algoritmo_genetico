#include <iostream>
using namespace std;
//Utilizamos a função bitwise porque ela trabalha bit a bit, assim fica mais fácil de mudar o "bit" genético

//struct com o individuo e o array de individuo
struct Individuos{
    int individuo = 0;
    int individuos[];
};

void retornaBin(int a){
    //Converte um valor decimal em binario
    int bit = 0;
    for(int i = 31; i >= 0; i--){ //vai passar bit a bit o numero que passamos com sentido a direita, sempre analisando se deveria ser 1 ou 0
        bit = (a >> i) & 1; 
        cout << bit;
    }
   
} 

void populacaoInicial(int tamanho){
    Individuos ind;
    srand(time(0));
    char opc;
    int max = 2000;
    int min = -2000;
   
    cout << "Deseja gerar uma populacao aleatoria? (s/n)" << endl;
    cin >> opc;
    for(int i = 0; i < tamanho; i++){
      int individuo_aleatorio = min +rand() % (max - min +1);
    
     // criar dois individuos geneticamente diferentes 
        if(opc == 's'){
            cout << "\nEstes e o individuos : " << endl;
            ind.individuos[i] = individuo_aleatorio;
            cout<< ind.individuos[i] << endl;
            retornaBin(ind.individuos[i]);
            cout <<"\n" << endl;
        }
    }
}

 
  
int main(){
    srand(time(0));
    char op;
   int tamanho_da_populacao = 0;
    
    cout<<"Deseja iniciar o programa? (s/n)" << endl;
    cin >> op;
    if(op =='s'){
        cout << "Escolha o tamanho da sua populacao: {10, 100, 1000}" << endl;
        cin >> tamanho_da_populacao;
        if(tamanho_da_populacao == 10 || tamanho_da_populacao == 100 || tamanho_da_populacao == 1000){   
            populacaoInicial(tamanho_da_populacao);
        }
        else {
            cout<<"Nao sao permitidas populacoes que nao tenham tamanho de 10, 100 ou 1000!" << endl;
            return 0;
        }
    }

    else{
        cout<<"O programa sera encerrado!" << endl;
        return 0;
    }

   
    
    
}

