#include<iostream>
#include<string>
#include<fstream>
using namespace std;
void menu() {
	cout << "1/ to create new account " << endl;
	cout << "2/ to login " << endl;
}
bool checklogin() {
	system("cls");
	string username, password,us,pa;
	cout << "Enter your username : ";   cin >> username;
	cout << "Enter your password : ";   cin >> password;
	
	fstream read(username + ".txt", ios::in);
	getline(read, us);
	getline(read, pa);
	if (username == us && password == pa) return true;
	else return false;
}
int main() {
	int choise;
	
    menu();
	cout << "Enter choice : ";    cin >> choise;
	system("cls");
	if (choise == 1) {
		string username, password;

		cout << "Creat your username : ";   cin>> username;
		cout << "Creat your password (paswword must more than 14): ";   cin>> password;

		for (int i = 0;; i++)
		{
			if (password.length() > 14)
				break;
			else {
				system("cls");
				cout << "invaled passwod please follow the rules and enter your password again \n";
				cin >> password;
			}
		}
	
		fstream file;
		file.open(username+".txt",ios::out);
		if (file.is_open()) {
			file<< username << endl  << password;
			file.close();
		}
		main();

	}
	if (choise == 2) {
		bool check = checklogin();

		if (check == 1) {
			system("cls");
			cout << "Success login " << endl;
		}

		else{
			system("cls");
			cout << "password or username is incorrect " << endl << "Try again" << endl;
			main();
		}
	}
	system("pause");
	return 0;
}