#include <iostream>
#include <utils.h>
#include <BinaryTree.h>

using namespace DSA::DS::BINARY_TREE;

template<typename T>
BinaryTree<T>::BinaryTree() : pRoot(nullptr), _Size(0), _Height(0)
{}

template<typename T>
void BinaryTree<T>::InOrder(void (*pFun)(T& x)) {
    recur_InOrder(pRoot, pFun);
}
// TODO @Noran
template<typename T>
void BinaryTree<T>::PreOrder(void (*pFun)(T& x)) {

}
// TODO @Noran
template<typename T>
void BinaryTree<T>::PostOrder(void (*pFun)(T& x)) {

}
// TODO @Noura
template<typename T>
bool BinaryTree<T>::IsEmpty() const {
    if (this->_Size) return false;
    else             return true;
}

// TODO @Noura
template<typename T>
uint32_t BinaryTree<T>::GetSize() const {

}

// TODO @Noura
template<typename T>
uint32_t BinaryTree<T>::GetHeight() const {

}


template<typename T>
void BinaryTree<T>::recur_InOrder(TreeNode_t<T> P, void (*pFun)(T& x)) {
    if(P == nullptr) {
        return;
    }
    // recur left 
    recur_InOrder(P->LeftNode, pFun);
    pFun(P->Data);
    recur_InOrder(P->RightNode, pFun);
}

INSTANTIATE_CLASS_TEMPLATES(BinaryTree);