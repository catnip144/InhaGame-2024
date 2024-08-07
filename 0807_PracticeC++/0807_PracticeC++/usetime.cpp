#include "mytime0.h"

using namespace std;

//.operator+(argument)

int main()
{
	//Time weeding(4, 35);
	//Time waxing(2, 47);
	//Time total, diff, adjusted;

	//cout << "weeding time = ";
	//weeding.Show();
	//cout << endl;

	//cout << "waxing time = ";
	//waxing.Show();
	//cout << endl;

	//cout << "total work time = ";
	//total = weeding + waxing;
	//total.Show();
	//cout << endl;

	////diff = waxing - weeding;
	//diff = weeding - waxing;
	//cout << "weeding time - waxing time = ";
	//diff.Show();
	//cout << endl;

	//adjusted = total * 1.5;
	////adjusted = 1.5 * total;

	//cout << "adjusted work time = ";
	//adjusted.Show();
	//cout << endl;

	/////////////////////////////////////////////////////////////////

	Time aida(3, 35);
	Time tosca(2, 48);

	cout << "Aida와 Tosca:\n";
	cout << aida << "; " << tosca << endl;

	Time temp = aida + tosca;
	cout << "Aida + Tosca: " << temp << endl;

	temp = aida * 1.17;
	cout << "Aida * 1.17: " << temp << endl;

	cout << "10 * Tosca: " << 10 * tosca << endl;

	return 0;
}

