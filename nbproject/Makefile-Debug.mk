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
	${OBJECTDIR}/src/utils/PhantomException.o \
	${OBJECTDIR}/src/core/Entity.o \
	${OBJECTDIR}/src/core/Composite.o \
	${OBJECTDIR}/src/core/PhantomGame.o \
	${OBJECTDIR}/src/graphics/shapes/Line.o \
	${OBJECTDIR}/src/core/GameState.o \
	${OBJECTDIR}/src/graphics/shapes/Rectangle.o \
	${OBJECTDIR}/src/glut/GLUTCamera.o \
	${OBJECTDIR}/src/physics/Mover.o \
	${OBJECTDIR}/src/input/KeyboardState.o \
	${OBJECTDIR}/src/layer/EntityLayer.o \
	${OBJECTDIR}/src/physics/Line2.o \
	${OBJECTDIR}/src/graphics/shapes/Arc.o \
	${OBJECTDIR}/src/utils/tree/BinaryTree.o \
	${OBJECTDIR}/src/utils/Time.o \
	${OBJECTDIR}/src/layer/Layer.o \
	${OBJECTDIR}/src/input/KeyboardListener.o \
	${OBJECTDIR}/src/graphics/shapes/Shape.o \
	${OBJECTDIR}/src/graphics/ImageCache.o \
	${OBJECTDIR}/src/graphics/shapes/Image.o \
	${OBJECTDIR}/src/graphics/Graphics.o \
	${OBJECTDIR}/src/glut/GLUTRenderer.o \
	${OBJECTDIR}/src/graphics/FreeTypeLibrary.o \
	${OBJECTDIR}/src/glut/GLUTDriver.o \
	${OBJECTDIR}/src/core/Driver.o \
	${OBJECTDIR}/src/glut/GLUTInput.o \
	${OBJECTDIR}/src/graphics/shapes/Text.o \
	${OBJECTDIR}/src/graphics/ImageLoader.o \
	${OBJECTDIR}/src/physics/Box3.o \
	${OBJECTDIR}/src/input/MouseState.o \
	${OBJECTDIR}/src/physics/Vector3.o \
	${OBJECTDIR}/src/graphics/shapes/Polygon.o \
	${OBJECTDIR}/src/physics/Polygon2.o \
	${OBJECTDIR}/src/core/Console.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=-D_GLIBCXX_USE_NANOSLEEP
CXXFLAGS=-D_GLIBCXX_USE_NANOSLEEP

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=-Wl,-rpath,. -Werror -lglut -lGL -lGLU -lpng15 -lfreetype

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ../dist/libphantom.${CND_DLIB_EXT}

../dist/libphantom.${CND_DLIB_EXT}: ${OBJECTFILES}
	${MKDIR} -p ../dist
	${LINK.cc} -Werror -shared -o ../dist/libphantom.${CND_DLIB_EXT} -fPIC ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/src/utils/PhantomException.o: src/utils/PhantomException.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/utils
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude -Isrc -I/usr/include/freetype2 -std=c++11 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/utils/PhantomException.o src/utils/PhantomException.cpp

${OBJECTDIR}/src/core/Entity.o: src/core/Entity.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/core
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude -Isrc -I/usr/include/freetype2 -std=c++11 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/core/Entity.o src/core/Entity.cpp

${OBJECTDIR}/src/core/Composite.o: src/core/Composite.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/core
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude -Isrc -I/usr/include/freetype2 -std=c++11 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/core/Composite.o src/core/Composite.cpp

${OBJECTDIR}/src/core/PhantomGame.o: src/core/PhantomGame.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/core
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude -Isrc -I/usr/include/freetype2 -std=c++11 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/core/PhantomGame.o src/core/PhantomGame.cpp

${OBJECTDIR}/src/graphics/shapes/Line.o: src/graphics/shapes/Line.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/graphics/shapes
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude -Isrc -I/usr/include/freetype2 -std=c++11 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/graphics/shapes/Line.o src/graphics/shapes/Line.cpp

${OBJECTDIR}/src/core/GameState.o: src/core/GameState.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/core
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude -Isrc -I/usr/include/freetype2 -std=c++11 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/core/GameState.o src/core/GameState.cpp

${OBJECTDIR}/src/graphics/shapes/Rectangle.o: src/graphics/shapes/Rectangle.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/graphics/shapes
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude -Isrc -I/usr/include/freetype2 -std=c++11 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/graphics/shapes/Rectangle.o src/graphics/shapes/Rectangle.cpp

${OBJECTDIR}/src/glut/GLUTCamera.o: src/glut/GLUTCamera.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/glut
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude -Isrc -I/usr/include/freetype2 -std=c++11 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/glut/GLUTCamera.o src/glut/GLUTCamera.cpp

${OBJECTDIR}/src/physics/Mover.o: src/physics/Mover.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/physics
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude -Isrc -I/usr/include/freetype2 -std=c++11 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/physics/Mover.o src/physics/Mover.cpp

${OBJECTDIR}/src/input/KeyboardState.o: src/input/KeyboardState.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/input
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude -Isrc -I/usr/include/freetype2 -std=c++11 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/input/KeyboardState.o src/input/KeyboardState.cpp

${OBJECTDIR}/src/layer/EntityLayer.o: src/layer/EntityLayer.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/layer
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude -Isrc -I/usr/include/freetype2 -std=c++11 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/layer/EntityLayer.o src/layer/EntityLayer.cpp

${OBJECTDIR}/src/physics/Line2.o: src/physics/Line2.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/physics
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude -Isrc -I/usr/include/freetype2 -std=c++11 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/physics/Line2.o src/physics/Line2.cpp

${OBJECTDIR}/src/graphics/shapes/Arc.o: src/graphics/shapes/Arc.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/graphics/shapes
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude -Isrc -I/usr/include/freetype2 -std=c++11 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/graphics/shapes/Arc.o src/graphics/shapes/Arc.cpp

${OBJECTDIR}/src/utils/tree/BinaryTree.o: src/utils/tree/BinaryTree.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/utils/tree
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude -Isrc -I/usr/include/freetype2 -std=c++11 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/utils/tree/BinaryTree.o src/utils/tree/BinaryTree.cpp

${OBJECTDIR}/src/utils/Time.o: src/utils/Time.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/utils
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude -Isrc -I/usr/include/freetype2 -std=c++11 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/utils/Time.o src/utils/Time.cpp

${OBJECTDIR}/src/layer/Layer.o: src/layer/Layer.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/layer
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude -Isrc -I/usr/include/freetype2 -std=c++11 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/layer/Layer.o src/layer/Layer.cpp

${OBJECTDIR}/src/input/KeyboardListener.o: src/input/KeyboardListener.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/input
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude -Isrc -I/usr/include/freetype2 -std=c++11 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/input/KeyboardListener.o src/input/KeyboardListener.cpp

${OBJECTDIR}/src/graphics/shapes/Shape.o: src/graphics/shapes/Shape.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/graphics/shapes
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude -Isrc -I/usr/include/freetype2 -std=c++11 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/graphics/shapes/Shape.o src/graphics/shapes/Shape.cpp

${OBJECTDIR}/src/graphics/ImageCache.o: src/graphics/ImageCache.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/graphics
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude -Isrc -I/usr/include/freetype2 -std=c++11 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/graphics/ImageCache.o src/graphics/ImageCache.cpp

${OBJECTDIR}/src/graphics/shapes/Image.o: src/graphics/shapes/Image.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/graphics/shapes
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude -Isrc -I/usr/include/freetype2 -std=c++11 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/graphics/shapes/Image.o src/graphics/shapes/Image.cpp

${OBJECTDIR}/src/graphics/Graphics.o: src/graphics/Graphics.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/graphics
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude -Isrc -I/usr/include/freetype2 -std=c++11 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/graphics/Graphics.o src/graphics/Graphics.cpp

${OBJECTDIR}/src/glut/GLUTRenderer.o: src/glut/GLUTRenderer.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/glut
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude -Isrc -I/usr/include/freetype2 -std=c++11 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/glut/GLUTRenderer.o src/glut/GLUTRenderer.cpp

${OBJECTDIR}/src/graphics/FreeTypeLibrary.o: src/graphics/FreeTypeLibrary.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/graphics
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude -Isrc -I/usr/include/freetype2 -std=c++11 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/graphics/FreeTypeLibrary.o src/graphics/FreeTypeLibrary.cpp

${OBJECTDIR}/src/glut/GLUTDriver.o: src/glut/GLUTDriver.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/glut
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude -Isrc -I/usr/include/freetype2 -std=c++11 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/glut/GLUTDriver.o src/glut/GLUTDriver.cpp

${OBJECTDIR}/src/core/Driver.o: src/core/Driver.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/core
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude -Isrc -I/usr/include/freetype2 -std=c++11 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/core/Driver.o src/core/Driver.cpp

${OBJECTDIR}/src/glut/GLUTInput.o: src/glut/GLUTInput.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/glut
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude -Isrc -I/usr/include/freetype2 -std=c++11 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/glut/GLUTInput.o src/glut/GLUTInput.cpp

${OBJECTDIR}/src/graphics/shapes/Text.o: src/graphics/shapes/Text.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/graphics/shapes
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude -Isrc -I/usr/include/freetype2 -std=c++11 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/graphics/shapes/Text.o src/graphics/shapes/Text.cpp

${OBJECTDIR}/src/graphics/ImageLoader.o: src/graphics/ImageLoader.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/graphics
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude -Isrc -I/usr/include/freetype2 -std=c++11 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/graphics/ImageLoader.o src/graphics/ImageLoader.cpp

${OBJECTDIR}/src/physics/Box3.o: src/physics/Box3.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/physics
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude -Isrc -I/usr/include/freetype2 -std=c++11 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/physics/Box3.o src/physics/Box3.cpp

${OBJECTDIR}/src/input/MouseState.o: src/input/MouseState.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/input
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude -Isrc -I/usr/include/freetype2 -std=c++11 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/input/MouseState.o src/input/MouseState.cpp

${OBJECTDIR}/src/physics/Vector3.o: src/physics/Vector3.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/physics
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude -Isrc -I/usr/include/freetype2 -std=c++11 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/physics/Vector3.o src/physics/Vector3.cpp

${OBJECTDIR}/src/graphics/shapes/Polygon.o: src/graphics/shapes/Polygon.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/graphics/shapes
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude -Isrc -I/usr/include/freetype2 -std=c++11 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/graphics/shapes/Polygon.o src/graphics/shapes/Polygon.cpp

${OBJECTDIR}/src/physics/Polygon2.o: src/physics/Polygon2.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/physics
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude -Isrc -I/usr/include/freetype2 -std=c++11 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/physics/Polygon2.o src/physics/Polygon2.cpp

${OBJECTDIR}/src/core/Console.o: src/core/Console.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/core
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude -Isrc -I/usr/include/freetype2 -std=c++11 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/core/Console.o src/core/Console.cpp

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
