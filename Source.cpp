#include <iostream>


class PhoneBook
{
public:

	PhoneBook()
	{
		_initials			  = new char[100] {"Empty!"};
		_homePhone		  = new char[100] {"Empty!"};
		_mobilePhone	  = new char[100] {"Empty!"};
		_additionalInfo = new char[100] {"Empty!"};
	}
	PhoneBook(const char* Initials, const char* HomePhone, const char* MobilePhone, const char* AdditionalInfo)
	{
		_initials = new char [strlen(Initials + 1)];
		strcpy_s(_initials,  strlen(Initials + 1), Initials);

		_homePhone = new char [strlen(HomePhone + 1)];
		strcpy_s(_homePhone,  strlen(HomePhone + 1), HomePhone);

		_mobilePhone = new char [strlen(MobilePhone + 1)];
		strcpy_s(_mobilePhone,  strlen(MobilePhone + 1), MobilePhone);

		_additionalInfo = new char [strlen(AdditionalInfo + 1)];
		strcpy_s(_additionalInfo,  strlen(AdditionalInfo + 1), AdditionalInfo);
	}
	
	void InputData()
	{
		std::cout << "Enter the new contact: " << std::endl;
		_initials = new char[100];
		std::cout << "Initials: ";
		std::cin  >> _initials;
		std::cout << std::endl;

		_homePhone = new char[100];
		std::cout << "Home phone: ";
		std::cin  >> _homePhone;
		std::cout << std::endl;

		_mobilePhone = new char[100];
		std::cout << "Mobile phone: ";
		std::cin  >> _mobilePhone;
		std::cout << std::endl;

		_additionalInfo = new char[100];
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
			std::cout << "Initials: "        << _initials       << std::endl;
			std::cout << "Home phone: "      << _homePhone      << std::endl;
			std::cout << "Mobile phone: "    << _mobilePhone    << std::endl;
			std::cout << "Additional info: " << _additionalInfo << std::endl;
			std::cout << std::endl;
		}
	}
	void ShowPhoneBook(PhoneBook* obj, int& size)
	{
		std::cout << "CONTACT LIST!" << std::endl;

		for (size_t i = 0; i < size; i++)
		{ 
			std::cout << "Contact: " << i + 1 << std::endl;
			obj[i].OutputData();
		}
	}
	void CreatePhoneBook(PhoneBook* obj, int& size)
		
	{
		std::cout << "Enter phonebook size: ";
		std::cin  >> size;

			for (size_t i = 0; i < size; i++)
			{
				obj[i].InputData();
			}
	}
	void AddContact(PhoneBook* obj, int& size)
	{
		std::cout << "Adding the new contact:" << std::endl;
		for (size_t i = size; i < size+1; i++)
		{
			obj[i].InputData();
		}
		size += 1;

	}
	void DeleteContact(PhoneBook* obj, int& size)
	{
		int numObjToDel = 0;

		std::cout << "The contact under which number you want to delete: ";
		std::cin >> numObjToDel;
		numObjToDel -= 1;

		std::cout << std::endl;

		for (size_t i = 0; i < size; i++)
		{
			if (i >= numObjToDel)
			{
				obj[i] = obj[i + 1];
			}
		}
		size -= 1;

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
	PhoneBook* obj = new PhoneBook[10];
	int SIZE = 0;
	//obj->CreatePhoneBook(obj,SIZE);
	//obj->ShowPhoneBook(obj,SIZE);
	//obj->AddContact(obj, SIZE);
	//obj->ShowPhoneBook(obj, SIZE);
	//
	//obj->ShowPhoneBook(obj, SIZE);

	int chooseVar;
	bool correct = true;
	do
	{
		std::cout << "MENU:\n"
			<< "1. Fill the phone book\n"
			<< "2. Show the phone book\n"
			<< "3. Add contact to the phone book\n"
			<< "4. Delete contact from the phone book\n"
			<< "5. Exit\n";
		std::cout << "Choose operation: ";
		std::cin >> chooseVar;
		system("cls");
		if (std::cin.fail() || chooseVar < 1 || chooseVar > 5)
		{
			std::cout << "Wrong input!!! Enter the right variant" << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		switch (chooseVar)
		{
		case 1:
			obj->CreatePhoneBook(obj, SIZE);
			break;
		case 2:
			obj->ShowPhoneBook(obj, SIZE);
			break;
		case 3:
			obj->AddContact(obj, SIZE);
			break;
		case 4:
			obj->DeleteContact(obj, SIZE);
			break;
		case 5:
			correct = false;
			system("exit");
			break;
		}
	} while (correct);
	
	delete[] obj;

	
}