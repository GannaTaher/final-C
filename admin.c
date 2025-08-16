#include "admin.h"

Patient patients[MAX_PATIENTS];
int patientCount = 0;

Slot slots[MAX_SLOTS] = {
    {"2:00 PM - 2:30 PM", 0, -1},
    {"2:30 PM - 3:00 PM", 0, -1},
    {"3:00 PM - 3:30 PM", 0, -1},
    {"4:00 PM - 4:30 PM", 0, -1},
    {"4:30 PM - 5:00 PM", 0, -1}
};

void initSlots() {
    for (int i = 0; i < MAX_SLOTS; i++) {
        slots[i].reserved = 0;
        slots[i].patientID = -1;
    }
}

int isIdExists(int id) {
    for (int i = 0; i < patientCount; i++) {
        if (patients[i].id == id) return 1;
    }
    return 0;
}

void addPatient() {
    if (patientCount >= MAX_PATIENTS) {
        printf("Maximum patient limit reached.\n");
        return;
    }

    Patient newPatient;

    printf("Enter patient ID: ");
    scanf("%d", &newPatient.id);

    if (isIdExists(newPatient.id)) {
        printf("Error: ID already exists.\n");
        return;
    }

    printf("Enter patient name: ");
    scanf(" %[^\n]s", newPatient.name);
    printf("Enter patient age: ");
    scanf("%d", &newPatient.age);
    printf("Enter patient gender: ");
    scanf(" %[^\n]s", newPatient.gender);

    patients[patientCount++] = newPatient;
    printf("Patient added successfully!\n");
}

void editPatient() {
    int id;
    printf("Enter patient ID to edit: ");
    scanf("%d", &id);

    int index = -1;
    for (int i = 0; i < patientCount; i++) {
        if (patients[i].id == id) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Error: Invalid patient ID.\n");
        return;
    }

    printf("Editing record for %s\n", patients[index].name);

    printf("Enter new name: ");
    scanf(" %[^\n]s", patients[index].name);
    printf("Enter new age: ");
    scanf("%d", &patients[index].age);
    printf("Enter new gender: ");
    scanf(" %[^\n]s", patients[index].gender);

    printf("Patient record updated successfully.\n");
}

void reserveSlot() {
    int patientID, slotNum;

    printf("Available Slots:\n");
    for (int i = 0; i < MAX_SLOTS; i++) {
        if (!slots[i].reserved)
            printf("%d. %s\n", i + 1, slots[i].time);
    }

    printf("Enter patient ID: ");
    scanf("%d", &patientID);
    if (!isIdExists(patientID)) {
        printf("Error: Invalid patient ID.\n");
        return;
    }

    printf("Enter slot number (1-%d): ", MAX_SLOTS);
    scanf("%d", &slotNum);

    if (slotNum < 1 || slotNum > MAX_SLOTS) {
        printf("Invalid slot number.\n");
        return;
    }

    if (slots[slotNum - 1].reserved) {
        printf("This slot is already reserved.\n");
        return;
    }

    slots[slotNum - 1].reserved = 1;
    slots[slotNum - 1].patientID = patientID;
    printf("Slot reserved successfully.\n");
}

void cancelReservation() {
    int patientID;
    printf("Enter patient ID to cancel reservation: ");
    scanf("%d", &patientID);

    int found = 0;
    for (int i = 0; i < MAX_SLOTS; i++) {
        if (slots[i].patientID == patientID) {
            slots[i].reserved = 0;
            slots[i].patientID = -1;
            found = 1;
        }
    }

    if (found)
        printf("Reservation canceled successfully.\n");
    else
        printf("No reservation found for this patient ID.\n");
}

void viewPatientRecord() {
    int id;
    printf("Enter patient ID: ");
    scanf("%d", &id);

    for (int i = 0; i < patientCount; i++) {
        if (patients[i].id == id) {
            printf("Name: %s\n", patients[i].name);
            printf("Age: %d\n", patients[i].age);
            printf("Gender: %s\n", patients[i].gender);
            printf("ID: %d\n", patients[i].id);
            return;
        }
    }

    printf("Patient not found.\n");
}

void viewReservations() {
    printf("Today's Reservations:\n");
    for (int i = 0; i < MAX_SLOTS; i++) {
        printf("Slot %d (%s): ", i + 1, slots[i].time);
        if (slots[i].reserved && slots[i].patientID != -1)
            printf("Reserved for Patient ID %d\n", slots[i].patientID);
        else
            printf("Available\n");
    }
}
