#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int l, n;

	cout << "도로의 길이: ";
	cin >> l;

	cout << "가로등 개수: ";
	cin >> n;

	cout << "가로등 위치 입력\n>> ";
	vector<int> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];

	sort(v.begin(), v.end());

	int lamps = v.size();
	int currentLightPos = 0;
	int d = 1;

	while (d++)
	{
		if ((v[0] - d > 0) || (v.back() + d < l))
			continue;

		bool flag = true;
		for (int i = 0; i < lamps; i++)
		{
			int lightStart = v[i] - d;
			int lightEnd = v[i] + d;

			if (currentLightPos < lightStart)
			{
				flag = false;
				break;
			}
			currentLightPos = lightEnd;
		}
		if (flag)
			break;
	}
	cout << d;
	return 0;
}

