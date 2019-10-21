//https://programmers.co.kr/learn/courses/30/lessons/42578

#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    map<string,int> hash; //key �� ����, value �� ����� 
    
    for(int i=0; i<clothes.size();i++){
        hash[clothes[i][1]]++;  // �ش� ������ ������ ���� ����
    }
    
    for(auto it=hash.begin(); it!=hash.end(); it++)
       answer = answer * (it->second +1) ;   
    // (A���� �� ������ + 1)*(B���� �� ������ + 1)*(C���� �� ������ + 1) - 1

    return answer-1;
}