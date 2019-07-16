#pragma once
#include <vector>
#include <utility>
#include <iostream>
using namespace std;

class HeapSort
{
private:
	vector<pair<int,int>> v;

public:
	HeapSort();
	HeapSort(vector<pair<int,int>> v);
	~HeapSort();

	void print_heap();	//heap�� ����ϴ� �Լ�
	void min_heapfity(int i);	//heap�� min heap������ �����ϰ� ������ִ� �Լ�
	void build_heap();		// heap �� ������Ű�� �Լ�
	void heapSort();
	void vector_swap( int a , int b);
	void update(int to, int weight);
	bool search(int a);
	vector<pair<int, int>> extract_min();
	bool IsEmpty();
	int getKey(int vertex);  //�Է��� vertex�� key���� �������� �Լ�
};