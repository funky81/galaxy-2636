//#include "wacom_i2c.h"
#include "wacom_i2c_func.h"
//#include "wacom_i2c_firm.h"

#define FLASH_START0 'f'
#define FLASH_START1 'l'
#define FLASH_START2 'a'
#define FLASH_START3 's'
#define FLASH_START4 'h'
#define FLASH_START5 '\r'
#define FLASH_ACK    0x06

#define PANA_QUERY   0x11

#define FLASH_END         0x80
#define FLASH_VERIFY      0x81
#define FLASH_WRITE       0x82
#define FLASH_READ        0x83
#define FLASH_ERASE       0x84
#define FLASH_SET_INFO    0x85
#define FLASH_END_TO_BOOT 0x87
#define FLASH_BAIDRATE    0x88

#define FLASH_QUERY    0xE0
#define FLASH_BLVER    0xE1
#define FLASH_UNITID   0xE2
#define FLASH_GET_INFO 0xE3
#define FLASH_FWVER    0xE4
#define FLASH_MPU      0xE8

#define WRITE_BUFF       300
#define BLOCK_SIZE_W     128
#define NUM_BLOCK_2WRITE 16
#define BANK             0
#define START_ADDR       0x1000
#define MAX_BLOCK_W8501  31
#define MAX_BLOCK_514    47
#define END_BLOCK        4
#define MPUVER_W8501     0x26
#define MPUVER_514       0x22
#define BLVER_W8501      0x41
#define BLVER_514        0x70
#define MAX_ADDR_W8501   0x7FFF
#define MAX_ADDR_514     0xBFFF   

#define RETRY            1

#define ERR_FAILED_ENTER -1
#define ERR_UNSENT       -2
#define ERR_NOT_FLASH    -3
#define ERR_FAILED_EXIT  -4

#define PEN_QUERY '*'

extern int wacom_i2c_chksum(struct wacom_i2c *wac_i2c, unsigned char *flash_data, size_t datasize, unsigned long *max_address);
extern int wacom_i2c_flash_cmd(struct wacom_i2c *wac_i2c);
extern int wacom_i2c_flash_query(struct wacom_i2c *wac_i2c, u8 query);
extern int wacom_i2c_flash_end(struct wacom_i2c *wac_i2c);
extern int wacom_i2c_flash_enter(struct wacom_i2c *wac_i2c);
extern int wacom_i2c_flash_BLVer(struct wacom_i2c *wac_i2c);
extern int wacom_i2c_flash_mucId(struct wacom_i2c *wac_i2c);
extern int wacom_i2c_flash_erase(struct wacom_i2c *wac_i2c, u8 cmd_erase, u8 cmd_block, u8 endBlock);
extern int wacom_i2c_flash_write(struct wacom_i2c *wac_i2c, unsigned long startAddr, u8 size, unsigned long maxAddr);
extern int wacom_i2c_flash_verify(struct wacom_i2c *wac_i2c, unsigned long startAddr, u8 size, unsigned long maxAddr);
extern int wacom_i2c_flash(struct wacom_i2c *wac_i2c);
