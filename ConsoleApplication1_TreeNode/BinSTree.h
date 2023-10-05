#pragma once

// author: �������� ���������
// ����� ��������� ������ ������

#include <iostream>
#include "TreeNode.h"

template <typename T>
class BinSTree
{
private:
	// ��������� �� ������ � �� ������� ����
	TreeNode<T>* root;
	TreeNode<T>* current;

	// ����� ��������� ������
	int size;


public:
	// �����������
	BinSTree();

	// ����������� ������ ��������� �������
	int Find(T& item);
	void Insert(const T& item);
	void Delete(const T& item);
	void ClearList(void);
	int ListEmpty(void) const;
	int ListSize(void) const;

	// �������� ����� ����������� � ������ � ������(?)

	// ������, ����������� ��� ��������
	void Update(const T& item);
	TreeNode<T>* GetRoot(void) const;



};

