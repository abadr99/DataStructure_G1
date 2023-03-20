#include <iostream>
#include <vector>
#include <utils.h>
#include "BinaryTree.h"
#include <queue>
using namespace DSA::DS::BINARY_TREE;

template<typename T>
BinaryTree<T>::BinaryTree() : pRoot(nullptr), _Size(0), _Height(0)
{

}

template<typename T>
void BinaryTree<T>::InOrder(void (*pFun)(T& pElement)) {
    recur_InOrder(pRoot, pFun);
}

template<typename T>
void BinaryTree<T>:: InOrder(std::vector<T> &TreeVector)
{
    recur_InOrder(pRoot, TreeVector);
}
template<typename T>
void BinaryTree<T>::LevelOrder(void (*pFun)(T& pElement)) {
 std::queue<TreeNode_t<T> >q;
 if(pRoot==nullptr)
 {
    return;
 }
 q.push(pRoot);
 while(q.empty()==0)
 {
    TreeNode_t<T> node =q.front();
    pFun(node->Data);
    q.pop();
    if(node->LeftNode!=nullptr)
    {
        q.push(node->LeftNode);
    }
    if (node->RightNode!=nullptr)
    {
        q.push(node->RightNode);
    }

 }
}
// TODO @Noran
template<typename T>
void BinaryTree<T>::PreOrder(void (*pFun)(T& pElement)) {
 recur_PreOrder(pRoot, pFun);
}
template<typename T> 
void BinaryTree<T>::recur_PreOrder(TreeNode_t<T> pNode, void (*pFun)(T& pElement)) { 
    if(pNode == nullptr) { 
        return; 
    }  
    pFun(pNode->Data); 
    recur_PreOrder(pNode->LeftNode, pFun); 
    recur_PreOrder(pNode->RightNode, pFun); 
} 
// TODO @Noran
template<typename T>
void BinaryTree<T>::PostOrder(void (*pFun)(T& pElement)) {
recur_PostOrder(pRoot, pFun); 
}
template<typename T> 
    void BinaryTree<T>::recur_PostOrder(TreeNode_t<T> PNode, void (*pFun)(T& pElement)){ 
    if(PNode == nullptr) { 
        return; 
    } 
    recur_PostOrder(PNode->LeftNode, pFun); 
    recur_PostOrder(PNode->RightNode, pFun); 
    pFun(PNode->Data); 
 
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
return _Size;
}

// TODO @Noura
template<typename T>
uint32_t BinaryTree<T>::GetHeight(TreeNode_t<T> PRoot) const {
if (pRoot == NULL) 
        return 0;
    else {
        
        uint32_t left_height = GetHeight(pRoot->LeftNode);   
        uint32_t right_height = GetHeight(pRoot->RightNode);
        return right_height>left_height ? right_height+1 :left_height+1; 
}
}

template<typename T>
void BinaryTree<T>::recur_InOrder(TreeNode_t<T> PNode, void (*pFun)(T& pElement)) {
    if(PNode== nullptr) {
        return;
    }
    // recur left 
    recur_InOrder(PNode->LeftNode, pFun);
    pFun(PNode->Data);
    recur_InOrder(PNode->RightNode, pFun);
}

template<typename T>
void BinaryTree<T>:: recur_InOrder(TreeNode_t<T> PNode, std::vector<T> &TreeVector)
{
    if(PNode== nullptr) {
        return;
    }
    // recur left 
    recur_InOrder(PNode->LeftNode, TreeVector);
    TreeVector.push_back(PNode->Data);
    recur_InOrder(PNode->RightNode, TreeVector);
}

INSTANTIATE_CLASS_TEMPLATES(BinaryTree);