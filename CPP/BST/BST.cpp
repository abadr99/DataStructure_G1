#include <iostream>
#include <Utils\utils.h>
#include <BinaryTree.h>
#include <BST.h>

using namespace DSA::DS::BINARY_TREE::BST;

template<typename T>
void BST<T>::Insert_recur(TreeNode_t<T>& pSubTree, Node<T>*& pNode) {
    if (pNode == nullptr) {
        return;
    }
    if (pSubTree->RightNode == nullptr && pSubTree->Data < pNode->Data) {
        pSubTree->RightNode = pNode;
    }
    else if (pSubTree->LeftNode == nullptr && pSubTree->Data > pNode->Data) {
        pSubTree->LeftNode = pNode;
    }
    if (pSubTree->Data < pNode->Data) {
        Insert_recur(pSubTree->RightNode,  pNode);
    } else {
        Insert_recur(pSubTree->LeftNode,  pNode);
    }
 }
template<typename T>
void BST<T>::Insert(T Data) {
    // 1) Create node
    auto pNewNode = new Node<T>(Data);
    // 2) 
    Insert_recur(this->pNode,Data);
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
