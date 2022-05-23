#include <iostream>
#include <string>

using namespace std;

bool over = false;
string mreaderPath1;

void logo() {
	cout <<	"Mreader v0.1a" << endl;
	cout <<	" " << endl;
	cout <<	"Interactive mode" << endl;
	cout <<	" " << endl; // logo (start screen)
}

void help() {
	cout << "Commands:" << endl;
	cout << "help: show this list." << endl;
	cout << "path: command to change path to your document directory." << endl;
	cout << "clear: clear your console." << endl;
	cout << "read: command to start read." << endl;
	cout << "exit or quit: quit mreader." << endl;
}

void path_change() {
	cout << "Do you want to change directory path? y, n (yes, no) : " ;
	string reply;
	getline(cin, reply);
	if (reply == "y" || reply == "yes" || reply == "Y" || reply == "Yes") {
		cout << "FULL path to document directory (with / in the end): ";
		getline(cin, mreaderPath1); // path to doc dir
	}

}

void feh() {
	int countFiles = system(("ls " + mreaderPath1 + " | wc -l").c_str());
	int k = 0;
	int i = 0;
	int countPage = 0; // count Page, starts with 0
	cout << "Press \"q\" to exit, \"'\" to open previous page or any other key to continue" << endl;
	while(k!= countFiles+1) {
		string reply;
		cout << "Page " + to_string(countPage)<< endl;
		system(("feh -q -. " + mreaderPath1 + to_string(i) + ".png &").c_str());
		system(("feh -q -. " + mreaderPath1 + to_string(i) + ".jpeg &").c_str());
		cout << "> ";
		getline(cin, reply);
		if (reply == "q") {k= countFiles + 1;}
		else if (reply == "'") {i--;countPage--;}
		else {i++;countPage++;}
		system("killall feh");
	}
}

void prompt() {
	cout << "> "; // cli prompt
	string reply;
	getline(cin, reply); // user reply
	if (reply == "exit" || reply == "quit") over = true;
	else if (reply == "clear") {system("clear"); logo();}
	else if (reply == "help") help();
	else if (reply == "path") path_change();
	else if (reply == "read") feh();

	else cout << "Unknown command: " << "\"" << reply <<  "\""<< endl;

}


int main() {
	logo();
while (!over) {
	prompt();
}}
