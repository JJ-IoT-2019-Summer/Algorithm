
#include "Heap.h"

HeapSort::HeapSort()	// ������ 
{

}
HeapSort::HeapSort(vector<pair<int, int>>  V) // �����ε� �� ������
{
	v = V; // �Ķ���ͷ� ���� V�� v�� set
}

HeapSort::~HeapSort()	//�Ҹ���
{
	v.clear();
}

bool HeapSort::IsEmpty()	//Heap�� ����ִ��� Ȯ���ϴ� �Լ� 
{
	if (v.size() == 0) return true;	//vector �� ���Ұ� 0�̸� true
	else	return false;	//�ƴϸ� false
}

vector<pair<int, int>>  HeapSort::extract_min()	//�ּ��� key���� ������ �ִ� vertex�� �������� �Լ�
{
	vector<pair<int, int>> min; //�ּ��� key���� ������ vertex�� ���� ����
	int i;
	i = v.size() - 1;//	i �� size - 1;

	if (i < 0) {  //size�� 0�̿����� ����ó��
		cout << "Heap is empty" << endl;
		return min;
	}

	vector_swap(0, i);	// 0��° vector (�ּڰ�) �� ������ vector ���� swap
	min.push_back(make_pair(v[v.size() - 1].first, v[v.size() - 1].second));
	v.pop_back();			//min vector�� �ּҰ��� ������ vertex ��ȣ��, ����ġ ����
							//v���� ������ ���� �ںκ��� pop
	min_heapfity(0);		// root ���� �ٽ� heapfity
	return min;				//�ּ��� key���� ������ vertex ��ȯ

}

void HeapSort::update(int to, int weight)
{
	for (size_t i = 0; i < v.size(); i++)
	{
		if (v[i].first == to)  //Q�� �����ִ� V���� üũ
		{
			v[i].second = weight; // �Ķ���ͷ� ���� ����ġ�� vertex ����ġ ������Ʈ
		}
	}
	build_heap();	// ����ġ�� �ٲ�����Ƿ� �ٽ� ���� 

}
bool HeapSort::search(int to_vertex)  //���ڷ� Q�ȿ��� ã�����ϴ� vertex ��ȣ �Է�
{
	for (size_t i = 0; i < v.size(); i++) //Q �� �����ִ� vertex�� üũ
	{
		if (v[i].first == to_vertex)	//���ڷ� ���� vertex��ȣ�� Q�� vertex��ȣ�� ���ٸ�
		{
			return true;	//Q�� �����ϴ� vertex, true ����
		}
	}
	return false;	//Q�� ���� vertex�̹Ƿ� false return
}

int HeapSort::getKey(int vertex) //�Է��� vertex�� key���� �������� �Լ�
{
	int a = 0;
	for (size_t i = 0; i < v.size(); i++)  //Q �� �����ִ� vertex�� üũ
	{
		if (v[i].first == vertex) //���ڷ� ���� vertex��ȣ�� Q�� vertex��ȣ�� ���ٸ�
		{
			a = v[i].second; //key���� ����.
			return a;
		}
	}
	return -1;	//Q�� �������� ���� vertex��� -1 ����
}


void HeapSort::print_heap()	//heap�� ����ϴ� �Լ�
{
	for (size_t i = 0; i < v.size(); i++)
		cout << "first = " << v[i].first << " second = " << v[i].second << endl;
	cout << endl;
}


void HeapSort::min_heapfity(int i)	//heap�� min heap������ �����ϰ� ������ִ� �Լ�
{
	size_t  l, r;
	int smallest;
	l = 2 * i;		//���� �ڽ� ���
	r = (2 * i + 1);	//������ �ڽ� ���
	if ((l < v.size()) && v[l].second < v[i].second) smallest = l;
	else smallest = i;		//l �� ���� ������ ���� �����ϰ�, �����ڽ� ����� key���� 
							//�θ���  key������ ������ smallest �� l �ƴϸ� i 

	if ((r < v.size()) && (v[r].second < v[smallest].second)) smallest = r;
	//r �� ���� ������ ���� �����ϰ�, ������ �ڽ� ����� key���� smallest ������
	//������ smallest �� r
	if (smallest != i)	// �θ� ���� ������ �ƴ϶��
	{
		vector_swap(i, smallest);	//�θ�� ���� ���� ��� ��ȯ
		min_heapfity(smallest);		//smallest �� �θ���ؼ� min heap ����������Ű�� heap ����
	}
}


void HeapSort::build_heap()		// heap �� ������Ű�� �Լ�
{
	for (int i = (v.size() / 2); i >= 0; i--) 	min_heapfity(i);
	// min_heapfity�� ȣ���Ͽ� ���� ������ ���� ����
}

void HeapSort::vector_swap(int a, int b)	//a,b �ε����� vector�� swap�ϴ� �Լ�
{
	pair<int, int> temp;
	temp = v[a];
	v[a] = v[b];
	v[b] = temp;
}

void HeapSort::heapSort()	//�켱���� Queue �� min heap�� ����Ͽ� �����ϴ� �Լ�
{
	build_heap();

}
