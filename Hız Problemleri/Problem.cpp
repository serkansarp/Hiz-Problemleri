#include "Problem.h"

Problem::Problem(int problemTip, int yol, int arac1Hiz, int _arac2Hiz)	//	Constructor
{
	this->problemTip = problemTip;
	this->yol = yol;
	this->arac1Hiz = arac1Hiz;
	arac2Hiz = new int(_arac2Hiz);
}

Problem::~Problem() {	//	Destructor
	delete arac2Hiz;
}
int Problem::getProblemTip() { return problemTip; }
int Problem::getYol()const { return yol; }
int Problem::getArac1Hiz()const { return arac1Hiz; }
int Problem::getArac2Hiz()const { return *arac2Hiz; }

void Problem::problemiCoz(Problem& a) {
	if (a.problemTip == 1) {
		double toplam = a.yol / (double)a.arac1Hiz;
		double dakika = a.yol % a.arac1Hiz / (double)a.arac1Hiz * 60;

		cout << endl;

		cout << "  - Bu tip problem çözümlerine " << a.yol << " olan yol uzunluðu, araç hýzý olan" << endl;
		cout << "    " << a.arac1Hiz << " sayýsýna bölünerek çözüme ulaþýlýr. Genelde tam sayý sonucu" << endl;
		cout << "    " << "bulunur. Bizim iþlemimizde bu " << a.yol / a.arac1Hiz << " saat olarak bulundu. Ancak artýk" << endl;
		cout << "    " << "ondalýk kýsým var ise o da 60 ile çarpýlarak dakika olarak yazýlýr." << endl;
		cout << "    " << "Örneðin 1,5 saatlik yol 1 saat sürmüþtür. Ondalýk kýsým var ise o" << endl;
		cout << "    " << "da çarpýlarak dakika olarak hesaplanabilir, yarým saat 30 dakikadýr.\n    0.5*60=30 gibi." << endl << endl;

		cout << "    " << "Ýþlemimizi böyle çözerek, dakika küsuratlý çýkarsa da yuvarlayayýp " << endl;
		cout << "    " << "Sonuç:" << endl;
		cout << "    - " << a.yol / a.arac1Hiz << " saat, " << setprecision(0) << fixed << dakika << " dakika -" << endl << endl;
	}
	else if (a.problemTip == 2) {
		int toplamHiz = a.arac1Hiz + *(a.arac2Hiz);
		double dakika = a.yol % toplamHiz / (double)toplamHiz * 60;

		cout << endl;
		cout << "  - Bu tip hýz problemi çözümlerine A noktasýndan kalkan araçla B" << endl;
		cout << "    " << "noktasýndan kalkan araçlarýn hýzý toplanarak baþlanýr. Çünkü" << endl;
		cout << "    " << "ikisinin birlikte kat ettiði bir mesafe söz konusudur." << endl;
		cout << "    " << "Örneðimizde A noktasýndan kalkan araç saatte " << a.arac1Hiz << " km, B" << endl;
		cout << "    " << "noktasýndan kalkan araç ise " << *(a.arac2Hiz) << " km yol kat ediyor, birlikte bir" << endl;
		cout << "    " << "saatte " << toplamHiz << " km yol kat ediyorlar. Ýkisinin hýzý toplamý bir hýzla giden" << endl;
		cout << "    " << "bir aracýn A noktasýndan B noktasýna gittiðini düþüneceðiz ve süreyi" << endl;
		cout << "    " << "hesaplayacaðýz. Yani 1'inci tip soru çözümleri gibi yol / hiz ile" << endl;
		cout << "    " << "devam ediyoruz. " << a.yol << " km uzunluðundaki bir yolu iki aracýn toplam" << endl;
		cout << "    " << "hýzý olan " << toplamHiz << " deðerine böldüðümüzde " << setprecision(2) << fixed << (double)a.yol / toplamHiz << " saat (yuvarlanmýþ) deðerine" << endl;
		cout << "    " << "ulaþýyoruz. Aslýnda bulduðumuz her iki aracýn karþýlaþmasý için gereken" << endl;
		cout << "    " << "süre. A noktasýndan kalkan aracýn hýzýný bu süre ile çarptýðýmýzda" << endl;
		cout << "    " << "kendisinin, B noktasýndan kalkan aracýn hýzý ile bu süreyi çarptýðýmýzda" << endl;
		cout << "    " << "onun kaçýncý km'sinde karþýlaþacaklarýný buluruz. Yani A'daki " << a.arac1Hiz << "x" << setprecision(2) << fixed << (double)a.yol / toplamHiz << "," << endl;
		cout << "    " << "B'deki " << *(a.arac2Hiz) << "x" << setprecision(2) << fixed << (double)a.yol / toplamHiz << " km yol kat etmelidir." << endl << endl;
		cout << "    " << "Sonuçlar:" << endl;
		cout << "    " << "- Ýkisi de yola çýktýktan -" << a.yol / toplamHiz << " saat, " << setprecision(0) << fixed << dakika << "- sonra karþýlaþýrlar." << endl;
		cout << "    " << "- A'dan yola çýkan araç " << setprecision(0) << fixed << a.arac1Hiz * (double)a.yol / toplamHiz << " km yol kat etmiþtir." << endl;
		cout << "    " << "- B'den yola çýkan araç " << setprecision(0) << fixed << *(a.arac2Hiz) * (double)a.yol / toplamHiz << " km yol kat etmiþtir." << endl;
	}
	else if (a.problemTip == 3) {
		// Bu çözümde ek bir parametreye daha ihtiyacýmýz olduðundan ve kullanýlmadýðýndan
		// yol parametresini saat olarak assign ettik
		int saat = a.yol;
		int uzaklik = abs(a.arac1Hiz - *(a.arac2Hiz));
		cout << endl;
		cout << "  - Bu tür hýz problemi çözümleri öncekilerden daha kolaydýr, zira 2 aracýn" << endl;
		cout << "    " << "arasýnda 1 saatte oluþacak mesafe, araçlarýn hýzlarýnýn birbirinden" << endl;
		cout << "    " << "çýkarýlmasýyla bulunur, negatifse pozitife çevirilir. Örneðimizde" << endl;
		cout << "    " << "biri " << a.arac1Hiz << " ve " << *(a.arac2Hiz) << " km/sa hýzlarýndaki iki araçtan bahsediliyor." << endl;
		cout << "    " << "Aralarýndaki hýz farký ise " << uzaklik << " km/sa, yani 1 saatte aralarýnda" << endl;
		cout << "    " << "bu kadar mesafe oluþacak. Her saat de bu kadar artacak. Soruda verilen " << saat << " saat" << endl;
		cout << "    " << "deðeriyle uzaklýðý çarptýðýmýzda sonuca ulaþýyoruz." << endl;
		cout << "    " << "Sonuç:" << endl;
		cout << "    - " << saat * uzaklik << " saat -" << endl << endl;
	}
	else {
		cout << "***ERROR***" << endl;
	}
}
