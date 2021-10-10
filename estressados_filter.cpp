#include <iostream>
#include <vector>
using namespace std;

vector<int> clone(vector<int> fila){
    vector<int> clone(fila);
    return clone;
}

vector<int> pegar_homens(vector<int> fila){
    int i = 0, n = 0;
    
    while (fila[i] != '\0'){
        if (fila[i] > 0){
            n++;
        }
        i++;
    }
    
    vector<int> homens;
    i = 0;
    
    for (int i = 0; i < n; i++){
        homens.push_back(i);
    }
    
    i = 0, n = 0;
    
    while (fila[i] != '\0'){
        if (fila[i] > 0){
            homens[n] = fila[i];
            n++;
        }
        i++;
    }
    return homens;
}

vector<int> pegar_calmos(vector<int> fila){
    int i = 0, n = 0;
    
    while (fila[i] != '\0'){
        if (fila[i] < 10 && fila[i] > -10){
            n++;
        }
        i++;
    }
    
    vector<int> calmos;
    i = 0;
    
    for (int i = 0; i < n; i++){
        calmos.push_back(i);
    }
    
    i = 0, n = 0;
    
    while (fila[i] != '\0'){
        if (fila[i] < 10 && fila[i] > -10){
            calmos[n] = fila[i];
            n++;
        }
        i++;
    }
    return calmos;
}

vector<int> pegar_mulheres_calmas(vector<int> fila){
    int i = 0, n = 0;
    
    while (fila[i] != '\0'){
        if (fila[i] < 0 && fila[i] > -10){
            n++;
        }
        i++;
    }
    
    vector<int> m_calmas;
    i = 0;
    
    for (int i = 0; i < n; i++){
        m_calmas.push_back(i);
    }
    
    i = 0, n = 0;
    
    while (fila[i] != '\0'){
        if (fila[i] < 0 && fila[i] > -10){
            m_calmas[n] = fila[i];
            n++;
        }
        i++;
    }
    return m_calmas;
}


int main() {
    int n;
    cout << "Informe a função para testar:\n 1 - clone \n 2 - pegar_homens \n 3 - pegar_calmos \n 4 - pegar_mulheres_calmas \n";
    
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
        vector<int> cl;
        cl = clone(fila);
        while (cl[i] != '\0'){
            cout << cl[i] << " ";
            i++; 
        }
    }if (n == 2){
        int i = 0;
        vector<int> h;
        h = pegar_homens(fila);
        while (h[i] != '\0'){
            cout << h[i] << " ";
            i++; 
        }
    }if (n == 3){
        int i = 0;
        vector<int> c;
        c = pegar_calmos(fila);
        while (c[i] != '\0'){
            cout << c[i] << " ";
            i++; 
        }
    }if (n == 4){
        int i = 0;
        vector<int> mc;
        mc = pegar_mulheres_calmas(fila);
        while (mc[i] != '\0'){
            cout << mc[i] << " ";
            i++; 
        }
    }
    
    return 0;
}
