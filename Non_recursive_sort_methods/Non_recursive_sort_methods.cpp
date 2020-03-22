//Created by Diego Ernesto Bahena López - 5B 18100022 
//This program contains the  6 sort methods (Bubble, insertion, selection, shell, quicksort, merge) 

#include <iostream>

using namespace std;


//class sort has the length of the array, a pointer to create dynamic arrays, the  methods to fill a valid array and the sort methods 
class sort {

public:
	int array_length, * position;

	//gets the length of the array (2-20)
	void ask_array();
	//makes a dynamic array with the length of "array_length"
	void create_array();
	//fills the array with the user's data 
	void fill_array();

	//prints the array
	void print_array();

	//sort methods
	void sort_method_bubble();
	void sort_method_insertion();
	void sort_method_selection();
	void sort_method_shell();

	//destruyer
	~sort();
};

//methods of the class

//release the memory used in the dynamic array
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
		cout << "Ingrese el numero de la posicion " << i + 1 << endl;
		cin >> position[i];
	}
}
void sort::print_array() {

	for (int i = 0; i < array_length; i++) {
		cout << position[i] << "\t"<<endl;
	}
	
}

//sort methods//

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
			cout << "\n\n";
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

			cout << "\n\n";
		}

	}
}
void sort:: sort_method_selection() {

	print_array();
	cout << "\n";
	int little_number, counter=0;
	for (int i = 0; i < array_length-1; i++) {

		int little_number = i;
		counter = 0;
		for (int j = i + 1; j < array_length; j++) {		
		
		

			if (position[j] < position[little_number]) {

				little_number = j;
				counter++;
			}
		
	
		}
		int v_aux = position[i];
		position[i] = position[little_number];
		position[little_number] = v_aux;
		if (counter == 0) {
			break;
		}	
	
		print_array();
		cout << "\n";
	}



}
void sort::sort_method_shell() {

	int jump = array_length / 2;

	while (jump > 0) {

		int k = 0;

		for (int i = jump; i < array_length; i++) {
			
			int v_aux = position[i];

			for (k = i; k >= jump && position[k - jump] > v_aux; k -= jump) {

				position[k] = position[k - jump];


			}

			position[k] = v_aux;
				
		}
	
		jump /= 2;

	}








}



int main() {

//infinite loop to always show the menu

	while (1 == 1) {

		int option_menu;
		system("cls");
		cout << "*Por favor, introduzca solo numeros enteros para interactuar con el programa*\nElige el metodo de ordenamiento:\n\n1. Bubble\n2. Insertion\n3. Selection\n4. Shell\n7. Salir\n";
		cin >> option_menu;
		switch (option_menu) {

		//bubble sort
		case 1: {  
			sort b1;
			b1.ask_array();
			b1.create_array();
			b1.fill_array();
			b1.sort_method_bubble();
			system("pause");

		}
			  break;
		//insertion sort
		case 2: {
			sort insert;
			insert.ask_array();
			insert.create_array();
			insert.sort_method_insertion();
			system("pause");

		}
			  break;
		//selection sort
		case 3: {
			sort selection;
			selection.ask_array();
			selection.create_array();
			selection.fill_array();
			selection.sort_method_selection();
			system("pause");
		}

			break;
		case 4: {
			sort shell;
			shell.ask_array();
			shell.create_array();
			shell.fill_array();
			shell.sort_method_shell();
			shell.print_array();
			system("pause");
		}
			  break;
		case 7:
			return 0;
		}
	}
	return 0;
}


