/****************************************************************************
**					SAKARYA UYGULAMALI BİLİMLER ÜNİVERSİTESİ
**			                      VERİ YAPILARI ÖDEVİ
**
**
**				ÖĞRENCİ ADI......:İSMAİL DEMİR
**				ÖĞRENCİ NUMARASI.:23210401403
**
****************************************************************************/


#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <tuple>

using namespace std;
using std::vector;
using std::string;

// Diskleri temsil eden karakter dizileri
vector<string> disk_sembol = { "", "*", "**", "***" };

// Direklerdeki disklerin durumu
vector<vector<int>> direk(3);

// Durumu çizmek için fonksiyon
void ciz_direk() {
    vector<string> direk_simge(3);
    for (int i = 0; i < 3; ++i) {
        direk_simge[i] = "| ";
        for (int j : direk[i]) {
            direk_simge[i] += disk_sembol[j] + " ";
        }
    }

    cout << "1: " << direk_simge[0] << "\n";
    cout << "2: " << direk_simge[1] << "\n";
    cout << "3: " << direk_simge[2] << "\n";
    cout << "----------------------\n";
}

void tasi_disk(int sayi, int bas, int bit, int diger) {
    if (sayi == 1) {
        cout << bas << " numarali direkten " << bit << " numarali direge tasi\n";
        int disk_ = direk[bas - 1].back();
        direk[bas - 1].pop_back();
        direk[bit - 1].push_back(disk_);
        ciz_direk();
        return;
    }
    tasi_disk(sayi - 1, bas, diger, bit);
    tasi_disk(1, bas, bit, diger);
    tasi_disk(sayi - 1, diger, bit, bas);
}

int adimSayisi = 0;

void Hanoi(int n, char kaynak, char ara, char hedef) {
    if (n == 1) {
        adimSayisi++; // Her adımda sayacı artırıyoruz
        cout << n << ". diski " << kaynak << " dan " << hedef << " ye tasi_______" << endl; return;
    }
    else {
        Hanoi(n - 1, kaynak, hedef, ara);
        adimSayisi++;
        cout << n << ". diski " << kaynak << " dan " << hedef << " ye tasi_______" << endl;
        Hanoi(n - 1, ara, kaynak, hedef);
    }
}


void tasima(char direkkk, char direk__, int diskkk) {
    cout << "diski tasi " << diskkk << " dan " << direkkk << " ye tasi_____ " << direk__ << endl;
}

// Hanoi kulelerini iteratif olarak çözme fonksiyonu
void iteratif(int disk_numarasi) {
    stack<tuple<int, char, char, char>> stack;
    bool cift = disk_numarasi % 2 == 0; // Disk sayısının çift olup olmadığını kontrol et

    char start_direk = 'A';
    char end_direk = 'C';
    char yedek_direk = 'B';

    if (cift) {
        swap(end_direk, yedek_direk);
    }

    stack.push(std::make_tuple(disk_numarasi, start_direk, end_direk, yedek_direk));

    while (!stack.empty()) {
        tuple<int, char, char, char> a = stack.top();
        stack.pop();

        int diskler_ = get<0>(a);
        char fromPeg = get<1>(a);
        char toPeg = get<2>(a);
        char auxPeg = get<3>(a);

        if (diskler_ == 1) {
            tasima(fromPeg, toPeg, diskler_);
        }
        else {
            stack.push(make_tuple(diskler_ - 1, auxPeg, toPeg, fromPeg));
            stack.push(make_tuple(1, fromPeg, toPeg, auxPeg));
            stack.push(make_tuple(diskler_ - 1, fromPeg, auxPeg, toPeg));
        }
    }
}

int main(int argc, char** argv)
{
    while (true) {
        cout << "1.Hanoi Kuleleri Problemi____ " << endl;
        cout << "2.Hanoi Kulelerinin iteratif cozumu____ " << endl;
        cout << "3.Grafiksel Gosterim____ " << endl;

        int secim;

        cout << " " << endl;
        cin >> secim;


        if (secim == 1) //Hanoi Kuleleri Problemi
        {

            int disk_sayisi;
            cout << "Disk Sayisi:";
            cin >> disk_sayisi;

            Hanoi(disk_sayisi, 'A', 'B', 'C');

            cout << "Toplam Adim Sayisi: " << adimSayisi << endl;

            cout << "Zaman Karmasikligi: O(2^n) -> O(2^" << disk_sayisi << ") = " << (1 << disk_sayisi) - 1 << endl;

            return 0;

        }



        else if (secim == 2) //Hanoi Kulelerinin iteratif cozumu
        {

            int disk__numarasi = 3;  // Değiştirmek isterseniz burayı değiştirebilirsiniz
            cout << "Hanoi Kulesi'ni Çözmek " << disk__numarasi << "iteratif yöntemle" << endl;
            iteratif(disk__numarasi);
            return 0;



        }

        else if (secim == 3) //Grafiksel Gosterim
        {

            int num_direk = 3;
            for (int i = num_direk; i >= 1; --i) {
                direk[0].push_back(i);
            }
            ciz_direk();
            tasi_disk(num_direk, 1, 3, 2);
            return 0;

        }

        else {
            cout << "!!!!!Hatali numara!!!!!"<<endl<<endl;
            
        }

    }

}

