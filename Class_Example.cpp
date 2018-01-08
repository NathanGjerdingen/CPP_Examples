// Chapter 13, Programming Challenge 6: Inventory Class
// By Nathan Gjerdingen

#include <iostream>
using namespace std;

class Inventory {

private:

	//Initialize needed variables...
	int itemNumber, quantity;
	double cost, totalCost;

public:

	//Constructors for class...
	Inventory() {
		itemNumber = 0;
		cost = 0;
		quantity = 0;
		setTotalCost();
	}

	Inventory(int num, double price, int quant) {
		itemNumber = num;
		cost = price;
		quantity = quant;
		setTotalCost();
	}

	//Accessors and Mutators for class...
	void setItemNumber(int in) {
		itemNumber = in;
	}

	void setQuantity(int q) {
		quantity = q;
	}

	void setCost(double c) {
		cost = c;
	}

	void setTotalCost() {
		totalCost = quantity * cost;
	}

	int getItemNumber() {
		return itemNumber;
	}

	double getQuantity() {
		return quantity;
	}

	double getCost() {
		return cost;
	}

	double getTotalCost() {
		return totalCost;
	}
};

int main()
{
	// Define an Inventory object and use the default constructor.
	Inventory inv;

	// Display the member values.
	cout << "We have defined an object using the default constructor\n";
	cout << "Here are the values of the members:\n";
	cout << "Item number: " << inv.getItemNumber() << endl;
	cout << "Quantity: " << inv.getQuantity() << endl;
	cout << "Cost: " << inv.getCost() << endl;
	cout << "Total cost: " << inv.getTotalCost() << endl << endl;

	// Define an Inventory object and use the overloaded constructor.
	Inventory inv2(777, 10, 12.50);

	// Display the member values.
	cout << "We have defined an object using the overloaded constructor\n";
	cout << "Here are the values of the members:\n";
	cout << "Item number: " << inv2.getItemNumber() << endl;
	cout << "Quantity: " << inv2.getQuantity() << endl;
	cout << "Cost: " << inv2.getCost() << endl;
	cout << "Total cost: " << inv2.getTotalCost() << endl << endl;

	// Use the mutator functions to change the member values.
	inv2.setItemNumber(555);
	inv2.setQuantity(20);
	inv2.setCost(19.95);
	inv2.setTotalCost();

	// Display the modified values.
	cout << "We have changed the values.\n";
	cout << "Here are the new values of the members:\n";
	cout << "Item number: " << inv2.getItemNumber() << endl;
	cout << "Quantity: " << inv2.getQuantity() << endl;
	cout << "Cost: " << inv2.getCost() << endl;
	cout << "Total cost: " << inv2.getTotalCost() << endl << endl;

	return 0;
}
