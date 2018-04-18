#include<string>
#include<iostream>
#include<algorithm>
#include<cstdio>

using namespace std;

struct zespol{
	string nazwa;
	int gole;
	int stracone;
	int wygrane, remis, przegrane;
};

bool porownanie(zespol A, zespol B){
	int PA, PB;
	PA = A.wygrane * 3 + A.remis;
	PB = B.wygrane * 3 + B.remis;
	if (PA > PB) return true;
	if (PB > PA) return false;
	if (A.wygrane > B.wygrane)	return true;
	if (A.wygrane < B.wygrane)	return false;
	if (A.gole - A.stracone>B.gole - B.stracone) return true;
	if (A.gole - A.stracone<B.gole - B.stracone) return false;
	if (A.gole > B.gole) return true;
	if (A.gole < B.gole) return false;
	PA = A.wygrane + A.remis + A.przegrane;
	PB = B.wygrane + B.remis + B.przegrane;
	if (PA > PB) return false;
	if (PA < PB) return true;
	for (int i = 0; ; ++i){ // ignore case
		char a = A.nazwa[i];
		char b = B.nazwa[i];
		if (a >= 'A' && a <= 'Z') a += 32;
		if (b >= 'A' && b <= 'Z') b += 32;
		if (a == '\0')	return true;
		if (b == '\0')	return false;
		if (a > b)	return false;
		if (a < b)	return true;
	}
}
int main(){
	int N;
	cin >> N;
	(void)getchar();
	while (N--){
		zespol druzyna[30];
		string nazwaTurnieju;
		getline(cin, nazwaTurnieju);
		int iloscDruzyn, iloscMeczy;
		cin >> iloscDruzyn;
		(void)getchar();
		for (int i = 0; i < iloscDruzyn; ++i){
			getline(cin, druzyna[i].nazwa);
			druzyna[i].stracone = druzyna[i].gole = druzyna[i].przegrane = druzyna[i].remis = druzyna[i].wygrane = 0;
		}
		cin >> iloscMeczy;
		(void)getchar();
		for (int i = 0; i < iloscMeczy; ++i){
			int a, AS = 0, BS = 0;
			string R, A, B;
			getline(cin, R);
			for (a = 0; R[a] != '#'; a++)
                A.push_back(R[a]);
			for (a++; R[a] != '@'; a++)
                AS = AS * 10 + R[a] - '0';
			for (a++; R[a] != '#'; a++)
                BS = BS * 10 + R[a] - '0';
			for (a++; R[a] != '\0'; a++)
                B.push_back(R[a]);
			for (int j = 0; j < iloscDruzyn; ++j){
				if (druzyna[j].nazwa == A){
					druzyna[j].gole += AS;
					druzyna[j].stracone += BS;
					if (AS > BS)	druzyna[j].wygrane++;
					if (AS == BS)	druzyna[j].remis++;
					if (AS < BS)	druzyna[j].przegrane++;
				}
				if (druzyna[j].nazwa == B){
					druzyna[j].gole += BS;
					druzyna[j].stracone += AS;
					if (AS < BS)	druzyna[j].wygrane++;
					if (AS == BS)	druzyna[j].remis++;
					if (AS > BS)	druzyna[j].przegrane++;
				}
			}
		}
		sort(druzyna, druzyna + iloscDruzyn, porownanie);
		cout << nazwaTurnieju << endl;
		for (int i = 0; i < iloscDruzyn; i++){
			cout << i + 1 << ") " << druzyna[i].nazwa << " " << druzyna[i].wygrane * 3 + druzyna[i].remis << "p, "
                 << druzyna[i].wygrane + druzyna[i].przegrane + druzyna[i].remis << "g (" << druzyna[i].wygrane << "-" << druzyna[i].remis << "-" << druzyna[i].przegrane << "), "
                 << druzyna[i].gole - druzyna[i].stracone << "gd (" << druzyna[i].gole << "-" << druzyna[i].stracone << ")" << endl;
		}
		if (N != 0)
			cout << endl;
	}
	return 0;
}
