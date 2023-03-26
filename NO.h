//
// Created by ronal on 3/26/2023.
//

#ifndef BINARYTREE_NO_H
#define BINARYTREE_NO_H

typedef int TIPOCHAVE;

struct NO {
    TIPOCHAVE chave;
    /* Dados armazenados vao aqui */
    struct NO *esq;
    struct NO *dir;
    typedef NO* PONT;
    static PONT Inicializa();
    static PONT Adiciona(PONT raiz, PONT no);
    static PONT CriaNovoNO(TIPOCHAVE tipochave);
    static PONT FindValue(TIPOCHAVE tipochave, PONT raiz);
    static void PrintTree(PONT raiz);
    static PONT BuscaNO(PONT raiz, TIPOCHAVE tipochave, PONT *pai);
    static PONT RemoveNO(PONT raiz, TIPOCHAVE tipochave);
};



#endif //BINARYTREE_NO_H
