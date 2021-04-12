#include "helpers.h"
#include "structs.h"
#include <iostream>

using namespace std;

// Forward declarations
void collectionsInitialization(clinicStruct &clinic);
medicalSpecialityStruct buildMedicalSpecialityStruct(string name, float price);
void addNewMedicalSpeciality(clinicStruct &clinic,
                             medicalSpecialityStruct newMedicalSpeciality);

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

void showMedicalSpeciality(medicalSpecialityStruct medicalSpeciality) {
  cout << medicalSpeciality.name << endl;
}
