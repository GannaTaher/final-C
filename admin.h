#ifndef ADMIN_H
#define ADMIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PATIENTS 100                           // Maximum patient that can be record to clinc
#define MAX_SLOTS 5                                // Just 5 solts to reserve 

typedef struct {                                  
    char name[50];                              
    int age;                                      // A struct for Patient and store their info
    char gender[10];
    int id;
} Patient;

typedef struct {
    char time[20];
    int reserved;                               // A struct for Slots that is store for reserve and cancel
    int patientID;      
} Slot;

// Global variable  for maximum patient and slots
extern Patient patients[MAX_PATIENTS];        
extern int patientCount;
extern Slot slots[MAX_SLOTS];

void initSlots();                        // initalize slots that reserved by ID of patient
void adminMode();                       // A function to call Admin mode and display his option by enter correct password
void userMode();                        // A function to call User mode and display his option

// Admin Mode
void addPatient();                     // An option of Admin that take a new patient  1- name 2-age 3- gender 4- ID
void editPatient();                    //An option of Admin  that edit info of patient by check his ID  
void reserveSlot();                    //An option of Admin that take ID of patient to reserve solt and check if it is available
void cancelReservation();              //An option of Admin that take ID of patient to cancel his solt that has been reserved 

// User Mode
void viewPatientRecord();             //An option of User that take ID to show info of this ID
void viewReservations();              //An option of User that take ID to show solt of this ID

#endif
