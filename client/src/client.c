#include "client.h"
#include <commons/log.h>
#include <commons/config.h>
#include <readline/readline.h>

int main(void)
{
	/*---------------------------------------------------PARTE 2-------------------------------------------------------------*/
	int conexion;
	char* ip;
	char* puerto;
	char* valor;

	t_log* logger;
	t_config* config;

	logger = log_create("tp0.log","tp0",true,LOG_LEVEL_INFO);


	config = config_create("tp0.config");

	ip = config_get_string_value(config,"IP");
	puerto = config_get_string_value(config,"PUERTO");
	valor = config_get_string_value(config,"CLAVE");
	log_info(logger,ip);
	log_info(logger,puerto);
	log_info(logger,valor);
	// Usando el config creado previamente
	// Lee las variables de IP, Puerto y Valor

	//Loggear valor de config





	/*---------------------------------------------------PARTE 3-------------------------------------------------------------*/

	// Antes de continuar, tenemos que asegurarnos que el servidor esté corriendo porque lo necesitaremos para lo que sigue.

	// Creamos una conexión hacia el servidor
	conexion = crear_conexion(ip, puerto);
	log_info(logger,"me conecte al Servidor");

	enviar_mensaje(valor,conexion);

	leer_consola(logger,conexion);

	//enviar CLAVE al servidor
	terminar_programa(conexion, logger, config);

	/*---------------------------------------------------PARTE 5-------------------------------------------------------------*/
	// Proximamente
}

t_log* iniciar_logger(void)
{
	t_log* nuevo_logger;

	return nuevo_logger;
}

t_config* iniciar_config(void)
{
	t_config* nuevo_config;

	return nuevo_config;
}

void leer_consola(t_log* logger, int socket)
{
	char* leido;
	t_paquete* paquete;

	paquete = crear_paquete();
	while(1){
		//El primero te lo dejo de yapa
			leido = readline(">");
			if(strcmp(leido,"")==0){
				break;
			}
			log_info(logger,leido);
			agregar_a_paquete(paquete,leido,strlen(leido)+1);
	}
	enviar_paquete(paquete,socket);
	eliminar_paquete(paquete);
	// Acá la idea es que imprimas por el log lo que recibis de la consola.

	//free(1);
}

void paquete(int conexion)
{
	//Ahora toca lo divertido!

	char* leido;
	t_paquete* paquete;


}

void terminar_programa(int conexion, t_log* logger, t_config* config)
{
	t_paquete* paquete = crear_paquete();
	paquete->codigo_operacion =4;
	enviar_paquete(paquete,conexion);
	log_destroy(logger);
	config_destroy(config);
	close(conexion);
}
