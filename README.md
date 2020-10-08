[![GitHub license](https://img.shields.io/github/license/robojackets/mjackets-api.svg?style=flat-square)](https://raw.githubusercontent.com/robojackets/mjackets-api/master/LICENSE) 
[![CI](https://concourse.robojackets.org/api/v1/teams/roboracing/pipelines/mjackets-build/jobs/build-master/badge)](https://concourse.robojackets.org/teams/roboracing/pipelines/mjackets-build)
[![Quality Gate Status](https://sonarcloud.io/api/project_badges/measure?project=RoboJackets_mjackets-api&metric=alert_status)](https://sonarcloud.io/dashboard?id=RoboJackets_mjackets-api)

# mJackets-api Repository
Welcome to the mJackets API! The mJackets API is a collaborative effort among the RoboJackets competitive robotic teams at the Georgia Institute of Technology to provide a common platform for STM32 MCU firmware development.

# Documentation

Checkout the latest [mJacket's API documentation](https://mjackets-api.readthedocs.io/en/latest) over at Read the Docs!

# Repository Overview

### api
Contains source code for public interface common C++ functions. These functions interface with the HAL to provide a standardized and simplistic method of interfacing with hardware peripherals on STM32 MCUs. 

### cmake
Contains files for the CMake build system. 

### cmsis
Contains common and device specific Cortex Microcontroller Software Interface Standard (CMSIS) libraries. 

### docs
Contains the source files for the online documenation. 

### drivers
Contains all of the peripheral driver libraries.

### external
Contains submodules for external libraries such as FatFS, FreeRTOS, and LwIP.

### include
Contains the include header files for the API. 

### template
Contains a template project structure for developing new mJackets API projects. 

### tests
Contain CI unit tests. 

### utilities
Contains useful tools and scripts for installing dependancies, flashing, etc. 

## API STATUS

| Peripheral API     | Status          |
|--------------------|-----------------|
| Analog In          | Experimental    |
| Delay              | Unstable        |
| Digital Input      | Unstable        |
| Digital Output     | Unstable        |
| SPI                | Dev in Progress |
| External Interrupt | Dev in Progress |