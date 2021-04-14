#include "helpers.h"
#include "structs.h"
#include <iostream>

using namespace std;

// Forward declarations

void collectionsInitialization(clinicStruct &clinic);

medicalSpecialityStruct buildMedicalSpeciality(int medicalSpecialityId,
                                               string name, float price);
nurseStruct buildNurse(string firstName, string lastName, string dni,
                       char genre, int medicalRoomId);
medicalPatientStruct buildMedicalPatient(string firstName, string lastName,
                                         string dni, string address,
                                         string bornDate, char genre,
                                         int medicalRoomId);
medicalRoomStruct buildMedicalRoom(int medicalRoomId, string area,
                                   string address, int floor, string roomCode,
                                   int medicalSpecialityId);
medicStruct buildMedic(string firstName, string lastName, string phoneNumber,
                       string dni, string address, string code, float salary,
                       char genre, int medicalSpecialityId);
receptionistStruct buildReceptionist(string firstName, string lastName,
                                     string dni, char genre,
                                     int medicalSpecialityId);

void addToCollection(clinicStruct &clinic,
                     medicalSpecialityStruct newMedicalSpeciality);
void addToCollection(clinicStruct &clinic, nurseStruct newNurse);
void addToCollection(clinicStruct &clinic,
                     medicalPatientStruct newMedicalPatient);
void addToCollection(clinicStruct &clinic, medicStruct newMedic);
void addToCollection(clinicStruct &clinic, medicalRoomStruct newMedicalRoom);
void addToCollection(clinicStruct &clinic, receptionistStruct newReceptionist);

// Functions

void collectionsInitialization(clinicStruct &clinic) {
  clinic.medicalSpecialities.firstNode = NULL;
  clinic.medicalSpecialities.length = 0;

  clinic.nurses.firstNode = NULL;
  clinic.nurses.length = 0;

  clinic.medicalPatients.firstNode = NULL;
  clinic.medicalPatients.length = 0;

  clinic.medics.firstNode = NULL;
  clinic.medics.length = 0;

  clinic.medicalRooms.firstNode = NULL;
  clinic.medicalRooms.length = 0;

  clinic.receptionists.firstNode = NULL;
  clinic.receptionists.length = 0;
}

void dataInitialization(clinicStruct &clinic) {

  medicalSpecialityStruct pediatric;
  medicalSpecialityStruct obstetrics;

  nurseStruct nurse_1;
  nurseStruct nurse_2;
  nurseStruct nurse_3;

  medicalPatientStruct patient_1;
  medicalPatientStruct patient_2;
  medicalPatientStruct patient_3;

  medicStruct medic_1;
  medicStruct medic_2;

  medicalRoomStruct medicalRoom_1;
  medicalRoomStruct medicalRoom_2;

  receptionistStruct receptionist_1;
  receptionistStruct receptionist_2;

  clinic.address = "Calle Los Algoritmos #487, Pimentel";
  clinic.businessName = "La Clinica";
  clinic.ruc = "12345678910";

  pediatric = buildMedicalSpeciality(1, "Pediatría", 400);
  obstetrics = buildMedicalSpeciality(2, "Obstetricia", 300);

  addToCollection(clinic, pediatric);
  addToCollection(clinic, obstetrics);

  medicalRoom_1 =
      buildMedicalRoom(1, "A-1", "Av. Algoritmos #200", 2, "A-200", 1);
  medicalRoom_2 =
      buildMedicalRoom(2, "A-2", "Av. Algoritmos #200", 3, "A-300", 2);

  addToCollection(clinic, medicalRoom_1);
  addToCollection(clinic, medicalRoom_2);

  medic_1 = buildMedic("Alfredo", "Lamadrid", "961111111", "15423268",
                       "Av. Algoritmos #111", "AC-111", 4000, 'm', 1);
  medic_2 = buildMedic("Monserrat", "Torrent", "962222222", "32657814",
                       "Av. Algoritmos #222", "AC-222", 3600, 'f', 2);

  addToCollection(clinic, medic_1);
  addToCollection(clinic, medic_2);

  receptionist_1 = buildReceptionist("Ramon", "Riveiro", "12454658", 'm', 1);
  receptionist_2 = buildReceptionist("Ciro", "Alegria", "45457896", 'm', 2);

  addToCollection(clinic, receptionist_1);
  addToCollection(clinic, receptionist_2);

  nurse_1 = buildNurse("Maria", "Rosas", "11111111", 'f', 1);
  nurse_2 = buildNurse("Julia", "Gomez", "22222222", 'f', 1);
  nurse_3 = buildNurse("Clara", "Garcia", "33333333", 'f', 2);

  addToCollection(clinic, nurse_1);
  addToCollection(clinic, nurse_2);
  addToCollection(clinic, nurse_3);

  patient_1 = buildMedicalPatient("Julio", "Rojas", "44444444",
                                  "Av. Las Condes #444", "1980-01-01", 'm', 1);
  patient_2 =
      buildMedicalPatient("Tulio", "Martinez", "55555555",
                          "Av. Los Geranios #444", "1981-01-01", 'm', 1);
  patient_3 =
      buildMedicalPatient("Ramon", "Gonzales", "66666666",
                          "Av. Las Petunias #444", "1982-01-01", 'm', 2);

  addToCollection(clinic, patient_1);
  addToCollection(clinic, patient_2);
  addToCollection(clinic, patient_3);
}

bool checkIfIdExist(medicalSpecialitiesList medicalSpecialities, int id) {
  medicalSpecialityNode *node = medicalSpecialities.firstNode;

  while (node != NULL) {
    if (node->medicalSpeciality.id == id)
      return true;

    node = node->next;
  }
  return false;
}

bool checkIfIdExist(medicalRoomsList medicalRooms, int id) {
  medicalRoomNode *node = medicalRooms.firstNode;

  while (node != NULL) {
    if (node->medicalRoom.id == id)
      return true;

    node = node->next;
  }
  return false;
}

int requestMedicalSpecialityId(clinicStruct clinic) {
  int selectedOption;
  int validOptions[100];
  int i = 0;

  medicalSpecialityNode *node = clinic.medicalSpecialities.firstNode;

  cout << endl << "Escoja una especializacion medica:" << endl << endl;

  while (node != NULL) {
    cout << "[" << i << "] - " << node->medicalSpeciality.name << endl;
    validOptions[i] = node->medicalSpeciality.id;
    node = node->next;
    i++;
  }

  cout << endl << "Introduzca la opción deseada:" << endl;

  do {
    cin >> selectedOption;
  } while (!contains(validOptions, i, selectedOption));

  return validOptions[selectedOption];
}

int requestMedicalRoomId(clinicStruct clinic) {
  int selectedOption;
  int validOptions[100];
  int i = 0;

  medicalRoomNode *node = clinic.medicalRooms.firstNode;

  cout << endl << "Escoja un consultorio:" << endl << endl;

  while (node != NULL) {
    cout << "[" << i << "] - " << node->medicalRoom.roomCode << endl;
    validOptions[i] = node->medicalRoom.id;
    node = node->next;
    i++;
  }

  cout << endl << "Introduzca la opción deseada:" << endl;

  do {
    cin >> selectedOption;
  } while (!contains(validOptions, i, selectedOption));

  return validOptions[selectedOption];
}

int requestNewMedicalSpecialityId(clinicStruct clinic) {
  int id;
  do {
    id = requestIntegerNumber("Ingrese el Id de la nueva especialidad medica, "
                              "este no debe de estar repetido",
                              1);
  } while (checkIfIdExist(clinic.medicalSpecialities, id));
  return id;
}

int requestNewMedicalRoomId(clinicStruct clinic) {
  int id;
  do {
    id = requestIntegerNumber("Ingrese el Id del nuevo consultorio medico, "
                              "este no debe de estar repetido",
                              1);
  } while (checkIfIdExist(clinic.medicalRooms, id));
  return id;
}

medicalSpecialityStruct buildMedicalSpeciality(int medicalSpecialityId,
                                               string name, float price) {
  medicalSpecialityStruct medicalSpeciality;
  medicalSpeciality.id = medicalSpecialityId;
  medicalSpeciality.name = name;
  medicalSpeciality.price = price;

  return medicalSpeciality;
}

nurseStruct buildNurse(string firstName, string lastName, string dni,
                       char genre, int medicalRoomId) {
  nurseStruct nurse;
  nurse.firstName = firstName;
  nurse.lastName = lastName;
  nurse.dni = dni;
  nurse.genre = genre;
  nurse.medicalRoomId = medicalRoomId;

  return nurse;
}

medicalPatientStruct buildMedicalPatient(string firstName, string lastName,
                                         string dni, string address,
                                         string bornDate, char genre,
                                         int medicalRoomId) {
  medicalPatientStruct medicalPatient;
  medicalPatient.firstName = firstName;
  medicalPatient.lastName = lastName;
  medicalPatient.dni = dni;
  medicalPatient.address = address;
  medicalPatient.bornDate = bornDate;
  medicalPatient.genre = genre;
  medicalPatient.medicalRoomId = medicalRoomId;

  return medicalPatient;
}

medicalRoomStruct buildMedicalRoom(int medicalRoomId, string area,
                                   string address, int floor, string roomCode,
                                   int medicalSpecialityId) {
  medicalRoomStruct medicalRoom;
  medicalRoom.id = medicalRoomId;
  medicalRoom.area = area;
  medicalRoom.address = address;
  medicalRoom.floor = floor;
  medicalRoom.roomCode = roomCode;
  medicalRoom.medicalSpecialityId = medicalSpecialityId;

  return medicalRoom;
}

medicStruct buildMedic(string firstName, string lastName, string phoneNumber,
                       string dni, string address, string code, float salary,
                       char genre, int medicalSpecialityId) {
  medicStruct medic;
  medic.firstName = firstName;
  medic.lastName = lastName;
  medic.phoneNumber = phoneNumber;
  medic.dni = dni;
  medic.address = address;
  medic.code = code;
  medic.salary = salary;
  medic.genre = genre;
  medic.medicalSpecialityId = medicalSpecialityId;

  return medic;
}

receptionistStruct buildReceptionist(string firstName, string lastName,
                                     string dni, char genre,
                                     int medicalSpecialityId) {
  receptionistStruct receptionist;
  receptionist.firstName = firstName;
  receptionist.lastName = lastName;
  receptionist.dni = dni;
  receptionist.medicalSpecialityId = medicalSpecialityId;
  receptionist.genre = genre;

  return receptionist;
}

void addToCollection(clinicStruct &clinic,
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

void addToCollection(clinicStruct &clinic, nurseStruct newNurse) {
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

void addToCollection(clinicStruct &clinic,
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

void addToCollection(clinicStruct &clinic, medicStruct newMedic) {
  medicNode *newNode = new medicNode();

  medicNode *lastNode = clinic.medics.firstNode;

  newNode->medic = newMedic;
  newNode->next = NULL;

  if (clinic.medics.firstNode == NULL) {
    clinic.medics.firstNode = newNode;
    return;
  }

  while (lastNode->next != NULL) {
    lastNode = lastNode->next;
  }

  lastNode->next = newNode;

  clinic.medics.length++;
}

void addToCollection(clinicStruct &clinic, medicalRoomStruct newMedicalRoom) {
  medicalRoomNode *newNode = new medicalRoomNode();

  medicalRoomNode *lastNode = clinic.medicalRooms.firstNode;

  newNode->medicalRoom = newMedicalRoom;
  newNode->next = NULL;

  if (clinic.medicalRooms.firstNode == NULL) {
    clinic.medicalRooms.firstNode = newNode;
    return;
  }

  while (lastNode->next != NULL) {
    lastNode = lastNode->next;
  }

  lastNode->next = newNode;

  clinic.medicalRooms.length++;
}

void addToCollection(clinicStruct &clinic, receptionistStruct newReceptionist) {
  receptionistNode *newNode = new receptionistNode();

  receptionistNode *lastNode = clinic.receptionists.firstNode;

  newNode->receptionist = newReceptionist;
  newNode->next = NULL;

  if (clinic.receptionists.firstNode == NULL) {
    clinic.receptionists.firstNode = newNode;
    return;
  }

  while (lastNode->next != NULL) {
    lastNode = lastNode->next;
  }

  lastNode->next = newNode;

  clinic.receptionists.length++;
}

void showMedicalSpeciality(medicalSpecialityStruct medicalSpeciality, int i) {
  cout << "#" << i << "-" << medicalSpeciality.name << "|"
       << medicalSpeciality.price << endl;
}

void showNurse(nurseStruct nurse, int i) {
  cout << "#" << i << "-" << nurse.firstName << "|" << nurse.lastName << endl;
}

void showMedicalPatient(medicalPatientStruct medicalPatient, int i) {
  cout << "#" << i << "-" << medicalPatient.firstName << endl;
}

void showMedicalRoom(medicalRoomStruct medicalRoom, int i) {
  cout << "#" << i << "-" << medicalRoom.address << endl;
}

void showMedic(medicStruct medic, int i) {
  cout << "#" << i << "-" << medic.firstName << " |" << medic.lastName << endl;
}

void showReceptionist(receptionistStruct receptionist, int i) {
  cout << "#" << i << "-" << receptionist.firstName << "|"
       << receptionist.lastName << "|" << receptionist.dni << endl;
}

string getMedicalSpecialityName(clinicStruct clinic, int medicalSpecialityId) {
  medicalSpecialityNode *node = clinic.medicalSpecialities.firstNode;

  while (node != NULL) {
    if (node->medicalSpeciality.id == medicalSpecialityId)
      return node->medicalSpeciality.name;

    node = node->next;
  }
  return "ERROR";
}

string getMedicalRoomNumber(clinicStruct clinic, int medicalRoomId) {
  medicalRoomNode *node = clinic.medicalRooms.firstNode;

  while (node != NULL) {
    if (node->medicalRoom.id == medicalRoomId)
      return node->medicalRoom.roomCode;

    node = node->next;
  }
  return "ERROR";
}
