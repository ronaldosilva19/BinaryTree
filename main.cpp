#include <iostream>
#include "NO.h"

using namespace std;
int main() {
    TIPOCHAVE key;
    NO::PONT r = NO::Inicializa();
    for(int i = 0; i < 10; i++){
        cin >> key;
        NO::PONT no = NO::CriaNovoNO(key);
        r = NO::Adiciona(r, no);
    }

    NO::PrintTree(r);
    return 0;
}
