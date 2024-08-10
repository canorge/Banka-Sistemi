#include <iostream>
#include <cstdlib> // rand ve srand fonksiyonları için kütüphane
#include <ctime>   // time fonksiyonu için kütüphane
#include<locale.h> // türkçe karakter kullanımı için kütüphane
#include <math.h>	//matematiksel işlemler için kütüphane
using namespace std;

int musterisayisi = 0; //musteri sayısı tutan değişken
int ozelmusteri = 0; //hesap türü  özel olan müşteri sayısını tutan değişken
int genelmusteri = 0;	//hesap türü genel olan müşteri sayısını tutan değişken

//hesap classı
class hesap
{
public:

	//kripto para alma fonksiyonu
	void al(float miktar)
	{
		int alinan = 0;
		//alınacak miktar doğru mu diye kontrol
		if (miktar <= 0)
		{
			cout << "lütfen geçerli bir miktar giriniz" << endl;
		}
		else
		{
			alissayisi++;
			alisfiyatı = kriptoParaDeger;
			alinan = miktar / kriptoParaDeger;
			para += (miktar - (alinan * kriptoParaDeger));
			kriptoParaAdet += alinan;
			cout << "alma işlemi başarılı" << endl;
			cout << alinan << " adet kripto para alındı" << endl;
			cout << "hesapta bulunan kripto para adedi:" << kriptoParaAdet << endl;
			cout << "güncel para(kripto para alınmamış para):" << para<<endl;


			//her alma işleminde ortalama maliyeti hesaplayan döngü
			for (int i = 0; i < alissayisi; i++)
			{
				ortmaliyet += (alisfiyatı * alinan);
			}
			ortmaliyet = ortmaliyet / kriptoParaAdet;
		}

	}

	//kripto para satma fonksiyonu
	void sat(float miktar)
	{
		int satilan = 0;
		
		if (miktar > (kriptoParaAdet * kriptoParaDeger))
		{
			cout<<"hesap bakiyesi yetersiz"<<endl;
			cout << "hesapta bulunan kripto para adedi:" << kriptoParaAdet << endl;
			cout << "hesap bakiyesi:" << (kriptoParaAdet * kriptoParaDeger)+para << endl;
		}
		else if (miktar <= 0)
		{
			cout << "lütfen geçerli bir sayı giriniz" << endl;
		}
		else
		{
			satilan = miktar / kriptoParaDeger;
			kriptoParaAdet -= satilan;
			para -= (miktar - (satilan * kriptoParaDeger));
			cout << satilan << " adet kripto para başarı ile satıldı" << endl;
			cout << "kalan kripto para adedi:" << kriptoParaAdet << endl;
			cout << "kalan para(kripto para alınmamış para):" << para << endl;
		}
	
	}

	//kar-zarar hesplayan fonksiyon
	void karhesapla()
	{
		cout << "kar/zarar durumu" << endl;

		if (kriptoParaDeger > ortmaliyet)
		{
			cout << kriptoParaAdet * (kriptoParaDeger - ortmaliyet) << " TL kardasınız" << endl;
		}
		else if (kriptoParaDeger < ortmaliyet)
		{
			cout << kriptoParaAdet * (ortmaliyet - kriptoParaDeger) << " TL zarardasınız" << endl;
		}
		else
		{
			cout << "hesap durumu nötr" << endl;
		}
	}

	// hesap classı bakiye göster fonksiyonu
	void bakiyeGoster()
	{
		cout << "hesaptaki kripto para adedi:" << kriptoParaAdet << endl;
		cout << "hesaptaki bakiye(kripto para degeri):" << kriptoParaAdet * kriptoParaDeger << endl;
		cout << "hesaptaki para(kripto para alınmamış para):" << para << endl;
	}

	//hesabın oluşturduğu günü gösteren fonksiyon
	void OlusumTarihi()
	{
		cout << "hesap açılış tarihi:" << Gun << "." << Ay << "." << Yil << endl;
	}
	//hesap classı tarih görüntüle
	void tarihGoruntule()
	{
		cout << "tarih:" << gun << "." << ay << "." << yil << endl;
	}

	int alissayisi = 0;//alma işleminin kaç defa yapıldığını tutan değişken
	float ortmaliyet = 0;	//ortalama maliyeti tutan değişken
	float alisfiyatı;	//kripto paranın alış fiyatını tutan değişken
	int hesapNO;	//hesap numarasını tutan değişken
	int kriptoParaAdet = 0;	//hesaptaki kripto para adedini tutan değişken
	float kriptoParaDeger = 1;	//kripto paranın değerini tutan değişken
	int gun = 01, ay = 01, yil = 2000; 
	const int Gun = 01;
	const int Ay = 01;
	const int Yil = 2000;
	
	float para = 0;
	string hesapturu;

};

//ozel hesap classı
class OzelHesap :public hesap
{
public:
	//özel hesabın kuralına göre kripto paranın günden güne değer değişimini yapan fonksiyon
	void OzelKriptoDeger(int gunsayisi)
	{
		//her ayda kriptoparanın düşüş göstereceği 3 günü tutan dizi
		int dusengunler[3];
		int index = 0;

		//düşüş gösteren günlerin random oluşumu ve bu günlerin farklı olması için kontrolü
		while (index < 3)
		{
			srand(time(0));
			int rastgeleSayi = rand() % 30;

			bool aynisivarmi = false;
			for (int i = 0; i < index; i++)
			{
				if (rastgeleSayi == dusengunler[i]) {
					aynisivarmi = true;
					break;
				}
			}
			if (!aynisivarmi)
			{
				dusengunler[index] = rastgeleSayi;
				index++;
			}
		}
		int tursayisi = 0;


		for (int i = gun; i < gunsayisi; i++)
		{
			if (i == dusengunler[0] || i == dusengunler[1] || i == dusengunler[2])
			{
				kriptoParaDeger = kriptoParaDeger - kriptoParaDeger * 0.1;
			}
			else
			{
				kriptoParaDeger = kriptoParaDeger + kriptoParaDeger * 0.05;

			}


			if (i == 30)
			{
				i = 1;
				gun = 1;
				gunsayisi -= tursayisi;
				tursayisi = 0;
				if (ay == 12)
				{
					ay = 1;
					yil++;
				}
				else
				{
					ay++;
				}
			}
			else
			{
				tursayisi++;
				gun++;
			}
		}
		

	}

}; OzelHesap Ozelhesaplar[30];


class GenelHesap :public hesap
{
public:

	//genel hesap kuralına göre kripto para 15 günde 1 düşecektir ben de bu günleri  ayın 15. ve 30. günü olarak yaptım
	void GenelkriptoDeger(int gunsayisi)
	{
		int tursayisi = 0;
		for (int i = gun; i < gunsayisi; i++)
		{
			if (i == 15 || i == 30)
			{
				kriptoParaDeger = kriptoParaDeger - kriptoParaDeger * 0.05;
			}
			else
			{
				kriptoParaDeger = kriptoParaDeger + kriptoParaDeger * 0.01;
			}

			if (i == 30)
			{
				i = 1;
				gun = 1;
				gunsayisi -= tursayisi;
				tursayisi = 0;
				if (ay == 12)
				{
					ay = 1;
					yil++;
				}
				else
				{
					ay++;
				}
			}
			else
			{
				tursayisi++;
				gun++;
			}
		}
		
	}

}; GenelHesap Genelhesaplar[30];



//hesap açma fonksiyonu
void hesapac()
{
	int hesapturusecimi = NULL;
	cout << "açmak istediğiniz hesabın türünü seçiniz" << endl;
	cout << "1-Özel Hesap" << endl;
	cout << "2-Genel Hesap" << endl;
	do
	{
		cin >> hesapturusecimi;
	} while (hesapturusecimi != 1 && hesapturusecimi != 2);

	if (hesapturusecimi == 1)
	{
		if (ozelmusteri == 30)
		{
			cout << "maksimum özel hesap kapasitesine ulaşıldı daha fazla hesap açamazsınız" << endl;
		}
		else
		{ 
		Ozelhesaplar[ozelmusteri].hesapNO = 1000 + musterisayisi;
		Ozelhesaplar[ozelmusteri].hesapturu = "özel hesap";
		cout << "hesabınız oluşturuldu" << endl;
		cout << "hesap numaranız:" << Ozelhesaplar[ozelmusteri].hesapNO << endl;
		cout << "hesap türü:" << Ozelhesaplar[ozelmusteri].hesapturu << endl;
		Ozelhesaplar[ozelmusteri].OlusumTarihi();
		ozelmusteri++;
		musterisayisi++;
		}
	}
	else
	{
		if (genelmusteri == 30)
		{
			cout << "maksimum genel hesap kapasitesine ulaşıldı daha fazla hesap açamazsınız" << endl;
		}
		else
		{
		Genelhesaplar[genelmusteri].hesapNO = 1000 + musterisayisi;
		Genelhesaplar[genelmusteri].hesapturu = "genel hesap";
		Genelhesaplar[genelmusteri].kriptoParaAdet = 0;
		Genelhesaplar[genelmusteri].kriptoParaDeger = 1;
		cout << "hesabınız oluşturuldu" << endl;
		cout << "hesap numaranız:" << Genelhesaplar[genelmusteri].hesapNO << endl;
		cout << "hesap türü:" << Genelhesaplar[genelmusteri].hesapturu << endl;
		 Genelhesaplar[genelmusteri].OlusumTarihi();
		musterisayisi++;
		genelmusteri++;
		}
	}
}

//para ekleme fonksiyonu
void paraekle()
{
	int geciciNO;
	float miktar;
	int HesapTuru;
	cout << "Para ekleyeceğiniz hesabın numarasını giriniz:";//para eklenecek hesabın numarasının alınması
	cin >> geciciNO;

	cout << "Para ekleyeceğiniz hesabın türünü giriniz" << endl; //para eklenecek hesabın türünün alınması
	cout << "1-özel hesap" << endl;
	cout << "2-genel hesap" << endl;
	cin >> HesapTuru;

	cout << "Eklemek istediğiniz tutarı giriniz:";
	cin >> miktar;
	if (HesapTuru == 1)
	{
		for (int i = 0; i < ozelmusteri; i++)//özel hesap dizisinin gezinip para eklenecek hesabın bulunup işlemin yapılması
		{
			if (Ozelhesaplar[i].hesapNO == geciciNO)
			{
				Ozelhesaplar[i].al(miktar);
			}
		}
	}
	else if (HesapTuru == 2)
	{
		for (int i = 0; i < genelmusteri; i++)//genel hesap dizisinin gezinip para  eklenecek hesabın bulunup işlemin yapılması
		{
			if (Genelhesaplar[i].hesapNO == geciciNO)
			{
				Genelhesaplar[i].al(miktar);
			}
		}
	}

}

void paracek()
{
	int geciciNO;
	float miktar;
	int HesapTuru;
	cout << "Para çekeceğiniz hesabın numarasını giriniz:"; //para çekilecek hesabın numarasının alınması
	cin >> geciciNO;

	cout << "Para ekleyeceğiniz hesabın türünü giriniz" << endl; //para çekilecek hesabın türünün alınması
	cout << "1-özel hesap" << endl;
	cout << "2-genel hesap" << endl;
	cin >> HesapTuru;

	cout << "çekmek istediğiniz tutarı giriniz:";
	cin >> miktar;
	if (HesapTuru == 1)
	{
		for (int i = 0; i < ozelmusteri; i++)//özel hesap dizisinin gezinip para çekilecek hesabın bulunup işlemin yapılması
		{
			if (Ozelhesaplar[i].hesapNO == geciciNO)
			{
				Ozelhesaplar[i].sat(miktar);
			}
		}
	}
	else if (HesapTuru == 2)
	{
		for (int i = 0; i < genelmusteri; i++)
		{
			if (Genelhesaplar[i].hesapNO == geciciNO)//genel hesap dizisinin gezinip para çekilecek hesabın bulunup işlemin yapılması
			{
				Genelhesaplar[i].sat(miktar);
			}
		}
	}

}

//tarih güncelleyerek kripto para güncellemesi yapan fonksiyon
void tarihguncelle()
{
	int HesapTuru;
	int geciciNO;
	int kacgun;

	cout << "işlemi yapacağınız hesabın numarasını giriniz";
	cin >> geciciNO;

	cout << "Para ekleyeceğiniz hesabın türünü giriniz" << endl;
	cout << "1-özel hesap" << endl;
	cout << "2-genel hesap" << endl;
	cin >> HesapTuru;

	cout << "kaç gün ilerisine güncellemek istersiniz?";
	cin >> kacgun;
	if (HesapTuru == 1)
	{
		for (int i = 0; i < ozelmusteri; i++)
		{
			if (Ozelhesaplar[i].hesapNO == geciciNO)
			{

				Ozelhesaplar[i].OzelKriptoDeger(kacgun);
				Ozelhesaplar[i].bakiyeGoster();
				Ozelhesaplar[i].tarihGoruntule();
			}
		}
	}

	else if (HesapTuru == 2)
	{
		for (int i = 0; i < genelmusteri; i++)
		{
			if (Genelhesaplar[i].hesapNO == geciciNO)
			{
				Genelhesaplar[i].GenelkriptoDeger(kacgun);
				Genelhesaplar[i].bakiyeGoster();
				Genelhesaplar[i].tarihGoruntule();
			}
		}
	}

}

//hesap bakiyesini ve kar-zarar durumunu gösteren fonksiyon
void BakiyeGor()
{
	int HesapTuru;
	int geciciNO;

	cout << "Bakiyesini görüntüleyeceğiniz hesabın numarasını giriniz:";
	cin >> geciciNO;

	cout << "Para ekleyeceğiniz hesabın türünü giriniz" << endl;
	cout << "1-özel hesap" << endl;
	cout << "2-genel hesap" << endl;
	cin >> HesapTuru;

	if (HesapTuru == 1)
	{
		for (int i = 0; i < ozelmusteri; i++)
		{
			if (Ozelhesaplar[i].hesapNO == geciciNO)
			{
				Ozelhesaplar[i].bakiyeGoster();
				Ozelhesaplar[i].karhesapla();
			}
		}
	}
	else if (HesapTuru == 2)
	{
		for (int i = 0; i < genelmusteri; i++)
		{
			if (Genelhesaplar[i].hesapNO == geciciNO)
			{
				Genelhesaplar[i].bakiyeGoster();
				Genelhesaplar[i].karhesapla();
			}
		}
	}

}

//açılan tüm hesapları listeleyen fonksiyon
void hesaplarıListele()
{
	cout << "Özel hesaplar listeleniyor" << endl;
	for (int i = 0; i < ozelmusteri; i++)
	{
		cout << "******************************************" << endl;
		cout << i + 1 << ". hesabın bilgileri" << endl;
		cout << "hesap numarası:" << Ozelhesaplar[i].hesapNO << endl;
		cout << "hesap türü:" << Ozelhesaplar[i].hesapturu << endl;
		cout << "Olusturulma tarihi:"; Ozelhesaplar[i].OlusumTarihi();
		cout << "hesap durumu:"; Ozelhesaplar[i].bakiyeGoster();
		cout << "kar/zarar durumu:"; Ozelhesaplar[i].karhesapla();
	}
	cout << endl;
	cout << "-------------------------------------------------------" << endl;
	cout << endl;
	cout << "Genel hesaplar listeleniyor" << endl;
	for (int i = 0; i < genelmusteri; i++)
	{
		cout << "******************************************" << endl;
		cout << i + 1 << ". hesabın bilgileri" << endl;
		cout << "hesap numarası:" << Genelhesaplar[i].hesapNO << endl;
		cout << "hesap türü:" << Genelhesaplar[i].hesapturu << endl;
		cout << "Olusturulma tarihi:"; Genelhesaplar[i].OlusumTarihi();
		cout << "hesap durumu:"; Genelhesaplar[i].bakiyeGoster();
		cout << "kar/zarar durumu:"; Genelhesaplar[i].karhesapla();
	}

}
int main()
{


	setlocale(LC_ALL, "Turkish");
	int secim = NULL;
	char devammi = 'h';

	//MENÜ
	cout << "Kripto para hesabı uygulamasına hoşgeldiniz" << endl;
	cout << endl;
	cout << "Yapmak istediğiniz işlemi seçiniz" << endl;
	do
	{
		cout << "1-Hesap aç" << endl;
		cout << "2-Hesaba para ekle" << endl;
		cout << "3-Hesaptan para çek" << endl;
		cout << "4-Tarih güncelle" << endl;
		cout << "5-hesap bakiye gör" << endl;
		cout << "6-Hesapları listele" << endl;
		cout << "işlem seçimi:"; cin >> secim;

		switch (secim)
		{
		case 1:
			
			hesapac();
			system("PAUSE");
			system("cls");
			break;

		case 2:
			paraekle();
			system("PAUSE");
			system("cls");
			break;

		case 3:
			paracek();
			system("PAUSE");
			system("cls");
			break;

		case 4:
			tarihguncelle();
			system("PAUSE");
			system("cls");
			break;

		case 5:
			BakiyeGor();
			system("PAUSE");
			system("cls");
			break;

		case 6:
			hesaplarıListele();
			system("PAUSE");
			system("cls");
			break;
		default:
			cout << "lütfen geçerli bir işlem seçiniz" << endl;
			break;
		}

		cout << "Başka bir işlem yapmak ister misiniz? (evet için e hayır için h tuşuna basınız)";
		cin >> devammi;
	} while (devammi != 'h');

}














