# - Try to find Judy
# Once done this will define
#
#  JUDY_FOUND - system has Judy
#  JUDY_INCLUDE_DIR - the Judy include directory
#  JUDY_LIBRARIES - Link these to use Judy
#  JUDY_DEFINITIONS - Compiler switches required for using Judy

IF (JUDY_INCLUDE_DIR AND JUDY_LIBRARIES)
    SET(Judy_FIND_QUIETLY TRUE)
ENDIF (JUDY_INCLUDE_DIR AND JUDY_LIBRARIES)

FIND_PATH(JUDY_INCLUDE_DIR Judy.h)
FIND_LIBRARY(JUDY_LIBRARIES NAMES Judy)

IF (JUDY_INCLUDE_DIR AND JUDY_LIBRARIES)
   SET(JUDY_FOUND TRUE)
ELSE (JUDY_INCLUDE_DIR AND JUDY_LIBRARIES)
   SET(JUDY_FOUND FALSE)
ENDIF (JUDY_INCLUDE_DIR AND JUDY_LIBRARIES)

IF (JUDY_FOUND)
  IF (NOT Judy_FIND_QUIETLY)
    MESSAGE(STATUS "Found libjudy: ${JUDY_LIBRARIES}")
  ENDIF (NOT Judy_FIND_QUIETLY)
ELSE (JUDY_FOUND)
  IF (Judy_FIND_REQUIRED)
    MESSAGE(FATAL_ERROR "Could NOT find libjudy")
  ENDIF (Judy_FIND_REQUIRED)
ENDIF (JUDY_FOUND)

MARK_AS_ADVANCED(JUDY_INCLUDE_DIR JUDY_LIBRARIES)
