#include "structHelpers.h"

using namespace std;

// Forward declarations

void updateClinicProperties(clinic &clinic);

void showAppTitle(clinic clinic);
int requestMenuOption(clinic clinic);

void registerNewMedicalSpeciality(clinic &clinic);
void showMedicalSpecialities(clinic clinic);

void registerNewMedic();
void showMedics();

void registerNewMedicalRoom();
void showMedicalRooms();

void registerNewNurse();
void showNurses();

void registerNewMedicalPatient();
void showMedicalPatients();

// Main menu function

void mainMenu(clinic &clinic) {

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
        registerNewMedic();
        addDelay(3);
        break;

      case 5:
        showMedics();
        pauseProcess();
        break;

      case 6:
        registerNewMedicalRoom();
        addDelay(3);
        break;

      case 7:
        showMedicalRooms();
        pauseProcess();
        break;

      case 8:
        registerNewNurse();
        addDelay(3);
        break;

      case 9:
        showNurses();
        pauseProcess();
        break;

      case 10:
        registerNewMedicalPatient();
        addDelay(3);
        break;

      case 11:
        showMedicalPatients();
        pauseProcess();
        break;
      }
    }
  } while (!(selectedOption == 0));

  cout << "Gracias por usar la app, tenga un buen día!";
}

// Menu functions

void showAppTitle(clinic clinic) {
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

void updateClinicProperties(clinic &clinic) {

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

int requestMenuOption(clinic clinic) {
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

void registerNewMedicalSpeciality(clinic &clinic) {
  cout << "placeholder: Register new medical speciality";
}
void showMedicalSpecialities(clinic clinic) {
  cout << "Especialidades medicas en La Clinica" << endl;

  medicalSpecialityNode *node = clinic.medicalSpecialitiesList.firstNode;

  while (node != NULL) {
    showMedicalSpeciality(node->medicalSpeciality);
    node = node->next;
  }
}

void registerNewMedic() { cout << "placeholder: Register new medic"; }
void showMedics() { cout << "placeholder: Show medics"; }

void registerNewMedicalRoom() {
  cout << "placeholder: Register new medical rooms";
}
void showMedicalRooms() { cout << "placeholder: Show medical rooms"; }

void registerNewNurse() { cout << "placeholder: Register new nurse"; }
void showNurses() { cout << "placeholder: Show nurses"; }

void registerNewMedicalPatient() {
  cout << "placeholder: Register new medical patient";
}
void showMedicalPatients() { cout << "placeholder: Show medical patients"; }
