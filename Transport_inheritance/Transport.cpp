#include <iostream>
#include <cstring>
using namespace std;

class Transport {
protected:
    char* brand_name;
    char* fuel;
    char* max_speed;
    int release_year;
    int weight;

public:
    Transport() : brand_name(nullptr), fuel(nullptr), max_speed(nullptr), release_year(0), weight(0) {}

    Transport(const char* b, const char* f, const char* m, int r, int w) : release_year(r), weight(w) {
        brand_name = new char[strlen(b) + 1];
        strcpy_s(brand_name, strlen(b) + 1, b);

        fuel = new char[strlen(f) + 1];
        strcpy_s(fuel, strlen(f) + 1, f);

        max_speed = new char[strlen(m) + 1];
        strcpy_s(max_speed, strlen(m) + 1, m);
    }

    virtual void Display() const {
        cout << "����� �������������: " << brand_name << endl;
        cout << "������������ �������: " << fuel << endl;
        cout << "������������ ��������: " << max_speed << endl;
        cout << "��� �������: " << release_year << endl;
        cout << "���: " << weight << endl;
    }

    virtual void Input() {
        cout << "\n����� �������������: "; cin >> brand_name;
        cout << "\n������������ ������� : "; cin >> fuel;
        cout << "\n������������ ��������: "; cin >> max_speed;
        cout << "\n��� �������: "; cin >> release_year;
        cout << "\n���: "; cin >> weight;
    }

    virtual ~Transport() {
        delete[] brand_name;
        delete[] fuel;
        delete[] max_speed;
    }
};

class Ship : public Transport {
private:
    char* type;
    int lifting_capacity;

public:
    Ship() : type(nullptr), lifting_capacity(0) {}

    Ship(const char* b, const char* f, const char* m, int r, int w, const char* t, int l)
        : Transport(b, f, m, r, w), lifting_capacity(l) {
        type = new char[strlen(t) + 1];
        strcpy_s(type, strlen(t) + 1, t);
    }

    virtual void Display() const override {
        Transport::Display();
        cout << "��� �����: " << type << endl;
        cout << "����������������: " << lifting_capacity << endl;
    }

    virtual void Input() override {
        Transport::Input();
        cout << "\n��� �����: ";
        char buffer[100];
        cin.ignore();
        cin.getline(buffer, sizeof(buffer));
        delete[] type;
        type = new char[strlen(buffer) + 1];
        strcpy_s(type, strlen(buffer) + 1, buffer);

        cout << "\n����������������: ";
        cin >> lifting_capacity;
    }

    virtual ~Ship() {
        delete[] type;
    }
};

class Car : public Transport {
private:
    char* car_body;
    int horsepower;

public:
    Car() : car_body(nullptr), horsepower(0) {}

    Car(const char* b, const char* f, const char* m, int r, int w, const char* c, int h) : Transport(b, f, m, r, w), horsepower(h) {
        car_body = new char[strlen(c) + 1];
        strcpy_s(car_body, strlen(c) + 1, c);
    }

    virtual void Display() const override {
        Transport::Display();
        cout << "��� ������: " << car_body << endl;
        cout << "��������� ���: " << horsepower << endl;
    }

    virtual void Input() override {
        Transport::Input();
        cout << "\n��� ������: ";
        cin >> car_body;
        cout << "\n��������� ���: ";
        cin >> horsepower;
    }

    virtual ~Car() {
        delete[] car_body;
    }
};

class Airplain : public Transport {
private:
    int flight_range;
    int seats_number;

public:
    Airplain() : flight_range(0), seats_number(0) {}

    Airplain(const char* b, const char* f, const char* m, int r, int w, int fr, int s)
        : Transport(b, f, m, r, w), flight_range(fr), seats_number(s) {}

    virtual void Display() const override {
        Transport::Display();
        cout << "��������� ������: " << flight_range << endl;
        cout << "���������� ����: " << seats_number << endl;
    }

    virtual void Input() override {
        Transport::Input();
        cout << "\n��������� ������: ";
        cin >> flight_range;
        cout << "\n���������� ����: ";
        cin >> seats_number;
    }

    virtual ~Airplain() {}
};

class Moto : public Transport {
private:
    char* moto_type;
    int engine_capacity;

public:
    Moto() : moto_type(nullptr), engine_capacity(0) {}

    Moto(const char* b, const char* f, const char* m, int r, int w, const char* mt, int e)
        : Transport(b, f, m, r, w), engine_capacity(e) {
        moto_type = new char[strlen(mt) + 1];
        strcpy_s(moto_type, strlen(mt) + 1, mt);
    }

    virtual void Display() const override {
        Transport::Display();
        cout << "��� ���������: " << moto_type << endl;
        cout << "����� ���������: " << engine_capacity << endl;
    }

    virtual void Input() override {
        Transport::Input();
        cout << "\n��� ���������: ";
        cin >> moto_type;
        cout << "\n����� ���������: ";
        cin >> engine_capacity;
    }

    virtual ~Moto() {
        delete[] moto_type;
    }
};

int main() {
    setlocale(LC_ALL, "");
    Transport* transport = nullptr;

    int choice;
    cout << "1 - �����\n2 - ������\n3 - �������\n4 - ��������\n";
    cin >> choice;

    switch (choice) {
    case 1:
        transport = new Ship;
        break;
    case 2:
        transport = new Car;
        break;
    case 3:
        transport = new Airplain;
        break;
    case 4:
        transport = new Moto;
        break;
    default:
        cout << "Error choice";
        return 1;
    }

    transport->Input();
    transport->Display();

    delete transport;
    return 0;
}