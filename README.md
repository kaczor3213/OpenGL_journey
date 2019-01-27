# OpenGL_RubicCube

---

![Our Cube](https://i.imgur.com/NQzcLg5.gif)

This is the simple Rubik's Cube written in C++ along with C and OpenGL.
It is also a standalone framework for programming graphic objects and manipulating them.

## Table of contents

- [General info](#general-info)
- [Technologies](#technologies)
- [Setup](#setup)
- [Features](#features)
- [Status](#status)
- [Inspiration](#inspiration)
- [Contact](#contact)

## General info

Project was started because of the object-oriented programming classes. Draft had to be something interesting and original so it came up to this.

## Technologies

- GLAD (version 3.3) - an OpenGL loading library
- Glew (version 2.1.0) - helps quering and loading OpenGL extensions
- GLFW (version 3.2.1) - open source library for OpenGL development
- GLM (version 0.9.9.2) - mathematics OpenGL library
- stb_image.h (version 2.14) - image loader

## Setup

In order to build youself an application follow these steps:

1. Clone the repositorium

2. Download all of above mentioned libraries and unpack them to External folder

3. In Visual Studio 2017 create new project in OpenGL_RubicCube folder. In its' configuration properties in the tab C/C++/General add include folders of all libraries to Additional Include Directories. Remember to do that for All Configurations. In the same window add the following files to the Linker/Input:

- glfw3.lib
- opengl32.lib
- glew32.lib

4. Arrange the project like the picture below or as you wish:

![Arrangement](https://i.imgur.com/5xAQIK8.png)

5. Have fun!

## Features

- 6 colors
- Every wall has different key (try numpad)
- Ability to rotate walls clockwise

## Status

Project status: _execution._

## Inspiration

The project has been inspired by <a href ="https://learnopengl.com/">Learn OpenGL</a>.
This site is very nice for learning how to program with OpenGL.

## Contact

Created by:

kaczor3213 @ kaczor3213@gmail.com
betonv13 @ czaru36@gmail.com