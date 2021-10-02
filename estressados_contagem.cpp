#include <iostream>
#include <vector>
using namespace std;

float calcular_stress_medio(vector<int> fila){
    int i = 0, soma = 0; 
    while (fila[i] != '\0'){
        soma += fila[i];
        i++;
    }
    float media = (soma*1.0)/(i*1.0);
    return media;
}

string mais_homens_ou_mulheres(vector<int> fila){
    int i = 0, n_mulheres = 0, n_homens = 0; 
    while (fila[i] != '\0'){
        if (fila[i] > 0){
            n_homens++;
        }
        else if (fila[i] < 0){
            n_mulheres++;
        }
        i++;
    }
    if (n_homens > n_mulheres) return "Homens";
    else if(n_homens < n_mulheres) return "Mulheres";
    else return "Empate";
}

string qual_metade_eh_mais_estressada(vector<int> fila, int x){
    int i = 0, p_metade = 0, s_metade = 0; 
    while (fila[i] != '\0'){
        if (i < x/2){
            p_metade += fila[i];
        }
        else if (i >= x/2 && i < x){
            s_metade += fila[i];
        }
        i++;
    }
    if(p_metade > s_metade) return "A primeira metade tem um nível de estresse maior.";
    else if(p_metade < s_metade) return "A segunda metade tem um nível de estresse maior.";
    else return "As duas metades têm níveis de estresse iguais.";
}

string homens_sao_mais_estressados_que_mulheres(vector<int> fila){
    int i = 0, s_mulheres = 0, s_homens = 0;
    int n_mulheres = 0, n_homens = 0;
    while (fila[i] != '\0'){
        if (fila[i] > 0){
            s_homens += fila[i];
            n_homens++;
        }
        else if (fila[i] < 0){
            s_mulheres += fila[i];
            n_mulheres++;
        }
        i++;
    }
    s_mulheres = s_mulheres*(-1.0);
    
    float media_h = 0, media_m = 0;
    if(n_mulheres != 0) {
        media_m = (s_mulheres*1.0)/(n_mulheres*1.0);
    }
    if(n_homens != 0) {
        media_h = (s_homens*1.0)/(n_homens*1.0);
    }
    if(media_h > media_m) return "Homens são mais estressados";
    else if(media_h < media_m) return "Mulheres são mais estressadas";
    else return "Os dois tem o mesmo nível de estresse";
}

int main() {
    int n;
    cout << "Informe a função para testar:\n 1 - calcular_stress_medio \n 2 - mais_homens_ou_mulheres \n 3 - qual_metade_eh_mais_estressada \n 4 - homens_sao_mais_estressados_que_mulheres \n";
    
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
    
    if(n == 1){
        cout << calcular_stress_medio(fila) << endl;
    }if(n == 2){
        cout << mais_homens_ou_mulheres(fila) << endl;
    }if(n == 3){
        cout << qual_metade_eh_mais_estressada(fila, tamanho) << endl;
    }if(n == 4){
        cout << homens_sao_mais_estressados_que_mulheres(fila) << endl;
    }

    return 0;
}
