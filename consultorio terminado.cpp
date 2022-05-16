#include <iostream>
#include <locale.h>
#include <locale>
#include <conio.h>
#include <string.h>
#include <string>
#include <stdbool.h>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <cstdlib> 
#include <ctime>

using namespace std;

struct cita {
	int cita;
int ctra;
	int pu;
int stotal;
	int iva;
int total;
	int hor;
string texto;
	string datos;
string nom;
	string ntra;
string desc;
};

void main() {

	setlocale(LC_CTYPE, "");

	cita Acita[99];
	int op, n;
	int j, z;
	int i = 0;
	ofstream myfile("cita.txt", ios::out);
	bool continuar;
	bool validar = false;
	int cont = 0;


	do {
		system("cls");
		cout << "[Bienvenidos a DoctorChark] " << endl;
	cout << "¿Que desea hacer?" << endl;
		cout << "1.Agendar cita" << endl;
	cout << "2.Modificar cita" << endl;
		cout << "3.Eliminar cita" << endl;
	cout << "4.Lista de citas vigentes" << endl;
		cout << "5.Limpiar pantalla" << endl;
	cout << "6.Salir" << endl;
		cout << "\nIngrese un numero: " << endl;
	cin >> op;
		switch (op) {
		case 1:
			cout << "¿Desea agendar cita? (Si=1 No=2) " << endl;
			cin >> op;
			system("cls");
			while (op == 1) {
				do {
					Acita[i].cita = i + 1;
					cout << "ID de paciente: " << Acita[i].cita << endl;
					do {
						validar = false;
						cout << "Nombre del Paciente: \n";
						cin.ignore();
						getline(cin, Acita[i].nom);
						for (z = 0; z < Acita[i].nom.length(); z++) {
							if (!isalpha(Acita[i].nom.at(z)) && !isspace(Acita[i].nom.at(z)))
							{
								z = Acita[i].nom.length() + 1;
								validar = true;
							}
						}
						if (validar == true) {
							cout << "Ingrese correctamente el nombre del paciente\n";
						}
					} while (validar == true);

					do {
						continuar = false;
						cin.clear();
						if (cont > 0) cin.ignore(1024, '\n');
						cout << "Hora del tratamiento (solo en formato 24hrs): " << endl;
						cin >> Acita[i].hor;
						cont++;
						if (cin.fail() && cin.rdstate()) {
							cout << "NO ES UN NUMERO" << endl;
							continuar = true;
						}
					} while (continuar);

					do {
						validar = false;
						cout << "Nombre del tratamient: \n";
						cin.ignore();
						getline(cin, Acita[i].ntra);
						for (z = 0; z < Acita[i].ntra.length(); z++) {
							if (!isalpha(Acita[i].ntra.at(z)) && !isspace(Acita[i].ntra.at(z)))
							{
								z = Acita[i].ntra.length() + 1;
								validar = true;
							}

						}
						if (validar == true) {
							cout << "Ingrese correctamente el nombre del tratamiento\n";
						}
					} while (validar == true);

					do {
						validar = false;
						cout << "Descripcion: \n";
						cin.ignore();
						getline(cin, Acita[i].desc);
						for (z = 0; z < Acita[i].desc.length(); z++) {
							if (!isalpha(Acita[i].desc.at(z)) && !isspace(Acita[i].desc.at(z)))
							{
								z = Acita[i].desc.length() + 1;
								validar = true;
							}

						}
						if (validar == true) {
							cout << "Ingrese correctamente una descripcion\n";
						}
					} while (validar == true);

					do {
						continuar = false;
						cin.clear();
						if (cont > 0) cin.ignore(1024, '\n');
						cout << "Cantidad del tratamiento: " << endl;
						cin >> Acita[i].ctra;
						cont++;
						if (cin.fail() && cin.rdstate()) {
							cout << "NO ES UN NUMERO" << endl;
							continuar = true;
						}
					} while (continuar);

					do {
						continuar = false;
						cin.clear();
						if (cont > 0) cin.ignore(1024, '\n');
						cout << "Precio Unitario: " << endl;
						cin >> Acita[i].pu;
						cont++;
						if (cin.fail() && cin.rdstate()) {
							cout << "NO ES UN NUMERO" << endl;
							continuar = true;
						}
					} while (continuar);
					Acita[i].stotal = Acita[i].ctra * Acita[i].pu;
					Acita[i].iva = Acita[i].stotal * .16;
					Acita[i].total = Acita[i].stotal + Acita[i].iva;
					cout << "\nNombre del paciente: " << Acita[i].nom << "\nHora del tratamiento (en formato 24hrs): " << Acita[i].hor << "\nNombre del tratamient: " << Acita[i].ntra << "\nDescripcion: " << Acita[i].desc << "\nCantidad del tratamiento: " << Acita[i].ctra << "\nPrecio Unitario: " << Acita[i].pu << "\n\nTotal: " << Acita[i].total << endl << endl;
					system("pause>nul");
					system("cls");
					cout << "¿Desea agregar otra cita? (Si=1 No=2) " << endl;
					cin >> op;
					i++;
					system("pause>nul");
				} while (op == 1);
				op = 0;
			}
			break;
		case 2:

			cout << "¿Desea modificar cita vigente? Si=1 No=2 " << endl;
			cin >> op;
			system("cls");
			while (op == 1) {
				cout << "ingrese la cita a modificar \n";
				cin >> j;

				if (j > i || j <= 0 || Acita[i].cita == 0) {
					cout << "\nID inexistente\n";
					break;
				}

				j = j - 1;

				for (i = j; i == j; i++) {

					cout << "ID de paciente: " << Acita[i].cita << endl;

					do {
						validar = false;
						cout << "Nombre del Paciente: \n";
						cin.ignore();
						getline(cin, Acita[i].nom);
						for (z = 0; z < Acita[i].nom.length(); z++) {
							if (!isalpha(Acita[i].nom.at(z)) && !isspace(Acita[i].nom.at(z)))
							{
								z = Acita[i].nom.length() + 1;
								validar = true;
							}

						}
						if (validar == true) {
							cout << "ingrese el nombre correcto\n";
						}
					} while (validar == true);

					do {
						continuar = false;
						cin.clear();
						if (cont > 0) cin.ignore(1024, '\n');
						cout << "Hora del tratamiento (solo en formato 24hrs): " << endl;
						cin >> Acita[i].hor;
						cont++;
						if (cin.fail() && cin.rdstate()) {
							cout << "ingrese la hora en formato de 24 horas correctamente" << endl;
							continuar = true;
						}
					} while (continuar);

					do {
						validar = false;
						cout << "Nombre del tratamiento: \n";
						cin.ignore();
						getline(cin, Acita[i].ntra);
						for (z = 0; z < Acita[i].ntra.length(); z++) {
							if (!isalpha(Acita[i].ntra.at(z)) && !isspace(Acita[i].ntra.at(z)))
							{
								z = Acita[i].ntra.length() + 1;
								validar = true;
							}

						}
						if (validar == true) {
							cout << "ese no es un tratamiento \n";
						}
					} while (validar == true);

					do {
						validar = false;
						cout << "Descripcion: \n";
						cin.ignore();
						getline(cin, Acita[i].desc);
						for (z = 0; z < Acita[i].desc.length(); z++) {
							if (!isalpha(Acita[i].desc.at(z)) && !isspace(Acita[i].desc.at(z)))
							{
								z = Acita[i].desc.length() + 1;
								validar = true;
							}
						}
						if (validar == true) {
							cout << "Ingrese correctamente una descripcion\n";
						}
					} while (validar == true);
					do {
						continuar = false;
						cin.clear();
						if (cont > 0) cin.ignore(1024, '\n');
						cout << "Cantidad del tratamiento: " << endl;
						cin >> Acita[i].ctra;
						cont++;
						if (cin.fail() && cin.rdstate()) {
							cout << "Ingrese un numero porfavor" << endl;
							continuar = true;
						}
					} while (continuar);
					do {
						continuar = false;
						cin.clear();
						if (cont > 0) cin.ignore(1024, '\n');
						cout << "Precio Unitario: " << endl;
						cin >> Acita[i].pu;
						cont++;
						if (cin.fail() && cin.rdstate()) {
							cout << "NO ES UN NUMERO" << endl;
							continuar = true;
						}
					} while (continuar);

					Acita[i].stotal = Acita[i].ctra * Acita[i].pu;
					Acita[i].iva = Acita[i].stotal * .16;
					Acita[i].total = Acita[i].stotal + Acita[i].iva;
					cout << "\nNombre del paciente: " << Acita[i].nom << "\nHora del tratamiento formato 24hrs: " << Acita[i].hor << "\nNombre del tratamiento: " << Acita[i].ntra << "\nDescripcion: " << Acita[i].desc << "\nCantidad del tratamiento: " << Acita[i].ctra << "\nPrecio Unitario: " << Acita[i].pu << "\n\nTotal: " << Acita[i].total << endl << endl;
				}
				op = 0;

			}
			break;

		case 3:
			cout << "Desea eliminar cita? Si=1 No=2 " << endl;
			cin >> op;

			system("cls");

			while (op == 1) {

				cout << "ingresa el registro a eliminar: " << endl;
				cin >> j;
				j = j - 1;
				for (int i = j; i == j; i++)
				{
					cout << "Eliminando registro: " << j + 1 << endl;
					Acita[i].cita = 0;
				Acita[i].nom = " ";
					Acita[i].hor = 0;
				Acita[i].ntra = " ";
					Acita[i].desc = " ";
				Acita[i].ctra = 0;
					Acita[i].pu = 0;
				Acita[i].total = 0;
					cout << "\n Su cita fue eliminada correctamente\n";
				}
				op = 0;
			}
			break;

		case 4:
			cout << "quiere ver las cita vigentes? Si=1 No=2 " << endl;
			cin >> op;
			system("cls");
			while (op == 1) {
				for (int k = 0; k < i; k++) 
				cout << "ID de cita: " << Acita[k].cita << endl;
					cout << "\nNombre del paciente: " << Acita[k].nom;
				cout << "\nHora del tratamiento (en formato 24hrs): " << Acita[k].hor;
					cout << "\nNombre del tratamient: " << Acita[k].ntra;
				cout << "\nDescripcion: " << Acita[k].desc;
					cout << "\nCantidad del tratamiento: " << Acita[k].ctra;
				cout << "\nPrecio Unitario: " << Acita[k].pu;
					cout << "\nTotal: " << Acita[k].total;
				cout << "\n\nSubtotal: " << Acita[k].stotal;
					cout << "\nIVA: " << Acita[k].iva;
				cout << "\nTotal: " << Acita[k].total << endl << endl;
				}
				op = 0;

				system("pause>nul");
				system("cls");
			}
			break;

		case 5:
			system("cls");
			op = 0;
			break;

		case 6:
			system("cls");
			cout << "Guardando espere porfavor" << endl;
			if (myfile.is_open()) {
				for (int k = 0; k < i; k++) {
					cout << "ID de cita: " << Acita[k].cita << endl;
				cout << "\nNombre del paciente: " << Acita[k].nom;
					cout << "\nHora del tratamiento ingreselo en formato de 24hrs: " << Acita[k].hor;
				cout << "\nNombre del tratamiento: " << Acita[k].ntra;
					cout << "\nDescripcion: " << Acita[k].desc;
				cout << "\nCantidad del tratamiento: " << Acita[k].ctra;
					cout << "\nPrecio Unitario: " << Acita[k].pu;
				cout << "\nTotal: " << Acita[k].total;
					cout << "\n\nSubtotal: " << Acita[k].stotal;
				cout << "\niva: " << Acita[k].iva;
					cout << "\nTotal: " << Acita[k].total << endl << endl;;
				}
			}
			myfile.close();
			system("pause");
			exit(0);

			break;

		default:
			cout << "\nno es valido \n\n";

		}
		system("pause>nul");
		system("cls");
		cout << "quieres volver al menu? Si=1 No=2\n";
		cin >> op;

	} while (op == 1);

}