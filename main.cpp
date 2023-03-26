#include <iostream>
#include "NO.h"

using namespace std;
int main() {
    TIPOCHAVE key;
    NO::PONT r = NO::Inicializa();
    for(int i = 0; i < 6; i++){
        cin >> key;
        NO::PONT no = NO::CriaNovoNO(key);
        r = NO::Adiciona(r, no);
    }

    NO::PrintTree(r);
    TIPOCHAVE value = 22;
    NO::PONT pont = NO::FindValue(value, r);
    if(pont != nullptr){
        cout << "\nAchou o elemento " << pont->chave << " procurado.\n";
    }else{
        cout << "\nElemento " << value << " nao encontrado!\n";
    }
    return 0;
}
