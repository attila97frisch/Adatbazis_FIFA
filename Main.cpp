#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>
#include <string.h>
#include "Classes.h"

using namespace std;


int main(void) {
	FILE* fp;
	Tarolo tarolo;

	char scannedtype[100 + 1];
	char scannedname[100 + 1];
	int scannedparam1;
	int scannedparam2;
	int scannedparam3;
	int scannedparam4;

	try {
		fp = fopen("jatekosok.txt", "r");
		if (fp == NULL)
		{
			throw "A fajl megnyitasa sikertelen.\n";
		}
	}

	catch (const char* file_exception)
	{
		cout << "Hiba. " << file_exception;
		return 0;
	}


	while ((fscanf(fp, "%s", scannedtype)) == 1)
	{
		if (strcmp(scannedtype, "Kapus") == 0)
		{
			fscanf(fp, "%s%d%d%d", scannedname, &scannedparam1, &scannedparam2, &scannedparam3);
			if (tarolo.hozzaad(new Kapus(scannedname, scannedparam1, scannedparam2, scannedparam3)) == 0)
				return 0;
		}
		if (strcmp(scannedtype, "Vedo") == 0)
		{
			fscanf(fp, "%s%d%d%d%d", scannedname, &scannedparam1, &scannedparam2, &scannedparam3, &scannedparam4);
			if (tarolo.hozzaad(new Vedo(scannedname, scannedparam1, scannedparam2, scannedparam3, scannedparam4)) == 0)
				return 0;
		}
		if (strcmp(scannedtype, "Kozeppalyas") == 0)
		{
			fscanf(fp, "%s%d%d%d%d", scannedname, &scannedparam1, &scannedparam2, &scannedparam3, &scannedparam4);
			if (tarolo.hozzaad(new Kozeppalyas(scannedname, scannedparam1, scannedparam2, scannedparam3, scannedparam4)) == 0)
				return 0;
		}
		if (strcmp(scannedtype, "Tamado") == 0)
		{
			fscanf(fp, "%s%d%d%d%d", scannedname, &scannedparam1, &scannedparam2, &scannedparam3, &scannedparam4);
			if (tarolo.hozzaad(new Tamado(scannedname, scannedparam1, scannedparam2, scannedparam3, scannedparam4)) == 0)
				return 0;
		}
	}

	fclose(fp);

	tarolo.kiir();

	cout << "Ha szeretne tovabbiakat elemezni, kerem irja be a jatekos tipusat majd nyomjon entert, ha nem, irja be az exit parancsot" << endl;
	try {
		cin >> scannedtype;
		if ((strcmp(scannedtype, "exit") != 0 && strcmp(scannedtype, "Kapus") != 0 && strcmp(scannedtype, "Vedo") != 0 && strcmp(scannedtype, "Kozeppalyas") != 0 && strcmp(scannedtype, "Tamado") != 0) || (strlen(scannedtype)>20))
			throw "Ilyen tipus nem letezik";

	}
	catch (const char* type_exception) {
		cout << "Hiba. " << type_exception << endl;
		return 0;
	}

	while (strcmp(scannedtype, "exit") != 0)
	{
		if (strcmp(scannedtype, "Kapus") == 0)
		{
			cout << "Kerem irja be a kapus nevet, mezszamat, vedeseinek szamat valamint kapott gol nelkuli merkozeseinek szamat, majd nyomja meg az entert" << endl;
			try {
				cin >> scannedname >> scannedparam1 >> scannedparam2 >> scannedparam3;
				if (cin.fail())
					throw "Helytelen adat.";
			}
			catch (const char* data_exception) {
				cout << "Hiba. " << data_exception << endl;
				return 0;
			}
			Kapus kapus(scannedname, scannedparam1, scannedparam2, scannedparam3);
			kapus.print();
		}
		if (strcmp(scannedtype, "Vedo") == 0)
		{
			cout << "Kerem irja be a vedo nevet, mezszamat, osszes passzanak szamat, sikeres passzainak szamat es szereleseinek szamat, majd nyomja meg az entert" << endl;
			try {
				cin >> scannedname >> scannedparam1 >> scannedparam2 >> scannedparam3 >> scannedparam4;
				if (cin.fail())
					throw "Helytelen adat.";
			}
			catch (const char* data_exception) {
				cout << "Hiba. " << data_exception << endl;
				return 0;
			}
			Vedo vedo(scannedname, scannedparam1, scannedparam2, scannedparam3, scannedparam4);
			vedo.print();
		}
		if (strcmp(scannedtype, "Kozeppalyas") == 0)
		{
			cout << "Kerem irja be a kozeppalyas nevet, mezszamat, osszes passzanak szamat, sikeres passzainak szamat es golpasszainak szamat, majd nyomja meg az entert" << endl;
			try {
				cin >> scannedname >> scannedparam1 >> scannedparam2 >> scannedparam3 >> scannedparam4;
				if (cin.fail())
					throw "Helytelen adat.";
			}
			catch (const char* data_exception) {
				cout << "Hiba. " << data_exception << endl;
				return 0;
			}
			Kozeppalyas kozeppalyas(scannedname, scannedparam1, scannedparam2, scannedparam3, scannedparam4);
			kozeppalyas.print();
		}
		if (strcmp(scannedtype, "Tamado") == 0)
		{
			cout << "Kerem irja be a tamado nevet, mezszamat, osszes passzanak szamat, sikeres passzainak szamat es goljainak szamat, majd nyomja meg az entert" << endl;
			try {
				cin >> scannedname >> scannedparam1 >> scannedparam2 >> scannedparam3 >> scannedparam4;
				if (cin.fail())
					throw "Helytelen adat.";
			}
			catch (const char* data_exception) {
				cout << "Hiba. " << data_exception << endl;
				return 0;
			}
			Tamado tamado(scannedname, scannedparam1, scannedparam2, scannedparam3, scannedparam4);
			tamado.print();
		}

		cout << "Ha szeretne tovabbiakat elemezni, kerem irja be a jatekos tipusat majd nyomjon entert, ha nem, irja be az exit parancsot" << endl;
		try {
			cin >> scannedtype;
			if (strcmp(scannedtype, "exit") != 0 && strcmp(scannedtype, "Kapus") != 0 && strcmp(scannedtype, "Vedo") != 0 && strcmp(scannedtype, "Kozeppalyas") != 0 && strcmp(scannedtype, "Tamado") != 0)
				throw "Hibas tipust adott meg vagy nem megfelelo parametereket irt be.";
		}
		catch (const char* data_exception) {
			cout << "Hiba. " << data_exception << endl;
			return 0;
		}
	}

	return 0;
}