#pragma once

// author: Денисова Екатерина
// класс бинарного дерева поиска

#include <iostream>
#include "TreeNode.h"

template <typename T>
class BinSTree
{
private:
	// указатели на корень и на текущий узел
	TreeNode<T>* root;
	TreeNode<T>* current;

	// число элементов дерева 
	int size;


public:
	// конструктор по умолчанию
	BinSTree();

	// конструктор с параметром
	BinSTree(TreeNode<T>* tree);


	// конструктор копирования
	BinSTree(const BinSTree<T>& tree);

	// оператор копирования (присваивания)
	BinSTree<T>& operator= (const BinSTree<T>& rhs);

	// деструктор
	~BinSTree() { deleteTree(this->root); }


	// стандартные методы обработки списков

	// возвращает уровень, на котором находится искомый узел
	// либо -1, если узла с таким значением в дереве нет
	int Find(const T& item);
	void Insert(const T& item);
	void Delete(const T& item);
	void ClearList();

	// проверка, пустое ли дерево
	bool ListEmpty() const;
	
	// количество узлов в дереве
	int ListSize() const;

	TreeNode<T>* GetRoot();
};

// конструктор по умолчанию
template <typename T>
BinSTree<T>::BinSTree()
{
	this->root = nullptr;
	this->current = nullptr;
	this->size = 0;
}

// конструктор с параметрами
template <typename T>
BinSTree<T>::BinSTree(TreeNode<T>* tree)
{
	this->root = CopyTree(tree);
	this->current = nullptr;
	this->size = treeCount(this->root);
}

// конструктор копирования
template <typename T>
BinSTree<T>::BinSTree(const BinSTree<T>& tree)
{
	this->root = CopyTree(tree.root);

	// присвоить текущему указателю значение корня и задать размер дерева
	this->current = this->root;
	this->size = tree.size;
}


// оператор копирования (присваивания)
template <class T>
BinSTree<T>& BinSTree<T>::operator= (const BinSTree<T>& rhs)
{
	// нельзя копировать дерево в само себя
	if (this == &rhs)
		return *this;

	// очистить текущее дерево
	ClearList();

	// скопировать новое дерево в текущий объект
	this->root = CopyTree(rhs.root);

	// присвоить текущему указателю значение корня и задать размер дерева
	this->current = this->root;
	this->size = rhs.size;

	// возвратить ссылку на текущий объект
	return *this;
}

// очистка дерева
template <typename T>
void BinSTree<T>::ClearList() {
	deleteTree(this->root);
	this->root = nullptr;
	this->current = nullptr;
	this->size = 0;
}

//проверка, пустое ли дерево
template<class T>
bool BinSTree<T>::ListEmpty() const {
	return (this->root == nullptr);
}

// количество узлов в дереве
template<class T>
int BinSTree<T>::ListSize() const {
	return this->size;
}


// поиск узла
// возвращает уровень, на котором был найден узел
// либо -1, если узла с искомым значением нет
template<class T>
int BinSTree<T>::Find(const T& item) {
	return SearchNode(this->root, item);
}

// вставка узла
template<class T>
void BinSTree<T>::Insert(const T& item) {
	this->root = InsertNode(this->root, item);
	size = treeCount(this->root);	
}

// удаление узла
template<class T>
void BinSTree<T>::Delete(const T& item) {
	this->root = DeleteNode(this->root, item);
	size = treeCount(this->root);
}

// Возвращает указатель на корень
template <typename T>
TreeNode<T>* BinSTree<T>::GetRoot()
{
	return this->root;
}