#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cctype>

using namespace std;

int main()
{
	string userInput;
	//string userInput = "((4*2+12)*(123+7))";
	// -2*(-1-1)-3.9+6/((3+3)/6.0)

	cout << "수식: ";
	cin >> userInput;

	string temp = "(";
	temp += userInput;
	userInput = temp;
	userInput += ')';

	int opVal[128] = { 0, };
	opVal['+'] = opVal['-'] = 1;
	opVal['*'] = opVal['/'] = 2;

	vector<char> opStack;
	vector<double> operand;
	queue <string> postfix;
	string numTemp = "";

	for (int i = 0; i < userInput.size(); i++)
	{
		if (userInput[i] == '-' && userInput[i - 1] == '(')
			numTemp += userInput[i];

		else if (isdigit(userInput[i]) || userInput[i] == '.')
			numTemp += userInput[i];
		else
		{
			if (numTemp != "")
			{
				postfix.push(numTemp);
				numTemp = "";
			}
			if (userInput[i] == ')')
			{
				while (!opStack.empty() && (opStack.back() != '('))
				{
					string temp = "";
					temp += opStack.back();
					postfix.push(temp);
					opStack.pop_back();
				}
				if (!opStack.empty())
					opStack.pop_back();
			}
			else if (userInput[i] != '(')
			{
				while (!opStack.empty() && (opVal[userInput[i]] <= opVal[opStack.back()]))
				{
					string temp = "";
					temp += opStack.back();
					postfix.push(temp);
					opStack.pop_back();	
				}
				opStack.push_back(userInput[i]);
;			}
			else
				opStack.push_back(userInput[i]);
		}
	}
	if (numTemp != "")
		postfix.push(numTemp);

	int qSize = postfix.size();
	for (int i = 0; i < qSize; i++)
	{
		if (isdigit(postfix.front()[0]) || (postfix.front().size() > 1 && postfix.front()[0] == '-'))
			operand.push_back(stod(postfix.front()));
		else
		{
			int arSize = operand.size();
			switch (postfix.front()[0])
			{
			case '+':
				operand[arSize - 2] += operand[arSize - 1];
				break;

			case '-':
				operand[arSize - 2] -= operand[arSize - 1];
				break;

			case '*':
				operand[arSize - 2] *= operand[arSize - 1];
				break;

			case '/':
				operand[arSize - 2] /= operand[arSize - 1];
				break;
			}
			operand.pop_back();
		}
		postfix.pop();
	}
	cout << operand[0] << endl;
	return 0;
}

