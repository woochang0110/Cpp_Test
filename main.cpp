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
	
	//coffee_menu ��ü �Է�
	Coffee_Menu[0].insert_menu("ī��_�Ƹ޸�ī��", "Short", 3600);
	Coffee_Menu[1].insert_menu("ī��_�Ƹ޸�ī��", "Tall", 4100);
	Coffee_Menu[2].insert_menu("ī��_��", "Short", 4100);
	Coffee_Menu[3].insert_menu("ī��_��", "Tall", 4600);
	Coffee_Menu[4].insert_menu("īǪġ��", "Short", 4100);
	Coffee_Menu[5].insert_menu("īǪġ��", "Tall", 4600);
	Coffee_Menu[6].insert_menu("ī���ī", "Short", 4100);
	Coffee_Menu[7].insert_menu("ī���ī", "Tall", 4600);
	Coffee_Menu[8].insert_menu("ī���_��Ű�ƶ�", "Short", 5100);
	Coffee_Menu[9].insert_menu("ī���_��Ű�ƶ�", "Tall", 5600);
	Coffee_Menu[10].insert_menu("��Ÿ����_��ü_��", "Short", 5100);
	Coffee_Menu[11].insert_menu("��Ÿ����_��ü_��", "Tall", 5600);



	for (i = 0; i < MENU; i++)//0~11 //12�� �����ϸ鼭 coffee_menu ��ü ������ �о��
	{
		coffee[i].enter_menu(Coffee_Menu[i].get_menu_coffee(), Coffee_Menu[i].get_menu_size(), Coffee_Menu[i].get_menu_price());
	}


	//display
	for (i = 0; i < MENU; i++)//0~11 //12�� ����
	{
		coffee[i].display_menu(i);
	}


	//static���� �ٲܸ��Ѱ� total�� day_total
	while(1)
	{
		cout << "\n�ֹ��� ��ǰ�� ��ȣ�� �Է��ϼ���(ex: 1 11 2 3 5): ";
		cin.getline(input, 100, '\n');
		cout << "\n�ֹ��� ��ǰ:"<<endl;
		i = 0, total=0;
		
		//get input and parsing
		ptr = strtok(input, " ");
		while (ptr != NULL)               // �ڸ� ���ڿ��� ������ ���� ������ �ݺ�
		{
			//cout << stoi(ptr) << endl;// �ڸ� ���ڿ� ���
			order = stoi(ptr);
			if (order == 0)
			{
				cout << "\n==============���� ���=============== " << endl;
				for (i = 0; i < 12; i++)
				{
					if (order_count[i] > 0)
					{
						coffee[i-1].display_menu(i-1, order_count[i]);
					}
				}
				cout << "\n����� �Ѱ�: " << coffee[0].total_price <<endl;
				return 0;
			}
			else if (order > 0 && order < 12)//0~11���̿� ������ �Է��̶��
			{
				total += coffee[order-1].get_price();
				order_count[order]++;
				coffee[order-1].display_menu(order-1);
			}

			else 
			{
				cout << order <<"�� ���� �޴��Դϴ�." << endl;
				total = 0;
			}
			ptr = strtok(NULL, " ");      // ���� ���ڿ��� �߶� �����͸� ��ȯ
		}
		//coffee[0].total_price += total;
		coffee[0].get_total_price(total);

	}
}
