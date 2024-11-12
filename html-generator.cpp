/* HTML-generator v1.0

	Tuukka J‰rvenp‰‰
	Marko Kairinen
	Markus Karjalainen
*/

#include <iostream.h>
#include <conio.h>
#include <fstream.h>
void PiirraValikot(char[],char,char,char,int);
int FontValikko (int);
void PoistaValikot(void);
int StyleValikko(int);
void StylePaivitys(int,char[],char,char,char,int);
int SizeValikko(int);
int FileValikko(void);
void HelpValikko(void);
void TitleWindow (void);
void OtsikkoHelppi (void);
void HTMLTyyli (int,char *,char *,char *,int *,int *);
void FontStatus (int,char *,char,char,char,int);
void TyhjennaTiedosto(void);
void AlustaHTML (int,char[],char[]);
void LuoTiedosto(char,char,char);
int WorkSpaceFull(void);

fstream kirjoita("MyPage.txt");
char title[25];
char tiedosto[9]={' ',' ',' ',' ',' ',' ',' ',' ',' '};

int main(void)
{
        char font[16]="Times New Roman";
        char underline, bold, italic;
        int size=3;
        int i=0,j=0,k=0,l=0;
        int syote;
        int fontti=0;
        int style=0;
        int file=0;
        int sarkainTaulu[2][30]={{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                                 {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}};
        int fonttiTaulu[2][30]={{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                                 {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}};
        int styleTaulu[2][30]={{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                                 {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}};
        char kirjain;
        int x=1;
        int y=7;
        int kursorinPaikka[20]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
        int taustavari=0, tekstinvari=7;
        int lopetus=0;

        TitleWindow();

        PoistaValikot();
        AlustaHTML(size,title,font);

        underline=' ';
        bold=' ';
        italic=' ';
        clrscr();
        x=1;
        y=7;
        PiirraValikot(font, underline, bold, italic, size);


        while (lopetus!=1)
        {
                textcolor(tekstinvari);
                textbackground(taustavari);
                if((syote!=13)&&(x==79)){kursorinPaikka[i]=0;}
                gotoxy(x,y);    //kursorin liikkuminen kirjoituksen mukana
                syote=getch();
                kirjain=syote;  //muutetaan kirjain ASCII-koodille

                if(syote!=20&&syote!=15&&syote!=19&&syote!=6&&syote!=9&&syote!=5&&syote!=8&&syote!=13) //ohjauskomentoja ei tulosteta
                {
                        cprintf("%c", kirjain);
                        x++; //kursorin liike vaakatasossa
                        kirjoita<<kirjain;
                }

                if (syote==20) //jos painettu Ctrl+T piirret‰‰n style-valikko
                {
                        style=StyleValikko(style);
                        StylePaivitys(style, font, underline, bold, italic, size);
                        HTMLTyyli(style,&bold,&italic,&underline,&tekstinvari,&taustavari);
                        styleTaulu[0][l]=x;
                        styleTaulu[1][l]=y;
                        l++;
                }

                if (syote==15) //jos painettu Ctrl+O piirret‰‰n fontti-valikko
                {
                        fontti=FontValikko(fontti);
                        FontStatus(fontti,font,underline,bold,italic,size);

                        fonttiTaulu[0][k]=x;
                        fonttiTaulu[1][k]=y;
                        k++;
                }

                if (syote==19)  //jos painettu Ctrl+S piirret‰‰n size-valikko
                {
                        size=SizeValikko(size);

                        StylePaivitys(style, font, underline, bold, italic, size);
                        kirjoita<<"<font face=\""<<font<<"\" size=\""<<size<<"\">";

                        fonttiTaulu[0][k]=x;
                        fonttiTaulu[1][k]=y;
                        k++;
                }

                if (syote==6)  //jos painetaan Ctrl+F piirret‰‰n file-valikko
                {
                        file=FileValikko();
                        if (file==69||file==101)
                        {
                                kirjoita.close();
                                DeleteFile("MyPage.txt");
                                lopetus=1;
                        }
                        if (file==78||file==110)
                        {

                                x=1;
                                y=7;
                                i=0;
                                j=0;
                                k=0;
                                l=0;
                                clrscr();
                                underline=' ';
                                bold=' ';
                                italic=' ';
                                size=3;
                                font[0]='T';font[1]='i';font[2]='m';font[3]='e';
                                font[4]='s';font[5]=' ';font[6]='N';font[7]='e';
                                font[8]='w';font[9]=' ';font[10]='R';font[11]='o';
                                font[12]='m';font[13]='a';font[14]='n';
                                PiirraValikot(font, underline, bold, italic, size);
                                gotoxy(x,y);
                                TyhjennaTiedosto();
                                AlustaHTML(size,title,font);
                                taustavari=0;
                                tekstinvari=7;
                        }
                        if (file==71||file==103)
                        {
                                LuoTiedosto(bold,italic,underline);
                        }

                }

                if (syote==5) //Jos painetaan Ctrl+E siirryt‰‰n help-valikkoon
                {
                        HelpValikko();
                }
                if (syote==13)  //enter-painallus vaihtaa rivia
                {
                        kirjoita<<"<br />";
                        kursorinPaikka[i]=x;
                        y++;
                        x=1;
                        i++;
                }
                if (y==23&&x==80)      //est‰‰ liian alas menemisen kirjoittamalla
                {
                        if (syote!=13)
                                x=80;

                        while(syote!=8)
                        {
                                syote=WorkSpaceFull();
                        }
                        gotoxy(50,25);
                        textbackground(BLACK);
                        textcolor(BLACK);
                        cprintf("                      ");
                        textbackground(taustavari);
                        textcolor(tekstinvari);
                }

                if (y==24)      //est‰‰ liian alas menemisen Enteri‰ painamalla
                {
                        while(syote!=8)
                        {
                                syote=WorkSpaceFull();
                        }
                        gotoxy(49,25);
                        textbackground(BLACK);
                        textcolor(BLACK);
                        cprintf("                               ");
                        textbackground(taustavari);
                        textcolor(tekstinvari);
                }

                if (syote==8) //syˆte on backspace
                {
                        if(x==fonttiTaulu[0][k-1]&&y==fonttiTaulu[1][k-1])
                        {
                                kirjoita.seekg(-38, ios_base::cur);
                                kirjoita<<"                                      ";
                                kirjoita.seekg(-38, ios_base::cur);
                                k--;
                        }
                        if(x==styleTaulu[0][l-1]&&y==styleTaulu[1][l-1])
                        {
                                kirjoita.seekg(-12, ios_base::cur);
                                kirjoita<<"            ";
                                kirjoita.seekg(-12, ios_base::cur);
                                l--;
                        }
                        if (x==1&&y==7)
                        {
                        }
                        else if (x!=1&&x!=sarkainTaulu[0][j-1])
                        {
                                kirjoita.seekg(-1, ios_base::cur);
                                kirjoita<<" ";
                                kirjoita.seekg(-1, ios_base::cur);
                                x=x-1;
                                gotoxy(x,y);
                                textcolor(BLACK);
                                textbackground(BLACK);
                                cprintf(" ");
                        }


                        else if(x==sarkainTaulu[0][j-1]&&y==sarkainTaulu[1][j-1])
                        {
                                if (x==1)
                                {
                                        y--;
                                        x=80;
                                        j--;
                                }
                                else
                                {
                                        x=x-10;
                                        kirjoita.seekg(-60, ios_base::cur);
                                        kirjoita<<"                    ";
                                        kirjoita<<"                    ";
                                        kirjoita<<"                    ";
                                        kirjoita.seekg(-60, ios_base::cur);
                                        j--;
                                }
                        }
                        else
                        {
                                kirjoita.seekg(-6, ios_base::cur);
                                kirjoita<<"      ";
                                kirjoita.seekg(-6, ios_base::cur);
                                y--;
                                x=80;
                                i--;
                                if(kursorinPaikka[i]!=0)
                                {
                                        x=kursorinPaikka[i];
                                }
                        }


                }

                if(syote==9) //jos syˆte on sarkain
                {
                        if (x>=70)
                        {

                                x=1;
                                y++;
                                sarkainTaulu[0][j]=x;
                                sarkainTaulu[1][j]=y;
                                j++;
                                kirjoita<<"   <br />";
                        }
                        else
                        {
                                textbackground(BLACK);
                                kirjoita<<"&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;";
                                cprintf("          ");
                                x=x+10;
                                sarkainTaulu[0][j]=x;
                                sarkainTaulu[1][j]=y;
                                j++;
                                textbackground(taustavari);
                        }
                }
                if (x>=80&&syote!=8)           //rivin lopussa lis‰t‰‰n 80 jotta muuttuja pysyy laskuissa
                {
                        kursorinPaikka[i]=x;
                        x=1;
                        y++;
                        kirjoita<<"<br />";
                        i++;
                }
        }
return 0;
}

void PiirraValikot(char font[], char underline,
char bold, char italic, int size)
{
        int koko=0;

        if(size==1)koko=8;
        if(size==2)koko=10;
        if(size==3)koko=12;

        gotoxy(1,25);
        textcolor(WHITE);
        textbackground(BLACK);
        cprintf("  FONT:");
        textcolor(BLUE);
        cprintf(" %s",font);
        textcolor(WHITE);
        cprintf("  STYLE:");

        if(bold==' '&&underline==' '&&italic==' ')
        {
                textcolor(LIGHTGRAY);
        }
        if(bold=='B'&&underline==' '&&italic==' ')
        {
                textcolor(BLACK);
                textbackground(LIGHTGRAY);
        }
        if(bold==' '&&underline==' '&&italic=='I')
        {
                textcolor(WHITE);
                textbackground(BLACK);
        }
        if(bold==' '&&underline=='U'&&italic==' ')
        {
                textcolor(BLUE);
                textbackground(BLACK);
        }
        if(bold=='B'&&underline=='U'&&italic=='I')
        {
                textcolor(RED);
                textbackground(LIGHTGRAY);
        }
        if(bold=='B'&&underline=='U'&&italic==' ')
        {
                textcolor(BLUE);
                textbackground(LIGHTGRAY);
        }
        if(bold=='B'&&underline==' '&&italic=='I')
        {
                textcolor(WHITE);
                textbackground(LIGHTGRAY);
        }
        if(bold==' '&&underline=='U'&&italic=='I')
        {
                textcolor(WHITE);
                textbackground(BLUE);
        }
        cprintf(" %c %c %c", underline, bold, italic);
        textbackground(BLACK);
        textcolor(WHITE);
        cprintf("  SIZE:");
        textcolor(BLUE);
        cprintf(" %u                   ", koko);
        gotoxy(1,1);
        textcolor(LIGHTGRAY);
        textbackground(BLUE);
        cprintf("  F");
        textcolor(WHITE);
        cprintf("ILE  F");
        textcolor(LIGHTGRAY);
        cprintf("O");
        textcolor(WHITE);
        cprintf("NT  S");
        textcolor(LIGHTGRAY);
        cprintf("T");
        textcolor(WHITE);
        cprintf("YLE   ");
        textcolor(LIGHTGRAY);
        cprintf("S");
        textcolor(WHITE);
        cprintf("IZE  ");
        cprintf("                          ");
        cprintf("                    H");
        textcolor(LIGHTGRAY);
        cprintf("E");
        textcolor(WHITE);
        cprintf("LP  ");
}

int FontValikko(int fontti)
{
int syote;
textbackground(BLUE);
textcolor(WHITE);
syote=fontti;
while(syote!=27) //ESC-n‰pp‰imell‰ pois
{
        if (syote==0 || syote==116) //Piirret‰‰n valikko jossa TimesNewRoman on oletuksena
        {
                gotoxy(8,2);
                cprintf(" Arial           ");
                gotoxy(8,3);
                cprintf(" Helvetica       ");
                gotoxy(8,4);
                cprintf("xTimes New Roman ");
                gotoxy(10,10);
                syote=getch();

                while (syote!=65 && syote!=97 && syote!=72 &&
                syote!=104 && syote!=84 && syote!=116 && syote!=27)
                        syote=getch();

                if (syote!=27)
                        fontti=syote;
        }
        if (syote==104) //Helvetica-fontin kohdalle rasti ja muut tyhj‰ksi
        {
        gotoxy(8,4);
        cprintf(" Times New Roman");
        gotoxy(8,3);
        cprintf("xHelvetica      ");
        gotoxy(8,2);
        cprintf(" Arial          ");
        gotoxy(10,10);
        syote=getch();

        while (syote!=65 && syote!=97 && syote!=72 &&
        syote!=104 && syote!=84 && syote!=116 && syote!=27)
                syote=getch();

        if (syote!=27)
                fontti=syote;
        }
        if (syote==97) // Arial-fontin kohdalle rasti ja muut tyhj‰ksi
        {
        gotoxy(8,4);
        cprintf(" Times New Roman");
        gotoxy(8,3);
        cprintf(" Helvetica      ");
        gotoxy(8,2);
        cprintf("xArial          ");
        gotoxy(10,10);
        syote=getch();

        while (syote!=65 && syote!=97 && syote!=72 &&
        syote!=104 && syote!=84 && syote!=116 && syote!=27)
                syote=getch();

        if (syote!=27)
                fontti=syote;
        }
}
PoistaValikot();

return fontti;
}

void PoistaValikot()
{
gotoxy(1,2);
textcolor(BLACK);
textbackground(BLACK);
int i;
for (i=0;i<10;i++)
{
        cprintf("                                        ");
}
}

int StyleValikko(int style)
{
int syote=0;
int boldKerrat=0;
int italicKerrat=0;
int underlineKerrat=0;

if (style==0)
{
        textcolor(WHITE);
        textbackground(BLUE);
        gotoxy(14,2);
        cprintf(" Bold      ");
        gotoxy(14,3);
        cprintf(" Italic    ");
        gotoxy(14,4);
        cprintf(" Underline ");
        syote=getch();

        while (syote!=98 && syote!=66 && syote!=85 &&
        syote!=117 && syote!=73 && syote!=105 && syote!=27)
                syote=getch();
}

if (style==1)
{
        textcolor(WHITE);
        textbackground(BLUE);
        gotoxy(14,2);
        cprintf("xBold      ");
        gotoxy(14,3);
        cprintf(" Italic    ");
        gotoxy(14,4);
        cprintf(" Underline ");
        syote=getch();

        while (syote!=98 && syote!=66 && syote!=85 &&
        syote!=117 && syote!=73 && syote!=105 && syote!=27)
                syote=getch();
}

if (style==2)
{
        textcolor(WHITE);
        textbackground(BLUE);
        gotoxy(14,2);
        cprintf(" Bold      ");
        gotoxy(14,3);
        cprintf("xItalic    ");
        gotoxy(14,4);
        cprintf(" Underline ");
        syote=getch();

        while (syote!=98 && syote!=66 && syote!=85 &&
        syote!=117 && syote!=73 && syote!=105 && syote!=27)
                syote=getch();
}

if (style==3)
{
        textcolor(WHITE);
        textbackground(BLUE);
        gotoxy(14,2);
        cprintf(" Bold      ");
        gotoxy(14,3);
        cprintf(" Italic    ");
        gotoxy(14,4);
        cprintf("xUnderline ");
        syote=getch();

        while (syote!=98 && syote!=66 && syote!=85 &&
        syote!=117 && syote!=73 && syote!=105 && syote!=27)
                syote=getch();
}

if (style==4)
{
        textcolor(WHITE);
        textbackground(BLUE);
        gotoxy(14,2);
        cprintf("xBold      ");
        gotoxy(14,3);
        cprintf("xItalic    ");
        gotoxy(14,4);
        cprintf("xUnderline ");
        syote=getch();

        while (syote!=98 && syote!=66 && syote!=85 &&
        syote!=117 && syote!=73 && syote!=105 && syote!=27)
                syote=getch();
}

if (style==5)
{
        textcolor(WHITE);
        textbackground(BLUE);
        gotoxy(14,2);
        cprintf("xBold      ");
        gotoxy(14,3);
        cprintf("xItalic    ");
        gotoxy(14,4);
        cprintf(" Underline ");
        syote=getch();

        while (syote!=98 && syote!=66 && syote!=85 &&
        syote!=117 && syote!=73 && syote!=105 && syote!=27)
        syote=getch();
}

if (style==6)
{
        textcolor(WHITE);
        textbackground(BLUE);
        gotoxy(14,2);
        cprintf(" Bold      ");
        gotoxy(14,3);
        cprintf("xItalic    ");
        gotoxy(14,4);
        cprintf("xUnderline ");
        syote=getch();

        while (syote!=98 && syote!=66 && syote!=85 &&
        syote!=117 && syote!=73 && syote!=105 && syote!=27)
                syote=getch();
}

if (style==7)
{
        textcolor(WHITE);
        textbackground(BLUE);
        gotoxy(14,2);
        cprintf("xBold      ");
        gotoxy(14,3);
        cprintf(" Italic    ");
        gotoxy(14,4);
        cprintf("xUnderline ");
        syote=getch();

        while (syote!=98 && syote!=66 && syote!=85 &&
        syote!=117 && syote!=73 && syote!=105 && syote!=27)
        syote=getch();
}

while (syote!=27)
{

        if ((syote==98||syote==66)&&boldKerrat==0&&
        italicKerrat==0&&underlineKerrat==0)
        {
                textcolor(WHITE);
                textbackground(BLUE);
                gotoxy(14,2);
                cprintf("xBold      ");
                gotoxy(14,3);
                cprintf(" Italic    ");
                gotoxy(14,4);
                cprintf(" Underline ");
                style=1;
                boldKerrat++;
                syote=getch();

                while (syote!=98 && syote!=66 && syote!=85 &&
                syote!=117 && syote!=73 && syote!=105 && syote!=27)
                        syote=getch();
        }

        if ((syote==98||syote==66)&&boldKerrat==1&&
        italicKerrat==0&&underlineKerrat==0)
        {
                textcolor(WHITE);
                textbackground(BLUE);
                gotoxy(14,2);
                cprintf(" Bold      ");
                gotoxy(14,3);
                cprintf(" Italic    ");
                gotoxy(14,4);
                cprintf(" Underline ");
                style=0;
                boldKerrat--;
                syote=getch();

                while (syote!=98 && syote!=66 && syote!=85 &&
                syote!=117 && syote!=73 && syote!=105 && syote!=27)
                        syote=getch();
        }

        if ((syote==73||syote==105)&&italicKerrat==0&&
        boldKerrat==0&&underlineKerrat==0)
        {
                textcolor(WHITE);
                textbackground(BLUE);
                gotoxy(14,2);
                cprintf(" Bold      ");
                gotoxy(14,3);
                cprintf("xItalic    ");
                gotoxy(14,4);
                cprintf(" Underline ");
                style=2;
                italicKerrat++;
                syote=getch();

                while (syote!=98 && syote!=66 && syote!=85 &&
                syote!=117 && syote!=73 && syote!=105 && syote!=27)
                        syote=getch();
        }

        if ((syote==73||syote==105)&&italicKerrat==1&&
        boldKerrat==0&&underlineKerrat==0)
        {
                textcolor(WHITE);
                textbackground(BLUE);
                gotoxy(14,2);
                cprintf(" Bold      ");
                gotoxy(14,3);
                cprintf(" Italic    ");
                gotoxy(14,4);
                cprintf(" Underline ");
                style=0;
                italicKerrat--;

                syote=getch();
                while (syote!=98 && syote!=66 && syote!=85 &&
                syote!=117 && syote!=73 && syote!=105 && syote!=27)
                        syote=getch();
        }

        if ((syote==85||syote==117)&&underlineKerrat==0&&
        boldKerrat==0&&italicKerrat==0)
        {
                textcolor(WHITE);
                textbackground(BLUE);
                gotoxy(14,2);
                cprintf(" Bold      ");
                gotoxy(14,3);
                cprintf(" Italic    ");
                gotoxy(14,4);
                cprintf("xUnderline ");
                style=3;
                underlineKerrat++;
                syote=getch();

                while (syote!=98 && syote!=66 && syote!=85 &&
                syote!=117 && syote!=73 && syote!=105 && syote!=27)
                syote=getch();
        }

        if ((syote==85||syote==117)&&underlineKerrat==1&&
        boldKerrat==0&&italicKerrat==0)
        {
                textcolor(WHITE);
                textbackground(BLUE);
                gotoxy(14,2);
                cprintf(" Bold      ");
                gotoxy(14,3);
                cprintf(" Italic    ");
                gotoxy(14,4);
                cprintf(" Underline ");
                style=0;
                underlineKerrat--;
                syote=getch();

                while (syote!=98 && syote!=66 && syote!=85 &&
                syote!=117 && syote!=73 && syote!=105 && syote!=27)
                        syote=getch();
        }

        if ((syote==85||syote==117)&&boldKerrat==1&&
        underlineKerrat==0&&italicKerrat==0)
        {
                textcolor(WHITE);
                textbackground(BLUE);
                gotoxy(14,2);
                cprintf("xBold      ");
                gotoxy(14,3);
                cprintf(" Italic    ");
                gotoxy(14,4);
                cprintf("xUnderline ");
                style=7;
                underlineKerrat++;
                syote=getch();

                while (syote!=98 && syote!=66 && syote!=85 &&
                syote!=117 && syote!=73 && syote!=105 && syote!=27)
                        syote=getch();
        }

        if ((syote==85||syote==117)&&boldKerrat==1&&
        underlineKerrat==1&&italicKerrat==0)
        {
                textcolor(WHITE);
                textbackground(BLUE);
                gotoxy(14,2);
                cprintf("xBold      ");
                gotoxy(14,3);
                cprintf(" Italic    ");
                gotoxy(14,4);
                cprintf(" Underline ");
                style=1;
                underlineKerrat--;
                syote=getch();

                while (syote!=98 && syote!=66 && syote!=85 &&
                syote!=117 && syote!=73 && syote!=105 && syote!=27)
                        syote=getch();
        }

        if ((syote==105||syote==73)&&boldKerrat==1&&
        underlineKerrat==1&&italicKerrat==0)
        {
                textcolor(WHITE);
                textbackground(BLUE);
                gotoxy(14,2);
                cprintf("xBold      ");
                gotoxy(14,3);
                cprintf("xItalic    ");
                gotoxy(14,4);
                cprintf("xUnderline ");
                style=4;
                italicKerrat++;
                syote=getch();

                while (syote!=98 && syote!=66 && syote!=85 &&
                syote!=117 && syote!=73 && syote!=105 && syote!=27)
                        syote=getch();
        }

        if ((syote==105||syote==73)&&boldKerrat==1&&
        underlineKerrat==1&&italicKerrat==1)
        {
                textcolor(WHITE);
                textbackground(BLUE);
                gotoxy(14,2);
                cprintf("xBold      ");
                gotoxy(14,3);
                cprintf(" Italic    ");
                gotoxy(14,4);
                cprintf("xUnderline ");
                style=7;
                italicKerrat--;
                syote=getch();

                while (syote!=98 && syote!=66 && syote!=85 &&
                syote!=117 && syote!=73 && syote!=105 && syote!=27)
                syote=getch();
        }

        if ((syote==98||syote==66)&&boldKerrat==0&&
        underlineKerrat==1&&italicKerrat==1)
        {
                textcolor(WHITE);
                textbackground(BLUE);
                gotoxy(14,2);
                cprintf("xBold      ");
                gotoxy(14,3);
                cprintf("xItalic    ");
                gotoxy(14,4);
                cprintf("xUnderline ");
                style=4;
                boldKerrat++;
                syote=getch();

                while (syote!=98 && syote!=66 && syote!=85 &&
                syote!=117 && syote!=73 && syote!=105 && syote!=27)
                        syote=getch();
        }

        if ((syote==98||syote==66)&&boldKerrat==1&&underlineKerrat==1&&italicKerrat==1)
        {
                textcolor(WHITE);
                textbackground(BLUE);
                gotoxy(14,2);
                cprintf(" Bold      ");
                gotoxy(14,3);
                cprintf("xItalic    ");
                gotoxy(14,4);
                cprintf("xUnderline ");
                style=6;
                boldKerrat--;
                syote=getch();

                while (syote!=98 && syote!=66 && syote!=85 &&
                syote!=117 && syote!=73 && syote!=105 && syote!=27)
                syote=getch();
        }
        if ((syote==85||syote==117)&&boldKerrat==1&&underlineKerrat==0&&italicKerrat==1)
        {
                textcolor(WHITE);
                textbackground(BLUE);
                gotoxy(14,2);
                cprintf("xBold      ");
                gotoxy(14,3);
                cprintf("xItalic    ");
                gotoxy(14,4);
                cprintf("xUnderline ");
                style=4;
                underlineKerrat++;
                syote=getch();

                while (syote!=98 && syote!=66 && syote!=85 &&
                syote!=117 && syote!=73 && syote!=105 && syote!=27)
                        syote=getch();
         }

        if ((syote==85||syote==117)&&boldKerrat==1&&underlineKerrat==1&&italicKerrat==1)
        {
                textcolor(WHITE);
                textbackground(BLUE);
                gotoxy(14,2);
                cprintf("xBold      ");
                gotoxy(14,3);
                cprintf("xItalic    ");
                gotoxy(14,4);
                cprintf(" Underline ");
                style=5;
                underlineKerrat--;
                syote=getch();

                while (syote!=98 && syote!=66 && syote!=85 &&
                syote!=117 && syote!=73 && syote!=105 && syote!=27)
                syote=getch();
        }

        if ((syote==73||syote==105)&&boldKerrat==1&&
        underlineKerrat==0&&italicKerrat==0)
        {
                textcolor(WHITE);
                textbackground(BLUE);
                gotoxy(14,2);
                cprintf("xBold      ");
                gotoxy(14,3);
                cprintf("xItalic    ");
                gotoxy(14,4);
                cprintf(" Underline ");
                style=5;
                italicKerrat++;
                syote=getch();

                while (syote!=98 && syote!=66 && syote!=85 &&
                syote!=117 && syote!=73 && syote!=105 && syote!=27)
                        syote=getch();
        }

        if ((syote==73||syote==105)&&boldKerrat==1&&
        underlineKerrat==0&&italicKerrat==1)
        {
                textcolor(WHITE);
                textbackground(BLUE);
                gotoxy(14,2);
                cprintf("xBold      ");
                gotoxy(14,3);
                cprintf(" Italic    ");
                gotoxy(14,4);
                cprintf(" Underline ");
                style=1;
                italicKerrat--;
                syote=getch();

                while (syote!=98 && syote!=66 && syote!=85 &&
                syote!=117 && syote!=73 && syote!=105 && syote!=27)
                        syote=getch();
        }

        if ((syote==85||syote==117)&&boldKerrat==0&&
        underlineKerrat==0&&italicKerrat==1)
        {
                textcolor(WHITE);
                textbackground(BLUE);
                gotoxy(14,2);
                cprintf(" Bold      ");
                gotoxy(14,3);
                cprintf("xItalic    ");
                gotoxy(14,4);
                cprintf("xUnderline ");
                style=6;
                underlineKerrat++;
                syote=getch();

                while (syote!=98 && syote!=66 && syote!=85 &&
                syote!=117 && syote!=73 && syote!=105 && syote!=27)
                        syote=getch();
        }

        if ((syote==85||syote==117)&&boldKerrat==0&&
        underlineKerrat==1&&italicKerrat==1)
        {
                textcolor(WHITE);
                textbackground(BLUE);
                gotoxy(14,2);
                cprintf(" Bold      ");
                gotoxy(14,3);
                cprintf("xItalic    ");
                gotoxy(14,4);
                cprintf(" Underline ");
                style=2;
                underlineKerrat--;
                syote=getch();

                while (syote!=98 && syote!=66 && syote!=85 &&
                syote!=117 && syote!=73 && syote!=105 && syote!=27)
                        syote=getch();
        }

        if ((syote==73||syote==105)&&boldKerrat==0&&
        underlineKerrat==1&&italicKerrat==0)
        {
                textcolor(WHITE);
                textbackground(BLUE);
                gotoxy(14,2);
                cprintf(" Bold      ");
                gotoxy(14,3);
                cprintf("xItalic    ");
                gotoxy(14,4);
                cprintf("xUnderline ");
                style=6;
                italicKerrat++;
                syote=getch();

                while (syote!=98 && syote!=66 && syote!=85 &&
                syote!=117 && syote!=73 && syote!=105 && syote!=27)
                        syote=getch();
        }

        if ((syote==73||syote==105)&&boldKerrat==0&&
        underlineKerrat==1&&italicKerrat==1)
        {
                textcolor(WHITE);
                textbackground(BLUE);
                gotoxy(14,2);
                cprintf(" Bold      ");
                gotoxy(14,3);
                cprintf(" Italic    ");
                gotoxy(14,4);
                cprintf("xUnderline ");
                style=3;
                italicKerrat--;
                syote=getch();

                while (syote!=98 && syote!=66 && syote!=85 &&
                syote!=117 && syote!=73 && syote!=105 && syote!=27)
                        syote=getch();
        }

        if ((syote==98||syote==66)&&boldKerrat==0&&
        italicKerrat==0&&underlineKerrat==1)
        {
                textcolor(WHITE);
                textbackground(BLUE);
                gotoxy(14,2);
                cprintf("xBold      ");
                gotoxy(14,3);
                cprintf(" Italic    ");
                gotoxy(14,4);
                cprintf("xUnderline ");
                style=7;
                boldKerrat++;
                syote=getch();

                while (syote!=98 && syote!=66 && syote!=85 &&
                syote!=117 && syote!=73 && syote!=105 && syote!=27)
                        syote=getch();

        }

        if ((syote==98||syote==66)&&boldKerrat==1&&
        italicKerrat==0&&underlineKerrat==1)
        {
                textcolor(WHITE);
                textbackground(BLUE);
                gotoxy(14,2);
                cprintf(" Bold      ");
                gotoxy(14,3);
                cprintf(" Italic    ");
                gotoxy(14,4);
                cprintf("xUnderline ");
                style=3;
                boldKerrat--;
                syote=getch();

                while (syote!=98 && syote!=66 && syote!=85 &&
                syote!=117 && syote!=73 && syote!=105 && syote!=27)
                        syote=getch();

        }

        if ((syote==98||syote==66)&&boldKerrat==0&&
        italicKerrat==1&&underlineKerrat==0)
        {
                textcolor(WHITE);
                textbackground(BLUE);
                gotoxy(14,2);
                cprintf("xBold      ");
                gotoxy(14,3);
                cprintf("xItalic    ");
                gotoxy(14,4);
                cprintf(" Underline ");
                style=5;
                boldKerrat++;
                syote=getch();

                while (syote!=98 && syote!=66 && syote!=85 &&
                syote!=117 && syote!=73 && syote!=105 && syote!=27)
                        syote=getch();
        }

        if ((syote==98||syote==66)&&boldKerrat==1&&
        italicKerrat==1&&underlineKerrat==0)
        {
                textcolor(WHITE);
                textbackground(BLUE);
                gotoxy(14,2);
                cprintf(" Bold      ");
                gotoxy(14,3);
                cprintf("xItalic    ");
                gotoxy(14,4);
                cprintf(" Underline ");
                style=2;
                boldKerrat--;
                syote=getch();

                while (syote!=98 && syote!=66 && syote!=85 &&
                syote!=117 && syote!=73 && syote!=105 && syote!=27)
                        syote=getch();
        }
}
PoistaValikot();
return style;
}

void StylePaivitys(int style, char font[], char underline,
                   char bold, char italic, int size)
{
if (style==0)
{
        bold=' ';
        italic=' ';
        underline=' ';
        PiirraValikot(font, underline, bold, italic, size);
}
if (style==1)
{
        bold='B';
        italic=' ';
        underline=' ';
        PiirraValikot(font, underline, bold, italic, size);
}
if (style==2)
{
        bold=' ';
        italic='I';
        underline=' ';
        PiirraValikot(font, underline, bold, italic, size);
}
if (style==3)
{
        bold=' ';
        italic=' ';
        underline='U';
        PiirraValikot(font, underline, bold, italic, size);
}
if (style==4)
{
        bold='B';
        italic='I';
        underline='U';
        PiirraValikot(font, underline, bold, italic, size);
}
if (style==5)
{
        bold='B';
        italic='I';
        underline=' ';
        PiirraValikot(font, underline, bold, italic, size);
}
if (style==6)
{
        bold=' ';
        italic='I';
        underline='U';
        PiirraValikot(font, underline, bold, italic, size);
}
if (style==7)
{
        bold='B';
        italic=' ';
        underline='U';
        PiirraValikot(font, underline, bold, italic, size);
}

}

int SizeValikko (int size)
{
int syote;
syote=size;

if (syote==1)    //muutetaan syote aliohjelman ymm‰rt‰m‰‰n ASCII:n
        syote=49;

if (syote==2)
        syote=50;

if (syote==3)
        syote=51;

while (syote!=27)
{
        if (syote==49)
        {
                gotoxy(21,2);
                textcolor(WHITE);
                textbackground(BLUE);
                cprintf("x(1) 8  ");
                gotoxy(21,3);
                cprintf(" (2) 10 ");
                gotoxy(21,4);
                cprintf(" (3) 12 ");
                syote=getch();

                while (syote!=49 && syote!=50 && syote!=51 && syote!=27)
                        syote=getch();

                if (syote!=27)
                        size=syote;
        }
        if (syote==50)
        {
        gotoxy(21,2);
        textcolor(WHITE);
        textbackground(BLUE);
        cprintf(" (1) 8  ");
        gotoxy(21,3);
        cprintf("x(2) 10 ");
        gotoxy(21,4);
        cprintf(" (3) 12 ");
        syote=getch();

        while (syote!=49 && syote!=50 && syote!=51 && syote!=27)
                syote=getch();

        if (syote!=27)
                size=syote;
        }
        if (syote==51)
        {
        gotoxy(21,2);
        textcolor(WHITE);
        textbackground(BLUE);
        cprintf(" (1) 8  ");
        gotoxy(21,3);
        cprintf(" (2) 10 ");
        gotoxy(21,4);
        cprintf("x(3) 12 ");
        syote=getch();

        while (syote!=49 && syote!=50 && syote!=51 && syote!=27)
                syote=getch();

        if (syote!=27)
                size=syote;
        }
        if (size==49)
                size=1;
        if (size==50)
                size=2;
        if (size==51)
                size=3;
}
PoistaValikot();
return size;
}

int FileValikko(void)
{
int syote,i,x,y;
int enter=0;
gotoxy(2,2);
textcolor(WHITE);
textbackground(BLUE);
cprintf(" New      ");
gotoxy(2,3);
cprintf(" Generate ");
gotoxy(2,4);
cprintf(" Exit     ");
syote=getch();
while(syote!=78&&syote!=110&&syote!=69&&syote!=101&&syote!=27&&syote!=71&&syote!=103)
{
        syote=getch();
}

if (syote==69 || syote==101)
{
        gotoxy(15,3);
        textcolor(WHITE);
        textbackground(BLUE);
        cprintf(" Are you sure you want to exit HTML-Generator? ");
        gotoxy(15,4);
        cprintf("                                               ");
        gotoxy(15,5);
        cprintf("    Press E to exit, any other key to abort    ");
        syote=getch();
}

if (syote==78 || syote==110)
{
        gotoxy(15,3);
        textcolor(WHITE);
        textbackground(BLUE);
        cprintf(" Are you sure you want to create a new document? ");
        gotoxy(15,4);
        cprintf("     (The old document will be deleted)          ");
        gotoxy(15,5);
        cprintf("  Press N to create new, any other key to abort  ");
        syote=getch();
}
if(syote==71 || syote==103)
{
        //kirjoita.close();
        gotoxy(15,3);
        textcolor(WHITE);
        textbackground(BLUE);
        cprintf("                                         ");
        gotoxy(15,4);
        cprintf(" Give a filename:");
        textcolor(BLACK);
        textbackground(BLACK);
        cprintf("         ");
        textcolor(WHITE);
        textbackground(BLUE);
        cprintf("               ");
        gotoxy(15,5);
        cprintf("                                         ");
        textcolor(LIGHTGRAY);
        textbackground(BLACK);
        x=32;
        y=4;
        gotoxy(x,y);
        for(i=0;i<8;i++)
        {
                textcolor(LIGHTGRAY);
                textbackground(BLACK);
                gotoxy(x,y);
                tiedosto[i]=getch();
                if(tiedosto[i]==13)
                {
                        enter=tiedosto[i];
                        for(i;i<8;i++)
                        {
                                tiedosto[i]=' ';
                        }
                        break;

                }
                else if(tiedosto[i]==46||tiedosto[i]==58||tiedosto[i]==47)
                {
                        if(i>0)
                        i--;
                }
                else if(tiedosto[i]==8)
                {
                        if(i>=0)
                        {
                                if(i==0)
                                i=i-1;
                                if(i>0)
                                i=i-2;
                        }
                        if(x>27)
                        x--;
                        gotoxy(x,y);
                        textcolor(BLACK);
                        textbackground(BLACK);
                        cprintf(" ");
                }
                else
                {
                        cprintf("%c", tiedosto[i]);
                        x++;
                }
        }

        while(enter!=13)
        {
                enter=getch();
        }

}
//kirjoita.open("MyPage.txt", ios_base::in | ios_base::out | ios_base::ate);
PoistaValikot();
return syote;
}

void HelpValikko(void)
{
int syote=0;
while(syote!=27)
{
gotoxy(1,2);
textbackground(BLUE);
textcolor(WHITE);
cprintf("                    Help topics: Html-generator v1.0    ");
cprintf("                        ");
cprintf("                                                        ");
cprintf("                        ");
cprintf("      1. Using Generator Help           2. The Generator");
cprintf(" Commands               ");
cprintf("      3. Editing the text               4. Statusbar Sym");
cprintf("bols                    ");
cprintf("                     Press a number to select a topic   ");
cprintf("                        ");
gotoxy(1,7);

syote=getch();

while(syote!=49&&syote!=50&&syote!=51&&syote!=52&&
      syote!=27)
{
        syote=getch();
}
if(syote==49)
{
        gotoxy(1,2);
        textbackground(BLUE);
        textcolor(WHITE);
        cprintf("                    Using Generator Help                ");
        cprintf("                        ");
        cprintf(" You can scroll the help menu by using the letters ");
        cprintf("U (UP) and D (DOWN) on ");
        cprintf("your   keyboard. To return to the main menu from a speci");
        cprintf("fic topic press X.     ");
        cprintf("        To return from the main menu to the program press ESC. ");
        cprintf("To choose a topic press  the number beside it.");
        cprintf("                                                         ");
        syote=getch();
        while(syote!=88&&syote!=120)
        {
                syote=getch();
        }

}
if(syote==50)
{
        while(syote==50)
        {
                gotoxy(1,2);
                textbackground(BLUE);
                textcolor(WHITE);
                cprintf("                       The Generator Commands 1/2        ");
                cprintf("                       ");
                cprintf(" To access the drop down menus press CTRL+the highlighted");
                cprintf(" letter.                The key combinations are: ");
                cprintf("    - File menu:  CTRL+F       - Font menu: CTRL+O       ");
                cprintf("                           - Style menu: CTRL+T");
                cprintf("       - Size menu: CTRL+S");
                cprintf("                                  - Help menu:  CTRL+E");
                cprintf("           press (D)own      ");
                do
                        syote=getch();
                while(syote!=100&&syote!=68&&syote!=88&&syote!=120);
                if(syote==100||syote==68)
                {
                        gotoxy(1,2);
                        textbackground(BLUE);
                        textcolor(WHITE);
                        cprintf("                       The Generator Commands 2/2        ");
                        cprintf("                      ");
                        cprintf("  To choose a function in the drop down menu press the first");
                        cprintf(" letter of the func-  tion with one exception: the Size menu,");
                        cprintf(" where the functions are chosen by       pressing a number. ");
                        cprintf("                                                         ");
                        cprintf("       ");
                        cprintf("                                                 ");
                        cprintf("         press (U)p        ");
                        do
                                syote=getch();
                        while(syote!=117&&syote!=85&&syote!=88&&syote!=120);
                        if(syote==117||syote==85)
                                syote=50;
                }
        }
        while(syote!=88&&syote!=120)
        {
                syote=getch();
        }

}
if(syote==51)
{
        while(syote==51)
        {
        gotoxy(1,2);
        textbackground(BLUE);
        textcolor(WHITE);
        cprintf("                         Editing the text 1/2   ");
        cprintf("                                ");
        cprintf(" To change the style of the text go to the Style menu.");
        cprintf(" The chosen style will be  displayed on the statusbar. ");
        cprintf(" The possible styles are: normal, bold, underline   and");
        cprintf(" different combinations of these three.               ");
        cprintf("                    ");
        cprintf("                     ");
        cprintf("                       ");
        cprintf("                   press (D)own       ");
        do
                syote=getch();
        while(syote!=88&&syote!=120&&syote!=100&&syote!=68);
        if(syote==100||syote==68)
        {
                gotoxy(1,2);
                textbackground(BLUE);
                textcolor(WHITE);
                cprintf("                         Editing the text 2/2   ");
                cprintf("                                ");
                cprintf(" The different styles will be displayed as follows:");
                cprintf("                               ");
                textbackground(BLACK);
                textcolor(LIGHTGRAY);
                cprintf("Normal");
                textbackground(BLUE);
                textcolor(WHITE);
                cprintf("  ");
                textbackground(LIGHTGRAY);
                textcolor(BLACK);
                cprintf("Bold");
                textbackground(BLUE);
                textcolor(WHITE);
                cprintf("  ");
                textbackground(BLACK);
                textcolor(WHITE);
                cprintf("Italic");
                textbackground(BLUE);
                textcolor(WHITE);
                cprintf("  ");
                textbackground(BLACK);
                textcolor(BLUE);
                cprintf("Underline");
                textbackground(BLUE);
                textcolor(WHITE);
                cprintf("  ");
                textbackground(LIGHTGRAY);
                textcolor(WHITE);
                cprintf("Bold Italic");
                textbackground(BLUE);
                textcolor(WHITE);
                cprintf("  ");
                textbackground(LIGHTGRAY);
                textcolor(BLUE);
                cprintf("Bold Underline");
                textbackground(BLUE);
                textcolor(WHITE);
                cprintf("                    ");
                textbackground(BLUE);
                textcolor(WHITE);
                cprintf("Italic Underline");
                cprintf("  ");
                textbackground(LIGHTGRAY);
                textcolor(RED);
                cprintf("Bold Italic Underline");
                textbackground(BLUE);
                textcolor(WHITE);
                cprintf("                 ");
                cprintf("                                                   ");
                cprintf("                                press (U)p         ");
                do
                        syote=getch();
                while(syote!=85&&syote!=117&&syote!=88&&syote!=120);
                if(syote==85||syote==117)
                        syote=51;
        }
}
}
if (syote==52)
{
                gotoxy(1,2);
                textbackground(BLUE);
                textcolor(WHITE);
                cprintf("                                 Statusbar Symbols     ");
                cprintf("                         ");
                cprintf(" The statusbar is the last line of the window. You can ");
                cprintf("see your current font,    font style and font size there.");
                cprintf(" The different styles are displayed in the sta-  tusbar the");
                cprintf(" same way as on the workspace.                               ");
                cprintf("                                                             ");
                gotoxy(1,7);
        do
                syote=getch();
        while (syote!=88&&syote!=120);
}
PoistaValikot();
}
}

void TitleWindow ()
{
        float otsikkoSyote=0;
        int i=0;
        int x=24;
        int y=11;

        gotoxy(21,5);
        cout<<"Welcome to HTML-generator v.1.0";
        gotoxy(20,8);
        textbackground(BLUE);
        cprintf("                                 ");
        gotoxy(20,9);
        cprintf("                                 ");
        textcolor(WHITE);
        gotoxy(20,10);
        cprintf("             Title:              ");
        gotoxy(20,11);
        cprintf("    ");
        textbackground(BLACK);
        cprintf("                         ");
        textbackground(BLUE);
        cprintf("    ");
        gotoxy(20,12);
        cprintf("                                 ");
        gotoxy(20,13);
        cprintf("                                 ");
        textcolor(LIGHTGRAY);
        gotoxy(28,18);
        cout<<"Press F1 for help";

        textcolor(LIGHTGRAY);

        while(otsikkoSyote!=13&&i<24)
        {
                gotoxy(x,y);
                otsikkoSyote=getch();

                if(otsikkoSyote==59)
                {
                        OtsikkoHelppi();
                        gotoxy(24,11);
                        textcolor(LIGHTGRAY);
                        x--;
                }
                if(otsikkoSyote==8&&x>24)
                {
                        x--;
                        gotoxy(x,y);
                        cout<<" ";
                        i--;
                }
                if(otsikkoSyote!=59&&otsikkoSyote!=8)
                {
                        if(otsikkoSyote!=13)
                        title[i]=otsikkoSyote;
                        textbackground(BLACK);
                        cprintf("%c", title[i]);
                        x++;
                        i++;
                }

        }
}

void OtsikkoHelppi(void)
{
        gotoxy(10,18);
        textbackground(BLUE);
        textcolor(WHITE);
        cprintf("                                                       ");
        gotoxy(10,19);
        cprintf("   With this function you can name your Web page.      ");
        gotoxy(10,20);
        cprintf("   The maximum length of the title is 25 characters.   ");
        gotoxy(10,21);
        cprintf("   The title will be shown in the upper left corner    ");
        gotoxy(10,22);
        cprintf("   of the browser. This title will be shown in all the ");
        gotoxy(10,23);
        cprintf("   Web pages created during this session.              ");
        gotoxy(10,24);
        cprintf("                                                       ");
}

void HTMLTyyli (int style, char *bold, char *italic, char *underline, int *tekstinvari, int *taustavari)
{
if(style==0)
{
        if (*bold=='B')
        kirjoita<<"        </b>";
        if (*italic=='I')
        kirjoita<<"        </i>";
        if (*underline=='U')
        kirjoita<<"        </u>";

        *bold=' ';*italic=' ';*underline=' ';
        *taustavari=0;
        *tekstinvari=7;
}

if(style==1)
{
        if(*bold==' '&&*underline==' '&&*italic==' ')
        kirjoita<<"         <b>";
        if(*italic=='I'&&*underline==' ')
        kirjoita<<"     </i><b>";
        if(*bold==' '&&*underline=='U')
        kirjoita<<"     </u><b>";
        if(*italic=='I'&&*underline=='U')
        kirjoita<<" </u></i><b>";

        *bold='B';*italic=' ';*underline=' ';
        *taustavari=7;
        *tekstinvari=0;
}

if(style==2)
{
        if(*bold==' '&&*underline==' '&&*italic==' ')
        kirjoita<<"         <i>";
        if(*bold=='B'&&*underline==' ')
        kirjoita<<"     </b><i>";
        if(*bold==' '&&*underline=='U')
        kirjoita<<"     </u><i>";
        if(*bold=='B'&&*underline=='U')
        kirjoita<<" </u></b><i>";

        *bold=' ';*italic='I';*underline=' ';
        *taustavari=0;
        *tekstinvari=15;
}

if(style==3)
{
        if(*bold==' '&&*underline==' '&&*italic==' ')
        kirjoita<<"         <u>";
        if(*bold=='B'&&*italic==' ')
        kirjoita<<"     </b><u>";
        if(*bold==' '&&*italic=='I')
        kirjoita<<"     </i><u>";
        if(*bold=='B'&&*italic=='I')
        kirjoita<<" </b></i><u>";

        *bold=' ';*italic=' ';*underline='U';
        *taustavari=0;
        *tekstinvari=1;
}

if(style==4)
{
        if(*bold==' '&&*italic==' '&&*underline==' ')
        kirjoita<<"   <b><u><i>";
        if(*bold=='B'&&*italic==' '&&*underline==' ')
        kirjoita<<"      <u><i>";
        if(*bold==' '&&*italic=='I'&&*underline==' ')
        kirjoita<<"      <u><b>";
        if(*bold==' '&&*italic==' '&&*underline=='U')
        kirjoita<<"      <i><b>";
        if(*bold=='B'&&*italic=='I'&&*underline==' ')
        kirjoita<<"         <u>";
        if(*bold=='B'&&*italic==' '&&*underline=='U')
        kirjoita<<"         <i>";
        if(*bold==' '&&*italic=='I'&&*underline=='U')
        kirjoita<<"         <b>";

        *bold='B';*italic='I';*underline='U';
        *taustavari=7;
        *tekstinvari=4;
}

if(style==5)
{
        if(*bold==' '&&*italic==' '&&*underline==' ')
        kirjoita<<"      <b><i>";
        if(*bold=='B'&&*italic==' '&&*underline==' ')
        kirjoita<<"         <i>";
        if(*bold==' '&&*italic=='I'&&*underline==' ')
        kirjoita<<"         <b>";
        if(*bold==' '&&*italic==' '&&*underline=='U')
        kirjoita<<"  </u><b><i>";
        if(*bold=='B'&&*italic==' '&&*underline=='U')
        kirjoita<<"     </u><i>";
        if(*bold==' '&&*italic=='I'&&*underline=='U')
        kirjoita<<"     </u><b>";

        *bold='B';*italic='I';*underline=' ';
        *taustavari=7;
        *tekstinvari=15;
}

if(style==6)
{
        if(*underline==' '&&*italic==' '&&*bold==' ')
        kirjoita<<"      <u><i>";
        if(*underline=='U'&&*italic==' '&&*bold==' ')
        kirjoita<<"         <i>";
        if(*underline==' '&&*italic=='I'&&*bold==' ')
        kirjoita<<"         <u>";
        if(*underline==' '&&*italic==' '&&*bold=='B')
        kirjoita<<"  </b><u><i>";
        if(*underline=='U'&&*italic==' '&&*bold=='B')
        kirjoita<<"     </b><i>";
        if(*underline==' '&&*italic=='I'&&*bold=='B')
        kirjoita<<"     </b><u>";

        *bold=' ';*italic='I';*underline='U';
        *taustavari=1;
        *tekstinvari=15;
}

if(style==7)
{
        if(*underline==' '&&*bold==' '&&*italic==' ')
        kirjoita<<"      <u><b>";
        if(*underline=='U'&&*bold==' '&&*italic==' ')
        kirjoita<<"         <b>";
        if(*underline==' '&&*bold=='B'&&*italic==' ')
        kirjoita<<"         <u>";
        if(*underline==' '&&*bold==' '&&*italic=='I')
        kirjoita<<"  </i><u><b>";
        if(*underline=='U'&&*bold==' '&&*italic=='I')
        kirjoita<<"     </i><b>";
        if(*underline==' '&&*bold=='B'&&*italic=='I')
        kirjoita<<"     </i><u>";

        *bold='B';*italic=' ';*underline='U';
        *taustavari=7;
        *tekstinvari=1;
}
}

void FontStatus (int fontti, char *font, char underline, char bold, char italic, int size)
{
if (fontti==104) //P‰ivitet‰‰n statusbar Helveticaksi
{
        font="Helvetica      ";
        PiirraValikot(font, underline, bold, italic, size);

}

if (fontti==97) //P‰ivitet‰‰n statusbar Arialiksi
{
        font="Arial          ";
        PiirraValikot(font, underline, bold, italic, size);
}

if (fontti==116) //P‰ivitet‰‰n statusbar TimesNewRoman
{
        font="Times New Roman";
        PiirraValikot(font, underline, bold, italic, size);
}

kirjoita<<"<font face=\""<<font<<"\" size=\""<<size<<"\">";

}

void TyhjennaTiedosto(void)
{
        kirjoita.close();
        kirjoita.open("MyPage.txt", ios_base::out | ios_base::trunc);
}

void AlustaHTML (int size,char title[],char font[])
{
        kirjoita<<"<!-- This page is created with Html-Generator v1.0 -->";
        kirjoita<<"<!doctype html public \"-//w3c//dtd html 3.2//en\">";
        kirjoita<<"<html>";
        kirjoita<<"<head>";
        kirjoita<<"<title>"<<title<<"</title>";
        kirjoita<<"</head>";
        kirjoita<<"<body>";
        kirjoita<<"<font face=\""<<font<<"\" size=\""<<size<<"\">";
}

void LuoTiedosto(char bold, char italic, char underline)
{
        char testiNimi[12]={' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '};
        char merkki;
        int i=0,k=0,merkkiLaskuri=0,merkkiLaskuri2=0;
        kirjoita.close();
        while(tiedosto[i]!=' ')
        {
                testiNimi[i]=tiedosto[i];
                i++;
        }

        i=i+4;

        if (i==5)
        {
                char tiedostoNimi[5]={' ',' ',' ',' ',' '};
                while(testiNimi[k]!=' ')
                {
                        tiedostoNimi[k]=testiNimi[k];
                        k++;
                }
                tiedostoNimi[k]='.';
                tiedostoNimi[k+1]='h';
                tiedostoNimi[k+2]='t';
                tiedostoNimi[k+3]='m';

                ofstream kirjoitaTiedostoon(tiedostoNimi);
                ifstream lueTiedostosta("MyPage.txt");
                while(lueTiedostosta.peek()!=EOF)
                {
                        lueTiedostosta.get(merkki);
                        kirjoitaTiedostoon<<merkki;
                }
                if(bold=='B')
                {
                        kirjoitaTiedostoon<<"</b>";
                }

                if(italic=='I')
                {
                        kirjoitaTiedostoon<<"</i>";
                }

                if(underline=='U')
                {
                        kirjoitaTiedostoon<<"</u>";
                }

                kirjoitaTiedostoon<<"\n</body>";
                kirjoitaTiedostoon<<"\n</html>";
                kirjoitaTiedostoon.close();

        }
        if (i==6)
        {
                char tiedostoNimi[6]={' ',' ',' ',' ',' ',' '};
                while(testiNimi[k]!=' ')
                {
                        tiedostoNimi[k]=testiNimi[k];
                        k++;
                }
                tiedostoNimi[k]='.';
                tiedostoNimi[k+1]='h';
                tiedostoNimi[k+2]='t';
                tiedostoNimi[k+3]='m';

                ofstream kirjoitaTiedostoon(tiedostoNimi);
                ifstream lueTiedostosta("MyPage.txt");
                while(lueTiedostosta.peek()!=EOF)
                {
                        lueTiedostosta.get(merkki);
                        kirjoitaTiedostoon<<merkki;
                }
                if(bold=='B')
                {
                        kirjoitaTiedostoon<<"</b>";
                }

                if(italic=='I')
                {
                        kirjoitaTiedostoon<<"</i>";
                }

                if(underline=='U')
                {
                        kirjoitaTiedostoon<<"</u>";
                }

                kirjoitaTiedostoon<<"\n</body>";
                kirjoitaTiedostoon<<"\n</html>";
                kirjoitaTiedostoon.close();

        }
        if (i==7)
        {
                char tiedostoNimi[7]={' ',' ',' ',' ',' ',' ',' '};
                while(testiNimi[k]!=' ')
                {
                        tiedostoNimi[k]=testiNimi[k];
                        k++;
                }
                tiedostoNimi[k]='.';
                tiedostoNimi[k+1]='h';
                tiedostoNimi[k+2]='t';
                tiedostoNimi[k+3]='m';

                ofstream kirjoitaTiedostoon(tiedostoNimi);
                ifstream lueTiedostosta("MyPage.txt");
                while(lueTiedostosta.peek()!=EOF)
                {
                        lueTiedostosta.get(merkki);
                        kirjoitaTiedostoon<<merkki;
                }
                if(bold=='B')
                {
                        kirjoitaTiedostoon<<"</b>";
                }

                if(italic=='I')
                {
                        kirjoitaTiedostoon<<"</i>";
                }

                if(underline=='U')
                {
                        kirjoitaTiedostoon<<"</u>";
                }

                kirjoitaTiedostoon<<"\n</body>";
                kirjoitaTiedostoon<<"\n</html>";
                kirjoitaTiedostoon.close();

        }
        if (i==8)
        {
                char tiedostoNimi[8]={' ',' ',' ',' ',' ',' ',' ',' '};
                while(testiNimi[k]!=' ')
                {
                        tiedostoNimi[k]=testiNimi[k];
                        k++;
                }
                tiedostoNimi[k]='.';
                tiedostoNimi[k+1]='h';
                tiedostoNimi[k+2]='t';
                tiedostoNimi[k+3]='m';

                ofstream kirjoitaTiedostoon(tiedostoNimi);
                ifstream lueTiedostosta("MyPage.txt");
                while(lueTiedostosta.peek()!=EOF)
                {
                        lueTiedostosta.get(merkki);
                        kirjoitaTiedostoon<<merkki;
                }
                if(bold=='B')
                {
                        kirjoitaTiedostoon<<"</b>";
                }

                if(italic=='I')
                {
                        kirjoitaTiedostoon<<"</i>";
                }

                if(underline=='U')
                {
                        kirjoitaTiedostoon<<"</u>";
                }

                kirjoitaTiedostoon<<"\n</body>";
                kirjoitaTiedostoon<<"\n</html>";
                kirjoitaTiedostoon.close();

        }
        if (i==9)
        {
                char tiedostoNimi[9]={' ',' ',' ',' ',' ',' ',' ',' ',' '};
                while(testiNimi[k]!=' ')
                {
                        tiedostoNimi[k]=testiNimi[k];
                        k++;
                }
                tiedostoNimi[k]='.';
                tiedostoNimi[k+1]='h';
                tiedostoNimi[k+2]='t';
                tiedostoNimi[k+3]='m';

                ofstream kirjoitaTiedostoon(tiedostoNimi);
                ifstream lueTiedostosta("MyPage.txt");
                while(lueTiedostosta.peek()!=EOF)
                {
                        lueTiedostosta.get(merkki);
                        kirjoitaTiedostoon<<merkki;
                }
                if(bold=='B')
                {
                        kirjoitaTiedostoon<<"</b>";
                }

                if(italic=='I')
                {
                        kirjoitaTiedostoon<<"</i>";
                }

                if(underline=='U')
                {
                        kirjoitaTiedostoon<<"</u>";
                }

                kirjoitaTiedostoon<<"\n</body>";
                kirjoitaTiedostoon<<"\n</html>";
                kirjoitaTiedostoon.close();

        }
        if (i==10)
        {
                char tiedostoNimi[10]={' ',' ',' ',' ',' ',' ',' ',' ',' ',' '};
                while(testiNimi[k]!=' ')
                {
                        tiedostoNimi[k]=testiNimi[k];
                        k++;
                }
                tiedostoNimi[k]='.';
                tiedostoNimi[k+1]='h';
                tiedostoNimi[k+2]='t';
                tiedostoNimi[k+3]='m';

                ofstream kirjoitaTiedostoon(tiedostoNimi);
                ifstream lueTiedostosta("MyPage.txt");
                while(lueTiedostosta.peek()!=EOF)
                {
                        lueTiedostosta.get(merkki);
                        kirjoitaTiedostoon<<merkki;
                }
                if(bold=='B')
                {
                        kirjoitaTiedostoon<<"</b>";
                }

                if(italic=='I')
                {
                        kirjoitaTiedostoon<<"</i>";
                }

                if(underline=='U')
                {
                        kirjoitaTiedostoon<<"</u>";
                }

                kirjoitaTiedostoon<<"\n</body>";
                kirjoitaTiedostoon<<"\n</html>";
                kirjoitaTiedostoon.close();

        }
        if (i==11)
        {
                char tiedostoNimi[11]={' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '};
                while(testiNimi[k]!=' ')
                {
                        tiedostoNimi[k]=testiNimi[k];
                        k++;
                }
                tiedostoNimi[k]='.';
                tiedostoNimi[k+1]='h';
                tiedostoNimi[k+2]='t';
                tiedostoNimi[k+3]='m';

                ofstream kirjoitaTiedostoon(tiedostoNimi);
                ifstream lueTiedostosta("MyPage.txt");
                while(lueTiedostosta.peek()!=EOF)
                {
                        lueTiedostosta.get(merkki);
                        kirjoitaTiedostoon<<merkki;
                }
                if(bold=='B')
                {
                        kirjoitaTiedostoon<<"</b>";
                }

                if(italic=='I')
                {
                        kirjoitaTiedostoon<<"</i>";
                }

                if(underline=='U')
                {
                        kirjoitaTiedostoon<<"</u>";
                }

                kirjoitaTiedostoon<<"\n</body>";
                kirjoitaTiedostoon<<"\n</html>";
                kirjoitaTiedostoon.close();

        }
        if (i==12)
        {
                char tiedostoNimi[12]={' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '};
                while(testiNimi[k]!=' ')
                {
                        tiedostoNimi[k]=testiNimi[k];
                        k++;
                }
                tiedostoNimi[k]='.';
                tiedostoNimi[k+1]='h';
                tiedostoNimi[k+2]='t';
                tiedostoNimi[k+3]='m';

                ofstream kirjoitaTiedostoon(tiedostoNimi);
                ifstream lueTiedostosta("MyPage.txt");
                while(lueTiedostosta.peek()!=EOF)
                {
                        lueTiedostosta.get(merkki);
                        kirjoitaTiedostoon<<merkki;
                }
                if(bold=='B')
                {
                        kirjoitaTiedostoon<<"</b>";
                }

                if(italic=='I')
                {
                        kirjoitaTiedostoon<<"</i>";
                }

                if(underline=='U')
                {
                        kirjoitaTiedostoon<<"</u>";
                }

                kirjoitaTiedostoon<<"\n</body>";
                kirjoitaTiedostoon<<"\n</html>";
                kirjoitaTiedostoon.close();
        }
        kirjoita.open("MyPage.txt");
        while(kirjoita.peek()!=EOF)
        {
                kirjoita.get(merkki);
                merkkiLaskuri2++;
                if(merkki==' ')
                merkkiLaskuri++;
                else
                merkkiLaskuri=0;
        }
        kirjoita.seekg(0);
        kirjoita.seekg(((merkkiLaskuri2)-merkkiLaskuri),ios_base::cur);
}

int WorkSpaceFull(void)
{
        gotoxy(49,25);
        textbackground(BLACK);
        textcolor(WHITE);
        cprintf("Workspace full! Press backspace");
        return (getch());
}
