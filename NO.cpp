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

NO::PONT NO::FindValue(TIPOCHAVE tipochave, PONT raiz) {
    if(raiz == nullptr){
        return nullptr;
    }else if(raiz->chave == tipochave){
        return raiz;
    }else if(raiz->chave > tipochave){
        return FindValue(tipochave, raiz->esq);
    }else{
        return FindValue(tipochave, raiz->dir);
    }
}

NO::PONT NO::BuscaNO(PONT raiz, TIPOCHAVE tipochave, PONT *pai) {
    PONT atual = raiz;
    *pai = nullptr;
    while(atual){
        if(atual->chave == tipochave){
            return atual;
        }
        *pai = atual;
        if(tipochave < atual->chave){
            atual = atual->esq;
        }else{
            atual = atual->dir;
        }
    }
    return nullptr;
}

NO::PONT NO::RemoveNO(PONT raiz, TIPOCHAVE tipochave) {
    PONT pai, no, p, q;
    no = BuscaNO(raiz, tipochave, &pai);
    if(no == nullptr){
        return raiz;
    }else if(!no->esq || !no->dir){
        if(!no->esq){
            q = no->dir;
        }else{
            q = no->esq;
        }
    }else{
        p = no;
        q = no->esq;
        while(q->dir){
            p = q;
            q = q->dir;
        }
        if(p != no){
            p->dir = q->esq;
            q->esq = no->esq;
        }
        q->dir = no->dir;
    }
    if(!pai){
        delete no;
        return q;
    }
    if(tipochave < pai->chave){
        pai->esq = q;
    }else{
        pai->dir = q;
    }
    delete no;
    return raiz;
}
void NO::PrintTree(PONT raiz) {
    if(raiz != nullptr){
        cout << raiz->chave << "(";
        PrintTree(raiz->esq);
        PrintTree(raiz->dir);
        cout << ")";
    }
}