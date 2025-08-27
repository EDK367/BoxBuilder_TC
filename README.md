# BoxBuilderTC

BoxBuilderTC es una aplicación desarrollada en C++ utilizando Qt y CMake que simula un entorno gráfico para la construcción y simulación de cajas. El proyecto integra múltiples módulos, demostrando conceptos de diseño modular, interacción gráfica y manejo eficiente de recursos.

## Índice

- [Introducción](#introducción)
- [Características](#características)
- [Requisitos](#requisitos)
- [Instalación](#instalación)
- [Compilación](#compilación)
- [Ejecución](#ejecución)
- [Uso con Qt Creator](#uso-con-qt-creator)
- [Estructura del Proyecto](#estructura-del-proyecto)
- [Solución de Problemas](#solución-de-problemas)
- [Contribución](#contribución)
- [Licencia](#licencia)

## Introducción

El proyecto BoxBuilderTC es una muestra práctica del uso de Qt para la creación de interfaces gráficas en C++ y de CMake para la gestión del proceso de compilación. La aplicación ofrece una interfaz intuitiva para diseñar, simular y manipular elementos gráficos y estructuras de cajas. Está pensada para fines demostrativos y educativos.

## Características

- **Interfaz Gráfica Avanzada:** Utiliza Qt para crear una interfaz amigable e interactiva.
- **Modularidad:** El código está organizado en varios módulos que separan la lógica, la interfaz y el manejo de datos.
- **Compatibilidad Multiplataforma:** Compilable con diferentes compiladores y entornos, incluyendo MinGW y Visual Studio.
- **Uso de CMake:** Facilita la configuración y generación de proyectos para múltiples plataformas y entornos de desarrollo.

## Requisitos

- **Qt:** Se recomienda utilizar Qt 6.9.1 o superior.
- **CMake:** Versión 3.0 o superior.
- **Compilador de C++:** Puede ser MinGW o Visual Studio, según tu entorno.
- **Sistema Operativo:** Preparado para entornos Windows, aunque el proyecto es portable a otros sistemas.

## Instalación

1. **Descarga o Clona el Repositorio:**

   Descarga el repositorio o clónalo desde GitHub:

   ```bash
   git clone https://github.com/tu_usuario/BoxBuilderTC.git
   ```

2. **Navega a la Carpeta del Proyecto:**

   En una terminal, dirígete al directorio del proyecto:

   ```powershell
   cd ruta\a\BoxBuilderTC
   ```

## Compilación

Es recomendable utilizar un directorio de compilación separado para mantener el árbol de fuentes limpio:

1. **Crear un Directorio de Compilación:**

   ```powershell
   mkdir build
   cd build
   ```

2. **Configuración con CMake:**

   Dependiendo del compilador, ejecuta:

   - Para MinGW:

     ```powershell
     cmake -G "MinGW Makefiles" ..
     ```

   - Para Visual Studio:

     ```powershell
     cmake -G "Visual Studio 16 2019" ..
     ```

3. **Compilar el Proyecto:**

   - Con MinGW:

     ```powershell
     mingw32-make
     ```

   - Con Visual Studio:

     Abre la solución (.sln) generada y compila desde el IDE.

## Ejecución

Una vez compilado, el ejecutable se ubicará en el directorio de salida. Por ejemplo, para MinGW, el ejecutable podría estar en:

```
build\Desktop_Qt_6_9_1_MinGW_64_bit-Build\BoxBuilderTC.exe
```

Ejecuta la aplicación desde la terminal:

```powershell
.\Desktop_Qt_6_9_1_MinGW_64_bit-Build\BoxBuilderTC.exe
```

O ejecútala directamente desde el explorador de archivos.

## Uso con Qt Creator

Si prefieres utilizar Qt Creator, sigue estos pasos:

1. Abre Qt Creator.
2. Selecciona **Archivo > Abrir Archivo o Proyecto...** y localiza el archivo `CMakeLists.txt` del proyecto.
3. Configura el kit de compilación adecuado (MinGW o MSVC) según tu entorno.
4. Compila y ejecuta el proyecto directamente desde la interfaz de Qt Creator.

## Estructura del Proyecto

La organización del proyecto está diseñada para separar la lógica de la interfaz y la configuración de compilación:

- **CMakeLists.txt**: Archivo principal de configuración para CMake.
- **main.cpp**: Punto de entrada de la aplicación.
- **mainWindow.cpp/h**: Archivos responsables de la interfaz principal.
- **viewplay.cpp/h, viewplay.ui**: Módulos adicionales para manejar vistas y controles específicos.
- **Otros módulos:** Archivos adicionales organizados para manejar funcionalidades específicas, siguiendo buenas prácticas de modularización.

## Solución de Problemas

### Qt o CMake no están en el PATH

Asegúrate de que las rutas de instalación de Qt y CMake se encuentren en las variables de entorno del sistema.

### Error de Compilación

Verifica que el compilador seleccionado sea compatible y que el kit de desarrollo esté correctamente configurado en Qt Creator o en la terminal.

### Problemas con Dependencias

Si se presentan errores relacionados con bibliotecas o dependencias, revisa la documentación de Qt y CMake para asegurarte de que todas las dependencias están correctamente instaladas y configuradas.

## Contribución

¡Las contribuciones son bienvenidas!

1. Haz un fork del repositorio.
2. Crea una rama para tu nueva funcionalidad o corrección.
3. Realiza tus cambios y envía un Pull Request, explicando detalladamente lo que has realizado.

## Licencia

Distribuido bajo la [Licencia MIT](LICENSE). Consulta el archivo de licencia para más detalles.
