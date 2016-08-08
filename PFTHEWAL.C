/*************************************************/
/*Pink Floyd - Another Brick in The Wall Pt. 2****/
/*Autor: Jos‚ Lu¡s Tadeu L. Carnevalli************/

#include<stdio.h>
#include<conio.h>
#include<dos.h>

void main (void);
void capa (void);
void voz1 (void);
void voz2 (void);
void voz3 (void);
void voz4 (void);
void waters (void);
void prelude (void);
void waters2 (void);
void prelude2 (void);
void exit (void);
void wall (void);

float  re=587.330, mi=659.225, mivib=669.000, fa=698.456, favib=710.00,
			rebass=146.832, labass=110, la=880, fevo=0, sol = 783.991,
			d0=523.251,  fabass=174.614, mibass=164.814;
int i=0, time=1, time2=1;

void main()  {
	static int i=0;
	char op;

	clrscr();
	capa();
	textbackground(BLUE);
	textcolor(WHITE);
	loop:
	i=0;
	clrscr();
	do{
		cprintf("ÛÛÛÛºþþþþº");
		i++;
	}while(i<24);
	voz1();
	wall();
	waters();
	voz2();
	wall();
	waters();
	voz1 ();
	wall();
	waters();
	voz3();
	wall();
	prelude();
	wall();
	waters2();
	nosound();
	delay(200);
	prelude2();
	voz4();
	wall();
	nosound();
	delay(400);
	prelude2();
	voz4();
	nosound();
	cprintf("\n\rDigite 0 para tocar novamente ou qualquer outra tecla para sair...");
	op = getch();
	if(op=='0') {
		time=1;
		time2=1;
		goto loop;
	}
	textbackground(BLACK);
	textcolor(WHITE);
}

void wall () {
	register int i = 0;
	do{
		cprintf("ÛÛÛÛºþþþþº");
		i++;
	}while(i<24);

}


void capa () {

	int j=1;
	char op;

	textbackground(DARKGRAY);
	textcolor(WHITE);
	clrscr();
	sound(re);
	delay(1000);
   nosound();
	do{
		cprintf("ÛÛÛÛºþþþþº");
		if (j%9==0) {
			if(j==90){
				textcolor(YELLOW +BLINK);
				cprintf("PINK FLOYDÛÛÛÛANOTHER BRICK IN THE WALLºÛÛÛÛºþþþþºÛÛÛÛºþþþþºÛÛÛÛºþþþþº");
				textcolor(WHITE);
			}else{
				cprintf("\n\r");
			}
		}
		j++;
	}while(j<247);


	cprintf("Digite qualquer tecla para ouvir ou 0 para sair...");
	op = getch();
	if (op=='0') {
		exit();
	}


}




void voz1() {

	(time==1) ? cprintf("\n\r     WE     ") : cprintf("\n\r     NO     ");
	sound(re);
	delay(200);
	nosound();
	sound(re);
	delay(450);
	nosound();
	(time==1) ? cprintf("DON`T     ") : cprintf("DARK     ");
	sound(mi);
	delay(500);
	nosound();
	(time==1) ? cprintf(" ") : cprintf("SAR");
	sound(mi);
	delay(100);
	nosound();
	(time==1) ? cprintf("NEED     "): cprintf("CAS");
	sound(fa);
	delay(600);
	nosound();
	(time==1) ? cprintf("NO     ") : cprintf("M   ");
	do{
		sound(mi);
		delay(100);
		sound(mivib);
		delay(100);
		i++;
	}while(i<3);
	nosound();
	delay(100);
	(time==1)? cprintf("E") : cprintf("IN   ");

	sound(re);
	delay(400);
	nosound();
	(time==1) ? cprintf("DU") : cprintf("THE   ");
	sound(mi);
	delay(500);
	nosound();
	sound(mi);
	delay(200);
	nosound();
	(time==1) ? cprintf("CA") : cprintf("CLASS");
	sound(fa);
	delay(300);
	nosound();
	(time==1) ? cprintf("TION!!\n\n\r") : cprintf("ROOM...\n\n\r");
	i =0;
	do{
		sound(mi);
		delay(100);
		sound(mivib);
		delay(100);
		i++;
	}while(i<4);
	time++;
}

void voz2() {


	cprintf("\r\n     WE     ");
	sound(re);
	delay(200);
	nosound();
	sound(re);
	delay(450);
	nosound();
	cprintf("DON`T      ") ;
	sound(mi);
	delay(500);
	nosound();
	sound(mi);
	delay(100);
	nosound();
	cprintf("NEED     ");
	sound(fa);
	delay(500);
	nosound();
	cprintf("NO   ");
	do{
		sound(mi);
		delay(100);
		sound(mivib);
		delay(100);
		i++;
	}while(i<4);
	delay(60);
	cprintf("THOUGHT   ");
	sound(re);
	delay(550);
	nosound();
	cprintf("CON");
	sound(mi);
	delay(500);
	nosound();
	sound(mi);
	delay(100);
	nosound();
	cprintf("TROL!!\n\n\r");
	sound(fa);
	delay(150);
	nosound();
	i =0;
	fevo=fa;
	do{
		sound(fevo);
		delay(180);
		if(i % 2 == 0) {
			fevo +=8;
		}else{
			fevo -= 8;
		}
		i++;
	}while(i<4);
}
void waters () {
	delay(20);
	sound(rebass);
	delay(400);
	nosound();
	delay(120);
	sound(rebass);
	delay(250);
	nosound();
	delay(100);
	sound(labass);
	delay(300);
	nosound();
	delay(100);
	sound(rebass);
	delay(400);
	nosound();
	delay(200);
	sound(rebass);
	delay(400);
	nosound();
	delay(100);
	sound(rebass);
	delay(100);
	nosound();
	delay(40);
	sound(rebass);
	delay(200);
	nosound();
	delay(100);
	sound(labass);
	delay(200);
	nosound();
	delay(100);
	sound(labass);
	delay(400);
	nosound();
	delay(80);
	sound(rebass);
	delay(400);
}

void voz3 () {
	cprintf("\r\n     TEA");
	sound(re);
	delay(200);
	nosound();
	sound(re);
	delay(450);
	nosound();
	cprintf("CHERS   ");
	sound(mi);
	delay(500);
	nosound();
	cprintf("LEA");
	sound(mi);
	delay(100);
	nosound();
	cprintf("VE   ");
	sound(fa);
	delay(600);
	cprintf("THEM   ");


	do{
		sound(mi);
		delay(100);
		sound(mivib);
		delay(100);
		i++;
	}while(i<4);
	delay(60);
	cprintf("KIDS   ");
	sound(re);
	delay(400);
	nosound();
	cprintf("A");
	sound(mi);
	delay(500);
	nosound();
	cprintf("LONE...\n\n\r");
	sound(fa);
	delay(300);
	fevo=re;
	do{
		sound(fevo);
		delay(100);
		nosound();
		fevo += 6;
	}while(fevo<=sol);
}

void prelude () {
	cprintf("\r\n     HEY!!!!!!!!!!!!   ");
	sound(sol);
	delay(700);
	nosound();
	delay(300);
	cprintf("TEA");
	sound(la);
	delay(500);
	cprintf("CHER!!!!!!!!!!!!!\n\n");
	fevo = sol;
	do{
		sound(fevo);
		delay(100);
		fevo -= 50;
	}while(fevo>re);
	cprintf("\r     LET   ");
	sound(la);
	delay(350);
	cprintf("THEM   ");
	sound(sol);
	delay(400);
	cprintf("KIDS   ");
	sound(fa);
	delay(300);
	cprintf("A");
	sound(sol);
	delay(350);
	sound(fa);
	delay(250);
	fevo=fa;
	i=0;
	cprintf("LONE!!!!!!!!!!!!!!!\n\n\r");
	do{
		sound(fevo);
		delay(100);
		if ((i%2==0)) {
			 fevo+=10;
		}else{
			 fevo-=10;
		}
		i++;
	}while(i<10);
}

void waters2 () {

	nosound();
	delay(70);

	sound(mibass);
	delay(170);
	nosound();
	delay(70);
	sound(fabass);
	delay(270);
	nosound();
	delay(70);
	sound(fabass);
	delay(270);
	nosound();
	delay(70);
	sound(mibass);
	delay(270);
	nosound();
	delay(70);
	sound(fabass);
	delay(270);
	sound(mibass);
	delay(270);
	sound(rebass);
	delay(400);

}

void voz4 () {


	cprintf("\r\n\n     ALL   ");
	sound(fa);
	delay(500);
	nosound();
	delay(200);
	cprintf("IN   ");
	sound(fa);
	delay(300);
	nosound();
	delay(50);
	cprintf("ALL   ");
	sound(fa);
	delay(300);
	nosound();
	delay(100);
	(time2==1) ? cprintf("IT") : cprintf("YOU");
	sound(fa);
	delay(300);
	(time2==1) ? cprintf("`S   ") : cprintf("`RE   ");
	sound(mi);
	delay(300);
	nosound();
	delay(250);
	cprintf("JUST   ");
	sound(mi);
	delay(400);
	nosound();
	delay(100);
	sound(mi);
	delay(200);
	cprintf("ANOTHER   ");
	sound(fa);
	delay(400);
	nosound();
	delay(200);
	cprintf("BRICK   ");
	sound(re);
	delay(400);
	cprintf("IN   ");
	sound(d0);
	delay(280);
	nosound();
	delay(100);
	cprintf("THE   ");
	sound(d0);
	delay(150);
	fevo=re;
	i=0;
	cprintf("WALL...\n\n\r");
	do{
		sound(fevo);
		delay(100);
		if(i%2==0) {
			fevo+=8;
		}else{
			fevo-=8;
		}
		i++;
	}while(i<5);
	time2++;
}


void prelude2() {

	fevo = rebass;
	do{
		sound(fevo);
		delay(100);
		fevo+=30;
	}while(fevo<=fa);
}

