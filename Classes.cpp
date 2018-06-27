#include "Classes.h"
#include <iostream>
#include <string.h>
using namespace std;

Jatekos::Jatekos(char* nameparam = "", int numberparam = 0) {
	try {
		nev = new char[20 + 1];
		if (nev == NULL)
			throw "Sikertelen helyfoglalas a nevnek.";
	}
	catch (const char* name_exception) {
		cout << "Hiba. " << name_exception << endl;
	}
	strcpy_s(nev, (strlen(nameparam) + 1) * sizeof(char), nameparam);
	mezszam = numberparam;
};

Kapus::Kapus(char* nameparam = "", int numberparam = 0, int savesparam = 0, int cleansheetsparam = 0) : Jatekos(nameparam, numberparam), vedesek(savesparam), kapott_gol_nelkuli(cleansheetsparam) {}

void Kapus::print() {
	printf("%s", nev);
	cout << " " << mezszam << " " << vedesek << " " << kapott_gol_nelkuli << endl << "Ertekeles: " << ertekel() << endl;
}

void Vedo::print() {
	printf("%s", nev);
	cout << " " << mezszam << " " << passzok << " " << sikeres_passzok << " " << szerelesek << " " << endl << "Ertekeles: " << ertekel() << endl;
}

void Kozeppalyas::print() {
	printf("%s", nev);
	cout << " " << mezszam << " " << passzok << " " << sikeres_passzok << " " << golpasszok << " " << endl << "Ertekeles: " << ertekel() << endl;
}

void Tamado::print() {
	printf("%s", nev);
	cout << " " << mezszam << " " << passzok << " " << sikeres_passzok << " " << golok << " " << endl << "Ertekeles: " << ertekel() << endl;
}

Mezonyjatekos::Mezonyjatekos(char* nameparam = "", int numberparam = 0, int passesparam = 0, int successfulparam = 0) :Jatekos(nameparam, numberparam), passzok(passesparam), sikeres_passzok(successfulparam) {}

Vedo::Vedo(char* nameparam, int numberparam, int passesparam, int successfulparam, int tacklesparam) : Mezonyjatekos(nameparam, numberparam, passesparam, successfulparam), szerelesek(tacklesparam) {}

Kozeppalyas::Kozeppalyas(char* nameparam, int numberparam, int passesparam, int successfulparam, int assistsparam) : Mezonyjatekos(nameparam, numberparam, passesparam, successfulparam), golpasszok(assistsparam) {}

Tamado::Tamado(char* nameparam, int numberparam, int passesparam, int successfulparam, int goalsparam) : Mezonyjatekos(nameparam, numberparam, passesparam, successfulparam), golok(goalsparam) {}

Jatekos::~Jatekos()
{
	delete nev;
}

double Kapus::ertekel() const {
	if (((10 * kapott_gol_nelkuli + vedesek) / 38) > 10)
		return 10;
	return (10 * kapott_gol_nelkuli + vedesek) / 38;
}

double Vedo::ertekel() const {
	if (((sikeres_passzok * 5 / passzok) + (szerelesek * 2 / 38)) > 10)
		return 10;
	return ((sikeres_passzok * 5 / passzok) + (szerelesek * 2 / 38));
}

double Kozeppalyas::ertekel() const {
	if (((sikeres_passzok * 5 / passzok) + (golpasszok * 5 / 38)) > 10)
		return 10;
	return ((sikeres_passzok * 5 / passzok) + (golpasszok * 5 / 38));
}

double Tamado::ertekel() const {
	if (((sikeres_passzok * 5 / passzok) + (golok * 5 / 38)) > 10)
		return 10;
	return ((sikeres_passzok * 5 / passzok) + (golok * 5 / 38));
}

Tarolo::Tarolo() :elementNum(0) {};

Tarolo::~Tarolo() {
	int i;
	for (i = 0;i < elementNum;i++)
		delete elemek[i];
}

bool Tarolo::hozzaad(Jatekos* j) {
	try {
		if (elementNum > 48)
			throw "Nincs tobb hely az adatoknak.";
	}
	catch (const char* space_exception) {
		cout << "Hiba. " << space_exception;
		return false;
	}
	try {
		if (j == NULL)
			throw "Memoriafoglalas sikertelen";
		elemek[elementNum++] = j;
		return true;
	}
	catch (const char* memory_alloc_exception) {
		cout << "Hiba. " << memory_alloc_exception << endl;
		return false;
	}
}

void Tarolo::kiir() {
	for (int i = 0;i < elementNum; i++)
	{
		elemek[i]->print();
	}
}