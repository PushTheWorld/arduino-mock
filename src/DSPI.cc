/** Implementation of DSPI mock **/

#include "arduino-mock/DSPI.h"

static DSPIMock* pDSPIMock = NULL;
DSPIMock* DSPIMockInstance() {
  if (!pDSPIMock) {
    pDSPIMock = new DSPIMock();
  }
  return pDSPIMock;
}

void releaseDSPIMock() {
  if (pDSPIMock) {
    delete pDSPIMock;
    pDSPIMock = NULL;
  }
}

void DSPI_::begin(void) {
  pDSPIMock->begin();
}
void DSPI_::setSpeed(uint32_t spd) {
  pDSPIMock->setSpeed(spd);
}
void DSPI_::setMode(uint16_t mod) {
  pDSPIMock->setMode(mod);
}
uint32_t DSPI_::transfer(uint32_t bVal) {
  return pDSPIMock->transfer(bVal);
}

// Preinstantiate Objects
DSPI_ DSPI;
