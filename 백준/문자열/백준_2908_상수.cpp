#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int a, b;
int result1, result2;

int swap(int num) {
	int temp1;
	int temp10;
	int temp100;
	string str;

	temp1 = num % 10; //1�� �ڸ�
	num = num / 10;
	temp10 = num % 10; //10���ڸ� 
	temp100 = num / 10; //100���ڸ� 
	str = to_string(temp1) + to_string(temp10) + to_string(temp100); // int to string


	return stoi(str);
}
int main()
{
	cin >> a >> b;
	result1 = swap(a);
	result2 = swap(b);
	cout << max(result1, result2);
	return 0;

}