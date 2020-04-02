//Created by Diego Ernesto Bahena L�pez - 5B 18100022 
//this program contains the search algorithms (binary & sequential)


#include <iostream>

using namespace std;





class search {

public:
	int array_length, * position;


	void ask_array();

	void create_array();
	
	void fill_array();

	//binary search
    void binary(int *, int , int , int);

	//sequential search
	void sequential_search();
	

	//calls binary search function
	void binary_search();
	
};

//methods of the class

	//gets the length of the array (1-100)  
void search::ask_array() {
	cout << "El programa genera una lista de n�meros ordenados de menor a mayor dependiendo del tama�o que ingrese (Por ejemplo, un tama�o de 20 genera un arreglo del 1 -20)\nDigite el tama�o de la lista de n�meros que se generar�" << endl;
	cin >> array_length;
	if (array_length < 1 || array_length>100) {

		while (array_length < 1 || array_length>100) {

			cout << "Digite una cantidad valida (1-100)" << endl;
			cin >> array_length;
			BOTONISTO OWO
			

		}
	}
}
//makes a dynamic array with the length of "array_length"
void search::create_array() {
	
	position = new int[array_length];
}
// fills the array with sorted numbers from 1 to the position of length array
void search::fill_array() {
	for (int i = 0; i < array_length; i++) {
			
		position[i] = i + 1;
	}
}



//search methods//

//the sequential search check one position by one searching the number given
void search::sequential_search() {
	
	int data;

dkfhiSDHFAOSDFOSDIJFA
	//this boolean is a little upgrade 
	bool found = true;
	cout << "Elige un n�mero a buscar" << endl;
	cin >> data;

	for (int i = 0; i < array_length; i++) {
		found = false;
		if (position[i] == data) {

			cout << "El numero " << data << " esta en la posicion " << i  << endl;
			found = true;
			//if we already found the number,we exit the loop

			if (found == true) {

				i = array_length + 1;
			}
		}
	}

	
	if (found == false) {

		cout << "el numero ingresado no esta en esta lista de numeros" << endl;
	}

}


//The binary search will search the data by halfs, recursevely
void search::binary(int * position, int data, int bottom, int top ) {


	if (data > array_length || data < array_length) {
		cout << "el numero ingresado no esta en esta lista de numeros" << endl;

	}
}

//this method calls the binary function (this is because we can't use global variables to give arguments to a function)
void search::binary_search() {
	int data;
	cout << "Elige un n�mero a buscar" << endl;
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
			  //binary search
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


