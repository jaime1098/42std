/*1. Validación del Mapa
Abrir y leer el archivo del mapa (fd).
Lectura del Mapa:*/
/*Verificar la validez del formato del mapa.
Manejo de Errores:
Identificar y manejar posibles errores:
Falta de muros alrededor del mapa.
Camino bloqueado al destino o a los objetos.
Presencia de múltiples posiciones iniciales o de salida.
Caracteres inválidos en el mapa.

2. Creación Gráfica del Mapa
Implementar Representación Gráfica:
Utilizar miniLibX o una biblioteca gráfica similar para mostrar visualmente el mapa.
Asignar imágenes a los diferentes elementos del mapa (muros, objetos, posición inicial, salida).

3. Implementación del Juego
Crear Personaje Principal:
Diseñar gráficamente el personaje principal.
Asociar al personaje con la posición inicial (P) en el mapa.
Movimiento y Contador de Movimientos:
Permitir el movimiento del personaje principal con teclas (WASD).
Implementar un contador de movimientos.
Establecer Límites del Mapa:
Definir los límites del mapa (muros) para evitar que el personaje se mueva fuera de ellos.

4. Finalización del Juego
Condición de Finalización:
Agregar funcionalidad para terminar el juego:
Botón ESC o cierre de ventana (manejo de eventos).
Mensajes para victoria y derrota.
Reiniciar el juego o cerrar la ventana tras terminar.*/

#include "so_long.h"

void	check_limits(t_game *game)
{
	int i;

	i = 0;
	printf("\n%s\n", game->map[2]);
	while(i < game->cols)
	{
		if (game->map[0][i] != '1' || game->map[game->rows - 1][i] != '1')
			printf("\n%c\n", game->map[0][i]);
		i++;
	}
	i = 0;
	while (i < game->rows)
	{
		if (game->map[i][0] != '1' || game->map[i][game->cols - 2] != '1')
			printf("\nta mal\n");
		i++;
	}
}
void	check_map(t_game game)
{
	printf("\n%s\n", game.map[2]);
	check_limits(&game);
}
void	check_rows(t_game *game)
{
	char	*line;

	(*game).rows = 0;
	(*game).fd = open("map.ber", O_RDONLY);
	if ((*game).fd < 0)
		printf("Error opening file");
	while ((line = get_next_line((*game).fd)))
	{
		(*game).rows++;
		free(line);
	}
	close((*game).fd);
}
void	read_map(t_game *game)
{
	int 	i;
	int		j;
	char	*line;

	(*game).fd = open("map.ber", O_RDONLY);
	i = 0;
	line = get_next_line((*game).fd);
	while (line != NULL)
	{
		(*game).map[i] = line;
		printf("%s", (*game).map[i]);
		line = get_next_line((*game).fd);
		i++;
	}
	(*game).map[i] = NULL;
	(*game).cols = ft_strlen((*game).map[0] - 1);
	close((*game).fd);
}
int	main()
{
	t_game game;

	check_rows(&game);
	game.map = (char **)malloc((game.rows + 1) * sizeof(char *));
	read_map(&game);
	check_map(game);
	free(game.map);
	return (0);
}