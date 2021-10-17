#include <iostream>
#include <vector>
using namespace std;

vector<int> remover(vector<int> fila, int t, int ref){
    int i = 0, j = 0;
    
    while (fila[i] != '\0'){
        if(fila[i] == ref){
            t--;
        }
        i++;
    }
    
    vector<int> aux;
    
    for (i = 0; i < t; i++){
        aux.push_back(i);
    }
    
    int x = 0;
    
    i = 0;
    while (fila[i] != '\0'){
        if(fila[i] != ref){
            aux[x] = fila[i];
            x++;
        }
        i++;
    }
    
    return aux;
}

vector<int> insert(vector<int> fila, int t, int x, int p){
    int i = 0, j = 0;
    t = t + 1;
    
    vector<int> aux;
    
    for (i = 0; i < t; i++){
        aux.push_back(i);
    }
    
    p = p - 1, i = 0;
    while (i < t){
        if(i < p){
            aux[i] = fila[i];
        }else if (i == p){
            aux[i] = x;
        }else if (i > p){
            aux[i] = fila[i-1];
        }
        i++;
    }
    
    return aux;
}

int main() {
    int n;
    cout << "Informe a função para testar:\n 1 - remover \n 2 - insert \n 3 - dance \n";
    
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
        int ref;
        
        cout << "Insira a referência: ";
        cin >> ref;
        
        int i = 0;
        vector<int> aux;
        aux = remover(fila, tamanho, ref);
        while (aux[i] != '\0'){
            cout << aux[i] << " ";
            i++; 
        }
    }if (n == 2){
        int x, p;
        
        cout << "Insira o que adicionar: ";
        cin >> x;
        
        cout << "Insira a posição: ";
        cin >> p;
        
        int i = 0;
        vector<int> aux;
        aux = insert(fila, tamanho, x, p);
        while (aux[i] != '\0'){
            cout << aux[i] << " ";
            i++; 
        }
    }
    
    return 0;
}
