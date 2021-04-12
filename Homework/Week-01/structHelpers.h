#include "helpers.h"
#include "structs.h"
#include <iostream>

using namespace std;

// Forward declarations
void collectionsInitialization(clinicStruct &clinic);

medicalSpecialityStruct buildMedicalSpecialityStruct(string name, float price);
nurseStruct buildNurse(string firstName, string lastName, string dni);
medicalPatientStruct buildMedicalPatient(string firstName, string lastName,
                                         string dni, string address,
                                         string bornDate);
medicalRoomStruct buildMedicalRoom(string area, string address, int floor,
                                   int roomNumber);
medicStruct buildMedic(string firstName, string lastName, string phoneNumber,
                       string dni, string address, string code, float salary);

void addNewMedicalSpeciality(clinicStruct &clinic,
                             medicalSpecialityStruct newMedicalSpeciality);
void addNewNurse(clinicStruct &clinic, nurseStruct newNurse);
void addNewMedicalPatient(clinicStruct &clinic,
                          medicalPatientStruct newMedicalPatient);

// Functions

void collectionsInitialization(clinicStruct &clinic) {
  clinic.medicalSpecialities.firstNode = NULL;
  clinic.medicalSpecialities.length = 0;

  clinic.nurses.firstNode = NULL;
  clinic.nurses.length = 0;

  clinic.medicalPatients.firstNode = NULL;
  clinic.medicalPatients.length = 0;
}

void dataInitialization(clinicStruct &clinic) {

  medicalSpecialityStruct pediatric;
  medicalSpecialityStruct obstetrics;

  clinic.address = "Calle Los Algoritmos #487, Pimentel";
  clinic.businessName = "La Clinica";
  clinic.ruc = "12345678910";

  pediatric = buildMedicalSpecialityStruct("Pediatría", 400);
  addNewMedicalSpeciality(clinic, pediatric);

  obstetrics = buildMedicalSpecialityStruct("Obstetricia", 300);
  addNewMedicalSpeciality(clinic, obstetrics);
}

medicalSpecialityStruct buildMedicalSpecialityStruct(string name, float price) {
  medicalSpecialityStruct newMedicalSpeciality;
  newMedicalSpeciality.name = name;
  newMedicalSpeciality.price = price;

  return newMedicalSpeciality;
}

nurseStruct buildNurse(string firstName, string lastName, string dni) {
  nurseStruct nurse;
  nurse.firstName = firstName;
  nurse.lastName = lastName;
  nurse.dni = dni;

  return nurse;
}

medicalPatientStruct buildMedicalPatient(string firstName, string lastName,
                                         string dni, string address,
                                         string bornDate) {
  medicalPatientStruct medicalPatient;
  medicalPatient.firstName = firstName;
  medicalPatient.lastName = lastName;
  medicalPatient.dni = dni;
  medicalPatient.address = address;
  medicalPatient.bornDate = bornDate;

  return medicalPatient;
}

medicalRoomStruct buildMedicalRoom(string area, string address, int floor,
                                   int roomNumber) {
  medicalRoomStruct medicalRoom;
  medicalRoom.area = area;
  medicalRoom.address = address;
  medicalRoom.floor = floor;
  medicalRoom.roomNumber = roomNumber;

  return medicalRoom;
}

medicStruct buildMedic(string firstName, string lastName, string phoneNumber,
                       string dni, string address, string code, float salary) {
  medicStruct medic;
  medic.firstName = firstName;
  medic.lastName = lastName;
  medic.phoneNumber = phoneNumber;
  medic.dni = dni;
  medic.address = address;
  medic.code = code;
  medic.salary = salary;

  return medic;
}

void addNewMedicalSpeciality(clinicStruct &clinic,
                             medicalSpecialityStruct newMedicalSpeciality) {
  medicalSpecialityNode *newNode = new medicalSpecialityNode();

  medicalSpecialityNode *lastNode = clinic.medicalSpecialities.firstNode;

  newNode->medicalSpeciality = newMedicalSpeciality;
  newNode->next = NULL;

  if (clinic.medicalSpecialities.firstNode == NULL) {
    clinic.medicalSpecialities.firstNode = newNode;
    return;
  }

  while (lastNode->next != NULL) {
    lastNode = lastNode->next;
  }

  lastNode->next = newNode;

  clinic.medicalSpecialities.length++;
}

void addNewNurse(clinicStruct &clinic, nurseStruct newNurse) {
  nurseNode *newNode = new nurseNode();

  nurseNode *lastNode = clinic.nurses.firstNode;

  newNode->nurse = newNurse;
  newNode->next = NULL;

  if (clinic.nurses.firstNode == NULL) {
    clinic.nurses.firstNode = newNode;
    return;
  }

  while (lastNode->next != NULL) {
    lastNode = lastNode->next;
  }

  lastNode->next = newNode;

  clinic.nurses.length++;
}

void addNewMedicalPatient(clinicStruct &clinic,
                          medicalPatientStruct newMedicalPatient) {
  medicalPatientNode *newNode = new medicalPatientNode();

  medicalPatientNode *lastNode = clinic.medicalPatients.firstNode;

  newNode->medicalPatient = newMedicalPatient;
  newNode->next = NULL;

  if (clinic.medicalPatients.firstNode == NULL) {
    clinic.medicalPatients.firstNode = newNode;
    return;
  }

  while (lastNode->next != NULL) {
    lastNode = lastNode->next;
  }

  lastNode->next = newNode;

  clinic.medicalPatients.length++;
}

void showMedicalSpeciality(medicalSpecialityStruct medicalSpeciality) {
  cout << medicalSpeciality.name << endl;
}
