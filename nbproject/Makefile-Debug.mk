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
	${OBJECTDIR}/src/graphics/shapes/Line.o \
	${OBJECTDIR}/src/layer/ObjectLayer.o \
	${OBJECTDIR}/src/input/GLUTInputState.o \
	${OBJECTDIR}/src/core/GameState.o \
	${OBJECTDIR}/src/graphics/shapes/Rectangle.o \
	${OBJECTDIR}/src/input/InputState.o \
	${OBJECTDIR}/src/physics/Mover.o \
	${OBJECTDIR}/src/graphics/shapes/Arc.o \
	${OBJECTDIR}/src/layer/Layer.o \
	${OBJECTDIR}/src/graphics/shapes/PNGImage.o \
	${OBJECTDIR}/src/graphics/shapes/Shape.o \
	${OBJECTDIR}/src/physics/Tile.o \
	${OBJECTDIR}/src/graphics/Graphics.o \
	${OBJECTDIR}/src/graphics/GLUTRenderer.o \
	${OBJECTDIR}/src/graphics/RenderLayer.o \
	${OBJECTDIR}/src/graphics/GLUTDriver.o \
	${OBJECTDIR}/src/graphics/shapes/Polygon.o \
	${OBJECTDIR}/src/layer/TiledObjectLayer.o


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
	${LINK.cc} -Werror -lglut -lGL -lGLU -lpng15 -shared -o ../dist/libphantom.${CND_DLIB_EXT} -fPIC ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/src/core/EventManager.o: src/core/EventManager.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/core
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude -Isrc -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/core/EventManager.o src/core/EventManager.cpp

${OBJECTDIR}/src/core/Entity.o: src/core/Entity.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/core
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude -Isrc -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/core/Entity.o src/core/Entity.cpp

${OBJECTDIR}/src/core/Composite.o: src/core/Composite.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/core
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude -Isrc -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/core/Composite.o src/core/Composite.cpp

${OBJECTDIR}/src/core/PhantomGame.o: src/core/PhantomGame.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/core
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude -Isrc -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/core/PhantomGame.o src/core/PhantomGame.cpp

${OBJECTDIR}/src/graphics/shapes/Line.o: src/graphics/shapes/Line.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/graphics/shapes
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude -Isrc -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/graphics/shapes/Line.o src/graphics/shapes/Line.cpp

${OBJECTDIR}/src/layer/ObjectLayer.o: src/layer/ObjectLayer.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/layer
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude -Isrc -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/layer/ObjectLayer.o src/layer/ObjectLayer.cpp

${OBJECTDIR}/src/input/GLUTInputState.o: src/input/GLUTInputState.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/input
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude -Isrc -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/input/GLUTInputState.o src/input/GLUTInputState.cpp

${OBJECTDIR}/src/core/GameState.o: src/core/GameState.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/core
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude -Isrc -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/core/GameState.o src/core/GameState.cpp

${OBJECTDIR}/src/graphics/shapes/Rectangle.o: src/graphics/shapes/Rectangle.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/graphics/shapes
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude -Isrc -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/graphics/shapes/Rectangle.o src/graphics/shapes/Rectangle.cpp

${OBJECTDIR}/src/input/InputState.o: src/input/InputState.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/input
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude -Isrc -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/input/InputState.o src/input/InputState.cpp

${OBJECTDIR}/src/physics/Mover.o: src/physics/Mover.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/physics
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude -Isrc -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/physics/Mover.o src/physics/Mover.cpp

${OBJECTDIR}/src/graphics/shapes/Arc.o: src/graphics/shapes/Arc.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/graphics/shapes
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude -Isrc -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/graphics/shapes/Arc.o src/graphics/shapes/Arc.cpp

${OBJECTDIR}/src/layer/Layer.o: src/layer/Layer.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/layer
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude -Isrc -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/layer/Layer.o src/layer/Layer.cpp

${OBJECTDIR}/src/graphics/shapes/PNGImage.o: src/graphics/shapes/PNGImage.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/graphics/shapes
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude -Isrc -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/graphics/shapes/PNGImage.o src/graphics/shapes/PNGImage.cpp

${OBJECTDIR}/src/graphics/shapes/Shape.o: src/graphics/shapes/Shape.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/graphics/shapes
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude -Isrc -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/graphics/shapes/Shape.o src/graphics/shapes/Shape.cpp

${OBJECTDIR}/src/physics/Tile.o: src/physics/Tile.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/physics
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude -Isrc -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/physics/Tile.o src/physics/Tile.cpp

${OBJECTDIR}/src/graphics/Graphics.o: src/graphics/Graphics.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/graphics
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude -Isrc -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/graphics/Graphics.o src/graphics/Graphics.cpp

${OBJECTDIR}/src/graphics/GLUTRenderer.o: src/graphics/GLUTRenderer.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/graphics
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude -Isrc -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/graphics/GLUTRenderer.o src/graphics/GLUTRenderer.cpp

${OBJECTDIR}/src/graphics/RenderLayer.o: src/graphics/RenderLayer.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/graphics
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude -Isrc -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/graphics/RenderLayer.o src/graphics/RenderLayer.cpp

${OBJECTDIR}/src/graphics/GLUTDriver.o: src/graphics/GLUTDriver.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/graphics
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude -Isrc -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/graphics/GLUTDriver.o src/graphics/GLUTDriver.cpp

${OBJECTDIR}/src/graphics/shapes/Polygon.o: src/graphics/shapes/Polygon.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/graphics/shapes
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude -Isrc -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/graphics/shapes/Polygon.o src/graphics/shapes/Polygon.cpp

${OBJECTDIR}/src/layer/TiledObjectLayer.o: src/layer/TiledObjectLayer.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/layer
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude -Isrc -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/layer/TiledObjectLayer.o src/layer/TiledObjectLayer.cpp

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
