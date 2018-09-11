#include <iostream>
#include <vector>

using namespace std;
typedef vector< vector<char> > matrix;

void rotate(matrix &);

int main() {
  
  int N, n;
  cin >> N >> n;
  while(N && n){
    matrix A(N, vector<char>(N));
    for(int r = 0; r < N; ++r){
      for(int c = 0; c < N; ++c){
        cin >> A[r][c];
      }
    }
    matrix B(n, vector<char>(n));
    for(int r = 0; r < n; ++r){
      for(int c = 0; c < n; ++c){
        cin >> B[r][c];
      }
    }
  }
  return 0;
}

void rotate(matrix &M) {


return;
}

// r,c --> c,(N-r-1) per 90 degree rotate
