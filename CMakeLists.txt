cmake_minimum_required(VERSION 3.16)
project(SistemaBancario)

set(CMAKE_CXX_STANDARD 17)

# Activar características automáticas de Qt (moc, uic, rcc)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# Qt setup (usa CMAKE_PREFIX_PATH si es necesario)
set(CMAKE_PREFIX_PATH "C:/msys64/ucrt64/lib/cmake")
find_package(Qt5 REQUIRED COMPONENTS Core Gui Widgets)

# Directorios de inclusión propios del proyecto
include_directories(
    src
    src/core
    src/core/entidades
    src/exceptions
    src/ui
    src/utils
)

# Archivos fuente y encabezados
file(GLOB_RECURSE SOURCES
    src/*.cpp
)

file(GLOB_RECURSE HEADERS
    src/*.h
)

# Crear ejecutable
add_executable(SistemaBancario ${SOURCES} ${HEADERS})

# Enlazar Qt
target_link_libraries(SistemaBancario
    Qt5::Core
    Qt5::Gui
    Qt5::Widgets
)

# Desactivar AUTOMOC para headers que no usan Qt (como SistemaBancario.h)
set_source_files_properties(
    src/core/entidades/SistemaBancario.h
    PROPERTIES SKIP_AUTOMOC ON
)
set_source_files_properties(
    src/utils/Utilidades.h
    PROPERTIES SKIP_AUTOMOC ON
)
