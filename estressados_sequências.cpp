#include <iostream>
#include <vector>
using namespace std;

//Duas ou mais pessoas do mesmo sexo seguidas podem formar um time. Quantos times existem na fila?
int quantos_times(vector<int> fila){
    int i = 0, j = 1, soma = 0, times = 0;
    
    while (fila[i] != '\0'){
        if (fila[i] > 0){
            while (fila[j] != '\0'){
                if (fila[j] > 0){
                    soma++;
                }
                else {
                    i = j - 1;
                    break;
                }
                j++;
            }
            if (soma >= 1){
                times++;
            }
        }
        else if (fila[i] < 0){
            while (fila[j] != '\0'){
                if (fila[j] < 0){
                    soma++;
                }
                else {
                    i = j - 1;
                    break;
                }
                j++;
            }
            if (soma >= 1){
                times++;
            }
        }
        soma = 0;
        j++;
        i++;
    }
    
    return times;
}

//Qual o maior time que apareceu na fila?
vector<int> maior_time(vector<int> fila){
    int i = 0, j = 1, soma = 0, times = 0;
    
    while (fila[i] != '\0'){
        if (fila[i] > 0){
            while (fila[j] != '\0'){
                if (fila[j] > 0){
                    soma++;
                }
                else {
                    i = j - 1;
                    break;
                }
                j++;
            }
            if (soma >= 1){
                times++;
            }
        }
        else if (fila[i] < 0){
            while (fila[j] != '\0'){
                if (fila[j] < 0){
                    soma++;
                }
                else {
                    i = j - 1;
                    break;
                }
                j++;
            }
            if (soma >= 1){
                times++;
            }
        }
        soma = 0;
        j++;
        i++;
    }
    
    int t_times[times];
    
    for (i = 0; i < times; i++){
        t_times[i] = 1;
    }
    
    int x = 0;
    
    i = 0, j = 1;
    while (fila[i] != '\0'){
        if (fila[i] > 0){
            while (fila[j] != '\0'){
                if (fila[j] > 0){
                    t_times[x]++;
                    soma++;
                }
                else {
                    if(soma >= 1){
                        x++;
                    }
                    i = j - 1;
                    break;
                }
                j++;
            }
        }
        else if (fila[i] < 0){
            while (fila[j] != '\0'){
                if (fila[j] < 0){
                    t_times[x]++;
                    soma++;
                }
                else {
                    if(soma >= 1){
                        x++;
                    }
                    i = j - 1;
                    break;
                }
                j++;
            }
        }
        soma = 0;
        j++;
        i++;
    }
    
    int maior = t_times[0];
    i = 0;
    while (i != 5){
        if(t_times[i] > maior){
            maior = t_times[i];
        }
        i++;
    }
    
    int marca;
    i = 0, j = 1, soma = 1;
    while (fila[i] != '\0'){
        if (fila[i] > 0){
            while (fila[j] != '\0'){
                if (fila[j] > 0){
                    soma++;
                }
                else {
                    if(soma == maior){
                        marca = i;
                    }
                    i = j - 1;
                    break;
                }
                j++;
            }
        }
        else if (fila[i] < 0){
            while (fila[j] != '\0'){
                if (fila[j] < 0){
                    soma++;
                }
                else {
                    if(soma == maior){
                        marca = i;
                    }
                    i = j - 1;
                    break;
                }
                j++;
            }
        }
        soma = 1;
        j++;
        i++;
    }
    
    vector<int> aux;
    
    for (i = 0; i < maior; i++){
        aux.push_back(i);
    }
    
    int limite = marca + maior;
    int p = 0;
    
    for (i = marca; i < limite; i++){
        aux[p] = fila[i];
        p++;
    }
    
    return aux;
}

//Quantas pessoas não estavam em um time?
vector<int> sozinhos(vector<int> fila, int t){
    int i = 0, j = 1, soma = 1, soma1 = 0;
    
    while (fila[i] != '\0'){
        if (fila[i] > 0){
            while (fila[j] != '\0'){
                if (fila[j] > 0){
                    soma++;
                    soma1++;
                }
                else {
                    if (soma1 != 0){
                        soma++;
                    }
                    i = j - 1;
                    break;
                }
                j++;
            }
        }
        else if (fila[i] < 0){
            while (fila[j] != '\0'){
                if (fila[j] < 0){
                    soma++;
                    soma1++;
                }
                else {
                    if (soma1 != 0){
                        soma++;
                    }
                    i = j - 1;
                    break;
                }
                j++;
            }
        }
        soma1 = 0;
        j++;
        i++;
    }
    
    int a = t - soma, x = 0;
    vector<int> aux;
    
    for (i = 0; i < a; i++){
        aux.push_back(i);
    }
    
    i = 0, j = 1;
    while (fila[i] != '\0'){
        if (fila[i] > 0){
            while (fila[j] != '\0'){
                if (fila[j] > 0){
                    soma++;
                }
                else {
                    if(soma == 0){
                        aux[x] = fila[i];
                        x++;
                    }
                    i = j - 1;
                    break;
                }
                j++;
            }
        }
        else if (fila[i] < 0){
            while (fila[j] != '\0'){
                if (fila[j] < 0){
                    soma++;
                }
                else {
                    if(soma == 0){
                        aux[x] = fila[i];
                        x++;
                    }
                    i = j - 1;
                    break;
                }
                j++;
            }
        }
        soma = 0;
        j++;
        i++;
    }
    
    return aux;
}

int main() {
    int n;
    cout << "Informe a função para testar:\n 1 - quantos_times \n 2 - maior_time \n 3 - sozinhos \n";
    
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
        cout << quantos_times(fila) << endl;
    }if (n == 2){
        int i = 0;
        vector<int> aux;
        aux = maior_time(fila);
        while (aux[i] != '\0'){
            cout << aux[i] << " ";
            i++; 
        }
    }if (n == 3){
        int i = 0;
        vector<int> aux;
        aux = sozinhos(fila, tamanho);
        while (aux[i] != '\0'){
            cout << aux[i] << " ";
            i++; 
        }
    }
    
    return 0;
}
