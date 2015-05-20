#include "Setting.h"
#include <string.h>
using namespace std;

class SettingTests {	
private :
	string testresult[6];
	string Compare(string a, string b) {
		if (a != b) {
			return "failed"; 
		} else return "OK";
	}
	void Test() {	
		string sett[7] = {"7aza", "9tatar","jklDGdG282","dG282gew","wefxewfwzfx","ferfjgtrgfewf","ewKLIBgnfea"};
		string param[7] = {"23fdgrecfrfr", "geeezazaEEFFD","00000","1488","32444yt32e","pohfdsfsexg","aovncgsldhvnduasdpf"};
		string def = "dwfrsdgdfmnbfg";
		try {
			setting *nsett = new setting("stest.cfg");
			testresult[0] = "OK";
		} catch (exception) {
			testresult[0] = "Setting create failed!";
		}	
		setting *nsett = new setting("stest.cfg");
		try {
			for (int i = 0; i < 7; i++) {
				nsett->set(sett[i], param[i]);
			}
			testresult[1] = "OK";
		} catch (exception) {
			testresult[1] = "Setting set failed!";
		}
		try {
			for (int i = 0; i < 7; i++) {
				string res = Compare(param[i], nsett->get(sett[i], def));
				testresult[2] = res;
			}
		} catch (exception) {
			testresult[2] = "error";
		}

		nsett->reload();

		for (int i = 0; i < 7; i++) {
			string res = Compare(param[i], nsett->get(sett[i], def));
			testresult[3] = res;
		}

		nsett->reset();

		for (int i = 0; i < 7; i++) {
			string hh = nsett->get(sett[i], def);
			string res = Compare(def, hh);
			testresult[4] = res;
		}

		delete nsett;
		nsett = new setting("stest.cfg");

		for (int i = 0; i < 7; i++) {
			string res = Compare(def, nsett->get(sett[i], def));
			testresult[4] = res;
		}

		for (int i = 0; i < 7; i++) {
			nsett->set(sett[i], param[i]);
		}

		delete nsett;
		nsett = new setting("stest.cfg");

		for (int i = 0; i < 7; i++) {
			string res = Compare(param[i], nsett->get(sett[i], def));
			testresult[5] = res;
		}
	}
public :
	SettingTests() {		
	}
	void runTest() {
		Test();
		if (testresult[0] != "OK") {
			cout << testresult[0];
		} else {
			if (testresult[1] != "OK") {
				cout << testresult[1];
			} else {
				string testmessage[6] = {
					"Setting create", 
					"Setting set",
					"Setting get",
					"Setting reload",
					"Setting reset",
					"Setting load from file"
				};
				for (int i = 0; i < 6; i++) {
					cout << testmessage[i] << " : " << testresult[i] << endl;
				}
			}
		}
	}
};

int main() {
	SettingTests *tests = new SettingTests();
	tests->runTest();
}

