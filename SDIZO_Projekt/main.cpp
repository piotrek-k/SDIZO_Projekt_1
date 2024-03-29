﻿#include "pch.h"
#include "main.h"

// menu.cpp : Defines the entry point for the console application.
//

#include<conio.h>
#include<string>
#include <iostream>
#include <filesystem>
#include "timeCounter.h"
#include "../AppLibrary/Table.h"
#include "../AppLibrary/List.h"
#include "../AppLibrary/Heap.h"
#include "../AppLibrary/RBTree.h"
#include "BinaryTreeDisplay.h"
using namespace std;

timeCounter tC = timeCounter();
BinaryTreeDisplay btd = BinaryTreeDisplay();

void displayMenu(string info, bool isLoaded)
{
	cout << endl;
	cout << info << endl;
	cout << "1.Wczytaj z pliku" << endl;
	//if (isLoaded) {
	cout << "2.Usun" << endl;
	cout << "3.Dodaj" << endl;
	cout << "4.Znajdz" << endl;
	cout << "5.Utworz losowo" << endl;
	cout << "6.Wyswietl" << endl;
	//}
	cout << "0.Powrot do menu" << endl;
	cout << "Podaj opcje:";
}

// cin działa w nieprzewidywalny sposób jeśli podamy
// wartość złego typu na strumień wejściowy
// funkcja eliminuje ten problem
void clearCinAfterError() {
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cin.sync();
}

// funkcja sprawdza czy dane wejściowe są w porządku
// jeśli nie, wyrzuca wyjątek
void validateCin() {
	if (cin.fail()) {
		throw exception("Podana wartosc nieprawidlowa");
	}
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
			//opt = _getche();
			cin >> opt;
			cout << endl;
			switch (opt) {
			case '1': //tutaj wczytytwanie  tablicy z pliku
				cout << " Podaj nazwe zbioru:";
				cin >> fileName;
				myTab.loadFromFile(fileName);
				myTab.display(cout);
				isLoaded = true;
				break;

			case '2': //tutaj usuwanie elemenu z tablicy
				cout << " podaj index:";
				cin >> index;
				validateCin();
				myTab.removeElement(index);
				myTab.display(cout);
				break;

			case '3': //tutaj dodawanie elemetu do tablicy
				cout << " podaj index:";
				cin >> index;
				cout << " podaj wartosc:";
				cin >> value;

				validateCin();
				myTab.addElement(index, value);
				myTab.display(cout);

				break;

			case '4': //tutaj znajdowanie elemetu w tablicy
				cout << " podaj wartosc:";
				cin >> value;
				validateCin();
				if (myTab.findValue(value))
					cout << "podana wartosc jest w tablicy";
				else
					cout << "podanej wartosci NIE ma w tablicy";
				break;

			case '5':  //tutaj generowanie  tablicy
				cout << "Podaj ilosc elementow tablicy:";
				cin >> value;
				validateCin();
				myTab.generateRandom(value, 10);
				myTab.display(cout);
				break;

			case '6':  //tutaj wyswietlanie tablicy
				myTab.display(cout);
				break;

			case '7': //tutaj nasza funkcja do eksperyment�w (pomiary czas�w i generowanie daneych) - nie b�dzie testowana przez prowadz�cego 
					  // mo�na sobie tu doda� w�asne case'y
				//tC.Start(200, 10, 50, 100, cout);
				break;
			}
		}
		catch (const std::exception & e) {
			cout << "program zwrocil blad: " << e.what() << endl;
			clearCinAfterError();
		}
		clearCinAfterError();
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
			case '1': //tutaj wczytytwanie  listy z pliku
				cout << " Podaj nazwe zbioru:";
				cin >> fileName;
				myTab.loadFromFile(fileName);
				myTab.display(cout);
				isLoaded = true;
				break;

			case '2': //tutaj usuwanie elemenu z listy
				cout << " podaj wartosc elementu do usunieca:";
				cin >> value;
				validateCin();
				myTab.removeElementByValue(value);
				myTab.display(cout);
				break;

			case '3': //tutaj dodawanie elemetu do listy
				cout << " podaj index:";
				cin >> index;
				cout << " podaj wartosc:";
				cin >> value;
				validateCin();
				myTab.addElementAtIndex(index, value);
				//myTab.addElementAsFirst(value);
				myTab.display(cout);

				break;

			case '4': //tutaj znajdowanie elemetu w listy
				cout << " podaj wartosc:";
				cin >> value;
				validateCin();
				if (myTab.findValue(value))
					cout << "podana wartosc jest w liscie";
				else
					cout << "podanej wartosci NIE ma w liscie";
				break;

			case '5':  //tutaj generowanie  tablicy
				cout << "Podaj ilosc elementow listy:";
				cin >> value;
				validateCin();
				myTab.generateRandom(value, 10);
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
		catch (const std::exception & e) {
			cout << "Program zwrocil blad: " << e.what() << endl;
			clearCinAfterError();
		}
		clearCinAfterError();
	} while (opt != '0');
}

void menu_heap()
{
	char opt; //wybrana opcja
	string fileName; //nazwa pliku wpisana przez użytkownika
	int index, value; // index/wartosc wpisana przez użytkownika
	Heap myTab = Heap(); // deklaracja obiektu
	bool isLoaded = false;

	do {
		try {
			//displayMenu("--- KOPIEC ---", isLoaded);
			cout << endl;
			cout << "--- KOPIEC ---" << endl;
			cout << "1.Wczytaj z pliku" << endl;
			//if (isLoaded) {
			cout << "2.Usun element o podanym indeksie" << endl;
			cout << "3.Usun wartosc" << endl;
			cout << "4.Dodaj" << endl;
			cout << "5.Znajdz" << endl;
			cout << "6.Utworz losowo" << endl;
			cout << "7.Wyswietl" << endl;
			//}
			cout << "0.Powrot do menu" << endl;
			cout << "Podaj opcje:";

			//opt = _getche();
			cin >> opt;
			cout << endl;
			switch (opt) {
			case '1': //tutaj wczytytwanie  kopca z pliku
				cout << " Podaj nazwe zbioru:";
				cin >> fileName;
				myTab.loadFromFile(fileName);
				myTab.display(cout);
				isLoaded = true;
				break;

			case '2': //tutaj usuwanie elemenu z kopca
				cout << " podaj index:";
				cin >> index;
				validateCin();
				myTab.removeElementAtIndex(index);
				myTab.display(cout);
				break;

			case '3': //tutaj usuwanie elemenu z kopca
				cout << " podaj wartosc:";
				cin >> value;
				validateCin();
				myTab.removeElementByValue(value);
				myTab.display(cout);
				break;

			case '4': //tutaj dodawanie elemetu do kopca
				cout << " podaj wartosc:";
				cin >> value;
				validateCin();
				myTab.addElement(value);
				myTab.display(cout);
				break;

			case '5': //tutaj znajdowanie elemetu w tablicy
				cout << " podaj wartosc:";
				cin >> value;
				validateCin();
				if (myTab.findValue(value))
					cout << "podana wartosc jest w kopcu";
				else
					cout << "podanej wartosci NIE ma w kopcu";
				break;

			case '6':  //tutaj generowanie  tablicy
				cout << "Podaj ilosc elementow kopca:";
				cin >> value;
				validateCin();
				myTab.generateRandom(value, 10);
				myTab.display(cout);
				break;

			case '7':  //tutaj wyswietlanie tablicy
				myTab.display(cout);
				cout << endl;
				btd.print_t(&myTab);
				break;

			case '8': //tutaj nasza funkcja do eksperyment�w (pomiary czas�w i generowanie daneych) - nie b�dzie testowana przez prowadz�cego 
					  // mo�na sobie tu doda� w�asne case'y
				break;
			}
		}
		catch (const std::exception & e) {
			cout << "Program zwrocil blad: " << e.what() << endl;
			clearCinAfterError();
		}

		clearCinAfterError();
	} while (opt != '0');
}

void menu_rbtree()
{
	char opt; //wybrana opcja
	string fileName; //nazwa pliku wpisana przez użytkownika
	int index, value; // index/wartosc wpisana przez użytkownika
	RBTree rbtree = RBTree(); // deklaracja obiektu
	bool isLoaded = false;

	do {
		try {
			displayMenu("--- DRZEWO CZERWONO-CZARNE ---", isLoaded);
			//opt = _getche();
			cin >> opt;
			validateCin();
			cout << endl;
			switch (opt) {
			case '1': //tutaj wczytytwanie  kopca z pliku
				cout << " Podaj nazwe zbioru:";
				cin >> fileName;
				rbtree.loadFromFile(fileName);
				//rbtree.display(cout);
				btd.print(rbtree.root);
				isLoaded = true;
				break;

			case '2': //tutaj usuwanie elemenu z kopca
				cout << " podaj wartosc:";
				cin >> value;
				validateCin();
				rbtree.removeElement(value);
				//rbtree.display(cout);
				btd.print(rbtree.root);
				break;

			case '3': //tutaj dodawanie elemetu do kopca
				cout << " podaj wartosc:";
				cin >> value;
				validateCin();
				rbtree.rbInsert(value);
				btd.print(rbtree.root);
				//rbtree.display(cout);
				break;

			case '4': //tutaj znajdowanie elemetu w tablicy
				cout << " podaj wartosc:";
				cin >> value;
				validateCin();
				if (rbtree.findValue(value)->isNotNull())
					cout << "podana wartosc jest w kopcu";
				else
					cout << "podanej wartosci NIE ma w kopcu";
				break;

			case '5':  //tutaj generowanie  tablicy
				cout << "Podaj ilosc elementow kopca:";
				cin >> value;
				validateCin();
				rbtree.generateRandom(value, 10);
				//rbtree.display(cout);
				btd.print(rbtree.root);
				break;

			case '6':  //tutaj wyswietlanie tablicy
				//rbtree.display(cout);
				//btd.print_t(rbtree.root);
				btd.print(rbtree.root);
				break;

			case '7': //tutaj nasza funkcja do eksperyment�w (pomiary czas�w i generowanie daneych) - nie b�dzie testowana przez prowadz�cego 
					  // mo�na sobie tu doda� w�asne case'y
				break;
			}
		}
		catch (const std::exception & e) {
			cout << "Program zwrocil blad: " << e.what() << endl;
			clearCinAfterError();
		}
		clearCinAfterError();
	} while (opt != '0');
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
		cout << "4.Drzewo czerwono-czarne" << endl;
		cout << "5.Wykonaj pomiary" << endl;
		cout << "0.Wyjscie" << endl;
		cout << "Podaj opcje:";
		//option = _getche();
		cin >> option;
		validateCin();
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

		case '4':
			menu_rbtree();
			break;

		case '5':
			tC.Start(210, 10, 50, 100, cout);
			break;
		default:
			cout << "Nie znaleziono takiej opcji";
		}
		clearCinAfterError();
	} while (option != '0');


	return 0;
}

