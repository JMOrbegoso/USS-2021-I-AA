#include "structFunctions.h"

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

  cout << "Gracias por usar la app, tenga un buen d??a!";
}

// Menu functions

void showAppTitle(clinicStruct clinic) {
  cout << endl
       << "-----------------------------------------------------------" << endl;
  cout << "\t\t Sistema virtual de " << clinic.businessName << endl;
  cout << endl
       << "-----------------------------------------------------------" << endl;
  cout << "Direcci??n: " << clinic.address << endl;
  cout << "RUC: " << clinic.ruc << endl;
  cout << endl
       << "-----------------------------------------------------------" << endl;
}

void updateClinicProperties(clinicStruct &clinic) {

  string businessName, address, ruc;

  businessName =
      requestText("Ingrese el nuevo nombre de la instituci??n medica", 3);
  clinic.businessName = businessName;

  address =
      requestText("Ingrese la nueva direcci??n de la instituci??n medica", 5);
  clinic.address = address;

  ruc = requestText("Ingrese el RUC de la instituci??n medica:", 11, 11);
  clinic.ruc = ruc;

  cout << endl
       << "Los datos de la instituci??n medica han sido actualizados "
          "correctamente"
       << endl;
}

int requestMenuOption(clinicStruct clinic) {
  int selectedOption;

  clearScreen();
  showAppTitle(clinic);

  cout << endl << "Por favor seleccione la opci??n deseada:" << endl << endl;

  cout << "[1] Actualizar datos de la instituci??n medica" << endl;

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
    cout << "La opcion seleccionada fue inv??lida, por favor seleccione una "
            "opcion v??lida:"
         << endl;
    cin >> selectedOption;
  }
  return selectedOption;
}

// Menu options

void registerNewMedicalSpeciality(clinicStruct &clinic) {
  medicalSpecialityStruct newMedicalSpeciality;
  int id;
  string name;
  float price;

  cout << "Va a registrar una nueva especialidad medica" << endl << endl;

  id = requestNewMedicalSpecialityId(clinic);
  name = requestText("Ingrese el nombre de la nueva especialidad medica", 3);
  price = requestMoney(
      "Ingrese el precio de consulta de la nueva especialidad medica", 1);

  newMedicalSpeciality = buildMedicalSpeciality(id, name, price);

  addToCollection(clinic, newMedicalSpeciality);

  cout << "La especialidad medica ha sido registrada correctamente";
}

void showMedicalSpecialities(clinicStruct clinic) {
  clearScreen();
  showAppTitle(clinic);

  gotoxy(10, 10);
  cout << "Especialidades medicas en " << clinic.businessName << endl;

  medicalSpecialityNode *node = clinic.medicalSpecialities.firstNode;

  gotoxy(0, 12);
  cout << "#";
  gotoxy(5, 12);
  cout << "Id";
  gotoxy(20, 12);
  cout << "Nombre";
  gotoxy(40, 12);
  cout << "Precio";

  int i = 1;
  while (node != NULL) {
    showMedicalSpeciality(node->medicalSpeciality, i);
    node = node->next;
    i++;
  }

  cout << endl << endl;
}

void registerNewNurse(clinicStruct &clinic) {
  nurseStruct newNurse;
  int medicalRoomId;
  string firstName, lastName, dni;
  char genre;

  cout << "Va a registrar una nueva enfermera" << endl << endl;

  firstName = requestText("Ingrese el nombre de la nueva enfermera", 3);
  lastName = requestText("Ingrese el apellido de la nueva enfermera", 3);
  dni = requestText("Ingrese el DNI de la nueva enfermera", 8, 8);
  genre = requestGenre("Ingrese el genero de la nueva enfermera");
  medicalRoomId = requestMedicalRoomId(clinic);

  newNurse = buildNurse(firstName, lastName, dni, genre, medicalRoomId);

  addToCollection(clinic, newNurse);

  cout << "La enfermera ha sido registrada correctamente";
}

void showNurses(clinicStruct clinic) {
  clearScreen();
  showAppTitle(clinic);

  gotoxy(10, 10);
  cout << "Enfermeras en " << clinic.businessName << endl;

  nurseNode *node = clinic.nurses.firstNode;

  gotoxy(0, 12);
  cout << "#";
  gotoxy(5, 12);
  cout << "Nombres";
  gotoxy(20, 12);
  cout << "Apellidos";
  gotoxy(40, 12);
  cout << "DNI";
  gotoxy(50, 12);
  cout << "Genero";
  gotoxy(60, 12);
  cout << "Consultorio";

  int i = 1;
  while (node != NULL) {
    showNurse(clinic.medicalRooms, node->nurse, i);
    node = node->next;
    i++;
  }

  cout << endl << endl;
}

void registerNewMedicalPatient(clinicStruct &clinic) {
  medicalPatientStruct newMedicalPatient;
  int medicalRoomId;
  string firstName, lastName, dni, address, bornDate;
  char genre;

  cout << "Va a registrar un nuevo paciente" << endl << endl;

  firstName = requestText("Ingrese el nombre del nuevo paciente", 3);
  lastName = requestText("Ingrese el apellido del nuevo paciente", 3);
  dni = requestText("Ingrese el DNI del nuevo paciente", 8, 8);
  address = requestText("Ingrese la direcci??n del nuevo paciente", 5);
  bornDate = requestDate("Ingrese la fecha de nacimiento del nuevo paciente");
  genre = requestGenre("Ingrese el genero del nuevo paciente");
  medicalRoomId = requestMedicalRoomId(clinic);

  newMedicalPatient = buildMedicalPatient(firstName, lastName, dni, address,
                                          bornDate, genre, medicalRoomId);

  addToCollection(clinic, newMedicalPatient);

  cout << "El paciente ha sido registrado correctamente";
}

void showMedicalPatients(clinicStruct clinic) {
  clearScreen();
  showAppTitle(clinic);

  gotoxy(10, 10);
  cout << "Pacientes en " << clinic.businessName << endl;

  medicalPatientNode *node = clinic.medicalPatients.firstNode;

  gotoxy(0, 12);
  cout << "#";
  gotoxy(5, 12);
  cout << "Nombres";
  gotoxy(20, 12);
  cout << "Apellidos";
  gotoxy(35, 12);
  cout << "Direcci??n";
  gotoxy(55, 12);
  cout << "Fecha Nacimiento";
  gotoxy(75, 12);
  cout << "DNI";
  gotoxy(85, 12);
  cout << "Genero";
  gotoxy(98, 12);
  cout << "Consultorio";

  int i = 1;
  while (node != NULL) {
    showMedicalPatient(clinic.medicalRooms, node->medicalPatient, i);
    node = node->next;
    i++;
  }

  cout << endl << endl;
}

void registerNewMedic(clinicStruct &clinic) {
  medicStruct newMedic;
  int medicalSpecialityId;
  string firstName, lastName, phoneNumber, dni, address, code;
  float salary;
  char genre;

  cout << "Va a registrar un nuevo medico" << endl << endl;

  firstName = requestText("Ingrese el nombre del nuevo medico", 3);
  lastName = requestText("Ingrese el apellido del nuevo medico", 3);
  phoneNumber =
      requestText("Ingrese el numero telefonico del nuevo medico", 9, 9);
  dni = requestText("Ingrese el DNI del nuevo medico", 8, 8);
  address = requestText("Ingrese la direcci??n del nuevo medico", 5);
  code = requestText("Ingrese el codigo del nuevo medico", 2);
  salary = requestMoney("Ingrese el salario del nuevo medico", 100);
  genre = requestGenre("Ingrese el genero del nuevo medico");
  medicalSpecialityId = requestMedicalSpecialityId(clinic);

  newMedic = buildMedic(firstName, lastName, phoneNumber, dni, address, code,
                        salary, genre, medicalSpecialityId);

  addToCollection(clinic, newMedic);

  cout << "El medico ha sido registrado correctamente";
}

void showMedics(clinicStruct clinic) {
  clearScreen();
  showAppTitle(clinic);

  gotoxy(10, 10);
  cout << "Medicos en " << clinic.businessName << endl;

  medicNode *node = clinic.medics.firstNode;

  gotoxy(0, 12);
  cout << "#";
  gotoxy(5, 12);
  cout << "Nombres";
  gotoxy(20, 12);
  cout << "Apellidos";
  gotoxy(35, 12);
  cout << "Direcci??n";
  gotoxy(60, 12);
  cout << "Codigo";
  gotoxy(70, 12);
  cout << "DNI";
  gotoxy(80, 12);
  cout << "Genero";
  gotoxy(93, 12);
  cout << "Especialidad";
  gotoxy(108, 12);
  cout << "Salario";

  int i = 1;
  while (node != NULL) {
    showMedic(clinic.medicalSpecialities, node->medic, i);
    node = node->next;
    i++;
  }

  cout << endl << endl;
}

void registerNewMedicalRoom(clinicStruct &clinic) {
  medicalRoomStruct newMedicalRoom;
  int id, floor, medicalSpecialityId;
  string area, address, roomCode;

  cout << "Va a registrar un nuevo consultorio medico" << endl << endl;

  id = requestNewMedicalRoomId(clinic);
  area = requestText("Ingrese el area del nuevo consultorio medico", 3);
  area = requestText("Ingrese la direccion del nuevo consultorio medico", 3);
  floor =
      requestIntegerNumber("Ingrese el piso del nuevo consultorio medico", 1);
  roomCode = requestText("Ingrese el codigo del nuevo consultorio medico", 1);
  medicalSpecialityId = requestMedicalRoomId(clinic);

  newMedicalRoom =
      buildMedicalRoom(id, area, address, floor, roomCode, medicalSpecialityId);

  addToCollection(clinic, newMedicalRoom);

  cout << "El consultorio ha sido registrado correctamente";
}

void showMedicalRooms(clinicStruct clinic) {
  clearScreen();
  showAppTitle(clinic);

  gotoxy(10, 10);
  cout << "Consultorios en " << clinic.businessName << endl;

  medicalRoomNode *node = clinic.medicalRooms.firstNode;

  gotoxy(0, 12);
  cout << "#";
  gotoxy(5, 12);
  cout << "Codigo";
  gotoxy(20, 12);
  cout << "Piso";
  gotoxy(35, 12);
  cout << "Direcci??n";
  gotoxy(60, 12);
  cout << "Area";
  gotoxy(70, 12);
  cout << "Especialidad Medica";

  int i = 1;
  while (node != NULL) {
    showMedicalRoom(clinic.medicalSpecialities, node->medicalRoom, i);
    node = node->next;
    i++;
  }

  cout << endl << endl;
}

void registerNewReceptionist(clinicStruct &clinic) {
  receptionistStruct newReceptionist;
  int medicalSpecialityId;
  string firstName, lastName, dni;
  char genre;

  cout << "Va a registrar un nuevo consultorio medico" << endl << endl;

  firstName = requestText("Ingrese el nombre del nuevo recepcionista", 3);
  lastName = requestText("Ingrese el apellido del nuevo recepcionista", 3);
  dni = requestText("Ingrese el DNI del nuevo recepcionista", 8, 8);
  genre = requestGenre("Ingrese el genero del nuevo recepcionista");
  medicalSpecialityId = requestMedicalSpecialityId(clinic);

  newReceptionist =
      buildReceptionist(firstName, lastName, dni, genre, medicalSpecialityId);

  addToCollection(clinic, newReceptionist);

  cout << "El recepcionista ha sido registrado correctamente";
}

void showReceptionists(clinicStruct clinic) {
  clearScreen();
  showAppTitle(clinic);

  gotoxy(10, 10);
  cout << "Recepcionistas en " << clinic.businessName << endl;

  receptionistNode *node = clinic.receptionists.firstNode;

  gotoxy(0, 12);
  cout << "#";
  gotoxy(5, 12);
  cout << "Nombres";
  gotoxy(20, 12);
  cout << "Apellidos";
  gotoxy(35, 12);
  cout << "DNI";
  gotoxy(45, 12);
  cout << "Genero";
  gotoxy(55, 12);
  cout << "Especialidad";

  int i = 1;
  while (node != NULL) {
    showReceptionist(clinic.medicalSpecialities, node->receptionist, i);
    node = node->next;
    i++;
  }

  cout << endl << endl;
}
