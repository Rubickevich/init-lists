#include <iostream>
class Competitor
{
	char lastName[40];
	bool gender; //1 - male, 0 - female
	int medalCount;
public:
	//constructors
	Competitor(const char* lastName, bool gender, int medalCount) : gender(gender), medalCount(medalCount)
	{
		strcpy_s(this->lastName, 40, lastName);
	}
	Competitor(char* lastName, bool gender) : Competitor(lastName, gender, 0){}
	Competitor(char* lastName) : Competitor(lastName, 0, 0) {}
	Competitor() : Competitor("No last name", 0, 0) {}
	//destructor
	~Competitor() { std::cout << "I'm a destructor" << std::endl; }
	//additional methods
	void Show()
	{
		std::cout << "Competitor name: " << lastName << std::endl;
		std::cout << "Competitor gender: " << (gender? "Male" : "Female") << std::endl;
		std::cout << "Competitor medal count: " << medalCount << std::endl;
	}
};
int main()
{
	std::cout << "Please fill data about the competitor" << std::endl;
	char lastName[40];
	int medalCount;
	bool gender;
	std::cout << "Write lastname: ";
	std::cin >> lastName;
	std::cout << "Write medal count: ";
	std::cin >> medalCount;
	std::cout << "Write gender (1 - male, 0 - female): ";
	std::cin >> gender;
	Competitor* full = new Competitor(lastName, gender, medalCount);
	Competitor noMedals(lastName, gender);
	Competitor onlyName(lastName);
	Competitor noInfo;
	full->Show();
	delete full;
	noMedals.Show();
	onlyName.Show();
	noInfo.Show();
}