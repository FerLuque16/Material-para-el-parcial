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
  int legajo;
  char nombre[51];
  char apellido[51];
  char sexo;
  float salario;
  eFecha fechaIng;
  int isEmpty;
  int idSector;

}eEmpleado;

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

void alta(eEmpleado emp[],int cantidad);

void mostrarUno(eEmpleado emp);

void mostrarTodos(eEmpleado emp[],int cantidad);

void mostrar(eEmpleado emp[],int cantidad);

void ordenar(eEmpleado emp[],int cantidad);

void init(eEmpleado emp[],int cantidad);

void baja(eEmpleado emp[],int cantidad);

void modificar(eEmpleado emp[],int cantidad);

void mostrarSector(eEmpleado emp[],int cantidadEmp,eSector[],int cantidadSec);

//static int generarId(void);

