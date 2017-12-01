#include <vector>
#include <queue>

using namespace std;

#define MAX(a, b) (a > b) ? a : b

int visit[100][100];
int dfs(int i, int j, int color, int m, int n, vector<vector<int>> picture){
    int area = 1;
    visit[i][j] = 1;
    if(i > 0 && visit[i - 1][j] != 1 && picture[i - 1][j] == color){
        area += dfs(i - 1, j, color, m, n, picture);
    }
    if(i < m - 1 && visit[i + 1][j] != 1 && picture[i + 1][j] == color){
        area += dfs(i + 1, j, color, m, n, picture);
    }
    if(j > 0 && visit[i][j - 1] != 1 && picture[i][j - 1] == color){
        area += dfs(i, j - 1, color, m, n, picture);
    }
    if(j < n - 1 && visit[i][j + 1] != 1 && picture[i][j + 1] == color){
        area += dfs(i, j + 1, color, m, n, picture);
    }
    return area;
}
// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    queue<pair<int, int>> spot;
    int number_of_area = 0;
    int max_size_of_one_area = 0;

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(picture[i][j] > 0){
                spot.push({ i, j });
                visit[i][j] = 0;
            }
        }
    }
    while(!spot.empty()){
        int i = spot.front().first;
        int j = spot.front().second;
        spot.pop();
        if(visit[i][j] == 1) continue;
        int area = dfs(i, j, picture[i][j], m, n, picture);
        max_size_of_one_area = MAX(max_size_of_one_area, area);
        number_of_area++;
    }
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}