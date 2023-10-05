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

	// конструктор копирования
	BinSTree(const BinSTree<T>& tree);

	// оператор копирования (присваивания)
	BinSTree<T>& operator= (const BinSTree<T>& rhs);

	// деструктор
	~BinSTree() { deleteTree(this->root); }


	// стандартные методы обработки списков
	int Find(T& item);
	void Insert(const T& item);
	void Delete(const T& item);
	void ClearList();

	// проверка 
	int ListEmpty() const;
	int ListSize() const;

};

// конструктор по умолчанию
template <typename T>
BinSTree<T>::BinSTree()
{
	root = nullptr;
	current = nullptr;
	size = 0;
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

	// очистить текущее дерево, скопировать новое дерево в текущий объект
	ClearList();
	this->root = CopyTree(rhs.root);

	// присвоить текущему указателю значение корня и задать размер дерева
	this->current = this->root;
	this->size = rhs.size;

	// возвратить ссылку на текущий объект
	return *this;
}


