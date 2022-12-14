// finalprojectCSC2110.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "stdafx.h"

#include <iostream>

#include <string>

#include <vector>

#include <cstdlib>

#include <fstream>

using namespace std;

// car class

class Car

{

protected:

	// Declare the private member variables.

	string VIN;

	string Make;

	string Model;

	int year;

	float price;

	string category;

public:

	// declare the public variables.

	Car()

	{

		VIN = "";

		Make = "";

		Model = "";

		category = "";

		year = 0;

		price = 0;

	}

	// constructor.

	Car(string myVIN, string myMake, string myModel, int myyear, float myprice, string mycategory)

	{

		VIN = myVIN;

		Make = myMake;

		Model = myModel;

		year = myyear;

		price = myprice;

		category = mycategory;

	}

	// Craete the getter for the private member variables.

	string getVIN()

	{

		return VIN;

	}

	string getMake()

	{

		return Make;

	}

	string getModel()

	{

		return Model;

	}

	string getCategory()

	{

		return category;

	}

	int getYear()

	{

		return year;

	}

	float getPrice()

	{

		return price;

	}

	// fucntion to display the car details.

	virtual void display()

	{

		cout << endl << endl;

		cout << "VIN:" << VIN << endl;

		cout << "Make:" << Make << endl;

		cout << "Model:" << Model << endl;

		cout << "year:" << year << endl;

		cout << "price:" << price << endl;

		cout << "category:" << category << endl;

	}

};

// Create the class NewCar and inherit the Car class.

class NewCar :public Car

{

	string warranty;

public:

	// define the public variables.

	NewCar() :Car()

	{

		warranty = "";

	}

	// constructor.

	NewCar(string myVINcar, string myMakecar, string myModelcar, int myyear_car, float myprice_car, string mycategory_car, string mywarranty) :

		Car(myVINcar, myMakecar, myModelcar, myyear_car, myprice_car, mycategory_car)

	{

		warranty = mywarranty;

	}

	string getWarranty()

	{

		return warranty;

	}

	void display()

	{

		Car::display();

		cout << "Provider process:" << warranty << endl;

		cout << endl;

	}

};

// Create the class OldCar and inherit the Car class.

class OldCar :public Car

{

	int mileage;

public:

	OldCar() :Car()

	{

		mileage = 0;

	}

	// constuctor.

	OldCar(string myVINcar, string myMakecar, string myModelcar, int myyear_car, float myprice_car, string mycategory_car, int mymileage) :

		Car(myVINcar, myMakecar, myModelcar, myyear_car, myprice_car, mycategory_car)

	{

		mileage = mymileage;

	}

	int getmileage()

	{

		return mileage;

	}

	void display()

	{

		Car::display();

		cout << "mileage: " << mileage << endl;

		cout << endl;

	}

};

// Function to find the car using the VIN

bool CarByVIN(string VINcar, vector<Car*>& list)

{

	bool gr = false;

	for (int jj = 0; jj < list.size(); jj++)

		if ((*list[jj]).getVIN() == VINcar)

			gr = true;

	return gr;

}

// Function to find the car using the Make

bool CarByMake(string Makecar, vector<Car*>& list)

{

	bool gr = false;

	for (int jj = 0; jj < list.size(); jj++)

		if ((*list[jj]).getMake() == Makecar)

		{

			gr = true;

			(*list[jj]).display();

		}

	return gr;

}

// Function to find the car using the model

bool CarByModel(string Modelcar, vector<Car*>& list)

{

	bool gr = false;

	for (int jj = 0; jj < list.size(); jj++)

		if ((*list[jj]).getModel() == Modelcar)

		{

			gr = true;

			(*list[jj]).display();

		}

	return gr;

}

// Function to find the car using the category

bool CarBycategory(string category_car, vector<Car*>& list)

{

	bool gr = false;

	for (int jj = 0; jj < list.size(); jj++)

		if ((*list[jj]).getCategory() == category_car)

		{

			gr = true;

			(*list[jj]).display();

		}

	return gr;

}

// manu of the search options.

void Menu()

{

	cout << "Menu" << endl;

	cout << "1. Search Inventory" << endl;

	cout << "2. Sell/Lease cars" << endl;

	cout << "3. Return a leased car" << endl;

	cout << "4. Add cars to inventory" << endl;

	cout << "5. Exit" << endl;

	cout << endl;

}

//main function

int main()

{

	// create an object of the file class

	ifstream file("file.txt");

	// declare the local variables.

	string VIN;

	string Make;

	string Model;

	int year;

	float price;

	string category;

	string warranty;

	int mileage;

	// Create the 2 vectors.

	vector<Car*> CarList;

	vector<Car*> leaselist;

	int choice1;

	int choice;

	//check condition and load file

	if (file.is_open())

	{

		while (file >> VIN >> Make >> Model >> year >> price >> category)

		{

			if (category == "new")

			{

				file >> warranty;

				int gr = CarByVIN(VIN, CarList);

				if (gr == 0)

					CarList.push_back(new NewCar(VIN, Make, Model, year, price, category, warranty));

				else

					cout << "Car exist" << endl;

			}

			else if (category == "old")

			{

				file >> mileage;

				int gr = CarByVIN(VIN, CarList);

				if (gr == 0)

					CarList.push_back(new OldCar(VIN, Make, Model, year, price, category, mileage));

				else

					cout << "Car exists" << endl;

			}

		}

		file.close();

	}

	// Use while loop to ask the user about the available options.

	while (1)

	{

		Menu();

		cout << "Enter ur choice:";

		cin >> choice1;

		// Use the switch case for different options.

		switch (choice1)

		{

		case 1:

		{

			cout << "Select \n 1. Search By Make.\n 2. Search by Model \n 3. Search By category" << endl;

			cout << "enter the choice:";

			cin >> choice;

			if (choice == 1)

			{

				cout << "Enter Makecar:";

				cin >> Make;

				bool gr = CarByMake(Make, CarList);

				if (gr == false)

					cout << "Car Not Found" << endl;

			}

			else if (choice == 2)

			{

				cout << "Enter Modelcar:";

				cin >> Model;

				bool gr = CarByModel(Model, CarList);

				if (gr == false)

					cout << "Car Not Found" << endl;

			}

			else if (choice == 3)

			{

				cout << "Enter category:";

				cin >> category;

				bool gr = CarBycategory(category, CarList);

				if (gr == false)

					cout << "Car Not Found" << endl;

			}

		}

		break;

		case 2:

		{

			choice = 0;

			cout << "Select \n 1. Sell\n 2. Lease" << endl;

			cout << "enter the choice:";

			cin >> choice;

			cout << "Enter VINcar:";

			cin >> VIN;

			bool pvalue = CarByVIN(VIN, CarList);

			if (pvalue == 0)

				cout << "Car Not Found" << endl;

			else

			{

				if (choice == 1)

				{

					for (int jj = 0; jj < CarList.size(); jj++)

						if ((*CarList[jj]).getVIN() == VIN)

						{

							CarList.erase(CarList.begin() + jj);

							cout << "Car sold successfully." << endl;

							cout << "Inventory" << endl;

							for (int jj = 0; jj < CarList.size(); jj++)

								(*CarList[jj]).display();

							break;

						}

				}

				else if (choice == 2)

				{

					for (int jj = 0; jj < CarList.size(); jj++)

						if ((*CarList[jj]).getVIN() == VIN)

						{

							leaselist.push_back(CarList[jj]);

							CarList.erase(CarList.begin() + jj);

							cout << "Car Leased successfully." << endl;

							cout << "Inventory" << endl;

							for (int jj = 0; jj < CarList.size(); jj++)

								(*CarList[jj]).display();

							break;

						}

				}

			}

		}

		break;

		case 3:

		{

			cout << "Enter VIN:";

			cin >> VIN;

			bool pvalue = CarByVIN(VIN, leaselist);

			if (pvalue == false)

				cout << "Car not Found" << endl;

			else

			{

				for (int jj = 0; jj < leaselist.size(); jj++)

					if ((*leaselist[jj]).getVIN() == VIN)

					{

						CarList.push_back(leaselist[jj]);

						leaselist.erase(leaselist.begin() + jj);

						cout << "Car returned to inventory" << endl;

						cout << "Inventory" << endl;

						for (int jj = 0; jj < CarList.size(); jj++)

							(*CarList[jj]).display();

						break;

					}

			}

		}

		break;

		case 4:

		{

			cout << "Enter VINcar:";

			cin >> VIN;

			cout << "Enter Makecar:";

			cin >> Make;

			cout << "Enter Modelcar:";

			cin >> Model;

			cout << "Enter year_car:";

			cin >> year;

			cout << "Enter price_car:";

			cin >> price;

			cout << "Enter category_car:";

			cin >> category;

			if (category == "new")

			{

				cout << "Enter warranty provider:";

				cin >> warranty;

				int gr = CarByVIN(VIN, CarList);

				if (gr == 0)

					CarList.push_back(new NewCar(VIN, Make, Model, year, price, category, warranty));

				else

					cout << "Car exists" << endl;

			}

			else if (category == "old")

			{

				cout << "Enter mileage:";

				cin >> mileage;

				int gr = CarByVIN(VIN, CarList);

				if (gr == 0)

					CarList.push_back(new OldCar(VIN, Make, Model, year, price, category, mileage));

				else

					cout << "Car exists" << endl;

			}

			cout << "Inventory" << endl;

			for (int jj = 0; jj < CarList.size(); jj++)

				(*CarList[jj]).display();

		}

		break;

		case 5:

			exit(0);

		default:

			cout << "Invalid choice" << endl;

		}

	}

	system("pause");

	return 0;

}