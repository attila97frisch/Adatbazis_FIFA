#pragma once
class Jatekos {
protected:
	char* nev;
	int mezszam;

	Jatekos(char* nameparam, int numberparam);
public:
	virtual void print() = 0;
	~Jatekos();
};

class Mezonyjatekos : public Jatekos {
protected:
	int passzok;
	int sikeres_passzok;

	Mezonyjatekos(char* nameparam, int numberparam, int passesparam, int successfulparam);
public:
	virtual void print() = 0;
};

class Kapus : public Jatekos {
	int kapott_gol_nelkuli;
	int vedesek;
public:
	Kapus(char* nameparam, int numberparam, int savesparam, int cleansheetsparam);
	void print();
	double ertekel() const;
};

class Vedo : public Mezonyjatekos {
	int szerelesek;
public:
	Vedo(char* nameparam, int numberparam, int passesparam, int succesfulparam, int tacklesparam);
	void print();
	double ertekel() const;
};

class Kozeppalyas : public Mezonyjatekos {
	int golpasszok;
public:
	Kozeppalyas(char* nameparam, int numberparam, int passesparam, int successfulparam, int assistsparam);
	void print();
	double ertekel() const;
};

class Tamado : public Mezonyjatekos {
	int golok;
public:
	Tamado(char* nameparam, int numberparam, int passesparam, int successfulparam, int goalsparam);
	void print();
	double ertekel() const;
};

class Tarolo {
	Jatekos* elemek[50];
	int elementNum;
public:
	Tarolo();
	~Tarolo();
	bool hozzaad(Jatekos* j);
	void Tarolo::kiir();
};