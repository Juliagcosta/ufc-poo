#include <iostream>
#include <vector>
using namespace std;

int procurar_menor(vector<int> fila){
    int i = 0, menor = fila[0]; 
    while (fila[i] != '\0'){
        if (fila[i] < menor){
            menor = fila[i];
        }
        i++;
    }
    return menor;
}

int procurar_menor_pos(vector<int> fila){
    int i = 0, menor = fila[0], pos = 0; 
    while (fila[i] != '\0'){
        if (fila[i] < menor){
            menor = fila[i];
            pos = i;
        }
        i++;
    }
    return pos;
}

int procurar_menor_pos_apartir(vector<int> fila, int inicio){
    int i = inicio; 
    int menor = fila[inicio], pos = inicio;
    while (fila[i] != '\0'){
        if (fila[i] < menor){
            menor = fila[i];
            pos = i;
        }
        i++;
    }
    return pos;
}

int procurar_melhor_pos_se(vector<int> fila){
    int i = 0, homem = 0, pos, menor; 
    if (fila[0] > 0){
            menor = fila[0];
            pos = 0;
            homem++;
    }
    while (fila[i] != '\0'){
        if (fila[i] > 0 && fila[i] < menor){
            menor = fila[i];
            pos = i;
            homem++;
        }
        i++;
    }
    if (homem == 0) return -1;
    else return pos;
}

int main() {
    int n;
    cout << "Informe a função para testar:\n 1 - procurar_menor \n 2 - procurar_menor_pos \n 3 - procurar_menor_pos_apartir \n 4 - procurar_melhor_pos_se \n";
    
    cin >> n;
    
    int tamanho;
    cout << "Informe o tamanho da cadeia: ";
    cin >> tamanho;
    
    vector<int> fila;
    
    for (int i = 0; i < tamanho; i++)
        fila.push_back(i);
    
    cout << "Insira a cadeia: ";
    for (int i = 0; i < tamanho; ++i){
        cin >> fila[i];
    }
    
    if (n == 1) {
        cout << procurar_menor(fila) << endl;
    }if (n == 2) {
        cout << procurar_menor_pos(fila) << endl;
    }if (n == 3) {
        int inicio;
        cout << "Informe o ponto de início: ";
        cin >> inicio;
        cout << procurar_menor_pos_apartir(fila, inicio) << endl;
    }if (n == 4) {
        cout << procurar_melhor_pos_se(fila) << endl;
    }

    return 0;
}
