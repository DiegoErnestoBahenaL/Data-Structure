//Created by Diego Ernesto Bahena López - 5B 18100022 



#include <iostream>

using namespace std;





class search {

public:
	int array_length, * position;

	//gets the length of the array (2-20)
	void ask_array();
	//makes a dynamic array with the length of "array_length"
	void create_array();
	//fills the array with the user's data 
	void fill_array();
void binary(int *, int , int , int);


	void sequential_search();
	void binary_search();
	
};

//methods of the class


void search::ask_array() {
	cout << "El programa genera una lista de números ordenados de menor a mayor dependiendo del tamaño que ingrese (Por ejemplo, un tamaño de 20 genera un arreglo del 1 -20)\nDigite el tamaño de la lista de números que se generará" << endl;
	cin >> array_length;
	if (array_length < 1 || array_length>100) {

		while (array_length < 1 || array_length>100) {

			cout << "Digite una cantidad valida (1-100)" << endl;
			cin >> array_length;
		}
	}
}
void search::create_array() {
	
	position = new int[array_length];
}
void search::fill_array() {
	for (int i = 0; i < array_length; i++) {
			
		position[i] = i + 1;
	}
}



//search methods//


void search::sequential_search() {
	
	int data;
	bool found = true;
	cout << "Elige un número a buscar" << endl;
	cin >> data;

	for (int i = 0; i < array_length; i++) {
		found = false;
		if (position[i] == data) {

			cout << "El numero " << data << " esta en la posicion " << i  << endl;
			found = true;

			if (found == true) {

				i = array_length + 1;
			}
		}
	}
	if (found == false) {

		cout << "el numero ingresado no esta en esta lista de numeros" << endl;
	}

}

void search::binary(int * position, int data, int bottom, int top ) {

	if (data > array_length || data < array_length) {
		cout << "el numero ingresado no esta en esta lista de numeros" << endl;

	}
	else
	{

		int half = (bottom + top) / 2;
		bool found = false;


		if (data == position[half]) {


			cout << "El numero " << data << " esta en la posicion " << half << endl;


		}
		else
		{
			if (position[half] < data) {
				binary(position, data, half, top);
			}
			if (position[half] > data) {
				binary(position, data, bottom, half);
			}
		}


	}
}


void search::binary_search() {
	int data;
	cout << "Elige un número a buscar" << endl;
	cin >> data;
	binary(position, data, 0, array_length);
}

int main() {
	


	//infinite loop to always show the menu

	while (1 == 1) {

		int option_menu;
		system("cls");
		cout << "*Por favor, introduzca solo numeros enteros para interactuar con el programa*\nElige el tipo de busqueda a realizar:\n\n1. Secuencial\n2. Binaria\n3. Salir\n";
		cin >> option_menu;
		switch (option_menu) {

			//sequential search
		case 1: {

			search seq;
			seq.ask_array();
			seq.create_array();
			seq.fill_array();
			seq.sequential_search();
			system("pause");

		}
			  break;
			  //insertion sort
		case 2: {

			search bin;
			bin.ask_array();
			bin.create_array();
			bin.fill_array();
			bin.binary_search();		
			system("pause");

		}
			  break;
			  //selection sort
		

		case 3:
			return 0;
		}
	}
	return 0;
}


