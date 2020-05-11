#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int n;

	while(scanf("%d", &n), n){

		vector<int> v;
		int count = 0;

		while(n--){
			int num;
			scanf("%d", &num);

			v.push_back(num);
		}

		for (vector<int>::iterator it1 = v.begin() + 1 ; it1 != v.end(); ++it1){
			for(vector<int>::iterator it2 = it1; (it2 != v.begin()) && (*it2 < *(it2 - 1)); it2--){
				iter_swap(it2, it2 - 1);
				count++;
			}
		}

		cout << count << endl;

	}

	return 0;
}