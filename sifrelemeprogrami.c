#include <stdio.h>
#include <string.h>
 
#define limit 1000
#define limitparola 100
void sifrele(char[], char[]);
void sifreCoz(char[], char[]);
int say(char[], char);
 
char metin[limit];
int karakterBoyutu;
int secA,secB;
char sifre[limitparola];
// Yukar�da de�i�kenleri tan�mlad�m. ayr�ca char degiskenleri i�in karakter limiti ekledim
int main() {
	
  char karakter[] = "abc�defg�h�ijklmno�prs�tu�vyz0123456789ABC�DEFG�HI�JKLMNO�PRS�TU�VYZ.,!'^+-/*%&()=?#${[]}~<>| ";
  //karakterler tan�mlad�m
    karakterBoyutu = strlen(karakter);
 printf("-------------------------------------\n");
  printf("Yapacaginiz islemi secin:\n");
   printf("[1]-Sifreleme yap \n");
   printf("[2]-Desifre yap \n");
   printf("[3]-Kapat \n");
    printf("-------------------------------------\n");
     scanf("%d",&secA);
	 
	 //Program�n men� k�sm� hangi i�lemin yap�laca��n� se�iyorum. se�ilen de�er if ile kol�ulu sa�l�yorsa o i�lemi ger�ekle�tiriyorum
     if(secA<=1){
	      getchar();
          printf("Sifrelenecek metini girin\n");
         
		  gets(metin);
		  printf("Parola girin\n");
   		  
   		  gets(sifre);
          printf("-------------------------------------\n");
          printf("------ Sifrelenecek Metin -----------\n");
 	   	 
  		  printf("[+]%s\n", metin);
 	      printf("------------- Parola ----------------\n");
          printf("[+]%s\n",sifre);
          printf("-------------------------------------\n");;
          sifrele(karakter, sifre);
          printf("--------- Sifrelendi... --------------\n");
          printf("Sifreli Hali:\n[+]%s\n", metin);
      }
      // e�er secilen de�er 1 ise yani �ifrele ise
      // �nce metin ve parola giri�i istiecek daha sonra sifrele(karakter, sifre); i�lemi ile alttaki fonksiyonu �a��r�p
      // �ifreleme i�lemini ger�ekle�tirecektir.
	  else if(secA==2){
	   	  getchar();
	      printf("Sifreli metini girin\n");
          gets(metin);
          printf("Parola girin\n");
          gets(sifre);
          printf("-------------------------------------\n");
          printf("------ Sifre Cozuluyor -----------\n");
           printf("-------------------------------------\n");
        sifreCoz(karakter, sifre);
        printf("Sifre Cozulmus hali:\n[+]%s\n", metin);
          printf("-------------------------------------\n");
          
      }
      //e�er 2 se�ilirse  �ncelikli �ifreli metin ve parola giri�i ister daha sonra �ifre ��zme fonksiyonu �a��r�larak �ifre ��z�l�r
     else{
        printf("Program Sonlandi ");
       
	  }
	  // program sonu   
  system("pause");  
  return 0;
}
 

void sifrele(char karakter[], char sifre[]) {
    int i, j = 0, metinHarfSirasi, parolaHarfSirasi;
    int metinBoyut = strlen(metin);
    int sifreBoyut = strlen(sifre);
    // metinboyutu ve �ifre boyutunu hesaplatt�r�yorum.
    for (i = 0; i < metinBoyut; i++, j++) {
        if (j >= sifreBoyut)
            j = 0;
 
        metinHarfSirasi = say(karakter, metin[i]);
        parolaHarfSirasi = say(karakter, sifre[j]);
 
        if (metinHarfSirasi != -1 && parolaHarfSirasi != -1) {
 
            metinHarfSirasi = (metinHarfSirasi + parolaHarfSirasi) % karakterBoyutu;
            metin[i] = karakter[metinHarfSirasi];
        }
    }
    // girilen metin boyutuna ba�l� olarak parola tekrarlan�yor. 
 	//daha sonra bu tekrarlanan de�erler toplan�yor ve �ifreli olarak ��k�yor. yani burada �ifrelemenin yap�ld��� ana fonksiyon yer al�r.
}
void sifreCoz(char karakter[], char sifre[]) {
    int i, j = 0, metinHarfSirasi, parolaHarfSirasi;
    int metinBoyut = strlen(metin);
    int sifreBoyut = strlen(sifre);
    // ayn� �ekilde �ifre ve metin boyutu hesaplan�r
    for (i = 0; i < metinBoyut; i++, j++) {
        if (j >= sifreBoyut)
            j = 0;
 
        metinHarfSirasi = say(karakter, metin[i]);
        parolaHarfSirasi = say(karakter, sifre[j]);
 
        if (metinHarfSirasi != -1 && parolaHarfSirasi != -1) {
            metinHarfSirasi = (metinHarfSirasi - parolaHarfSirasi) % karakterBoyutu;
 
            if (metinHarfSirasi < 0)
                metinHarfSirasi += karakterBoyutu;
 
            metin[i] = karakter[metinHarfSirasi];
        }
    }
    // �ifreleme i�teminin tam tersi ger�ekle�tirilir metin de�erlerinden parola de�erleri ��kart�larak �ifre ��z�l�r.
}
 
int say(char karakter[], char arananHarf) {
 
    int i, sayac = -1;
 
    for (i = 0; i < karakterBoyutu; i++) {
        if (arananHarf == karakter[i])
            sayac = i;
    }
    return sayac;
    // burada ise girilen karakter bulunup kancinci sirada oldu�u hesaplan�r. yani karakter de�erleri bulunur.
}
