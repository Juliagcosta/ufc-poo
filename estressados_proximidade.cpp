#include <iostream>
#include <vector>
using namespace std;

int briga(vector<int> fila){
    int i = 0, soma = 0;
    
    while (fila[i] != '\0'){
        if (fila[i] > 50 || fila[i] < -50){
            if (fila[i + 1] > 30 || fila[i + 1] < -30 || 
            fila[i - 1] < -30 || fila[i - 1] > 30){
                soma++;
            }
        }
        i++;
    }
    
    return soma;
}

vector<int> apaziguado(vector<int> fila){
    int i = 0, soma = 0, a = 0;
    
    while (fila[i] != '\0'){
        if (fila[i] > 80 || fila[i] < -80){
            if ((fila[i + 1] < 30 && fila[i + 1] > -30) ||
            (fila[i - 1] < 30 && fila[i - 1] > -30)){
                soma++;
            }
        }
        i++;
    }
    
    vector<int> aux;
    
    for (i = 0; i < soma; i++){
        aux.push_back(i);
    }
    
    i = 0;
    while (fila[i] != '\0'){
        if (fila[i] > 80 || fila[i] < -80){
            if ((fila[i + 1] < 30 && fila[i + 1] > -30) ||
            (fila[i - 1] < 30 && fila[i - 1] > -30)){
                aux[a] = i + 1;
                a++;
            }
        }
        i++;
    }
    
    return aux;
}

int main() {
    int n;
    cout << "Informe a função para testar:\n 1 - briga \n 2 - apaziguado \n";
    
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
        cout << briga(fila) << " vezes." << endl;
    }if (n == 2){
        int i = 0;
        vector<int> aux;
        aux = apaziguado(fila);
        while (aux[i] != '\0'){
            cout << aux[i] << " ";
            i++; 
        }
    }
    
    return 0;
}
