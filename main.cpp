#include <iostream>
#include <windows.h>
#include <string>
#include <fstream>
#include <vector>


using namespace std;

struct Adresat {
    int id;
    string imie, nazwisko, nrTel, email, adres;
};
string wczytajLinie() {
    string nazwa = " ";
    cin.sync();
    getline(cin,nazwa);
    return nazwa;
}

void wczytajAdresatowZPliku(vector <Adresat>&adresaci) {
    Adresat nowyAdresat;
    string linia;
    int nrLinii = 1;
    fstream ksiazka;
    int poczatek, koniec;
    string id;

    ksiazka.open("ksiazka.txt", ios::in);

    if(!ksiazka.good()) cout << "Nie mozna otworzyc pliku!";

    while(getline(ksiazka, linia)) {
        poczatek = 0;
        koniec = linia.find("|", poczatek);
        id = linia.substr(poczatek, koniec - poczatek);
        nowyAdresat.id = atoi(id.c_str());
        poczatek = koniec;
        koniec = linia.find("|", poczatek+1);
        nowyAdresat.imie = linia.substr(poczatek +1, koniec - poczatek - 1);
        poczatek = koniec;
        koniec = linia.find("|", poczatek+1);
        nowyAdresat.nazwisko = linia.substr(poczatek +1, koniec - poczatek - 1);
        poczatek = koniec;
        koniec = linia.find("|", poczatek+1);
        nowyAdresat.nrTel = linia.substr(poczatek +1, koniec - poczatek - 1);
        poczatek = koniec;
        koniec = linia.find("|", poczatek+1);
        nowyAdresat.email = linia.substr(poczatek +1, koniec - poczatek - 1);
        poczatek = koniec;
        koniec = linia.find("|", poczatek+1);
        nowyAdresat.adres = linia.substr(poczatek +1, koniec - poczatek - 1);
        adresaci.push_back(nowyAdresat);
        nrLinii++;
    }
    ksiazka.close();
}

void dodawanieAdresata (vector <Adresat>&adresaci) {

    Adresat nowyAdresat;
    int ostatniAdresat = adresaci.size() - 1;

    cout << "Podaj imie: ";
    nowyAdresat.imie = wczytajLinie();
    cout << "Podaj nazwisko: ";
    nowyAdresat.nazwisko = wczytajLinie();
    cout << "Podaj numer telefonu: ";
    nowyAdresat.nrTel = wczytajLinie();
    cout << "Podaj email: ";
    nowyAdresat.email = wczytajLinie();
    cout << "Podaj adres: ";
    nowyAdresat.adres = wczytajLinie();
    nowyAdresat.id = adresaci[ostatniAdresat].id + 1;

    adresaci.push_back(nowyAdresat);

    fstream ksiazka;
    ksiazka.open("ksiazka.txt", ios::out | ios::app);

    if (ksiazka.good()) {
        ksiazka << nowyAdresat.id  << "|" << nowyAdresat.imie << "|" << nowyAdresat.nazwisko << "|" << nowyAdresat.nrTel << "|" << nowyAdresat.email << "|" << nowyAdresat.adres << "|" << endl;
        cout << "Nowy adresat dodany" << endl;
        ksiazka.close();
    } else cout << "Nie udalo sie otworzycpliku i zapisac do niego danych" << endl;
    system("pause");
}

void wyswietlanieWszystkich(vector <Adresat>&adresaci) {
    if (adresaci.size() >0) {
        for(int i = 0; i < adresaci.size(); i++) {
            cout << endl;
            cout << "ID: "             <<adresaci[i].id << endl;
            cout << "Imie: "           << adresaci[i].imie << endl;
            cout << "Nazwisko: "       << adresaci[i].nazwisko << endl;
            cout << "Numer telefonu: " << adresaci[i].nrTel << endl;
            cout << "Email: "          << adresaci[i].email << endl;
            cout << "Adres: "          << adresaci[i].adres << endl;
        }
    } else  cout << "Ksiazka adresatow jest pusta, dodaj  kontakty." << endl;
    system("pause");
}

void wyswietlImie(vector <Adresat> adresaci) {

    int iloscWystapien = 0;
    string imie;

    if (adresaci.size() >0) {
        cout << "Podaj imie do wyswietlenia: ";
        imie = wczytajLinie();
        for(int i = 0; i < adresaci.size(); i++) {
            if (imie == adresaci[i].imie) {
                cout << "ID: "             <<adresaci[i].id << endl;
                cout << "Imie: "           << adresaci[i].imie << endl;
                cout << "Nazwisko: "       << adresaci[i].nazwisko << endl;
                cout << "Numer telefonu: " << adresaci[i].nrTel << endl;
                cout << "Email: "          << adresaci[i].email << endl;
                cout << "Adres: "          << adresaci[i].adres << endl;
                iloscWystapien ++;
            }
        }
        if (iloscWystapien == 0) cout << "Brak osoby o takim imieniu w ksiazce adresowej. " << endl;
    } else cout << "Ksiazka adresatow jest pusta, dodaj  kontakty." << endl;
    system("pause");
}

void wyswietlNazwisko(vector <Adresat> adresaci) {
    string nazwisko;
    int iloscWystapien = 0;

    if (adresaci.size() > 0) {
        cout << "Podaj nazwisko do wyswietlenia: ";
        nazwisko = wczytajLinie();
        for(int i = 0; i < adresaci.size(); i++) {
            if (nazwisko == adresaci[i].nazwisko) {
                cout << "ID: "             <<adresaci[i].id << endl;
                cout << "Imie: "           << adresaci[i].imie << endl;
                cout << "Nazwisko: "       << adresaci[i].nazwisko << endl;
                cout << "Numer telefonu: " << adresaci[i].nrTel << endl;
                cout << "Email: "          << adresaci[i].email << endl;
                cout << "Adres: "          << adresaci[i].adres << endl;
                iloscWystapien ++;
            }
        }
        if (iloscWystapien == 0) cout << "Brak osoby o takim nazwisku w ksiazce adresowej. " << endl;
    } else cout << "Ksiazka adresatow jest pusta, dodaj  kontakty." << endl;
    system("pause");
}

void zapisPoZmianach(vector <Adresat>& adresaci) {

    fstream ksiazkaPoZmianach;
    vector <Adresat>::iterator it = adresaci.begin();

    ksiazkaPoZmianach.open("ksiazka.txt", ios::out | ios :: trunc);

    if (ksiazkaPoZmianach.good()) {
        for (int i = 0; i < adresaci.size(); i++) {
            ksiazkaPoZmianach << adresaci[i].id  << "|" << adresaci[i].imie << "|" << adresaci[i].nazwisko << "|" << adresaci[i].nrTel << "|" << adresaci[i].email << "|" << adresaci[i].adres << "|" << endl;
        }
    }
    ksiazkaPoZmianach.close();

}

void edycjaAdresata(vector <Adresat>& adresaci) {
    int id;
    char danaDoEdycji;
    int sprawdzenie = 0;
    cout << " >>>EDYCJA ADRESATA<<<" << endl;
    cout << "Podaj ID adresata do edycji:";
    cin >> id;

    for (int i = 0; i < adresaci.size(); i++) {
        if (id == adresaci[i].id) {
            cout << "Jaka dana chcesz modyfikowac?" << endl;
            cout << "1. Imie" << endl;
            cout << "2. Nazwisko" << endl;
            cout << "3. Numer telefonu" << endl;
            cout << "4. Email" << endl;
            cout << "5. Adres" << endl;
            cout << "6. Powrot do menu" << endl;
            cin >> danaDoEdycji;
            switch(danaDoEdycji) {
            case '1':
                cout << "Podaj nowe imie:";
                adresaci[i].imie = wczytajLinie();
                break;
            case '2':
                cout << "Podaj nowe nazwisko:";
                adresaci[i].nazwisko = wczytajLinie();
                break;
            case '3':
                cout << "Podaj nowy numer telefonu:";
                adresaci[i].nrTel = wczytajLinie();
                break;
            case '4':
                cout << "Podaj nowy email:";
                adresaci[i].email = wczytajLinie();
                break;
            case '5':
                cout << "Podaj nowy adres:";
                adresaci[i].adres = wczytajLinie();
                break;
            case '6':
                break;
            }
            sprawdzenie ++;
            if (danaDoEdycji != '6'){
            zapisPoZmianach(adresaci);
            cout << "Dane zostaly zmienione" << endl;
            }
        }
    }
    if(sprawdzenie == 0) cout  << "Brak osoby o takim id w ksiazce adresowej. " << endl;
    system("pause");
}

void usunAdresata(vector <Adresat>& adresaci) {
    int id;
    int sprawdzenie = 0;
    vector <Adresat>::iterator it;
    string odpowiedz;

    cout << " >>>USUWANIE ADRESATA<<<" << endl;
    cout << "Podaj ID adresata do usuniecia:";
    cin >> id;

    for (int i = 0; i < adresaci.size(); i++) {
        if (id == adresaci[i].id) {
            sprawdzenie++;
            cout << "Wcisnij t aby potiwerdzic usuniecie adresata " << adresaci[i].imie << " " <<  adresaci[i].nazwisko << " : ";
            cin >> odpowiedz;
            if(odpowiedz == "t") {
                it = adresaci.begin() + i;
                adresaci.erase(it);
                zapisPoZmianach(adresaci);
            } else cout << "Adresat nie zostal usuniety";
        }
    }
    if(sprawdzenie == 0) cout << "Brak osoby o takim id w ksiazce adresowej.";
    system("pause");
}



int main() {
    vector <Adresat> adresaci;
    wczytajAdresatowZPliku(adresaci);
    char wybor;

    while(1) {
        system("cls");
        cout << " >>>KSIAZKA ADRESOWA<<<" << endl;
        cout << "1. Dodaj adresata" << endl;
        cout << "2. Wyszukaj po imieniu" << endl;
        cout << "3. Wyszukaj po nazwisku" << endl;
        cout << "4. Wyswietl wszystkich adresatow" << endl;
        cout << "5. Eytuj wybranego adresata" << endl;
        cout << "6. Usun wybranego adresata" << endl;
        cout << "9. Zakoncz program" << endl;
        cin >> wybor;

        switch(wybor) {
        case '1':
            dodawanieAdresata(adresaci);
            break;
        case '2':
            wyswietlImie(adresaci);
            break;
        case '3':
            wyswietlNazwisko(adresaci);
            break;
        case '4':
            wyswietlanieWszystkich(adresaci);
            break;
        case '5':
            edycjaAdresata(adresaci);
            break;
        case '6':
            usunAdresata(adresaci);
            break;
        case '9':
            exit(0);
            break;
        default:
            cout << "Nie ma takiej opcji" << endl;
            Sleep(3000);
        }
    }
    return 0;
}

