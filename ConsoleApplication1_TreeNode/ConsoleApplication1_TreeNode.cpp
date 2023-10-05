// ConsoleApplication1_TreeNode.cpp 
// author: Денисова Екатерина

#include <iostream>
#include "TreeNode.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");

    // создаётся указатели на узлы дерева 
    TreeNode<int>* leftleaf, * rightleaf, * root;
    
    
    //      10
    //        \
    //         5
    //        / \
    //       2   4
    //      /
    //     12

    //создаётся указатель на лист дерева (указатели на левый и правый узлы nullptr)
    leftleaf = new TreeNode<int>(12);

    //создаётся узел только с левым потомком
    root = new TreeNode<int>(2, leftleaf, nullptr);

    // указатель leftleaf переносится на только что созданный узел
    leftleaf = root;
    rightleaf = new TreeNode<int>(4);

    //создаётся узел с левым и правым потомком
    root = new TreeNode<int>(5, leftleaf, rightleaf);
    rightleaf = root;

    //создаётся узел только с правым потомком
    root = new TreeNode<int>(10, nullptr, rightleaf);

    // вывод дерева в консоль
    cout << root->Data() << "\n  " << root->Right()->Data() << "\n " << root->Right()->Left()->Data()
        << " " <<  root->Right()->Right()->Data() << "\n" << root->Right()->Left()->Left()->Data() << "\n\n";

    cout << "Прямой обход: ";
    preorderPrint(root, &printNode);

    cout << "\nСимметричный обход: ";
    inorderPrint(root, &printNode);

    cout << "\nОбратный обход: ";
    postorderPrint(root, &printNode);

    cout << "\nГлубина дерева = ";
    cout<< treeHeight(root);

    cout << "\nКоличество узлов в дереве = ";
    int count = treeCount(root);
    cout << count << "\n\n";


    vector<int> arr;
    TreeToArrayNLR(root, arr);
    cout << "Массив из дерева (прямой обход): ";

    for (auto& it : arr) {
        cout << it << ' ';
    }
    arr.clear();

    TreeToArrayLNR(root, arr);
    cout << "\nМассив из дерева (симметричный обход): ";

    for (auto& it : arr) {
        cout << it << ' ';
    }
    arr.clear();

    TreeToArrayLRN(root, arr);
    cout << "\nМассив из дерева (обратный обход): ";

    for (auto& it : arr) {
        cout << it << ' ';
    }
    arr.clear();

    cout << "\n\nПрименение функции к узлам дерева";
    cout << "\nДобавление единицы: ";
    preorderPrint(root, &add1);
    preorderPrint(root, &printNode);
    cout << "\nВозведение в квадрат: ";
    preorderPrint(root, &squaring);
    preorderPrint(root, &printNode);


    deleteTree(root);


    /// Бинарное дерево поиска

    //     8
    //    / \
    //   3   10
    //  / \
    // 1   6
    //    /
    //   4

    // создаётся указатели на узлы дерева 
    //TreeNode<int>* root;

    //создаётся указатель на лист дерева (указатели на левый и правый узлы nullptr)
    leftleaf = new TreeNode<int>(4);

    rightleaf = new TreeNode<int>(6, leftleaf, nullptr);
    leftleaf = new TreeNode<int>(1);
    //создаётся узел только с левым и правым потомком
    root = new TreeNode<int>(3, leftleaf, rightleaf);

    // указатель leftleaf переносится на только что созданный узел
    leftleaf = root;
    rightleaf = new TreeNode<int>(10);

    //создаётся корень
    root = new TreeNode<int>(8, leftleaf, rightleaf);
    
    cout << "\n\nБинароное дерево поиска: ";
    inorderPrint(root, &printNode);

    int p = SearchNode(root, 1);

    cout << "\nУзел со значением 1 находится на уровне " << p;

    
    InsertNode(root, 7);

    cout << "\nПосле добавления узла со значением 7: ";

    inorderPrint(root, &printNode);

    cout << "\nНахождение следующего наибольшего для 4: ";
    TreeNode<int>* s = nullptr;

    Successor(root, s, 4);
    if (s != nullptr) {
        cout << s->Data();
    }
    else cout << "Не существует\n";


    root = DeleteNode(root, 3);

    cout << "\nПосле удаления узла со значением 3: ";
    inorderPrint(root, &printNode);

    root = DeleteNode(root, 6);

    cout << "\nПосле удаления узла со значением 6: ";
    inorderPrint(root, &printNode);


    TreeNode<int>* t = CopyTree(root);
    cout << "\n\nСкопированное дерево: ";
    inorderPrint(t, &printNode);







}

