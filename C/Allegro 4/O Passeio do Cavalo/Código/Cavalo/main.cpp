#include <allegro.h>
#include <stdio.h>
#include <ctype.h>
#include <time.h>
#include <string.h>
#include<conio2.h>
#define  MAX 628 
#define  MAY 624 
#define  cavX 80
#define  cavY 78

struct rank{
    char nome[27];
    int tempo[3];
    int pontos;
};

void deinit() {
	clear_keybuf();

}
void grava(rank J)
{
    FILE*arq=fopen("rank.dat","ab+");
    
    if(arq==NULL)
    {
        arq=fopen("rank.dat","wb+");
    }
    fwrite(&J,sizeof(J),1,arq);
    fclose(arq);
}

void user1(char V[22])
{
   
	BITMAP *NOME;
	BITMAP *LETRA;
	char nome[27]={0};
	int tecla=0;
	int ERRO=0,E=0; // W , M
	int X=70,Y=352,Mov=14,i=0;
	       NOME=load_bitmap("nome.bmp", NULL);

	       draw_sprite(screen,NOME,0,0);
	       
	       do
            {   
             label:         
             tecla=readkey();
             
             if (((tecla & 0xff) < 96||(tecla & 0xff) > 124)&&((tecla & 0xff) != 32)
              &&((tecla & 0xff) != 13)&&((tecla & 0xff) != 8))          
             goto label;
             if((tecla & 0xff) == 13&&i==0)
              goto label;
             
             nome[i]=tecla;
                 if(key[KEY_A])            
                    LETRA=load_bitmap("fonte\\a.bmp", NULL);                                           
                 if(key[KEY_W]) 
                 {                
                    LETRA=load_bitmap("fonte\\w.bmp", NULL);
                    ERRO=1;
                 }
                 if(key[KEY_Q])
                    LETRA=load_bitmap("fonte\\q.bmp", NULL);
                 if(key[KEY_E])
                    LETRA=load_bitmap("fonte\\e.bmp", NULL);
                 if(key[KEY_R])
                    LETRA=load_bitmap("fonte\\r.bmp", NULL);
                 if(key[KEY_T])
                    LETRA=load_bitmap("fonte\\t.bmp", NULL);
                 if(key[KEY_Y])
                    LETRA=load_bitmap("fonte\\y.bmp", NULL);
                 if(key[KEY_U])
                    LETRA=load_bitmap("fonte\\u.bmp", NULL);
                 if(key[KEY_I])
                    LETRA=load_bitmap("fonte\\i.bmp", NULL);
                 if(key[KEY_O])
                    LETRA=load_bitmap("fonte\\o.bmp", NULL);
                 if(key[KEY_P])
                    LETRA=load_bitmap("fonte\\p.bmp", NULL);
                 if(key[KEY_S])
                    LETRA=load_bitmap("fonte\\s.bmp", NULL);
                 if(key[KEY_D])
                    LETRA=load_bitmap("fonte\\d.bmp", NULL);
                 if(key[KEY_F])
                    LETRA=load_bitmap("fonte\\f.bmp", NULL);
                 if(key[KEY_G])
                    LETRA=load_bitmap("fonte\\g.bmp", NULL);
                 if(key[KEY_H])
                    LETRA=load_bitmap("fonte\\h.bmp", NULL);
                 if(key[KEY_I])
                    LETRA=load_bitmap("fonte\\i.bmp", NULL);
                 if(key[KEY_J])
                    LETRA=load_bitmap("fonte\\j.bmp", NULL);
                 if(key[KEY_K])
                    LETRA=load_bitmap("fonte\\k.bmp", NULL);
                 if(key[KEY_L])
                    LETRA=load_bitmap("fonte\\l.bmp", NULL);              
                 if(key[KEY_Z])
                    LETRA=load_bitmap("fonte\\z.bmp", NULL);
                 if(key[KEY_X])
                    LETRA=load_bitmap("fonte\\x.bmp", NULL);
                 if(key[KEY_C])
                    LETRA=load_bitmap("fonte\\c.bmp", NULL);
                 if(key[KEY_V])
                    LETRA=load_bitmap("fonte\\v.bmp", NULL);
                 if(key[KEY_B])
                    LETRA=load_bitmap("fonte\\b.bmp", NULL);
                 if(key[KEY_N])
                    LETRA=load_bitmap("fonte\\n.bmp", NULL);
                 if(key[KEY_M])
                  {
                    LETRA=load_bitmap("fonte\\m.bmp", NULL);
                    ERRO=1;
                 }
                 if(!key[KEY_SPACE]&&!key[KEY_BACKSPACE]&&!key[KEY_ENTER]&&!key[KEY_ENTER_PAD])                                                                                       
                 draw_sprite(screen,LETRA,X+(i*(Mov+E)),Y);
                 
                 if(!key[KEY_BACKSPACE])
                    i++;
                 else
                 {
                    if(i-1>=0)    
                    {
                        i=i-1;                   
                        LETRA=load_bitmap("fonte\\null.bmp", NULL);
                        draw_sprite(screen,LETRA,X+(i*(Mov+E)),Y);
                    }
                 }
                        
                 if(ERRO==1)
                 {
                    E=Mov/4;ERRO=0;                
                 }
                 else
                 E=0;
                    
             
            }while(!key[KEY_ENTER]&&!key[KEY_ENTER_PAD]&&i<27);
            
            strcpy(V,nome);
           // printf("%d",V[0]);
             while(!key[KEY_ENTER]&&!key[KEY_ENTER_PAD])
      int j;
            
}
void ordena()
{
     int i,j,tam;
     rank B,Baux;//foram criadas 2 Structs do tipo turma
     FILE*arq=fopen("rank.dat","rb+");//Abre como gravação
     
  if(arq!=NULL)
  {
     fseek(arq,0,2);//Aponta o final do arquivo
     tam=ftell(arq)/sizeof(rank);//Descobre quantidade de structs no arquivo..
     for(i=0;i<tam-1;i++)//Usa como limitador
      for(j=i+1;j<tam;j++)
     {
            fseek(arq,i*sizeof(rank),0);//Ex:Se o sizeof da struct é 44bytes, vai andar de
                                         //44 em 44, assim vai pegar o começo de cada struct
                                         
            fread(&Baux,sizeof(rank),1,arq);//lê auxiliar

            fseek(arq,j*sizeof(rank),0);//Igual como esta acima, mas quem indica é a 
                                        //variavel J
            fread(&B,sizeof(rank),1,arq);//lê Original

            //Vai começar testando tds da Original com a auxiliar
            if(Baux.pontos<B.pontos)//Compara
            {                             //Se a auxiliar for "maior" que Original
                                          //Na variavel "idade"
    
                fseek(arq,i*sizeof(rank),0);//Vai pro começo da struct Original na pos i
                fwrite(&B,sizeof(rank),1,arq);//E grava
                fseek(arq,j*sizeof(rank),0);//Vai pro começo da struct Auxiliar na pos J
                fwrite(&Baux,sizeof(rank),1,arq);//E grava
            }
        }
//Desempate---------------------------------------------------------------------
        for(i=0;i<tam-1;i++)//Usa como limitador
      for(j=i+1;j<tam;j++)
     {
            fseek(arq,i*sizeof(rank),0);//Ex:Se o sizeof da struct é 44bytes, vai andar de
                                         //44 em 44, assim vai pegar o começo de cada struct

            fread(&Baux,sizeof(rank),1,arq);//lê auxiliar

            fseek(arq,j*sizeof(rank),0);//Igual como esta acima, mas quem indica é a
                                        //variavel J
            fread(&B,sizeof(rank),1,arq);//lê Original

            //Vai começar testando tds da Original com a auxiliar
            if(Baux.pontos==B.pontos)//Compara
            {                             //Se a auxiliar for "maior" que Original
                if(Baux.tempo[2]>B.tempo[2])                          //Na variavel "idade"
                {
                    fseek(arq,i*sizeof(rank),0);//Vai pro começo da struct Original na pos i
                    fwrite(&B,sizeof(rank),1,arq);//E grava
                    fseek(arq,j*sizeof(rank),0);//Vai pro começo da struct Auxiliar na pos J
                    fwrite(&Baux,sizeof(rank),1,arq);//E grava
                }
            }
        }

      }
       
        fclose(arq);



}
void ranking()
{
  //  clear(screen);
    BITMAP *RANK;
	RANK=load_bitmap("rank.bmp", NULL);
    int Mov=14;
    int ERRO=0,E=0; // W , M
    int ERRO2=0;    //min>10
    char pontos[3]={};
	draw_sprite(screen,RANK,0,0);
	int i=1,x=14,y=180;
	char min[3]={};
	char sec[3]={};
	ordena();
	FILE*arq=fopen("rank.dat","rb");//Abre para leitura
    rank B;
    if(arq==NULL)//Ve se o arquivo existe
    {            //Se nao..
       i=12;
    }
    BITMAP *LETRA;
    while(i<9&&!feof(arq))
    {
        
        fread(&B,sizeof(rank),1,arq);
//Pontuação---------------------------------------------------------------------
   itoa(B.pontos,pontos,10);
   
        for(int j=0;j<=1;j++)
        {
            LETRA=load_bitmap("fonte\\null.bmp", NULL);
            if(pontos[j]=='0')
            LETRA=load_bitmap("fonte\\0b.bmp", NULL);
            if(pontos[j]=='1')
            LETRA=load_bitmap("fonte\\1b.bmp", NULL);
            if(pontos[j]=='2')
            LETRA=load_bitmap("fonte\\2b.bmp", NULL);
            if(pontos[j]=='3')
            LETRA=load_bitmap("fonte\\3b.bmp", NULL);
            if(pontos[j]=='4')
            LETRA=load_bitmap("fonte\\4b.bmp", NULL);
            if(pontos[j]=='5')
            LETRA=load_bitmap("fonte\\5b.bmp", NULL);
            if(pontos[j]=='6')
            LETRA=load_bitmap("fonte\\6b.bmp", NULL);
            if(pontos[j]=='7')
            LETRA=load_bitmap("fonte\\7b.bmp", NULL);
            if(pontos[j]=='8')
            LETRA=load_bitmap("fonte\\8b.bmp", NULL);
            if(pontos[j]=='9')
            LETRA=load_bitmap("fonte\\9b.bmp", NULL);            
            if(!feof(arq))
            draw_sprite(screen,LETRA,x+450+(j*20),y+((i-1)*32)); 
        } 
            
        
//Classificação-----------------------------------------------------------------
        if(i==1)    
            LETRA=load_bitmap("fonte\\1b.bmp", NULL);
        if(i==2)
            LETRA=load_bitmap("fonte\\2b.bmp", NULL);
        if(i==3)
            LETRA=load_bitmap("fonte\\3b.bmp", NULL);
        if(i==4)
            LETRA=load_bitmap("fonte\\4b.bmp", NULL);
        if(i==5)
            LETRA=load_bitmap("fonte\\5b.bmp", NULL);
        if(i==6)
            LETRA=load_bitmap("fonte\\6b.bmp", NULL);
        if(i==7)
            LETRA=load_bitmap("fonte\\7b.bmp", NULL);
        if(i==8)
            LETRA=load_bitmap("fonte\\8b.bmp", NULL);
       
        if(!feof(arq))  
            draw_sprite(screen,LETRA,x,y+((i-1)*32+2));            
        
//Minuto & Segundo--------------------------------------------------------------
        itoa(B.tempo[0],min,10);
        itoa(B.tempo[1],sec,10);
       for(int l=0;l<2;l++)
       {
            if(min[1]=='\0')
            ERRO2=20;
            
            LETRA=load_bitmap("fonte\\null.bmp", NULL);
            if(min[l]=='1')
                LETRA=load_bitmap("fonte\\1b.bmp", NULL);
            if(min[l]=='2')
                LETRA=load_bitmap("fonte\\2b.bmp", NULL);  
            if(min[l]=='3')
                LETRA=load_bitmap("fonte\\3b.bmp", NULL);
            if(min[l]=='4')
                LETRA=load_bitmap("fonte\\4b.bmp", NULL); 
            if(min[l]=='5')
                LETRA=load_bitmap("fonte\\5b.bmp", NULL); 
            if(min[l]=='6')
                LETRA=load_bitmap("fonte\\6b.bmp", NULL);
            if(min[l]=='7')
                LETRA=load_bitmap("fonte\\7b.bmp", NULL);
            if(min[l]=='8')
                LETRA=load_bitmap("fonte\\8b.bmp", NULL);
            if(min[l]=='9')
                LETRA=load_bitmap("fonte\\9b.bmp", NULL);
            if(min[l]=='0')
                LETRA=load_bitmap("fonte\\0b.bmp", NULL);
             if(!feof(arq))   
             draw_sprite(screen,LETRA,x+500+(l*20)+ERRO2,y+((i-1)*32+2));
             ERRO2=0;
             
            }
             LETRA=load_bitmap("fonte\\pt.bmp", NULL);
             if(!feof(arq))   
             draw_sprite(screen,LETRA,x+500+40+ERRO2,y+((i-1)*32+2));

//Nome--------------------------------------------------------------------------             
            for(int l=0;l<2;l++)
            {
                ERRO2=20;
    
                LETRA=load_bitmap("fonte\\null.bmp", NULL);
                if(sec[l]=='1')
                    LETRA=load_bitmap("fonte\\1b.bmp", NULL);
                if(sec[l]=='2')
                    LETRA=load_bitmap("fonte\\2b.bmp", NULL);
                if(sec[l]=='3')
                    LETRA=load_bitmap("fonte\\3b.bmp", NULL);
                if(sec[l]=='4')
                    LETRA=load_bitmap("fonte\\4b.bmp", NULL);
                if(sec[l]=='5')
                    LETRA=load_bitmap("fonte\\5b.bmp", NULL);
                if(sec[l]=='6')
                    LETRA=load_bitmap("fonte\\6b.bmp", NULL);
                if(sec[l]=='7')
                    LETRA=load_bitmap("fonte\\7b.bmp", NULL);
                if(sec[l]=='8')
                    LETRA=load_bitmap("fonte\\8b.bmp", NULL);
                if(sec[l]=='9')
                    LETRA=load_bitmap("fonte\\9b.bmp", NULL);
                if(sec[l]=='0')
                    LETRA=load_bitmap("fonte\\0b.bmp", NULL);
                 if(!feof(arq))
                 draw_sprite(screen,LETRA,x+540+(l*20)+ERRO2,y+((i-1)*32+2));
                 ERRO2=0;
                 
             }
        for(int j=0;B.nome[j]!='\0';j++)
        {
            
            if(!feof(arq))
            {
             //   printf("%c",B.nome[j]);
                if(B.nome[j]=='r')
                    LETRA=load_bitmap("fonte\\r.bmp", NULL);
                if(B.nome[j]=='e')
                    LETRA=load_bitmap("fonte\\e.bmp", NULL);
                if(B.nome[j]=='n')
                    LETRA=load_bitmap("fonte\\n.bmp", NULL);
                if(B.nome[j]=='a')
                    LETRA=load_bitmap("fonte\\a.bmp", NULL);
                if(B.nome[j]=='t')
                    LETRA=load_bitmap("fonte\\t.bmp", NULL);
                if(B.nome[j]=='o')
                    LETRA=load_bitmap("fonte\\o.bmp", NULL);
                 if(B.nome[j]=='q')
                    LETRA=load_bitmap("fonte\\q.bmp", NULL);
                 if(B.nome[j]=='l')
                    LETRA=load_bitmap("fonte\\l.bmp", NULL);
                 if(B.nome[j]=='w')
                 {
                    ERRO=1;
                    LETRA=load_bitmap("fonte\\w.bmp", NULL);
                 }
                 if(B.nome[j]=='y')
                    LETRA=load_bitmap("fonte\\y.bmp", NULL);
                 if(B.nome[j]=='u')
                    LETRA=load_bitmap("fonte\\u.bmp", NULL);
                 if(B.nome[j]=='i')
                    LETRA=load_bitmap("fonte\\i.bmp", NULL);
                 if(B.nome[j]=='p')
                    LETRA=load_bitmap("fonte\\p.bmp", NULL);
                 if(B.nome[j]=='s')
                    LETRA=load_bitmap("fonte\\s.bmp", NULL);
                 if(B.nome[j]=='f')
                    LETRA=load_bitmap("fonte\\f.bmp", NULL);
                 if(B.nome[j]=='g')
                    LETRA=load_bitmap("fonte\\g.bmp", NULL);
                 if(B.nome[j]=='h')
                    LETRA=load_bitmap("fonte\\h.bmp", NULL);
                 if(B.nome[j]=='j')
                    LETRA=load_bitmap("fonte\\j.bmp", NULL);
                 if(B.nome[j]=='k')
                    LETRA=load_bitmap("fonte\\k.bmp", NULL);
                 if(B.nome[j]=='z')
                    LETRA=load_bitmap("fonte\\z.bmp", NULL);
                 if(B.nome[j]=='x')
                    LETRA=load_bitmap("fonte\\x.bmp", NULL);
                 if(B.nome[j]=='c')
                    LETRA=load_bitmap("fonte\\c.bmp", NULL);
                 if(B.nome[j]=='v')
                    LETRA=load_bitmap("fonte\\v.bmp", NULL);
                 if(B.nome[j]=='b')
                    LETRA=load_bitmap("fonte\\b.bmp", NULL);
                 if(B.nome[j]=='m')
                 {
                    ERRO=1;
                    LETRA=load_bitmap("fonte\\m.bmp", NULL);
                 }
                 if(B.nome[j]=='d')
                    LETRA=load_bitmap("fonte\\d.bmp", NULL);
                if(!feof(arq))    
                draw_sprite(screen,LETRA,x+((Mov*j)+E)+20+15,y+((i-1)*32));
                LETRA=load_bitmap("fonte\\null.bmp", NULL);
                
                if(ERRO==1)
                 {
                    E=Mov/4;ERRO=0;
                 }
                 else
                 E=0;
            }
            
            
        }
            char min[4]={};
            char sec[4]={};
            itoa(B.tempo[0],min,10);
            itoa(B.tempo[1],sec,10);
         i++;
    }
       while(!key[KEY_ENTER]&&!key[KEY_ENTER_PAD])
    {
          int y=0;
    }
    
}
void escolhe(int &x, int &y,int mat[8][8])
{
    allegro_init();
	install_keyboard();

	set_color_depth(32);
	set_gfx_mode(GFX_AUTODETECT_WINDOWED, MAX,MAY,0,0);
	install_sound(DIGI_AUTODETECT,MIDI_AUTODETECT,NULL);
	SAMPLE *MOV;
	
	MOV=load_wav("mov.wav");
	       BITMAP *TAB;
	       TAB=load_bitmap("tab.bmp", NULL);


	       BITMAP *CAVALO;
	       CAVALO=load_bitmap("cavalo.bmp", NULL);


	       BITMAP *CAVALOB;
	       CAVALOB=load_bitmap("cavaloB.bmp", NULL);
	       
	       draw_sprite(screen,TAB,0,0);
	       
	       BITMAP *ENT;
	       ENT=load_bitmap("ent.bmp", NULL);
	       
	       BITMAP *ENTb;
	       ENTb=load_bitmap("entB.bmp", NULL);

	       draw_sprite(screen,TAB,0,0);
	       draw_sprite(screen,ENT,0,0);
	       int x2=0,y2=0;
	       int tecla=0;
	       while(!key[KEY_ENTER]&&!key[KEY_ENTER_PAD])
            {
           
           
               label:
               tecla=readkey();

            
             if ((tecla >> 8) == KEY_RIGHT)
             {
                 if(x+1>7)
                    goto label;
                 else
                 {
                  x=x+1;
                  x2=x2+cavX;
                 }
                 
             }
             if ((tecla >> 8) == KEY_LEFT)
             {
                 if(x-1<0)
                    goto label;
                 else
                 {
                  x=x-1;
                  x2=x2-cavX;
                 }

             }
             if ((tecla >> 8) == KEY_UP)
             {
                 if(y-1<0)
                    goto label;
                 else
                 {
                  y=y-1;
                  y2=y2-cavY;
                 }

             }
             if ((tecla >> 8) == KEY_DOWN)
             {
                 if(y+1>7)
                    goto label;
                 else
                 {
                  y=y+1;
                  y2=y2+cavY;
                 }

             }
             clear(screen);
             draw_sprite(screen,TAB,0,0);
             
             if(mat[x][y]==1)
                draw_sprite(screen,ENTb,x2,y2);
             else
                draw_sprite(screen,ENT,x2,y2);
    }
     clear(screen);
     draw_sprite(screen,TAB,0,0);
     SAMPLE *OK;//Ponteiro pro tipo wav
	 OK=load_wav("Mov.wav");
	 play_sample(OK,255,90,1000,0);
             if(mat[x][y]==1)
                draw_sprite(screen,CAVALOB,x2,y2);
             else
                draw_sprite(screen,CAVALO,x2,y2);
      
     // x=x2;y=y2;
      tecla=readkey();          
      while(!key[KEY_ENTER]&&!key[KEY_ENTER_PAD])
      int j;
      
      allegro_exit();
           
}
int menu()
{
      SAMPLE *THEME;//Ponteiro pro tipo wav
	  THEME=load_wav("Unf.wav");
	  play_sample(THEME,255,90,1000,1);                     
      label:
      BITMAP*INICIO=load_bitmap("inicio.bmp", NULL);
      draw_sprite(screen,INICIO,0,0);
	  int i=0,tecla=0;   
      readkey();   
	        while(!key[KEY_ENTER]&&!key[KEY_ENTER_PAD])
             {
                 
                 if(key[KEY_ESC])
                 {
                        return 9;
                    }
                 if(key[KEY_DOWN]) 
                 {
                        i++;                       
                 }
                 if(key[KEY_UP])
                 {
                        i--;
                 }
                 
                 if(i==0)
                 INICIO=load_bitmap("inicio.bmp", NULL);
                 if(i==1)
                 INICIO=load_bitmap("iniciob.bmp", NULL);
                 if(i==2)
                 INICIO=load_bitmap("inicioc.bmp", NULL);
                 if(i==3)
                 INICIO=load_bitmap("iniciod.bmp", NULL);
                 
                 draw_sprite(screen,INICIO,0,0);
                 readkey(); 
            }
            
            if(i==1)
            {
               clear_keybuf();

                       BITMAP *INICIO2;
            	       INICIO2=load_bitmap("inicio2.bmp", NULL);
            	       draw_sprite(screen,INICIO2,0,0);
            	       	readkey();
            
                while(!key[KEY_ENTER]&&!key[KEY_ENTER_PAD])
                {
                      int y=0;
                }
                       BITMAP *INICIO3;
            	       INICIO3=load_bitmap("inicio3.bmp", NULL);
            	       draw_sprite(screen,INICIO3,0,0);
           	       	   readkey();
            
                while(!key[KEY_ENTER]&&!key[KEY_ENTER_PAD])
                {
                      int y=0;
                }
                
                goto label;
              
              
              
            }
            if(i==2)
            {
                ranking();
                readkey();
                 while(!key[KEY_ENTER]&&!key[KEY_ENTER_PAD])
                {
                      int y=0;
                }
                goto label;
            }
            if(i>=3)
            {
                return 9;
            }
             
            clear(screen);
}
int main()
{
    int mat [8][8]={};
	int x=0;
    int y=0;
    rank B;
    int tecla = 0 ;
    x=0;y=0;
    int matriz[8][8]={};
    //matriz[0][0]=1;
    int MatPos[64][3]={};
    int i=0,cor=0;
    int Start=0;
    MatPos[0][0]=1;
    MatPos[0][1]=1;
    MatPos[0][2]=0;
    
     for(int y=0;y<8;y++)
        for(int j=0;j<8;j++)
        {
            if(y%2==0 && j%2!=0 || y%2!=0 && j%2==0)
                mat[y][j]=1;
        }
    allegro_init();//Inica a Janela
	install_keyboard();//Instala teclado
    SAMPLE *THEME;//Ponteiro pro tipo wav
	set_color_depth(32);//Qualidade das cores
	set_gfx_mode(GFX_AUTODETECT_WINDOWED, MAX,MAY,0,0);//X Y da janela
	install_sound(DIGI_AUTODETECT,MIDI_AUTODETECT,NULL);
	
	int sair = menu();
	if(sair==9)
	return 0;
	
    user1(B.nome);
    allegro_exit();
        
           //------------------------------------------
    
    //--------------------------------------------------------------------------
    escolhe(x,y,mat);
    //--------------------------------------------------------------------------    
    MatPos[0][0]=x*cavX;
    MatPos[0][1]=y*cavY;
    
    if(MatPos[0][0]==0)
    MatPos[0][0]=1;
    if(MatPos[0][1]==0)
    MatPos[0][1]=1;
    if(mat[x][y]==1)
    MatPos[0][2]=1;
    else
    MatPos[0][2]=0;
	allegro_init();
	install_keyboard();

	set_color_depth(32);
	set_gfx_mode(GFX_AUTODETECT_WINDOWED, MAX,MAY,0,0);
	install_sound(DIGI_AUTODETECT,MIDI_AUTODETECT,NULL);
	SAMPLE *MOV;
	MOV=load_wav("mov.wav");
	       BITMAP *TAB;
	       TAB=load_bitmap("tab.bmp", NULL);
	      

	       BITMAP *CAVALO;
	       CAVALO=load_bitmap("cavalo.bmp", NULL);
	       

	       BITMAP *CAVALOB;
	       CAVALOB=load_bitmap("cavaloB.bmp", NULL);

	       BITMAP *X;
	       X=load_bitmap("X.bmp", NULL);

	       BITMAP *Xb;
	       Xb=load_bitmap("Xb.bmp", NULL);

         
	 draw_sprite(screen,TAB,0,0);
	 
     if(mat[x][y]==1)
                draw_sprite(screen,CAVALOB,x*cavX,y*cavY);
             else
                draw_sprite(screen,CAVALO,x*cavX,y*cavY);
    
    int fim=0,pts=0;
    stop_sample(THEME);
    int matX=y,matY=x;
    matriz[y][x]=1;
    int inicio[2];
    x=x*cavX,y=y*cavY;
 
    float iclock=clock();   
    int trancado=0;
	while(!key[KEY_ESC]&&fim==0&&trancado==0)
        {
            
             pts=0;
             label:
             tecla=readkey();
                         
             play_sample(MOV,255,90,1000,0);
             
              if(!key[KEY_ESC])
                 if(!((tecla & 0xff)>47&&(tecla & 0xff)<58))
                 goto label;
             
             if(Start==1)
             {
                MatPos[i][0]=y; 
                MatPos[i][1]=x;  
                MatPos[i][2]=cor; 
                                   
             }
             
             
              
              if(matriz[matX+2][matY+1]==1||matX+2>7||matY+1>7)//K3
                if(matriz[matX-2][matY-1]==1||matX-2<0||matY-1<0)//K7
                   if(matriz[matX+2][matY-1]==1||matX+2>7||matY-1<0)//K1
                     if(matriz[matX+1][matY+2]==1||matX+1>7||matY+2>7)//K2
                        if(matriz[matX+1][matY-2]==1||matX+1>7||matY-2<0)//K4
                           if(matriz[matX-1][matY+2]==1||matX-1<0||matY+2>7)//K6
                             if(matriz[matX-1][matY-2]==1||matX-1<0||matY-2<0)//K8)
                                if(matriz[matX-2][matY+1]==1||matX-2<0||matY+1>7)
                                {                                  
                                    trancado=1;
                                    BITMAP *OVER=load_bitmap("gameover.bmp", NULL);
	                                draw_sprite(screen,OVER,155,232);
	                                while(!key[KEY_ENTER]&&!key[KEY_ENTER_PAD])
                                    int times=0;                                                                                                  
                                    goto Fim;
                                }
              /*&&matriz[matX-2][matY-1]==1||matX-2<0||matY-1<0//K7
              &&matriz[matX+2][matY-1]==1||matX+2>7||matY-1<0//K1
              &&matriz[matX-2][matY+1]==1||matX-2<0||matY+1>7//K9
              &&matriz[matX-1][matY+2]==1||matX-1<0||matY+2>7//K6
              &&matriz[matX-1][matY-2]==1||matX-1<0||matY-2<0//K8
              &&matriz[matX+1][matY-2]==1||matX+1>7||matY-2<0//K4
              &&matriz[matX+1][matY+2]==1||matX+1>7||matY+2>7))//K2*/
              
              
              
             if ((tecla >> 8) == KEY_5_PAD||(tecla >> 8) == KEY_5)
             goto label;
             if ((tecla >> 8) == KEY_3_PAD||(tecla >> 8) == KEY_3)
             {
                 if(matriz[matX+2][matY+1]==1||matX+2>7||matY+1>7)//
                    goto label;
                 else
                 {
                 matX=matX+2;matY=matY+1;
                 x=x+cavX;y=y+(2*cavY);  
                }                                                           
             }
             if ((tecla >> 8) == KEY_7_PAD||(tecla >> 8) == KEY_7)
             {
                 if(matriz[matX-2][matY-1]==1||matX-2<0||matY-1<0)
                    goto label; 
                 else
                 {
                     matX=matX-2;matY=matY-1;
                     x=x-cavX;y=y-(2*cavY);
                 }                                                   
             }
             if ((tecla >> 8) == KEY_1_PAD||(tecla >> 8) == KEY_1)
             {
                 if(matriz[matX+2][matY-1]==1||matX+2>7||matY-1<0)
                    goto label;
                 else
                 {
                 matX=matX+2;matY=matY-1;                
                 x=x-cavX;y=y+(2*cavY);
                }
             }
             if ((tecla >> 8) == KEY_9_PAD||(tecla >> 8) == KEY_9)
             {
                 if(matriz[matX-2][matY+1]==1||matX-2<0||matY+1>7)
                    goto label;
                 else
                 {
                 matX=matX-2;matY=matY+1;
                 matriz[matX][matY]=1;
                 x=x+cavX;y=y-(2*cavY);  
                 }              
             }
             if ((tecla >> 8) == KEY_6_PAD||(tecla >> 8) == KEY_6)
             {
                 if(matriz[matX-1][matY+2]==1||matX-1<0||matY+2>7)
                    goto label;
                 else
                 {
                 matX=matX-1;matY=matY+2;              
                 x=x+(2*cavX);y=y-(cavY);
                 }               
             }
             if ((tecla >> 8) == KEY_8_PAD||(tecla >> 8) == KEY_8)
             {
                 if(matriz[matX-1][matY-2]==1||matX-1<0||matY-2<0)
                    goto label;
                 else
                 {
                 matX=matX-1;matY=matY-2;                
                 x=x-(2*cavX);y=y-(cavY);
                 }              
             }
             if ((tecla >> 8) == KEY_4_PAD||(tecla >> 8) == KEY_4)
             {
                 if(matriz[matX+1][matY-2]==1||matX+1>7||matY-2<0)
                    goto label;
                 else
                 {
                 matX=matX+1;matY=matY-2;                
                 x=x-(2*cavX);y=y+(cavY);  
                 }              
             }
             if ((tecla >> 8) == KEY_2_PAD||(tecla >> 8) == KEY_2)
             {
                 if(matriz[matX+1][matY+2]==1||matX+1>7||matY+2>7)
                 goto label;
                 else
                 {
                 matX=matX+1;matY=matY+2;                 
                 x=x+(2*cavX);y=y+(cavY);    
                 }           
             }

                 matriz[matX][matY]=1;
                 clear(screen);
                 draw_sprite(screen,TAB,0,0);
                
                 
                    for(int p=0;p<8;p++)
                    for(int h=0;h<8;h++)
                    {
                       if(matriz[0][0]==1)
                       {
                            if(matriz[h][p]==1)
                            {
                                 if(mat[h][p]==1)
                                 {
                                    draw_sprite(screen,Xb,p*cavX,h*cavY); cor=1;                                                     
                                 }
                                 else
                                 {
                                    draw_sprite(screen,X,p*cavX,h*cavY);  cor=0;
                                 }
                             }
                        }
                        else
                        {
                            if(matriz[h][p]==1)
                            {
                                 if(mat[h][p]==1)
                                 {
                                    draw_sprite(screen,Xb,p*cavX,h*cavY); cor=1;
                                 }
                                 else
                                 {
                                    draw_sprite(screen,X,p*cavX,h*cavY);  cor=0;
                                 }
                          
                             }
                         }
                        
                         
                    }
                     
                 if(mat[matX][matY]==1)
                 {
                    draw_sprite(screen,CAVALOB,x,y); cor=1;                   
                 }
                 else
                 {
                    draw_sprite(screen,CAVALO,x,y);  cor=0;             
                 }
                    
               
                 Fim:      
              i++; 
              Start=1;
              fim=1;
              for(int f=0;f<8;f++)
                for(int f1=0;f1<8;f1++)
                   if( matriz[f1][f]==0)
                   fim=0;
                   else
                   {
                    pts++;  
                }
                   
           
                    
        
        
        }
        float jclock=clock();
        allegro_exit();
        allegro_init();
	    install_keyboard();

	    set_color_depth(32);
	    set_gfx_mode(GFX_AUTODETECT_WINDOWED, MAX,MAY,0,0);
	    install_sound(DIGI_AUTODETECT,MIDI_AUTODETECT,NULL);
           BITMAP *FIM;
           SAMPLE *FINAL;//Ponteiro pro tipo wav
           if(fim==1)
           {
	            FIM=load_bitmap("win.bmp", NULL);
	            FINAL=load_wav("Par.wav");
            }
	       else
	       {
               char pontos[3]={};
               char img[6]={};int espaco=32;
    	       FIM=load_bitmap("lose.bmp", NULL);
               FINAL=load_wav("Sta.wav");
               draw_sprite(screen,FIM,0,0);
               BITMAP *um;BITMAP *dois;BITMAP *tres;BITMAP *zero;
               BITMAP *quatro;BITMAP *cinco;BITMAP *seis;
               BITMAP *sete;BITMAP *oito;BITMAP *nove;
               itoa(pts,pontos,10);
               um=load_bitmap("1.bmp", NULL);
               dois=load_bitmap("2.bmp", NULL);
               tres=load_bitmap("3.bmp", NULL);
               quatro=load_bitmap("4.bmp", NULL);
               cinco=load_bitmap("5.bmp", NULL);
               seis=load_bitmap("6.bmp", NULL);
               sete=load_bitmap("7.bmp", NULL);
               oito=load_bitmap("8.bmp", NULL);
               nove=load_bitmap("9.bmp", NULL);
               zero=load_bitmap("0.bmp", NULL);
               
               for(int i=0;i<=1;i++)
               {                                          
                     if(pontos[i]=='1')                  
                     draw_sprite(screen,um,220+(espaco*i),450);
                     if(pontos[i]=='2') 
                     draw_sprite(screen,dois,220+(espaco*i),450);
                     if(pontos[i]=='3') 
                     draw_sprite(screen,tres,220+(espaco*i),450);
                     if(pontos[i]=='4') 
                     draw_sprite(screen,quatro,220+(espaco*i),450);
                     if(pontos[i]=='5') 
                     draw_sprite(screen,cinco,220+(espaco*i),450);
                     if(pontos[i]=='6') 
                     draw_sprite(screen,seis,220+(espaco*i),450);
                     if(pontos[i]=='7') 
                     draw_sprite(screen,sete,220+(espaco*i),450);
                     if(pontos[i]=='8') 
                     draw_sprite(screen,oito,220+(espaco*i),450);
                     if(pontos[i]=='9') 
                     draw_sprite(screen,nove,220+(espaco*i),450);
                     if(pontos[i]=='0') 
                     draw_sprite(screen,zero,220+(espaco*i),450);
                                         
               }
                              
            }
           
           int SEC=(jclock-iclock)/1000;

  
  B.pontos=pts;
  B.tempo[0]=SEC/60;
  B.tempo[1]=SEC-((SEC/60)*60);
  B.tempo[2]=(jclock-iclock)/1000;;
 
  grava(B);
  
  
	 play_sample(FINAL,255,90,1000,1);
           
	       

    while(!key[KEY_ENTER]&&!key[KEY_ENTER_PAD])
    {
          int y=0;
    }
    readkey();
    ranking();
    readkey();
    stop_sample(FINAL);
    allegro_exit();
    main();
        return 0;
}
END_OF_MAIN();



