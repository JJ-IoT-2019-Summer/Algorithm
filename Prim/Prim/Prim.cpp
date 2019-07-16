#include <stdio.h>
#include <limits.h>
#include <time.h>
#include <iostream>
#include <vector>
#include <utility>
#include "Heap.h"

using namespace std;
#define matrix_size 8 // adjacency-matrix �� ũ�� 

void getAdj(int graph[matrix_size][matrix_size], int vertex, vector<pair<int, int>>* m); //�Է� vertex �ֺ� ��带 ��� �Լ�
void Prim(int graph[matrix_size][matrix_size]); // MST�� ���ϴ� ���� �˰��� 


int main()
{
	/*int graph[matrix_size][matrix_size] = { { 0,6,12,0,0,0,0 },
											{ 6,0,5,0,14,0,0,8 },
											{ 12,5,0,9,0,7,0,0 },
											{ 0,0,9,0,0,0,0,0 },
											{ 0,14,0,0,0,0,0,3 },
											{ 0,0,7,0,0,0,15,10},
											{ 0,0,0,0,0,15,0,0},
											{ 0,8,0,0,3,10,0,0} };*/
/*int graph[matrix_size][matrix_size] = { {0,12,INT_MAX,INT_MAX,5 },
											{12,0,3,INT_MAX,INT_MAX },
											{INT_MAX ,3,0,4,8},
											{ INT_MAX ,INT_MAX ,4,0,INT_MAX },
											{ 5,INT_MAX ,8,INT_MAX ,0}	};*/
	int graph[matrix_size][matrix_size] = { {0,7,0,0,0,10,15,0},
											{7,0,12,5,0,0,0,9}, //1}
											{0,12,0,6,0,0,0,0}, //2
											{0,5,6,0,14,8,0,0},//3
											{0,0,0,14,0,3,0,0}, //4
											{10,0,0,8,3,0,0,0}, //5
											{15,0,0,0,0,0,0,0}, //6
											{0,9,0,0,0,0,0,0}, //7
	};

	Prim(graph);		//graph�� MST�� ���ϱ����� Prim �Լ� ȣ��
	return 0;
}

void getAdj(int graph[matrix_size][matrix_size], int vertex, vector<pair<int, int>>* m) //graph�� vertex, �ֺ���� ������ ���� m
{
	for (int i = 0; i < matrix_size;i++)	//adjacency-matrix�� ũ�⸸ŭ Ž���ϸ鼭
	{
		if (graph[vertex][i] != 0)	//vertex�κ��� ����� vertex (����ġ�� ����) �� �ִ� �� Ȯ��
			m->push_back(make_pair(i, graph[vertex][i])); // �����ϸ� m �� ��� vertex ����, ����ġ�� �Բ� vector�� �Է� 
	}
}

void Prim(int graph[matrix_size][matrix_size])  // ��������� ����ؼ� MST�� ���ϴ� Prim's algorithm
{
	int MST[matrix_size] = { 0 }; // MST ������ ���� �迭 MST

	vector<pair<int, int>> Q;	//Vertex ������ ������ �ִ� vector Q

	for (int i = 0; i < matrix_size;i++) Q.push_back(make_pair(i, INT_MAX));	//�� vertex �� key���� MAX�μ���

	srand(time(NULL));
	int s = (rand() % Q.size() - 1) + 1;	//������ ������ s 
	Q.at(s).second = 0; // �������� key���� 0 �Է�

	HeapSort PriorityQueue(Q);	//vector Q�� ������ �켱���� ť ����
	PriorityQueue.heapSort();	//key���� ���� min_heap ���� 

	while (!(PriorityQueue.IsEmpty()))	//�켱���� ť�� ���� �����ҵ���
	{
		vector<pair<int, int>> u = PriorityQueue.extract_min();	// �켱���� ť���� key���� �ּ��� vertex�� ť���� ���� u�� assign
		cout << "\nextract_min from Q : " << "u = " << u[0].first << " weight = " << u[0].second << endl;
		cout << endl;		// Queue ���� ������ �ּڰ� ���

		vector<pair<int, int>> adjacency;	//�ֺ� vertex �� ���� ���� ����
		getAdj(graph, u[0].first, &adjacency);   //�׷������� u�� �ֺ� vertex��  adjacency �� ��ƿ�

		for (size_t i = 0; i < adjacency.size(); i++)		// �������� �� Ž�� 
		{
			int v = adjacency[i].first;		// v �� �ֺ� vertex�� ��ȣ 
			cout << "====== �ֺ� vertex " << v << " ======" << endl;
			if (PriorityQueue.search(v)		 // PriorityQueue���� �ֺ���� v�� Q�� �ִ��� Ȯ�� 
				&& (graph[u[0].first][v] < PriorityQueue.getKey(v))) // w(u,v) < key[v] �� ���
			{
				cout << " vertex " << v << " key : " << PriorityQueue.getKey(v)
					<< " update to " << graph[u[0].first][v] << endl; // update �� Ű�� ���
				MST[v] = u[0].first;							//MST[V] �� ���� ����� u ���
				PriorityQueue.update(v, graph[u[0].first][v]); //  w(u,v)�� key[v] update

			}
			else
				cout << " vertex " << v << " key : " << PriorityQueue.getKey(v) << endl;
								// ������Ʈ ���� ���� Ű�� ���, key���� -1 �� ���� �湮�ߴ� ��� ǥ��
		}
		adjacency.clear();	//�ֺ�vertex�� ����ִ� vector �ʱ�ȭ
		u.clear();		// �ּ� key���� ���� vertex �ʱ�ȭ
	}

	cout << "======= MST =======" << endl << endl;
	for (int i = 0; i < matrix_size;i++)
	{
		if (graph[i][MST[i]] != 0 && graph[i][MST[i]] != INT_MAX)	//MST ���, ����ġ�� INT_MAX�̰ų�,0 �ϰ��� ����
			cout << " V : " << MST[i] << " -> " << i << " weight : " << graph[i][MST[i]] << endl;
	}
	cout << endl;
	return;
}

