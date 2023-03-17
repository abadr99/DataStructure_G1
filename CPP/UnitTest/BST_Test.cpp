#include <iostream>
#include <vector>
#include "SonicTest.h"
#include "Stack.h"
#include "BST.h"
#include "BinaryTree.h"
#include "BST_Test.h"


TEST(BST_Insert)
{
    using namespace DSA::DS::BINARY_TREE::BST;
    START_TEST(BST_Insert);
    std::vector<int> TreeVector;
    int _Iterator=0;
    int TreeArray[]={50,70,71,75,77,80,100,110,115,120,125,130,140};
    BST<int> B;
    B.Insert(100);
    B.Insert(70);
    B.Insert(50);
    B.Insert(80);
    B.Insert(130);
    B.Insert(110);
    B.Insert(140);
    B.Insert(120);
    B.Insert(115);
    B.Insert(125);
    B.Insert(75);
    B.Insert(71);
    B.Insert(77);
    B.InOrder(TreeVector);
    for(int _VectorIterator : TreeVector){
        EXPECT_EQ(TreeArray[_Iterator] ,_VectorIterator );
        _Iterator++;
    }
}
TEST(BST_Delete)
{
    using namespace DSA::DS::BINARY_TREE::BST;
    START_TEST(BST_Delete Delete Node Has One Right Child : TEST);
    std::vector<int> TreeVector;
    int _Iterator=0;
    int TreeArray_1[]={50,70,71,75,77,80,100,115,120,125,130,140};
    BST<int> B;
    B.Insert(100);
    B.Insert(70);
    B.Insert(50);
    B.Insert(80);
    B.Insert(130);
    B.Insert(110);
    B.Insert(140);
    B.Insert(120);
    B.Insert(115);
    B.Insert(125);
    B.Insert(75);
    B.Insert(71);
    B.Insert(77);
    B.Delete(110);
    B.InOrder(TreeVector);
    for(int _VectorIterator : TreeVector){
        EXPECT_EQ(TreeArray_1[_Iterator] ,_VectorIterator );
        _Iterator++;
    }


    _Iterator=0;
    TreeVector.clear();
    START_TEST(BST_Delete Delete Node Has One Left Child   TEST);
    B.Delete(80);
    B.InOrder(TreeVector);
    int TreeArray_2[]={50,70,71,75,77,100,115,120,125,130,140};
    for(int _VectorIterator : TreeVector){
        EXPECT_EQ(TreeArray_2[_Iterator] ,_VectorIterator );
        _Iterator++;
    }


    _Iterator=0;
    TreeVector.clear();
    START_TEST(BST_Delete Delete Node Has Two Child   TEST);
    B.Delete(130);
    B.InOrder(TreeVector);
    int TreeArray_3[]={50,70,71,75,77,100,115,120,125,140};
        for(int _VectorIterator : TreeVector){
        EXPECT_EQ(TreeArray_3[_Iterator] ,_VectorIterator );
        _Iterator++;
    }

    _Iterator=0;
    TreeVector.clear();
    START_TEST(BST_Delete Delete Leaf Node   TEST);
    B.Delete(77);
    B.InOrder(TreeVector);
    int TreeArray_4[]={50,70,71,75,100,115,120,125,140};
        for(int _VectorIterator : TreeVector){
        EXPECT_EQ(TreeArray_4[_Iterator] ,_VectorIterator );
        _Iterator++;
    }

    _Iterator=0;
    TreeVector.clear();
    START_TEST(BST_Delete Delete Root Node   TEST);
    B.Delete(100);
    B.InOrder(TreeVector);
    int TreeArray_5[]={50,70,71,75,115,120,125,140};
        for(int _VectorIterator : TreeVector){
        EXPECT_EQ(TreeArray_5[_Iterator] ,_VectorIterator );
        _Iterator++;
    }
}
TEST(BST_Search)
{
    using namespace DSA::DS::BINARY_TREE::BST;
    START_TEST(BST_Search  TEST);
    BST<int> B;
    B.Insert(100);
    B.Insert(70);
    B.Insert(50);
    B.Insert(80);
    B.Insert(130);
    B.Insert(110);
    EXPECT_EQ(B.Search(130),FOUND );
    EXPECT_EQ(B.Search(100),FOUND );
    EXPECT_EQ(B.Search(50 ),FOUND );
    EXPECT_EQ(B.Search(30 ),NOT_FOUND );


}