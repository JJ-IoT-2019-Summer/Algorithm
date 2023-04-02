//https://programmers.co.kr/learn/courses/30/lessons/12905

include <iostream>
#include<vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> board)
{
	int answer = 0;
	int row = board.size();
	int col = board[0].size();

	vector<vector<int>> dp;
	dp.assign(row + 1, vector<int>(col + 1, 0)); //(n+1)*(n+1)�� 2���� ���� �Ҵ� �� 0���� �ʱ�ȭ

	int max = -1;

	for (int i = 1; i < row + 1; ++i) {
		for (int j = 1; j < col + 1; ++j) {
			if (board[i - 1][j - 1] == 1) {
				dp[i][j] = min({ dp[i - 1][j - 1] , dp[i][j - 1], dp[i - 1][j] }) + 1;
			}
			if (dp[i][j] > max) max = dp[i][j];  //���� ū ���簢���� ��� ������Ʈ       
		}
	}

	return max * max;
}