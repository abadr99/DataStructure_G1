#include <iostream>
#include "utils.h"
#include <BinaryTree.h>
#include <BST.h>

using namespace DSA::DS::BINARY_TREE::BST;
namespace BT = DSA::DS::BINARY_TREE;
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
BT::TreeNode_t<T> BST<T>::Helper_Search(T Data) {
    BT::TreeNode_t<T> temp = this->pRoot;
    while(temp != nullptr) {
        if(temp->Data < Data) {
            temp = temp->RightNode;
        }
        else if (temp->Data < Data) {
            temp = temp->LeftNode;
        }
        else {
            return temp;
        }
    }
    return nullptr;
}

template<typename T>
Search_State BST<T>::Search(T Data) {
    BT::TreeNode_t<T> p = Helper_Search(Data);
    return p == nullptr ? Search_State::NOT_FOUND : Search_State::FOUND;
}

template<typename T>
void BST<T>::Destroy() {

}

INSTANTIATE_CLASS_TEMPLATES(BST);
