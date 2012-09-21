#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux-x86
CND_DLIB_EXT=so
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/src/core/EventManager.o \
	${OBJECTDIR}/src/core/Entity.o \
	${OBJECTDIR}/src/core/Composite.o \
	${OBJECTDIR}/src/core/PhantomGame.o \
	${OBJECTDIR}/src/physics/shapes/Shape.o \
	${OBJECTDIR}/src/input/GLUTInputState.o \
	${OBJECTDIR}/src/core/GameState.o \
	${OBJECTDIR}/src/input/InputState.o \
	${OBJECTDIR}/src/physics/Mover.o \
	${OBJECTDIR}/src/core/Layer.o \
	${OBJECTDIR}/src/graphics/Graphics.o \
	${OBJECTDIR}/src/graphics/GLGraphics.o \
	${OBJECTDIR}/src/graphics/RenderLayer.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=-Werror
CXXFLAGS=-Werror

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=-L/opt/freeglut-2.8.0/src/.libs -lSDL_draw

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/phantom

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/phantom: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -shared -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/phantom -fPIC ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/src/core/EventManager.o: src/core/EventManager.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/core
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude -Isrc -I/opt/freeglut-2.8.0/include -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/core/EventManager.o src/core/EventManager.cpp

${OBJECTDIR}/src/core/Entity.o: src/core/Entity.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/core
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude -Isrc -I/opt/freeglut-2.8.0/include -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/core/Entity.o src/core/Entity.cpp

${OBJECTDIR}/src/core/Composite.o: src/core/Composite.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/core
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude -Isrc -I/opt/freeglut-2.8.0/include -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/core/Composite.o src/core/Composite.cpp

${OBJECTDIR}/src/core/PhantomGame.o: src/core/PhantomGame.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/core
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude -Isrc -I/opt/freeglut-2.8.0/include -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/core/PhantomGame.o src/core/PhantomGame.cpp

${OBJECTDIR}/src/physics/shapes/Shape.o: src/physics/shapes/Shape.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/physics/shapes
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude -Isrc -I/opt/freeglut-2.8.0/include -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/physics/shapes/Shape.o src/physics/shapes/Shape.cpp

${OBJECTDIR}/src/input/GLUTInputState.o: src/input/GLUTInputState.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/input
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude -Isrc -I/opt/freeglut-2.8.0/include -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/input/GLUTInputState.o src/input/GLUTInputState.cpp

${OBJECTDIR}/src/core/GameState.o: src/core/GameState.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/core
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude -Isrc -I/opt/freeglut-2.8.0/include -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/core/GameState.o src/core/GameState.cpp

${OBJECTDIR}/src/input/InputState.o: src/input/InputState.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/input
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude -Isrc -I/opt/freeglut-2.8.0/include -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/input/InputState.o src/input/InputState.cpp

${OBJECTDIR}/src/physics/Mover.o: src/physics/Mover.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/physics
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude -Isrc -I/opt/freeglut-2.8.0/include -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/physics/Mover.o src/physics/Mover.cpp

${OBJECTDIR}/src/core/Layer.o: src/core/Layer.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/core
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude -Isrc -I/opt/freeglut-2.8.0/include -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/core/Layer.o src/core/Layer.cpp

${OBJECTDIR}/src/graphics/Graphics.o: src/graphics/Graphics.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/graphics
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude -Isrc -I/opt/freeglut-2.8.0/include -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/graphics/Graphics.o src/graphics/Graphics.cpp

${OBJECTDIR}/src/graphics/GLGraphics.o: src/graphics/GLGraphics.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/graphics
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude -Isrc -I/opt/freeglut-2.8.0/include -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/graphics/GLGraphics.o src/graphics/GLGraphics.cpp

${OBJECTDIR}/src/graphics/RenderLayer.o: src/graphics/RenderLayer.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/graphics
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude -Isrc -I/opt/freeglut-2.8.0/include -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/graphics/RenderLayer.o src/graphics/RenderLayer.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/phantom

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
