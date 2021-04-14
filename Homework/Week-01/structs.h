#include <iostream>

using namespace std;

/* Medical Speciality struct  */

struct medicalSpecialityStruct {
  int id;
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
  char genre;
  int medicalSpecialityId;
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
  int id;
  int roomNumber;
  int floor;
  string address;
  string area;
  int medicalSpecialityId;
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
  char genre;
  int medicalSpecialityId;
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
  char genre;
  int medicalRoomId;
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
  char genre;
  int medicalRoomId;
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
