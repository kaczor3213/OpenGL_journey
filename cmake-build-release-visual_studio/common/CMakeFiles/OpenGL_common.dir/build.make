# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.12

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


.SUFFIXES: .hpux_make_needs_suffix_list


# Produce verbose output by default.
VERBOSE = 1

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "F:\PROGRAMMING\CLion 2018.2.5\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "F:\PROGRAMMING\CLion 2018.2.5\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = F:\STUDIES\CPP\OpenGL_journey

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = F:\STUDIES\CPP\OpenGL_journey\cmake-build-release-visual_studio

# Include any dependencies generated for this target.
include common\CMakeFiles\OpenGL_common.dir\depend.make

# Include the progress variables for this target.
include common\CMakeFiles\OpenGL_common.dir\progress.make

# Include the compile flags for this target's objects.
include common\CMakeFiles\OpenGL_common.dir\flags.make

common\CMakeFiles\OpenGL_common.dir\src\shader.cpp.obj: common\CMakeFiles\OpenGL_common.dir\flags.make
common\CMakeFiles\OpenGL_common.dir\src\shader.cpp.obj: ..\common\src\shader.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=F:\STUDIES\CPP\OpenGL_journey\cmake-build-release-visual_studio\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object common/CMakeFiles/OpenGL_common.dir/src/shader.cpp.obj"
	cd F:\STUDIES\CPP\OpenGL_journey\cmake-build-release-visual_studio\common
	F:\PROGRAMMING\ViusalStudio\VC\Tools\MSVC\14.15.26726\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\OpenGL_common.dir\src\shader.cpp.obj /FdCMakeFiles\OpenGL_common.dir\ /FS -c F:\STUDIES\CPP\OpenGL_journey\common\src\shader.cpp
<<
	cd F:\STUDIES\CPP\OpenGL_journey\cmake-build-release-visual_studio

common\CMakeFiles\OpenGL_common.dir\src\shader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OpenGL_common.dir/src/shader.cpp.i"
	cd F:\STUDIES\CPP\OpenGL_journey\cmake-build-release-visual_studio\common
	F:\PROGRAMMING\ViusalStudio\VC\Tools\MSVC\14.15.26726\bin\Hostx86\x86\cl.exe > CMakeFiles\OpenGL_common.dir\src\shader.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E F:\STUDIES\CPP\OpenGL_journey\common\src\shader.cpp
<<
	cd F:\STUDIES\CPP\OpenGL_journey\cmake-build-release-visual_studio

common\CMakeFiles\OpenGL_common.dir\src\shader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OpenGL_common.dir/src/shader.cpp.s"
	cd F:\STUDIES\CPP\OpenGL_journey\cmake-build-release-visual_studio\common
	F:\PROGRAMMING\ViusalStudio\VC\Tools\MSVC\14.15.26726\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\OpenGL_common.dir\src\shader.cpp.s /c F:\STUDIES\CPP\OpenGL_journey\common\src\shader.cpp
<<
	cd F:\STUDIES\CPP\OpenGL_journey\cmake-build-release-visual_studio

common\CMakeFiles\OpenGL_common.dir\src\point.cpp.obj: common\CMakeFiles\OpenGL_common.dir\flags.make
common\CMakeFiles\OpenGL_common.dir\src\point.cpp.obj: ..\common\src\point.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=F:\STUDIES\CPP\OpenGL_journey\cmake-build-release-visual_studio\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object common/CMakeFiles/OpenGL_common.dir/src/point.cpp.obj"
	cd F:\STUDIES\CPP\OpenGL_journey\cmake-build-release-visual_studio\common
	F:\PROGRAMMING\ViusalStudio\VC\Tools\MSVC\14.15.26726\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\OpenGL_common.dir\src\point.cpp.obj /FdCMakeFiles\OpenGL_common.dir\ /FS -c F:\STUDIES\CPP\OpenGL_journey\common\src\point.cpp
<<
	cd F:\STUDIES\CPP\OpenGL_journey\cmake-build-release-visual_studio

common\CMakeFiles\OpenGL_common.dir\src\point.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OpenGL_common.dir/src/point.cpp.i"
	cd F:\STUDIES\CPP\OpenGL_journey\cmake-build-release-visual_studio\common
	F:\PROGRAMMING\ViusalStudio\VC\Tools\MSVC\14.15.26726\bin\Hostx86\x86\cl.exe > CMakeFiles\OpenGL_common.dir\src\point.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E F:\STUDIES\CPP\OpenGL_journey\common\src\point.cpp
<<
	cd F:\STUDIES\CPP\OpenGL_journey\cmake-build-release-visual_studio

common\CMakeFiles\OpenGL_common.dir\src\point.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OpenGL_common.dir/src/point.cpp.s"
	cd F:\STUDIES\CPP\OpenGL_journey\cmake-build-release-visual_studio\common
	F:\PROGRAMMING\ViusalStudio\VC\Tools\MSVC\14.15.26726\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\OpenGL_common.dir\src\point.cpp.s /c F:\STUDIES\CPP\OpenGL_journey\common\src\point.cpp
<<
	cd F:\STUDIES\CPP\OpenGL_journey\cmake-build-release-visual_studio

common\CMakeFiles\OpenGL_common.dir\src\color.cpp.obj: common\CMakeFiles\OpenGL_common.dir\flags.make
common\CMakeFiles\OpenGL_common.dir\src\color.cpp.obj: ..\common\src\color.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=F:\STUDIES\CPP\OpenGL_journey\cmake-build-release-visual_studio\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object common/CMakeFiles/OpenGL_common.dir/src/color.cpp.obj"
	cd F:\STUDIES\CPP\OpenGL_journey\cmake-build-release-visual_studio\common
	F:\PROGRAMMING\ViusalStudio\VC\Tools\MSVC\14.15.26726\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\OpenGL_common.dir\src\color.cpp.obj /FdCMakeFiles\OpenGL_common.dir\ /FS -c F:\STUDIES\CPP\OpenGL_journey\common\src\color.cpp
<<
	cd F:\STUDIES\CPP\OpenGL_journey\cmake-build-release-visual_studio

common\CMakeFiles\OpenGL_common.dir\src\color.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OpenGL_common.dir/src/color.cpp.i"
	cd F:\STUDIES\CPP\OpenGL_journey\cmake-build-release-visual_studio\common
	F:\PROGRAMMING\ViusalStudio\VC\Tools\MSVC\14.15.26726\bin\Hostx86\x86\cl.exe > CMakeFiles\OpenGL_common.dir\src\color.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E F:\STUDIES\CPP\OpenGL_journey\common\src\color.cpp
<<
	cd F:\STUDIES\CPP\OpenGL_journey\cmake-build-release-visual_studio

common\CMakeFiles\OpenGL_common.dir\src\color.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OpenGL_common.dir/src/color.cpp.s"
	cd F:\STUDIES\CPP\OpenGL_journey\cmake-build-release-visual_studio\common
	F:\PROGRAMMING\ViusalStudio\VC\Tools\MSVC\14.15.26726\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\OpenGL_common.dir\src\color.cpp.s /c F:\STUDIES\CPP\OpenGL_journey\common\src\color.cpp
<<
	cd F:\STUDIES\CPP\OpenGL_journey\cmake-build-release-visual_studio

common\CMakeFiles\OpenGL_common.dir\src\vertex.cpp.obj: common\CMakeFiles\OpenGL_common.dir\flags.make
common\CMakeFiles\OpenGL_common.dir\src\vertex.cpp.obj: ..\common\src\vertex.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=F:\STUDIES\CPP\OpenGL_journey\cmake-build-release-visual_studio\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object common/CMakeFiles/OpenGL_common.dir/src/vertex.cpp.obj"
	cd F:\STUDIES\CPP\OpenGL_journey\cmake-build-release-visual_studio\common
	F:\PROGRAMMING\ViusalStudio\VC\Tools\MSVC\14.15.26726\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\OpenGL_common.dir\src\vertex.cpp.obj /FdCMakeFiles\OpenGL_common.dir\ /FS -c F:\STUDIES\CPP\OpenGL_journey\common\src\vertex.cpp
<<
	cd F:\STUDIES\CPP\OpenGL_journey\cmake-build-release-visual_studio

common\CMakeFiles\OpenGL_common.dir\src\vertex.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OpenGL_common.dir/src/vertex.cpp.i"
	cd F:\STUDIES\CPP\OpenGL_journey\cmake-build-release-visual_studio\common
	F:\PROGRAMMING\ViusalStudio\VC\Tools\MSVC\14.15.26726\bin\Hostx86\x86\cl.exe > CMakeFiles\OpenGL_common.dir\src\vertex.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E F:\STUDIES\CPP\OpenGL_journey\common\src\vertex.cpp
<<
	cd F:\STUDIES\CPP\OpenGL_journey\cmake-build-release-visual_studio

common\CMakeFiles\OpenGL_common.dir\src\vertex.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OpenGL_common.dir/src/vertex.cpp.s"
	cd F:\STUDIES\CPP\OpenGL_journey\cmake-build-release-visual_studio\common
	F:\PROGRAMMING\ViusalStudio\VC\Tools\MSVC\14.15.26726\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\OpenGL_common.dir\src\vertex.cpp.s /c F:\STUDIES\CPP\OpenGL_journey\common\src\vertex.cpp
<<
	cd F:\STUDIES\CPP\OpenGL_journey\cmake-build-release-visual_studio

# Object files for target OpenGL_common
OpenGL_common_OBJECTS = \
"CMakeFiles\OpenGL_common.dir\src\shader.cpp.obj" \
"CMakeFiles\OpenGL_common.dir\src\point.cpp.obj" \
"CMakeFiles\OpenGL_common.dir\src\color.cpp.obj" \
"CMakeFiles\OpenGL_common.dir\src\vertex.cpp.obj"

# External object files for target OpenGL_common
OpenGL_common_EXTERNAL_OBJECTS =

common\OpenGL_common.dll: common\CMakeFiles\OpenGL_common.dir\src\shader.cpp.obj
common\OpenGL_common.dll: common\CMakeFiles\OpenGL_common.dir\src\point.cpp.obj
common\OpenGL_common.dll: common\CMakeFiles\OpenGL_common.dir\src\color.cpp.obj
common\OpenGL_common.dll: common\CMakeFiles\OpenGL_common.dir\src\vertex.cpp.obj
common\OpenGL_common.dll: common\CMakeFiles\OpenGL_common.dir\build.make
common\OpenGL_common.dll: ..\common\external\glew-2.1.0\lib\Release\Win32\glew32s.lib
common\OpenGL_common.dll: ..\common\external\glfw-3.2.1.bin.WIN32\lib-vc2015\glfw3.lib
common\OpenGL_common.dll: common\CMakeFiles\OpenGL_common.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=F:\STUDIES\CPP\OpenGL_journey\cmake-build-release-visual_studio\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX shared library OpenGL_common.dll"
	cd F:\STUDIES\CPP\OpenGL_journey\cmake-build-release-visual_studio\common
	"F:\PROGRAMMING\CLion 2018.2.5\bin\cmake\win\bin\cmake.exe" -E vs_link_dll --intdir=CMakeFiles\OpenGL_common.dir --manifests  -- F:\PROGRAMMING\ViusalStudio\VC\Tools\MSVC\14.15.26726\bin\Hostx86\x86\link.exe /nologo @CMakeFiles\OpenGL_common.dir\objects1.rsp @<<
 /out:OpenGL_common.dll /implib:OpenGL_common.lib /pdb:F:\STUDIES\CPP\OpenGL_journey\cmake-build-release-visual_studio\common\OpenGL_common.pdb /dll /version:1.0 /machine:X86 /INCREMENTAL:NO ..\..\common\external\glew-2.1.0\lib\Release\Win32\glew32s.lib ..\..\common\external\glfw-3.2.1.bin.WIN32\lib-vc2015\glfw3.lib kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib  
<<
	cd F:\STUDIES\CPP\OpenGL_journey\cmake-build-release-visual_studio

# Rule to build all files generated by this target.
common\CMakeFiles\OpenGL_common.dir\build: common\OpenGL_common.dll

.PHONY : common\CMakeFiles\OpenGL_common.dir\build

common\CMakeFiles\OpenGL_common.dir\clean:
	cd F:\STUDIES\CPP\OpenGL_journey\cmake-build-release-visual_studio\common
	$(CMAKE_COMMAND) -P CMakeFiles\OpenGL_common.dir\cmake_clean.cmake
	cd F:\STUDIES\CPP\OpenGL_journey\cmake-build-release-visual_studio
.PHONY : common\CMakeFiles\OpenGL_common.dir\clean

common\CMakeFiles\OpenGL_common.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" F:\STUDIES\CPP\OpenGL_journey F:\STUDIES\CPP\OpenGL_journey\common F:\STUDIES\CPP\OpenGL_journey\cmake-build-release-visual_studio F:\STUDIES\CPP\OpenGL_journey\cmake-build-release-visual_studio\common F:\STUDIES\CPP\OpenGL_journey\cmake-build-release-visual_studio\common\CMakeFiles\OpenGL_common.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : common\CMakeFiles\OpenGL_common.dir\depend

