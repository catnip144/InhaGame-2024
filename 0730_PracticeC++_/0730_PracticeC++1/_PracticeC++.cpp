/*

*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

int zeros[50] = { 1, 0, 1, 1, 0 };
int ones[50] = { 0, 1, 1, 2, 0  };

/*

f3:  0 1개 1 2개
f4: 

f(2) f(1) f(0)

f(3) f(2) f(1)
     f(1), f(0)

f(4) f(3) f(2)
       
*/

int main()
{
	int n, num;
	cin >> n;

	for (int i = 4; i <= 50; i++)
	{
		zeros[i] = zeros[i - 1] + zeros[i - 2];
		ones[i] = ones[i - 1] + ones[i - 2];
	}
	while (n--)
	{
		cin >> num;
		cout << zeros[num] << " " << ones[num] << '\n';
	}
	return 0;
}

