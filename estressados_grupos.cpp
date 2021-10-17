#include <iostream>
#include <vector>
using namespace std;

int casais(vector<int> fila){
    int i = 0, j = 0, s_casais = 0, soma = 0;
    
    while (fila[i] != '\0'){
        while (fila[j] != '\0'){
            if (fila[i] == (-1)*fila[j] && soma != 1){
                soma++;
                s_casais++;
            }
            j++;
        }
        soma = 0;
        i++;
        j = i;
    }
    
    return s_casais;
}

int trios(vector<int> fila){
    int i = 0, j = 0, s_casais = 0, soma = 0;
    
    while (fila[i] != '\0'){
        while (fila[j] != '\0'){
            if ((fila[i] == (-1)*fila[j]) || (fila[i] == fila[j]) && soma != 2 && i != j){
                if (soma == 1){
                    s_casais++;
                }
                soma++;
            }
            j++;
        }
        soma = 0;
        i++;
        j = i;
    }
    
    return s_casais;
}

int main() {
    int n;
    cout << "Informe a função para testar:\n 1 - casais \n 2 - trios \n";
    
    cin >> n;
    
    int tamanho;
    cout << "Informe o tamanho da cadeia: ";
    cin >> tamanho;
    
    vector<int> fila;
    
    for (int i = 0; i < tamanho; i++){
        fila.push_back(i);
    }
    
    cout << "Insira a cadeia: ";
    for (int i = 0; i < tamanho; ++i){
        cin >> fila[i];
    }
    
    if (n == 1){
        cout << casais(fila) << endl;
    }if (n == 2){
        cout << trios(fila) << endl;
    }
    
    return 0;
}
