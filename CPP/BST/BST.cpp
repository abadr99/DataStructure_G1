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
void BST<T>::Delete(T Data) {
    BT::TreeNode_t<T> pDeletedElement = Helper_Search(Data);
    if (pDeletedElement == nullptr) return;
    BT::TreeNode_t<T> pParentOfDeletedElement = Helper_GetParent(pDeletedElement);
    // CASE-I : LEAF NODE
    if (pDeletedElement->RightNode == nullptr && pDeletedElement->LeftNode == nullptr) {
        if(pParentOfDeletedElement->LeftNode == pDeletedElement) {
            pParentOfDeletedElement->LeftNode = nullptr;
        }
        else {
            pParentOfDeletedElement->RightNode = nullptr;
        }
        delete pDeletedElement;
    }
    // CASE II-a: Have one right child 
    else if (pDeletedElement->RightNode != nullptr && pDeletedElement->LeftNode == nullptr ) {
        auto pIterator = pDeletedElement;
        while(pIterator->RightNode) {
            Helper_SwapNode(pIterator,pIterator->RightNode);
        }
        auto Parent = Helper_GetParent(pIterator);
        Parent->RightNode = nullptr;
        Helper_DeleteNode(pIterator);
    }
    // CASE II-b: Have one left child 
    else if (pDeletedElement->RightNode == nullptr && pDeletedElement->LeftNode != nullptr ) {
        auto pIterator = pDeletedElement;
        while(pIterator->LeftNode) {
            Helper_SwapNode(pIterator,pIterator->LeftNode);
        }
        auto Parent = Helper_GetParent(pIterator);
        Parent->LeftNode = nullptr;
        Helper_DeleteNode(pIterator);
    }
    // CASE III - Has two children

}
template<typename T>
void BST<T>::Helper_SwapNode(TreeNode_t<T>& _1stNode, TreeNode_t<T>& _2ndNode) {
    auto temp = _1stNode->Data;
    _1stNode->Data = _2ndNode -> Data;
    _2ndNode->Data = temp ;
}

template<typename T>
void BST<T>::Helper_DeleteNode(TreeNode_t<T>& pNode) {
    delete pNode;
}

template<typename T>
BT::TreeNode_t<T> BST<T>::Helper_GetParent(TreeNode_t<T>& pNode) {
    auto Iterator = this->pRoot;
    while(Iterator->RightNode != pNode && Iterator->LeftNode != pNode) {
        if(pNode->Data > Iterator->Data) {
            Iterator = Iterator->RightNode;
        }
        else {
            Iterator = Iterator->LeftNode;
        }
        if(Iterator == nullptr) {
            break;
        }
    }
    return Iterator;
}


template<typename T>
void BST<T>::Destroy() {

}

INSTANTIATE_CLASS_TEMPLATES(BST);
