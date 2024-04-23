cmake_minimum_required(VERSION 3.25)

project(LibPepito LANGUAGES CXX)

include(GNUInstallDirs)


add_library(libpepito pepito.cpp)

target_include_directories(libpepito
      PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
             $<INSTALL_INTERFACE:include>)

target_sources(libpepito
  PUBLIC
    FILE_SET HEADERS
    BASE_DIRS include
    FILES include/pepito/pepito.h)

install(TARGETS libpepito
    EXPORT pepito-targets
    FILE_SET HEADERS
    INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

install(EXPORT pepito-targets
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/pepito
    NAMESPACE pepito::)

install(FILES PepitoConfig.cmake
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/pepito )

