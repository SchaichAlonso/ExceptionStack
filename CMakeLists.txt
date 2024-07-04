cmake_minimum_required(VERSION 3.28)

cmake_policy(SET CMP0091 NEW)

project(Exceptions
  VERSION 0.0.1
  DESCRIPTION "Exception Library"
  HOMEPAGE_URL "https://github.com/SchaichAlonso/Exceptions"
  LANGUAGES CXX
)

option(WITH_TESTS "Enable test binary compilation")

enable_testing()
include(CMakePackageConfigHelpers)
include(CPack)
include(GNUInstallDirs)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_VISIBILITY_PRESET hidden)

add_subdirectory(src)

install(EXPORT ${CMAKE_PROJECT_NAME}Targets DESTINATION share/${CMAKE_PROJECT_NAME})

configure_package_config_file(${CMAKE_CURRENT_SOURCE_DIR}/Config.cmake.in
  "${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_PROJECT_NAME}Config.cmake"
  INSTALL_DESTINATION share/${CMAKE_PROJECT_NAME}
  NO_SET_AND_CHECK_MACRO
  NO_CHECK_REQUIRED_COMPONENTS_MACRO
)

write_basic_package_version_file(
  "${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_PROJECT_NAME}ConfigVersion.cmake"
  VERSION "${CMAKE_PROJECT_VERSION}"
  COMPATIBILITY AnyNewerVersion
)

install(
  FILES
    "${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_PROJECT_NAME}Config.cmake"
    "${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_PROJECT_NAME}ConfigVersion.cmake"
  DESTINATION
    share/${CMAKE_PROJECT_NAME}
)
