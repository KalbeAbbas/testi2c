#include "inttypes.h"
#include "pxt.h"

#define MAX11646_SETUP 0xD2
#define reg 0x21
#define MAX11646_I2C_ADDRESS 0x36 << 1


#if MICROBIT_CODAL
#define BUFFER_TYPE uint8_t*
#else
#define BUFFER_TYPE char*
#endif

namespace testi2c
{

//%
void readWordFromCommand() {

  /*if (!i2c_dev->write(command, commandLength)) {
    return false;
  }*/
  
  uint8_t buf[2];
  
  buf[0] = MAX11646_SETUP;
  buf[1] = reg;
  
  uBit.i2c.write(MAX11646_I2C_ADDRESS, (BUFFER_TYPE)buf, 2, false);

  //delay(delayms);
  
  /*uBit.sleep(delayms);

  if (readlen == 0)
    return true;*/

  /*uint8_t replylen = readlen * (SGP30_WORD_LEN);
  uint8_t replybuffer[replylen];*/
  uint8_t replybuffer[2];

  /*if (!i2c_dev->read(replybuffer, replylen)) {
    return false;
  }*/
  
  uBit.i2c.read(MAX11646_I2C_ADDRESS, (BUFFER_TYPE)replybuffer, 2, false);
 replybuffer[0];
 replybuffer[1];
  
  uint16_t data = replybuffer[0] << 8 | replybuffer[1];
  
  uBit.serial.send(data);

  /*for (uint8_t i = 0; i < readlen; i++) {
	  readdata[i] = replybuffer[i];
    uint8_t crc = generateCRC(replybuffer + i * 3, 2);
#ifdef I2C_DEBUG
    uBit.serial.send("\t\tCRC calced: 0x");
    uBit.serial.send(crc);
    uBit.serial.send(" vs. 0x");
    uBit.serial.send(replybuffer[i * 3 + 2]);
#endif
    if (crc != replybuffer[i * 3 + 2])
      return false;*/
    // success! store it
    /*readdata[i] = replybuffer[i * 3];
    readdata[i] <<= 8;
    readdata[i] |= replybuffer[i * 3 + 1];
#ifdef I2C_DEBUG
    uBit.serial.send("\t\tRead: 0x");
    uBit.serial.send(readdata[i]);
#endif
  }*/
}

}
