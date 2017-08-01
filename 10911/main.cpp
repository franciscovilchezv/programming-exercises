#include <iostream>
#include <cmath>
#include <string>

using namespace std;

double distance2points(int x1, int y1, int x2, int y2){
	return sqrt(((x1*x1) - (2*x1*x2) + (x2*x2))
		+ ((y1*y1) - (2*y1*y2) + (y2*y2)));
}

double distance(){
	return 0.0;
}

int main(){
	int n;

	while(scanf("%d", &n), n){
		int cant = n * 2;
		cout << n << endl;

		while(cant--){
			string s;
			int x;
			int y;

			scanf("%*s %d %d", &x, &y);
		}
	}

	return 0;
}
