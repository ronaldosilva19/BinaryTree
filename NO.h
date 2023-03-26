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
    static void PrintTree(PONT raiz);
};



#endif //BINARYTREE_NO_H
