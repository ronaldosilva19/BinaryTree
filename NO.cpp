//
// Created by ronal on 3/26/2023.
//

#include "NO.h"
#include <iostream>
using namespace std;
NO::PONT NO::Inicializa() {
    return nullptr;
}

NO::PONT NO::Adiciona(PONT raiz, PONT no) {
    if(raiz == nullptr){
        return no;
    }else if(no->chave < raiz->chave){
        raiz->esq = Adiciona(raiz->esq, no);
    }else{
        raiz->dir = Adiciona(raiz->dir, no);
    }
    return raiz;
}

NO::PONT NO::CriaNovoNO(TIPOCHAVE tipochave) {
    PONT novoNO = new NO;
    novoNO->esq = nullptr;
    novoNO->dir = nullptr;
    novoNO->chave = tipochave;
    return novoNO;
}

void NO::PrintTree(PONT raiz) {
    if(raiz != nullptr){
        cout << raiz->chave << "(";
        PrintTree(raiz->esq);
        PrintTree(raiz->dir);
        cout << ")";
    }
}