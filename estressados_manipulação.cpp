#include <iostream>
#include <vector>
using namespace std;

vector<int> sozinhos(vector<int> fila, int t){
    int i = 0, j = 0, k = 0, soma = 0;
    
    while (fila[i] != '\0'){
        j = i;
        while (fila[j] != '\0'){
            if ((fila[i] == fila[j] && i != j) || 
            (fila[i] == (-1)*fila[j] && i != j)){
                soma++;
            }
            j++;
        }
        if(soma > 0){
            t--;
        }
        if(soma == 0){
            while(fila[k] != '\0'){
                if((fila[i] == fila[k] && i != k) || 
                (fila[i] == (-1)*fila[k] && i != k)){
                    t--;
                    break;
                }
                k++;
            }
            k = 0;
        }
        soma = 0;
        i++;
    }
    
    vector<int> aux;
    
    for (i = 0; i < t; i++){
        aux.push_back(i);
    }
    
    bool sim = true, sim2 = true;
    int a = 0;
    i = 0, j = 0;
    
    while (fila[i] != '\0'){
        j = i;
        while (fila[j] != '\0'){
            if ((fila[i] == fila[j] && i != j) || 
            (fila[i] == (-1)*fila[j] && i != j)){
                sim = false;
            }
            j++;
        }
        if(sim){
            while(fila[k] != '\0'){
                if((fila[i] == fila[k] && i != k) || 
                (fila[i] == (-1)*fila[k] && i != k)){
                    sim2 = false;
                }
                k++;
            }
            if(sim2){
                aux[a] = fila[i];
                a++;
            }
            k = 0;
        }
        i++;
        sim = true;
        sim2 = true;
    }
    
    return aux;
}

int mais_ocorrencias(vector<int> fila, int t){
    int i = 0, j = 0, soma = 0;
    int somas[t];
    
    while (fila[i] != '\0'){
        while (fila[j] != '\0'){
            if(fila[i] == fila[j] || fila[i] == (-1)*fila[j]){
                soma++;
            }
            j++;
        }
        somas[i] = soma;
        soma = 0;
        j = 0;
        i++;
    }
    
    int maior = somas[0];
    i = 0;
    
    while (fila[i] != '\0'){
        if(somas[i] > maior){
            maior = somas[i];
        }
        i++;
    }
    
    return maior;
}

vector<int> mais_recorrentes(vector<int> fila, int t){
    int i = 0, j = 0, soma = 0;
    int somas[t];
    
    vector<int> aux;
    
    for (i = 0; i < 2; i++){
        aux.push_back(i);
    }
    
    i = 0;
    while (fila[i] != '\0'){
        somas[i] = 0;
    }
    
    i = 0;
    while (fila[i] != '\0'){
        while (fila[j] != '\0'){
            if((fila[i] == fila[j] && i != j) || 
            (fila[i] == (-1)*fila[j] && i != j)){
                somas[i] += 1;
            }
            j++;
        }
        j = 0;
        i++;
    }
    
    int a, maior = somas[0];
    i = 0;
    while (somas[i] != '\0'){
        if(somas[i] > maior){
            aux[0] = maior;
            a = i;
        }
        i++;
    }
    
    i = a + 1;
    while (somas[i] != '\0'){
        if(somas[i] < maior && i != a){
            aux[1] = maior;
        }
        i++;
    }
    
    return aux;
}

int main() {
    int n;
    cout << "Informe a função para testar:\n 1 - sozinhos \n 2 - mais_ocorrencias \n 3 - mais_recorrentes \n";
    
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
        aux = sozinhos(fila, tamanho);
        while (aux[i] != '\0'){
            cout << aux[i] << " ";
            i++; 
        }
    }if (n == 2){
        cout << mais_ocorrencias(fila, tamanho) << endl;
    }if (n == 3){
        int i = 0;
        vector<int> aux;
        aux = mais_recorrentes(fila, tamanho);
        while (aux[i] != '\0'){
            cout << aux[i] << " ";
            i++; 
        }
    }
    
    return 0;
}
