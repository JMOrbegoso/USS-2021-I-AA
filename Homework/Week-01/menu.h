#include "structHelpers.h"

using namespace std;

#pragma region Forward declarations

void showAppTitle();
int requestMenuOption();

void registerNewMedicalSpeciality(clinic &clinic);
void showMedicalSpecialities(clinic &clinic);

void registerNewMedic();
void showMedics();

void registerNewMedicalRoom();
void showMedicalRooms();

void registerNewNurse();
void showNurses();

void registerNewMedicalPatient();
void showMedicalPatients();

#pragma endregion Forward declarations

void mainMenu() {

  int selectedOption;

  clinic clinic;

  dataInitialization(clinic);

  do {
    selectedOption = requestMenuOption();

    if (selectedOption != 0) {
      switch (selectedOption) {
      case 1:
        registerNewMedicalSpeciality(clinic);
        break;

      case 2:
        showMedicalSpecialities(clinic);
        break;

      case 3:
        registerNewMedic();
        break;

      case 4:
        showMedics();
        break;

      case 5:
        registerNewMedicalRoom();
        break;

      case 6:
        showMedicalRooms();
        break;

      case 7:
        registerNewNurse();
        break;

      case 8:
        showNurses();
        break;

      case 9:
        registerNewMedicalPatient();
        break;

      case 10:
        showMedicalPatients();
        break;
      }
    }
  } while (!(selectedOption == 0));

  cout << "Gracias por usar la app, tenga un buen día!";
}

#pragma region Menu functions

void showAppTitle() {
  cout << endl;
  cout << "-----------------------------------------------------------";
  cout << endl << "\t\t Sistema virtual de La Clínica" << endl << endl;
  cout << "-----------------------------------------------------------";
}

int requestMenuOption() {
  int selectedOption;

  clearScreen();
  showAppTitle();

  cout << endl << "Por favor seleccione la opción deseada:" << endl << endl;

  cout << "[1] Registrar nueva especialidad medica" << endl;
  cout << "[2] Ver la lista de especialidades medicas" << endl;

  cout << "[3] Registrar nuevo doctor" << endl;
  cout << "[4] Ver la lista de doctores" << endl;

  cout << "[5] Registrar nuevo consultorio" << endl;
  cout << "[6] Ver la lista de consultorios" << endl;

  cout << "[7] Registrar nueva enfermera" << endl;
  cout << "[8] Ver la lista de enfermeras" << endl;

  cout << "[9] Registrar nuevo paciente" << endl;
  cout << "[10] Ver la lista de pacientes" << endl;

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

#pragma endregion

#pragma region Menu options

void registerNewMedicalSpeciality(clinic &clinic) {
  cout << "placeholder: Register new medical speciality";
  addDelay(3);
}
void showMedicalSpecialities(clinic &clinic) {
  cout << "placeholder: Show medical specialities";
  pauseProcess();
}

void registerNewMedic() {
  cout << "placeholder: Register new medic";
  addDelay(3);
}
void showMedics() {
  cout << "placeholder: Show medics";
  pauseProcess();
}

void registerNewMedicalRoom() {
  cout << "placeholder: Register new medical rooms";
  addDelay(3);
}
void showMedicalRooms() {
  cout << "placeholder: Show medical rooms";
  pauseProcess();
}

void registerNewNurse() {
  cout << "placeholder: Register new nurse";
  addDelay(3);
}
void showNurses() {
  cout << "placeholder: Show nurses";
  pauseProcess();
}

void registerNewMedicalPatient() {
  cout << "placeholder: Register new medical patient";
  addDelay(3);
}
void showMedicalPatients() {
  cout << "placeholder: Show medical patients";
  pauseProcess();
}

#pragma endregion
