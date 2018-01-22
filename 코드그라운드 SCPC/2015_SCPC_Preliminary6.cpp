/*
You should use the statndard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful.
*/

#include <iostream>

using namespace std;

int Answer;

int find_gcd(long long a, long long b) {
	if (a == 0 && b == 0)
		return 0;
	else if (a == 0 || b == 0)
		return -1;

	if (a % b == 0)
		return b;
	else
		return find_gcd(b, a % b);
}

int find_num_of_measure(long long a) {
	long long count = 0, i = 1;
	if (a == -1)
		return 0;
	if (a == 0 || a == 1)
		return 1;

	for (i = 1; i * i < a; i++) {
		if (a % i == 0) count += 2;
	}
	if (a == i * i) count++;

	return count;
}

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
		int M;
		long long first, second, diff;
		Answer = 0;
		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
		Implement your algorithm here.
		The answer to the case will be stored in variable Answer.
		*/
		cin >> M;
		cin >> first >> second;
		diff = second - first;

		for (int i = 2; i < M; i++) {
			long long a, temp;
			cin >> a;
			temp = a - second;
			second = a;

			if (diff > temp) {
				diff = find_gcd(diff, temp);
			}
			else {
				diff = find_gcd(temp, diff);
			}
			
			if (diff == -1) break;
		}

		Answer = find_num_of_measure(diff);
		/////////////////////////////////////////////////////////////////////////////////////////////

		// Print the answer to standard output(screen).
		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}