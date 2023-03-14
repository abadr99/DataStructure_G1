#ifndef _BINARY_TREE_H_
#define _BINARY_TREE_H_

namespace DSA{
namespace DS{
namespace BINARY_TREE {

template<typename T>
struct Node {
    Node(T Val) : Data(Val), RightNode(nullptr), LeftNode(nullptr) {}
    T Data;
    Node<T>* RightNode;
    Node<T>* LeftNode;
};

template<typename T>
using TreeNode_t =  Node<T>*;

template<typename T>
class BinaryTree {
    public:
        BinaryTree();
        void InOrder(void (*pFun)(T& x));
        void PreOrder(void (*pFun)(T& x));
        void PostOrder(void (*pFun)(T& x));
        void LevelOrder(void (*pFun)(T& pElement)) ;
        bool IsEmpty() const;
        uint32_t GetSize() const;
        uint32_t GetHeight(TreeNode_t<T> PNode) const;
    protected:
        TreeNode_t<T> pRoot;
        uint32_t _Size;
        uint32_t _Height;
        void recur_InOrder(TreeNode_t<T> PNode, void (*pFun)(T& pElement));
        void recur_PostOrder(TreeNode_t<T> PNode, void (*pFun)(T& pElement));
        void recur_PreOrder(TreeNode_t<T> PNode, void (*pFun)(T& pElement));
};
}}} // DSA::DS::BINARY_TREE
#endif // _BINARY_TREE_H_