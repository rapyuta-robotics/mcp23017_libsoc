#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

#include "mcp23017.h"

#define MCP_ADDRESS 0x20
#define I2C_BUS     8

#define VL53L0X_1_XSHUT_MCP23xx_IO  0
#define VL53L0X_2_XSHUT_MCP23xx_IO  1
#define VL53L0X_3_XSHUT_MCP23xx_IO  2
#define VL53L0X_4_XSHUT_MCP23xx_IO  3

int main(int argc, char** argv) {
    i2c *i2c_mcp23017;

    i2c_mcp23017 = mcp23xx_init(I2C_BUS, MCP_ADDRESS);
	if (i2c_mcp23017 == NULL)
		return -1;

    mcp_pinMode(i2c_mcp23017, VL53L0X_1_XSHUT_MCP23xx_IO, OUTPUT);
    mcp_pinMode(i2c_mcp23017, VL53L0X_2_XSHUT_MCP23xx_IO, OUTPUT);
    mcp_pinMode(i2c_mcp23017, VL53L0X_3_XSHUT_MCP23xx_IO, OUTPUT);
    mcp_pinMode(i2c_mcp23017, VL53L0X_4_XSHUT_MCP23xx_IO, OUTPUT);

    mcp_digitalWrite(i2c_mcp23017, VL53L0X_1_XSHUT_MCP23xx_IO, LOW);
    mcp_digitalWrite(i2c_mcp23017, VL53L0X_2_XSHUT_MCP23xx_IO, LOW);
    mcp_digitalWrite(i2c_mcp23017, VL53L0X_3_XSHUT_MCP23xx_IO, LOW);
    mcp_digitalWrite(i2c_mcp23017, VL53L0X_4_XSHUT_MCP23xx_IO, LOW);

    printf("DEUG: Port val: %X\n", mcp_readGPIOAB(i2c_mcp23017));

    return 0;
}

