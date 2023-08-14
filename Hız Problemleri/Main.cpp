/*
HIZ PROBLEMLERİ
-	Yazılım, genel anlamda OOP, detayda ptr, const ve metoda nesne parametrelerini geçirme pratiği projesidir.
-	Matematik derslerinde öğretilen 3 ayrı tip hız problemi çözer ve çözümü anlatır.
-	Sonucu 2.78 saat vb. değil, saat ve dakika cinsinden verir,
-	Dakika küsuratları yuvarlanır.
-	Başta nesneye değer olarak atanan değerler, sonrasında switch/case yapısı kullanılarak
	hazırlanan çözüm işlemlerinde const getterlar çağırılarak çözülür ve çözüm anlatılır.
-	* Hız problemini çözmek için bu veya başka bir kaynağı kullanacak olan öğrencilere not:
	Konuyu ve çözümü anlamayı deneyin, olmazsa tekrar çalışın, okuyun, dinleyin, öğrenin.
	Anlamadan, ezberden yapılan çözümler başınıza mutlaka dert olacaktır.
*/


#include "Problem.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "Turkish");

	int problemTip = 0, yol = 0, arac1Hiz = 0, arac2Hiz = 0;

	cout << " - HIZ PROBLEMLERİ - " << endl << endl;
	cout << " 1. Bir araç A noktasından B noktasında x hızla kaç saatte gider?" << endl << endl;
	cout << " 2. Biri A, diğeri B noktasından birbirine doğru gelen x ve y" << endl
		<< "    hızlarında 2 araç, nerede kilometresinde karşılaşır veya" << endl
		<< "    karşılaşmaları kaç saat, kaç dakika sürer?" << endl << endl;
	cout << " 3. Aynı noktadan farklı hızlarda hareket eden 2 aracın arası x saat" << endl
		<< "    sonra kaç km olur?" << endl << endl;
	cout << " Lütfen problem tipinizi seçin: ";
	cin >> problemTip;

	Problem a0(0, 0, 0, 0);

	switch (problemTip) {
	case 1:
	{
		cout << "  - Lütfen yol uzunluğunu girin (km): ";
		cin >> yol;
		cout << "  - Lütfen araç hızını girin (km/sa): ";
		cin >> arac1Hiz;
		Problem a1(1, yol, arac1Hiz, 0);
		a0.problemiCoz(a1);
	}break;
	case 2: {
		cout << "  - Lütfen yol uzunluğunu girin (km): ";
		cin >> yol;
		cout << "  - Lütfen A noktasındaki araç hızını girin (km/sa): ";
		cin >> arac1Hiz;
		cout << "  - Lütfen B noktasındaki araç hızını girin (km/sa): ";
		cin >> arac2Hiz;
		Problem a2(2, yol, arac1Hiz, arac2Hiz);
		a0.problemiCoz(a2);
	}break;
	case 3: {
		cout << "  - Lütfen ilk aracın hızını girin (km/sa): ";
		cin >> arac1Hiz;
		cout << "  - Lütfen ikinci aracın hızını girin (km/sa): ";
		cin >> arac2Hiz;
		cout << "  - Lütfen verilen saati tam sayı olarak girin: ";
		cin >> yol;
		Problem a3(3, yol, arac1Hiz, arac2Hiz);
		a0.problemiCoz(a3);
	}break;
	default: break;
	}

	return 0;
}
