#include <stdio.h>

#include "admin.h"

void adminMode() {
    const int correctPassword = 1234;
    int attempts = 0;
    int password;

    while (attempts < 3) {
        printf("Enter password: ");
        scanf("%d", &password);

        if (password == correctPassword) {
            int choice;
            do {
                printf("\nAdmin Menu:\n");
                printf("1. Add New Patient\n");
                printf("2. Edit Patient Record\n");
                printf("3. Reserve a Slot\n");
                printf("4. Cancel Reservation\n");
                printf("5. Back to Main Menu\n");
                printf("Choose an option: ");
                scanf("%d", &choice);

                switch (choice) {
                    case 1: addPatient(); break;
                    case 2: editPatient(); break;
                    case 3: reserveSlot(); break;
                    case 4: cancelReservation(); break;
                    case 5: printf("Returning to main menu...\n"); break;
                    default: printf("Invalid option.\n");
                }
            } while (choice != 5);
            return;
        } else {
            attempts++;
            printf("Incorrect password. %d attempts left.\n", 3 - attempts);
        }
    }

    printf("Too many incorrect attempts. System closing.\n");
    exit(0);
}

void userMode() {
    int choice;
    do {
        printf("\nUser Menu:\n");
        printf("1. View Patient Record\n");
        printf("2. View Today's Reservations\n");
        printf("3. Back to Main Menu\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: viewPatientRecord(); break;
            case 2: viewReservations(); break;
            case 3: printf("Returning to main menu...\n"); break;
            default: printf("Invalid option.\n");
        }
    } while (choice != 3);
}

int main() {
    initSlots();

    int mode;
    do {
        printf("\nWelcome to Clinic Management System\n");
        printf("Select Mode:\n");
        printf("1. Admin Mode\n");
        printf("2. User Mode\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &mode);

        switch (mode) {
            case 1:
                adminMode();
                break;
            case 2:
                userMode();
                break;
            case 3:
                printf("Exiting the system. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (mode != 3);

    return 0;
}
