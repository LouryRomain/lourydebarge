# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/utilisateur/Documents/PLT

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/utilisateur/Documents/PLT/build

# Include any dependencies generated for this target.
include CMakeFiles/run.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/run.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/run.dir/flags.make

CMakeFiles/run.dir/src/state/State.cpp.o: CMakeFiles/run.dir/flags.make
CMakeFiles/run.dir/src/state/State.cpp.o: ../src/state/State.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/utilisateur/Documents/PLT/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/run.dir/src/state/State.cpp.o"
	/usr/bin/g++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/run.dir/src/state/State.cpp.o -c /home/utilisateur/Documents/PLT/src/state/State.cpp

CMakeFiles/run.dir/src/state/State.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/run.dir/src/state/State.cpp.i"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/utilisateur/Documents/PLT/src/state/State.cpp > CMakeFiles/run.dir/src/state/State.cpp.i

CMakeFiles/run.dir/src/state/State.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/run.dir/src/state/State.cpp.s"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/utilisateur/Documents/PLT/src/state/State.cpp -o CMakeFiles/run.dir/src/state/State.cpp.s

CMakeFiles/run.dir/src/state/State.cpp.o.requires:

.PHONY : CMakeFiles/run.dir/src/state/State.cpp.o.requires

CMakeFiles/run.dir/src/state/State.cpp.o.provides: CMakeFiles/run.dir/src/state/State.cpp.o.requires
	$(MAKE) -f CMakeFiles/run.dir/build.make CMakeFiles/run.dir/src/state/State.cpp.o.provides.build
.PHONY : CMakeFiles/run.dir/src/state/State.cpp.o.provides

CMakeFiles/run.dir/src/state/State.cpp.o.provides.build: CMakeFiles/run.dir/src/state/State.cpp.o


CMakeFiles/run.dir/src/state/Gang.cpp.o: CMakeFiles/run.dir/flags.make
CMakeFiles/run.dir/src/state/Gang.cpp.o: ../src/state/Gang.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/utilisateur/Documents/PLT/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/run.dir/src/state/Gang.cpp.o"
	/usr/bin/g++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/run.dir/src/state/Gang.cpp.o -c /home/utilisateur/Documents/PLT/src/state/Gang.cpp

CMakeFiles/run.dir/src/state/Gang.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/run.dir/src/state/Gang.cpp.i"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/utilisateur/Documents/PLT/src/state/Gang.cpp > CMakeFiles/run.dir/src/state/Gang.cpp.i

CMakeFiles/run.dir/src/state/Gang.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/run.dir/src/state/Gang.cpp.s"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/utilisateur/Documents/PLT/src/state/Gang.cpp -o CMakeFiles/run.dir/src/state/Gang.cpp.s

CMakeFiles/run.dir/src/state/Gang.cpp.o.requires:

.PHONY : CMakeFiles/run.dir/src/state/Gang.cpp.o.requires

CMakeFiles/run.dir/src/state/Gang.cpp.o.provides: CMakeFiles/run.dir/src/state/Gang.cpp.o.requires
	$(MAKE) -f CMakeFiles/run.dir/build.make CMakeFiles/run.dir/src/state/Gang.cpp.o.provides.build
.PHONY : CMakeFiles/run.dir/src/state/Gang.cpp.o.provides

CMakeFiles/run.dir/src/state/Gang.cpp.o.provides.build: CMakeFiles/run.dir/src/state/Gang.cpp.o


CMakeFiles/run.dir/src/state/Element.cpp.o: CMakeFiles/run.dir/flags.make
CMakeFiles/run.dir/src/state/Element.cpp.o: ../src/state/Element.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/utilisateur/Documents/PLT/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/run.dir/src/state/Element.cpp.o"
	/usr/bin/g++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/run.dir/src/state/Element.cpp.o -c /home/utilisateur/Documents/PLT/src/state/Element.cpp

CMakeFiles/run.dir/src/state/Element.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/run.dir/src/state/Element.cpp.i"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/utilisateur/Documents/PLT/src/state/Element.cpp > CMakeFiles/run.dir/src/state/Element.cpp.i

CMakeFiles/run.dir/src/state/Element.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/run.dir/src/state/Element.cpp.s"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/utilisateur/Documents/PLT/src/state/Element.cpp -o CMakeFiles/run.dir/src/state/Element.cpp.s

CMakeFiles/run.dir/src/state/Element.cpp.o.requires:

.PHONY : CMakeFiles/run.dir/src/state/Element.cpp.o.requires

CMakeFiles/run.dir/src/state/Element.cpp.o.provides: CMakeFiles/run.dir/src/state/Element.cpp.o.requires
	$(MAKE) -f CMakeFiles/run.dir/build.make CMakeFiles/run.dir/src/state/Element.cpp.o.provides.build
.PHONY : CMakeFiles/run.dir/src/state/Element.cpp.o.provides

CMakeFiles/run.dir/src/state/Element.cpp.o.provides.build: CMakeFiles/run.dir/src/state/Element.cpp.o


CMakeFiles/run.dir/src/state/Territory.cpp.o: CMakeFiles/run.dir/flags.make
CMakeFiles/run.dir/src/state/Territory.cpp.o: ../src/state/Territory.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/utilisateur/Documents/PLT/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/run.dir/src/state/Territory.cpp.o"
	/usr/bin/g++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/run.dir/src/state/Territory.cpp.o -c /home/utilisateur/Documents/PLT/src/state/Territory.cpp

CMakeFiles/run.dir/src/state/Territory.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/run.dir/src/state/Territory.cpp.i"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/utilisateur/Documents/PLT/src/state/Territory.cpp > CMakeFiles/run.dir/src/state/Territory.cpp.i

CMakeFiles/run.dir/src/state/Territory.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/run.dir/src/state/Territory.cpp.s"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/utilisateur/Documents/PLT/src/state/Territory.cpp -o CMakeFiles/run.dir/src/state/Territory.cpp.s

CMakeFiles/run.dir/src/state/Territory.cpp.o.requires:

.PHONY : CMakeFiles/run.dir/src/state/Territory.cpp.o.requires

CMakeFiles/run.dir/src/state/Territory.cpp.o.provides: CMakeFiles/run.dir/src/state/Territory.cpp.o.requires
	$(MAKE) -f CMakeFiles/run.dir/build.make CMakeFiles/run.dir/src/state/Territory.cpp.o.provides.build
.PHONY : CMakeFiles/run.dir/src/state/Territory.cpp.o.provides

CMakeFiles/run.dir/src/state/Territory.cpp.o.provides.build: CMakeFiles/run.dir/src/state/Territory.cpp.o


CMakeFiles/run.dir/src/state/Card.cpp.o: CMakeFiles/run.dir/flags.make
CMakeFiles/run.dir/src/state/Card.cpp.o: ../src/state/Card.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/utilisateur/Documents/PLT/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/run.dir/src/state/Card.cpp.o"
	/usr/bin/g++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/run.dir/src/state/Card.cpp.o -c /home/utilisateur/Documents/PLT/src/state/Card.cpp

CMakeFiles/run.dir/src/state/Card.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/run.dir/src/state/Card.cpp.i"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/utilisateur/Documents/PLT/src/state/Card.cpp > CMakeFiles/run.dir/src/state/Card.cpp.i

CMakeFiles/run.dir/src/state/Card.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/run.dir/src/state/Card.cpp.s"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/utilisateur/Documents/PLT/src/state/Card.cpp -o CMakeFiles/run.dir/src/state/Card.cpp.s

CMakeFiles/run.dir/src/state/Card.cpp.o.requires:

.PHONY : CMakeFiles/run.dir/src/state/Card.cpp.o.requires

CMakeFiles/run.dir/src/state/Card.cpp.o.provides: CMakeFiles/run.dir/src/state/Card.cpp.o.requires
	$(MAKE) -f CMakeFiles/run.dir/build.make CMakeFiles/run.dir/src/state/Card.cpp.o.provides.build
.PHONY : CMakeFiles/run.dir/src/state/Card.cpp.o.provides

CMakeFiles/run.dir/src/state/Card.cpp.o.provides.build: CMakeFiles/run.dir/src/state/Card.cpp.o


CMakeFiles/run.dir/src/main.cpp.o: CMakeFiles/run.dir/flags.make
CMakeFiles/run.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/utilisateur/Documents/PLT/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/run.dir/src/main.cpp.o"
	/usr/bin/g++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/run.dir/src/main.cpp.o -c /home/utilisateur/Documents/PLT/src/main.cpp

CMakeFiles/run.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/run.dir/src/main.cpp.i"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/utilisateur/Documents/PLT/src/main.cpp > CMakeFiles/run.dir/src/main.cpp.i

CMakeFiles/run.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/run.dir/src/main.cpp.s"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/utilisateur/Documents/PLT/src/main.cpp -o CMakeFiles/run.dir/src/main.cpp.s

CMakeFiles/run.dir/src/main.cpp.o.requires:

.PHONY : CMakeFiles/run.dir/src/main.cpp.o.requires

CMakeFiles/run.dir/src/main.cpp.o.provides: CMakeFiles/run.dir/src/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/run.dir/build.make CMakeFiles/run.dir/src/main.cpp.o.provides.build
.PHONY : CMakeFiles/run.dir/src/main.cpp.o.provides

CMakeFiles/run.dir/src/main.cpp.o.provides.build: CMakeFiles/run.dir/src/main.cpp.o


CMakeFiles/run.dir/src/control/Clavier.cpp.o: CMakeFiles/run.dir/flags.make
CMakeFiles/run.dir/src/control/Clavier.cpp.o: ../src/control/Clavier.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/utilisateur/Documents/PLT/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/run.dir/src/control/Clavier.cpp.o"
	/usr/bin/g++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/run.dir/src/control/Clavier.cpp.o -c /home/utilisateur/Documents/PLT/src/control/Clavier.cpp

CMakeFiles/run.dir/src/control/Clavier.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/run.dir/src/control/Clavier.cpp.i"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/utilisateur/Documents/PLT/src/control/Clavier.cpp > CMakeFiles/run.dir/src/control/Clavier.cpp.i

CMakeFiles/run.dir/src/control/Clavier.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/run.dir/src/control/Clavier.cpp.s"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/utilisateur/Documents/PLT/src/control/Clavier.cpp -o CMakeFiles/run.dir/src/control/Clavier.cpp.s

CMakeFiles/run.dir/src/control/Clavier.cpp.o.requires:

.PHONY : CMakeFiles/run.dir/src/control/Clavier.cpp.o.requires

CMakeFiles/run.dir/src/control/Clavier.cpp.o.provides: CMakeFiles/run.dir/src/control/Clavier.cpp.o.requires
	$(MAKE) -f CMakeFiles/run.dir/build.make CMakeFiles/run.dir/src/control/Clavier.cpp.o.provides.build
.PHONY : CMakeFiles/run.dir/src/control/Clavier.cpp.o.provides

CMakeFiles/run.dir/src/control/Clavier.cpp.o.provides.build: CMakeFiles/run.dir/src/control/Clavier.cpp.o


CMakeFiles/run.dir/src/renderer/View.cpp.o: CMakeFiles/run.dir/flags.make
CMakeFiles/run.dir/src/renderer/View.cpp.o: ../src/renderer/View.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/utilisateur/Documents/PLT/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/run.dir/src/renderer/View.cpp.o"
	/usr/bin/g++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/run.dir/src/renderer/View.cpp.o -c /home/utilisateur/Documents/PLT/src/renderer/View.cpp

CMakeFiles/run.dir/src/renderer/View.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/run.dir/src/renderer/View.cpp.i"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/utilisateur/Documents/PLT/src/renderer/View.cpp > CMakeFiles/run.dir/src/renderer/View.cpp.i

CMakeFiles/run.dir/src/renderer/View.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/run.dir/src/renderer/View.cpp.s"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/utilisateur/Documents/PLT/src/renderer/View.cpp -o CMakeFiles/run.dir/src/renderer/View.cpp.s

CMakeFiles/run.dir/src/renderer/View.cpp.o.requires:

.PHONY : CMakeFiles/run.dir/src/renderer/View.cpp.o.requires

CMakeFiles/run.dir/src/renderer/View.cpp.o.provides: CMakeFiles/run.dir/src/renderer/View.cpp.o.requires
	$(MAKE) -f CMakeFiles/run.dir/build.make CMakeFiles/run.dir/src/renderer/View.cpp.o.provides.build
.PHONY : CMakeFiles/run.dir/src/renderer/View.cpp.o.provides

CMakeFiles/run.dir/src/renderer/View.cpp.o.provides.build: CMakeFiles/run.dir/src/renderer/View.cpp.o


CMakeFiles/run.dir/src/renderer/Level.cpp.o: CMakeFiles/run.dir/flags.make
CMakeFiles/run.dir/src/renderer/Level.cpp.o: ../src/renderer/Level.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/utilisateur/Documents/PLT/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/run.dir/src/renderer/Level.cpp.o"
	/usr/bin/g++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/run.dir/src/renderer/Level.cpp.o -c /home/utilisateur/Documents/PLT/src/renderer/Level.cpp

CMakeFiles/run.dir/src/renderer/Level.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/run.dir/src/renderer/Level.cpp.i"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/utilisateur/Documents/PLT/src/renderer/Level.cpp > CMakeFiles/run.dir/src/renderer/Level.cpp.i

CMakeFiles/run.dir/src/renderer/Level.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/run.dir/src/renderer/Level.cpp.s"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/utilisateur/Documents/PLT/src/renderer/Level.cpp -o CMakeFiles/run.dir/src/renderer/Level.cpp.s

CMakeFiles/run.dir/src/renderer/Level.cpp.o.requires:

.PHONY : CMakeFiles/run.dir/src/renderer/Level.cpp.o.requires

CMakeFiles/run.dir/src/renderer/Level.cpp.o.provides: CMakeFiles/run.dir/src/renderer/Level.cpp.o.requires
	$(MAKE) -f CMakeFiles/run.dir/build.make CMakeFiles/run.dir/src/renderer/Level.cpp.o.provides.build
.PHONY : CMakeFiles/run.dir/src/renderer/Level.cpp.o.provides

CMakeFiles/run.dir/src/renderer/Level.cpp.o.provides.build: CMakeFiles/run.dir/src/renderer/Level.cpp.o


CMakeFiles/run.dir/src/renderer/Tile.cpp.o: CMakeFiles/run.dir/flags.make
CMakeFiles/run.dir/src/renderer/Tile.cpp.o: ../src/renderer/Tile.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/utilisateur/Documents/PLT/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/run.dir/src/renderer/Tile.cpp.o"
	/usr/bin/g++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/run.dir/src/renderer/Tile.cpp.o -c /home/utilisateur/Documents/PLT/src/renderer/Tile.cpp

CMakeFiles/run.dir/src/renderer/Tile.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/run.dir/src/renderer/Tile.cpp.i"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/utilisateur/Documents/PLT/src/renderer/Tile.cpp > CMakeFiles/run.dir/src/renderer/Tile.cpp.i

CMakeFiles/run.dir/src/renderer/Tile.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/run.dir/src/renderer/Tile.cpp.s"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/utilisateur/Documents/PLT/src/renderer/Tile.cpp -o CMakeFiles/run.dir/src/renderer/Tile.cpp.s

CMakeFiles/run.dir/src/renderer/Tile.cpp.o.requires:

.PHONY : CMakeFiles/run.dir/src/renderer/Tile.cpp.o.requires

CMakeFiles/run.dir/src/renderer/Tile.cpp.o.provides: CMakeFiles/run.dir/src/renderer/Tile.cpp.o.requires
	$(MAKE) -f CMakeFiles/run.dir/build.make CMakeFiles/run.dir/src/renderer/Tile.cpp.o.provides.build
.PHONY : CMakeFiles/run.dir/src/renderer/Tile.cpp.o.provides

CMakeFiles/run.dir/src/renderer/Tile.cpp.o.provides.build: CMakeFiles/run.dir/src/renderer/Tile.cpp.o


CMakeFiles/run.dir/src/renderer/Texture.cpp.o: CMakeFiles/run.dir/flags.make
CMakeFiles/run.dir/src/renderer/Texture.cpp.o: ../src/renderer/Texture.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/utilisateur/Documents/PLT/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/run.dir/src/renderer/Texture.cpp.o"
	/usr/bin/g++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/run.dir/src/renderer/Texture.cpp.o -c /home/utilisateur/Documents/PLT/src/renderer/Texture.cpp

CMakeFiles/run.dir/src/renderer/Texture.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/run.dir/src/renderer/Texture.cpp.i"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/utilisateur/Documents/PLT/src/renderer/Texture.cpp > CMakeFiles/run.dir/src/renderer/Texture.cpp.i

CMakeFiles/run.dir/src/renderer/Texture.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/run.dir/src/renderer/Texture.cpp.s"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/utilisateur/Documents/PLT/src/renderer/Texture.cpp -o CMakeFiles/run.dir/src/renderer/Texture.cpp.s

CMakeFiles/run.dir/src/renderer/Texture.cpp.o.requires:

.PHONY : CMakeFiles/run.dir/src/renderer/Texture.cpp.o.requires

CMakeFiles/run.dir/src/renderer/Texture.cpp.o.provides: CMakeFiles/run.dir/src/renderer/Texture.cpp.o.requires
	$(MAKE) -f CMakeFiles/run.dir/build.make CMakeFiles/run.dir/src/renderer/Texture.cpp.o.provides.build
.PHONY : CMakeFiles/run.dir/src/renderer/Texture.cpp.o.provides

CMakeFiles/run.dir/src/renderer/Texture.cpp.o.provides.build: CMakeFiles/run.dir/src/renderer/Texture.cpp.o


CMakeFiles/run.dir/src/renderer/Window.cpp.o: CMakeFiles/run.dir/flags.make
CMakeFiles/run.dir/src/renderer/Window.cpp.o: ../src/renderer/Window.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/utilisateur/Documents/PLT/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/run.dir/src/renderer/Window.cpp.o"
	/usr/bin/g++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/run.dir/src/renderer/Window.cpp.o -c /home/utilisateur/Documents/PLT/src/renderer/Window.cpp

CMakeFiles/run.dir/src/renderer/Window.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/run.dir/src/renderer/Window.cpp.i"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/utilisateur/Documents/PLT/src/renderer/Window.cpp > CMakeFiles/run.dir/src/renderer/Window.cpp.i

CMakeFiles/run.dir/src/renderer/Window.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/run.dir/src/renderer/Window.cpp.s"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/utilisateur/Documents/PLT/src/renderer/Window.cpp -o CMakeFiles/run.dir/src/renderer/Window.cpp.s

CMakeFiles/run.dir/src/renderer/Window.cpp.o.requires:

.PHONY : CMakeFiles/run.dir/src/renderer/Window.cpp.o.requires

CMakeFiles/run.dir/src/renderer/Window.cpp.o.provides: CMakeFiles/run.dir/src/renderer/Window.cpp.o.requires
	$(MAKE) -f CMakeFiles/run.dir/build.make CMakeFiles/run.dir/src/renderer/Window.cpp.o.provides.build
.PHONY : CMakeFiles/run.dir/src/renderer/Window.cpp.o.provides

CMakeFiles/run.dir/src/renderer/Window.cpp.o.provides.build: CMakeFiles/run.dir/src/renderer/Window.cpp.o


# Object files for target run
run_OBJECTS = \
"CMakeFiles/run.dir/src/state/State.cpp.o" \
"CMakeFiles/run.dir/src/state/Gang.cpp.o" \
"CMakeFiles/run.dir/src/state/Element.cpp.o" \
"CMakeFiles/run.dir/src/state/Territory.cpp.o" \
"CMakeFiles/run.dir/src/state/Card.cpp.o" \
"CMakeFiles/run.dir/src/main.cpp.o" \
"CMakeFiles/run.dir/src/control/Clavier.cpp.o" \
"CMakeFiles/run.dir/src/renderer/View.cpp.o" \
"CMakeFiles/run.dir/src/renderer/Level.cpp.o" \
"CMakeFiles/run.dir/src/renderer/Tile.cpp.o" \
"CMakeFiles/run.dir/src/renderer/Texture.cpp.o" \
"CMakeFiles/run.dir/src/renderer/Window.cpp.o"

# External object files for target run
run_EXTERNAL_OBJECTS =

../bin/run: CMakeFiles/run.dir/src/state/State.cpp.o
../bin/run: CMakeFiles/run.dir/src/state/Gang.cpp.o
../bin/run: CMakeFiles/run.dir/src/state/Element.cpp.o
../bin/run: CMakeFiles/run.dir/src/state/Territory.cpp.o
../bin/run: CMakeFiles/run.dir/src/state/Card.cpp.o
../bin/run: CMakeFiles/run.dir/src/main.cpp.o
../bin/run: CMakeFiles/run.dir/src/control/Clavier.cpp.o
../bin/run: CMakeFiles/run.dir/src/renderer/View.cpp.o
../bin/run: CMakeFiles/run.dir/src/renderer/Level.cpp.o
../bin/run: CMakeFiles/run.dir/src/renderer/Tile.cpp.o
../bin/run: CMakeFiles/run.dir/src/renderer/Texture.cpp.o
../bin/run: CMakeFiles/run.dir/src/renderer/Window.cpp.o
../bin/run: CMakeFiles/run.dir/build.make
../bin/run: /usr/lib/x86_64-linux-gnu/libsfml-graphics.so
../bin/run: /usr/lib/x86_64-linux-gnu/libsfml-window.so
../bin/run: /usr/lib/x86_64-linux-gnu/libsfml-system.so
../bin/run: CMakeFiles/run.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/utilisateur/Documents/PLT/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Linking CXX executable ../bin/run"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/run.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/run.dir/build: ../bin/run

.PHONY : CMakeFiles/run.dir/build

CMakeFiles/run.dir/requires: CMakeFiles/run.dir/src/state/State.cpp.o.requires
CMakeFiles/run.dir/requires: CMakeFiles/run.dir/src/state/Gang.cpp.o.requires
CMakeFiles/run.dir/requires: CMakeFiles/run.dir/src/state/Element.cpp.o.requires
CMakeFiles/run.dir/requires: CMakeFiles/run.dir/src/state/Territory.cpp.o.requires
CMakeFiles/run.dir/requires: CMakeFiles/run.dir/src/state/Card.cpp.o.requires
CMakeFiles/run.dir/requires: CMakeFiles/run.dir/src/main.cpp.o.requires
CMakeFiles/run.dir/requires: CMakeFiles/run.dir/src/control/Clavier.cpp.o.requires
CMakeFiles/run.dir/requires: CMakeFiles/run.dir/src/renderer/View.cpp.o.requires
CMakeFiles/run.dir/requires: CMakeFiles/run.dir/src/renderer/Level.cpp.o.requires
CMakeFiles/run.dir/requires: CMakeFiles/run.dir/src/renderer/Tile.cpp.o.requires
CMakeFiles/run.dir/requires: CMakeFiles/run.dir/src/renderer/Texture.cpp.o.requires
CMakeFiles/run.dir/requires: CMakeFiles/run.dir/src/renderer/Window.cpp.o.requires

.PHONY : CMakeFiles/run.dir/requires

CMakeFiles/run.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/run.dir/cmake_clean.cmake
.PHONY : CMakeFiles/run.dir/clean

CMakeFiles/run.dir/depend:
	cd /home/utilisateur/Documents/PLT/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/utilisateur/Documents/PLT /home/utilisateur/Documents/PLT /home/utilisateur/Documents/PLT/build /home/utilisateur/Documents/PLT/build /home/utilisateur/Documents/PLT/build/CMakeFiles/run.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/run.dir/depend

