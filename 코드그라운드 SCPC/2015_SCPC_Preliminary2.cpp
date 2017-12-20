/*
You should use the statndard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful.
*/

#include <iostream>
#include <vector>

using namespace std;

int Answer;

int main(int argc, char** argv)
{
	int T, test_case;
	/*
	The freopen function below opens input.txt file in read only mode, and afterward,
	the program will read from input.txt file instead of standard(keyboard) input.
	To test your program, you may save input data in input.txt file,
	and use freopen function to read from the file when using cin function.
	You may remove the comment symbols(//) in the below statement and use it.
	Use #include<cstdio> or #include <stdio.h> to use the function in your program.
	But before submission, you must remove the freopen function or rewrite comment symbols(//).
	*/

	// freopen("input.txt", "r", stdin);

	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{
		int K;
		Answer = 0;
		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
		Implement your algorithm here.
		The answer to the case will be stored in variable Answer.
		*/
		cin >> K;
		vector<vector<int>> room(K, vector<int>(K, 0));
		vector<vector<int>> mirror(K, vector<int>(K, 0));

		for (int i = 0; i < K; i++) {
			for (int j = 0; j < K; j++) {
				char a;
				cin >> a;
				room[i][j] = a - 48;
			}
		}

		// right = 1, left = 2 up = 3, down = 4
		int x = 0, y = 0, direction = 1;
		while(x < K && x >= 0 && y < K && y >= 0) {
			if (room[y][x] == 1) {
				if (mirror[y][x] == 0) {
					mirror[y][x]++;
					Answer++;
				}
				if (direction == 1) direction = 3;
				else if (direction == 2) direction = 4;
				else if (direction == 3) direction = 1;
				else direction = 2;
			}
			else if (room[y][x] == 2) {
				if (mirror[y][x] == 0) {
					mirror[y][x]++;
					Answer++;
				}
				if (direction == 1) direction = 4;
				else if (direction == 2) direction = 3;
				else if (direction == 3) direction = 2;
				else direction = 1;
			}
			if (direction == 1) x++;
			else if (direction == 2) x--;
			else if (direction == 3) y--;
			else y++;
		}
		/////////////////////////////////////////////////////////////////////////////////////////////

		// Print the answer to standard output(screen).
		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}