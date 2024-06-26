#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    int day;
    int month;
    int year;
} Date;

void setDate(Date* date, int d, int m, int y) {
    date->day = d;
    date->month = m;
    date->year = y;
}

typedef struct {
    char patientID[50];
    char patientName[100];
    char gender[10];
    Date birthday;
    char address[200];
    char phoneNumber[15];
} Patient;

void setPatientID(Patient* patient, const char* id) {
    strcpy(patient->patientID, id);
}

void setPatientName(Patient* patient, const char* name) {
    strcpy(patient->patientName, name);
}

void setGender(Patient* patient, const char* gender) {
    strcpy(patient->gender, gender);
}

void setBirthday(Patient* patient, Date* date) {
    patient->birthday = *date;
}

void setAddress(Patient* patient, const char* address) {
    strcpy(patient->address, address);
}

void setPhoneNumber(Patient* patient, const char* phone) {
    strcpy(patient->phoneNumber, phone);
}

void addPatient(Patient* patients, int* patientCount) {
    Patient newPatient;
    char input[200];
    int day, month, year;

    printf("Nhap ten benh nhan: ");
    getchar(); // clear the buffer
    fgets(input, 100, stdin);
    input[strcspn(input, "\n")] = '\0'; // remove the newline character
    setPatientName(&newPatient, input);

    printf("Nhap ngay sinh:\n");
    printf("  Ngay (dd): ");
    scanf("%d", &day);
    printf("  Thang (mm): ");
    scanf("%d", &month);
    printf("  Nam (yyyy): ");
    scanf("%d", &year);
    getchar(); // clear the buffer
    Date birthdate;
    setDate(&birthdate, day, month, year);
    setBirthday(&newPatient, &birthdate);

    printf("Nhap gioi tinh: ");
    fgets(input, 10, stdin);
    input[strcspn(input, "\n")] = '\0';
    setGender(&newPatient, input);

    printf("Nhap dia chi: ");
    fgets(input, 200, stdin);
    input[strcspn(input, "\n")] = '\0';
    setAddress(&newPatient, input);

    printf("Nhap so dien thoai: ");
    fgets(input, 15, stdin);
    input[strcspn(input, "\n")] = '\0';
    setPhoneNumber(&newPatient, input);

    printf("Nhap ma so benh nhan: ");
    fgets(input, 50, stdin);
    input[strcspn(input, "\n")] = '\0';
    setPatientID(&newPatient, input);

    patients[*patientCount] = newPatient;
    (*patientCount)++;
}

void displayPatients(const Patient* patients, int patientCount) {
    printf("%-20s %-15s %-10s %-30s %-15s %-15s\n", "Ho va ten", "Ngay sinh", "Gioi tinh", "Dia chi", "So dien thoai", "Ma benh nhan");
    for (int i = 0; i < 105; i++) printf("-");
    printf("\n");

    for (int i = 0; i < patientCount; i++) {
        const Patient* p = &patients[i];
        printf("%-20s %02d/%02d/%4d   %-10s %-30s %-15s %-15s\n",
               p->patientName, p->birthday.day, p->birthday.month, p->birthday.year,
               p->gender, p->address, p->phoneNumber, p->patientID);
        for (int j = 0; j < 105; j++) printf("-");
        printf("\n");
    }
}

void searchByName(const Patient* patients, int patientCount, const char* name) {
    int found = 0;
    for (int i = 0; i < patientCount; i++) {
        if (strcmp(patients[i].patientName, name) == 0) {
            found = 1;
            printf("Tim thay benh nhan voi ten %s:\n", name);
            printf("%-20s %-15s %-10s %-30s %-15s %-15s\n", "Ho va ten", "Ngay sinh", "Gioi tinh", "Dia chi", "So dien thoai", "Ma benh nhan");
            for (int i = 0; i < 105; i++) printf("-");
            printf("\n");
            printf("%-20s %02d/%02d/%4d   %-10s %-30s %-15s %-15s\n",
                   patients[i].patientName, patients[i].birthday.day, patients[i].birthday.month, patients[i].birthday.year,
                   patients[i].gender, patients[i].address, patients[i].phoneNumber, patients[i].patientID);
            for (int i = 0; i < 105; i++) printf("-");
            printf("\n");
        }
    }
    if (!found) {
        printf("Khong tim thay benh nhan voi ten %s\n", name);
    }
}

void searchByBirthYear(const Patient* patients, int patientCount, int year) {
    int found = 0;
    for (int i = 0; i < patientCount; i++) {
        if (patients[i].birthday.year == year) {
            if (!found) {
                printf("Tim thay benh nhan voi nam sinh %d:\n", year);
                printf("%-20s %-15s %-10s %-30s %-15s %-15s\n", "Ho va ten", "Ngay sinh", "Gioi tinh", "Dia chi", "So dien thoai", "Ma benh nhan");
                for (int i = 0; i < 105; i++) printf("-");
                printf("\n");
            }
            found = 1;
            printf("%-20s %02d/%02d/%4d   %-10s %-30s %-15s %-15s\n",
                   patients[i].patientName, patients[i].birthday.day, patients[i].birthday.month, patients[i].birthday.year,
                   patients[i].gender, patients[i].address, patients[i].phoneNumber, patients[i].patientID);
            for (int i = 0; i < 105; i++) printf("-");
            printf("\n");
        }
    }
    if (!found) {
        printf("Khong tim thay benh nhan voi nam sinh %d\n", year);
    }
}

void removePatientByID(Patient* patients, int* patientCount, const char* id) {
    int found = 0;
    for (int i = 0; i < *patientCount; i++) {
        if (strcmp(patients[i].patientID, id) == 0) {
            found = 1;
            for (int j = i; j < *patientCount - 1; j++) {
                patients[j] = patients[j + 1];
            }
            (*patientCount)--;
            printf("Da xoa benh nhan voi ma so %s\n", id);
            return;
        }
    }
    if (!found) {
        printf("Khong tim thay benh nhan voi ma so %s\n", id);
    }
}

int main() {
    Patient patients[100];
    int patientCount = 0;
    int choice;
    char input[100];
    int year;

    while (1) {
        printf("Menu:\n");
        printf("1. Them benh nhan\n");
        printf("2. Hien thi tat ca benh nhan\n");
        printf("3. Tim kiem benh nhan theo ten\n");
        printf("4. Tim kiem benh nhan theo nam sinh\n");
        printf("5. Xoa benh nhan theo ma so\n");
        printf("6. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);
        getchar(); // clear the buffer

        switch (choice) {
            case 1:
                addPatient(patients, &patientCount);
                break;
            case 2:
                displayPatients(patients, patientCount);
                break;
            case 3:
                printf("Nhap ten benh nhan can tim: ");
                fgets(input, 100, stdin);
                input[strcspn(input, "\n")] = '\0';
                searchByName(patients, patientCount, input);
                break;
            case 4:
                printf("Nhap nam sinh can tim: ");
                scanf("%d", &year);
                getchar(); // clear the buffer
                searchByBirthYear(patients, patientCount, year);
                break;
            case 5:
                printf("Nhap ma so benh nhan can xoa: ");
                fgets(input, 50, stdin);
                input[strcspn(input, "\n")] = '\0';
                removePatientByID(patients, &patientCount, input);
                break;
            case 6:
                printf("Thoat chuong trinh.\n");
                return 0;
            default:
                printf("Lua chon khong hop le. Vui long chon lai.\n");
                break;
        }
    }

    return 0;
}