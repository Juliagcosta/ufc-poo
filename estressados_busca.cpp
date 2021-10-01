#include <iostream>
#include <vector>
using namespace std;

bool existe(vector<int> fila, int x){
    int i = 0, a = 0; 
    while(fila[i] != '\0'){
        if(x == fila[i]){
            a = 1;
            return true;
        }
        i++;
    }
    if(a == 0) return false;
}

int contar(vector<int> fila, int x){
    int i = 0, soma = 0;
    while(fila[i] != '\0'){
        if(x == fila[i]) soma++;
        i++;
    }
    return soma;
}

int procurar_valor(vector<int> fila, int x){
    int i = 0;
    while(fila[i] != '\0'){
        if(x == fila[i]){
            break;
        }
        i++;
    }
    i++;
    return i;
}

int procurar_valor_apartir(vector<int> fila, int x, int inicio){
    int i = inicio;
    while(fila[i] != '\0'){
        if(x == fila[i]){
            break;
        }
        i++;
    }
    return i;
}

int main() {
    int n;
    cout << "Informe a função para testar:\n 1 - existe \n 2 - contar \n 3 - procurar_valor \n 4 - procurar_valor_apartir \n";
    
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
    
    int ref;
    cout << "Informe a referencia: ";
    cin >> ref;
    
    if (n == 1) {
        if(existe(fila, ref)) cout << "Existe";
        else cout << "Não Existe";
    }if (n == 2) {
        cout << contar(fila, ref) << endl;
    }if (n == 3) {
        cout << procurar_valor(fila, ref) << endl;
    }if (n == 4) {
        int inicio;
        cout << "Informe o ponto de início: ";
        cin >> inicio;
        cout << procurar_valor_apartir(fila, ref, inicio) << endl;
    }

    return 0;
}
