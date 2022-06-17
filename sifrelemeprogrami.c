#include <stdio.h>
#include <string.h>
 
#define limit 1000
#define limitparola 100
void sifrele(char[], char[]);
int say(char[], char);
 
char metin[limit];
int karakterBoyutu;
int secA,secB;
char sifre[limitparola];
int main() {
	
  char karakter[] = "abcçdefgðhýijklmnoöprsþtuüvyz0123456789ABCÇDEFGÐHIÝJKLMNOÖPRSÞTUÜVYZ.,!'^+-/*%&()=?#${[]}~<>| ";
    karakterBoyutu = strlen(karakter);
 printf("-------------------------------------\n");
  printf("Yapacaginiz islemi secin:\n");
   printf("[1]-Sifreleme yap \n");
   printf("[2]-Kapat \n");
    printf("-------------------------------------\n");
     scanf("%d",&secA);
	 
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
	  
     else{
        printf("Program Sonlandi ");
       
	  }
     
     
  system("pause");  
  return 0;
}
 

void sifrele(char karakter[], char sifre[]) {
    int i, j = 0, metinHarfSirasi, parolaHarfSirasi;
    int metinBoyut = strlen(metin);
    int sifreBoyut = strlen(sifre);
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
}
 

 
int say(char karakter[], char arananHarf) {
 
    int i, sayac = -1;
 
    for (i = 0; i < karakterBoyutu; i++) {
        if (arananHarf == karakter[i])
            sayac = i;
    }
    return sayac;
}
