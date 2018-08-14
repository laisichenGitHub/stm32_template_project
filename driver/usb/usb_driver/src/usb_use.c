#include "usb_use.h"
//#include "uuid.h"
//#include "sys.h"
#include "hw_config.h"
extern u8 EP1BUSY;			//�������ݷ���æ��־
//����USB ����/����
//enable:0,�Ͽ�
//       1,��������	   

extern  u8 enter_sta;
extern  u8 tab_sta;
extern u8 moudle_flag;
extern u8 uuid_flag;

void usb_port_set(u8 enable)
{  	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);	
	if(enable)_SetCNTR(_GetCNTR()&(~(1<<1)));//�˳��ϵ�ģʽ
	else
	{	  
		_SetCNTR(_GetCNTR()|(1<<1));  // �ϵ�ģʽ
		GPIOA->CRH&=0XFFF00FFF;
		GPIOA->CRH|=0X00033000;
		PAout(12)=0;    		  
	}
}  

void usb_use_init(void)
{
//	
//		//USB��֧�֡�����������
//    usb_port_set(0); 	//USB�ȶϿ�	�����㡿
//	delay_ms(300);
//    usb_port_set(1);	//USB�ٴ�����	����λ��������USB���ܡ�

//	//USB����
//	USB_Disconnect_Config();
 	USB_Interrupts_Config();  
 	Set_USBClock();  
 	USB_Init();		
	
}
void usb_use_dis(void)
{
	  usb_port_set(0); 	//USB�ȶϿ�	�����㡿
}


void usb_print(char *q)
{
		char *tok;
		char m;
		char *p;
	  delay_ms(20);
		for( p= q ;(*p) != '\0' ; p++)
		{
				tok=strtok(p,"");
				m= *tok;
			  
			  Joystick_Send(m);
				delay_us(1000);
				delay_us(300);
				delay_us(500);
				delay_us(500);
//				delay_us(500);
					
//				Joystick_Send(m);
//        delay_us(1020);
    

				Joystick_Send(0);
				delay_us(1000);
				delay_us(300);
				delay_us(500);
				delay_us(500);
//				Joystick_Send(0);
//				delay_us(1020);


		}
}



//void usb_print_yoko(char *q)
//{
//		char *tok;
//		char m;
//		char *p;
//	  delay_ms(20);
//		for( p= q ;(*p) != '\0' ; p++)
//		{
//				tok=strtok(p,"");
//				m= *tok;
//			
//			  Joystick_Send(m);
//				delay_us(800);
//			  Joystick_Send(m);
//				delay_us(800);
//		  	Joystick_Send(m);
//				delay_us(800);
//			  Joystick_Send(m);
//				delay_us(800);
//			  Joystick_Send(m);
//				delay_us(800);
//				Joystick_Send(m);
//				delay_us(800);
//			  Joystick_Send(m);
//				delay_us(800);
//			
//				Joystick_Send(0);
//				delay_ms(1);
//			  Joystick_Send(0);
//				delay_ms(1);
//		}
//		Joystick_Send(0);  //����ֹͣ
//		delay_ms(1);
//}


