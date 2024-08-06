/*
	Q1.	임의의 한 단어를 생성하고 사용자가 한번에
		한 문자만 추측하도록 해서 단어를 맞추는 게임.

		단어의 각 문자는 '*' 으로 표시된다.
		사용자가 올바른 추측을 했을 때 실제 문자가 화면에 표시된다.

		사용자가 단어를 맞추기를 끝냈을 때 실수한 횟수를 표시하고,
		다른 단어를 계속할 것인지를 묻도록 한다.

		ex) 생성된 단어: apple
		> 단어 중 한 글자를 입력하시오. ***** > a
		>> a****

		> 단어 중 한 글자를 입력하시오. a**** > r
		>> r은 단어에 포함되지 ㅇ낳습니다.

		> 단어 중 한 글자를 입력하시오. a**** > a
		>> a는 이미 단어에 포함되어 있습니다.
		...

		>> 총 xx번 실패, 00번 만에 정답! apple
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <time.h>


using namespace std;

void PrintAnswerState(const string& answer, const int* leftAlphabets)
{
	for (int i = 0; i < answer.size(); i++)
	{
		if (leftAlphabets[answer[i] - 'a'] == 1)
			cout << "*";
		else
			cout << answer[i];
	}
}
int CheckFullAnswer(const string& answer, const int* leftAlphabets)
{
	for (int i = 0; i < answer.size(); i++)
	{
		if (leftAlphabets[answer[i] - 'a'] == 1)
			return false;
	}
	return true;
}
string CreateAnswer(vector<string>& answerList)
{
	srand((unsigned int)time(NULL));
	return answerList[rand() % answerList.size()];
}

int main()
{
	vector<string> answerList = { "apple", "banana", "grape", "lemon", "strawberry", "pear", "watermelon" };
	string answer = CreateAnswer(answerList);
	string userInput;

	int leftAlphabets[26] = { 0 };
	int fails = 0, tries = 0;
	bool isFullAnswer = false;

	for (int i = 0; i < 26; i++)
		leftAlphabets[i] = -1;

	for (int i = 0; i < answer.size(); i++)
		leftAlphabets[answer[i] - 'a'] = 1;
	
	while (!isFullAnswer)
	{
		++tries;

		cout << "\n> 단어 중 한 글자를 입력하시오. ";
		PrintAnswerState(answer, leftAlphabets);

		cout << " > ";
		cin >> userInput;

		if (userInput.size() > 1)
		{
			cout << ">> 잘못된 입력입니다.\n";
			continue;
		}
		if (leftAlphabets[userInput[0] - 'a'] == -1)
		{
			cout << ">> " << userInput[0] << "은 단어에 포함되지 않습니다.\n";
			++fails;
		}
		else if (leftAlphabets[userInput[0] - 'a'] == 0)
		{
			cout << ">> " << userInput[0] << "은 이미 단어에 포함되어 있습니다.\n";
			++fails;
		}
		else
		{
			leftAlphabets[userInput[0] - 'a'] = 0;
			cout << ">> ";
			PrintAnswerState(answer, leftAlphabets);
			cout << '\n';
		}
		isFullAnswer = CheckFullAnswer(answer, leftAlphabets);
	}
	cout << "\n>> 총 " << fails << "번 실패, " << tries << "번 만에 정답! " << answer << '\n';

	return 0;
}

