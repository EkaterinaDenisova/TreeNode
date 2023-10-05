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

	// проверка, пустое ли дерево
	bool ListEmpty() const;
	
	// количество узлов в дереве
	int ListSize() const;

};

// конструктор по умолчанию
template <typename T>
BinSTree<T>::BinSTree()
{
	this->root = nullptr;
	this->current = nullptr;
	this->size = 0;
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
int BinSTree<T>::Find(T& item) {
	return SearchNode(this->root, item);
}

// вставка узла
template<class T>
void BinSTree<T>::Insert(const T& item) {

	//t - текущий узел, parent - предыдущий узел
	TreeNode<T>* t = root, * parent = nullptr, * newNode;
	//закончить на пустом дереве
	while (t != nullptr)
	{
		//обновить указатель parent и идти направа или влево
		parent = t;
		if (item < t->Data())
			t = t->Left();
		else
			t = t->Right();
	}

	//если родителя нет, вставить в качестве корневого узла
	newNode = new TreeNode<T>(item, nullptr, nullptr);
	if (parent == nullptr) {
		root = newNode;

		//присвоить указателю current адрес нового узла и увеличить size на 1
		current = newNode;
		size++;
	}
		
	//если item меньше родительского узла, вставить в качестве левого сына
	else if (item < parent->Data()) {
		parent->SetLeft(newNode);

		//присвоить указателю current адрес нового узла и увеличить size на 1
		current = newNode;
		size++;
	}
		
	else if (item > parent->Data()) {

		//если item больше родительского узла
		//вставить в качесте правого сына
		parent->SetRight(newNode);

		//присвоить указателю current адрес нового узла и увеличить size на 1
		current = newNode;
		size++;
	}

	// если значение уже есть в дереве
	else {
		current = parent;
	}
}

// удаление узла
template<class T>
void BinSTree<T>::Delete(const T& item) {
	this->root = DeleteNode(this->root, item);
	size--;
}