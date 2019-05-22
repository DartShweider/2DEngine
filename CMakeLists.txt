cmake_minimum_required(VERSION 2.8)

project(2DEngine)


set(SFML_INCLUDE_DIR "SFML/include")
set(SFML_LIBRARY_DIR "SFML/lib")

include_directories("SFML/include")
link_directories("SFML/lib")

set(SFML_DIR "SFML/lib/cmake/SFML")
find_package(SFML 2.5.1 COMPONENTS system window graphics network audio)




set(project_sources src/main.cpp
                    src/application.cpp
                    src/scripts/scripts.cpp
                    src/core/engine.cpp
                    src/core/management/eventmanager.cpp
                    src/core/management/drawmanager.cpp
                    src/core/management/logicsmanager.cpp
                    src/core/management/physicsmanager.cpp
                    src/core/objects/gameobject.cpp
                    src/core/storage/datastorage.cpp
                    src/core/tools/tools.cpp
                    src/core/tools/input.cpp
                    src/core/tools/time.cpp
                    src/core/object_components/gameobjectcomponent.cpp
                    src/core/object_components/basicscript.cpp
                    src/core/object_components/renderer.cpp
                    src/core/object_components/rectcollider.cpp
                    src/core/object_components/physicalbody.cpp
                    src/core/object_components/animation.cpp
                    )

add_executable(${PROJECT_NAME} ${project_sources})

target_link_libraries (${PROJECT_NAME} sfml-graphics sfml-window sfml-system)

#Hello!Hello!Hello!

