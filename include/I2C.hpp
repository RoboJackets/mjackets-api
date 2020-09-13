#pragma once

#include "mJackets.hpp"
#include <vector>

/**
 * @brief Typedef for all the I2C Bus peripherals
 * 
 */
typedef enum {
    I2CBus1,
    I2CBus4,
} I2CBus;

class I2C {
public:
    /**
     * @brief Configures the I2C Peripheral
     * 
     * @param i2cBus I2C Bus to initialize
     */
    I2C(I2CBus i2cBus);

    /**
     * @brief Destroy the I2C object
     * 
     */
    ~I2C();

    /**
     * @brief Transmits a byte to a register of a slave device
     * 
     * @param address Network address to transmit to
     * @param regAddr Register of the slave device to write to
     * @param data Byte to write
     */
    void transmit(uint8_t address, uint8_t regAddr, uint8_t data);

    /**
     * @brief Transmits a byte array to a register of a slave device
     * 
     * @param address Slave address
     * @param regAddr Register to write to
     * @param data Array of bytes to write
     */
    void transmit(uint8_t address, uint8_t regAddr, const std::vector<uint8_t>& data);

    /**
     * @brief Reads a byte from a register of a slave device
     * 
     * @param address Slave address
     * @param regAddr Register to read from
     * @return uint8_t Byte received from slave
     */
    uint8_t receive(uint8_t address, uint8_t regAddr);

    /**
     * @brief Reads a byte array from a register of a slave device
     * 
     * @param address Slave address
     * @param regAddr Register to read from
     * @return std::vector<uint8_t> Byte array received from slave
     */
    std::vector<uint8_t> receive(uint8_t address, uint8_t regAddr, size_t count);

    /**
     * @brief Performs a bus recovery
     * 
     */
    void recover_bus();

private:
    I2C_HandleTypeDef i2cHandle = {};
};
