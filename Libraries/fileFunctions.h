#ifndef FILE_FUNCTIONS_H
#define FILE_FUNCTIONS_H

#define MAX_PATH 100

/**
 * Funcion que carga los perfiles en el archivo con nombre "file_name", y retorna un mapa con los perfiles cargados, usando como
 * key el rut del perfil, y como data un typeProfile que guarda la info del perfil.
 *
 * @param file_name: nombre del archivo donde se sacaran los perfiles (admins.txt o clients.txt).
 * @return puntero al mapa recien creado con los perfiles cargados.
 */
Map *loadProfiles(char file_name[]);

/**
 * Procedimiento que guarda los perfiles cargados en el mapa "profiles", en el archivo de nombre "file_name".
 *
 * @param profiles: mapa de los perfiles cargados.
 * @param file_name: nombre del archivo en donde se guardara los perfiles.
 */
void saveProfiles(Map *profiles, char file_name[]);

/**
 * Funcion que carga la informacion del cliente, para ello entra a la carpeta del cliente usando su rut, y carga la informacion
 * del archivo "client-info.txt".
 *
 * @param rut: rut del cliente, se usa para entrar a la carpeta del cliente.
 * @return puntero a typeClient, con la informacion recien cargada.
 */
typeClient *loadClientInfo(char rut[]);

/**
 * Procedimiento que guarda la informacion de "client", en su carpeta correspondiente.
 *
 * @param client: registro de typeClient, que contiene la informacion del cliente a ser guardada.
 */
void saveClientInfo(typeClient *client);

/**
 * Funcion que carga los numeros de cuenta validos guardados del sistema.
 *
 * @return puntero al mapa creado con los numeros de cuenta cargados.
 */
Map *loadAccNumbers(void);

/**
 * Funcion que guarda los numeros de cuenta validos guardados del sistema.
 *
 * @param puntero al mapa con los numeros de cuenta cargados.
 */
void saveAccNumbers(Map *acc_numbers);

/**
 * Procedimiento que carga la informacion de una cuenta del cliente, para ello ingresa a la carpeta del cliente, y
 * dependiendo del tipo de cuenta a cargar (rut o de ahorro) ingresa a la carpeta de la cuenta correspondiente
 * y carga la informacion de los archivo de dicha carpeta.
 *
 * @param account: puntero a typeAccount que contiene la informacion de la cuenta.
 * @param rut: se usara para entrar en la carpeta del cliente.
 */
void loadAccount(typeAccount *account, char rut[], char account_type);

/**
 * Procedimiento que guarda la informacion de una cuenta del cliente, para ello ingresa a la carpeta del cliente, y
 * dependiendo del tipo de cuenta a guardar (rut o de ahorro) ingresa a la carpeta de la cuenta correspondiente
 * y guarda la informacion en los archivos correspondientes en dicha carpeta.
 *
 * @param account: puntero a typeAccount que contiene la informacion de la cuenta.
 * @param rut: se usara para entrar en la carpeta del cliente
 */
void saveAccount(typeAccount *account, char rut[]);

/**
 * Procedimiento que carga los avisos que tenga pendientes el cliente, para ello entra a la carpeta del cliente ingresado
 * y abre el archivo "notices.txt" y carga los avisos en la lista ingresada como parametro.
 *
 * @param client: puntero a typeClient que contiene la informacion del cliente.
 * @param list_notices: lista vacia que guardara los avisos recien cargados.
 */
void loadNotices(typeClient *client, List *list_notices);

/**
 * Procedimiento que guarda los avisos que tenga pendientes el cliente, para ello entra a la carpeta del cliente ingresado
 * y abre el archivo "notices.txt" y guarda los avisos de la lista ingresada como parametro.
 *
 * @param client: puntero a typeClient que contiene la informacion del cliente.
 * @param list_notices: lista que contiene los avisos a guardar.
 */
void saveNotices(typeClient *client, List *list_notices);

/**
  * Procedimiento que valida si el archivo "file" fue abierto correctamente, en caso contrario, imprime una advertencia y aborta
  * la ejecucion del programa
  *
  * @param file: puntero al archivo a analizar
  */
void validFileOpening(FILE *file);

/**
 * Procedimiento que carga la informacion (saldo y num de cuenta) de la cuenta en el archivo "acc-info.txt",
 * en la carpeta correspondiente.
 *
 * @param account: puntero que contiene la informacion de la cuenta a cargar
 * @param acc_path: cadena que contiene la ruta de la carpeta de la cuenta.
 */
void loadAccInfo(typeAccount *account, char acc_path[]);

/**
 * Procedimiento que guarda la informacion (saldo y num de cuenta) de la cuenta en el archivo "acc-info.txt",
 * en la carpeta correspondiente.
 *
 * @param account: puntero que contiene la informacion de la cuenta a guardar
 * @param acc_path: cadena que contiene la ruta de la carpeta de la cuenta.
 */
void saveAccInfo(typeAccount *account, char acc_path[]);

/**
 * Funcion que establece la ruta de la carpeta del cliente con el rut ingresado.
 *
 * @param rut: rut del cliente titular de la cuenta.
 * @return puntero a la cadena que contiene la ruta de la carpeta del cliente.
 */
char *setClientPath(char rut[]);

/**
 * Funcion que establece la ruta de la carpeta de la cuenta (account_type) del cliente con el rut ingresado.
 *
 * @param rut: rut del cliente titular de la cuenta.
 * @param account_type: tipo de cuenta a cargar.
 * @return puntero a la cadena que contiene la ruta de la carpeta de la cuenta.
 */
char *setAccPath(char rut[], char account_type);

#endif // FILE_FUNCTIONS_H
