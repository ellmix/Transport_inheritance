#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;


/*Создать общий родительский класс Транспорт и потомственные (Машина, Смолет, Судно, Мотоцикл)
  Реализовать функциональность. Функции ввода, get, set и тд.
  Использовать механизм позднего связывания*/


class Transport {
protected:
    char* brand;
    int year;

public:
    Transport(const char* brand, int year) : year(year) {
        this->brand = new char[strlen(brand) + 1];
        strcpy(this->brand, brand);
    }

    virtual ~Transport() {
        delete[] brand;
    }

    virtual void display() const {
        cout << "Brand: " << brand << ", Year: " << year;
    }

    virtual void input() {
        char inputBrand[100];
        cout << "Enter brand: ";
        cin.getline(inputBrand, sizeof(inputBrand));
        delete[] brand;
        brand = new char[strlen(inputBrand) + 1];
        strcpy(brand, inputBrand);

        cout << "Enter year: ";
        cin >> year;
        cin.ignore();
    }

    const char* getBrand() const {
        return brand;
    }

    void setBrand(const char* newBrand) {
        delete[] brand;
        brand = new char[strlen(newBrand) + 1];
        strcpy(brand, newBrand);
    }

    int getYear() const {
        return year;
    }

    void setYear(int newYear) {
        year = newYear;
    }
};

class Car : public Transport {
    int numWheels;

public:
    Car(const char* brand, int year, int numWheels) : Transport(brand, year), numWheels(numWheels) {}

    void display() const override {
        Transport::display();
        cout << ", Number of Wheels: " << numWheels << endl;
    }

    void input() override {
        Transport::input();

        cout << "Enter number of wheels: ";
        cin >> numWheels;
        cin.ignore();
    }
};

class Airplane : public Transport {
    int numEngines;

public:
    Airplane(const char* brand, int year, int numEngines) : Transport(brand, year), numEngines(numEngines) {}

    void display() const override {
        Transport::display();
        cout << ", Number of Engines: " << numEngines << endl;
    }

    void input() override {
        Transport::input();

        cout << "Enter number of engines: ";
        cin >> numEngines;
        cin.ignore();
    }
};

class Motorcycle : public Transport {
    bool hasSidecar;

public:
    Motorcycle(const char* brand, int year, bool hasSidecar) : Transport(brand, year), hasSidecar(hasSidecar) {}

    void display() const override {
        Transport::display();
        cout << ", Has Sidecar: " << (hasSidecar ? "Yes" : "No") << endl;
    }

    void input() override {
        Transport::input();

        char choice;
        cout << "Does it have a sidecar? (y/n): ";
        cin >> choice;
        hasSidecar = (choice == 'y' || choice == 'Y');
        cin.ignore();
    }
};

class Ship : public Transport {
    int numPropellers;

public:
    Ship(const char* brand, int year, int numPropellers) : Transport(brand, year), numPropellers(numPropellers) {}

    void display() const override {
        Transport::display();
        cout << ", Number of Propellers: " << numPropellers << endl;
    }

    void input() override {
        Transport::input();

        cout << "Enter number of propellers: ";
        cin >> numPropellers;
        cin.ignore();
    }
};

void displayTransportInfo(const Transport& transport) {
    transport.display();
}

int main() {
    int choice;
    cout << "1 - Car\n2 - Airplane\n3 - Motorcycle\n4 - Ship\n";
    cin >> choice;
    cin.ignore();

    Transport* transport;

    switch (choice) {
    case 1:
        transport = new Car("-", 0, 0);
        break;
    case 2:
        transport = new Airplane("-", 0, 0);
        break;
    case 3:
        transport = new Motorcycle("-", 0, false);
        break;
    case 4:
        transport = new Ship("-", 0, 0);
        break;
    default:
        cerr << "Invalid choice." << endl;
        return 1;
    }

    transport->input();
    //позднее связывание
    displayTransportInfo(*transport);

    delete transport;

    return 0;
}