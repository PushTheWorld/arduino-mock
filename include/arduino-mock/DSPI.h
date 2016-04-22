/**
 * Chipkit DSPI Mock Header
 */ 
#ifndef __DSPI_h__
#define __DSPI_h__

#include <stdint.h>
#include <gmock/gmock.h>

#define	DSPI_MODE0 0
#define	DSPI_MODE1 1
#define	DSPI_MODE2 2
#define	DSPI_MODE3 3

class DSPI_ {
  public:
    void begin(void);
	void setSpeed(uint32_t spd);
	void setMode(uint16_t  mod);
	uint32_t transfer(uint32_t bVal);
};
extern DSPI_ DSPI;

class DSPIMock {
  public:
  	MOCK_METHOD0(begin, void());
    MOCK_METHOD1(setSpeed, void(uint32_t));
    MOCK_METHOD1(setMode, void(uint16_t));
    MOCK_METHOD1(transfer, uint32_t(uint32_t));
};

DSPIMock* DSPIMockInstance();
void releaseDSPIMock();
#endif
