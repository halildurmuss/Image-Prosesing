#include<iostream>
#include<string.h>
#include <fstream>
#include <sys/time.h>

using namespace std;

#define PENCERE 5
int pencere_ortalamasi_al (int * matris, int genislik, int indeks);

int main (int argc, char **argv)
{
    if (argc == 2) {
    	struct timeval currentTime;
		double startTime,endTime,elapsedTime;

        // Tam olarak bir tane arguman aldığımızdan emin olduk
        char * girdi_dosya_adresi_orig = new char [128];    // girilen metnin orijimal halini tuttuk
        strcpy(girdi_dosya_adresi_orig, argv[1]);

        char girdi_dosya_adresi[128];                           // girilen metni burada tuttuk (token işlemi yaparken değişecek)
        strcpy(girdi_dosya_adresi, girdi_dosya_adresi_orig);

        char cikti_dosya_adresi[128];
        char * dosya_ismi = NULL;
        if (strstr(girdi_dosya_adresi, "/")){
            // Girilen metinde "/" varmı diye bakıyoruz

            char *p = strtok(girdi_dosya_adresi, "/");
            while (p) {
                if (strstr(p, ".txt")) {
                    dosya_ismi = strtok(p, ".");               
                }
                p = strtok(NULL, "/");
            }
        }else if (strstr(girdi_dosya_adresi, ".txt")) {
            // Girilen metinde ".txt" var mı diye bakıyoruz
            dosya_ismi = strtok(girdi_dosya_adresi, ".");
        }

        if (dosya_ismi == NULL) {
            cout << "Verilen adresteki dosya tanımlanamadı.";
            return -1;
        }else {
            sprintf(cikti_dosya_adresi, "%s_filtered.txt", dosya_ismi);
        }

        strcpy(girdi_dosya_adresi, girdi_dosya_adresi_orig);
        delete [] girdi_dosya_adresi_orig;

        ifstream girdi_txt_dosyasi; 
        girdi_txt_dosyasi.open(girdi_dosya_adresi);
        if (girdi_txt_dosyasi.is_open())
        {
            int yukseklik;
            int genislik;
            girdi_txt_dosyasi >> yukseklik >> genislik;

            int * girdi_ana_dizi = new int [yukseklik * genislik];

            int * cikti_ana_dizi = new int [yukseklik * genislik];

            int piksel;
            int i = 0;
            while (girdi_txt_dosyasi >> piksel) {
                girdi_ana_dizi[i] = piksel;
                cikti_ana_dizi[i] = piksel;
                i++;
            }

        	gettimeofday(&currentTime, NULL); //Seconds from the epoch time
			startTime=currentTime.tv_sec+(currentTime.tv_usec/1000000.0); 	

            int pf = PENCERE/2; // pencere farkı

            int ilk_piksel = pf * genislik + pf;
            int son_piksel = (yukseklik-pf) * genislik + (genislik - pf);

            for (i = ilk_piksel; i < son_piksel; i++) {
                cikti_ana_dizi[i] = pencere_ortalamasi_al(girdi_ana_dizi, genislik, i);
            }

    		gettimeofday(&currentTime, NULL); //Seconds from the epoch time
			endTime=currentTime.tv_sec+(currentTime.tv_usec/1000000.0);

            ofstream cikti_txt_dosyasi; 
            cikti_txt_dosyasi.open(cikti_dosya_adresi);
            if (cikti_txt_dosyasi.is_open())
            {
                cikti_txt_dosyasi << yukseklik << " " << genislik << endl;

                for (i = 0; i < yukseklik * genislik; i++)
                {
                    if (i>0 && i % genislik == 0) cikti_txt_dosyasi << endl;
                    cikti_txt_dosyasi << cikti_ana_dizi[i] << " ";
                }

                cikti_txt_dosyasi.close();
            }

            girdi_txt_dosyasi.close();
            
            delete [] girdi_ana_dizi;
            delete [] cikti_ana_dizi;

        	elapsedTime = (endTime-startTime) * 1000;
			cout << "Total Time Taken (milisaniye cinsinden): " << elapsedTime<< endl;

        }else {
            cout << "Verilen adresteki dosya açılamadı." << endl;;
            return -1;
        }

    }else {
        cout << "Tam olarak bir komut satiri parametresi girilmelidir." << endl;
        return -1;
    }
}

int pencere_ortalamasi_al (int * matris, int genislik, int indeks)
{
    int i;
    int j;
    int pf = PENCERE / 2; // pencere farkı
    int toplam = 0;
    int komsu_sayisi = 0;

    int ilk_piksel = (indeks - pf) - (pf*genislik);
    
    for ( i = 0; i < PENCERE; i++)
    {
        int k = ilk_piksel + (i*genislik);
        toplam += matris[k] + matris[k+1] + matris[k+2] + matris[k+3] + matris[k+4];
        komsu_sayisi+=5;
    }

    return toplam / komsu_sayisi;
}