[![GitHub release (latest by date)](https://img.shields.io/github/v/release/hernancham/The_Lambda_Matrix)](https://github.com/hernancham/The_Lambda_Matrix/releases)

![Portada](img/github.comthe_lambda_matrix.png)

# The Lambda Matrix
<picture>
<img src="img/THE%20LAMBDA%20MATRIX%20LOGO.png" alt="The Lambda Matrix Logo" width="300">
<\n>
</picture>

The Lambda Matrix es una librería de C++ diseñada para resolver operaciones matriciales. La librería fue creada utilizando CMake, un sistema de administración de compilación independiente del compilador, que permite una gestión eficiente de varias librerías y carpetas en el proyecto. Además, para garantizar la calidad del código, el proyecto utiliza el framework Googletest para realizar pruebas exhaustivas.

## Estructura del proyecto
```bash
The_Lambda_Matrix
├── CMakeLists.txt
├── LICENSE
├── build
│ └── ...
├── examples
│ ├── CMakeLists.txt
│ ├── Examples1.cpp
│ └── Examples2.cpp
├── img
│ ├── THE LAMBDA MATRIX LOGO.png
│ └── github.comthe_lambda_matrix.png
├── src
│ ├── matrix
│ │ ├── CMakeLists.txt
│ │ ├── Matrix.cpp
│ │ └── include
│ │ └── Matrix.hpp
│ └── rational
│ ├── CMakeLists.txt
│ ├── Rational.cpp
│ └── include
│ └── Rational.hpp
└── tests
├── CMakeLists.txt
├── MatrixTest.cpp
└── RationalTest.cpp
```

## Características

- Resolución de operaciones matriciales en C++.
- Utilización de CMake para una gestión eficiente del proceso de compilación.
- Pruebas de calidad con el framework Googletest.

## Uso

Puedes utilizar la librería siguiendo estos pasos:

1. Clona el repositorio:

git clone https://github.com/tu_usuario/The_Lambda_Matrix.git

2. Compila el proyecto utilizando CMake:
   
```Version requerida del CMake 3.26 o más recientes``` [Descargar aquí](https://cmake.org/download/)


En Linux: 
```bash
cd The_Lambda_Matrix
mkdir build
cd build
cmake --build ..
make
```
En Windows:
```bash
cd The_Lambda_Matrix
mkdir build
cd build
cmake --build ..
make
```

3. Ejecuta los ejemplos para ver cómo utilizar la librería:
```bash
cd build

./examples/Examples1.exe
./examples/Examples2.exe
```

4. Si lo deseas, también puedes construir y ejecutar las pruebas:
```bash
cd build

./tests/Matrixtest1.exe
./tests/test1.exe

./tests/Rationaltest2.exe
./tests/test2.exe
```

## Contribuciones

Si deseas contribuir a este proyecto, ¡eres bienvenido/a! Siéntete libre de enviar pull requests con mejoras o correcciones.

## Licencia

Este proyecto está licenciado bajo la Licencia GNU (GNU General Public License) versión 3. Consulta el archivo [LICENSE](LICENSE) para obtener más detalles.
