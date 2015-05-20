#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
using namespace std;

class setting {
    private:
		map<string, string> Setting;
		string fname;
		void save();
		void CheckFile();
    public: 		
		setting(std::string const & filename);
		
		std::string const & get(std::string const & name, 
			std::string const & def = "") const;
		
		void set(std::string const & name, 
			std::string const & value);
		
		void reset();		
		
		void reload();
 
};