#include <iostream>
#include "utils.h"
#include <BinaryTree.h>
#include <BST.h>

using namespace DSA::DS::BINARY_TREE::BST;

template<typename T>
void BST<T>::Helper_Insert(TreeNode_t<T>& pSubTree, T Val) {
    if (pSubTree == nullptr) {
        pSubTree = new Node<T>(Val);
        return;
    }
    else if (Val > pSubTree->Data) {
        Helper_Insert(pSubTree->RightNode,Val);
    }
    else if (Val < pSubTree->Data)  {
        Helper_Insert(pSubTree->LeftNode,Val);
    }
    else {
        // Erorr handling
    }
 }
template<typename T>
void BST<T>::Insert(T Data) {
    Helper_Insert(this->pRoot,Data);
    this->_Size ++;
}

template<typename T>
void BST<T>::Delete(T Data) {
}

template<typename T>
void BST<T>::Search(T Data) {

}

template<typename T>
void BST<T>::Destroy() {

}

INSTANTIATE_CLASS_TEMPLATES(BST);
