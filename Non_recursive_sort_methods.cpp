//Created by Diego Ernesto Bahena López - 5B 18100022 
//This program contains the first 3 sort methods (Bubble, insertion & selection) 

#include <iostream>

using namespace std;



class sort {

public:
	int array_length, * position;
	void ask_array();
	void create_array();
	void fill_array();
	void sort_method_bubble();
	void sort_method_insertion();
	void sort_method_selection();
	void print_array();
	~sort();
};

sort::~sort() {

	delete[] position;
}

void sort::ask_array() {
	cout << "Digite cuantos numeros se ordenaran" << endl;
	cin >> array_length;
	if (array_length < 2 || array_length>20) {

		while (array_length < 2 || array_length>20) {

			cout << "Digite una cantidad valida (2-20)" << endl;
			cin >> array_length;
		}
	}
}
void sort::create_array() {
	cout << "Ingrese los numeros a ordenar" << endl;
	position = new int[array_length];
}
void sort::fill_array() {
	for (int i = 0; i < array_length; i++) {
		cin >> position[i];
	}
}
void sort::print_array() {

	for (int i = 0; i < array_length; i++) {
		cout << position[i] << "\t";
	}

}
void sort::sort_method_bubble() {
	print_array();
	cout << "\n";
	while (1 == 1) {

		int counter = 0;
		for (int i = 0; i < array_length - 1; i++) {

			int number_compare = position[i];
			if (number_compare > position[i + 1]) {

				int num_x = position[i + 1];
				position[i + 1] = number_compare;
				position[i] = num_x;
				counter++;
			}
		}
		if (counter > 0) {

			print_array();
			cout << "\n";
		}
		else
		{
			break;
		}
	}
}

void sort::sort_method_insertion() {

	int actual_number, place, k = 0;

	for (k; k < array_length; k++) {
		cin >> actual_number;
		position[k] = actual_number;
		place = k;

		if (k == 0) {

			position[k] = actual_number;
			for (int i = 0; i < array_length; i++)
			{
				cout << position[i] << "\t";
				if (i == k) {
					break;
				}
			}
			cout << "\n";
		}
		else {

			while (place > 0 && position[place - 1] > actual_number) {

				position[place] = position[place - 1];
				place--;
			}

			position[place] = actual_number;

			for (int i = 0; i < array_length; i++)
			{
				cout << position[i] << "\t";
				if (i == k) {
					break;
				}
			}

			cout << "\n";
		}

	}
}


/////////////////////////////////
// Functions





int main() {

	

	while (1 == 1) {

		int option_menu;
		system("cls");
		cout << "Elige el metodo de ordenamiento:\n\n1. Bubble\n2. Insertion\n3. Selection\n4. Salir\n";
		cin >> option_menu;
		switch (option_menu) {


		case 1: {
			sort b1;
			b1.ask_array();
			b1.create_array();
			b1.fill_array();
			b1.sort_method_bubble();
			system("pause");
			
		}
			  break;
		case 2: {
			sort insert;
			insert.ask_array();
			insert.create_array();
			insert.sort_method_insertion();
			system("pause");
		
		}
			  break;

			  cout << "Not ready yet";
			  system("pause");
			  break;
		case 3:
			cout << "not ready yet";
			system("pause");
			break;
		case 4:
			return 0;
		}
	}
	return 0;
}


