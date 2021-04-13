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

void registerNewReceptionist(clinicStruct &clinic);
void showReceptionists(clinicStruct clinic);

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

      case 12:
        registerNewReceptionist(clinic);
        addDelay(3);
        break;

      case 13:
        showReceptionists(clinic);
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

  cout << "[12] Registrar nuevo recepcionista" << endl;
  cout << "[13] Ver la lista de recepcionistas" << endl;

  cout << "[0] Cerrar" << endl;

  cout << endl << "Por favor ingrese una de las opciones:" << endl;
  cin >> selectedOption;
  while (!(0 <= selectedOption && selectedOption <= 13)) {
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

  int i = 1;
  while (node != NULL) {
    showMedicalSpeciality(node->medicalSpeciality, i);
    node = node->next;
    i++;
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

  cout << "La enfermera ha sido registrada correctamente";
}

void showNurses(clinicStruct clinic) {
  cout << "Enfermeras en " << clinic.businessName << endl;

  nurseNode *node = clinic.nurses.firstNode;

  int i = 1;
  while (node != NULL) {
    showNurse(node->nurse, i);
    node = node->next;
    i++;
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

  cout << "El paciente ha sido registrado correctamente";
}

void showMedicalPatients(clinicStruct clinic) {
  cout << "Pacientes en " << clinic.businessName << endl;

  medicalPatientNode *node = clinic.medicalPatients.firstNode;

  int i = 1;
  while (node != NULL) {
    showMedicalPatient(node->medicalPatient, i);
    node = node->next;
    i++;
  }
}

void registerNewMedic(clinicStruct &clinic) {

  medicStruct newMedic;
  string firstName, lastName, phoneNumber, dni, address, code;
  float salary;

  cout << "Va a registrar un nuevo medico" << endl << endl;

  firstName = requestText("Ingrese el nombre del nuevo medico", 3);
  lastName = requestText("Ingrese el apellido del nuevo medico", 3);
  phoneNumber =
      requestText("Ingrese el numero telefonico del nuevo medico", 9, 9);
  dni = requestDNI();
  address = requestText("Ingrese la dirección del nuevo medico", 5);
  code = requestText("Ingrese el codigo del nuevo medico", 2);
  salary = requestMoney("Cual es el salario del nuevo medico", 100);

  newMedic =
      buildMedic(firstName, lastName, phoneNumber, dni, address, code, salary);

  addNewMedic(clinic, newMedic);

  cout << "El medico ha sido registrado correctamente";
}

void showMedics(clinicStruct clinic) {
  cout << "Medicos en " << clinic.businessName << endl;

  medicNode *node = clinic.medics.firstNode;

  int i = 1;
  while (node != NULL) {
    showMedic(node->medic, i);
    node = node->next;
    i++;
  }
}

void registerNewMedicalRoom(clinicStruct &clinic) {

  medicalRoomStruct newMedicalRoom;
  string area, address;
  int floor, roomNumber;

  cout << "Va a registrar un nuevo consultorio medico" << endl << endl;

  area = requestText("Ingrese el area del nuevo consultorio medico", 3);
  area = requestText("Ingrese la direccion del nuevo consultorio medico", 3);
  floor =
      requestIntegerNumber("Ingrese el piso del nuevo consultorio medico", 1);
  roomNumber =
      requestIntegerNumber("Ingrese el numero del nuevo consultorio medico", 1);

  newMedicalRoom = buildMedicalRoom(area, address, floor, roomNumber);

  addNewMedicalRoom(clinic, newMedicalRoom);

  cout << "El consultorio ha sido registrado correctamente";
}

void showMedicalRooms(clinicStruct clinic) {
  cout << "Consultorios en " << clinic.businessName << endl;

  medicalRoomNode *node = clinic.medicalRooms.firstNode;

  int i = 1;
  while (node != NULL) {
    showMedicalRoom(node->medicalRoom, i);
    node = node->next;
    i++;
  }
}

void registerNewReceptionist(clinicStruct &clinic) {

  receptionistStruct newReceptionist;
  string firstName, lastName, dni;

  cout << "Va a registrar un nuevo consultorio medico" << endl << endl;

  firstName = requestText("Ingrese el nombre del recepcionista", 3);
  lastName = requestText("Ingrese el apellido del recepcionista", 3);
  dni = requestDNI();

  newReceptionist = buildReceptionist(firstName, lastName, dni);

  addNewReceptionist(clinic, newReceptionist);

  cout << "El recepcionista ha sido registrado correctamente";
}

void showReceptionists(clinicStruct clinic) {
  cout << "Recepcionistas en " << clinic.businessName << endl;

  receptionistNode *node = clinic.receptionists.firstNode;

  int i = 1;
  while (node != NULL) {
    showReceptionist(node->receptionist, i);
    node = node->next;
    i++;
  }
}
