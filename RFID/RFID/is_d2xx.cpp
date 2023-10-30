#include "is_d2xx.h"


#include <stdio.h>
#include <windows.h>

#define DLL_HANDLE           HINSTANCE
#define dlsym(handle, name)  GetProcAddress(handle, name)


//
unsigned char g_writeData[1024];
unsigned short g_writeLength = 0;
unsigned char g_readData[1024];
unsigned short g_readLength = 0;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//																															//
//			IS_D2xx DLL Load Function																								//
//																															//
//																															//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
static void *_loadFunction(const char *name) {
	static DLL_HANDLE handle = 0;
	void * function = 0;

	/* Load the shared library if necessary */
	if (handle == 0) {
		handle = LoadLibrary(TEXT("IS_D2XX_x64.dll")); // 경로 유치 확인 부탁 합니다.
		if (handle == 0) {
			return 0;
		}

	}

	/* Bind the requested function in the shared library */
	function = (void *)dlsym(handle, name);
	return function;
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//																															//
//			SDK Interface Function																								//
//																															//
//																															//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//
typedef int (*type_is_SetTimeOut) (IS_HANDLE , unsigned long, unsigned long);
static type_is_SetTimeOut c_is_SetTimeOut = 0;
int is_SetTimeOut(IS_HANDLE ftHandle, unsigned long readTimeOut_milliseconds, unsigned long writeTimeOut_milliseconds)
{
	if (c_is_SetTimeOut == 0) {
		if (!(c_is_SetTimeOut = (type_is_SetTimeOut)_loadFunction("is_SetTimeOut")))
			return IS_UNABLE_TO_LOAD_LIBRARY;
	}
	return c_is_SetTimeOut(ftHandle, readTimeOut_milliseconds, writeTimeOut_milliseconds);
}


//
typedef int (*type_is_GetTimeOut) (IS_HANDLE, unsigned long *, unsigned long *);
static type_is_GetTimeOut c_is_GetTimeOut = 0;
int is_GetTimeOut(IS_HANDLE ftHandle, unsigned long *readTimeOut_milliseconds, unsigned long *writeTimeOut_milliseconds)
{
	if (c_is_GetTimeOut == 0) {
		if (!(c_is_GetTimeOut = (type_is_GetTimeOut)_loadFunction("is_GetTimeOut")))
			return IS_UNABLE_TO_LOAD_LIBRARY;
	}
	return c_is_GetTimeOut(ftHandle, readTimeOut_milliseconds, writeTimeOut_milliseconds);
}

//
typedef int(*type_is_GetDeviceNumber) (short *);
static type_is_GetDeviceNumber c_is_GetDeviceNumber = 0;
int is_GetDeviceNumber(short *deviceNumber)
{
	if (c_is_GetDeviceNumber == 0) {
		if (!(c_is_GetDeviceNumber = (type_is_GetDeviceNumber)_loadFunction("is_GetDeviceNumber")))
			return IS_UNABLE_TO_LOAD_LIBRARY;
	}
	return c_is_GetDeviceNumber(deviceNumber);
}


//USB Serial Number Read
typedef int (*type_is_GetSerialNumber) (long, char*);
static type_is_GetSerialNumber c_is_GetSerialNumber = 0;
int is_GetSerialNumber(long   usb_device_number,	char *serialNumberString)
{
	if (c_is_GetSerialNumber == 0) {
		if (!(c_is_GetSerialNumber = (type_is_GetSerialNumber)_loadFunction("is_GetSerialNumber")))
			return IS_UNABLE_TO_LOAD_LIBRARY;
	}
	return c_is_GetSerialNumber(usb_device_number, serialNumberString);
}


//USB Serial Number Read
typedef int (*type_is_GetDescription) (long, char*);
static type_is_GetDescription c_is_GetDescription = 0;
int is_GetDescription(long   usb_device_number, char *descriptionString)
{
	if (c_is_GetDescription == 0) {
		if (!(c_is_GetDescription = (type_is_GetDescription)_loadFunction("is_GetDescription")))
			return IS_UNABLE_TO_LOAD_LIBRARY;
	}
	return c_is_GetDescription(usb_device_number, descriptionString);
}


//
typedef int(*type_is_OpenSerialNumber) (IS_HANDLE *, char *, long);
static type_is_OpenSerialNumber c_is_OpenSerialNumber = 0;
int is_OpenSerialNumber(IS_HANDLE *ftHandle, char *serialNumberString, long BaudRate)
{
	if (c_is_OpenSerialNumber == 0) {
		if (!(c_is_OpenSerialNumber = (type_is_OpenSerialNumber)_loadFunction("is_OpenSerialNumber")))
			return IS_UNABLE_TO_LOAD_LIBRARY;
	}
	return c_is_OpenSerialNumber(ftHandle, serialNumberString, BaudRate);
}

//
typedef int(*type_is_Close) (IS_HANDLE);
static type_is_Close c_is_Close = 0;
int is_Close(IS_HANDLE ftHandle)
{
	if (c_is_Close == 0) {
		if (!(c_is_Close = (type_is_Close)_loadFunction("is_Close")))
			return IS_UNABLE_TO_LOAD_LIBRARY;
	}
	return c_is_Close(ftHandle);
}

//
typedef int(*type_is_OpenDescription) (IS_HANDLE *, char *, long);
static type_is_OpenDescription c_is_OpenDescription = 0;
int is_OpenDescription(IS_HANDLE *ftHandle, char *descriptionString, long BaudRate)
{
	if (c_is_OpenDescription == 0) {
		if (!(c_is_OpenDescription = (type_is_OpenDescription)_loadFunction("is_OpenDescription")))
			return IS_UNABLE_TO_LOAD_LIBRARY;
	}
	return c_is_OpenDescription(ftHandle, descriptionString, BaudRate);
}


//
typedef int(*type_is_SetSerialNumber) (long , char *);
static type_is_SetSerialNumber c_is_SetSerialNumber = 0;
int is_SetSerialNumber(long   usb_device_number, char *serialNumberString)
{
	if (c_is_SetSerialNumber == 0) {
		if (!(c_is_SetSerialNumber = (type_is_SetSerialNumber)_loadFunction("is_SetSerialNumber")))
			return IS_UNABLE_TO_LOAD_LIBRARY;
	}
	return c_is_SetSerialNumber(usb_device_number, serialNumberString);
}


//
typedef int(*type_is_GetFTDIDriverType) (IS_HANDLE, unsigned char *);
static type_is_GetFTDIDriverType c_is_GetFTDIDriverType = 0;
int is_GetFTDIDriverType(IS_HANDLE ftHandle, unsigned char *d2xx_vcp)
{
	if (c_is_GetFTDIDriverType == 0) {
		if (!(c_is_GetFTDIDriverType = (type_is_GetFTDIDriverType)_loadFunction("is_GetFTDIDriverType")))
			return IS_UNABLE_TO_LOAD_LIBRARY;
	}
	return c_is_GetFTDIDriverType(ftHandle, d2xx_vcp);
}

typedef int(*type_is_SetFTDIDriverType) (IS_HANDLE, unsigned char );
static type_is_SetFTDIDriverType c_is_SetFTDIDriverType = 0;
int is_SetFTDIDriverType(IS_HANDLE ftHandle, unsigned char d2xx_vcp)
{
	if (c_is_SetFTDIDriverType == 0) {
		if (!(c_is_SetFTDIDriverType = (type_is_SetFTDIDriverType)_loadFunction("is_SetFTDIDriverType")))
			return IS_UNABLE_TO_LOAD_LIBRARY;
	}
	return c_is_SetFTDIDriverType(ftHandle, d2xx_vcp);
}


//
typedef int(*type_is_SetDriverType) (IS_HANDLE , unsigned char );
static type_is_SetDriverType c_is_SetDriverType = 0;
int is_SetDriverType(IS_HANDLE ftHandle, unsigned char d2xx_vcp)
{
	if (c_is_SetDriverType == 0) {
		if (!(c_is_SetDriverType = (type_is_SetDriverType)_loadFunction("is_SetDriverType")))
			return IS_UNABLE_TO_LOAD_LIBRARY;
	}
	return c_is_SetDriverType(ftHandle, d2xx_vcp);
}

//
typedef int(*type_is_GetCOMPort) (IS_HANDLE, unsigned long *);
static type_is_GetCOMPort c_is_GetCOMPort = 0;
int is_GetCOMPort(IS_HANDLE ftHandle, unsigned long *portNumber)
{
	if (c_is_GetCOMPort == 0) {
		if (!(c_is_GetCOMPort = (type_is_GetCOMPort)_loadFunction("is_GetCOMPort")))
			return IS_UNABLE_TO_LOAD_LIBRARY;
	}
	return c_is_GetCOMPort(ftHandle, portNumber);
}

typedef int(*type_is_GetCOMPort_NoConnect) (long, unsigned long *);
static type_is_GetCOMPort_NoConnect c_is_GetCOMPort_NoConnect = 0;
int is_GetCOMPort_NoConnect(long usb_device_number, unsigned long *portNumber)
{
	if (c_is_GetCOMPort_NoConnect == 0) {
		if (!(c_is_GetCOMPort_NoConnect = (type_is_GetCOMPort_NoConnect)_loadFunction("is_GetCOMPort_NoConnect")))
			return IS_UNABLE_TO_LOAD_LIBRARY;
	}
	return c_is_GetCOMPort_NoConnect(usb_device_number, portNumber);
}


//
typedef int(*type_is_WriteCommand) (IS_HANDLE , unsigned char , unsigned char , unsigned short , unsigned char *);
static type_is_WriteCommand c_is_WriteCommand = 0;
int is_WriteCommand(IS_HANDLE ftHandle, unsigned char cmd1, unsigned char cmd2, unsigned short writeLength, unsigned char *writeData)
{
	if (c_is_WriteCommand == 0) {
		if (!(c_is_WriteCommand = (type_is_WriteCommand)_loadFunction("is_WriteCommand")))
			return IS_UNABLE_TO_LOAD_LIBRARY;
	}
	return c_is_WriteCommand(ftHandle, cmd1, cmd2, writeLength, writeData);
}


//
typedef int(*type_is_WriteReadCommand) (IS_HANDLE , unsigned char , unsigned char , unsigned short , unsigned char *, unsigned short *, unsigned char *);
static type_is_WriteReadCommand c_is_WriteReadCommand = 0;
int is_WriteReadCommand(IS_HANDLE ftHandle, unsigned char cmd1, unsigned char cmd2, unsigned short writeLength, unsigned char *writeData, unsigned short *length, unsigned char *readData)
{
	if (c_is_WriteReadCommand == 0) {
		if (!(c_is_WriteReadCommand = (type_is_WriteReadCommand)_loadFunction("is_WriteReadCommand")))
			return IS_UNABLE_TO_LOAD_LIBRARY;
	}
	return c_is_WriteReadCommand(ftHandle, cmd1, cmd2, writeLength, writeData, length, readData);
}


//
typedef int(*type_is_ReadCommand) (IS_HANDLE , unsigned short *, unsigned char *);
static type_is_ReadCommand c_is_ReadCommand = 0;
int is_ReadCommand(IS_HANDLE ftHandle, unsigned short *readLength, unsigned char *readData)
{
	if (c_is_ReadCommand == 0) {
		if (!(c_is_ReadCommand = (type_is_ReadCommand)_loadFunction("is_ReadCommand")))
			return IS_UNABLE_TO_LOAD_LIBRARY;
	}
	return c_is_ReadCommand(ftHandle, readLength, readData);
}

//
typedef int(*type_is_ReadExCommand) (IS_HANDLE , unsigned char *, unsigned char *, unsigned short *, unsigned char *);
static type_is_ReadExCommand c_is_ReadExCommand = 0;
int is_ReadExCommand(IS_HANDLE ftHandle, unsigned char *cmd1, unsigned char *cmd2, unsigned short *length, unsigned char *readData)
{
	if (c_is_ReadExCommand == 0) {
		if (!(c_is_ReadExCommand = (type_is_ReadExCommand)_loadFunction("is_ReadExCommand")))
			return IS_UNABLE_TO_LOAD_LIBRARY;
	}
	return c_is_ReadExCommand(ftHandle, cmd1, cmd2, length, readData);
}



//

// 필요한 파일을 추가 해서 작업 하시면 됩니다. 
int is_TagAllUidRead(IS_HANDLE handle, unsigned char *uid, unsigned short *uidSize)
{
	int ret = IS_NO_TAG;
	if (is_WriteReadCommand(handle, CM1_COMMON, CMD2_COMMON_ALL_UID_READ, 0, 0, uidSize, uid) == IS_OK)
	{
		ret = IS_OK;
	}
	return ret;
}

int is_MifareActive(IS_HANDLE handle, unsigned char *uid, unsigned short *uidSize)
{
	int ret = IS_NO_TAG;
	if (is_WriteReadCommand(handle, CM1_MIFARE, CM2_MIFARE_ACTIVEL, 0, 0, uidSize, uid) == IS_OK)
	{
		ret = IS_OK;
	}
	return ret;
}

int is_Mifare_KeyA_Auth(IS_HANDLE handle, unsigned char *keyValue, unsigned char blockNumber)
{
	int ret = IS_NO_TAG;
	int i;

	g_writeData[0] = blockNumber;
	g_writeData[1] = 0x01; // Key A - 0x01 , Key B = 0x02
	for (i = 0; i < 6; i++)
		g_writeData[i + 2] = keyValue[i];
	g_writeLength = 8;
	if (is_WriteReadCommand(handle, CM1_MIFARE, CM2_MIFARE_AUTH, g_writeLength, g_writeData, &g_readLength, g_readData) == IS_OK)
	{
		ret = IS_OK;
	}
	return ret;
}



int is_MifarBlockRead(IS_HANDLE handle, unsigned char blockNumber, unsigned short *blockDataSize, unsigned char * blockReadData)
{
	int ret = IS_NO_TAG;
	int i;

	g_writeData[0] = blockNumber;
	g_writeLength = 1;
	if (is_WriteReadCommand(handle, CM1_MIFARE, CM2_MIFARE_BLOCK_READ + BUZZER_ON, g_writeLength, g_writeData, &g_readLength, g_readData) == IS_OK)
	{
		for (i = 0; i < g_readLength; i++)
			blockReadData[i] = g_readData[i];
		*blockDataSize = g_readLength;
		ret = IS_OK;
	}
	return ret;
}

int is_RfOff(IS_HANDLE handle)
{
	int ret = IS_TIME_OUT;

	if (is_WriteReadCommand(handle, CM1_COMMON, CMD2_COMMON_RFOFF, g_writeLength, g_writeData, &g_readLength, g_readData) == IS_OK)
		ret = IS_OK;
	return ret;
}