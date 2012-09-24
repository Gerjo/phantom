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
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/_ext/1416150433/Layer.o \
	${OBJECTDIR}/_ext/1416150433/PhantomGame.o \
	${OBJECTDIR}/_ext/325940660/Shape.o \
	${OBJECTDIR}/_ext/325940660/Line.o \
	${OBJECTDIR}/_ext/325940660/Polygon.o \
	${OBJECTDIR}/_ext/1923082125/RenderLayer.o \
	${OBJECTDIR}/_ext/1923082125/GLUTDriver.o \
	${OBJECTDIR}/_ext/1416150433/GameState.o \
	${OBJECTDIR}/_ext/1416150433/Composite.o \
	${OBJECTDIR}/_ext/1923082125/Graphics.o \
	${OBJECTDIR}/_ext/1416150433/EventManager.o \
	${OBJECTDIR}/_ext/956500488/InputState.o \
	${OBJECTDIR}/_ext/956500488/GLUTInputState.o \
	${OBJECTDIR}/_ext/1923082125/GLUTRenderer.o \
	${OBJECTDIR}/_ext/1416150433/Entity.o \
	${OBJECTDIR}/_ext/325940660/Rectangle.o \
	${OBJECTDIR}/_ext/325940660/Arc.o \
	${OBJECTDIR}/_ext/1827995909/Mover.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=-Wl,-rpath,.

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ../dist/libphantom.${CND_DLIB_EXT}

../dist/libphantom.${CND_DLIB_EXT}: ${OBJECTFILES}
	${MKDIR} -p ../dist
	${LINK.cc} -Werror -lglut -shared -o ../dist/libphantom.${CND_DLIB_EXT} -fPIC ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/_ext/1416150433/Layer.o: /home/gerjo/pccs/phantom/src/core/Layer.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1416150433
	${RM} $@.d
	$(COMPILE.cc) -O2 -Iinclude -Isrc -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1416150433/Layer.o /home/gerjo/pccs/phantom/src/core/Layer.cpp

${OBJECTDIR}/_ext/1416150433/PhantomGame.o: /home/gerjo/pccs/phantom/src/core/PhantomGame.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1416150433
	${RM} $@.d
	$(COMPILE.cc) -O2 -Iinclude -Isrc -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1416150433/PhantomGame.o /home/gerjo/pccs/phantom/src/core/PhantomGame.cpp

${OBJECTDIR}/_ext/325940660/Shape.o: /home/gerjo/pccs/phantom/src/graphics/shapes/Shape.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/325940660
	${RM} $@.d
	$(COMPILE.cc) -O2 -Iinclude -Isrc -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/325940660/Shape.o /home/gerjo/pccs/phantom/src/graphics/shapes/Shape.cpp

${OBJECTDIR}/_ext/325940660/Line.o: /home/gerjo/pccs/phantom/src/graphics/shapes/Line.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/325940660
	${RM} $@.d
	$(COMPILE.cc) -O2 -Iinclude -Isrc -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/325940660/Line.o /home/gerjo/pccs/phantom/src/graphics/shapes/Line.cpp

${OBJECTDIR}/_ext/325940660/Polygon.o: /home/gerjo/pccs/phantom/src/graphics/shapes/Polygon.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/325940660
	${RM} $@.d
	$(COMPILE.cc) -O2 -Iinclude -Isrc -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/325940660/Polygon.o /home/gerjo/pccs/phantom/src/graphics/shapes/Polygon.cpp

${OBJECTDIR}/_ext/1923082125/RenderLayer.o: /home/gerjo/pccs/phantom/src/graphics/RenderLayer.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1923082125
	${RM} $@.d
	$(COMPILE.cc) -O2 -Iinclude -Isrc -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1923082125/RenderLayer.o /home/gerjo/pccs/phantom/src/graphics/RenderLayer.cpp

${OBJECTDIR}/_ext/1923082125/GLUTDriver.o: /home/gerjo/pccs/phantom/src/graphics/GLUTDriver.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1923082125
	${RM} $@.d
	$(COMPILE.cc) -O2 -Iinclude -Isrc -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1923082125/GLUTDriver.o /home/gerjo/pccs/phantom/src/graphics/GLUTDriver.cpp

${OBJECTDIR}/_ext/1416150433/GameState.o: /home/gerjo/pccs/phantom/src/core/GameState.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1416150433
	${RM} $@.d
	$(COMPILE.cc) -O2 -Iinclude -Isrc -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1416150433/GameState.o /home/gerjo/pccs/phantom/src/core/GameState.cpp

${OBJECTDIR}/_ext/1416150433/Composite.o: /home/gerjo/pccs/phantom/src/core/Composite.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1416150433
	${RM} $@.d
	$(COMPILE.cc) -O2 -Iinclude -Isrc -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1416150433/Composite.o /home/gerjo/pccs/phantom/src/core/Composite.cpp

${OBJECTDIR}/_ext/1923082125/Graphics.o: /home/gerjo/pccs/phantom/src/graphics/Graphics.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1923082125
	${RM} $@.d
	$(COMPILE.cc) -O2 -Iinclude -Isrc -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1923082125/Graphics.o /home/gerjo/pccs/phantom/src/graphics/Graphics.cpp

${OBJECTDIR}/_ext/1416150433/EventManager.o: /home/gerjo/pccs/phantom/src/core/EventManager.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1416150433
	${RM} $@.d
	$(COMPILE.cc) -O2 -Iinclude -Isrc -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1416150433/EventManager.o /home/gerjo/pccs/phantom/src/core/EventManager.cpp

${OBJECTDIR}/_ext/956500488/InputState.o: /home/gerjo/pccs/phantom/src/input/InputState.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/956500488
	${RM} $@.d
	$(COMPILE.cc) -O2 -Iinclude -Isrc -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/956500488/InputState.o /home/gerjo/pccs/phantom/src/input/InputState.cpp

${OBJECTDIR}/_ext/956500488/GLUTInputState.o: /home/gerjo/pccs/phantom/src/input/GLUTInputState.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/956500488
	${RM} $@.d
	$(COMPILE.cc) -O2 -Iinclude -Isrc -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/956500488/GLUTInputState.o /home/gerjo/pccs/phantom/src/input/GLUTInputState.cpp

${OBJECTDIR}/_ext/1923082125/GLUTRenderer.o: /home/gerjo/pccs/phantom/src/graphics/GLUTRenderer.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1923082125
	${RM} $@.d
	$(COMPILE.cc) -O2 -Iinclude -Isrc -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1923082125/GLUTRenderer.o /home/gerjo/pccs/phantom/src/graphics/GLUTRenderer.cpp

${OBJECTDIR}/_ext/1416150433/Entity.o: /home/gerjo/pccs/phantom/src/core/Entity.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1416150433
	${RM} $@.d
	$(COMPILE.cc) -O2 -Iinclude -Isrc -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1416150433/Entity.o /home/gerjo/pccs/phantom/src/core/Entity.cpp

${OBJECTDIR}/_ext/325940660/Rectangle.o: /home/gerjo/pccs/phantom/src/graphics/shapes/Rectangle.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/325940660
	${RM} $@.d
	$(COMPILE.cc) -O2 -Iinclude -Isrc -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/325940660/Rectangle.o /home/gerjo/pccs/phantom/src/graphics/shapes/Rectangle.cpp

${OBJECTDIR}/_ext/325940660/Arc.o: /home/gerjo/pccs/phantom/src/graphics/shapes/Arc.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/325940660
	${RM} $@.d
	$(COMPILE.cc) -O2 -Iinclude -Isrc -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/325940660/Arc.o /home/gerjo/pccs/phantom/src/graphics/shapes/Arc.cpp

${OBJECTDIR}/_ext/1827995909/Mover.o: /home/gerjo/pccs/phantom/src/physics/Mover.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1827995909
	${RM} $@.d
	$(COMPILE.cc) -O2 -Iinclude -Isrc -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1827995909/Mover.o /home/gerjo/pccs/phantom/src/physics/Mover.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ../dist/libphantom.${CND_DLIB_EXT}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
