/*
 * RegisterIOSPI.h
 *
 *  Created on: Jul 29, 2015
 *      Author: Scott
 */

#ifndef SRC_REGISTERIOSPI_H_
#define SRC_REGISTERIOSPI_H_

#include "RegisterIO.h"
#include "SPIClient.h"

static const int MAX_SPI_MSG_LENGTH = 256;

class RegisterIO_SPI: public IRegisterIO {
public:
    RegisterIO_SPI(SPIClient& client);
    virtual ~RegisterIO_SPI() {}
    bool Init();
    bool Write(uint8_t address, uint8_t value );
    bool Read(uint8_t first_address, uint8_t* buffer, uint8_t buffer_len);
    bool Shutdown();
private:
    SPIClient& client;
    uint8_t rx_buffer[MAX_SPI_MSG_LENGTH];
    bool trace;
};

#endif /* SRC_REGISTERIOSPI_H_ */
