#include <iostream>
using namespace std;

int main() {
	char id[15];

	int bY, age;	// bY : birthYear
	char sex;
	cin >> id;

	switch (id[7]-48) {
		case 1:
			sex = 'M';
			bY = 1900 + 10 * (id[0] - 48) + (id[1] - 48);
			age = 2019 - bY + 1;
			break;
		case 2:
			sex = 'W';
			bY = 1900 + 10 * (id[0] - 48) + (id[1] - 48);
			age = 2019 - bY + 1;
			break;
		case 3:
			sex = 'M';
			bY = 2000 + 10 * (id[0] - 48) + (id[1] - 48);
			age = 2019 - bY + 1;
			break;
		case 4:
			sex = 'W';
			bY = 2000 + 10 * (id[0] - 48) + (id[1] - 48);
			age = 2019 - bY + 1;
			break;
	}

	cout << age << " " << sex;

	return 0;
}
