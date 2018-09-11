#include <iostream>
#include <vector>

using namespace std;
typedef vector<vector<char>> matrix;

void rotate(matrix &, int);
int filter(matrix, matrix, int, int);

int main() {

	int N, n;
	cin >> N >> n;
	while (N && n) {
		matrix A(N, vector<char>(N));
		for (int r = 0; r < N; ++r) {
			for (int c = 0; c < N; ++c) {
				cin >> A[r][c];
			}
		}
		matrix B(n, vector<char>(n));
		for (int r = 0; r < n; ++r) {
			for (int c = 0; c < n; ++c) {
				cin >> B[r][c];
			}
		}
		cout << filter(A, B, N, n);
		for (int i = 0; i < 3; ++i) {
			rotate(B, n);
			cout << " " << filter(A, B, N, n);
		}
		cout << endl;
		
		/*
		for (int r = 0; r < N; ++r) {
			for (int c = 0; c < N; ++c) {
				cout << A[r][c];
			}
			cout << endl;
		}
		/*
		for (int r = 0; r < n; ++r) {
			for (int c = 0; c < n; ++c) {
				cout << B[r][c];
			}
			cout << endl;
		}
		*/
		cin >> N >> n;
	}
	return 0;
}

void rotate(matrix &M, int N) {
	// Inplace rotate
	// r,c --> c,(N-r-1) per 90 degree rotate
	// c,(N-r-1) --> (N-r-1),(N-c-1)
	// (N-r-1),(N-c-1) --> (N-c-1),r
	// (N-c-1),r --> r,c

	// Goes through half the rows rounded down, 
	// every spot that needs to rotate is caught...
	for (int r = 0; r < N / 2; ++r) {
		// ...by this loop, which ignores
		// spots that were already altered
		for (int c = r; c < N - r - 1; ++c) {
			// top left is saved
			int temp = M[r][c];
			// bottom left moved to top left
			M[r][c] = M[N - c - 1][r];
			// bottom right moved to bottom left
			M[N - c - 1][r] = M[N - 1 - r][N - 1 - c];
			// top right to bottom right
			M[N - 1 - r][N - 1 - c] = M[c][N - r - 1];
			// top right overwritten with top left
			M[c][N - r - 1] = temp;
		}
	}
	return;
}
/*
int filter(matrix M, matrix m, int N, int n) {
	int match = 0;
	// For each spot the filter can pass over...
	for (int r = 0; r < N - n + 1; ++r) {
		for (int c = 0; c < N - n + 1; ++c) {
			// ...loop through every position the filter 
			// overlays
			int flag = 1;
			for (int rf = 0; rf < n; ++rf) {
				for (int cf = 0; cf < n; ++cf) {
					if (m[rf][cf] != M[r][c]) {
						flag = 0;
						break;
					}
				}
			}
			match += flag;
		}
	}
	return match;
}
*/
int filter(matrix M, matrix m, int N, int n) {
	int match = 0;
	// For each spot the filter can pass over...
	for (int r = 0; r < N - n + 1; ++r) {
		for (int c = 0; c < N - n + 1; ++c) {
			// ...loop through every position the filter 
			// overlays
			int flag = 1;
			int rf = 0;
			// choosing to use while loops for the potential 
			// efficiency gained by not continuing to compare
			// failed matches
			while (flag && rf < n) {
				int cf = 0;
				while (flag && cf < n) {
					if (m[rf][cf] != M[r + rf][c + cf]) {
						flag = 0;
					}
					++cf;
				}
				++rf;
			}
			match += flag;
		}
	}
	return match;
}
