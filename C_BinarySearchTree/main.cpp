#include <iostream>
#include <map>

using namespace std;

int main()
{
	map<int, int> m;

	m.insert(make_pair(1, 2));
	cout << m[1] << '\n';

	m.insert(make_pair(1, 3));
	cout << m[1] << '\n';
}