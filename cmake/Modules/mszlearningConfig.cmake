INCLUDE(FindPkgConfig)
PKG_CHECK_MODULES(PC_MSZLEARNING mszlearning)

FIND_PATH(
    MSZLEARNING_INCLUDE_DIRS
    NAMES mszlearning/api.h
    HINTS $ENV{MSZLEARNING_DIR}/include
        ${PC_MSZLEARNING_INCLUDEDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/include
          /usr/local/include
          /usr/include
)

FIND_LIBRARY(
    MSZLEARNING_LIBRARIES
    NAMES gnuradio-mszlearning
    HINTS $ENV{MSZLEARNING_DIR}/lib
        ${PC_MSZLEARNING_LIBDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/lib
          ${CMAKE_INSTALL_PREFIX}/lib64
          /usr/local/lib
          /usr/local/lib64
          /usr/lib
          /usr/lib64
          )

include("${CMAKE_CURRENT_LIST_DIR}/mszlearningTarget.cmake")

INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(MSZLEARNING DEFAULT_MSG MSZLEARNING_LIBRARIES MSZLEARNING_INCLUDE_DIRS)
MARK_AS_ADVANCED(MSZLEARNING_LIBRARIES MSZLEARNING_INCLUDE_DIRS)
