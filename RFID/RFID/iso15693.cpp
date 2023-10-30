#include <windows.h>
#include <stdio.h>
#include "is_usb.h"


typedef	enum
{
	ISO15693_BLOCK_READ,		//ISO 15693 Block Read Example
	ISO15693_MULTI_BLOCK_READ,	//ISO 15693 Multi Block Read Example
	ISO15693_BLOCK_WRITE,		 //ISO 15693 Block Write Example
	ISO15693_BLOCK_LOCK,		//ISO 15693 Block Lock Example
	ISO15693_AFI_WRITE,			//ISO 15693 AFI Write Example
	ISO15693_DSFID_WRITE,		//ISO 15693 DSFID Write Example
	ISO15693_AFI_LOCK,			//ISO 15693 AFI Lock Example
	ISO15693_DSFID_LCOK,		//ISO 15693 DSFID Lock Read Example
	ISO15693_GET_SYS,			//ISO 15693 Card 정보 읽기 Example
	ISO15693_STAY_QUIET,		//ISO 15693 Card Halt Example
	ISO15693_RESET_TO_READY,	//ISO 15693 Card Reset Example
}card_enum;


int main(void)
{
    int port;
	int card_select = 0;
    int handle;
	int stop = 1;
		
	port    = 0;

	// card_select 변수 값 변경으로 쉽게 테스트 해볼수 있습니다.
	card_select = ISO15693_STAY_QUIET;

	handle  = is_open_usb(port);
	if (handle <= 0) {
        printf("Unable to open IS USB device on port %d\n", port);
        return 1;
    }
	while(stop)
	{
		switch(card_select)
		{
			//ISO 15693 Block Read Example
			case ISO15693_BLOCK_READ:
			{
				unsigned char read_buff[256];
				int buff_lens, row;
				int block_number = 0;

				if (is_iso15693_active(handle, read_buff, &buff_lens, BUZZER_OFF, 500) == IS_OK)
				{
					printf(" - ISO 15693 card serial : ");
					for(row = 0; row < buff_lens; row++)
						printf("%02x ",read_buff[row]);
					
					if (is_iso15693_block_read(handle, block_number, read_buff, &buff_lens, BUZZER_ON, 500) == IS_OK)
					{
						printf("\n - ISO 15693 block : %02X \n\r block data : ", block_number);
						for(row = 0; row < buff_lens; row++)
						{
							printf("%02x ",read_buff[row]);
						}
						stop = 0;
					}
					is_rf_off(handle, BUZZER_OFF, 100);
				}

			}
			break;

			//ISO 15693 Multi Block Read Example
			case ISO15693_MULTI_BLOCK_READ:
			{
				unsigned char read_buff[256];
				int buff_lens, row;
				int block_number = 0;
				int block_count = 10;

				if (is_iso15693_active(handle, read_buff, &buff_lens, BUZZER_OFF, 500) == IS_OK)
				{
					printf(" - ISO 15693 card serial : ");
					for(row = 0; row < buff_lens; row++)
						printf("%02x ",read_buff[row]);
					
					if (is_iso15693_multi_block_read(handle, block_number, block_count, read_buff, &buff_lens, BUZZER_ON, 500) == IS_OK)
					{
						printf("\n - ISO 15693 block : %02X \n\r block data : ", block_number);
						for(row = 0; row < buff_lens; row++)
						{
							printf("%02x ",read_buff[row]);
						}
						stop = 0;
					}
					is_rf_off(handle, BUZZER_OFF, 100);
				}

			}
			break;
			
			//ISO 15693 Block Write Example
			case ISO15693_BLOCK_WRITE:
			{
				unsigned char read_buff[256];
				int buff_lens, row;
				int block_number = 0;
				unsigned char write_block_data[4] = { 0x01, 0x02, 0x03, 0x04};
				

				if (is_iso15693_active(handle, read_buff, &buff_lens, BUZZER_OFF, 500) == IS_OK)
				{
					printf(" - ISO 15693 card serial : ");
					for(row = 0; row < buff_lens; row++)
						printf("%02x ",read_buff[row]);
					
					if (is_iso15693_block_write(handle, block_number, write_block_data, sizeof(write_block_data), BUZZER_ON, 500) == IS_OK)
					{
						printf("\n - ISO 15693 block : %02X Write 성공\n ", block_number);
						stop = 0;
					}
					is_rf_off(handle, BUZZER_OFF, 100);
				}

			}
			break;
			
			//ISO 15693 Block Lock Example
			case ISO15693_BLOCK_LOCK:
			{
				unsigned char read_buff[256];
				int buff_lens, row;
				int block_number = 3;
				
				if (is_iso15693_active(handle, read_buff, &buff_lens, BUZZER_OFF, 500) == IS_OK)
				{
					printf(" - ISO 15693 card serial : ");
					for(row = 0; row < buff_lens; row++)
						printf("%02x ",read_buff[row]);
					
					if (is_iso15693_block_lock(handle, block_number, BUZZER_ON, 500) == IS_OK)
					{
						printf("\n - ISO 15693 block  : %02X Lock 성공\n ", block_number);
						stop = 0;
					}
					is_rf_off(handle, BUZZER_OFF, 100);
				}

			}
			break;

			//ISO 15693 AFI Write Example
			case ISO15693_AFI_WRITE:
			{
				unsigned char read_buff[256];
				int buff_lens, row;
				int afi_data = 0x01;
				
				if (is_iso15693_active(handle, read_buff, &buff_lens, BUZZER_OFF, 500) == IS_OK)
				{
					printf(" - ISO 15693 card serial : ");
					for(row = 0; row < buff_lens; row++)
						printf("%02x ",read_buff[row]);
					
					if (is_iso15693_afi_write(handle, afi_data, BUZZER_ON, 500) == IS_OK)
					{
						printf("\n - ISO 15693 AFI %02x Write 성공\n ", afi_data);
						stop = 0;
					}
					is_rf_off(handle, BUZZER_OFF, 100);
				}

			}
			break;
	
			//ISO 15693 DSFID Write Example
			case ISO15693_DSFID_WRITE:
			{
				unsigned char read_buff[256];
				int buff_lens, row;
				int dsfid_data = 0x02;
				
				if (is_iso15693_active(handle, read_buff, &buff_lens, BUZZER_OFF, 500) == IS_OK)
				{
					printf(" - ISO 15693 card serial : ");
					for(row = 0; row < buff_lens; row++)
						printf("%02x ",read_buff[row]);
					
					if (is_iso15693_dsfid_write(handle, dsfid_data, BUZZER_ON, 500) == IS_OK)
					{
						printf("\n - ISO 15693 DSFID %02x Write 성공\n ", dsfid_data);
						stop = 0;
					}
					is_rf_off(handle, BUZZER_OFF, 100);
				}

			}
			break;

			//ISO 15693 AFI Lock Example
			case ISO15693_AFI_LOCK:
			{
				unsigned char read_buff[256];
				int buff_lens, row;
				
				if (is_iso15693_active(handle, read_buff, &buff_lens, BUZZER_OFF, 500) == IS_OK)
				{
					printf(" - ISO 15693 card serial : ");
					for(row = 0; row < buff_lens; row++)
						printf("%02x ",read_buff[row]);
					
					if (is_iso15693_afi_lock(handle, BUZZER_ON, 500) == IS_OK)
					{
						printf("\n - ISO 15693 AFI Lock 성공\n ");
						stop = 0;
					}
					is_rf_off(handle, BUZZER_OFF, 100);
				}

			}
			break;

			//ISO 15693 DSFID Lock Example
			case ISO15693_DSFID_LCOK:
			{
				unsigned char read_buff[256];
				int buff_lens, row;
				
				if (is_iso15693_active(handle, read_buff, &buff_lens, BUZZER_OFF, 500) == IS_OK)
				{
					printf(" - ISO 15693 card serial : ");
					for(row = 0; row < buff_lens; row++)
						printf("%02x ",read_buff[row]);
					
					if (is_iso15693_dsfid_lock(handle, BUZZER_ON, 500) == IS_OK)
					{
						printf("\n - ISO 15693 DSFID Lock 성공\n ");
						stop = 0;
					}
					is_rf_off(handle, BUZZER_OFF, 100);
				}

			}
			break;

			//ISO 15693 Card 정보 읽기 Example
			case ISO15693_GET_SYS:
			{
				unsigned char read_buff[256];
				int buff_lens, row;
				
				if (is_iso15693_active(handle, read_buff, &buff_lens, BUZZER_OFF, 500) == IS_OK)
				{
					printf(" - ISO 15693 card serial : ");
					for(row = 0; row < buff_lens; row++)
						printf("%02x ",read_buff[row]);
					
					if (is_iso15693_get_sys(handle, read_buff, &buff_lens, BUZZER_ON, 500) == IS_OK)
					{
						printf("\n - ISO 15693 Get Sys : ");
						for(row = 0; row < buff_lens; row++)
							printf("%02x ",read_buff[row]);
						stop = 0;
					}
					is_rf_off(handle, BUZZER_OFF, 100);
				}

			}
			break;
		
			//ISO 15693 Stay quiet(카드 Halt) Example
			case ISO15693_STAY_QUIET:
			{
				unsigned char read_buff[256];
				int buff_lens, row;
				
				if (is_iso15693_active(handle, read_buff, &buff_lens, BUZZER_OFF, 500) == IS_OK)
				{
					printf(" - ISO 15693 card serial : ");
					for(row = 0; row < buff_lens; row++)
						printf("%02x ",read_buff[row]);
					
					if (is_iso15693_stay_quiet(handle, BUZZER_ON, 500) == IS_OK)
					{
						printf("\n - ISO 15693 Stay Quiet  : Card Halt ");
						stop = 0;
					}
					is_rf_off(handle, BUZZER_OFF, 100);
				}

			}
			break;

			//ISO 15693 Reset To Ready(카드 Reset) Example
			case ISO15693_RESET_TO_READY:
			{
				unsigned char read_buff[256];
				int buff_lens, row;
				
				if (is_iso15693_active(handle, read_buff, &buff_lens, BUZZER_OFF, 500) == IS_OK)
				{
					printf(" - ISO 15693 card serial : ");
					for(row = 0; row < buff_lens; row++)
						printf("%02x ",read_buff[row]);
					
					if (is_iso15693_reset_to_ready(handle, BUZZER_ON, 500) == IS_OK)
					{
						printf("\n - ISO 15693 Reset To Ready  : Card Reset ");
						stop = 0;
					}
					is_rf_off(handle, BUZZER_OFF, 100);
				}

			}
			break;
		}
		
		printf(".\n");
		Sleep(500);	//Polling 500ms 
	}
	if (handle != 0)
		is_close_usb(handle);
	return 0;
}