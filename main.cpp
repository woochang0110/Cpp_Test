#include "cafe.h"



int main(void)
{
	//---object
	Cafe_Menu Coffee_Menu[12];
	Cafe coffee[12];
	//variables
	int order= 0;
	int order_count[12] = { 0 };
	char input[100];
	int i = 0;
	int day_total = 0, total = 0;
	char* ptr;
	
	//coffee_menu 객체 입력
	Coffee_Menu[0].insert_menu("카페_아메리카노", "Short", 3600);
	Coffee_Menu[1].insert_menu("카페_아메리카노", "Tall", 4100);
	Coffee_Menu[2].insert_menu("카페_라떼", "Short", 4100);
	Coffee_Menu[3].insert_menu("카페_라떼", "Tall", 4600);
	Coffee_Menu[4].insert_menu("카푸치노", "Short", 4100);
	Coffee_Menu[5].insert_menu("카푸치노", "Tall", 4600);
	Coffee_Menu[6].insert_menu("카페모카", "Short", 4100);
	Coffee_Menu[7].insert_menu("카페모카", "Tall", 4600);
	Coffee_Menu[8].insert_menu("카라멜_마키아또", "Short", 5100);
	Coffee_Menu[9].insert_menu("카라멜_마키아또", "Tall", 5600);
	Coffee_Menu[10].insert_menu("스타벅스_돌체_라떼", "Short", 5100);
	Coffee_Menu[11].insert_menu("스타벅스_돌체_라떼", "Tall", 5600);



	for (i = 0; i < MENU; i++)//0~11 //12번 루프하면서 coffee_menu 객체 값들을 읽어옴
	{
		coffee[i].enter_menu(Coffee_Menu[i].get_menu_coffee(), Coffee_Menu[i].get_menu_size(), Coffee_Menu[i].get_menu_price());
	}


	//display
	for (i = 0; i < MENU; i++)//0~11 //12번 루프
	{
		coffee[i].display_menu(i);
	}


	//static으로 바꿀만한게 total과 day_total
	while(1)
	{
		cout << "\n주문할 상품의 번호를 입력하세요(ex: 1 11 2 3 5): ";
		cin.getline(input, 100, '\n');
		cout << "\n주문한 상품:"<<endl;
		i = 0, total=0;
		
		//get input and parsing
		ptr = strtok(input, " ");
		while (ptr != NULL)               // 자른 문자열이 나오지 않을 때까지 반복
		{
			//cout << stoi(ptr) << endl;// 자른 문자열 출력
			order = stoi(ptr);
			if (order == 0)
			{
				cout << "\n==============매출 통계=============== " << endl;
				for (i = 0; i < 12; i++)
				{
					if (order_count[i] > 0)
					{
						coffee[i-1].display_menu(i-1, order_count[i]);
					}
				}
				cout << "\n매출액 총계: " << coffee[0].total_price <<endl;
				return 0;
			}
			else if (order > 0 && order < 12)//0~11사이에 정상적 입력이라면
			{
				total += coffee[order-1].get_price();
				order_count[order]++;
				coffee[order-1].display_menu(order-1);
			}

			else 
			{
				cout << order <<"는 없는 메뉴입니다." << endl;
				total = 0;
			}
			ptr = strtok(NULL, " ");      // 다음 문자열을 잘라서 포인터를 반환
		}
		//coffee[0].total_price += total;
		coffee[0].get_total_price(total);

	}
}
