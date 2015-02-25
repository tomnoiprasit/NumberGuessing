#include <iostream>
#include <string>
#include <random>
using std::cin;
using std::cout;
using std::default_random_engine;
using std::endl;

int main() {

	int minValue{ 1 };
	int maxValue{ 100 };

	cin >> minValue >> maxValue;

	default_random_engine e(rand());
	cout << e() << endl;
	std::uniform_int_distribution<int> intValue(minValue, maxValue);

	cout << intValue(e) << endl;
	
	std::string theAnswer{ "Y" };
	do {
		int theNumber = intValue(e);
		int guessNumber{ 0 };
		do {
			cout << "Choose a number between "
				<< minValue
				<< " and "
				<< maxValue
				<< " : ";
			cin >> guessNumber;
			if (!cin) {
				cin.clear();
				std::string removeThisLine;
				std::getline(cin, removeThisLine);
			}
			else {
				if (!(guessNumber < minValue || guessNumber > maxValue)) {
					if (guessNumber > theNumber)
						cout << "My number is lower than "
						<< guessNumber << endl;
					else if (guessNumber < theNumber)
						cout << "My number is higher than "
						<< guessNumber << endl;
					else
						cout << "You've won" << endl;
				}
			}
		} while (guessNumber != theNumber);
		cout << "Another game? (Y/N) ";
		cin >> theAnswer;
	} while (theAnswer == "Y" || theAnswer == "y");
	system("pause");
	return 0;
}