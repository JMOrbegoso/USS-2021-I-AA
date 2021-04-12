#include "helpers.h"
#include "structs.h"
#include <iostream>

using namespace std;

void dataInitialization(clinic &clinic) {
  clinic.address = "Calle Los Algoritmos #487, Pimentel";
  clinic.businessName = "La Clinica";
  clinic.ruc = "12345678910";

  /* pediatric area */

  medicalSpeciality pediatric;
  pediatric.name = "Pediatría";
  pediatric.price = 400;

  medicalSpecialityNode pediatricNode;
  pediatricNode.medicalSpeciality = pediatric;
  pediatricNode.next = NULL;

  clinic.medicalSpecialitiesList.firstNode = &pediatricNode;
  clinic.medicalSpecialitiesList.length = 1;

  /* obstetrics area */

  medicalSpeciality obstetrics;
}

void showMedicalSpeciality(medicalSpeciality medicalSpeciality) {
  cout << medicalSpeciality.name << endl;
}
