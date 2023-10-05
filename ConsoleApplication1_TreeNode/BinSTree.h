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
	// конструктор
	BinSTree();

	// стандартные методы обработки списков
	int Find(T& item);
	void Insert(const T& item);
	void Delete(const T& item);
	void ClearList(void);
	int ListEmpty(void) const;
	int ListSize(void) const;

	// добавить метод копирования и обхода в ширину(?)

	// методы, специфичные для деревьев
	void Update(const T& item);
	TreeNode<T>* GetRoot(void) const;



};

