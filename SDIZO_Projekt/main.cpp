#include "pch.h"
#include "main.h"

// menu.cpp : Defines the entry point for the console application.
//

#include<conio.h>
#include<string>
#include <iostream>
#include <filesystem>
#include "../AppLibrary/Table.h"
#include "../AppLibrary/List.h"
using namespace std;


void displayMenu(string info, bool isLoaded)
{
	cout << endl;
	cout << info << endl;
	cout << "1.Wczytaj z pliku" << endl;
	if (isLoaded) {
		cout << "2.Usun" << endl;
		cout << "3.Dodaj" << endl;
		cout << "4.Znajdz" << endl;
		cout << "5.Utworz losowo" << endl;
		cout << "6.Wyswietl" << endl;
		cout << "7.Test (pomiary)" << endl;
	}
	cout << "0.Powrot do menu" << endl;
	cout << "Podaj opcje:";
}

void menu_table()
{
	char opt; //wybrana opcja
	string fileName; //nazwa pliku wpisana przez użytkownika
	int index, value; // index/wartosc wpisana przez użytkownika
	Table myTab = Table(); // deklaracja obiektu
	bool isLoaded = false;

	do {
		try {
			displayMenu("--- TABLICA ---", isLoaded);
			opt = _getche();
			cout << endl;
			switch (opt) {
			case '1': //tutaj wczytytwanie  tablicy z pliku
				cout << " Podaj nazwe zbioru:";
				cin >> fileName;
				cout << fileName;
				myTab.loadFromFile(fileName);
				myTab.display(cout);
				isLoaded = true;
				break;

			case '2': //tutaj usuwanie elemenu z tablicy
				cout << " podaj index:";
				cin >> index;
				myTab.removeElement(index);
				myTab.display(cout);
				break;

			case '3': //tutaj dodawanie elemetu do tablicy
				cout << " podaj index:";
				cin >> index;
				cout << " podaj wartosc:";
				cin >> value;

				myTab.addElement(index, value);
				myTab.display(cout);
				break;

			case '4': //tutaj znajdowanie elemetu w tablicy
				cout << " podaj wartosc:";
				cin >> value;
				if (myTab.findValue(value))
					cout << "podana wartosc jest w tablicy";
				else
					cout << "podanej wartosci NIE ma w tablicy";
				break;

			case '5':  //tutaj generowanie  tablicy
				cout << "Podaj ilosc elementow tablicy:";
				cin >> value;
				myTab.generateRandom(value);
				myTab.display(cout);
				break;

			case '6':  //tutaj wyswietlanie tablicy
				myTab.display(cout);
				break;

			case '7': //tutaj nasza funkcja do eksperyment�w (pomiary czas�w i generowanie daneych) - nie b�dzie testowana przez prowadz�cego 
					  // mo�na sobie tu doda� w�asne case'y
				break;
			}
		}
		catch (const std::exception& e) {
			cout << "Program zwrocil blad: " << e.what() << endl;
		}

	} while (opt != '0');
}

void menu_list()
{
	char opt; //wybrana opcja
	string fileName; //nazwa pliku wpisana przez użytkownika
	int index, value; // index/wartosc wpisana przez użytkownika
	List myTab = List(); // deklaracja obiektu
	bool isLoaded = false;

	do {
		try {
			displayMenu("--- LISTA ---", isLoaded);
			//opt = _getche();
			cin >> opt;
			cout << endl;
			switch (opt) {
			case '1': //tutaj wczytytwanie  tablicy z pliku
				cout << " Podaj nazwe zbioru:";
				cin >> fileName;
				cout << fileName;
				myTab.loadFromFile(fileName);
				myTab.display(cout);
				isLoaded = true;
				break;

			case '2': //tutaj usuwanie elemenu z tablicy
				cout << " podaj wartosc elementu do usunieca:";
				cin >> value;
				myTab.removeElementByValue(value);
				myTab.display(cout);
				break;

			case '3': //tutaj dodawanie elemetu do tablicy
				/*cout << " podaj index:";
				cin >> index;*/
				cout << " podaj wartosc:";
				cin >> value;

				myTab.addElement(value);
				myTab.display(cout);
				break;

			case '4': //tutaj znajdowanie elemetu w tablicy
				cout << " podaj wartosc:";
				cin >> value;
				if (myTab.findValue(value))
					cout << "podana wartosc jest w tablicy";
				else
					cout << "podanej wartosci NIE ma w tablicy";
				break;

			case '5':  //tutaj generowanie  tablicy
				cout << "Podaj ilosc elementow tablicy:";
				cin >> value;
				myTab.generateRandom(value);
				myTab.display(cout);
				break;

			case '6':  //tutaj wyswietlanie tablicy
				myTab.display(cout);
				break;

			case '7': //tutaj nasza funkcja do eksperyment�w (pomiary czas�w i generowanie daneych) - nie b�dzie testowana przez prowadz�cego 
					  // mo�na sobie tu doda� w�asne case'y
				break;
			}
		}
		catch (const std::exception& e) {
			cout << "Program zwrocil blad: " << e.what() << endl;
		}

	} while (opt != '0');
}

void menu_heap()
{
	//analogicznie jak menu_table()
}

int main(int argc, char* argv[])
{

	char option;
	do {
		cout << endl;
		cout << "==== MENU GLOWNE ===" << endl;
		cout << "1.Tablica" << endl;
		cout << "2.Lista" << endl;
		cout << "3.Kopiec" << endl;
		cout << "0.Wyjscie" << endl;
		cout << "Podaj opcje:";
		option = _getche();
		cout << endl;

		switch (option) {
		case '1':
			menu_table();
			break;

		case '2':
			menu_list();
			break;

		case '3':
			menu_heap();
			break;
		}

	} while (option != '0');


	return 0;
}

