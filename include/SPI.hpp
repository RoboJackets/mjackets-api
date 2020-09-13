#pragma once

#include "mJackets.hpp"
#include <vector>
#include <optional>

/**
 * @brief Typedef for all the SPI Bus peripherals
 * 
 */
typedef enum {
    SpiBus2,
    SpiBus3,
    SpiBus5,
} SpiBus;

/**
 * @brief SPI peripheral clock frequency
 * 
 */
constexpr int fPCLK = 108'000'000; // Hz

class SPI {
public:
    /**
     * @brief Construct a new SPI object
     * 
     * @param spiBus 
     * @param cs 
     * @param hz 
     */
    SPI(SpiBus spiBus, std::optional<PinName> cs = std::nullopt, int hz = 1'000'000);

    /**
     * @brief Destroy the SPI object
     * 
     */
    ~SPI();

    /**
     * @brief Configures the message format
     * 
     * @param bits 
     * @param mode 
     */
    void format(int bits, int mode = 0);
    
    /**
     * @brief Congfigures the bus frequency
     * 
     * @param hz Desired bus frequency
     */
    void frequency(int hz);

    /**
     * @brief Transmits a byte onto the bus
     * 
     * @param data Byte to transmit onto the bus
     */
    void transmit(uint8_t data);

    /**
     * @brief Transmits a byte array onto the bus
     * 
     * @param data 
     */
    void transmit(const std::vector<uint8_t>& data);

    /**
     * @brief Transmits a byte array onto the bus
     * 
     * @param size Length of byte array to transmit
     */
    void transmit(const uint8_t*, size_t size);

    /**
     * @brief Sequentially transmits and receives a byte
     * 
     * @param data Byte to transmit onto bus
     * @return uint8_t Byte received from bus
     */
    uint8_t transmitReceive(uint8_t data);

    /**
     * @brief Sequentially transmits and receives a byte array
     * 
     * @param data Byte array to transmit onto bus
     * @return std::vector<uint8_t> Byte array received from bus
     */
    std::vector<uint8_t> transmitReceive(const std::vector<uint8_t>& data);

    /**
     * @brief Sequentially transmits and receives a byte array
     * 
     * @param dataIn Pointer to data array to store recieved data
     * @param dataOut Pointer to data array to tranmit onto the bus
     * @param size Length of the receive and transmit arrays
     */
    void transmitReceive(const uint8_t* dataIn, uint8_t* dataOut, size_t size);

private:
    SPI_HandleTypeDef spiHandle = {};
    std::optional<PinName> chipSelect;
    uint32_t freqToPrescaler(int hz);
};
