#ifndef SERIAL_NMEA_ZERO_H
#define SERIAL_NMEA_ZERO_H

#include <Arduino.h>


/*********************/
/* serial nmea class */
/*********************/

#define SERIAL_NMEA_NEWLINE_LENGTH 2 
#define SERIAL_NMEA_BUFFER_SIZE 128

class SerialNmea {

 public:
  void begin(unsigned long baud, bool rxEnable);
  bool lockRMC(void);
  bool lockGGA(void);
  uint8_t read(void);
  void lock(void); //lock rx completely to write manually
  void write(uint8_t c);
  void release(void);
  
  void rxCompleteVect(void);
  void udrEmptyVect(void);
  uint8_t buffer[SERIAL_NMEA_BUFFER_SIZE];
  volatile byte stateInterrupt = LOW;

 private :
  volatile uint8_t state;
  volatile uint8_t txTail;
  volatile uint8_t txHead;
  volatile uint8_t writePos;
  volatile uint8_t rmcPos;
  volatile uint8_t ggaPos;
  volatile uint8_t nmeaPos;
  uint8_t readPos;
  volatile int8_t nmeaParseStep;
  volatile uint8_t nmeaParity;
  volatile uint8_t parityTag;
  
};

extern SerialNmea serialNmea;

#endif
