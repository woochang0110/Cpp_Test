#ifndef IS_D2XX_H
#define	IS_D2XX_H


enum {
	IS_OK,
	IS_INVALID_HANDLE,
	IS_DEVICE_NOT_FOUND,
	IS_DEVICE_NOT_OPENED,
	IS_IO_ERROR,
	IS_INSUFFICIENT_RESOURCES,
	IS_INVALID_PARAMETER,
	IS_INVALID_BAUD_RATE,

	IS_DEVICE_NOT_OPENED_FOR_ERASE,
	IS_DEVICE_NOT_OPENED_FOR_WRITE,
	IS_FAILED_TO_WRITE_DEVICE,
	IS_EEPROM_READ_FAILED,
	IS_EEPROM_WRITE_FAILED,
	IS_EEPROM_ERASE_FAILED,
	IS_EEPROM_NOT_PRESENT,
	IS_EEPROM_NOT_PROGRAMMED,
	IS_INVALID_ARGS,
	IS_NOT_SUPPORTED,
	IS_OTHER_ERROR,
	IS_DEVICE_LIST_NOT_READY,
	IS_NO_TAG,
	IS_TIME_OUT,
	IS_UNABLE_TO_LOAD_LIBRARY,
};

#define	FTDI_DIRVER_D2XX		0
#define	FTDI_DIRVER_VCP			1

// Buzzer On
#define	BUZZER_ON			0x80
#define	BUZZER_OFF			0x00

// cmd1
#define	CMD1_COMMON						0x00
#define	CMD1_ISO14443AB					0x01
#define	CMD1_MIFARE_CLASSIC				0x02
#define	CMD1_ISO15693				0x03
#define	CMD1_MIFARE_UL_NTAG				0x05
#define	CMD1_MIFARE_PLUS				0x07
#define	CMD1_ISO7816					0x0A
#define	CMD1_CRYPT						0x10



// common cm2
#define	CMD2_COMMON_UNIQUE_ID		0x0F
#define	CMD2_COMMON_VERSION			0x10
#define	CMD2_COMMON_BAUD_CHANGE			0x12
#define	CMD2_COMMON_SAK_TYPE			0x14
#define	CMD2_COMMON_RFON	0x20
#define	CMD2_COMMON_RFOFF	0x21
#define	CMD2_COMMON_ALL_UID_READ	0x23
#define	CMD2_COMMON_ISO14443A_UID_READ	0x24
#define	CMD2_COMMON_ISO14443B_UID_READ	0x25
#define	CMD2_COMMON_FELICA_UID_READ	0x26
#define	CMD2_COMMON_ISO15693_UID_READ	0x27
#define	CMD2_COMMON_T_MONEY_SERIAL_NUMBER_READ	0x30
#define	CMD2_COMMON_CASHBEE_SERIAL_NUMBER_READ	0x31
#define	CMD2_COMMON_KCASH_SERIAL_NUMBER_READ	0x32
#define	CMD2_COMMON_ALL_CASH_SERIAL_NUMBER_READ	0x33


// 
#define  BUZZER_ON  0x80
//
#define  CM1_COMMON  0x00
#define  CM1_ISO14443AB  0x01
#define  CM1_ISO15693  0x03
#define  CM1_MIFARE  0x02
#define  CM1_MIFARE_ULTRALIGHT  0x05
#define  CM1_MIFARE_PLUS  0x07
#define  CM1_ISO7816  0x0A
#define  CM1_CRYPT  0x10

// common cm2
#define  CMD2_COMMON_UNIQUE_ID  0x0F
#define  CMD2_COMMON_VERSION  0x10
#define  CMD2_COMMON_BAUD_CHANGE  0x12
#define  CMD2_COMMON_SAK_TYPE  0x14
#define  CMD2_COMMON_RFON  0x20
#define  CMD2_COMMON_RFOFF  0x21
#define  CMD2_COMMON_ALL_UID_READ  0x23
#define  CMD2_COMMON_ISO14443A_UID_READ  0x24
#define  CMD2_COMMON_ISO14443B_UID_READ  0x25
#define  CMD2_COMMON_FELICA_UID_READ  0x26
#define  CMD2_COMMON_ISO15693_UID_READ  0x27
#define  CMD2_COMMON_T_MONEY_SERIAL_NUMBER_READ  0x30
#define  CMD2_COMMON_CASHBEE_SERIAL_NUMBER_READ  0x31
#define  CMD2_COMMON_KCASH_SERIAL_NUMBER_READ  0x32
#define  CMD2_COMMON_ALL_CASH_SERIAL_NUMBER_READ  0x33

// ISO15693
#define  CM2_ISO15693_ACTIVE  0x20
#define  CM2_ISO15693_SINGLE_BLOCK_READ  0x21
#define  CM2_ISO15693_MULTIPLE_BLOCK_READ  0x22
#define  CM2_ISO15693_SINGLE_BLOCK_WRITE  0x23
#define  CM2_ISO15693_MULTIPLE_BLOCK_WRITE  0x24
#define  CM2_ISO15693_STAYQUIET  0x25
#define  CM2_ISO15693_SELECT  0x26
#define  CM2_ISO15693_RESETTOREADY  0x27
#define  CM2_ISO15693_BLOCK_LOOK  0x28
#define  CM2_ISO15693_WRITE_AFI  0x29
#define  CM2_ISO15693_LOCK_AFI  0x2A
#define  CM2_ISO15693_WRITE_DSFID  0x2B
#define  CM2_ISO15693_LOCK_DSFID  0x2C
#define  CM2_ISO15693_GETSYSTEMINFORMATION  0x2D
#define  CM2_ISO15693_GETMULTIPLEBLOCKSECURITYSTATUS  0x2E

//ISO15693 & SLIX 2
#define  CM2_ISO15693_ICODE_GET_RANDOM_NUMBER  0x30
#define  CM2_ISO15693_ICODE_SET_PASSWD  0x31
#define  CM2_ISO15693_ICODE_WRITE_PASSWD  0x32
#define  CM2_ISO15693_ICODE_LOCK_PASSWD  0x33
#define  CM2_ISO15693_ICODE_PROTECT_PAGE  0x34
#define  CM2_ISO15693_ICODE_LOCK_PROTECT_PAGE  0x35
#define  CM2_ISO15693_ICODE_PROTECT_BLOCK_STATE  0x38
#define  CM2_ISO15693_ICODE_DESTROY  0x36
#define  CM2_ISO15693_ICODE_ENABLE_PRIVACY  0x37
#define  CM2_ISO15693_ICODE_AUTO_SET_PASSWD  0x39
#define  CM2_ISO15693_ICODE_INVENTORY_READ  0x40
#define  CM2_ISO15693_ICODE_FASET_INVENTORY_READ  0x41
#define  CM2_ISO15693_ICODE_SET_EAS  0x42
#define  CM2_ISO15693_ICODE_RESET_EAS  0x43
#define  CM2_ISO15693_ICODE_PROTEC_EAS  0x44
#define  CM2_ISO15693_ICODE_LOCK_EAS  0x45
#define  CM2_ISO15693_ICODE_EAS_ALRAM  0x46
#define  CM2_ISO15693_ICODE_WRITE_EAS_ID  0x47
#define  CM2_ISO15693_ICODE_READ_EPC  0x48
#define  CM2_ISO15693_ICODE_GET_NXP_SYSTEMINFORMATION  0x49
#define  CM2_ISO15693_ICODE_STAY_QUIET_PERSISTENT  0x4A
#define  CM2_ISO15693_ICODE_READ_SIGNATURE  0x4B
#define  CM2_ISO15693_ICODE_64BIT_PASSWORD_SET  0x50
#define  CM2_ISO15693_ICODE_16BIT_COUNTER_READ  0x51
#define  CM2_ISO15693_ICODE_16BIT_COUNTER_INCREMENT  0x52
#define  CM2_ISO15693_ICODE_16BIT_COUNTER_PROTECT_SET  0x53
#define  CM2_ISO15693_ICODE_16BIT_COUNTER_PROTECT_CLREAR  0x54

//Crypt Calculator
#define  CM2_RANDOM_SEED  0x30
#define  CM2_RANDOM_CREATE  0x31
#define  CM2_AES128_KEY_SAVE  0x35
#define  CM2_AES128_IV_SAVE  0x36
#define  CM2_AES128_DECRYPT  0x37
#define  CM2_AES128_ENCRYPT  0x38
#define  CM2_3DES_KEY_SAVE  0x39
#define  CM2_3DES_IV_SAVE  0x3A
#define  CM2_3DES_DECRYPT  0x3B
#define  CM2_3DES_ENCRYPT  0x3C
#define  CM2_CRYPT_KEY_IV_SAVE  0x40
#define  CM2_CRYPT_COMMAND_CONVERT  0x42
#define  CM2_CRYPT_COMMAND_EXE  0x43

// ISO14443A/B
#define  CM2_ISO14443A_ACTIVE  0x20
#define  CM2_ISO14443_4A_106_ACTIVE  0x21
#define  CM2_ISO14443_3A_4A_ACTIVE  0x22
#define  CM2_ISO14443B_ACTIVE  0x23
#define  CM2_ISO14443AB_ACTIVE  0x24
#define  CM2_ISO14443A_HALT  0x2A
#define  CM2_ISO14443B_HALT  0x2B
#define  CM2_ISO14443P4_DATA_EXCHANGE  0x30

//Mifare Ultralight
#define  CM2_MIFARE_ULTRALIGHT_ACTIVE  0x20
#define  CM2_ULTRALIGHT_AUTH  0x21
#define  CM2_ULTRALIGHT_READ  0x22
#define  CM2__ULTRALIGHT_WRITE  0x23
#define  CM2_ULTRALIGHT_PASSWD_CHANGE  0x24
#define  CM2__ULTRALIGHT_OTP_READ  0x25
#define  CM2__ULTRALIGHT_OTP_WRITE  0x26
#define  CM2__ULTRALIGHT_COUNT_READ  0x27
#define  CM2__ULTRALIGHT_COUNT_INC_1  0x28
#define  CM2__ULTRALIGHT_COUNT_INC_ADD  0x29
#define  CM2__ULTRALIGHT_LOCK_BYTE0_WRITE  0x2A
#define  CM2__ULTRALIGHT_LOCK_BYTE2_WRITE  0x2B
#define  CM2__ULTRALIGHT_PASSWORD_WRITE  0x2C
#define  CM2__ULTRALIGHT_AUTH0_AUTH1_READ  0x2D
#define  CM2__ULTRALIGHT_AUTH0_WRITE  0x2E
#define  CM2__ULTRALIGHT_AUTH1_WRITE  0x2F
#define  CM2_ULTRALIGHT_AUTH_32BIT  0x30

//NTAG 
#define  CM2_NTAG_COUNTER_READ  0x31
#define  CM2_NTAG_GET_VERSION  0x32
#define  CM2_NTAG_READ_SIGNAL_ECC  0x33
#define  CM2_NTAG_FAST_READ  0x34
#define  CM2_NTAG_AUTH0_WRITE  0x35
#define  CM2_NTAG_ACCESS_WRITE  0x36
#define  CM2_NTAG_AUTH0_ACCESS_READ  0x37
#define  CM2_NTAG_COUNTER_ENABLE_WRITE  0x38
#define  CM2_NTAG_COUNTER_PWD_WRITE  0x39
#define  CM2_NTAG_COUNTER_STATE_READ  0x3A
#define  CM2_NTAG_PASSWD_CHANGE  0x3B
#define  CM2__ULTRALIGHT_COMPATILITY_WRITE  0x3C

//Mifare Plus
#define  CM2_MIFARE_PLUS_SL3_ACTIVE  0x20
#define  CM2_MIFARE_PLUS_SL3_BLOCK_READ  0x21
#define  CM2_MIFARE_PLUS_SL3_BLOCK_WRITE  0x22
#define  CM2_MIFARE_PLUS_SL3_READ_VALUE  0x23
#define  CM2_MIFARE_PLUS_SL3_WRITE_VALUE  0x24
#define  CM2_MIFARE_PLUS_SL3_INC  0x25
#define  CM2_MIFARE_PLUS_SL3_DEC  0x26
#define  CM2_MIFARE_PLUS_SL3_TRAN  0x27
#define  CM2_MIFARE_PLUS_SL3_RESOTE  0x28
#define  CM2_MIFARE_PLUS_SL3_INC_TRAN  0x29
#define  CM2_MIFARE_PLUS_SL3_DEC_TRAN  0x2A
#define  CM2_MIFARE_PLUS_SL3_AUTH  0x2B
#define  CM2_MIFARE_PLUS_SL3_KEY_CHANGE  0x2C

//Mifare Classic
#define  CM2_MIFARE_ACTIVEL  0x20
#define  CM2_MIFARE_AUTH  0x21
#define  CM2_MIFARE_BLOCK_READ  0x22
#define  CM2_MIFARE_SECTOR_READ  0x23
#define  CM2_MIFARE_BLOCK_WRITE  0x24
#define  CM2_MIFARE_SECTOR_WRITE  0x25
#define  CM2_MIFARE_PURSE_CREATE  0x26
#define  CM2_MIFARE_PURSE_READ  0x27
#define  CM2_MIFARE_INC  0x28
#define  CM2_MIFARE_DEC  0x29
#define  CM2_MIFARE_TRANSFER  0x2A
#define  CM2_MIFARE_RESTORE  0x2B
#define  CM2_MIFARE_INC_TRAN  0x2C
#define  CM2_MIFARE_DEC_TRAN  0x2D
#define  CM2_MIFARE_RESTORE_TRAN  0x2E


// ISO7816
#define  CM2_USIM_ACTIVE  0x20
#define  CM2_USIM_DEACTIVE  0x21
#define  CM2_USIM_TPDU_COMMAND  0x22




typedef	void *	PVOID;
typedef	PVOID	IS_HANDLE;

int is_SetTimeOut(IS_HANDLE ftHandle, unsigned long readTimeOut_milliseconds, unsigned long writeTimeOut_milliseconds);
int is_GetTimeOut(IS_HANDLE ftHandle, unsigned long *readTimeOut_milliseconds, unsigned long *writeTimeOut_milliseconds);

int is_GetDeviceNumber(short *deviceNumber);
int is_GetSerialNumber(long   usb_device_number,	char *serialNumberString);
int is_SetSerialNumber(long   usb_device_number, char *serialNumberString);
int is_GetDescription(long   usb_device_number, char *descriptionString);

int is_OpenSerialNumber(IS_HANDLE *ftHandle, char *serialNumberString, long BaudRate);
int is_OpenDescription(IS_HANDLE *ftHandle, char *descriptionString, long BaudRate);
int is_Close(IS_HANDLE ftHandle);

int is_GetFTDIDriverType(IS_HANDLE ftHandle, unsigned char *d2xx_vcp);
int is_SetFTDIDriverType(IS_HANDLE ftHandle, unsigned char d2xx_vcp);
int is_SetDriverType(IS_HANDLE ftHandle, unsigned char d2xx_vcp);
int is_GetCOMPort(IS_HANDLE ftHandle, unsigned long *portNumber);
int is_GetCOMPort_NoConnect(long usb_device_number, unsigned long *portNumber);



int is_WriteCommand(IS_HANDLE ftHandle, unsigned char cmd1, unsigned char cmd2, unsigned short writeLength, unsigned char *writeData);
int is_WriteReadCommand(IS_HANDLE ftHandle, unsigned char cmd1, unsigned char cmd2, unsigned short writeLength, unsigned char *writeData, unsigned short *length, unsigned char *readData);
int is_ReadCommand(IS_HANDLE ftHandle, unsigned short *readLength, unsigned char *readData);
int is_ReadExCommand(IS_HANDLE ftHandle, unsigned char *cmd1, unsigned char *cmd2, unsigned short *length, unsigned char *readData);


//
int is_TagAllUidRead(IS_HANDLE handle, unsigned char *uid, unsigned short *uidSize);
int is_MifareActive(IS_HANDLE handle, unsigned char *uid, unsigned short *uidSize);
int is_Mifare_KeyA_Auth(IS_HANDLE handle, unsigned char *keyValue, unsigned char blockNumber);
int is_MifarBlockRead(IS_HANDLE handle, unsigned char blockNumber, unsigned short *blockDataSize, unsigned char * blockReadData);
int is_RfOff(IS_HANDLE handle);



#endif // !IS_D2XX_H

