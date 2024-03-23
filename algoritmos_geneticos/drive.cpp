#include <iostream>
using namespace std;
//Utilizamos a função bitwise porque ela trabalha bit a bit, assim fica mais fácil de mudar o "bit" genético


void retornaBin(int a){
    //Converte um valor decimal em binario
    int bit = 0;
    for(int i = 31; i >= 0; i--){ //vai passar bit a bit o numero que passamos com sentido a direita, sempre analisando se deveria ser 1 ou 0
        bit = (a >> i) & 1; 
        cout << bit;
    }
   
} 

//Definir um intervalo (-2000, 2000) para que achemos uma boa solução 


int main(){
    srand(time(0));
    int individuo1 = 0;
    int individuo2 = 0;
    char op;
    
    cout<<"Deseja iniciar o programa? (s/n)" << endl;
    
    cin >> op;
    if(op == 's'){
        char op;
        cout << "Deseja criar dois individuos aleatorios? (s/n)" << endl;
        cin >> op;
        if(op == 's'){
            //cria dois individuos geneticamente diferentes
            cout << "\nEste e o indivduo 2: ";
            individuo1 = rand();
            cout << individuo1 << endl;
            retornaBin(individuo1);

            cout << "\nEste e o indivduo 2: ";
            individuo2 = rand();
            cout << individuo2 << endl;
            retornaBin(individuo2);
                
                

        }
    }
    else if(op == 'n'){
        cout << "O programa sera encerrado." << endl;
        return 0;
    }

}
