#include "Setting.h"

setting::setting(std::string const & filename) {
	fname = filename;
	reload();
}

void setting::reload() {
	CheckFile();
	Setting.clear();
	ifstream cin (fname);
	string set, value;
	while (cin) {
		getline(cin, set, ' ');
		getline(cin, value);
		Setting[set] = value;
	}
	cin.close();
}

std::string const & setting::get(std::string const & name, std::string const & def) const {
	if (Setting.count(name) != 0)
		return Setting.at(name);
	else 
	    return def;	
}

void setting::set(std::string const & name, std::string const & value) {
	CheckFile();
	Setting[name] = value;
	setting::save();
}

void setting::save() {
	CheckFile();
	ofstream cout (fname);
	map <string,string>::iterator temp;
	for (temp = Setting.begin(); temp != Setting.end(); temp++) {
		cout << (*temp).first << " " << (*temp).second << endl;
	}
	cout.close();
}

void setting::reset() {
	CheckFile();
	ofstream cout (fname);
	Setting.clear();
	cout.close();
}

void setting::CheckFile() {
	if (fname == "") {
		fname = "default.cfg";
	}
}