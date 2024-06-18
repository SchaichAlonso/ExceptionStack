project(${CMAKE_PROJECT_NAME}Implementation)

find_package(Qt6Concurrent CONFIG REQUIRED)
find_package(Qt6Core CONFIG REQUIRED)
qt_standard_project_setup()

add_library(Exceptions SHARED)
target_sources(Exceptions PUBLIC
    FILE_SET public_headers
    TYPE HEADERS
    FILES
        main/cxx/Exceptions/ExceptionsAPI.hpp
        main/cxx/Exceptions/FileNotFoundException
        main/cxx/Exceptions/FileNotFoundException.hpp
        main/cxx/Exceptions/IOException
        main/cxx/Exceptions/IOException.hpp
        main/cxx/Exceptions/IllegalArgumentException
        main/cxx/Exceptions/IllegalArgumentException.hpp
        main/cxx/Exceptions/IndexOutOfBoundsException
        main/cxx/Exceptions/IndexOutOfBoundsException.hpp
        main/cxx/Exceptions/NullPointerException
        main/cxx/Exceptions/NullPointerException.hpp
        main/cxx/Exceptions/RuntimeException
        main/cxx/Exceptions/RuntimeException.hpp
    BASE_DIRS
        ${PROJECT_SOURCE_DIR}/main/cxx
)
target_sources(Exceptions PRIVATE
    main/cxx/Exceptions/IndexOutOfBoundsException.cpp
    main/cxx/Exceptions/FileNotFoundException.cpp
    main/cxx/Exceptions/IOException.cpp
    main/cxx/Exceptions/IllegalArgumentException.cpp
    main/cxx/Exceptions/NullPointerException.cpp
    main/cxx/Exceptions/RuntimeException.cpp
)

target_compile_definitions(Exceptions PRIVATE ExceptionsAPI_DLLEXPORT INTERFACE ExceptionsAPI_DLLIMPORT)
target_include_directories(Exceptions INTERFACE $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/main/cxx> $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}/>)
target_link_libraries(Exceptions PUBLIC Qt::Core Qt::Concurrent)
set_target_properties(Exceptions PROPERTIES MSVC_RUNTIME_LIBRARY ${MSVC_RUNTIME_LIBRARY})

install(
    TARGETS Exceptions
    EXPORT ${CMAKE_PROJECT_NAME}Targets
    FILE_SET public_headers
)

if (DEFINED WITH_TESTS)
    find_package(Qt6Test CONFIG REQUIRED)
    
    add_executable(${CMAKE_PROJECT_NAME}Test)
    target_sources(${CMAKE_PROJECT_NAME}Test PRIVATE test/cxx/Exceptions/SmokeTest.cpp)
    target_link_libraries(${CMAKE_PROJECT_NAME}Test Qt::Concurrent Qt::Core Qt::Test Exceptions)
    add_test(NAME ${CMAKE_PROJECT_NAME}Test COMMAND ${CMAKE_PROJECT_NAME}Test -v2 -junitxml)
    if (DEFINED _VCPKG_INSTALLED_DIR)
        set_property(TEST ${CMAKE_PROJECT_NAME}Test PROPERTY ENVIRONMENT_MODIFICATION "PATH=path_list_prepend:${_VCPKG_INSTALLED_DIR}/${VCPKG_TARGET_TRIPLET}$<$<CONFIG:Debug>:/debug>/bin")
        set_property(TEST ${CMAKE_PROJECT_NAME}Test APPEND PROPERTY ENVIRONMENT_MODIFICATION "QT_PLUGIN_PATH=set:${_VCPKG_INSTALLED_DIR}/${VCPKG_TARGET_TRIPLET}$<$<CONFIG:Debug>:/debug>/Qt6/plugins")
    endif ()

    install(TARGETS ${CMAKE_PROJECT_NAME}Test)
endif ()