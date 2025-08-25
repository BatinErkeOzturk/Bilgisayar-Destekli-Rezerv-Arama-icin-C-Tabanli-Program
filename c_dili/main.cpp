#include <stdio.h>
#include <curl/curl.h>
#include <string.h>
#include <stdlib.h>
#include <graphics.h>

// 220201031 BATIN ERKE OZTURK VE MEHMET ALI DEMIR 220201092 //

char veri[1000];

int getPixelColor(int x, int y) {
    return getpixel(x, y);
}

size_t VeriAlmaCallback(void *icerik, size_t boyut, size_t nmemb, void *kullanici) {
    size_t gercek_boyut = boyut * nmemb;
    strcat(veri, (char*)icerik);
    return gercek_boyut;
}

int main() {
    CURL *curl;
    CURLcode sonuc;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, "http://bilgisayar.kocaeli.edu.tr/prolab1/prolab1.txt");
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, VeriAlmaCallback);
        sonuc = curl_easy_perform(curl);

        if (sonuc == CURLE_OK) {
            printf("Veri : \n%s \n", veri);
            char* satirlar[20];
            char* belirteci;
            int satir_sayisi = 0;

            belirteci = strtok(veri, "\n");

            while (belirteci != NULL && satir_sayisi <=20) {
                satirlar[satir_sayisi] = belirteci;
                satir_sayisi++;
                belirteci = strtok(NULL, "\n");
            }

            int secilen_satir;
            float sondaj_maliyeti,platform_maliyeti;
            
            printf("Hangi satiri cizdirmek istersin? (1-20): ");
            scanf("%d", &secilen_satir);
            
            fflush(stdin);
            
            printf("Birim sondaj maliyetini giriniz : ");
            scanf("%f", &sondaj_maliyeti);
            
            fflush(stdin);
            
            printf("Birim platform maliyetini giriniz : ");
            scanf("%f", &platform_maliyeti);
            
            if(sondaj_maliyeti>10 || sondaj_maliyeti<1){
            	printf("\nYanlis sondaj maliyeti girdiniz !\n");
            	return 0;
			}
			
			if(platform_maliyeti<0){
				printf("\nYanlis platform maliyeti girdiniz !\n");
            	return 0;
			}

            if (secilen_satir<satir_sayisi+1) {
                char* satir = satirlar[secilen_satir - 1];
                printf("%d.Satir: %s\n", secilen_satir, satir);

                int x_koordinatlar[100]; 
                int y_koordinatlar[100]; 
                int koordinat_sayisi = 0;
                
                char* parantez = strchr(satir, '(');
                while (parantez != NULL) {
                    char* kapanis_parantez = strchr(parantez, ')');
                    if (kapanis_parantez != NULL) {
                        parantez++; 
                        *kapanis_parantez = '\0';

                        int x, y;
                        sscanf(parantez, "%d, %d", &x, &y);
                        x_koordinatlar[koordinat_sayisi] = x*10;
                        y_koordinatlar[koordinat_sayisi] = y*10;
                        koordinat_sayisi++;

                        parantez = strchr(kapanis_parantez + 1, '(');
                    } else {
                        break;
                    }
                }
                
                int koordinatsayisi=0;
                koordinatsayisi=koordinat_sayisi;
    
                printf("Koordinatlar:\n");
                for (int i = 0; i < koordinat_sayisi; i++) {
                    printf("X: %d, Y: %d\n", x_koordinatlar[i]/10, y_koordinatlar[i]/10);
                }
                
                int dizibir[30],diziiki[30],diziuc[30];
                int sayacbir=2,sayaciki=2,sayacuc=2;
                float toplamsondajmaliyeti=0,toplamplatformmaliyeti=0,toplammaliyet=0,karzarardurumu=0;
                int platformsayisi=0,kirmiziplatformsayisi=0,alansayac=0,toplamplatform=0;
                int birliksayisi=0,ikiliksayisi=0,dortluksayisi=0,sekizliksayisi=0,onaltiliksayisi=0;

                dizibir[0] = x_koordinatlar[0];
                dizibir[1] = y_koordinatlar[0];

                int i = 2, k = 2 , n = 2, j = 1;
                for (; j < koordinat_sayisi; j++) {
                    dizibir[i] =x_koordinatlar[j];
                    dizibir[i + 1] =y_koordinatlar[j];
                    i += 2;
                    koordinatsayisi=koordinatsayisi-1;
                    sayacbir=sayacbir+2;

                    if (dizibir[0] == x_koordinatlar[j] && dizibir[1] == y_koordinatlar[j] && j != 1)
                        break;
                }
                
                if(sayacbir>3){
				
                printf("1. Sekil Koordinatlari : ");
                for (int e = 0; e < sayacbir; e++) {
                    printf("%d ", dizibir[e]/10);
                }
            }
                printf("\n");
                
                if(koordinatsayisi>1){
				
                diziiki[0] = x_koordinatlar[j + 1];
                diziiki[1] = y_koordinatlar[j + 1];
                for (; j < koordinat_sayisi; j++) {
                    diziiki[k] = x_koordinatlar[j + 2];
                    diziiki[k + 1] = y_koordinatlar[j + 2];
                    k += 2;
                    koordinatsayisi=koordinatsayisi-1;
                    sayaciki=sayaciki+2;

                    if (diziiki[0] == x_koordinatlar[j + 2] && diziiki[1] == y_koordinatlar[j + 2])
                        break;
                }      
          }
                if(sayaciki>3){
                printf("2. Sekil Koordinatlari : ");
                for (int e = 0; e < sayaciki; e++) {
                    printf(" %d ", diziiki[e]/10);
                }
         }
                if(koordinatsayisi>1){
			
                diziuc[0] = x_koordinatlar[j + 3];
                diziuc[1] = y_koordinatlar[j + 3];
                for (; j < koordinat_sayisi; j++) {
                    diziuc[n] = x_koordinatlar[j + 4];
                    diziuc[n + 1] = y_koordinatlar[j + 4];
                    n += 2;
                    koordinatsayisi=koordinatsayisi-1;
                    sayacuc+2;

                    if (diziuc[0] == x_koordinatlar[j + 4] && diziuc[1] == y_koordinatlar[j + 4])
                        break;
                }
          }
              if(sayacuc>3){
              	printf("3. Sekil Koordinatlari : ");
                for (int e = 0; e < sayacuc; e++) {
                    printf(" %d ", diziuc[e]/10);
                 }
            }
            
            
            
            initwindow(750,750, "Window Text", 0, 0);
            
               int kareBoyutu = 10;

               for (int w = 0; w < 750; w += kareBoyutu) {
               for (int q = 0; q < 750; q += kareBoyutu) {
               setcolor(WHITE);
               rectangle(w, q, w + kareBoyutu, q + kareBoyutu);
    }
}
               setfillstyle(1,YELLOW);
               setcolor(GREEN); 
               fillpoly((sayacbir/2),dizibir);
                                                              
               fillpoly(sayaciki/2,diziiki);
             	                            
               fillpoly(sayacuc/2,diziuc);
               
               getch();
               
                 for(int birx=0;birx<=750;birx++){
            for(int biry=0;biry<=750;biry++){
            if(getpixel(birx,biry) == YELLOW) {
           	int kosebirx = birx - (birx % 10);
            int kosebiry = biry - (biry % 10); 
            int birickare[10] = {kosebirx,kosebiry,kosebirx,kosebiry+10,kosebirx+10,
			kosebiry+10,kosebirx+10,kosebiry,kosebirx,kosebiry}; 
        setcolor(6);
        setfillstyle(1,12);
        fillpoly(4,birickare);
        alansayac++;
            }
        }
    }
    
               printf("\nTOPLAM ALAN : %d BirimKare\n",alansayac);
               
               float rezerv_degeri;
               rezerv_degeri=(alansayac*10);
               printf("Rezerv Degeri : %2.f \n",rezerv_degeri);
               
               getch();
    
                for(int ikiy=0;ikiy<=750;ikiy+=20){
                 for(int ikix=0;ikix<=750;ikix+=20){
                  if( (getpixel(ikix+1,ikiy+1) == 12) && (getpixel(ikix+19,ikiy+1) == 12) 
				  && (getpixel(ikix+1,ikiy+19) == 12) && (getpixel(ikix+19,ikiy+19) == 12) ) {
				  	
				   int koseikix = ikix;
           	       int koseikiy = ikiy;
                   int ikikare[10] = {koseikix,koseikiy,koseikix,koseikiy+20,
				   koseikix+20,koseikiy+20,koseikix+20,koseikiy,koseikix,koseikiy}; 
                    setcolor(CYAN);
                    setfillstyle(1,GREEN);
                    fillpoly(4,ikikare);
                    platformsayisi=platformsayisi+1;
                    ikiliksayisi=ikiliksayisi+1;
            }
        }
    } 
                   for(int ikiy=0;ikiy<=750;ikiy+=10){
                     for(int ikix=0;ikix<=750;ikix+=10){
                        if( (getpixel(ikix+1,ikiy+1) == 12) && (getpixel(ikix+19,ikiy+1) == 12) 
				        && (getpixel(ikix+1,ikiy+19) == 12) && (getpixel(ikix+19,ikiy+19) == 12) ) {
				  	
				           int koseikix = ikix;
           	               int koseikiy = ikiy;
                           int ikikare[10] = {koseikix,koseikiy,koseikix,koseikiy+20,
						   koseikix+20,koseikiy+20,koseikix+20,koseikiy,koseikix,koseikiy}; 
                           setcolor(CYAN);
                           setfillstyle(1,GREEN);
                           fillpoly(4,ikikare);
                           platformsayisi=platformsayisi+1;
                           ikiliksayisi=ikiliksayisi+1;
            }
        }
    } 
				  
    
                   for(int dorty=0;dorty<=750;dorty+=40){
                     for(int dortx=0;dortx<=750;dortx+=40){
                       if( (getpixel(dortx+1,dorty+1) == GREEN) && (getpixel(dortx+39,dorty+1) == GREEN) 
				       && (getpixel(dortx+1,dorty+39) == GREEN) && (getpixel(dortx+39,dorty+39) == GREEN) 
				       && (getpixel(dortx+1,dorty-1) != 12) && (getpixel(dortx+11,dorty-1) != 12) 
				       && (getpixel(dortx+21,dorty-1) != 12) && (getpixel(dortx+31,dorty-1) != 12) 
			           && (getpixel(dortx+41,dorty+1) != 12) && (getpixel(dortx+41,dorty+11) != 12)
				       && (getpixel(dortx+41,dorty+21) != 12) && (getpixel(dortx+41,dorty+31) != 12)
				       && (getpixel(dortx+39,dorty+41) != 12) && (getpixel(dortx+29,dorty+41) != 12)
				       && (getpixel(dortx+19,dorty+41) != 12) && (getpixel(dortx+9,dorty+41) != 12)
				       && (getpixel(dortx-1,dorty+39) != 12) && (getpixel(dortx+-1,dorty+29) != 12)
			           && (getpixel(dortx-1,dorty+19) != 12) && (getpixel(dortx-1,dorty+9) != 12) ){
				  
				          int kosedortx = dortx;	
                          int kosedorty = dorty;
                          int dortkare[10] = {kosedortx,kosedorty,kosedortx,kosedorty+40,
						  kosedortx+40,kosedorty+40,kosedortx+40,kosedorty,kosedortx,kosedorty}; 
                          setcolor(BROWN);
                          setfillstyle(1,MAGENTA);
                          fillpoly(4,dortkare);
                          platformsayisi=platformsayisi+1;
                          dortluksayisi=dortluksayisi+1;
            }
        }
    } 
    
                for(int dorty=0;dorty<=750;dorty+=20){
                     for(int dortx=0;dortx<=750;dortx+=20){
                       if( (getpixel(dortx+1,dorty+1) == GREEN) && (getpixel(dortx+39,dorty+1) == GREEN) 
				       && (getpixel(dortx+1,dorty+39) == GREEN) && (getpixel(dortx+39,dorty+39) == GREEN) 
				       && (getpixel(dortx+1,dorty-1) != 12) && (getpixel(dortx+11,dorty-1) != 12) 
				       && (getpixel(dortx+21,dorty-1) != 12) && (getpixel(dortx+31,dorty-1) != 12) 
			           && (getpixel(dortx+41,dorty+1) != 12) && (getpixel(dortx+41,dorty+11) != 12)
				       && (getpixel(dortx+41,dorty+21) != 12) && (getpixel(dortx+41,dorty+31) != 12)
				       && (getpixel(dortx+39,dorty+41) != 12) && (getpixel(dortx+29,dorty+41) != 12)
				       && (getpixel(dortx+19,dorty+41) != 12) && (getpixel(dortx+9,dorty+41) != 12)
				       && (getpixel(dortx-1,dorty+39) != 12) && (getpixel(dortx+-1,dorty+29) != 12)
			           && (getpixel(dortx-1,dorty+19) != 12) && (getpixel(dortx-1,dorty+9) != 12) ){
				  
				          int kosedortx = dortx;	
                          int kosedorty = dorty;
                          int dortkare[10] = {kosedortx,kosedorty,kosedortx,kosedorty+40,
						  kosedortx+40,kosedorty+40,kosedortx+40,kosedorty,kosedortx,kosedorty}; 
                          setcolor(BROWN);
                          setfillstyle(1,MAGENTA);
                          fillpoly(4,dortkare);
                          platformsayisi=platformsayisi+1;
                          dortluksayisi=dortluksayisi+1;
            }
        }
    } 
                
            for(int sekizy=0;sekizy<=750;sekizy+=10){
                 for(int sekizx=0;sekizx<=750;sekizx+=10){
                  if( (getpixel(sekizx+1,sekizy+1) == MAGENTA) && (getpixel(sekizx+79,sekizy+1) == MAGENTA) 
				  && (getpixel(sekizx+1,sekizy+79) == MAGENTA) && (getpixel(sekizx+79,sekizy+79) == MAGENTA)
				  && (getpixel(sekizx+1,sekizy-1) != GREEN) && (getpixel(sekizx+11,sekizy-1) != GREEN) 
				  && (getpixel(sekizx+21,sekizy-1) != GREEN) && (getpixel(sekizx+31,sekizy-1) != GREEN) 
				  && (getpixel(sekizx+41,sekizy-1) != GREEN) && (getpixel(sekizx+51,sekizy-1) != GREEN) 
				  && (getpixel(sekizx+61,sekizy-1) != GREEN) && (getpixel(sekizx+71,sekizy-1) != GREEN)
				  && (getpixel(sekizx+81,sekizy+1) != GREEN) && (getpixel(sekizx+81,sekizy+11) != GREEN)
				  && (getpixel(sekizx+81,sekizy+21) != GREEN) && (getpixel(sekizx+81,sekizy+31) != GREEN)
				  && (getpixel(sekizx+81,sekizy+41) != GREEN) && (getpixel(sekizx+81,sekizy+51) != GREEN)
				  && (getpixel(sekizx+81,sekizy+61) != GREEN) && (getpixel(sekizx+81,sekizy+71) != GREEN)
				  && (getpixel(sekizx+71,sekizy+81) != GREEN) && (getpixel(sekizx+61,sekizy+81) != GREEN)
				  && (getpixel(sekizx+51,sekizy+81) != GREEN) && (getpixel(sekizx+41,sekizy+81) != GREEN)
				  && (getpixel(sekizx+31,sekizy+81) != GREEN) && (getpixel(sekizx+21,sekizy+81) != GREEN)
				  && (getpixel(sekizx+11,sekizy+81) != GREEN) && (getpixel(sekizx+1,sekizy+81) != GREEN)
				  && (getpixel(sekizx-1,sekizy+71) != GREEN) && (getpixel(sekizx-1,sekizy+61) != GREEN)
				  && (getpixel(sekizx-1,sekizy+51) != GREEN) && (getpixel(sekizx-1,sekizy+41) != GREEN)
				  && (getpixel(sekizx-1,sekizy+31) != GREEN) && (getpixel(sekizx-1,sekizy+21) != GREEN)
				  && (getpixel(sekizx-1,sekizy+11) != GREEN) && (getpixel(sekizx-1,sekizy+1) != GREEN) ) {
				  	
				   int kosesekizx = sekizx; 
           	       int kosesekizy = sekizy;
                   int sekizkare[10] = {kosesekizx,kosesekizy,kosesekizx,kosesekizy+80,
				   kosesekizx+80,kosesekizy+80,kosesekizx+80,kosesekizy,kosesekizx,kosesekizy}; 
                    setcolor(13);
                    setfillstyle(1,9);
                    fillpoly(4,sekizkare);
                    platformsayisi=platformsayisi+1;
                    sekizliksayisi=sekizliksayisi+1;
            }
        }
    } 
            
              for(int onaltiy=0;onaltiy<=750;onaltiy+=10){
                 for(int onaltix=0;onaltix<=750;onaltix+=10){
                   if( (getpixel(onaltix+1,onaltiy+1) == 9) && (getpixel(onaltix+159,onaltiy+1) == 9) 
				   && (getpixel(onaltix+1,onaltiy+159) == 9) && (getpixel(onaltix+159,onaltiy+159) == 9)
				   && (getpixel(onaltix+1,onaltiy-1) != MAGENTA) && (getpixel(onaltix+11,onaltiy-1) != MAGENTA) 
				   && (getpixel(onaltix+21,onaltiy-1) != MAGENTA) && (getpixel(onaltix+31,onaltiy-1) != MAGENTA)
				   && (getpixel(onaltix+41,onaltiy-1) != MAGENTA) && (getpixel(onaltix+51,onaltiy-1) != MAGENTA)
				   && (getpixel(onaltix+61,onaltiy-1) != MAGENTA) && (getpixel(onaltix+71,onaltiy-1) != MAGENTA)
			 	   && (getpixel(onaltix+81,onaltiy-1) != MAGENTA) && (getpixel(onaltix+91,onaltiy-1) != MAGENTA)
				   && (getpixel(onaltix+101,onaltiy-1) != MAGENTA) && (getpixel(onaltix+111,onaltiy-1) != MAGENTA)
				   && (getpixel(onaltix+121,onaltiy-1) != MAGENTA) && (getpixel(onaltix+131,onaltiy-1) != MAGENTA)
				   && (getpixel(onaltix+141,onaltiy-1) != MAGENTA) && (getpixel(onaltix+151,onaltiy-1) != MAGENTA)
				   && (getpixel(onaltix+161,onaltiy+1) != MAGENTA) && (getpixel(onaltix+161,onaltiy+11) != MAGENTA)
				   && (getpixel(onaltix+161,onaltiy+21) != MAGENTA) && (getpixel(onaltix+161,onaltiy+31) != MAGENTA)
				   && (getpixel(onaltix+161,onaltiy+41) != MAGENTA) && (getpixel(onaltix+161,onaltiy+51) != MAGENTA)
				   && (getpixel(onaltix+161,onaltiy+61) != MAGENTA) && (getpixel(onaltix+161,onaltiy+71) != MAGENTA)
				   && (getpixel(onaltix+161,onaltiy+81) != MAGENTA) && (getpixel(onaltix+161,onaltiy+91) != MAGENTA)
				   && (getpixel(onaltix+161,onaltiy+101) != MAGENTA) && (getpixel(onaltix+161,onaltiy+111) != MAGENTA)
			 	   && (getpixel(onaltix+161,onaltiy+121) != MAGENTA) && (getpixel(onaltix+161,onaltiy+131) != MAGENTA)
				   && (getpixel(onaltix+161,onaltiy+141) != MAGENTA) && (getpixel(onaltix+161,onaltiy+151) != MAGENTA)
			   	   && (getpixel(onaltix+151,onaltiy+161) != MAGENTA) && (getpixel(onaltix+141,onaltiy+161) != MAGENTA)
				   && (getpixel(onaltix+131,onaltiy+161) != MAGENTA) && (getpixel(onaltix+121,onaltiy+161) != MAGENTA)
				   && (getpixel(onaltix+111,onaltiy+161) != MAGENTA) && (getpixel(onaltix+101,onaltiy+161) != MAGENTA)
				   && (getpixel(onaltix+91,onaltiy+161) != MAGENTA) && (getpixel(onaltix+81,onaltiy+161) != MAGENTA)
				   && (getpixel(onaltix+71,onaltiy+161) != MAGENTA) && (getpixel(onaltix+61,onaltiy+161) != MAGENTA)
				   && (getpixel(onaltix+51,onaltiy+161) != MAGENTA) && (getpixel(onaltix+41,onaltiy+161) != MAGENTA)
				   && (getpixel(onaltix+31,onaltiy+161) != MAGENTA) && (getpixel(onaltix+21,onaltiy+161) != MAGENTA)
				   && (getpixel(onaltix+11,onaltiy+161) != MAGENTA) && (getpixel(onaltix+1,onaltiy+161) != MAGENTA)
				   && (getpixel(onaltix-1,onaltiy+151) != MAGENTA) && (getpixel(onaltix-1,onaltiy+141) != MAGENTA)
				   && (getpixel(onaltix-1,onaltiy+131) != MAGENTA) && (getpixel(onaltix-1,onaltiy+121) != MAGENTA)
				   && (getpixel(onaltix-1,onaltiy+111) != MAGENTA) && (getpixel(onaltix-1,onaltiy+101) != MAGENTA)
				   && (getpixel(onaltix-1,onaltiy+91) != MAGENTA) && (getpixel(onaltix-1,onaltiy+81) != MAGENTA)
				   && (getpixel(onaltix-1,onaltiy+71) != MAGENTA) && (getpixel(onaltix-1,onaltiy+61) != MAGENTA)
				   && (getpixel(onaltix-1,onaltiy+51) != MAGENTA) && (getpixel(onaltix-1,onaltiy+41) != MAGENTA)
				   && (getpixel(onaltix-1,onaltiy+31) != MAGENTA) && (getpixel(onaltix-1,onaltiy+21) != MAGENTA)
				   && (getpixel(onaltix-1,onaltiy+11) != MAGENTA) && (getpixel(onaltix-1,onaltiy+1) != MAGENTA) ) {
				  	
				    int koseonaltix = onaltix;	
           	        int koseonaltiy = onaltiy;
                    int onaltikare[10] = {koseonaltix,koseonaltiy,koseonaltix,koseonaltiy+160,koseonaltix+160,
				    koseonaltiy+160,koseonaltix+160,koseonaltiy,koseonaltix,koseonaltiy}; 
                    setcolor(CYAN);
                    setfillstyle(1,BROWN);
                    fillpoly(4,onaltikare);
                    platformsayisi=platformsayisi+1;
                    onaltiliksayisi=onaltiliksayisi+1;
            }
        }
    }          
    
               toplamsondajmaliyeti=alansayac*sondaj_maliyeti;
               printf("Toplam Sondaj Maliyeti : %.2f \n",toplamsondajmaliyeti);
               
               birliksayisi=alansayac-(ikiliksayisi*4);
	           platformsayisi=platformsayisi-(dortluksayisi*4)-(sekizliksayisi*4)-(onaltiliksayisi*4)+birliksayisi;
	           toplamplatformmaliyeti=platformsayisi*platform_maliyeti;
	           
	           printf("Toplam Platform Sayisi : %d \n",platformsayisi);
	           printf("Toplam Platform Maliyeti : %.2f \n",toplamplatformmaliyeti);
	           
	           toplammaliyet=toplamsondajmaliyeti+toplamplatformmaliyeti;
	           printf("Toplam Maliyet : %.2f\n",toplammaliyet);
	           
	           karzarardurumu=rezerv_degeri-toplammaliyet;
	           printf("Kar - Zarar Durumu : %.2f\n",karzarardurumu);
	                          
               getch();
               closegraph();
                
            } else {
                printf("Gecersiz satir numarasi ! \n");
            }
        } else {
            fprintf(stderr, "Curl hatasi: %s\n", curl_easy_strerror(sonuc));
        }

        curl_easy_cleanup(curl);
    }
   
   curl_global_cleanup();
}

  
