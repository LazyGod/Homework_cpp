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
		class param {
			private:
				param(param const &);
			public:
				operator std::string() const;
				operator int() const;
				operator bool() const;
				operator double() const;
 
				param & operator=(std::string const &);
				param & operator=(int);
				param & operator=(bool);
				param & operator=(double);
 
				param & operator+=(std::string const &);
				param & operator+=(int);
				param & operator+=(double);
 
				param & operator-=(int);
				param & operator-=(double);
 
				param & operator*=(int);
				param & operator*=(double);
 
				param & operator/=(int);
				param & operator/=(double);
 
				param & operator|=(bool);
				param & operator&=(bool);
                bool is_empty() const;
		};
 

		setting(std::string const & filename);

		std::string const & get(std::string const & name, 
			std::string const & def = "") const;

		void set(std::string const & name, 
			std::string const & value);

		void reset();		

		void reload();
 
		const param operator[](std::string const & name) const;

		param operator[](std::string const & name);
};