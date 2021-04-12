#include "helpers.h"
#include "structs.h"
#include <iostream>

using namespace std;

void dataInitialization(clinicStruct &clinic) {
  clinic.address = "Calle Los Algoritmos #487, Pimentel";
  clinic.businessName = "La Clinica";
  clinic.ruc = "12345678910";

  /* pediatric area */

  medicalSpecialityStruct pediatric;
  pediatric.name = "Pediatría";
  pediatric.price = 400;

  medicalSpecialityNode pediatricNode;
  pediatricNode.medicalSpeciality = pediatric;
  pediatricNode.next = NULL;

  clinic.medicalSpecialities.firstNode = &pediatricNode;
  clinic.medicalSpecialities.length = 1;

  /* obstetrics area */

  medicalSpecialityStruct obstetrics;
}

void showMedicalSpeciality(medicalSpecialityStruct medicalSpeciality) {
  cout << medicalSpeciality.name << endl;
}
