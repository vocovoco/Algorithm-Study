#include <vector>
#include <iostream>

using namespace std;

int MOD = 20170805;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int m, int n, vector<vector<int>> city_map) {
    int answer = 0;
    int right[500][500] = { 0, };
    int down[500][500] = { 0, };
    
    right[0][0] = 1;
    down[0][0] = 1;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(i == 0 && j == 0) continue;
            if(city_map[i][j] == 1){
                right[i][j] = 0;
                down[i][j] = 0;
            }else if(city_map[i][j] == 2){
                if(j > 0) right[i][j] = right[i][j - 1] % MOD;
                if(i > 0) down[i][j] = down[i - 1][j] % MOD;
            }else if(city_map[i][j] == 0){
                if(i == 0){
                    right[i][j] = (right[i][j] + right[i][j - 1]) % MOD;
                    down[i][j] = (down[i][j] + right[i][j - 1]) % MOD;
                }else if(j == 0){
                    right[i][j] = (right[i][j] + down[i - 1][j]) % MOD;
                    down[i][j] = (down[i][j] + down[i - 1][j]) % MOD;
                }else{
                    right[i][j] = (right[i][j] + right[i][j - 1] + down[i - 1][j]) % MOD;
                    down[i][j] = (down[i][j] + right[i][j - 1] + down[i - 1][j]) % MOD;
                }
            }
        }
    }
    answer = (right[m - 1][n - 2] + down[m - 2][n - 1]) % MOD;
    return answer;
}