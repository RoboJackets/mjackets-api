# mJackets-api Repository
Welcome to the mJackets API! The mJackets API is a collaborative effort among the RoboJackets competitive robotic teams at the Georgia Institute of Technology to provide a common platform for STM32 MCU firmware development.

# Repository Overview

## API
Contains public interface common C++ functions. These functions interface with the HAL to provide a standardized and simplistic method of interfacing with hardware peripherals on STM32 MCUs. 

## cmake
Contains files for CMake. 

## HAL
Contains all of the family and device specific hardware drivers needed to interface with the microcontroller peripherals. 

## LIB
Contains external libraries such as FreeRTOS, LwIP, and FatFS.

## TEMPLATE
Contains a project template for an mJackets API based project.

## TEST
Contains API unit tests for CI.

## UTIL
Contains various scripts for automating development environment setup and device flashing and debugging. 

