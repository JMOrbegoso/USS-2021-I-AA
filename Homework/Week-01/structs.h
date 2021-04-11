#include <iostream>

using namespace std;

/* Medic struct */

struct medic {
  string code;
  string fistName;
  string lastName;
  string address;
  string phoneNumber;
  float salary;
  string dni;
};

struct medicNode {
  medic medic;
  medicNode *next;
};

struct medicsList {
  medicNode *firstNode;
  int length;
};

/* Medical Room struct */

struct medicalRoom {
  int roomNumber;
  int floor;
  string address;
  string area;
};

struct medicalRoomNode {
  medicalRoom medicalRoom;
  medicalRoomNode *next;
};

struct medicalRoomsList {
  medicalRoomNode *firstNode;
  int length;
};

/* Medical Patient struct */

struct medicalPatient {
  string firstName;
  string lastName;
  string address;
  string bornDate;
  string dni;
};

struct medicalPatientNode {
  medicalPatient medicalPatient;
  medicalPatientNode *next;
};

struct medicalPatientsList {
  medicalPatientNode *firstNode;
  int length;
};

/* Nurse struct */

struct nurse {
  string firstName;
  string lastName;
  string dni;
};

struct nurseNode {
  nurse nurse;
  nurseNode *next;
};

struct nursesList {
  nurseNode *firstNode;
  int length;
};

/*

struct receptionist {
  string firstName;
  string lastName;
  string dni;
};

struct receptionistNode {
  receptionist receptionist;
  receptionistNode *receptionistNode;
};

struct receptionistsList {
  receptionistNode *firstNode;
  int length;
};
*/

/* Medical Speciality struct  */

struct medicalSpeciality {
  string name;
  float price;
  string employeeInChargeFirstName;
  string employeeInChargeLastName;
  medicsList medicsList;
  medicalRoomsList medicalRoomsList;
};

struct medicalSpecialityNode {
  medicalSpeciality medicalSpeciality;
  medicalSpecialityNode *next;
};

struct medicalSpecialitiesList {
  medicalSpecialityNode *firstNode;
  int length;
};

/* Clinic struct */

struct clinic {
  string businessName;
  string ruc;
  string address;
  medicalSpecialitiesList medicalSpecialitiesList;
  medicalPatientsList medicalPatientsList;
  nursesList nursesList;
};
