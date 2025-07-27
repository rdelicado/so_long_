# so_long - 2D Game Engine

![42 School Project](https://img.shields.io/badge/42-Project-4285F4?style=for-the-badge&logo=42&logoColor=white)
![C](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white)
![OpenGL](https://img.shields.io/badge/OpenGL-FFFFFF?style=for-the-badge&logo=opengl)
![Grade](https://img.shields.io/badge/Grade-125%2F100-brightgreen?style=for-the-badge)

## 📋 Índice

- [Descripción del Proyecto](#-descripción-del-proyecto)
- [Características del Juego](#-características-del-juego)
- [Especificaciones Técnicas](#-especificaciones-técnicas)
- [Arquitectura del Proyecto](#-arquitectura-del-proyecto)
- [Instalación y Compilación](#-instalación-y-compilación)
- [Uso y Controles](#-uso-y-controles)
- [Sistema de Mapas](#-sistema-de-mapas)
- [Algoritmos Implementados](#-algoritmos-implementados)
- [Gestión Gráfica](#-gestión-gráfica)
- [Testing y Debugging](#-testing-y-debugging)
- [Objetivos de Aprendizaje](#-objetivos-de-aprendizaje)

## 🎯 Descripción del Proyecto

**so_long** es un juego 2D desarrollado en C utilizando la librería gráfica **MLX42**. Este proyecto forma parte del currículo de **42 School** y representa una introducción completa al desarrollo de videojuegos, programación gráfica y gestión de eventos en tiempo real.

### Concepto del Juego

El jugador controla a un personaje que debe:
- **Recoger todos los coleccionables** distribuidos por el mapa
- **Encontrar la salida** para completar el nivel
- **Navegar por laberintos** evitando paredes
- **Optimizar los movimientos** para completar el objetivo

### Contexto Académico

Este proyecto introduce conceptos fundamentales de:
- **Programación gráfica** con OpenGL/MLX42
- **Gestión de eventos** de teclado y ventana
- **Algoritmos de pathfinding** y validación de mapas
- **Gestión de memoria** en aplicaciones gráficas
- **Arquitectura de videojuegos** modular

## 🎮 Características del Juego

### Mecánicas Básicas

- **Movimiento por tiles**: El personaje se mueve en una cuadrícula discreta
- **Colección de objetos**: Recoger todos los elementos 'C' del mapa
- **Condición de victoria**: Llegar a la salida 'E' tras recoger todo
- **Validación de mapas**: Verificación automática de jugabilidad

### Elementos del Juego

| Símbolo | Elemento | Descripción |
|---------|----------|-------------|
| `P` | Jugador | Posición inicial del personaje |
| `E` | Salida | Meta del nivel (Exit) |
| `C` | Coleccionable | Objetos que recoger (Collectible) |
| `1` | Pared | Obstáculos sólidos |
| `0` | Suelo | Terreno transitable |

### Funcionalidades Avanzadas (Bonus)

- **Contador de movimientos** visible en pantalla
- **Sprites animados** para mayor fluidez visual
- **Enemigos patrulleros** que añaden dificultad
- **Mapas expandibles** con viewport dinámico
- **Sistema de puntuación** basado en eficiencia

## 🔧 Especificaciones Técnicas

### Dependencias del Sistema

- **OS**: macOS/Linux compatible
- **Compilador**: GCC con flags `-Wall -Werror -Wextra`
- **Librerías gráficas**: GLFW, OpenGL
- **MLX42**: Librería gráfica de 42 School

### Estructura de Directorios

```
so_long/
├── src/                    # Código fuente principal
├── srcb/                   # Código fuente bonus
├── include/                # Headers del proyecto
├── maps/                   # Archivos de mapas (.ber)
├── img/                    # Texturas y sprites
├── libft/                  # Librería de funciones auxiliares
├── MLX42/                  # Librería gráfica
└── Makefile               # Sistema de compilación
```

## 🛠 Instalación y Compilación

### Prerequisitos

```bash
# macOS
brew install glfw

# Linux (Ubuntu/Debian)
sudo apt-get update
sudo apt-get install libglfw3-dev
```

### Compilación

```bash
# Compilar versión básica
make

# Compilar versión bonus
make bonus

# Compilar y limpiar objetos
make solong

# Limpiar archivos objeto
make clean

# Limpieza completa
make fclean

# Recompilar desde cero
make re
```

## 🚀 Uso y Controles

### Ejecución Básica

```bash
# Ejecutar el juego con un mapa
./so_long maps/map_lab.ber

# Ejecutar versión bonus
./so_long_bonus maps/map_lab_bonus.ber

# Ejemplos de mapas incluidos
./so_long maps/map_mini.ber          # Mapa pequeño
./so_long maps/map_mediano.ber       # Mapa mediano
```

### Controles del Juego

| Tecla | Acción |
|-------|--------|
| `W` / `↑` | Mover arriba |
| `A` / `←` | Mover izquierda |
| `S` / `↓` | Mover abajo |
| `D` / `→` | Mover derecha |
| `ESC` | Salir del juego |

## 🗺 Sistema de Mapas

### Formato de Archivos

Los mapas utilizan la extensión `.ber` y siguen reglas específicas:

```
11111111111111111111
1P0000011C0000000001
11101101111111111001
10101101000000000001
10001101001111111001
11111001001E00000001
1000C011001111011111
101111110000110000C1
10101111111011111101
100000000C0000000001
11111111111111111111
```

### Reglas de Validación

1. **Forma rectangular**: El mapa debe ser un rectángulo perfecto
2. **Paredes perimetrales**: Rodeado completamente por paredes ('1')
3. **Un jugador**: Exactamente una posición inicial ('P')
4. **Una salida**: Exactamente una salida ('E')
5. **Coleccionables**: Al menos un objeto coleccionable ('C')
6. **Jugabilidad**: Debe existir un camino válido para completar el juego

## 🧠 Algoritmos Implementados

### Flood Fill Algorithm

Para validar que el mapa es completable:

```c
void flood_fill(t_read *r, t_point size, t_point init)
{
    // Verificar límites del mapa
    if (init.x < 0 || init.y < 0 || init.x >= size.x || init.y >= size.y)
        return;
    
    // Si es pared, no continuar
    if (r->copy_m[init.y][init.x] == '1')
        return;
    
    // Marcar como visitado
    if (r->copy_m[init.y][init.x] == 'C')
        r->flag_c--;
    if (r->copy_m[init.y][init.x] == 'E')
        r->flag_e--;
    
    r->copy_m[init.y][init.x] = '1';
    
    // Recursión en 4 direcciones
    flood_fill(r, size, (t_point){init.x + 1, init.y});
    flood_fill(r, size, (t_point){init.x - 1, init.y});
    flood_fill(r, size, (t_point){init.x, init.y + 1});
    flood_fill(r, size, (t_point){init.x, init.y - 1});
}
```

### Validación de Movimientos

```c
int is_valid_position(t_read *r, int nx, int ny)
{
    // Verificar límites del mapa
    if (nx < 0 || ny < 0 || nx >= r->column || ny >= r->row)
        return 0;
    
    // Verificar que no sea una pared
    if (r->map[ny][nx] == '1')
        return 0;
    
    return 1;
}
```

## 🎨 Gestión Gráfica

### Sistema de Texturas

```c
void load_images(t_read *r)
{
    // Cargar texturas desde archivos
    r->texture_floor = mlx_load_png("img/floor.png");
    r->texture_walls = mlx_load_png("img/wall.png");
    r->texture_player = mlx_load_png("img/player.png");
    r->texture_collectable = mlx_load_png("img/collectible.png");
    r->texture_exit = mlx_load_png("img/exit.png");
    
    // Verificar carga exitosa
    check_img(r);
    
    // Convertir texturas a imágenes
    r->img_floor = mlx_texture_to_image(r->mlx, r->texture_floor);
    r->img_walls = mlx_texture_to_image(r->mlx, r->texture_walls);
}
```

### Gestión de Eventos

```c
void key_hook(mlx_key_data_t keydata, void *param)
{
    t_read *r = (t_read *)param;
    
    if (keydata.action != MLX_PRESS)
        return;
    
    switch (keydata.key) {
        case MLX_KEY_W:
        case MLX_KEY_UP:
            move_player(r, 0, -1);
            break;
        case MLX_KEY_S:
        case MLX_KEY_DOWN:
            move_player(r, 0, 1);
            break;
        case MLX_KEY_A:
        case MLX_KEY_LEFT:
            move_player(r, -1, 0);
            break;
        case MLX_KEY_D:
        case MLX_KEY_RIGHT:
            move_player(r, 1, 0);
            break;
        case MLX_KEY_ESCAPE:
            mlx_close_window(r->mlx);
            break;
    }
}
```

## 🧪 Testing y Debugging

### Mapas de Prueba Incluidos

```bash
# Mapas válidos
maps/map_mini.ber              # Mapa mínimo válido
maps/map_lab.ber               # Laberinto básico
maps/map_mediano.ber           # Mapa de tamaño medio

# Mapas inválidos (para testing)
maps/map_null_muro0.ber        # Sin paredes perimetrales
maps/map_null_irregular.ber    # Forma irregular
maps/map_no_all_coleccionable.ber # Sin camino a coleccionables
```

### Validaciones de Entrada

```c
int verification_args(int ac, char **av)
{
    if (ac != 2) {
        ft_putstr_fd("Error: Uso: ./so_long <archivo_mapa.ber>\n", 2);
        return (0);
    }
    
    verification_av(av);
    return (1);
}
```

## 🎓 Objetivos de Aprendizaje

### Conceptos Técnicos Desarrollados

1. **Programación Gráfica**
   - Gestión de ventanas y eventos
   - Rendering de sprites y texturas
   - Optimización de refresh rate

2. **Algoritmos de Juegos**
   - Pathfinding básico con flood fill
   - Validación de mapas jugables
   - Detección de colisiones

3. **Gestión de Memoria**
   - Liberación correcta de texturas MLX
   - Prevención de memory leaks
   - Gestión de arrays dinámicos

4. **Arquitectura de Software**
   - Separación de lógica y presentación
   - Modularidad en sistemas complejos
   - Event-driven programming

### Habilidades Prácticas

- **Debugging gráfico** con herramientas especializadas
- **Optimización de rendimiento** en aplicaciones en tiempo real
- **Diseño de interfaces** intuitivas para videojuegos
- **Testing exhaustivo** de casos límite
- **Documentación técnica** de sistemas complejos

---

**Autor**: rdelicado (rdelicad@student.42.com)  
**Proyecto**: so_long  
**Escuela**: 42 School  
**Fecha**: Agosto - Septiembre 2023  

---

*Este proyecto representa una introducción completa al desarrollo de videojuegos en C, combinando programación gráfica, algoritmos de validación y arquitectura de software profesional.*