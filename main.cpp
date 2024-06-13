#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
using namespace std;

class Date {
    int day;
    int month;
    int year;
public:
    Date(int d = 1, int m = 1, int y = 1900) : day(d), month(m), year(y) {}

    int getDay() const { return day; }
    int getMonth() const { return month; }
    int getYear() const { return year; }

    void setDay(int d) { day = d; }
    void setMonth(int m) { month = m; }
    void setYear(int y) { year = y; }

    void setDate(int d, int m, int y) {
        day = d;
        month = m;
        year = y;
    }
};

class Patient {
private:
    string patientID;
    string patientName;
    string gender;
    Date birthday;
    string address;
    string phoneNumber;

public:
    Patient(string id = "", string name = "", string g = "", Date b = Date(), string addr = "", string phone = "")
        : patientID(id), patientName(name), gender(g), birthday(b), address(addr), phoneNumber(phone) {}

    string getPatientID() const { return patientID; }
    string getPatientName() const { return patientName; }
    string getGender() const { return gender; }
    Date getBirthday() const { return birthday; }
    string getAddress() const { return address; }
    string getPhoneNumber() const { return phoneNumber; }

    void setPatientID(const string& id) { patientID = id; }
    void setPatientName(const string& name) { patientName = name; }
    void setGender(const string& g) { gender = g; }
    void setBirthday(const Date& b) { birthday = b; }
    void setAddress(const string& addr) { address = addr; }
    void setPhoneNumber(const string& phone) { phoneNumber = phone; }

    static void addPatient(vector<Patient>& patients);
    static void displayPatients(const vector<Patient>& patients);
    static void deletePatient(vector<Patient>& patients);
};

//Ham them benh nhan
void Patient::addPatient(vector<Patient>& patients) {
    Patient newPatient;
    string input;
    int day, month, year;

    cout << "Nhap ten benh nhan: ";
    cin.ignore();
    getline(cin, input);
    newPatient.setPatientName(input);

    cout << "Nhap ngay sinh:" << endl;
    cout << "  Ngay (dd): ";
    cin >> day;
    cout << "  Thang (mm): ";
    cin >> month;
    cout << "  Nam (yyyy): ";
    cin >> year;
    cin.ignore();
    newPatient.setBirthday(Date(day, month, year));

    cout << "Nhap gioi tinh: ";
    getline(cin, input);
    newPatient.setGender(input);

    cout << "Nhap dia chi: ";
    getline(cin, input);
    newPatient.setAddress(input);

    cout << "Nhap so dien thoai: ";
    getline(cin, input);
    newPatient.setPhoneNumber(input);

    cout << "Nhap ma so benh nhan: ";
    getline(cin, input);
    newPatient.setPatientID(input);

    patients.push_back(newPatient);
}

//Ham hien thi benh nhan theo dong voi cac cot la cac muc
void Patient::displayPatients(const vector<Patient>& patients) {
    cout << left << setw(20) << "Ho va ten"
         << setw(15) << "Ngay sinh"
         << setw(10) << "Gioi tinh"
         << right<< setw(30) << "Dia chi"
         << setw(15) << "So dien thoai"
         << setw(15) << "Ma benh nhan" << endl;

    cout << setfill('-') << setw(105) << "-" << endl;
    cout << setfill(' ');

    for (const auto& patient : patients) {
        cout << left << setw(20) << patient.getPatientName()
             << setw(2) << setfill('0') << patient.getBirthday().getDay() << "/"
             << setw(2) << setfill('0') << patient.getBirthday().getMonth() << "/"
             << setw(4) << setfill('0') << patient.getBirthday().getYear() << setfill(' ') << setw(11)
             << right << setw(10) << patient.getGender()
             << right << setw(30) << patient.getAddress()
             << right << setw(15) << patient.getPhoneNumber()
             << right<< setw(15) << patient.getPatientID() << endl;
        cout << setfill('-') << setw(105) << "-" << endl;
        cout << setfill(' ');
    }
}

//ham xoa benh nha
void Patient::deletePatient(vector<Patient>& patients){
    cout<<"\nNhap id ma ban muon xoa: ";
    string id;
    cin.ignore();
    getline(cin,id);

    bool found=false;
    for(int i=0;i<patients.size();i++){
        if(patients[i].getPatientID() == id){
            patients.erase(patients.begin()+i);
            found=true;
            cout<<"Da xoa thanh cong benh nhan voi ID: "<<id<<endl;
            break;
        }
    }

    if(!found){
        cout<<"Khong tim thay benh nhan co ID: "<<id<<endl;
    }
}

void menu() {
    vector<Patient> patients;

    char number;
    do {
        cout << "-------------------------------------------" << endl;
        cout << "=============QUAN LI BENH NHAN=============" << endl;
        cout << "-------------------------------------------" << endl;
        cout << "[1]. Them thong tin benh nhan." << endl;
        cout << "[2]. Hien thi danh sach benh nhan." << endl;
        cout << "[3]. Sua thong tin benh nhan." << endl;
        cout << "[4]. Xoa thong tin benh nhan." << endl;
        cout << "[5]. Tim kiem ho so benh nhan." << endl;
        cout << "[6]. Sap xep ho so benh nhan." << endl;
        cout << "[7]. Thong ke ho so benh nhan." << endl;
        cout << "[8]. Them nguoi dung." << endl;
        cout << "[0]. Thoat chuong trinh" << endl;
        cin >> number;

        switch (number) {
            case '1':
                system("cls");
                Patient::addPatient(patients);
                break;
            case '2':
                system("cls");
                Patient::displayPatients(patients);
                break;
            case '3':
                system("cls");
                cout << " sua ." << endl;
                break;
            case '4':
                system("cls");
                Patient::deletePatient(patients);
                break;
            case '5':
                system("cls");
                cout << "tim kiem." << endl;
                break;
            case '6':
                system("cls");
                cout << "sap xep " << endl;
                break;
            case '7':
                system("cls");
                cout << " thong ke " << endl;
                break;

            case '0':
                cout << "Thoat chuong trinh." << endl;
                break;
            default:
                system("cls");
                cout << "Khong tim thay hanh dong phu hop!" << endl;
                break;
        }
    } while (number != '0');
}

int main() {
    menu();
    return 0;
}
