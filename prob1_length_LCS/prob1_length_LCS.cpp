#include <iostream>
#include <string.h>
using namespace std;
void print(int** table, int i, int j);
void print(char** table, int i, int j);		//bottom-up table ����ϱ� ���� �Լ�

int main()
{
	char X[] = "GOODMORNING";	//���ڿ� X
	char Y[] = "GUTENMORGEN";	//���ڿ� Y
	int m = sizeof(X) / sizeof(char);   // X ���ڹ迭�� ����
	int n = sizeof(Y) / sizeof(char);	// Y ���ڹ迭�� ����

	char *x = new char[m + 1];
	char *y = new char[n + 1];
	x[0] = ' '; for (int i = 1; i < m + 1;i++) 	x[i] = X[i - 1]; // bottom-up table ������ ���� �Ǿտ� ���� ����
	y[0] = ' '; for (int i = 1; i < n + 1;i++) 	y[i] = Y[i - 1];

	char **b = new char*[n + 1];
	int **c = new int*[n + 1];
	for (int i = 0; i < n + 1;i++)
	{
		b[i] = new char[m + 1];   //���������� LCS ���ڿ��� ã�� ���� �迭 b
	    c[i] = new int[m + 1];	  //LCS�� ���� ������ ��� �ִ� �迭 c
	}

	for (int i = 0; i < n + 1;i++)		//b,c �迭 �ʱ�ȭ
	{
		for (int j = 0; j < m + 1;j++)
		{
			b[i][j] = '_';
			c[i][j] = 0;
		}
	}

	for (int i = 1; i < n;i++)	// Y �迭�� ���ڵ鿡 ���� �ݺ���
	{
		for (int j = 1; j < m; j++)	// X �迭�� ���ڵ鿡 ���� �ݺ���
		{
			if (y[i] == x[j])  // X�� Y �迭�� ���ڰ� ���ٸ�
			{
				c[i][j] = c[i - 1][j - 1] + 1; // X�� Y�� ���� ��ġ�� c�迭�� �ε����� 1����
				b[i][j] = 'W';	// �������� ���� W (��) ǥ�� 
			}
			else if (c[i - 1][j] >= c[i][j - 1])	//X�� Y ���� ��ġ ���ʹ��� �迭�� ���� �� ���ʹ��� ���� ũ��
			{
				c[i][j] = c[i - 1][j];	//X,Y ��ǥ �� �ε����� ���� ������(�������� �ִ� LCS ����) �� ����
				b[i][j] = 'U';		     //���� ������ ŭ�� U(��)�� ǥ�� 
			}
			else
			{
				c[i][j] = c[i][j - 1];	//�ƴ϶�� X,Y ��ǥ �� �ε����� ���� ������(�������� �ִ� LCS ����) �� ����
				b[i][j] = 'L';		     //���� ������ ŭ�� U(��)�� ǥ�� 
			}
		}
	}
	print(c, m, n);		//LCS �ִ� ���� ���� �� ���� table ���
	print(b, m, n);		//�������� ���� ǥ�ø� ���� table ��� 

	cout << "X : " << X << endl << "Y : " << Y << endl; // X,Y �迭 ���
	cout << "LCS�� ���� : "<<c[n-1][m-1]<<endl; //LCS ���� ���

	delete x;
	delete y;
	for (int i = 0; i < n + 1;i++)delete[] b[i];   //���� �Ҵ� �迭�� ����
	delete[] b;
	for (int i = 0; i < n + 1;i++) delete[] c[i];
	delete[] c;

	return 0;

}

void print(int** table, int i, int j)	//LCS �ִ� ���� ���� �� ���� table ���
{
	for (int a = 0; a < j;a++)
	{
		for (int b = 0; b < i;b++)
		{
			cout << table[a][b] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void print(char** table, int i, int j)		//�������� ���� ǥ�ø� ���� table ���
{
	for (int a = 0; a < j;a++)
	{
		for (int b = 0; b < i;b++)
		{
			cout << table[a][b] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

