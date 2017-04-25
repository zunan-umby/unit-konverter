#include<stdio.h>
#include<string.h>

/* Program Untuk merubah/mengkonversi satuan tertentu ke satuan lain.
 * Author: Zunan Arif R.
 * Version: 1.0
 */

// Membuat Structure Satuan
struct satuan {
	float skala;
	char nama[50];
	float penambah;	
};

// Deklarasi Fungsi
void konversi_panjang();
void konversi_suhu();
void konversi_waktu();

int main() {
	
	int pilihan;
	
	printf("-------------------------------------\n");
	printf(" Nama\t: Zunan Arif Rahmanto\n");
	printf(" NIM\t: 15111131\n");
	printf("-------------------------------------\n");	
	printf("-------------------------------------\n");
	printf(" ===== Program Konversi Satuan =====\n");
	printf("-------------------------------------");

	do {
		printf("\n\n-----------------------\n");
		printf(" Pilihan Kategori:\n");
		printf("-----------------------\n");
		printf(" 1. Satuan Panjang\n");
		printf(" 2. Temperatur / Suhu\n");
		printf(" 3. Waktu\n");
		printf(" 0. Keluar\n");	
		printf("-----------------------\n");
		printf(" Masukkan pilihan (0-3): ");
		scanf("%d", &pilihan);
		
		if(pilihan < 0 || pilihan > 3) {
			printf("-----------------------\n");
			printf(" Error. Silahkan Ulangi lagi!\n");
		} else {
			
			switch(pilihan) {				
				case 1:
					konversi_panjang();
					break;
				case 2:
					konversi_suhu();
					break;
				case 3:
					konversi_waktu();
					break;
				default:
					break;
				
			} // end switch			
			
		} // end else
	
	} while(pilihan != 0);
	
	printf("\n\n-------------------------------------\n");
	printf(" Bye.. Terima Kasih, Wassalam \n");

	
	return 0;	
}
/* Program Utama Selesai */


/* -------- Deskirpsi Fungsi-fungsi -------- */

void konversi_panjang() {
	
	// Deklarasi var
	double sumber, hasil;	
	int satuan_awal, satuan_akhir;	
	struct satuan meter[6];
	
	// Mengisi nilai meter
	meter[0].skala = 1;
	strcpy(meter[0].nama, "Meter");
	
	meter[1].skala = 100;
	strcpy(meter[1].nama, "Cm");
	
	meter[2].skala = 1000;
	strcpy(meter[2].nama, "Mm");
	
	meter[3].skala = 0.001;
	strcpy(meter[3].nama, "Km");
	
	meter[4].skala = 39.3701;
	strcpy(meter[4].nama, "Inch");
	
	meter[5].skala = 3.28084;
	strcpy(meter[5].nama, "Foot");
	
	for(;;) {
		printf("\n-----------------------\n");
		printf(" Pilihan Satuan:\n");
		printf("-----------------------\n");
		printf(" 1. Meter\n");
		printf(" 2. Centimeter\n");
		printf(" 3. Milimeter\n");
		printf(" 4. Kilometer\n");
		printf(" 5. Inch\n");
		printf(" 6. Foot\n");	
		printf(" 0. Kembali ke pilihan kategori\n");	
		printf("-----------------------\n");
		
		for(;;) {
			printf(" Masukkan pilihan satuan awal (0-6): ");
			scanf("%d", &satuan_awal);
			if(satuan_awal <= 6 && satuan_awal >= 0) {
				break;
			} else {
				printf(" Error. Silahkan Ulangi lagi!\n");
			}
		}
		
		if(satuan_awal == 0)
			break;
		
		for(;;) {
			printf(" Masukkan pilihan satuan tujuan (0-6): ");
			scanf("%d", &satuan_akhir);
			if(satuan_akhir <= 6 && satuan_akhir >= 0) {
				break;
			} else {
				printf(" Error. Silahkan Ulangi lagi!\n");
			}
		}
		
		if(satuan_akhir == 0)
			break;
	
		printf(" Masukkan angka yang akan diconvert: ");
		scanf("%lf", &sumber);
		
		hasil = sumber / meter[satuan_awal-1].skala;
		hasil = hasil * meter[satuan_akhir-1].skala;
		printf("-----------------------\n");
		printf(" Hasilnya: \n");
		printf(" %g %s sama dengan %g %s \n\n", sumber, meter[satuan_awal-1].nama, hasil, meter[satuan_akhir-1].nama);
	
	} // end for
}
/* Fungsi konversi panjang selesai. */


void konversi_suhu() {
	
	// Deklarasi var
	double sumber, hasil;	
	int satuan_awal, satuan_akhir;	
	struct satuan celcius[3];
	
	// Mengisi nilai celcius
	celcius[0].skala = 1;
	celcius[0].penambah = 0;	
	strcpy(celcius[0].nama, "Celcius");
	
	celcius[1].skala = 1.8;
	celcius[1].penambah = 32;	
	strcpy(celcius[1].nama, "Fahrenheit");
	
	celcius[2].skala = 1;
	celcius[2].penambah = 273.15;	
	strcpy(celcius[2].nama, "Kelvin");
	
	
	for(;;) {
		printf("\n-----------------------\n");
		printf(" Pilihan Satuan:\n");
		printf("-----------------------\n");
		printf(" 1. Celcius\n");
		printf(" 2. Fahrenheit\n");
		printf(" 3. Kelvin\n");
		printf(" 0. Kembali ke pilihan kategori\n");	
		printf("-----------------------\n");
		
		for(;;) {
			printf(" Masukkan pilihan satuan awal (0-3): ");
			scanf("%d", &satuan_awal);
			if(satuan_awal <= 3 && satuan_awal >= 0) {
				break;
			} else {
				printf(" Error. Silahkan Ulangi lagi!\n");
			}
		}
		
		if(satuan_awal == 0)
			break;
		
		for(;;) {
			printf(" Masukkan pilihan satuan tujuan (0-3): ");
			scanf("%d", &satuan_akhir);
			if(satuan_akhir <= 3 && satuan_akhir >= 0) {
				break;
			} else {
				printf(" Error. Silahkan Ulangi lagi!\n");
			}
		}
		
		if(satuan_akhir == 0)
			break;
	
		printf(" Masukkan angka yang akan diconvert: ");
		scanf("%lf", &sumber);
		
		hasil = (sumber - celcius[satuan_awal-1].penambah) / celcius[satuan_awal-1].skala;
		hasil = (hasil * celcius[satuan_akhir-1].skala) + celcius[satuan_akhir-1].penambah;
		printf("-----------------------\n");
		printf(" Hasilnya: \n");
		printf(" %g %s sama dengan %g %s \n\n", sumber, celcius[satuan_awal-1].nama, hasil, celcius[satuan_akhir-1].nama);
	
	} // end for
	
}
/* Fungsi konversi suhu selesai. */


void konversi_waktu() {
	
	// Deklarasi var
	double sumber, hasil;	
	int satuan_awal, satuan_akhir;	
	struct satuan minggu[5];
	
	// Mengisi nilai hari
	minggu[0].skala = 1;
	strcpy(minggu[0].nama, "Minggu");
	
	minggu[1].skala = 7;
	strcpy(minggu[1].nama, "Hari");
	
	minggu[2].skala = 168;
	strcpy(minggu[2].nama, "Jam");
	
	minggu[3].skala = 10080;
	strcpy(minggu[3].nama, "Menit");
	
	minggu[4].skala = 604800;
	strcpy(minggu[4].nama, "Detik");

	
	for(;;) {
		printf("\n-----------------------\n");
		printf(" Pilihan Satuan:\n");
		printf("-----------------------\n");
		printf(" 1. Minggu\n");
		printf(" 2. Hari\n");
		printf(" 3. Jam\n");
		printf(" 4. Menit\n");
		printf(" 5. Detik\n");
		printf(" 0. Kembali ke pilihan kategori\n");	
		printf("-----------------------\n");
		
		for(;;) {
			printf(" Masukkan pilihan satuan awal (0-6): ");
			scanf("%d", &satuan_awal);
			if(satuan_awal <= 6 && satuan_awal >= 0) {
				break;
			} else {
				printf(" Error. Silahkan Ulangi lagi!\n");
			}
		}
		
		if(satuan_awal == 0)
			break;
		
		for(;;) {
			printf(" Masukkan pilihan satuan tujuan (0-6): ");
			scanf("%d", &satuan_akhir);
			if(satuan_akhir <= 6 && satuan_akhir >= 0) {
				break;
			} else {
				printf(" Error. Silahkan Ulangi lagi!\n");
			}
		}
		
		if(satuan_akhir == 0)
			break;
	
		printf(" Masukkan angka yang akan diconvert: ");
		scanf("%lf", &sumber);
		
		hasil = sumber / minggu[satuan_awal-1].skala;
		hasil = hasil * minggu[satuan_akhir-1].skala;
		printf("-----------------------\n");
		printf(" Hasilnya: \n");
		printf(" %g %s sama dengan %g %s \n\n", sumber, minggu[satuan_awal-1].nama, hasil, minggu[satuan_akhir-1].nama);
	
	} // end for
}
/* Fungsi konversi waktu selesai. */
