# BoxBuilderTC

BoxBuilderTC es una aplicación en C++ que utiliza Qt y CMake para ofrecer una experiencia gráfica robusta en la construcción y simulación de cajas. Este proyecto ejemplifica el uso de diseño modular, integración de funciones 100% nativas y prácticas modernas de compilación en entornos multiplataforma.

---

## Índice

- [Introducción](#introducción)
- [Características](#características)
- [Requisitos](#requisitos)
- [Instalación y Configuración](#instalación-y-configuración-Se-Usara-Windows-Como-Demostración)
- [Compilación](#compilación)
- [Ejecución](#ejecución)
- [Uso con Qt Creator](#uso-con-qt-creator)
- [Estructura del Proyecto](#estructura-del-proyecto)
- [Solución de Problemas](#solución-de-problemas)
- [Contribuir](#contribuir)

---

## Introducción

El proyecto BoxBuilderTC demuestra cómo combinar C++ con Qt para la creación de interfaces gráficas avanzadas, y CMake para la automatización de la compilación. Diseñado para ser un ejemplo educativo, permite a los desarrolladores entender la integración de múltiples módulos y la configuración de entornos de desarrollo complejos. Debido a su complejidad y requesitos se tienen apartado hechos sin ninguna libreria de c++ como lo es un vector dinamico el cual utiliza solo punteros a base de un arreglo los cuales no son dinamicos. 

---

## Características

- **Interfaz Gráfica Avanzada:** Desarrollada con Qt, la aplicación ofrece una experiencia de usuario intuitiva y visualmente atractiva.
- **Diseño Modular:** El código está organizado en módulos separados para la lógica de negocio, la interfaz de usuario y la gestión de recursos.
- **Compatibilidad Multiplataforma:** Aunque optimizado para Windows, la arquitectura permite una fácil adaptación a otros sistemas operativos.
- **Automatización de la Compilación:** Gracias a CMake, el proyecto se configura de manera eficiente para diferentes entornos y compiladores.

---

## Requisitos

- **Qt:** Versión 6.9.1 o superior.
- **CMake:** Versión 3.0 o superior.
- **Compilador de C++:** Puede utilizarse MinGW para Windows (Recomendable) aunque QT ofrece un entorno para Linux (GCC/G++) o Visual Studio (No recomendable).
- **Sistema Operativo:** Este documento utiliza Windows, aunque el proyecto puede ser compilado en otros sistemas operativos.

---

## Instalación y Configuración

1. **Clonar o Descargar el Repositorio:**

   Utiliza Git para clonar el repositorio:

   ```bash
   git clone https://github.com/EDK367/BoxBuilder_TC.git
   ```

2. **Navegar al Directorio del Proyecto:**

   Abre una terminal en la carpeta donde se encuentra el proyecto:

   ```powershell
   cd ruta\a\BoxBuilder_TC
   ```

3. **Configurar Variables de Entorno (Opcional):**

   Asegúrate de que las rutas de Qt y CMake estén correctamente configuradas en el PATH del sistema.

---

## Compilación

Se recomienda crear un directorio de compilación separado para evitar mezclar el código fuente con los archivos generados:

1. **Crear un Directorio de Compilación:**

   ```powershell
   mkdir build
   cd build
   ```

2. **Configurar el Proyecto con CMake:**

   Dependiendo de tu compilador, ejecuta uno de los siguientes comandos:

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

   - Con Visual Studio: Abre la solución (.sln) generada en el directorio de compilación y compílala desde el IDE.

<!-- Instrucciones para Linux -->
## Compilación en Linux

Para compilar el proyecto en Linux, sigue estos pasos:

1. Abre una terminal en el directorio raíz del proyecto.
2. Crea un directorio de compilación:
   ```bash
   mkdir build && cd build
   ```
3. Configura el proyecto con CMake:
   ```bash
   cmake ..
   ```
4. Compila el proyecto:
   ```bash
   make
   ```

## Ejecución en Linux

El ejecutable se generará en el directorio "build". Para ejecutarlo, usa:
   ```bash
   ./BoxBuilderTC
   ```
<!-- Fin instrucciones para Linux -->

---

## Ejecución

Una vez completada la compilación, el ejecutable se ubicará en el directorio de salida. Un ejemplo típico para MinGW es:

```
build\Desktop_Qt_6_9_1_MinGW_64_bit-Build\BoxBuilderTC.exe
```

Después de compilar el proyecto, se genera el builder (el ejecutable) en el directorio de compilación. Sigue estos pasos para que el .exe funcione:

1. **Generar el Builder:**
   - Compila el proyecto según las instrucciones de la sección de compilación.
   - Verifica que el builder se haya generado en el directorio de compilación, por ejemplo:
     ```
     build\Desktop_Qt_6_9_1_MinGW_64_bit-Build\BoxBuilderTC.exe
     ```

2. **Mover el Ejecutable a una Carpeta Temporal:**
   - Desde el directorio `build`, crea una carpeta llamada `release`:
     ```powershell
     mkdir build\release
     ```
   - Copia el ejecutable a la carpeta `release`:
     ```powershell
     copy build\Desktop_Qt_6_9_1_MinGW_64_bit-Build\BoxBuilderTC.exe build\release\
     ```
     Esto lo puedes hacer en cualquier carpeta

3. **Navegar a Qt y Ejecutar windeployqt:**
   - Abre la terminal que viene con Qt (Qt Command Prompt), la cual configura automáticamente el entorno de Qt.
   - En esa terminal, navega hasta el directorio `build\release` (reemplaza "ruta\al\proyecto" con la ruta real de tu proyecto):
   - O busca la carpeta Qt en tu Computadora y luego navegas hasta la ruta donde esta el .exe
     ```powershell
     cd ruta\al\proyecto\build\release
     ```
   - Ejecuta el siguiente comando para empaquetar la aplicación con todas sus dependencias Qt:
     ```powershell
     windeployqt BoxBuilderTC.exe
     ```
   - Este comando copiará las librerías necesarias junto al ejecutable, permitiendo que la aplicación funcione en cualquier sistema Windows sin tener Qt instalado.
   - Es necesario este paso para generar el .exe (Se necesita pasar toda la carpeta no solo el .exe)

Para más detalles sobre este proceso, consulta el siguiente video (Se muestra tambien como hacer un .exe para linux): [Video Guía](https://youtu.be/hCXAgB6y8eA?si=O1ffBFfwhxNGbs5P)

---

## Uso con Qt Creator

Para compilar y ejecutar el proyecto utilizando Qt Creator:

1. Abre Qt Creator.
2. Selecciona **Archivo > Abrir Archivo o Proyecto...** y localiza el archivo `CMakeLists.txt` del proyecto.
3. Configura el kit de compilación adecuado (MinGW o MSVC) en función de tu entorno.
4. Compila y ejecuta el proyecto desde la interfaz de Qt Creator.

---

## Estructura del Proyecto

- **CMakeLists.txt:** Configuración principal para CMake.
- **main.cpp:** Archivo de entrada de la aplicación.
- **mainWindow.cpp/h:** Implementación de la ventana principal e interfaz de usuario.
- **viewplay.cpp/h, viewplay.ui:** Módulos para vistas y controles específicos.
- **Otros módulos:** Código adicional organizado para separar funcionalidades y lógica de negocio.

---

## Solución de Problemas

### Problemas de Compilación

- Verifica que el compilador configurado sea compatible con tu entorno (MinGW o Visual Studio).
- Asegúrate de que las rutas de Qt y CMake estén correctamente establecidas en las variables de entorno.
- Puede elimninar el archivo build de la carpeta BoxBuilderTc y crear una nueva con el mismo nombre "build"

### Dependencias No Encontradas

Si encuentras errores relacionados con librerías o dependencias, revisa la documentación de Qt y CMake para confirmar que todas las dependencias están instaladas y configuradas adecuadamente.

---

## Contribuir

Las contribuciones son bienvenidas. Para colaborar en el proyecto:

1. Haz un fork del repositorio.
2. Crea una rama para nuevas funcionalidades o correcciones.
3. Realiza tus cambios y envía un Pull Request con una descripción detallada de las modificaciones realizadas.

---

