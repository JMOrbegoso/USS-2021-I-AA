#include <iostream>

using namespace std;

/* Medical Speciality struct  */

struct medicalSpecialityStruct {
  string name;
  float price;
};

struct medicalSpecialityNode {
  medicalSpecialityStruct medicalSpeciality;
  medicalSpecialityNode *next;
};

struct medicalSpecialitiesList {
  medicalSpecialityNode *firstNode;
  int length;
};

/* Medic struct */

struct medicStruct {
  string code;
  string firstName;
  string lastName;
  string address;
  string phoneNumber;
  float salary;
  string dni;
};

struct medicNode {
  medicStruct medic;
  medicNode *next;
};

struct medicsList {
  medicNode *firstNode;
  int length;
};

/* Medical Room struct */

struct medicalRoomStruct {
  int roomNumber;
  int floor;
  string address;
  string area;
};

struct medicalRoomNode {
  medicalRoomStruct medicalRoom;
  medicalRoomNode *next;
};

struct medicalRoomsList {
  medicalRoomNode *firstNode;
  int length;
};

/* receptionist struct */

struct receptionistStruct {
  string firstName;
  string lastName;
  string dni;
};

struct receptionistNode {
  receptionistStruct receptionist;
  receptionistNode *next;
};

struct receptionistsList {
  receptionistNode *firstNode;
  int length;
};

/* Nurse struct */

struct nurseStruct {
  string firstName;
  string lastName;
  string dni;
};

struct nurseNode {
  nurseStruct nurse;
  nurseNode *next;
};

struct nursesList {
  nurseNode *firstNode;
  int length;
};

/* Medical Patient struct */

struct medicalPatientStruct {
  string firstName;
  string lastName;
  string address;
  string bornDate;
  string dni;
};

struct medicalPatientNode {
  medicalPatientStruct medicalPatient;
  medicalPatientNode *next;
};

struct medicalPatientsList {
  medicalPatientNode *firstNode;
  int length;
};

/* Clinic struct */

struct clinicStruct {
  string businessName;
  string ruc;
  string address;
  medicalSpecialitiesList medicalSpecialities;
  nursesList nurses;
  medicalPatientsList medicalPatients;
  medicsList medics;
  medicalRoomsList medicalRooms;
  receptionistsList receptionists;
};
