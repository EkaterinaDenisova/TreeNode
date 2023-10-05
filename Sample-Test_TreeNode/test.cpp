#include "pch.h"
#include "../ConsoleApplication1_TreeNode/TreeNode.h"

// author: �������� ���������
// ������������ ������ ���� ��������� ������

TreeNode<int>* createTree1() {

    // �������� ��������� �� ���� ������ 
    TreeNode<int>* leftleaf, * rightleaf, * root;


    //       5
    //      / \
    //     4   22
    //        / \
    //       12  24
    //      /
    //     10

    //�������� ��������� �� ���� ������ (��������� �� ����� � ������ ���� nullptr)
    leftleaf = new TreeNode<int>(10);

    //�������� ���� ������ � ����� ��������
    root = new TreeNode<int>(12, leftleaf, nullptr);

    // ��������� leftleaf ����������� �� ������ ��� ��������� ����
    leftleaf = root;
    rightleaf = new TreeNode<int>(24);

    //�������� ���� � ����� � ������ ��������
    root = new TreeNode<int>(22, leftleaf, rightleaf);
    rightleaf = root;
    leftleaf = new TreeNode<int>(4);

    //�������� ���� ������ � ������ ��������
    root = new TreeNode<int>(5, leftleaf, rightleaf);

    return root;
}

// ����������� ������
TreeNode<int>* createTree2() {

    // �������� ��������� �� ���� ������ 
    TreeNode<int>* rightleaf, * root;


    //       10
    //        \
    //         19
    //          \
    //           30
    //            \
    //             33

    //�������� ��������� �� ���� ������ (��������� �� ����� � ������ ���� nullptr)
    rightleaf = new TreeNode<int>(33);

    //�������� ���� ������ � ������ ��������
    root = new TreeNode<int>(30, nullptr, rightleaf);

    // ��������� rightleaf ����������� �� ������ ��� ��������� ����
    rightleaf = root;

    //�������� ���� � ������ ��������
    root = new TreeNode<int>(19, nullptr, rightleaf);
    rightleaf = root;

    //�������� ���� ������ � ������ ��������
    root = new TreeNode<int>(10, nullptr, rightleaf);

    return root;
}

// ����������� �����
TreeNode<int>* createTree3() {

    // �������� ��������� �� ���� ������ 
    TreeNode<int>* leftleaf, * root;


    //       60
    //       /  
    //      54   
    //      /   
    //     14      



    //�������� ����
    root = new TreeNode<int>(14);

    // ��������� rightleaf ����������� �� ������ ��� ��������� ����
    leftleaf = root;

    //�������� ���� � ����� ��������
    root = new TreeNode<int>(54, leftleaf, nullptr);
    leftleaf = root;

    //�������� ���� ������ � ����� ��������
    root = new TreeNode<int>(60, leftleaf, nullptr);

    return root;
}

// ����������� ������
TreeNode<int>* createTree4() {

    // �������� ��������� �� ���� ������ 
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

	// �������� ��������� �� ������ ������ 
	TreeNode<int>*  root1 = createTree1();
	EXPECT_EQ(3, treeHeight(root1));

    // ����������� ������
    TreeNode<int>* root2 = createTree2();
    EXPECT_EQ(3, treeHeight(root2));

    // ����������� �����
    TreeNode<int>* root3 = createTree3();
    EXPECT_EQ(2, treeHeight(root3));

    // ����������� ������
    TreeNode<int>* root4 = createTree4();
    EXPECT_EQ(3, treeHeight(root4));

    // ������ ������
    TreeNode<int>* root5 = nullptr;
    EXPECT_EQ(-1, treeHeight(root5));

    // ������ � ����� �����
    TreeNode<int>* root6 = new TreeNode<int>(2);
    EXPECT_EQ(0, treeHeight(root6));
}

// ���� ���������� ���������� ����� � ������
TEST(TestTreeNode, TestCount) {

    // �������� ��������� �� ������ ������ 
    TreeNode<int>* root1 = createTree1();
    EXPECT_EQ(6, treeCount(root1));

    // ����������� ������
    TreeNode<int>* root2 = createTree2();
    EXPECT_EQ(4, treeCount(root2));

    // ����������� �����
    TreeNode<int>* root3 = createTree3();
    EXPECT_EQ(3, treeCount(root3));

    // ����������� ������
    TreeNode<int>* root4 = createTree4();
    EXPECT_EQ(10, treeCount(root4));

    // ������ ������
    TreeNode<int>* root5 = nullptr;
    EXPECT_EQ(0, treeCount(root5));

    // ������ � ����� �����
    TreeNode<int>* root6 = new TreeNode<int>(2);
    EXPECT_EQ(1, treeCount(root6));
}

TEST(TestTreeNode, TestToArray) {

    // �������� ��������� �� ������ ������ 
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

    // ����������� ������
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

    // ����������� �����
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


    // ����������� ������
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

    // ������ ������
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

    // ������ � ����� �����
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

    // �������� ��������� �� ������ ������ 
    TreeNode<int>* root1 = createTree1();
    EXPECT_EQ(2, SearchNode(root1,12));
    EXPECT_EQ(-1, SearchNode(root1, 13));

    // ����������� ������
    TreeNode<int>* root2 = createTree2();
    EXPECT_EQ(3, SearchNode(root2, 33));
    EXPECT_EQ(-1, SearchNode(root2, 13));

    // ����������� �����
    TreeNode<int>* root3 = createTree3();
    EXPECT_EQ(0, SearchNode(root3, 60));
    EXPECT_EQ(-1, SearchNode(root3, 13));

    // ����������� ������
    TreeNode<int>* root4 = createTree4();
    EXPECT_EQ(1, SearchNode(root4, 10));
    EXPECT_EQ(2, SearchNode(root4, 7));
    EXPECT_EQ(-1, SearchNode(root4, 13));

    // ������ ������
    TreeNode<int>* root5 = nullptr;
    EXPECT_EQ(-1, SearchNode(root5, 13));

    // ������ � ����� �����
    TreeNode<int>* root6 = new TreeNode<int>(2);
    EXPECT_EQ(0, SearchNode(root6, 2));
    EXPECT_EQ(-1, SearchNode(root6, 13));
}


TEST(TestTreeNode, TestSuccessor) {
    // �������� ��������� �� ������ ������ 
    TreeNode<int>* root1 = createTree1();

    TreeNode<int>* s = nullptr;
    Successor(root1, s, 5);
    EXPECT_EQ(10, s->Data());

    s = nullptr;
    Successor(root1, s, 24);
    EXPECT_EQ(nullptr, s);

    // ����������� ������
    TreeNode<int>* root2 = createTree2();

    s = nullptr;
    Successor(root2, s, 10);
    EXPECT_EQ(19, s->Data());

    s = nullptr;
    Successor(root2, s, 33);
    EXPECT_EQ(nullptr, s);


    // ����������� �����
    TreeNode<int>* root3 = createTree3();
    
    s = nullptr;
    Successor(root3, s, 14);
    EXPECT_EQ(54, s->Data());

    s = nullptr;
    Successor(root3, s, 60);
    EXPECT_EQ(nullptr, s);

    // ����������� ������
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

    // ������ ������
    TreeNode<int>* root5 = nullptr;

    s = nullptr;
    Successor(root5, s, 10);
    EXPECT_EQ(nullptr, s);

    // ������ � ����� �����
    TreeNode<int>* root6 = new TreeNode<int>(2);
    s = nullptr;
    Successor(root6, s, 2);
    EXPECT_EQ(nullptr, s);
}

TEST(TestTreeNode, TestInsertNode) {
    // �������� ��������� �� ������ ������ 
    TreeNode<int>* root1 = createTree1();

    root1 = InsertNode(root1, 5);
    vector<int> arr, arr1 = { 4, 5, 10, 12, 22, 24 };
    TreeToArrayLNR(root1, arr);
    EXPECT_EQ(arr, arr1);
    arr.clear();
    //       5
    //      / \
    //     4   22
    //        / \
    //       12  24
    //      /
    //     10

    root1 = InsertNode(root1, 6);
    arr1 = { 4, 5, 6, 10, 12, 22, 24 };
    TreeToArrayLNR(root1, arr);
    EXPECT_EQ(arr, arr1);
    arr.clear();


    root1 = InsertNode(root1, 13);
    arr1 = { 4, 5, 6, 10, 12, 13, 22, 24 };
    TreeToArrayLNR(root1, arr);
    EXPECT_EQ(arr, arr1);
    arr.clear();


    // ����������� ������
    TreeNode<int>* root2 = createTree2();
    root2 = InsertNode(root2, 19);
    arr1 = { 10, 19, 30, 33 };
    TreeToArrayLNR(root2, arr);
    EXPECT_EQ(arr, arr1);
    arr.clear();
    //       10
    //        \
    //         19
    //          \
    //           30
    //            \
    //             33

    root2 = InsertNode(root2, 20);
    arr1 = { 10, 19, 20, 30, 33 };
    TreeToArrayLNR(root2, arr);
    EXPECT_EQ(arr, arr1);
    arr.clear();


    // ����������� �����
    TreeNode<int>* root3 = createTree3();
    root3 = InsertNode(root3, 14);
    arr1 = { 14, 54, 60 };
    TreeToArrayLNR(root3, arr);
    EXPECT_EQ(arr, arr1);
    arr.clear();
    //       60
    //       /  
    //      54   
    //      /   
    //     14  

    root3 = InsertNode(root3, 52);
    arr1 = { 14, 52, 54, 60 };
    TreeToArrayLNR(root3, arr);
    EXPECT_EQ(arr, arr1);
    arr.clear();

    // ����������� ������
    TreeNode<int>* root4 = createTree4();
    root4 = InsertNode(root4, 2);
    arr1 = { 1, 2, 3, 4, 5, 7, 8, 9, 10, 30 };
    TreeToArrayLNR(root4, arr);
    EXPECT_EQ(arr, arr1);
    arr.clear();
    //          8
    //       /    \
    //      4      10
    //    /   \    / \
    //   2     7   9   30
    //  / \    /       
    // 1   3  5 

    root4 = InsertNode(root4, 6);
    arr1 = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 30 };
    TreeToArrayLNR(root4, arr);
    EXPECT_EQ(arr, arr1);
    arr.clear();

    // ������ ������
    TreeNode<int>* root5 = nullptr;
    root5 = InsertNode(root5, 12);
    arr1 = { 12 };
    TreeToArrayLNR(root5, arr);
    EXPECT_EQ(arr, arr1);
    arr.clear();


    // ������ � ����� �����
    TreeNode<int>* root6 = new TreeNode<int>(2);
    root6 = InsertNode(root6, 15);
    arr1 = { 2, 15 };
    TreeToArrayLNR(root6, arr);
    EXPECT_EQ(arr, arr1);
    arr.clear();

}

TEST(TestTreeNode, TestDeleteNode) {
    // �������� ��������� �� ������ ������ 
    TreeNode<int>* root1 = createTree1();

    root1 = DeleteNode(root1, 11);
    vector<int> arr, arr1 = { 4, 5, 10, 12, 22, 24 };
    TreeToArrayLNR(root1, arr);
    EXPECT_EQ(arr, arr1);
    arr.clear();
    //       5
    //      / \
    //     4   22
    //        / \
    //       12  24
    //      /
    //     10

    root1 = DeleteNode(root1, 5);
    arr1 = { 4, 10, 12, 22, 24 };
    TreeToArrayLNR(root1, arr);
    EXPECT_EQ(arr, arr1);
    arr.clear();


    root1 = DeleteNode(root1, 10);
    arr1 = { 4, 12, 22, 24 };
    TreeToArrayLNR(root1, arr);
    EXPECT_EQ(arr, arr1);
    arr.clear();


    // ����������� ������
    TreeNode<int>* root2 = createTree2();
    root2 = DeleteNode(root2, 20);
    arr1 = { 10, 19, 30, 33 };
    TreeToArrayLNR(root2, arr);
    EXPECT_EQ(arr, arr1);
    arr.clear();
    //       10
    //        \
    //         19
    //          \
    //           30
    //            \
    //             33

    root2 = DeleteNode(root2, 30);
    arr1 = { 10, 19, 33 };
    TreeToArrayLNR(root2, arr);
    EXPECT_EQ(arr, arr1);
    arr.clear();


    // ����������� �����
    TreeNode<int>* root3 = createTree3();
    root3 = DeleteNode(root3, 13);
    arr1 = { 14, 54, 60 };
    TreeToArrayLNR(root3, arr);
    EXPECT_EQ(arr, arr1);
    arr.clear();
    //       60
    //       /  
    //      54   
    //      /   
    //     14  

    root3 = DeleteNode(root3, 60);
    arr1 = { 14, 54 };
    TreeToArrayLNR(root3, arr);
    EXPECT_EQ(arr, arr1);
    arr.clear();

    // ����������� ������
    TreeNode<int>* root4 = createTree4();
    root4 = DeleteNode(root4, 6);
    arr1 = { 1, 2, 3, 4, 5, 7, 8, 9, 10, 30 };
    TreeToArrayLNR(root4, arr);
    EXPECT_EQ(arr, arr1);
    arr.clear();
    //          8
    //       /    \
    //      4      10
    //    /   \    / \
    //   2     7   9   30
    //  / \    /       
    // 1   3  5 

    root4 = DeleteNode(root4, 8);
    arr1 = { 1, 2, 3, 4, 5, 7,  9, 10, 30 };
    TreeToArrayLNR(root4, arr);
    EXPECT_EQ(arr, arr1);
    arr.clear();

    root4 = DeleteNode(root4, 7);
    arr1 = { 1, 2, 3, 4, 5, 9, 10, 30 };
    TreeToArrayLNR(root4, arr);
    EXPECT_EQ(arr, arr1);
    arr.clear();

    root4 = DeleteNode(root4, 1);
    arr1 = { 2, 3, 4, 5, 9, 10, 30 };
    TreeToArrayLNR(root4, arr);
    EXPECT_EQ(arr, arr1);
    arr.clear();

    // ������ ������
    TreeNode<int>* root5 = nullptr;
    root5 = DeleteNode(root5, 12);
    arr1 = { };
    TreeToArrayLNR(root5, arr);
    EXPECT_EQ(arr, arr1);
    arr.clear();


    // ������ � ����� �����
    TreeNode<int>* root6 = new TreeNode<int>(2);
    root6 = DeleteNode(root6, 15);
    arr1 = { 2 };
    TreeToArrayLNR(root6, arr);
    EXPECT_EQ(arr, arr1);
    arr.clear();

    root6 = DeleteNode(root6, 2);
    arr1 = {  };
    TreeToArrayLNR(root6, arr);
    EXPECT_EQ(arr, arr1);
    arr.clear();

}


TEST(TestTreeNode, TestCopyTree) {
    vector<int> arr, arr1;

    // �������� ��������� �� ������ ������ 
    TreeNode<int>* root1 = createTree1();
    TreeNode<int>* tmp = CopyTree(root1);
    
    TreeToArrayNLR(root1, arr);
    TreeToArrayNLR(tmp, arr1);
    EXPECT_EQ(arr, arr1);
    arr.clear(); arr1.clear();
    deleteTree(tmp);

    // ����������� ������
    TreeNode<int>* root2 = createTree2();
    tmp = CopyTree(root2);

    TreeToArrayNLR(root2, arr);
    TreeToArrayNLR(tmp, arr1);
    EXPECT_EQ(arr, arr1);
    arr.clear(); arr1.clear();
    deleteTree(tmp);

    // ����������� �����
    TreeNode<int>* root3 = createTree3();
    tmp = CopyTree(root3);

    TreeToArrayNLR(root3, arr);
    TreeToArrayNLR(tmp, arr1);
    EXPECT_EQ(arr, arr1);
    arr.clear(); arr1.clear();
    deleteTree(tmp);

    // ����������� ������
    TreeNode<int>* root4 = createTree4();
    tmp = CopyTree(root4);

    TreeToArrayNLR(root4, arr);
    TreeToArrayNLR(tmp, arr1);
    EXPECT_EQ(arr, arr1);
    arr.clear(); arr1.clear();
    deleteTree(tmp);

    // ������ ������
    TreeNode<int>* root5 = nullptr;
    tmp = CopyTree(root5);

    TreeToArrayNLR(root5, arr);
    TreeToArrayNLR(tmp, arr1);
    EXPECT_EQ(arr, arr1);
    arr.clear(); arr1.clear();
    deleteTree(tmp);

    // ������ � ����� �����
    TreeNode<int>* root6 = new TreeNode<int>(2);
    tmp = CopyTree(root6);

    TreeToArrayNLR(root6, arr);
    TreeToArrayNLR(tmp, arr1);
    EXPECT_EQ(arr, arr1);
    arr.clear(); arr1.clear();
    deleteTree(tmp);

}

