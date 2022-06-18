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
// Yukarýda deðiþkenleri tanýmladým. ayrýca char degiskenleri için karakter limiti ekledim
int main() {
	
  char karakter[] = "abcçdefgðhýijklmnoöprsþtuüvyz0123456789ABCÇDEFGÐHIÝJKLMNOÖPRSÞTUÜVYZ.,!'^+-/*%&()=?#${[]}~<>| ";
  //karakterler tanýmladým
    karakterBoyutu = strlen(karakter);
 printf("-------------------------------------\n");
  printf("Yapacaginiz islemi secin:\n");
   printf("[1]-Sifreleme yap \n");
   printf("[2]-Desifre yap \n");
   printf("[3]-Kapat \n");
    printf("-------------------------------------\n");
     scanf("%d",&secA);
	 
	 //Programýn menü kýsmý hangi iþlemin yapýlacaðýný seçiyorum. seçilen deðer if ile kolþulu saðlýyorsa o iþlemi gerçekleþtiriyorum
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
      // eðer secilen deðer 1 ise yani þifrele ise
      // önce metin ve parola giriþi istiecek daha sonra sifrele(karakter, sifre); iþlemi ile alttaki fonksiyonu çaðýrýp
      // þifreleme iþlemini gerçekleþtirecektir.
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
      //eðer 2 seçilirse  öncelikli þifreli metin ve parola giriþi ister daha sonra þifre çözme fonksiyonu çaðýrýlarak þifre çözülür
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
    // metinboyutu ve þifre boyutunu hesaplattýrýyorum.
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
    // girilen metin boyutuna baðlý olarak parola tekrarlanýyor. 
 	//daha sonra bu tekrarlanan deðerler toplanýyor ve þifreli olarak çýkýyor. yani burada þifrelemenin yapýldýðý ana fonksiyon yer alýr.
}
void sifreCoz(char karakter[], char sifre[]) {
    int i, j = 0, metinHarfSirasi, parolaHarfSirasi;
    int metinBoyut = strlen(metin);
    int sifreBoyut = strlen(sifre);
    // ayný þekilde þifre ve metin boyutu hesaplanýr
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
    // þifreleme iþteminin tam tersi gerçekleþtirilir metin deðerlerinden parola deðerleri çýkartýlarak þifre çözülür.
}
 
int say(char karakter[], char arananHarf) {
 
    int i, sayac = -1;
 
    for (i = 0; i < karakterBoyutu; i++) {
        if (arananHarf == karakter[i])
            sayac = i;
    }
    return sayac;
    // burada ise girilen karakter bulunup kancinci sirada olduðu hesaplanýr. yani karakter deðerleri bulunur.
}
