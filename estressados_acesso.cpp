#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

vector<int> inverter_com_copia(vector<int> fila, int t){
    int i = 0;
    vector<int> aux;
    
    for (int i = 0; i < t; i++){
        aux.push_back(i);
    }
    
    i = 0, t--;
    while (fila[i] != '\0'){
        aux[t] = fila[i];
        i++;
        t--;
    }
    return aux;
}

vector<int> inverter_inplace(vector<int> fila, int t){
    int i = 0, save;
    int met = t/2;
    t--;
    while (i < met){
        save = fila[i];
        fila[i] = fila[t];
        fila[t] = save;
        i++;
        t--;
    }
    return fila;
}

int sortear(vector<int> fila, int t){
    int r = rand() % t;
    return fila[r];
}

vector<int> embaralhar(vector<int> fila, int t){
    int i = 0, r, save;
    int met = t/2;
    vector<int> aux;
    
    for (int i = 0; i < t; i++){
        aux.push_back(i);
    }
    
    i = 0;
    while (fila[i] != '\0'){
        aux[i] = fila[i];
        i++;
    }
    
    i = 0;
    while (i < met){
        r = rand() % t;
        if (i != r){
            aux[i] = fila[r];
            aux[r] = fila[i];
        }
        i++;
    }
    return aux;
}

vector<int> ordenar(vector<int> fila, int t){
    int i = 0, menor, p, j, save;
    bool troca;
    
    vector<int> aux;
    
    for (int i = 0; i < t; i++){
        aux.push_back(i);
    }
    
    i = 0, t--;
    while (fila[i] != '\0'){
        aux[i] = fila[i];
        i++;
    }
    
    i = 0;
    while (fila[i] != '\0'){
        menor = aux[i];
        p = i;
        troca = false;
        j = i + 1;
        while (fila[j] != '\0'){
            if (aux[j] < menor){
                menor = aux[j];
                p = j;
                troca = true;
            }
            j++;
        }
        if (troca){
            save = aux[i];
            aux[i] = menor;
            aux[p] = save;
        }
        i++;
    }
    return aux;
}

int main() {
    int n;
    cout << "Informe a função para testar:\n 1 - inverter_com_copia \n 2 - inverter_inplace \n 3 - sortear \n 4 - embaralhar \n 5 - ordenar \n";
    
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
        aux = inverter_com_copia(fila, tamanho);
        while (aux[i] != '\0'){
            cout << aux[i] << " ";
            i++; 
        }
    }if (n == 2){
        int i = 0;
        vector<int> inplace;
        inplace = inverter_inplace(fila, tamanho);
        while (inplace[i] != '\0'){
            cout << inplace[i] << " ";
            i++; 
        }
    }if (n == 3){
        cout << sortear(fila, tamanho) << endl;
    }if (n == 4){
        int i = 0;
        vector<int> emb;
        emb = embaralhar(fila, tamanho);
        while (emb[i] != '\0'){
            cout << emb[i] << " ";
            i++; 
        }
    }if (n == 5){
        int i = 0;
        vector<int> ord;
        ord = ordenar(fila, tamanho);
        while (ord[i] != '\0'){
            cout << ord[i] << " ";
            i++; 
        }
    }
    
    return 0;
}
