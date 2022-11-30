#include <iostream>


class PhoneBook
{
public:
	PhoneBook()
	{
		_initials			  = nullptr;
		_homePhone		  = nullptr;
		_mobilePhone	  = nullptr;
		_additionalInfo = nullptr;
	}
	PhoneBook(const char* Initials, const char* HomePhone, const char* MobilePhone, const char* AdditionalInfo)
	{
		_initials = new char[strlen(Initials + 1)];
		strcpy_s(_initials,  strlen(Initials + 1), Initials);

		_homePhone = new char[strlen(HomePhone + 1)];
		strcpy_s(_homePhone,  strlen(HomePhone + 1), HomePhone);

		_mobilePhone = new char[strlen(MobilePhone + 1)];
		strcpy_s(_mobilePhone,  strlen(MobilePhone + 1), MobilePhone);

		_additionalInfo = new char[strlen(AdditionalInfo + 1)];
		strcpy_s(_additionalInfo,  strlen(AdditionalInfo + 1), AdditionalInfo);
	}
	
	void InputData()
	{
		std::cout << "Enter the new contact: " << std::endl;

		std::cout << "Initials: ";
		std::cin  >> _initials;
		std::cout << std::endl;

		std::cout << "Home phone: ";
		std::cin  >> _homePhone;
		std::cout << std::endl;

		std::cout << "Mobile phone: ";
		std::cin  >> _mobilePhone;
		std::cout << std::endl;

		std::cout << "Additional infotmation: ";
		std::cin  >> _additionalInfo;
		std::cout << std::endl;
	}
	void OutputData()
	{
		if (_initials       == nullptr &&
			  _homePhone      == nullptr &&
			  _mobilePhone    == nullptr &&
			  _additionalInfo == nullptr)
		{
			std::cout << "Empty cell!" << std::endl;
		}
		else
		{
			std::cout << "Initials: "        << _initials;
			std::cout << "Home phone: "      << _homePhone;
			std::cout << "Mobile phone: "    << _mobilePhone;
			std::cout << "Additional info: " << _additionalInfo;
		}
	}
	~PhoneBook()
	{
		delete[] _initials;
		delete[] _homePhone;
		delete[] _mobilePhone;
		delete[] _additionalInfo;
	}
private:
	char* _initials;
	char* _homePhone;
	char* _mobilePhone;
	char* _additionalInfo;
};

int main()
{

}