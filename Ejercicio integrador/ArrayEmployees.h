typedef struct
{
    int idMenu;
    char menu[51];
    float importe;
}eMenu;

typedef struct
{
    int dia,mes,anio;
}eFecha;

typedef struct
{
  int id;
  char nombre[51];
  char apellido[51];
  char sexo;
  float salario;
  eFecha fechaIng;
  int isEmpty;
  int sector;

}eEmployee;

typedef struct
{
    int id;
    int idMenu;
    int idEmpleado;
    eFecha fechaAlm;

}eAlmuerzo;

typedef struct
{
    int id;
    char desc[51];

}eSector;

int initEmployees(eEmployee *emp, int len);

int addEmployee(eEmployee *emp, int len, eSector *auxSector, int lenSector);
int removeEmployee(eEmployee *emp,int len ,eSector *sec, int lenSec );
void modifyEmployee(eEmployee *emp,int len, eSector *sec, int lenSector);





void printSector(eSector sec[], int len);
void printEmployee(eEmployee emp,eSector sec[], int lenSec, int formato);
void printAllEmployees(eEmployee listE[], int len, eSector listS[], int lenSector);
void sortEmployee(eEmployee emp[], int len, int order);
void calculateSalaryInfo(eEmployee emp[], int len);
int findEmptyPlace (eEmployee emp[], int len);
int findEmployeeById(eEmployee emp[], int len, int id);
