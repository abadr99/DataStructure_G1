#ifndef _BST_H_
#define _BST_H_
#include <BinaryTree.h>
namespace DSA {
namespace DS {
namespace BINARY_TREE {
namespace BST{

enum Search_State {
    NOT_FOUND,
    FOUND,
};

template <typename T>
class BST : public BinaryTree<T> {
    public :
        void Insert(T Data);
        void Delete(T Data);
        Search_State Search(T Data);
        ~BST();
    private:
        void Helper_Insert(TreeNode_t<T>& pSubTree, T Val) ;
        TreeNode_t<T> Helper_Search(T Data);
        void Helper_SwapNode(TreeNode_t<T>& _1stNode, TreeNode_t<T>& _2ndNode);
        void Helper_DeleteNode(TreeNode_t<T>& pNode);
        TreeNode_t<T> Helper_GetParent(TreeNode_t<T>& pNode);
        void Helper_Destroy(TreeNode_t<T>& ptr) ;
};

}}}} // DSA::DS::BINART_TREE::BST
#endif // _BST_H_