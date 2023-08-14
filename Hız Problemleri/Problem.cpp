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

		cout << "  - Bu tip problem ��z�mlerine " << a.yol << " olan yol uzunlu�u, ara� h�z� olan" << endl;
		cout << "    " << a.arac1Hiz << " say�s�na b�l�nerek ��z�me ula��l�r. Genelde tam say� sonucu" << endl;
		cout << "    " << "bulunur. Bizim i�lemimizde bu " << a.yol / a.arac1Hiz << " saat olarak bulundu. Ancak art�k" << endl;
		cout << "    " << "ondal�k k�s�m var ise o da 60 ile �arp�larak dakika olarak yaz�l�r." << endl;
		cout << "    " << "�rne�in 1,5 saatlik yol 1 saat s�rm��t�r. Ondal�k k�s�m var ise o" << endl;
		cout << "    " << "da �arp�larak dakika olarak hesaplanabilir, yar�m saat 30 dakikad�r.\n    0.5*60=30 gibi." << endl << endl;

		cout << "    " << "��lemimizi b�yle ��zerek, dakika k�suratl� ��karsa da yuvarlayay�p " << endl;
		cout << "    " << "Sonu�:" << endl;
		cout << "    - " << a.yol / a.arac1Hiz << " saat, " << setprecision(0) << fixed << dakika << " dakika -" << endl << endl;
	}
	else if (a.problemTip == 2) {
		int toplamHiz = a.arac1Hiz + *(a.arac2Hiz);
		double dakika = a.yol % toplamHiz / (double)toplamHiz * 60;

		cout << endl;
		cout << "  - Bu tip h�z problemi ��z�mlerine A noktas�ndan kalkan ara�la B" << endl;
		cout << "    " << "noktas�ndan kalkan ara�lar�n h�z� toplanarak ba�lan�r. ��nk�" << endl;
		cout << "    " << "ikisinin birlikte kat etti�i bir mesafe s�z konusudur." << endl;
		cout << "    " << "�rne�imizde A noktas�ndan kalkan ara� saatte " << a.arac1Hiz << " km, B" << endl;
		cout << "    " << "noktas�ndan kalkan ara� ise " << *(a.arac2Hiz) << " km yol kat ediyor, birlikte bir" << endl;
		cout << "    " << "saatte " << toplamHiz << " km yol kat ediyorlar. �kisinin h�z� toplam� bir h�zla giden" << endl;
		cout << "    " << "bir arac�n A noktas�ndan B noktas�na gitti�ini d���nece�iz ve s�reyi" << endl;
		cout << "    " << "hesaplayaca��z. Yani 1'inci tip soru ��z�mleri gibi yol / hiz ile" << endl;
		cout << "    " << "devam ediyoruz. " << a.yol << " km uzunlu�undaki bir yolu iki arac�n toplam" << endl;
		cout << "    " << "h�z� olan " << toplamHiz << " de�erine b�ld���m�zde " << setprecision(2) << fixed << (double)a.yol / toplamHiz << " saat (yuvarlanm��) de�erine" << endl;
		cout << "    " << "ula��yoruz. Asl�nda buldu�umuz her iki arac�n kar��la�mas� i�in gereken" << endl;
		cout << "    " << "s�re. A noktas�ndan kalkan arac�n h�z�n� bu s�re ile �arpt���m�zda" << endl;
		cout << "    " << "kendisinin, B noktas�ndan kalkan arac�n h�z� ile bu s�reyi �arpt���m�zda" << endl;
		cout << "    " << "onun ka��nc� km'sinde kar��la�acaklar�n� buluruz. Yani A'daki " << a.arac1Hiz << "x" << setprecision(2) << fixed << (double)a.yol / toplamHiz << "," << endl;
		cout << "    " << "B'deki " << *(a.arac2Hiz) << "x" << setprecision(2) << fixed << (double)a.yol / toplamHiz << " km yol kat etmelidir." << endl << endl;
		cout << "    " << "Sonu�lar:" << endl;
		cout << "    " << "- �kisi de yola ��kt�ktan -" << a.yol / toplamHiz << " saat, " << setprecision(0) << fixed << dakika << "- sonra kar��la��rlar." << endl;
		cout << "    " << "- A'dan yola ��kan ara� " << setprecision(0) << fixed << a.arac1Hiz * (double)a.yol / toplamHiz << " km yol kat etmi�tir." << endl;
		cout << "    " << "- B'den yola ��kan ara� " << setprecision(0) << fixed << *(a.arac2Hiz) * (double)a.yol / toplamHiz << " km yol kat etmi�tir." << endl;
	}
	else if (a.problemTip == 3) {
		// Bu ��z�mde ek bir parametreye daha ihtiyac�m�z oldu�undan ve kullan�lmad���ndan
		// yol parametresini saat olarak assign ettik
		int saat = a.yol;
		int uzaklik = abs(a.arac1Hiz - *(a.arac2Hiz));
		cout << endl;
		cout << "  - Bu t�r h�z problemi ��z�mleri �ncekilerden daha kolayd�r, zira 2 arac�n" << endl;
		cout << "    " << "aras�nda 1 saatte olu�acak mesafe, ara�lar�n h�zlar�n�n birbirinden" << endl;
		cout << "    " << "��kar�lmas�yla bulunur, negatifse pozitife �evirilir. �rne�imizde" << endl;
		cout << "    " << "biri " << a.arac1Hiz << " ve " << *(a.arac2Hiz) << " km/sa h�zlar�ndaki iki ara�tan bahsediliyor." << endl;
		cout << "    " << "Aralar�ndaki h�z fark� ise " << uzaklik << " km/sa, yani 1 saatte aralar�nda" << endl;
		cout << "    " << "bu kadar mesafe olu�acak. Her saat de bu kadar artacak. Soruda verilen " << saat << " saat" << endl;
		cout << "    " << "de�eriyle uzakl��� �arpt���m�zda sonuca ula��yoruz." << endl;
		cout << "    " << "Sonu�:" << endl;
		cout << "    - " << saat * uzaklik << " saat -" << endl << endl;
	}
	else {
		cout << "***ERROR***" << endl;
	}
}
