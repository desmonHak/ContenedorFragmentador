#ifndef __TREE_H_
#define __TREE_H_

#include "type_data_c.h"
#include "other.h"

typedef struct nodo
{
    VarPoint_define(db, this_name_file_or_dir)
   // nombre del archivo o directorio actual

    VarPoint_define(db, back_name_file_or_dir)
    // nombre del directorio anterior

    bool file_or_dir;
    // false si es un directorio, true si es un archivo

    nodo *subNodos;
    // lista de sub Nodos que contiene este Nodo
} nodo;

typedef struct tree
{
    VarPoint_define(db, root_dir)
    // directorio raiz

    nodo *subNodos;
    // lista de sub Nodos que contiene este Arbol
} tree;

tree initTree(db * directory);
void addNodo(tree *_tree);

#include "tree.c"
#endif