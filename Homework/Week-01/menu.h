#include "structHelpers.h"

using namespace std;

// Forward declarations

void updateClinicProperties(clinicStruct &clinic);

void showAppTitle(clinicStruct clinic);
int requestMenuOption(clinicStruct clinic);

void registerNewMedicalSpeciality(clinicStruct &clinic);
void showMedicalSpecialities(clinicStruct clinic);

void registerNewNurse(clinicStruct &clinic);
void showNurses(clinicStruct clinic);

void registerNewMedicalPatient(clinicStruct &clinic);
void showMedicalPatients(clinicStruct clinic);

void registerNewMedic(clinicStruct &clinic);
void showMedics(clinicStruct clinic);

void registerNewMedicalRoom(clinicStruct &clinic);
void showMedicalRooms(clinicStruct clinic);

// Main menu function

void mainMenu(clinicStruct &clinic) {

  int selectedOption;

  do {
    selectedOption = requestMenuOption(clinic);

    if (selectedOption != 0) {
      switch (selectedOption) {
      case 1:
        updateClinicProperties(clinic);
        addDelay(3);
        break;

      case 2:
        registerNewMedicalSpeciality(clinic);
        addDelay(3);
        break;

      case 3:
        showMedicalSpecialities(clinic);
        pauseProcess();
        break;

      case 4:
        registerNewMedic(clinic);
        addDelay(3);
        break;

      case 5:
        showMedics(clinic);
        pauseProcess();
        break;

      case 6:
        registerNewMedicalRoom(clinic);
        addDelay(3);
        break;

      case 7:
        showMedicalRooms(clinic);
        pauseProcess();
        break;

      case 8:
        registerNewNurse(clinic);
        addDelay(3);
        break;

      case 9:
        showNurses(clinic);
        pauseProcess();
        break;

      case 10:
        registerNewMedicalPatient(clinic);
        addDelay(3);
        break;

      case 11:
        showMedicalPatients(clinic);
        pauseProcess();
        break;
      }
    }
  } while (!(selectedOption == 0));

  cout << "Gracias por usar la app, tenga un buen día!";
}

// Menu functions

void showAppTitle(clinicStruct clinic) {
  cout << endl
       << "-----------------------------------------------------------" << endl;
  cout << "\t\t Sistema virtual de " << clinic.businessName << endl;
  cout << endl
       << "-----------------------------------------------------------" << endl;
  cout << "Dirección: " << clinic.address << endl;
  cout << "RUC: " << clinic.ruc << endl;
  cout << endl
       << "-----------------------------------------------------------" << endl;
}

void updateClinicProperties(clinicStruct &clinic) {

  string businessName, address, ruc;

  businessName =
      requestText("Ingrese el nuevo nombre de la institución medica", 3);
  clinic.businessName = businessName;

  address =
      requestText("Ingrese la nueva dirección de la institución medica", 5);
  clinic.address = address;

  ruc = requestRUC();
  clinic.ruc = ruc;

  cout << endl
       << "Los datos de la institución medica han sido actualizados "
          "correctamente"
       << endl;
}

int requestMenuOption(clinicStruct clinic) {
  int selectedOption;

  clearScreen();
  showAppTitle(clinic);

  cout << endl << "Por favor seleccione la opción deseada:" << endl << endl;

  cout << "[1] Actualizar datos de la institución medica" << endl;

  cout << "[2] Registrar nueva especialidad medica" << endl;
  cout << "[3] Ver la lista de especialidades medicas" << endl;

  cout << "[4] Registrar nuevo doctor" << endl;
  cout << "[5] Ver la lista de doctores" << endl;

  cout << "[6] Registrar nuevo consultorio" << endl;
  cout << "[7] Ver la lista de consultorios" << endl;

  cout << "[8] Registrar nueva enfermera" << endl;
  cout << "[9] Ver la lista de enfermeras" << endl;

  cout << "[10] Registrar nuevo paciente" << endl;
  cout << "[11] Ver la lista de pacientes" << endl;

  cout << "[0] Cerrar" << endl;

  cout << endl << "Por favor ingrese una de las opciones:" << endl;
  cin >> selectedOption;
  while (!(0 <= selectedOption && selectedOption <= 10)) {
    cout << "La opcion seleccionada fue inválida, por favor seleccione una "
            "opcion válida:"
         << endl;
    cin >> selectedOption;
  }
  return selectedOption;
}

// Menu options

void registerNewMedicalSpeciality(clinicStruct &clinic) {
  medicalSpecialityStruct newMedicalSpeciality;
  string name;
  float price;

  cout << "Va a registrar una nueva especialidad medica" << endl << endl;

  name = requestText("Ingrese el nombre de la nueva especialidad medica", 3);
  price = requestMoney(
      "Ingrese el precio de consulta de la nueva especialidad medica", 1);

  newMedicalSpeciality = buildMedicalSpeciality(name, price);

  addNewMedicalSpeciality(clinic, newMedicalSpeciality);

  cout << "La especialidad medica ha sido registrada correctamente";
}

void showMedicalSpecialities(clinicStruct clinic) {
  cout << "Especialidades medicas en " << clinic.businessName << endl;

  medicalSpecialityNode *node = clinic.medicalSpecialities.firstNode;

  while (node != NULL) {
    showMedicalSpeciality(node->medicalSpeciality);
    node = node->next;
  }
}

void registerNewNurse(clinicStruct &clinic) {

  nurseStruct newNurse;
  string firstName, lastName, dni;

  cout << "Va a registrar una nueva enfermera" << endl << endl;

  firstName = requestText("Ingrese el nombre de la nueva enfermera", 3);
  lastName = requestText("Ingrese el apellido de la nueva enfermera", 3);
  dni = requestDNI();

  newNurse = buildNurse(firstName, lastName, dni);

  addNewNurse(clinic, newNurse);

  cout << "La especialidad medica ha sido registrada correctamente";
}

void showNurses(clinicStruct clinic) {
  cout << "Enfermeras en " << clinic.businessName << endl;

  nurseNode *node = clinic.nurses.firstNode;

  while (node != NULL) {
    showNurse(node->nurse);
    node = node->next;
  }
}

void registerNewMedicalPatient(clinicStruct &clinic) {

  medicalPatientStruct newMedicalPatient;
  string firstName, lastName, dni, address, bornDate;

  cout << "Va a registrar un nuevo paciente" << endl << endl;

  firstName = requestText("Ingrese el nombre del nuevo paciente", 3);
  lastName = requestText("Ingrese el apellido del nuevo paciente", 3);
  dni = requestDNI();
  address = requestText("Ingrese la dirección del nuevo paciente", 5);
  bornDate = requestDate();

  newMedicalPatient =
      buildMedicalPatient(firstName, lastName, dni, address, bornDate);

  addNewMedicalPatient(clinic, newMedicalPatient);

  cout << "La especialidad medica ha sido registrada correctamente";
}

void showMedicalPatients(clinicStruct clinic) {
  cout << "Pacientes en " << clinic.businessName << endl;

  medicalPatientNode *node = clinic.medicalPatients.firstNode;

  while (node != NULL) {
    showMedicalPatient(node->medicalPatient);
    node = node->next;
  }
}

void registerNewMedic(clinicStruct &clinic) {
  cout << "La especialidad medica ha sido registrada correctamente";
}

void showMedics(clinicStruct clinic) { cout << "placeholder: Show medics"; }

void registerNewMedicalRoom(clinicStruct &clinic) {
  cout << "La especialidad medica ha sido registrada correctamente";
}

void showMedicalRooms(clinicStruct clinic) {
  cout << "placeholder: Show medical rooms";
}
