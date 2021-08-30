xdata unsigned int smg0[] = {189,24,213,217,120,233,237,152,253,249};			//0123456789	段码
xdata unsigned int smgA[] = {252,109,165,93,229,228,249,124};					//AbCdEFgH		段码

void Display(wei,duan)								//数码管显示函数
{
	switch(wei)
	{
		case 1: 	wei=CH452_DIG4;		break;			//右1
		case 2: 	wei=CH452_DIG5;		break;
		case 3: 	wei=CH452_DIG6;		break;
		case 4: 	wei=CH452_DIG7;		break; 			//左1
	}
	switch(duan)
	{
		case 0: 	duan=smg0[0];		break;
		case 1: 	duan=smg0[1];		break;
		case 2: 	duan=smg0[2];		break;
		case 3: 	duan=smg0[3];		break;
		case 4: 	duan=smg0[4];		break;
		case 5: 	duan=smg0[5];		break;
		case 6: 	duan=smg0[6];		break;
		case 7: 	duan=smg0[7];		break;
		case 8: 	duan=smg0[8];		break;
		case 9: 	duan=smg0[9];		break;
	}
	CH452_Write(wei | duan);
}

void counter(num)									//数值显示函数
{
	unsigned int a,b,c,d;
	
	a=num/1000;
	b=num%1000/100;
	c=num%100/10;
	d=num%10;
	Display(4,a);		
	Display(3,b);
	Display(2,c);
	Display(1,d);
}