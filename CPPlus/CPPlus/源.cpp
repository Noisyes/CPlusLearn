#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;
int main()
{
	vector<int> vi = { 1,2,35,2,365,2,346,435,67,34,6 };
	auto t = count_if(vi.begin(), vi.end(), not1(bind2nd(less<int>(), 5)));
	cout << t << endl;
	return 0;
}