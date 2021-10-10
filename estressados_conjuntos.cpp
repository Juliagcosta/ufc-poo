#include <iostream>
#include <vector>
using namespace std;

vector<int> exclusivos(vector<int> fila, int t){
    int i = 0, j = 1, m = 0, soma = 0;
    bool x;
    
    while (fila[i] != '\0'){
        j = i;
        while (fila[j] != '\0'){
            if (fila[i] == fila[j] && i != j){
                soma++;
            }
            j++;
        }
        i++;
    }
    
    vector<int> aux;
    t = t - soma;
    
    for (int i = 0; i < t; i++){
        aux.push_back(i);
    }
    
    i = 0;
    while (fila[i] != '\0'){
        x = true;
        j = i;
        while (fila[j] != '\0'){
            if (fila[i] == fila[j] && i != j){
                x = false;
            }
            j++;
        }
        if (x){
            aux[m] = fila[i]; 
            m++;
        }
        i++;
    }
    return aux;
}

vector<int> diferentes(vector<int> fila, int t){
    int i = 0, j = 1, m = 0, soma = 0;
    bool x;
    
    while (fila[i] != '\0'){
        if (fila[i] < 0){
            fila[i] = fila[i]*(-1);
        }
        j = i;
        while (fila[j] != '\0'){
            if (fila[j] < 0){
                fila[j] = fila[j]*(-1);
            }
            if (fila[i] == fila[j] && i != j){
                soma++;
            }
            j++;
        }
        i++;
    }
    
    vector<int> aux;
    t = t - soma;
    
    for (int i = 0; i < t; i++){
        aux.push_back(i);
    }
    
    i = 0;
    while (fila[i] != '\0'){
        x = true;
        j = i;
        while (fila[j] != '\0'){
            if (fila[i] == fila[j] && i != j){
                x = false;
            }
            j++;
        }
        if (x){
            aux[m] = fila[i]; 
            m++;
        }
        i++;
    }
    return aux;
}

vector<int> abandonados(vector<int> fila, int t){
    int i = 0, j = 1, soma = 0;
    bool x;
    
    while (fila[i] != '\0'){
        j = i;
        while (fila[j] != '\0'){
            if (fila[i] == fila[j] && i != j){
                soma++;
            }
            j++;
        }
        i++;
    }
    
    vector<int> aux;
    
    for (int i = 0; i < soma; i++){
        aux.push_back(i);
    }
    
    i = 0, soma = 0;
    while (fila[i] != '\0'){
        x = true;
        j = i;
        while (fila[j] != '\0'){
            if (fila[i] == fila[j] && i != j){
                x = false;
            }
            j++;
        }
        if (!x){
            aux[soma] = fila[i]; 
            soma++;
        }
        i++;
    }
    return aux;
}


int main() {
    int n;
    cout << "Informe a função para testar:\n 1 - exclusivos \n 2 - diferentes \n 3 - abandonados \n";
    
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
        int i = 0;
        vector<int> aux;
        aux = exclusivos(fila, tamanho);
        while (aux[i] != '\0'){
            cout << aux[i] << " ";
            i++; 
        }
    }if (n == 2){
        int i = 0;
        vector<int> aux;
        aux = diferentes(fila, tamanho);
        while (aux[i] != '\0'){
            cout << aux[i] << " ";
            i++; 
        }
    }if (n == 3){
        int i = 0;
        vector<int> aux;
        aux = abandonados(fila, tamanho);
        while (aux[i] != '\0'){
            cout << aux[i] << " ";
            i++; 
        }
    }
    
    return 0;
}
