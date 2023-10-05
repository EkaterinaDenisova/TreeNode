#pragma once

// author: Äåíèñîâà Åêàòåðèíà
// êëàññ áèíàðíîãî äåðåâà ïîèñêà

#include <iostream>
#include "TreeNode.h"

template <typename T>
class BinSTree
{
private:
	// óêàçàòåëè íà êîðåíü è íà òåêóùèé óçåë
	TreeNode<T>* root;
	TreeNode<T>* current;

	// ÷èñëî ýëåìåíòîâ äåðåâà
	int size;


public:
	// êîíñòðóêòîð
	BinSTree();

	// ñòàíäàðòíûå ìåòîäû îáðàáîòêè ñïèñêîâ
	int Find(T& item);
	void Insert(const T& item);
	void Delete(const T& item);
	void ClearList(void);
	int ListEmpty(void) const;
	int ListSize(void) const;

	// äîáàâèòü ìåòîä êîïèðîâàíèÿ è îáõîäà â øèðèíó(?)

	// ìåòîäû, ñïåöèôè÷íûå äëÿ äåðåâüåâ
	void Update(const T& item);
	TreeNode<T>* GetRoot(void) const;



};

