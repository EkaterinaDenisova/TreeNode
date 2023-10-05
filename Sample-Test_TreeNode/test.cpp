#include "pch.h"
#include "../ConsoleApplication1_TreeNode/TreeNode.h"

// author: Денисова Екатерина
// тестирование класса узла бинарного дерева

TreeNode<int>* createTree1() {

    // создаётся указатели на узлы дерева 
    TreeNode<int>* leftleaf, * rightleaf, * root;


    //       5
    //      / \
    //     4   22
    //        / \
    //       12  24
    //      /
    //     10

    //создаётся указатель на лист дерева (указатели на левый и правый узлы nullptr)
    leftleaf = new TreeNode<int>(10);

    //создаётся узел только с левым потомком
    root = new TreeNode<int>(12, leftleaf, nullptr);

    // указатель leftleaf переносится на только что созданный узел
    leftleaf = root;
    rightleaf = new TreeNode<int>(24);

    //создаётся узел с левым и правым потомком
    root = new TreeNode<int>(22, leftleaf, rightleaf);
    rightleaf = root;
    leftleaf = new TreeNode<int>(4);

    //создаётся узел только с правым потомком
    root = new TreeNode<int>(5, leftleaf, rightleaf);

    return root;
}

// вырожденное вправо
TreeNode<int>* createTree2() {

    // создаётся указатели на узлы дерева 
    TreeNode<int>* rightleaf, * root;


    //       10
    //        \
    //         19
    //          \
    //           30
    //            \
    //             33

    //создаётся указатель на лист дерева (указатели на левый и правый узлы nullptr)
    rightleaf = new TreeNode<int>(33);

    //создаётся узел только с правым потомком
    root = new TreeNode<int>(30, nullptr, rightleaf);

    // указатель rightleaf переносится на только что созданный узел
    rightleaf = root;

    //создаётся узел с правым потомком
    root = new TreeNode<int>(19, nullptr, rightleaf);
    rightleaf = root;

    //создаётся узел только с правым потомком
    root = new TreeNode<int>(10, nullptr, rightleaf);

    return root;
}

// вырожденное влево
TreeNode<int>* createTree3() {

    // создаётся указатели на узлы дерева 
    TreeNode<int>* leftleaf, * root;


    //       60
    //       /  
    //      54   
    //      /   
    //     14      



    //создаётся узел
    root = new TreeNode<int>(14);

    // указатель rightleaf переносится на только что созданный узел
    leftleaf = root;

    //создаётся узел с левым потомком
    root = new TreeNode<int>(54, leftleaf, nullptr);
    leftleaf = root;

    //создаётся узел только с левым потомком
    root = new TreeNode<int>(60, leftleaf, nullptr);

    return root;
}

// законченное дерево
TreeNode<int>* createTree4() {

    // создаётся указатели на узлы дерева 
    TreeNode<int>* rightleaf, *leftleaf, * root;


    //          8
    //       /    \
    //      4      10
    //    /   \    / \
    //   2     7   9   30
    //  / \    /       
    // 1   3  5        

    rightleaf = new TreeNode<int>(3);
    leftleaf = new TreeNode<int>(1);

    
    root = new TreeNode<int>(2, leftleaf, rightleaf);

    leftleaf = new TreeNode<int>(5);
    rightleaf = new TreeNode<int>(7, leftleaf, nullptr);

    root = new TreeNode<int>(4, root, rightleaf);

    leftleaf = new TreeNode<int>(9);
    rightleaf = new TreeNode<int>(30);

    rightleaf = new TreeNode<int>(10, leftleaf, rightleaf);

    root = new TreeNode<int>(8, root, rightleaf);

    return root;
}

TEST(TestTreeNode, TestHeight) {

	// создаётся указатель на корень дерева 
	TreeNode<int>*  root1 = createTree1();
	EXPECT_EQ(3, treeHeight(root1));

    // вырожденное вправо
    TreeNode<int>* root2 = createTree2();
    EXPECT_EQ(3, treeHeight(root2));

    // вырожденное влево
    TreeNode<int>* root3 = createTree3();
    EXPECT_EQ(2, treeHeight(root3));

    // завершённое дерево
    TreeNode<int>* root4 = createTree4();
    EXPECT_EQ(3, treeHeight(root4));

    // пустое дерево
    TreeNode<int>* root5 = nullptr;
    EXPECT_EQ(-1, treeHeight(root5));

    // дерево с одним узлом
    TreeNode<int>* root6 = new TreeNode<int>(2);
    EXPECT_EQ(0, treeHeight(root6));
}

// Тест нахождения количества узлов в дереве
TEST(TestTreeNode, TestCount) {

    // создаётся указатель на корень дерева 
    TreeNode<int>* root1 = createTree1();
    EXPECT_EQ(6, treeCount(root1));

    // вырожденное вправо
    TreeNode<int>* root2 = createTree2();
    EXPECT_EQ(4, treeCount(root2));

    // вырожденное влево
    TreeNode<int>* root3 = createTree3();
    EXPECT_EQ(3, treeCount(root3));

    // завершённое дерево
    TreeNode<int>* root4 = createTree4();
    EXPECT_EQ(10, treeCount(root4));

    // пустое дерево
    TreeNode<int>* root5 = nullptr;
    EXPECT_EQ(0, treeCount(root5));

    // дерево с одним узлом
    TreeNode<int>* root6 = new TreeNode<int>(2);
    EXPECT_EQ(1, treeCount(root6));
}

TEST(TestTreeNode, TestToArray) {

    // создаётся указатель на корень дерева 
    TreeNode<int>* root1 = createTree1();

    vector<int> arr, arr1 = {5, 4, 22, 12, 10, 24};
    TreeToArrayNLR(root1, arr);
    EXPECT_EQ(arr,arr1);
    arr.clear();
    arr1.clear();

    arr1 = { 4, 5, 10, 12, 22, 24 };
    TreeToArrayLNR(root1, arr);
    EXPECT_EQ(arr, arr1);
    arr.clear();
    arr1.clear();

    arr1 = { 4, 10, 12, 24, 22, 5 };
    TreeToArrayLRN(root1, arr);
    EXPECT_EQ(arr, arr1);
    arr.clear();
    arr1.clear();

    // вырожденное вправо
    TreeNode<int>* root2 = createTree2();
    
    arr1 = { 10,19,30,33 };
    TreeToArrayNLR(root2, arr);
    EXPECT_EQ(arr, arr1);
    arr.clear();
    arr1.clear();

    arr1 = { 10,19,30,33 };
    TreeToArrayLNR(root2, arr);
    EXPECT_EQ(arr, arr1);
    arr.clear();
    arr1.clear();

    arr1 = { 33,30,19,10 };
    TreeToArrayLRN(root2, arr);
    EXPECT_EQ(arr, arr1);
    arr.clear();
    arr1.clear();

    // вырожденное влево
    TreeNode<int>* root3 = createTree3();
    
    arr1 = { 60,54,14 };
    TreeToArrayNLR(root3, arr);
    EXPECT_EQ(arr, arr1);
    arr.clear();
    arr1.clear();

    arr1 = { 14,54,60 };
    TreeToArrayLNR(root3, arr);
    EXPECT_EQ(arr, arr1);
    arr.clear();
    arr1.clear();

    arr1 = { 14,54,60 };
    TreeToArrayLRN(root3, arr);
    EXPECT_EQ(arr, arr1);
    arr.clear();
    arr1.clear();


    // завершённое дерево
    TreeNode<int>* root4 = createTree4();
    
    arr1 = { 8, 4, 2, 1, 3, 7, 5, 10, 9, 30 };
    TreeToArrayNLR(root4, arr);
    EXPECT_EQ(arr, arr1);
    arr.clear();
    arr1.clear();

    arr1 = { 1, 2, 3, 4, 5, 7, 8, 9, 10, 30 };
    TreeToArrayLNR(root4, arr);
    EXPECT_EQ(arr, arr1);
    arr.clear();
    arr1.clear();

    arr1 = { 1, 3, 2, 5, 7, 4, 9, 30, 10, 8 };
    TreeToArrayLRN(root4, arr);
    EXPECT_EQ(arr, arr1);
    arr.clear();
    arr1.clear();

    // пустое дерево
    TreeNode<int>* root5 = nullptr;

    arr1 = { };
    TreeToArrayNLR(root5, arr);
    EXPECT_EQ(arr, arr1);
    arr.clear();
    arr1.clear();

    arr1 = { };
    TreeToArrayLNR(root5, arr);
    EXPECT_EQ(arr, arr1);
    arr.clear();
    arr1.clear();

    arr1 = { };
    TreeToArrayLRN(root5, arr);
    EXPECT_EQ(arr, arr1);
    arr.clear();
    arr1.clear();

    // дерево с одним узлом
    TreeNode<int>* root6 = new TreeNode<int>(2);
    arr1 = {2};
    TreeToArrayNLR(root6, arr);
    EXPECT_EQ(arr, arr1);
    arr.clear();
    arr1.clear();

    arr1 = {2};
    TreeToArrayLNR(root6, arr);
    EXPECT_EQ(arr, arr1);
    arr.clear();
    arr1.clear();

    arr1 = {2};
    TreeToArrayLRN(root6, arr);
    EXPECT_EQ(arr, arr1);
    arr.clear();
    arr1.clear();

}


TEST(TestTreeNode, TestSearch) {

    // создаётся указатель на корень дерева 
    TreeNode<int>* root1 = createTree1();
    EXPECT_EQ(2, SearchNode(root1,12));
    EXPECT_EQ(-1, SearchNode(root1, 13));

    // вырожденное вправо
    TreeNode<int>* root2 = createTree2();
    EXPECT_EQ(3, SearchNode(root2, 33));
    EXPECT_EQ(-1, SearchNode(root2, 13));

    // вырожденное влево
    TreeNode<int>* root3 = createTree3();
    EXPECT_EQ(0, SearchNode(root3, 60));
    EXPECT_EQ(-1, SearchNode(root3, 13));

    // завершённое дерево
    TreeNode<int>* root4 = createTree4();
    EXPECT_EQ(1, SearchNode(root4, 10));
    EXPECT_EQ(2, SearchNode(root4, 7));
    EXPECT_EQ(-1, SearchNode(root4, 13));

    // пустое дерево
    TreeNode<int>* root5 = nullptr;
    EXPECT_EQ(-1, SearchNode(root5, 13));

    // дерево с одним узлом
    TreeNode<int>* root6 = new TreeNode<int>(2);
    EXPECT_EQ(0, SearchNode(root6, 2));
    EXPECT_EQ(-1, SearchNode(root6, 13));
}


TEST(TestTreeNode, TestSuccessor) {
    // создаётся указатель на корень дерева 
    TreeNode<int>* root1 = createTree1();

    TreeNode<int>* s = nullptr;
    Successor(root1, s, 5);
    EXPECT_EQ(10, s->Data());

    s = nullptr;
    Successor(root1, s, 24);
    EXPECT_EQ(nullptr, s);

    // вырожденное вправо
    TreeNode<int>* root2 = createTree2();

    s = nullptr;
    Successor(root2, s, 10);
    EXPECT_EQ(19, s->Data());

    s = nullptr;
    Successor(root2, s, 33);
    EXPECT_EQ(nullptr, s);


    // вырожденное влево
    TreeNode<int>* root3 = createTree3();
    
    s = nullptr;
    Successor(root3, s, 14);
    EXPECT_EQ(54, s->Data());

    s = nullptr;
    Successor(root3, s, 60);
    EXPECT_EQ(nullptr, s);

    // завершённое дерево
    TreeNode<int>* root4 = createTree4();
    // 4 7 5 10 30
    s = nullptr;
    Successor(root4, s, 4);
    EXPECT_EQ(5, s->Data());

    s = nullptr;
    Successor(root4, s, 7);
    EXPECT_EQ(8, s->Data());


    s = nullptr;
    Successor(root4, s, 5);
    EXPECT_EQ(7, s->Data());

    s = nullptr;
    Successor(root4, s, 10);
    EXPECT_EQ(30, s->Data());

    s = nullptr;
    Successor(root4, s, 30);
    EXPECT_EQ(nullptr, s);

    // пустое дерево
    TreeNode<int>* root5 = nullptr;

    s = nullptr;
    Successor(root5, s, 10);
    EXPECT_EQ(nullptr, s);

    // дерево с одним узлом
    TreeNode<int>* root6 = new TreeNode<int>(2);
    s = nullptr;
    Successor(root6, s, 2);
    EXPECT_EQ(nullptr, s);
}


