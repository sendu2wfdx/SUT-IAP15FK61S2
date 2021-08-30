unsigned char keyvalue(unsigned char key)			//键值获取函数
{
	unsigned char num;
	switch(key)
	{												//	DOWN	UP
		case 0x4F:		num=1;		break;			//	0x4F	0x0F
		case 0x4E:		num=2;		break;			//	0x4E	0x0E
		case 0x4D:		num=3;		break;			//	0x4D	0x0D
		case 0x4C:		num=4;		break;			//	0x4C	0x0C
		case 0x47:		num=5;		break;			//	0x47	0x07
		case 0x46:		num=6;		break;			//	0x46	0x06
		case 0x45:		num=7;		break;			//	0x45	0x05
		case 0x44:		num=8;		break;			//	0x44	0x04
		default:		num=0;		break;
	}
	return num;
}

void check_keyboard(void) interrupt 2				//外部中断1服务函数
{
	unsigned int keycode=keyvalue(CH452_Read());
	switch(keycode)									//根据对应的按键码选择相应的功能服务函数
    {
		case 1:		key1_serv();	break;
		case 2:		key2_serv();	break;
		case 3:		key3_serv();	break;
		case 4:		key4_serv();	break;
		case 5:		key5_serv();	break;
		case 6:		key6_serv();	break;
		case 7:		key7_serv();	break;
		case 8:		key8_serv();	break; 
		default:					break;
    }
	EA=1;
	EX1=1;
}
