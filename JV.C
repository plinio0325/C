#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

void capa(void);
void menu(void);
void borda(int corfundo);
void amistoso(void);
void campeonato(void);
void tab (void);
int jogo(void);
void placar(int p);
void sons (int x);

char jog1[12], jog2[12], op;
int pontos1=0, pontos2=0, partidas, resultados[100], tempos[100], p=-1;

void main () {


	capa();

	do{
		pontos1=0;
		pontos2=0;
		p=-1;
		menu();
		op = getch();
		textcolor(LIGHTGREEN);
		switch (op) {
			case'1':
				cprintf("( 1 ) - AMISTOSO");
				delay(700);
				amistoso();
				break;
			case'2':
				cprintf("( 2 ) - CAMPEONATO");
				delay(700);
				campeonato();

				break;
			case'3':
				cprintf("( 3 ) - SAIR");
				delay(700);
				exit(0);
			default:
				cprintf("INV LIDA. Retornando ao MENU em 1 s");
				sound(1300);
				delay(700);
				nosound();
				delay(300);
				menu();
			}


	}while(1);
}

void capa () {
	register int x, y;

	textmode(C80);
	textcolor(BLACK);

	textbackground(BLACK);
	clrscr();
	window(1, 1, 79, 25);
	textbackground(WHITE);
	clrscr();
	window(1,1,80,25);

	for(x=1; x<80; x++) {
		gotoxy(x, 1); cprintf("%c", 158);
		gotoxy(x, 8); cprintf("%c", 158);
		gotoxy(x, 16); cprintf("%c", 158);
		gotoxy(x, 25); cprintf("%c", 158);
		delay(30);
	}
	for(y=1; y<26; y++) {
		gotoxy(26, y); cprintf("%c", 158);
		gotoxy(52, y); cprintf("%c", 158);
		gotoxy(79, y); cprintf("%c", 158);
		gotoxy(1, y); cprintf("%c", 158);
		delay(50);
	}
	delay(300);
	window(27, 9, 51, 15);
		textbackground(BLACK);
		clrscr();
		sound(1046);
		delay(200);
		nosound();
		delay(100);
	window(53, 9, 78, 15);
		textbackground(YELLOW);
		clrscr();
		sound(1320);
		delay(200);
		nosound();
		delay(100);

	window(2, 2, 25, 7);
		textbackground(BLACK);
		clrscr();
		sound(1046);
		delay(200);
		nosound();
		delay(100);


	window(2, 9, 25, 15);
		textbackground(YELLOW);
		clrscr();
		sound(1320);
		delay(200);
		nosound();
		delay(100);

	window(53, 2, 78, 7);
		textbackground(BLACK);
		clrscr();
		sound(1046);
		delay(200);
		nosound();
		delay(100);

	delay(200);
	window(2, 17, 25, 24);
		textbackground(YELLOW);
		clrscr();
		sound(1320);
		delay(200);
		nosound();
		delay(300);

	window(53, 17, 78, 24);
		textbackground(BLACK);
		clrscr();
		sound(1046);
		delay(200);
		nosound();
		delay(100);
	window(1, 1, 80, 25);
	delay(500);
	textcolor(WHITE);
	gotoxy(11, 4); cprintf("JOGO");
		sons(0);
	delay(500);
	gotoxy(39, 12); cprintf("DA");
		sons(0);
	delay(500);
	gotoxy(64, 21); cprintf("VELHA");
		sons(0);
	delay(500);
}

void borda (int corfundo) {
	register int x, y;

	textmode(C80);
	textcolor(WHITE);
	textbackground(BLACK);
	clrscr();
	window(3,2,78, 24);
		textbackground(corfundo);
		clrscr();
	window(1,1,80, 25);
	for(x=2; x<80; x++) {
		gotoxy(x, 1); cprintf("%c", 205);
		gotoxy(x, 25); cprintf("%c", 205);
	}
	for(y=1; y<26; y++) {
		gotoxy(2, y); cprintf("%c", 186);
		gotoxy(79, y); cprintf("%c", 186);
	}
	gotoxy(2, 1); cprintf("%c", 201);
	gotoxy(2, 25); cprintf("%c", 200);
	gotoxy(79, 1); cprintf("%c", 187);
	gotoxy(79, 25); cprintf("%c", 188);
}

void menu () {
	register int x, y;

	borda(0);
	for(x=2; x<79; x++) {
		gotoxy(x, 3); cprintf("%c", 205);
	}
	gotoxy(2, 3); cprintf("%c", 204);
	gotoxy(79, 3); cprintf("%c", 185);

	textcolor(YELLOW);
	gotoxy(22, 2); cprintf("***MENU - Escolha a op‡ao de jogo***");
	gotoxy(10, 10);  cprintf("( 1 ) - JOGO AMISTOSO");
	gotoxy(12,  14); cprintf("( 2 ) - CAMPEONATO");
	gotoxy(14,  18); cprintf("( 3 ) - SAIR");
	gotoxy(10, 22 ); cprintf("Sua op‡ao ‚: ");
}

void tab () {
	register int x, y;
	clrscr();
	textmode(C80);
	textbackground(BLACK);
	textcolor(BLACK);


	window(16, 3, 64, 22);
	textbackground(WHITE);
	clrscr();
	window(1,1,80,25);
	for(x=17; x<64; x++){
		gotoxy(x, 2); cprintf("%c", 205);
		gotoxy(x, 9); cprintf("%c", 205);
		gotoxy(x, 15); cprintf("%c", 205);
		gotoxy(x, 22); cprintf("%c", 205);
	}
	for(y=3; y<22; y++) {
		gotoxy(16, y); cprintf("%c", 186);
		gotoxy(32, y); cprintf("%c", 186);
		gotoxy(48, y); cprintf("%c", 186);
		gotoxy(64, y); cprintf("%c", 186);
	}
	gotoxy(16, 2); cprintf("%c", 201);
	gotoxy(16, 22); cprintf("%c", 200);
	gotoxy(64, 2); cprintf("%c", 187);
	gotoxy(64, 22); cprintf("%c", 188);
	gotoxy(32, 2); cprintf("%c", 203);
	gotoxy(48, 2); cprintf("%c", 203);
	gotoxy(32, 22); cprintf("%c", 202);
	gotoxy(48, 22); cprintf("%c", 202);
	gotoxy(16, 9); cprintf("%c", 204);
	gotoxy(16, 15); cprintf("%c", 204);
	gotoxy(64, 9); cprintf("%c", 185);
	gotoxy(64, 15); cprintf("%c", 185);
	gotoxy(32, 9); cprintf("%c", 206);
	gotoxy(32, 15); cprintf("%c", 206);
	gotoxy(48, 9); cprintf("%c", 206);
	gotoxy(48, 15); cprintf("%c", 206);
	gotoxy(19, 4); cprintf("1");
	gotoxy(41, 4); cprintf("2");
	gotoxy(61, 4); cprintf("3");
	gotoxy(19, 13); cprintf("4");
	gotoxy(41, 13); cprintf("5");
	gotoxy(61, 13); cprintf("6");
	gotoxy(19, 20); cprintf("7");
	gotoxy(41, 20); cprintf("8");
	gotoxy(61, 20); cprintf("9");
	window(3, 5, 13, 10);
		textbackground(YELLOW);
		clrscr();
	window(67, 5, 77, 10);
		textbackground(BLUE);
		clrscr();
	window(1,1,80,25);
}

void amistoso() {

	clrscr();
	borda(0);
	gotoxy(5, 5); cprintf("Digite o nome do jogador 1: [MAX 10 Caracteres]");
	gotoxy(5, 7); cprintf("//");
	fgets(jog1, 11, stdin);
	fflush(stdin);
	gotoxy(5, 15); cprintf("Digite o nome do jogador 2: [MAX 10 Caracteres]");
	gotoxy(5, 17); cprintf("//");
	fgets(jog2, 11, stdin);
	fflush(stdin);
	gotoxy(5, 23); cprintf("PRESSIONE QUALQUER TECLA PARA INICIAR O JOGO...");
	getch();
	jogo();
}

int jogo () {
	register int i, j, c, c1, c2, m[3][3];
	int  inicio=0, fim=9;
	clock_t ti, tf;
	register char pos;

	for(i=0; i<3; i++) {
		for(j=0; j<3; j++) {
			m[i][j] = -10;
		}
	}

	borda(0);
	tab();
	textbackground(BLACK);
	textcolor(LIGHTGREEN);
	if(op=='1'){
		gotoxy(37, 1); cprintf("AMISTOSO");
	}else{
		gotoxy(28, 1); cprintf("CAMPEONATO - Partidas Restantes: %d", partidas);
	}
	textcolor(BLACK);
	textbackground(YELLOW);
	gotoxy(4, 6); cputs(jog1);
	if(op=='2') {
		gotoxy(4, 9); cprintf("PONTOS: %d", pontos1);
	}
	textcolor(WHITE);
	textbackground(BLUE);
	gotoxy(68, 6); cputs(jog2);
	if(op=='2') {
		gotoxy(68, 9); cprintf("PONTOS: %d", pontos2);
	}
	textbackground(BLACK);
	ti = clock();

	if(op=='2') {
		if(p%2==0) {
			inicio = 0;
			fim = 9;
		}else{
			inicio = 1;
			fim = 10;
		}
	}

	for(c=inicio; c<fim; c++) {
		textbackground(BLACK);
		window(32,23, 78, 23); clrscr(); window(1,1,80,25);
		if(c%2==0) {
			textcolor(YELLOW);
			gotoxy(32, 23); cprintf("Jogando Agora: %s", jog1);
		}else{
			textcolor(LIGHTBLUE);
			gotoxy(32, 23); cprintf("Jogando Agora: %s", jog2);
		}

		window(32, 24, 78, 24); clrscr(); window(1,1,80,25);
		textcolor(WHITE);
		gotoxy(32, 24); cprintf("Digite a c‚lula:");
		pos = getche();
		if(c%2==0) {
			textbackground(YELLOW);
			switch(pos){
				case'1':
					if(m[0][0]==-10) {
						m[0][0] = 1;
						window(17,3,31,8);
						clrscr();
						sound(1046);
						delay(200);
						nosound();
					}else{
						c--;
					}
					break;
				case'2':
					if(m[0][1]==-10) {
						m[0][1] = 1;
						window(33,3,47,8);
						clrscr();
						sound(1046);
						delay(200);
						nosound();
					}else{
						c--;
					}
					break;
				case'3':
					if(m[0][2]==-10){
						m[0][2] = 1;
							window(49,3,63,8);
							clrscr();
							sound(1046);
							delay(200);
							nosound();
					}else{
						c--;
					}
					break;
				case'4':
					if(m[1][0]==-10) {
						m[1][0] = 1;
						window(17,10,31,14);
						clrscr();
						sound(1046);
						delay(200);
						nosound();
					}else{
						c--;
					}
					break;
				case '5':
					if(m[1][1]==-10) {
						m[1][1] = 1;
						window(33,10,47,14);
						clrscr();
						sound(1046);
						delay(200);
						nosound();
					}else{
						c--;
					}
					break;
				case'6':
					if(m[1][2]==-10) {
						m[1][2] = 1;
						window(49,10,63,14);
						clrscr();
						sound(1046);
						delay(200);
						nosound();
					}else{
						c--;
					}
					break;
				case'7':
					if(m[2][0]==-10) {
						m[2][0] = 1;
						window(17,16,31,21);
						clrscr();
						sound(1046);
						delay(200);
						nosound();
					}else{
						c--;
					}
					break;
				case'8':
					if(m[2][1]==-10) {
						m[2][1] = 1;
						window(33,16,47,21);
						clrscr();
						sound(1046);
						delay(200);
						nosound();
					}else{
						c--;
					}
					break;
				case'9':
					if(m[2][2]==-10) {
						m[2][2] = 1;
						window(49,16,63,21);
						clrscr();
						sound(1046);
						delay(200);
						nosound();
					}else{
						c--;
					}
					break;
				default:
					sound(1000);
					delay(500);
					nosound();
					c--;
					break;

				}
			}else{
				textbackground(BLUE);
				switch(pos){
				case'1':
					if(m[0][0]==-10) {
						m[0][0] = 2;
						window(17,3,31,8);
						clrscr();
						sound(1320);
						delay(200);
						nosound();
					}else{
						c--;
					}
					break;
				case'2':
					if(m[0][1]==-10) {
						m[0][1] = 2;
						window(33,3,47,8);
						clrscr();
						sound(1320);
						delay(200);
						nosound();
					}else{
						c--;
					}
					break;
				case'3':
					if(m[0][2]==-10){
						m[0][2] = 2;
						window(49,3,63,8);
						clrscr();
						sound(1320);
						delay(200);
						nosound();
					}else{
						c--;
					}
					break;
				case'4':
					if(m[1][0]==-10) {
						m[1][0] = 2;
						window(17,10,31,14);
						clrscr();
						sound(1320);
						delay(200);
						nosound();
					}else{
						c--;
					}
					break;
				case '5':
					if(m[1][1]==-10) {
						m[1][1] = 2;
						window(33,10,47,14);
						clrscr();
						sound(1320);
						delay(200);
						nosound();
					}else{
						c--;
					}
					break;
				case'6':
					if(m[1][2]==-10) {
						m[1][2] = 2;
						window(49,10,63,14);
						clrscr();
						sound(1320);
						delay(200);
						nosound();
					}else{
						c--;
					}
					break;
				case'7':
					if(m[2][0]==-10) {
						m[2][0] = 2;
						window(17,16,31,21);
						clrscr();
						sound(1320);
						delay(200);
						nosound();
					}else{
						c--;
					}
					break;
				case'8':
					if(m[2][1]==-10) {
						m[2][1] = 2;
						window(33,16,47,21);
						clrscr();
						sound(1320);
						delay(200);
						nosound();
					}else{
						c--;
					}
					break;
				case'9':
					if(m[2][2]==-10) {
						m[2][2] = 2;
						window(49,16,63,21);
						clrscr();
						sound(1320);
						delay(200);
						nosound();
					}else{
						c--;
					}
					break;
				default:
					sound(1000);
					delay(500);
					nosound();
					c--;
					break;

				}
			}
			for(i=0; i<3; i++) {
				c1=0;
				c2=0;
				for(j=0; j<3; j++) {
					if(m[i][j]==1) {
						c1++;
					}
					if(m[i][j]==2) {
						c2++;
					}
				}
				if(c1==3||c2==3){
					break;
				}
			}
			if(c1!=3&&c2!=3){
				for(j=0; j<3; j++) {
					c1=0;
					c2=0;
					for(i=0; i<3; i++) {
						if(m[i][j]==1) {
							c1++;
						}
						if(m[i][j]==2) {
							c2++;
						}
					}
					if(c1==3||c2==3){
						break;
					}
				}
			}
			if(c1!=3&&c2!=3) {
					c1=0;
					c2=0;
					for(i=0; i<3; i++) {

						if(m[i][i]==1) {
							c1++;
						}
						if(m[i][i]==2) {
							c2++;
						}
						if(c1==3||c2==3) {
							break;
						}
					}
			}
			if(c1!=3&&c2!=3) {
					c1=0;
					c2=0;
				for(i=0; i<3; i++) {
					if(m[i][2-i]==1) {
						c1++;
					}
					if(m[i][2-i]==2) {
						c2++;
					}
					if(c1==3||c2==3) {
						break;
					}
				}
			}
			window(1, 1, 80, 25);
			if(c1==3) {
					sons(1);
					window(10, 23, 70, 24);
					textbackground(YELLOW);
					textcolor(BLACK);
					clrscr();
					window(1, 1, 80, 25);
					gotoxy(16, 23);  cprintf("Parab‚ns, %s", jog1); gotoxy(wherex(), 23); cprintf(" ! Vocˆ venceu esta partida!"
					);
					gotoxy(11, 24);
					if(op=='1') {
						  cprintf("Pressione qualquer tecla para voltar ao menu...");
					}else{
						if(partidas==1) {
							cprintf("Pressione qualquer tecla para ver o PLACAR FINAL...");
						}else{
							cprintf("Pressione qualquer tecla para iniciar a PRàXIMA PARTIDA...");
						}
					}
					tf=clock();
					tempos[p] = (tf-ti)/CLK_TCK;
					getch();
					return(1);
			}
			if(c2==3) {
					sons(1);
					window(10, 23, 70, 24);
					textbackground(BLUE);
					textcolor(WHITE);
					clrscr();
					window(1, 1, 80, 25);
					gotoxy(16, 23); cprintf("Parab‚ns, %s", jog2); gotoxy(wherex(), 23); cprintf(" ! Vocˆ venceu esta partida!");
					gotoxy(11, 24);
					if(op=='1') {
						  cprintf("Pressione qualquer tecla para voltar ao menu...");
					}else{
						if(partidas==1) {
							cprintf("Pressione qualquer tecla para ver o PLACAR FINAL...");
						}else{
							cprintf("Pressione qualquer tecla para iniciar a PRàXIMA PARTIDA...");
						}
					}
					tf=clock();
					tempos[p] = (tf-ti)/CLK_TCK;
					getch();
					return(2);
			}

	  }


	if(c1!=3&&c2!=3) {
		sons(0);
		window(10, 23, 70, 24); textbackground(RED); clrscr();
		textcolor(WHITE);
		window(1,1,80,25);
		gotoxy(30, 23); cprintf("O jogo terminou empatado");
		gotoxy(11, 24);
		if(op=='1') {
		  cprintf("Pressione qualquer tecla para voltar ao menu...");
		}else{
			if(partidas==1) {
				cprintf("Pressione qualquer tecla para ver o PLACAR FINAL...");
			}else{
				cprintf("Pressione qualquer tecla para iniciar a PRàXIMA PARTIDA...");
			}
		}
		tf=clock();
		tempos[p] = (tf-ti)/CLK_TCK;
		getch();
		return(0);
	}
  return(0);
}

void campeonato() {

	int x;


	borda(0);
	textcolor(WHITE);
	for(x=2; x<79; x++) {
		gotoxy(x, 3);cprintf("%c", 205);
	}
	gotoxy(2, 3); cprintf("%c", 204);
	gotoxy(79, 3); cprintf("%c", 185);
	textcolor(LIGHTGREEN);
	gotoxy(20, 2); cprintf("*** CAMPEONATO :: OP€OES ***");
	do{
		gotoxy(10, 10); cprintf("Quantas partidas? [1-100] >> ");
		cscanf("%d",&partidas);
		if(partidas<1||partidas>100) {
			gotoxy(20, 15); cprintf("Valor Inv lido...");
			sons(0);
         delay(300);
         window(19, 15, 50, 15); clrscr(); window(1,1,80,25);
		}
	}while(partidas<1 || partidas> 100);
   
	gotoxy(10, 15); cprintf("Digite o nome do jogador 1 [MAX 10 Caracteres]:");
	gotoxy(15, 17); fgets(jog1, 11, stdin);
   fflush(stdin);
	gotoxy(10, 20);  cprintf("Digite o nome do jogador 2 [MAX 10 Caracteres]:");
	gotoxy(15, 22); fgets(jog2, 11, stdin);
	fflush(stdin);

	gotoxy(5, 24); cprintf("Pressione qualquer tecla para iniciar o jogo...");
   getch();
	do{
		p++;
		resultados[p] = jogo();
		if(resultados[p]==1) {
			pontos1++;
		}
		if(resultados[p]==2) {
			pontos2++;
		}

		partidas--;

	}while(partidas>0);
	placar(p);


}


void placar(int p) {
	register int c=0, x;

	borda(0);
	textcolor(LIGHTRED);
	gotoxy(3, 2); cprintf("%s", jog1); gotoxy(wherex(), 2); cprintf(" %d - %d %s", pontos1, pontos2, jog2);

	textcolor(WHITE);
	gotoxy(30, 3); cprintf("RESULTADOS FINAIS");
	gotoxy(16, 4); cprintf("PARTIDA    -       VENCEDOR    -   TEMPO DE PARTIDA");
	textcolor(LIGHTGREEN);
	for(x=0; x<=p; x++) {
		gotoxy(16, 6+c); cprintf("%3d                ", x+1);
		if(resultados[x]==0) {
			cprintf("------");
		}else{
			if(resultados[x]==1){
				cprintf("%s", jog1);
			}else{
				cprintf("%s", jog2);
			}
		}
		gotoxy(55, 6+c); cprintf("%4ds", tempos[x]);
		c+=2;
		if(c==16) {
			gotoxy(10, 24); cprintf("Pressione qualquer tecla para ver os pr¢ximos resultados");
			getch();
			borda(0);
			textcolor(LIGHTGREEN);
			c=0;
		}
	}
	textbackground(BLACK);
	gotoxy(35, 22); cprintf("VENCEDOR: ");
	if(pontos1>pontos2) {
		textcolor(YELLOW);
		cprintf("%s", jog1);
		sons(2);
	}else{
		if(pontos2>pontos1) {
			textcolor(LIGHTBLUE);
			cprintf("%s", jog2);
			sons(2);
		}else{
			printf("EMPATE.");
		}
	}
	textcolor(WHITE);
	gotoxy(15, 23); cprintf("Digite qualquer tecla para voltar ao menu...");
	getch();

}



void sons (int x){
	register int i;

	if(x==0) {
		sound(146);
		delay(700);
		nosound();
	}

	if(x==1){
		for(i=1; i<6; i++) {
			sound(440*i/2);
			if(i<5)		delay(150);
			else			delay(300);
		}
		nosound();
	}
	if(x==2){
			int f=698, c=1046, b=987, a=880, g=783, e=659;
			register int i;

		sound(f);
		delay(500);
		nosound();
		for(i=0; i<10; i++) {
			if(i%2==0){
				sound(c+5);
				delay(100);
			}else{
				sound(c);
				delay(100);
			}
		}
		nosound();
		delay(100);
		for(i=0; i<10; i++) {
			if(i%2==0) {
				sound(b);
			}else{
				sound(b+5);
			}
			delay(50);
		}
		nosound();
		for(i=0; i<10; i++) {
			if(i%2==0) {
				sound(c);
			}else{
				sound(c+5);
			}
			delay(50);
		}
		nosound();
		sound(b);
		delay(300);
		nosound();
		delay(100);
		sound(g);
		delay(800);
		nosound();
		delay(300);
		sound(g);
		delay(200);
		nosound();
		delay(100);
		sound(g);
		delay(200);
		sound(a);
		delay(400);
		nosound();
		sound(e);
		delay(400);
		nosound();
   }


}

