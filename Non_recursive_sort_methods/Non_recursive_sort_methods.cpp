//Created by Diego Ernesto Bahena López - 5B 18100022 
//This program contains the sort methods (Bubble, insertion, selection, shell) 

//*quick sort & merge sort were not ready

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
	void sort_method_quicksort();

	//destroyer
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
		cout << position[i] << "\t";
	}
	
}

//sort methods//



//bubble sort: we compare two items in the array and swap them if they're not sorted untill array is sorted
void sort::sort_method_bubble() {
	print_array();
	cout << "\n";


	//infinite loop because we don't know how many iterations will be in this method
	while (1 == 1) {


		//counter is the marker
		int counter = 0;
		for (int i = 0; i < array_length - 1; i++) {

			int number_compare = position[i];
			if (number_compare > position[i + 1]) {



				//here we swap if the numbers aren't sorted
				int num_x = position[i + 1];
				position[i + 1] = number_compare;
				position[i] = num_x;

				//the marker will change if we change numbers in the array
				counter++;
			}
		}

		//if there's no changes we exit the loop because the array is sorted
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

//insertion sort: we put numbers in the array and they will be sorted in real time
void sort::sort_method_insertion() {

	int actual_number, place, k = 0;

	for (k; k < array_length; k++) {
		cout << "Ingrese el numero de la posicion " << k + 1 << endl;
		cin >> actual_number;
		position[k] = actual_number;
		place = k;

		//the 0 position will always be our initially sorted element
		if (k == 0) {

			//the numbers introduced by the user will be saved in the aux variable
			position[k] = actual_number;

			//here we are printing only the necesary elements (the introduced)

			for (int i = 0; i < array_length; i++)
			{
				cout << position[i] << "\t";
				if (i == k) {
					break;
				}
			}
			cout << "\n\n";
		}

		//for the positions after 0 in the array we will swap the numbers to their position looking in the previous numbers (going back)
		else {


			while (place > 0 && position[place - 1] > actual_number) {

				position[place] = position[place - 1];
				place--;
			}

			position[place] = actual_number;

			//here we are printing only the necesary elements (the introduced)
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
//selection sort: basically we are searching for the smallest number in the entire array, then the second one, untill the array is sorted
void sort:: sort_method_selection() {

	print_array();
	cout << "\n";
	int little_number, counter=0;
	for (int i = 0; i < array_length-1; i++) {

		//we take the position 0 as the "smallest" because in a 1 element array the position 0 is already sorted
		int little_number = i;
		counter = 0;
		
		for (int j = i + 1; j < array_length; j++) {		
		
		
			//we are comparing all the elements to find the smallest
			if (position[j] < position[little_number]) {

				little_number = j;
				counter++;
			}
		
	
		}
		//the swap with aux variable
		int v_aux = position[i];
		position[i] = position[little_number];
		position[little_number] = v_aux;
		//we exit if the array is sorted
		if (counter == 0) {
			break;
		}	
	
		print_array();
		cout << "\n";
	}



}

//shell sort: A variation more efficient of insertion sort

void sort::sort_method_shell() {
	
	//we evaluate positions in the array by "jumps" of separation based in the array length
	int jump = array_length / 2;
	
	//we need at least 1 "jump" of distance (0 means compare the position with the same position)
	while (jump > 0) {

		int k = 0;


		for (int i = jump; i < array_length; i++) {
			

			//we give the value of the position in the array to an aux variable
			int v_aux = position[i];
			
			//if the number in the correspondet "jump" is bigger, they will be swaped and move along in the array doing the same
			for (k = i; k >= jump && position[k - jump] > v_aux; k -= jump) {

				position[k] = position[k - jump];
			}
			
			//doesn't matter if the number ins't bigger, it will be swaped with itself
			position[k] = v_aux;
				
		}
	//reducing the space of the jumps
		jump /= 2;

	}








}





int main() {

//infinite loop to always show the menu

	while (1 == 1) {

		int option_menu;
		system("cls");
		cout << "*Por favor, introduzca solo numeros enteros para interactuar con el programa*\nElige el metodo de ordenamiento:\n\n1. Bubble\n2. Insertion\n3. Selection\n4. Salir\n";
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
		//shell sort
		case 4: {
			sort shell;
			shell.ask_array();
			shell.create_array();
			shell.fill_array();
			shell.sort_method_shell();
			shell.print_array();
			cout << "\n";
			system("pause");
		}
			  break;
		//Quicksort
		
		
		case 5:
			return 0;
		}
	}
	return 0;
}


