#include "gtest/gtest.h"
#include "DSPI.h"
#include "Arduino.h"
using ::testing::Return;

TEST(DSPI, access) {
  DSPIMock* mock = DSPIMockInstance();
  uint32_t expected_speed = 4000000;
  uint16_t expected_mode = 0;
  uint32_t expected_bVal = 1;

  EXPECT_CALL(*mock, begin());
  EXPECT_CALL(*mock, setSpeed(expected_speed));
  EXPECT_CALL(*mock, setMode(expected_mode));
  EXPECT_CALL(*mock, transfer(expected_bVal));

  DSPI.begin();
  DSPI.setSpeed(expected_speed);
  DSPI.setMode(expected_mode);
  DSPI.transfer(expected_bVal);

  releaseDSPIMock();
}
