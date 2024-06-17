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
    static void editPatient(vector<Patient>& patients);
    static void searchPatients(const vector<Patient>& patients, char searchOption);
    static void statisticsPatients(const vector<Patient>& patients);

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
//Tìm kiếm bệnh nhân theo tên hoặc ID
void Patient::searchPatients(const vector<Patient>& patients, char searchOption) {
    if (searchOption != '1' && searchOption != '2') {
        cout << "Lua chon khong hop le." << endl;
        return;
    }
    if (searchOption == '1') {
        string id;
        cout << "Nhap ma so benh nhan can tim kiem: ";
        cin >> id;

        bool found = false;
        for (const auto& patient : patients) {
            if (patient.getPatientID() == id) {
                found = true;
                cout << "Thong tin benh nhan can tim: " << endl;
                cout << "Ho va ten: " << patient.getPatientName() << endl;
                cout << "Ngay sinh: " << patient.getBirthday().getDay() << "/" << patient.getBirthday().getMonth() << "/" << patient.getBirthday().getYear() << endl;
                cout << "Gioi tinh: " << patient.getGender() << endl;
                cout << "Dia chi: " << patient.getAddress() << endl;
                cout << "So dien thoai: " << patient.getPhoneNumber() << endl;
                cout << "Ma benh nhan: " << patient.getPatientID() << endl;
                break;
            }
        }
        if (!found)
            cout << "Khong tim thay benh nhan voi ma so " << id << endl;
    } else if (searchOption == '2') {
        string name;
        cout << "Nhap ten benh nhan can tim kiem: ";
        cin.ignore();
        getline(cin, name);

        bool found = false;
        for (const auto& patient : patients) {
            if (patient.getPatientName() == name) {
                found = true;
                cout << "Thong tin benh nhan can tim: " << endl;
                cout << "Ho va ten: " << patient.getPatientName() << endl;
                cout << "Ngay sinh: " << patient.getBirthday().getDay() << "/" << patient.getBirthday().getMonth() << "/" << patient.getBirthday().getYear() << endl;
                cout << "Gioi tinh: " << patient.getGender() << endl;
                cout << "Dia chi: " << patient.getAddress() << endl;
                cout << "So dien thoai: " << patient.getPhoneNumber() << endl;
                cout << "Ma benh nhan: " << patient.getPatientID() << endl;
            }
        }
        if (!found)
            cout << "Khong tim thay benh nhan voi ten " << name << endl;
    }
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
             << setw(2) << patient.getBirthday().getDay() << "/"
             << setw(2) << patient.getBirthday().getMonth() << "/"
             << setw(4) << patient.getBirthday().getYear() << setfill(' ') << setw(11)
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

//hàm sửa
void Patient::editPatient(vector<Patient>& patients){
    cout<<"Nhap id cua benh nhan ma ban muon sua: ";
    string id;
    cin.ignore();
    getline(cin,id);

    bool found=false;
    for(int i=0;i<patients.size();i++){
        if(patients[i].getPatientID() == id){
            found = true;
            cout << "Chon muc can sua:" << endl;
            cout << "[1]. Ten benh nhan" << endl;
            cout << "[2]. Ngay sinh" << endl;
            cout << "[3]. Gioi tinh" << endl;
            cout << "[4]. Dia chi" << endl;
            cout << "[5]. So dien thoai" << endl;
            cout << "[0]. Quay lai menu" << endl;

            char choice;
            do{
            cin >> choice;
            cin.ignore(); 

            switch (choice) {
                case '1': {
                    string newName;
                    cout << "Nhap ten benh nhan moi: ";
                    getline(cin, newName);
                    patients[i].setPatientName(newName);
                    cout << "Da sua ten benh nhan thanh cong." << endl;
                    break;
                }
                case '2': {
                    int day, month, year;
                    cout << "Nhap ngay sinh moi:" << endl;
                    cout << "  Ngay (dd): ";
                    cin >> day;
                    cout << "  Thang (mm): ";
                    cin >> month;
                    cout << "  Nam (yyyy): ";
                    cin >> year;
                    cin.ignore(); 
                    patients[i].setBirthday(Date(day, month, year));
                    cout << "Da sua ngay sinh thanh cong." << endl;
                    break;
                }
                case '3': {
                    string newGender;
                    cout << "Nhap gioi tinh moi: ";
                    getline(cin, newGender);
                    patients[i].setGender(newGender);
                    cout << "Da sua gioi tinh thanh cong." << endl;
                    break;
                }
                case '4': {
                    string newAddress;
                    cout << "Nhap dia chi moi: ";
                    getline(cin, newAddress);
                    patients[i].setAddress(newAddress);
                    cout << "Da sua dia chi thanh cong." << endl;
                    break;
                }
                case '5': {
                    string newPhone;
                    cout << "Nhap so dien thoai moi: ";
                    getline(cin, newPhone);
                    patients[i].setPhoneNumber(newPhone);
                    cout << "Da sua so dien thoai thanh cong." << endl;
                    break;
                }
                case '0':
                    cout << "Quay lai menu chinh." << endl;
                    break;
                default:
                    cout << "Lua chon khong hop le." << endl;
                    break;
            }
            }while(choice!='0');
        }
    }
    if(!found){
        cout<<"Khong tim thay benh nhan co ID: "<<id<<endl;
    }
}
//Hàm tính tuổi
int calculateAge(const Date& birthdate) {
    time_t t = time(0); 
    tm* now = localtime(&t);
    int currentYear = now->tm_year + 1900;
    int currentMonth = now->tm_mon + 1;
    int currentDay = now->tm_mday;

    int age = currentYear - birthdate.getYear();
    if (currentMonth < birthdate.getMonth() || (currentMonth == birthdate.getMonth() && currentDay < birthdate.getDay())) {
        age--;
    }
    return age;
}

//Hàm thống kê bệnh nhân
void Patient::statisticsPatients(const vector<Patient>& patients) {
    int choice;
    cout << "[1]. Thong ke benh nhan theo do tuoi." << endl;
    cout << "[2]. Thong ke benh nhan theo gioi tinh." << endl;
    cout << "Nhap lua chon: ";
    cin >> choice;

    switch (choice) {
        case 1: {
            int under15 = 0, between15And65 = 0, over65 = 0;
            for (const auto& patient : patients) {
                int age = calculateAge(patient.getBirthday());
                if (age < 15) under15++;
                else if (age <= 65) between15And65++;
                else over65++;
            }
            cout << "So luong benh nhan duoi 15 tuoi: " << under15 << endl;
            cout << "So luong benh nhan tu 15 den 65 tuoi: " << between15And65 << endl;
            cout << "So luong benh nhan tren 65 tuoi: " << over65 << endl;
            break;
        }
        case 2: {
            int male = 0, female = 0;
            for (const auto& patient : patients) {
                if (patient.getGender() == "Nam") male++;
                else if (patient.getGender() == "Nu") female++;
            }
            cout << "So luong benh nhan nam: " << male << endl;
            cout << "So luong benh nhan nu: " << female << endl;
            break;
        }
        default:
            cout << "Lua chon khong hop le!" << endl;
            break;
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
                Patient::editPatient(patients);
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
