#pragma once

// author: Денисова Екатерина
// класс узла бинарного дерева
#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class TreeNode
{
private:
	// указатели левого и правого дочерних узлов
	TreeNode<T>* left;
	TreeNode<T>* right;

	// данные в узле
	T data;

public:

	// конструктор без параметров
	// Компилятор напишет конструктор по умолчанию
	TreeNode() = default;

	// конструктор с параметрами
	TreeNode(const T& item, TreeNode<T>* lptr = nullptr, TreeNode<T>* rptr = nullptr);

	// методы доступа к полям указателей
	TreeNode<T>* Left() const;
	TreeNode<T>* Right() const;


	// сделать класс BinSTree дружественным, поскольку необходим
	// доступ к полям left и right
	//friend class BinSTree<T>;


	// метод доступа к полю данных
	T Data() const;

	// методы для задания значений полей
	void SetLeft(TreeNode<T>* left1);
	void SetRight(TreeNode<T>* right1);
	void SetData(T data1);

};

// конструктор инициализирует поля данных и указателей
// значение nullptr соответствует пустому поддереву
template <typename T>
TreeNode<T>::TreeNode(const T& item, TreeNode<T>* lptr, TreeNode<T>* rptr) 
{
	data = item;
	left = lptr;
	right = rptr;
}

// Методы Left и Right возвращают значения полей левого и правого указателей
template <typename T>
TreeNode<T>* TreeNode<T>::Right() const
{
	return this->right;
}

template <typename T>
TreeNode<T>* TreeNode<T>::Left() const
{
	return this->left;
}

// Метод Data возвращает значение поля данных
template <typename T>
T TreeNode<T>::Data() const
{
	return this->data;
}

// Метод задания значения поля данных
template <typename T>
void TreeNode<T>::SetData(T data1) {
	this->data = data1;
}

// Метод задания значения правого потомка
template <typename T>
void TreeNode<T>::SetRight(TreeNode<T>* right1) {
	this->right = right1;
}

// Метод задания значения левого потомка
template <typename T>
void TreeNode<T>::SetLeft(TreeNode<T>* left1) {
	this->left = left1;
}

// Печать узла дерева
template <typename T>
void printNode(TreeNode<T>* root) {
	cout << root->Data() << " ";
}

// функция добавления единицы к значению узла
template <typename T>
void add1(TreeNode<T>* root) {
	root->SetData(root->Data()+1);
}

// функция возведения в квадрат значения узла
template <typename T>
void squaring(TreeNode<T>* root) {
	root->SetData(root->Data() * root->Data());
}

// прямое прохождение узлов дерева
template <typename T>
void preorderPrint(TreeNode<T>* root, void (*func) (TreeNode<T>*))
{

	if (root != nullptr)   // Базовый случай
	{
		func(root);
		preorderPrint(root->Left(), func);   //рекурсивный вызов левого поддерева
		preorderPrint(root->Right(), func);  //рекурсивный вызов правого поддерева
	}

}

// симметричный обход
// больше всего подходит для бинарного дерева поиска (выведет в порядке от меньшего к большему)
template <typename T>
void inorderPrint(TreeNode<T>* root, void (*func) (TreeNode<T>*))
{
	if (root != nullptr) {
		inorderPrint(root->Left(), func);   //рекурсивный вызов левого поддерева
		func(root);
		inorderPrint(root->Right(), func);  //рекурсивный вызов правого поддерева
	}

}

// печать (обратный обход)
template <typename T>
void postorderPrint(TreeNode<T>* root, void (*func) (TreeNode<T>*))
{
	if (root != nullptr) {
		postorderPrint(root->Left(), func);   //рекурсивный вызов левого поддерева
		postorderPrint(root->Right(), func);  //рекурсивный вызов правого поддерева
		func(root);
	}

}

// cоздание массива на основе дерева (прямой обход)
template <typename T>
int TreeToArrayNLR(TreeNode<T>* root, vector<T>& arr, int i) {
	if (root == nullptr) {
		return i;
	}

	arr.push_back(root->Data());
	//arr[i] = root->Data();
	i++;

	if (root->Left() != nullptr) {
		i = TreeToArrayNLR(root->Left(), arr, i);
	}
	if (root->Right() != nullptr) {
		i = TreeToArrayNLR(root->Right(), arr, i);
	}

	return i;
}

// cоздание массива на основе дерева (симметричный обход)
template <typename T>
int TreeToArrayLNR(TreeNode<T>* root, vector<T>& arr, int i) {
	if (root == nullptr) {
		return i;
	}

	if (root->Left() != nullptr) {
		i = TreeToArrayLNR(root->Left(), arr, i);
	}

	arr.push_back(root->Data());
	i++;

	if (root->Right() != nullptr) {
		i = TreeToArrayLNR(root->Right(), arr, i);
	}

	return i;
}

// cоздание массива на основе дерева (обратный обход)
template <typename T>
int TreeToArrayLRN(TreeNode<T>* root, vector<T>& arr, int i) {
	if (root == nullptr) {
		return i;
	}

	if (root->Left() != nullptr) {
		i = TreeToArrayLRN(root->Left(), arr, i);
	}

	if (root->Right() != nullptr) {
		i = TreeToArrayLRN(root->Right(), arr, i);
	}

	arr.push_back(root->Data());
	i++;

	return i;
}

// Нахождение глубины дерева
template <typename T>
int treeHeight(TreeNode<T>* root) {
	int left_height, right_height;
	int height = 0;
	if (root == nullptr)
		height = -1;
	else {
		
		// находим глубину левого и правого поддеревьев
		// рекурсивный вызов функции treeHeight
		left_height = treeHeight(root->Left());
		right_height = treeHeight(root->Right());

		// Находим максимальное из поддеревьев
		height = max(left_height, right_height)+1;
	}
	return height;
}

// Нахождение количества узлов в дереве
template <typename T>
unsigned int treeCount(TreeNode<T>* root)
{
	if (root == nullptr) {
		return 0;
	}

	unsigned int l = treeCount(root->Left());
	unsigned int r = treeCount(root->Right());

	return 1 + l + r;
}

// Удаление дерева
template <typename T>
void deleteTree(TreeNode<T>* root)
{
	if (root != nullptr) {

		// сначала удаляем левое и правое поддерево
		deleteTree(root->Left());
		deleteTree(root->Right());

		// удаляем текущий узел после удаления его левого и правого поддерева
		delete root;

	}
}


/// Бинарное дерево поиска

// поиск узла по значению
// возвращает уровень, на котором был найден узел
// либо -1, если узла с искомым значением нет
template <typename T>
int SearchNode(TreeNode<T>* root, const T key, int depth = 0) {
	if (root == nullptr) {
		return -1;
	}

	if (key > root->Data()) {
		SearchNode(root->Right(), key, depth + 1);
	}
		

	else if (key < root->Data()) {
		SearchNode(root->Left(), key, depth + 1);
	}
		
	else return depth;
}

// операция вставки узла в бинарное дерево поиска
template <typename T>
TreeNode<T>* InsertNode(TreeNode<T>* root, const T value) {

	if (root == nullptr) {

		// Insert the first node, if root is NULL.
		return new TreeNode<T>(value);
	}

	// Insert data.
	if (value > root->Data()) {
		// Insert right node data, if the 'value'
		// to be inserted is greater than 'root' node data.

		// Process right nodes.
		root->SetRight(InsertNode(root->Right(), value));
	}
	else if (value < root->Data()) {
		// Insert left node data, if the 'value'
		// to be inserted is smaller than 'root' node data.

		// Process left nodes.
		root->SetLeft(InsertNode(root->Left(), value));
	}

	// Return 'root' node, after insertion.
	return root;
}

template <typename T>
TreeNode<T>* getNextLeft(TreeNode<T>* root)
{
	while (root->Left() != nullptr) {
		root = root->Left();
	}

	return root;
}

// нахождение ближайшего наибольшего
template <typename T>
void Successor(TreeNode<T>* root, TreeNode<T>*& succ, int key) {

	if (root == nullptr) {
		succ = nullptr;
	}

	else if (root->Data() == key)
	{
		if (root->Right() != nullptr) {
			succ = getNextLeft(root->Right());
		}
	}

	else if (key < root->Data())
	{
		succ = root;
		Successor(root->Left(), succ, key);
	}
	else {
		Successor(root->Right(), succ, key);
	}
}

// операция удаления узла из бинарного дерева поиска
template <typename T>
TreeNode<T>* DeleteNode(TreeNode<T>* root, const T value) {

	// базовый случай
	if (root == nullptr) {
		return root;
	}

	// Recursive calls for ancestors of
	// node to be deleted
	if (root->Data() > value) {
		root->SetLeft(DeleteNode(root->Left(), value));
		return root;
	}
	else if (root->Data() < value) {
		root->SetRight(DeleteNode(root->Right(), value));
		return root;
	}

	// We reach here when root is the node
	// to be deleted.

	// If one of the children is empty
	if (root->Left() == nullptr) {
		TreeNode<T>* temp = root->Right();
		delete root;
		return temp;
	}
	else if (root->Right() == nullptr) {
		TreeNode<T>* temp = root->Left();
		delete root;
		return temp;
	}

	// If both children exist
	else {

		TreeNode<T>* succParent = root;

		// Find successor
		TreeNode<T>* succ = root->Right();
		while (succ->Left() != nullptr) {
			succParent = succ;
			succ = succ->Left();
		}


		// Delete successor.  Since successor
		// is always left child of its parent
		// we can safely make successor's right
		// right child as left of its parent.
		// If there is no succ, then assign
		// succ->right to succParent->right
		if (succParent != root)
			succParent->SetLeft(succ->Right());
		else
			succParent->SetRight(succ->Right());

		/*TreeNode<T>* succ = nullptr;
		Successor(root->Right(), succ, root->Data());*/

		// Copy Successor Data to root
		root->SetData(succ->Data());
		//root->SetRight(DeleteNode(root->Right(), succ->Data()));

		// Delete Successor and return root
		delete succ;
		return root;
	}
}


