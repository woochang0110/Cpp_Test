
#include "is_usb.h"

#if defined(WIN32) || defined(_WIN32)

#include <stdio.h>
#include <windows.h>

#define DLL_HANDLE           HINSTANCE
#define dlsym(handle, name)  GetProcAddress(handle, name)

#endif

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//																															//
//			DLL Load Function																								//
//																 															//
//																															//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
static void *_loadFunction (const char *name) {
    static DLL_HANDLE handle = 0;
    void * function = 0;

    /* Load the shared library if necessary */
    if (handle == 0) {
        handle = LoadLibrary(TEXT("../IS_USB.dll")); // 경로 유치 확인 부탁 합니다.
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
//			USB Interface Function																								//
//																															//
//																															//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


//USB Auto Detect
typedef int (*type_c_is_find_usb) (int , int*) ;
static type_c_is_find_usb c_is_find_usb = 0;
int is_find_usb (
    int   usb_lens,
    int *device
)
{
    if (c_is_find_usb == 0) {
        if (!(c_is_find_usb = (type_c_is_find_usb)_loadFunction("c_is_find_usb")))
            return IS_UNABLE_TO_LOAD_LIBRARY;
    }
    return c_is_find_usb(usb_lens, device);
}


// usb unique id read
typedef int (*type_c_is_unique_id) (int , unsigned char *, int *, int , int) ;
static type_c_is_unique_id c_is_unique_id = 0;
int is_unique_id(
    int handle,							//handle
	unsigned char *read_buff,			//unique id data
	int *buff_lens,						//unique id length
	int buzzerOn,						//buzzer ono/off
	int timeOut							//time out (ms)
)
{
    if (c_is_unique_id == 0) {
        if (!(c_is_unique_id = (type_c_is_unique_id)_loadFunction("c_is_unique_id")))
            return IS_UNABLE_TO_LOAD_LIBRARY;
    }
    return c_is_unique_id(handle, read_buff, buff_lens, buzzerOn, timeOut);
}

// USB Open Connect
typedef int (*type_c_is_open_usb) (int ) ;
static type_c_is_open_usb c_is_open_usb = 0;
int is_open_usb (
    int usb_number
)
{
    if (c_is_open_usb == 0) {
        if (!(c_is_open_usb = (type_c_is_open_usb)_loadFunction("c_is_open_usb")))
            return 0;
    }
    return c_is_open_usb(usb_number);
}

// USB Close
typedef int (*type_c_is_close_usb) (int ) ;
static type_c_is_close_usb c_is_close_usb = 0;
int is_close_usb (
    int usb_number
)
{
    if (c_is_close_usb == 0) {
        if (!(c_is_close_usb = (type_c_is_close_usb)_loadFunction("c_is_close_usb")))
            return IS_UNABLE_TO_LOAD_LIBRARY;
    }
    return c_is_close_usb(usb_number);
}

// RFID Reader Version
typedef int (*type_c_is_rfid_reader_version) (int , unsigned char *, int *, int , int) ;
static type_c_is_rfid_reader_version c_is_rfid_reader_version = 0;

int is_rfid_reader_version(
    int handle,								// handle
	unsigned char *read_buff,				//Version data
	int *buff_lens,							//Version length
	int buzzerOn,							//buzzer on/off
	int timeOut								//time out (ms)
)
{
    if (c_is_rfid_reader_version == 0) {
        if (!(c_is_rfid_reader_version = (type_c_is_rfid_reader_version)_loadFunction("c_is_rfid_reader_version")))
            return IS_UNABLE_TO_LOAD_LIBRARY;
    }
    return c_is_rfid_reader_version(handle, read_buff, buff_lens, buzzerOn, timeOut);
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//																															//
//			Card Serial Function																								//
//																															//
//																															//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Card Type Read
typedef int (*type_c_is_card_type) (int , unsigned char *, int *, int , int) ;
static type_c_is_card_type c_is_card_type = 0;
int is_card_type(
   int handle, 
   unsigned char *read_buff, 
   int *read_lens, 
   int buzzerOn, 
   int timeOut
   )
{
    if (c_is_card_type == 0) {
        if (!(c_is_card_type = (type_c_is_card_type)_loadFunction("c_is_card_type")))
            return IS_UNABLE_TO_LOAD_LIBRARY;
    }
    return c_is_card_type(handle, read_buff, read_lens, buzzerOn, timeOut);
}

// All Card Serial Reader 
typedef int (*type_c_is_card_serial) (int , unsigned char *, unsigned char *, int *, int , int) ;
static type_c_is_card_serial c_is_card_serial = 0;
int is_card_serial(
    int handle,								// handle
	unsigned char *card_type,				//card type 
	unsigned char *read_buff,				//card serial data
	int *buff_lens,							//card serial length
	int buzzerOn,							//buzzer on/off
	int timeOut								//time out (ms)
)
{
    if (c_is_card_serial == 0) {
        if (!(c_is_card_serial = (type_c_is_card_serial)_loadFunction("c_is_card_serial")))
            return IS_UNABLE_TO_LOAD_LIBRARY;
    }
    return c_is_card_serial(handle, card_type, read_buff, buff_lens, buzzerOn, timeOut);
}

// iso14443A / mifare serial reader
typedef int (*type_c_is_iso14443a_card_serial) (int , unsigned char *, int *, int , int) ;
static type_c_is_iso14443a_card_serial c_is_iso14443a_card_serial = 0;
int is_iso14443a_card_serial(
    int handle,							//handle
	unsigned char *read_buff,			//card serial data
	int *buff_lens,						//card serial length
	int buzzerOn,						//buzzer ono/off
	int timeOut							//time out (ms)
)
{
    if (c_is_iso14443a_card_serial == 0) {
        if (!(c_is_iso14443a_card_serial = (type_c_is_iso14443a_card_serial)_loadFunction("c_is_iso14443a_card_serial")))
            return IS_UNABLE_TO_LOAD_LIBRARY;
    }
    return c_is_iso14443a_card_serial(handle, read_buff, buff_lens, buzzerOn, timeOut);
}

// iso14443B serial reader
typedef int (*type_c_is_iso14443b_card_serial) (int , unsigned char *, int *, int , int) ;
static type_c_is_iso14443b_card_serial c_is_iso14443b_card_serial = 0;
int is_iso14443b_card_serial(
    int handle,							//handle
	unsigned char *read_buff,			//card serial data
	int *buff_lens,						//card serial length
	int buzzerOn,						//buzzer ono/off
	int timeOut							//time out (ms)
)
{
    if (c_is_iso14443b_card_serial == 0) {
        if (!(c_is_iso14443b_card_serial = (type_c_is_iso14443b_card_serial)_loadFunction("c_is_iso14443b_card_serial")))
            return IS_UNABLE_TO_LOAD_LIBRARY;
    }
    return c_is_iso14443b_card_serial(handle, read_buff, buff_lens, buzzerOn, timeOut);
}

// felica serial reader
typedef int (*type_c_is_felica_card_serial) (int , unsigned char *, int *, int , int) ;
static type_c_is_felica_card_serial c_is_felica_card_serial = 0;
int is_felica_card_serial(
    int handle,							//handle
	unsigned char *read_buff,			//card serial data
	int *buff_lens,						//card serial length
	int buzzerOn,						//buzzer ono/off
	int timeOut							//time out (ms)
)
{
    if (c_is_felica_card_serial == 0) {
        if (!(c_is_felica_card_serial = (type_c_is_felica_card_serial)_loadFunction("c_is_felica_card_serial")))
            return IS_UNABLE_TO_LOAD_LIBRARY;
    }
    return c_is_felica_card_serial(handle, read_buff, buff_lens, buzzerOn, timeOut);
}

// iso15693 serial reader
typedef int (*type_c_is_iso15693_card_serial) (int , unsigned char *, int *, int , int) ;
static type_c_is_iso15693_card_serial c_is_iso15693_card_serial = 0;
int is_iso15693_card_serial(
    int handle,							//handle
	unsigned char *read_buff,			//card serial data
	int *buff_lens,						//card serial length
	int buzzerOn,						//buzzer ono/off
	int timeOut							//time out (ms)
)
{
    if (c_is_iso15693_card_serial == 0) {
        if (!(c_is_iso15693_card_serial = (type_c_is_iso15693_card_serial)_loadFunction("c_is_iso15693_card_serial")))
            return IS_UNABLE_TO_LOAD_LIBRARY;
    }
    return c_is_iso15693_card_serial(handle, read_buff, buff_lens, buzzerOn, timeOut);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//																															//
//			Mifare Classic Function																								//
//																															//
//																															//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Mifare Classic Card Active
typedef int (*type_c_is_mifare_active) (int , unsigned char *, int *, int , int) ;
static type_c_is_mifare_active c_is_mifare_active = 0;
int is_mifare_active(
    int handle,
	unsigned char *read_buff, 
	int *buff_lens,
	int buzzerOn, 
	int timeOut
)
{
    if (c_is_mifare_active == 0) {
        if (!(c_is_mifare_active = (type_c_is_mifare_active)_loadFunction("c_is_mifare_active")))
            return IS_UNABLE_TO_LOAD_LIBRARY;
    }
    return c_is_mifare_active(handle, read_buff, buff_lens, buzzerOn, timeOut);
}

// Mifare Classic Card Authentication
typedef int (*type_c_is_mifare_authentication) (int , int ,  int , unsigned char *, int, int , int ) ;
static type_c_is_mifare_authentication c_is_mifare_authentication = 0;
int is_mifare_authentication(
    int handle,
	int block_Number,  
	int keytype, 
	unsigned char *auth_key, 
	int authKey_lens, 
	int buzzerOn, 
	int timeOut
)
{
    if (c_is_mifare_authentication == 0) {
        if (!(c_is_mifare_authentication = (type_c_is_mifare_authentication)_loadFunction("c_is_mifare_authentication")))
            return IS_UNABLE_TO_LOAD_LIBRARY;
    }
    return c_is_mifare_authentication(handle, block_Number, keytype, auth_key, authKey_lens, buzzerOn, timeOut);
}

// Mifare Classic Card Block Read
typedef int (*type_c_is_mifare_block_read) (int , int, unsigned char *, int *, int , int) ;
static type_c_is_mifare_block_read c_is_mifare_block_read = 0;
int is_mifare_block_read(
   int handle, 
   int block_Number,  
   unsigned char *read_block_buff, 
   int *read_block_lens, 
   int buzzerOn, 
   int timeOut
   )
{
    if (c_is_mifare_block_read == 0) {
        if (!(c_is_mifare_block_read = (type_c_is_mifare_block_read)_loadFunction("c_is_mifare_block_read")))
            return IS_UNABLE_TO_LOAD_LIBRARY;
    }
    return c_is_mifare_block_read(handle, block_Number, read_block_buff, read_block_lens, buzzerOn, timeOut);
}

// Mifare Classic Card Authentication & Block Read 동시 수행
typedef int (*type_c_is_mifare_block_read_ext) (int , mifare_block_type *mifare_block, int , int) ;
static type_c_is_mifare_block_read_ext c_is_mifare_block_read_ext = 0;
int is_mifare_block_read_ext(
   int handle, 
   mifare_block_type *mifare_block,
   int buzzerOn, 
   int timeOut
   )
{
    if (c_is_mifare_block_read_ext == 0) {
        if (!(c_is_mifare_block_read_ext = (type_c_is_mifare_block_read_ext)_loadFunction("c_is_mifare_block_read_ext")))
            return IS_UNABLE_TO_LOAD_LIBRARY;
    }
    return c_is_mifare_block_read_ext(handle, mifare_block, buzzerOn, timeOut);
}

// Mifare Classic Card Sector Read (64Byte Read)
typedef int (*type_c_is_mifare_sector_read) (int , int, unsigned char *, int *, int , int) ;
static type_c_is_mifare_sector_read c_is_mifare_sector_read = 0;
int is_mifare_sector_read(
   int handle, 
   int sector_Number,  
   unsigned char *read_sector_buff, 
   int *read_sector_lens, 
   int buzzerOn, 
   int timeOut
   )
{
    if (c_is_mifare_sector_read == 0) {
        if (!(c_is_mifare_sector_read = (type_c_is_mifare_sector_read)_loadFunction("c_is_mifare_sector_read")))
            return IS_UNABLE_TO_LOAD_LIBRARY;
    }
    return c_is_mifare_sector_read(handle, sector_Number, read_sector_buff, read_sector_lens, buzzerOn, timeOut);
}

// Mifare Classic Card Authentication & Sector Read (64Byte Read) 동시 수행
typedef int (*type_c_is_mifare_sector_read_ext) (int , mifare_sector_type *, int , int) ;
static type_c_is_mifare_sector_read_ext c_is_mifare_sector_read_ext = 0;
int is_mifare_sector_read_ext(
   int handle, 
   mifare_sector_type *mifare_sector,
   int buzzerOn, 
   int timeOut
   )
{
    if (c_is_mifare_sector_read_ext == 0) {
        if (!(c_is_mifare_sector_read_ext = (type_c_is_mifare_sector_read_ext)_loadFunction("c_is_mifare_sector_read_ext")))
            return IS_UNABLE_TO_LOAD_LIBRARY;
    }
    return c_is_mifare_sector_read_ext(handle, mifare_sector, buzzerOn, timeOut);
}

// Mifare Classic Card Block Write
typedef int (*type_c_is_mifare_block_write) (int , int, unsigned char *, int , int , int) ;
static type_c_is_mifare_block_write c_is_mifare_block_write = 0;
int is_mifare_block_write(
   int handle, 
   int block_Number,  
   unsigned char *write_block_buff, 
   int write_block_lens, 
   int buzzerOn, 
   int timeOut
   )
{
    if (c_is_mifare_block_write == 0) {
        if (!(c_is_mifare_block_write = (type_c_is_mifare_block_write)_loadFunction("c_is_mifare_block_write")))
            return IS_UNABLE_TO_LOAD_LIBRARY;
    }
    return c_is_mifare_block_write(handle, block_Number, write_block_buff, write_block_lens, buzzerOn, timeOut);
}

// Mifare Classic Card Sector Write (48Byte Write)
typedef int (*type_c_is_mifare_sector_write) (int , int, unsigned char *, int , int , int) ;
static type_c_is_mifare_sector_write c_is_mifare_sector_write = 0;
int is_mifare_sector_write(
   int handle, 
   int sector_Number,  
   unsigned char *write_sector_buff, 
   int write_sector_lens, 
   int buzzerOn, 
   int timeOut
   )
{
    if (c_is_mifare_sector_write == 0) {
        if (!(c_is_mifare_sector_write = (type_c_is_mifare_sector_write)_loadFunction("c_is_mifare_sector_write")))
            return IS_UNABLE_TO_LOAD_LIBRARY;
    }
    return c_is_mifare_sector_write(handle, sector_Number, write_sector_buff, write_sector_lens, buzzerOn, timeOut);
}

// Mifare Classic Card Authentication & Block Write 동시 수행
typedef int (*type_c_is_mifare_block_write_ext) (int , mifare_block_type *mifare_block, int , int) ;
static type_c_is_mifare_block_write_ext c_is_mifare_block_write_ext = 0;
int is_mifare_block_write_ext(
   int handle, 
   mifare_block_type *mifare_block,
   int buzzerOn, 
   int timeOut
   )
{
    if (c_is_mifare_block_write_ext == 0) {
        if (!(c_is_mifare_block_write_ext = (type_c_is_mifare_block_write_ext)_loadFunction("c_is_mifare_block_write_ext")))
            return IS_UNABLE_TO_LOAD_LIBRARY;
    }
    return c_is_mifare_block_write_ext(handle, mifare_block, buzzerOn, timeOut);
}

// Mifare Classic Card Authentication & Sector Write (48Byte Write) 동시 수행
typedef int (*type_c_is_mifare_sector_write_ext) (int , mifare_sector_type *, int , int) ;
static type_c_is_mifare_sector_write_ext c_is_mifare_sector_write_ext = 0;
int is_mifare_sector_write_ext(
   int handle, 
   mifare_sector_type *mifare_sector,
   int buzzerOn, 
   int timeOut
   )
{
    if (c_is_mifare_sector_write_ext == 0) {
        if (!(c_is_mifare_sector_write_ext = (type_c_is_mifare_sector_write_ext)_loadFunction("c_is_mifare_sector_write_ext")))
            return IS_UNABLE_TO_LOAD_LIBRARY;
    }
    return c_is_mifare_sector_write_ext(handle, mifare_sector, buzzerOn, timeOut);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//																															//
//			Mifare Classic Card 전자 지갑 Function																								//
//																															//
//																															//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//전자 지갑 : 전자 지갑 생성  
typedef int (*type_c_is_mifare_electronic_purse_create) (int , int, unsigned char *, int , int , int) ;
static type_c_is_mifare_electronic_purse_create c_is_mifare_electronic_purse_create = 0;
int is_mifare_electronic_purse_create(
   int handle, 
   int block_Number,  
   unsigned char *money_value_buff, 
   int money_value_lens, 
   int buzzerOn, 
   int timeOut
   )
{
    if (c_is_mifare_electronic_purse_create == 0) {
        if (!(c_is_mifare_electronic_purse_create = (type_c_is_mifare_electronic_purse_create)_loadFunction("c_is_mifare_electronic_purse_create")))
            return IS_UNABLE_TO_LOAD_LIBRARY;
    }
    return c_is_mifare_electronic_purse_create(handle, block_Number, money_value_buff, money_value_lens, buzzerOn, timeOut);
}

//전자 지갑 : 전자 지갑 잔액 조회
typedef int (*type_c_is_mifare_electronic_purse_read) (int , int, unsigned char *, int* , int , int) ;
static type_c_is_mifare_electronic_purse_read c_is_mifare_electronic_purse_read = 0;
int is_mifare_electronic_purse_read(
   int handle, 
   int block_Number,  
   unsigned char *money_value_buff, 
   int *money_value_lens, 
   int buzzerOn, 
   int timeOut
   )
{
    if (c_is_mifare_electronic_purse_read == 0) {
        if (!(c_is_mifare_electronic_purse_read = (type_c_is_mifare_electronic_purse_read)_loadFunction("c_is_mifare_electronic_purse_read")))
            return IS_UNABLE_TO_LOAD_LIBRARY;
    }
    return c_is_mifare_electronic_purse_read(handle, block_Number, money_value_buff, money_value_lens, buzzerOn, timeOut);
}

//전자 지갑 : 전자 지갑 머니 충전(증가)  
typedef int (*type_c_is_mifare_electronic_purse_increment) (int , int, unsigned char *, int , int , int) ;
static type_c_is_mifare_electronic_purse_increment c_is_mifare_electronic_purse_increment = 0;
int is_mifare_electronic_purse_increment(
   int handle, 
   int block_Number,  
   unsigned char *money_value_buff, 
   int money_value_lens, 
   int buzzerOn, 
   int timeOut
   )
{
    if (c_is_mifare_electronic_purse_increment == 0) {
        if (!(c_is_mifare_electronic_purse_increment = (type_c_is_mifare_electronic_purse_increment)_loadFunction("c_is_mifare_electronic_purse_increment")))
            return IS_UNABLE_TO_LOAD_LIBRARY;
    }
    return c_is_mifare_electronic_purse_increment(handle, block_Number, money_value_buff, money_value_lens, buzzerOn, timeOut);
}

//전자 지갑 : 전자 지갑 머니 거래(감소) 
typedef int (*type_c_is_mifare_electronic_purse_decrement) (int , int, unsigned char *, int , int , int) ;
static type_c_is_mifare_electronic_purse_decrement c_is_mifare_electronic_purse_decrement = 0;
int is_mifare_electronic_purse_decrement(
   int handle, 
   int block_Number,  
   unsigned char *money_value_buff, 
   int money_value_lens, 
   int buzzerOn, 
   int timeOut
   )
{
    if (c_is_mifare_electronic_purse_decrement == 0) {
        if (!(c_is_mifare_electronic_purse_decrement = (type_c_is_mifare_electronic_purse_decrement)_loadFunction("c_is_mifare_electronic_purse_decrement")))
            return IS_UNABLE_TO_LOAD_LIBRARY;
    }
    return c_is_mifare_electronic_purse_decrement(handle, block_Number, money_value_buff, money_value_lens, buzzerOn, timeOut);
}

//전자 지갑 : 거래 저장 
typedef int (*type_c_is_mifare_electronic_purse_transfer) (int , int, int , int) ;
static type_c_is_mifare_electronic_purse_transfer c_is_mifare_electronic_purse_transfer = 0;
int is_mifare_electronic_purse_transfer(
   int handle, 
   int block_Number,  
   int buzzerOn, 
   int timeOut
   )
{
    if (c_is_mifare_electronic_purse_transfer == 0) {
        if (!(c_is_mifare_electronic_purse_transfer = (type_c_is_mifare_electronic_purse_transfer)_loadFunction("c_is_mifare_electronic_purse_transfer")))
            return IS_UNABLE_TO_LOAD_LIBRARY;
    }
    return c_is_mifare_electronic_purse_transfer(handle, block_Number, buzzerOn, timeOut);
}

//전자 지갑 : 이전 거래 취소 
typedef int (*type_c_is_mifare_electronic_purse_restore) (int , int, int , int) ;
static type_c_is_mifare_electronic_purse_restore c_is_mifare_electronic_purse_restore = 0;
int is_mifare_electronic_purse_restore(
   int handle, 
   int block_Number,  
   int buzzerOn, 
   int timeOut
   )
{
    if (c_is_mifare_electronic_purse_restore == 0) {
        if (!(c_is_mifare_electronic_purse_restore = (type_c_is_mifare_electronic_purse_restore)_loadFunction("c_is_mifare_electronic_purse_restore")))
            return IS_UNABLE_TO_LOAD_LIBRARY;
    }
    return c_is_mifare_electronic_purse_restore(handle, block_Number, buzzerOn, timeOut);
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//																															//
//			Mifare UltraLight Card Function																								//
//																															//
//																															//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//mifare ultraLight block read 
typedef int (*type_c_is_mifare_ultralight_block_read) (int , int, unsigned char *, int *, int , int) ;
static type_c_is_mifare_ultralight_block_read c_is_mifare_ultralight_block_read = 0;
int is_mifare_ultralight_block_read(
   int handle, 
   int block_Number,  
   unsigned char *read_block_buff, 
   int *read_block_lens, 
   int buzzerOn, 
   int timeOut
   )
{
    if (c_is_mifare_ultralight_block_read == 0) {
        if (!(c_is_mifare_ultralight_block_read = (type_c_is_mifare_ultralight_block_read)_loadFunction("c_is_mifare_ultralight_block_read")))
            return IS_UNABLE_TO_LOAD_LIBRARY;
    }
    return c_is_mifare_ultralight_block_read(handle, block_Number, read_block_buff, read_block_lens, buzzerOn, timeOut);
}

//mifare ultraLight 전체 block read 
typedef int (*type_c_is_mifare_ultralight_all_block_read) (int , unsigned char *, int *, int , int) ;
static type_c_is_mifare_ultralight_all_block_read c_is_mifare_ultralight_all_block_read = 0;
int is_mifare_ultralight_all_block_read(
   int handle, 
   unsigned char *read_block_buff, 
   int *read_block_lens, 
   int buzzerOn, 
   int timeOut
   )
{
    if (c_is_mifare_ultralight_all_block_read == 0) {
        if (!(c_is_mifare_ultralight_all_block_read = (type_c_is_mifare_ultralight_all_block_read)_loadFunction("c_is_mifare_ultralight_all_block_read")))
            return IS_UNABLE_TO_LOAD_LIBRARY;
    }
    return c_is_mifare_ultralight_all_block_read(handle, read_block_buff, read_block_lens, buzzerOn, timeOut);
}

//mifare ultraLight block write
typedef int (*type_c_is_mifare_ultralight_block_write) (int , int, unsigned char *, int , int , int) ;
static type_c_is_mifare_ultralight_block_write c_is_mifare_ultralight_block_write = 0;
int is_mifare_ultralight_block_write(
   int handle, 
   int block_Number,  
   unsigned char *write_block_buff, 
   int write_block_lens, 
   int buzzerOn, 
   int timeOut
   )
{
    if (c_is_mifare_ultralight_block_write == 0) {
        if (!(c_is_mifare_ultralight_block_write = (type_c_is_mifare_ultralight_block_write)_loadFunction("c_is_mifare_ultralight_block_write")))
            return IS_UNABLE_TO_LOAD_LIBRARY;
    }
    return c_is_mifare_ultralight_block_write(handle, block_Number, write_block_buff, write_block_lens, buzzerOn, timeOut);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//																															//
//			RF Function																								//
//																															//
//																															//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//RF Off : Card에 전원 차단 
typedef int (*type_c_is_rf_off) (int , int , int) ;
static type_c_is_rf_off c_is_rf_off = 0;
int is_rf_off(
   int handle, 
   int buzzerOn, 
   int timeOut
   )
{
    if (c_is_rf_off == 0) {
        if (!(c_is_rf_off = (type_c_is_rf_off)_loadFunction("c_is_rf_off")))
            return IS_UNABLE_TO_LOAD_LIBRARY;
    }
    return c_is_rf_off(handle, buzzerOn, timeOut);
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//																															//
//			ISO 14443 A/B Function																								//
//																															//
//																															//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// ISO 14443 A/B Card Active
typedef int (*type_c_is_apdu_active) (int , unsigned char *, int *, int , int) ;
static type_c_is_apdu_active c_is_apdu_active = 0;
int is_apdu_active(
   int handle, 
   unsigned char *read_buff, 
   int *read_lens, 
   int buzzerOn, 
   int timeOut
   )
{
    if (c_is_apdu_active == 0) {
        if (!(c_is_apdu_active = (type_c_is_apdu_active)_loadFunction("c_is_apdu_active")))
            return IS_UNABLE_TO_LOAD_LIBRARY;
    }
    return c_is_apdu_active(handle, read_buff, read_lens, buzzerOn, timeOut);
}

// ISO 14443 A/B Card Block Read/Write (APDU)
typedef int (*type_c_is_apdu_command) (int , unsigned char *, int, unsigned char *, int *, int , int) ;
static type_c_is_apdu_command c_is_apdu_command = 0;
int is_apdu_command(
   int handle, 
   unsigned char *apdu_command_buff, 
   int apdu_command_lens, 
   unsigned char *read_buff, 
   int *read_lens, 
   int buzzerOn, 
   int timeOut
   )
{
    if (c_is_apdu_command == 0) {
        if (!(c_is_apdu_command = (type_c_is_apdu_command)_loadFunction("c_is_apdu_command")))
            return IS_UNABLE_TO_LOAD_LIBRARY;
    }
    return c_is_apdu_command(handle, apdu_command_buff, apdu_command_lens, read_buff, read_lens, buzzerOn, timeOut);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//																															//
//			T-money , K-cash Function																								//
//																															//
//																															//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


//T-Money 잔액 조회  
typedef int (*type_c_is_t_money_balance) (int , unsigned char *, int* , int , int) ;
static type_c_is_t_money_balance c_is_t_money_balance = 0;
int is_t_money_balance(
   int handle, 
   unsigned char *money_value_buff, 
   int *money_value_lens, 
   int buzzerOn, 
   int timeOut
   )
{
    if (c_is_t_money_balance == 0) {
        if (!(c_is_t_money_balance = (type_c_is_t_money_balance)_loadFunction("c_is_t_money_balance")))
            return IS_UNABLE_TO_LOAD_LIBRARY;
    }
    return c_is_t_money_balance(handle, money_value_buff, money_value_lens, buzzerOn, timeOut);
}


//K Cash-Money 잔액 조회  
typedef int (*type_c_is_kcash_money_balance) (int , unsigned char *, int* , int , int) ;
static type_c_is_kcash_money_balance c_is_kcash_money_balance = 0;
int is_kcash_money_balance(
   int handle, 
   unsigned char *money_value_buff, 
   int *money_value_lens, 
   int buzzerOn, 
   int timeOut
   )
{
    if (c_is_kcash_money_balance == 0) {
        if (!(c_is_kcash_money_balance = (type_c_is_kcash_money_balance)_loadFunction("c_is_kcash_money_balance")))
            return IS_UNABLE_TO_LOAD_LIBRARY;
    }
    return c_is_kcash_money_balance(handle, money_value_buff, money_value_lens, buzzerOn, timeOut);
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//																															//
//			ISO 15693 Function																								//
//																															//
//																															//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//iso15693 Card Active
typedef int (*type_c_is_iso15693_active) (int , unsigned char *, int *, int , int) ;
static type_c_is_iso15693_active c_is_iso15693_active = 0;
int is_iso15693_active(
   int handle, 
   unsigned char *read_buff, 
   int *read_lens, 
   int buzzerOn, 
   int timeOut
   )
{
    if (c_is_iso15693_active == 0) {
        if (!(c_is_iso15693_active = (type_c_is_iso15693_active)_loadFunction("c_is_iso15693_active")))
            return IS_UNABLE_TO_LOAD_LIBRARY;
    }
    return c_is_iso15693_active(handle, read_buff, read_lens, buzzerOn, timeOut);
}


//iso15693 block read 
typedef int (*type_c_is_iso15693_block_read) (int , int , unsigned char *, int *, int , int) ;
static type_c_is_iso15693_block_read c_is_iso15693_block_read = 0;
int is_iso15693_block_read(
   int handle, 
   int block_number, 
   unsigned char *read_block_buff, 
   int *read_block_lens, 
   int buzzerOn, 
   int timeOut
   )
{
    if (c_is_iso15693_block_read == 0) {
        if (!(c_is_iso15693_block_read = (type_c_is_iso15693_block_read)_loadFunction("c_is_iso15693_block_read")))
            return IS_UNABLE_TO_LOAD_LIBRARY;
    }
    return c_is_iso15693_block_read(handle, block_number, read_block_buff, read_block_lens, buzzerOn, timeOut);
}

//iso15693 multi block read 
typedef int (*type_c_is_iso15693_multi_block_read) (int , int , int, unsigned char *, int *, int , int) ;
static type_c_is_iso15693_multi_block_read c_is_iso15693_multi_block_read = 0;
int is_iso15693_multi_block_read(
   int handle, 
   int block_number, 
   int block_count, 
   unsigned char *read_block_buff, 
   int *read_block_lens, 
   int buzzerOn, 
   int timeOut
   )
{
    if (c_is_iso15693_multi_block_read == 0) {
        if (!(c_is_iso15693_multi_block_read = (type_c_is_iso15693_multi_block_read)_loadFunction("c_is_iso15693_multi_block_read")))
            return IS_UNABLE_TO_LOAD_LIBRARY;
    }
    return c_is_iso15693_multi_block_read(handle, block_number, block_count, read_block_buff, read_block_lens, buzzerOn, timeOut);
}


//iso15693 block write 
typedef int (*type_c_is_iso15693_block_write) (int , int , unsigned char *, int , int , int) ;
static type_c_is_iso15693_block_write c_is_iso15693_block_write = 0;
int is_iso15693_block_write(
   int handle, 
   int block_number, 
   unsigned char *write_block_buff, 
   int write_size, 
   int buzzerOn, 
   int timeOut
   )
{
    if (c_is_iso15693_block_write == 0) {
        if (!(c_is_iso15693_block_write = (type_c_is_iso15693_block_write)_loadFunction("c_is_iso15693_block_write")))
            return IS_UNABLE_TO_LOAD_LIBRARY;
    }
    return c_is_iso15693_block_write(handle, block_number, write_block_buff, write_size, buzzerOn, timeOut);
}

//iso15693 block lock 
typedef int (*type_c_is_iso15693_block_lock) (int , int , int , int) ;
static type_c_is_iso15693_block_lock c_is_iso15693_block_lock = 0;
int is_iso15693_block_lock(
   int handle, 
   int block_number, 
   int buzzerOn, 
   int timeOut
   )
{
    if (c_is_iso15693_block_lock == 0) {
        if (!(c_is_iso15693_block_lock = (type_c_is_iso15693_block_lock)_loadFunction("c_is_iso15693_block_lock")))
            return IS_UNABLE_TO_LOAD_LIBRARY;
    }
    return c_is_iso15693_block_lock(handle, block_number, buzzerOn, timeOut);
}

//iso15693 afi write 
typedef int (*type_c_is_iso15693_afi_write) (int , int , int , int) ;
static type_c_is_iso15693_afi_write c_is_iso15693_afi_write = 0;
int is_iso15693_afi_write(
   int handle, 
   int afi_data, 
   int buzzerOn, 
   int timeOut
   )
{
    if (c_is_iso15693_afi_write == 0) {
        if (!(c_is_iso15693_afi_write = (type_c_is_iso15693_afi_write)_loadFunction("c_is_iso15693_afi_write")))
            return IS_UNABLE_TO_LOAD_LIBRARY;
    }
    return c_is_iso15693_afi_write(handle, afi_data, buzzerOn, timeOut);
}

//iso15693 dsfid write 
typedef int (*type_c_is_iso15693_dsfid_write) (int , int , int , int) ;
static type_c_is_iso15693_dsfid_write c_is_iso15693_dsfid_write = 0;
int is_iso15693_dsfid_write(
   int handle, 
   int dsfid_data, 
   int buzzerOn, 
   int timeOut
   )
{
    if (c_is_iso15693_dsfid_write == 0) {
        if (!(c_is_iso15693_dsfid_write = (type_c_is_iso15693_dsfid_write)_loadFunction("c_is_iso15693_dsfid_write")))
            return IS_UNABLE_TO_LOAD_LIBRARY;
    }
    return c_is_iso15693_dsfid_write(handle, dsfid_data, buzzerOn, timeOut);
}


//iso15693 AFI Lock
typedef int (*type_c_is_iso15693_afi_lock) (int , int , int) ;
static type_c_is_iso15693_afi_lock c_is_iso15693_afi_lock = 0;
int is_iso15693_afi_lock(
   int handle, 
   int buzzerOn, 
   int timeOut
   )
{
    if (c_is_iso15693_afi_lock == 0) {
        if (!(c_is_iso15693_afi_lock = (type_c_is_iso15693_afi_lock)_loadFunction("c_is_iso15693_afi_lock")))
            return IS_UNABLE_TO_LOAD_LIBRARY;
    }
    return c_is_iso15693_afi_lock(handle, buzzerOn, timeOut);
}

//iso15693 DSFID Lock
typedef int (*type_c_is_iso15693_dsfid_lock) (int , int , int) ;
static type_c_is_iso15693_dsfid_lock c_is_iso15693_dsfid_lock = 0;
int is_iso15693_dsfid_lock(
   int handle, 
   int buzzerOn, 
   int timeOut
   )
{
    if (c_is_iso15693_dsfid_lock == 0) {
        if (!(c_is_iso15693_dsfid_lock = (type_c_is_iso15693_dsfid_lock)_loadFunction("c_is_iso15693_dsfid_lock")))
            return IS_UNABLE_TO_LOAD_LIBRARY;
    }
    return c_is_iso15693_dsfid_lock(handle, buzzerOn, timeOut);
}

//iso15693 Get Sys
typedef int (*type_c_is_iso15693_get_sys) (int , unsigned char *, int *, int , int) ;
static type_c_is_iso15693_get_sys c_is_iso15693_get_sys = 0;
int is_iso15693_get_sys(
   int handle, 
   unsigned char *read_buff, 
   int *read_lens, 
   int buzzerOn, 
   int timeOut
   )
{
    if (c_is_iso15693_get_sys == 0) {
        if (!(c_is_iso15693_get_sys = (type_c_is_iso15693_get_sys)_loadFunction("c_is_iso15693_get_sys")))
            return IS_UNABLE_TO_LOAD_LIBRARY;
    }
    return c_is_iso15693_get_sys(handle, read_buff, read_lens, buzzerOn, timeOut);
}

//iso15693 Stay Quiet
typedef int (*type_c_is_iso15693_stay_quiet) (int , int , int) ;
static type_c_is_iso15693_stay_quiet c_is_iso15693_stay_quiet = 0;
int is_iso15693_stay_quiet(
   int handle, 
   int buzzerOn, 
   int timeOut
   )
{
    if (c_is_iso15693_stay_quiet == 0) {
        if (!(c_is_iso15693_stay_quiet = (type_c_is_iso15693_stay_quiet)_loadFunction("c_is_iso15693_stay_quiet")))
            return IS_UNABLE_TO_LOAD_LIBRARY;
    }
    return c_is_iso15693_stay_quiet(handle, buzzerOn, timeOut);
}

//iso15693 reset to ready
typedef int (*type_c_is_iso15693_reset_to_ready) (int , int , int) ;
static type_c_is_iso15693_reset_to_ready c_is_iso15693_reset_to_ready = 0;
int is_iso15693_reset_to_ready(
   int handle, 
   int buzzerOn, 
   int timeOut
   )
{
    if (c_is_iso15693_reset_to_ready == 0) {
        if (!(c_is_iso15693_reset_to_ready = (type_c_is_iso15693_reset_to_ready)_loadFunction("c_is_iso15693_reset_to_ready")))
            return IS_UNABLE_TO_LOAD_LIBRARY;
    }
    return c_is_iso15693_reset_to_ready(handle, buzzerOn, timeOut);
}
