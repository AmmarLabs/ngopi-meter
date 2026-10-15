// Link Video : https://drive.google.com/drive/folders/1DlSPcNOeq9c1CpCrhBZilbV6a-a3mxD8?usp=sharing

#include <iostream>
#include <unordered_map>
#include <conio.h>
using namespace std;

// Memori sementara untuk menyimpan data user
unordered_map<string, string> userDatabase;

bool registerUser() {
    string username, password;
    cout << "Program Kopi Meter\n";
    cout << ">>> Registrasi Pengguna Baru!\n";
    cout << "Username Apa: "; cin >> username;

    // Looping validasi input password wajib >= 10 char
    do {
        cout << "Masukkan Passwordmu: "; cin >> password;

        if (password.length() < 10) {
            cout << "Password Kurang dari 10!!!\n";
        }
    } while (password.length() < 10);

    // Simpan kredensial ke hashmap
    userDatabase[username] = password;
    cout << "Password Sukses Dimasukkan\n";
    return true;
}

bool loginUser() {
    string username, password;
    
    // looping infinite sampai user memasukkan kredensial yg benar
    do {
        cout << ">> Menu Login <<\n";
        cout << "Username: ";
        cin >> username;
        cout << "Password: ";
        cin >> password;

        // Cek kecocokan username dan password
        auto it = userDatabase.find(username);
        if (it != userDatabase.end() && it->second == password)
        {
            return true;
        }

        cout << "[warning] - Antara User atau Pass Salah\n";
        cout << "\n";
    } while (true);
}

int main() {
    int pilihan, cangkirKopi;
    double efekNormal, efekTotal;

    if (registerUser()) {
        // Cuma lanjut ke login kalau registrasi sukses (return true)
        if (loginUser()) {
            do
            {
                system("cls"); // Clear console

                cout << ">>> Menu Program NgopiMeter <<<\n";
                cout << "1. Hitung Cangkir Kopi\n";
                cout << "2. Hitung Efek Kopi\n";
                cout << "3. Tingkat Produktivitas\n";
                cout << "4. Exit dari Program\n";
                cout << "Apa Pilihanmu: ";
                cin >> pilihan;

                switch (pilihan)
                {
                case 1:
                    cout << ">> Perhitungan Cangkir Kopi\n";
                    cout << "Berapa Kopi yang telah kamu minum?: ";
                    cin >> cangkirKopi;

                    // Validasi input minus / bukan angka
                    if (cin.fail() || cangkirKopi < 0) {
                        cin.clear();
                        cin.ignore(10000, '\n');
                        cout << "Kopinya Minus? Biar kutanyakan pada rumput yang bergoyang...\n";
                        break;
                    }

                    // Logika perhitungan cangkir kopi
                    if (cangkirKopi < 2)
                    {
                        cout << "Kurang fokus, bro\n";
                    }
                    else if (cangkirKopi >= 2 && cangkirKopi <= 4)
                    {
                        cout << "Produktif banget\n";
                    }
                    else
                    {
                        cout << "Hehe Jantungan Nih\n";
                    }
                    break;
                case 2:
                    cout << ">> Penghitung Efek Kafein Kopi\n";
                    cout << "Udah Berapa Cangkir: ";
                    cin >> cangkirKopi;

                    if (cin.fail() || cangkirKopi < 0)
                    {
                        cin.clear();
                        cin.ignore(10000, '\n');
                        cout << "Kopinya Minus? Biar kutanyakan pada rumput yang bergoyang...\n";
                        break;
                    }

                    // Hitung durasi efek kafein
                    efekNormal = cangkirKopi * 1.5;
                    efekTotal = cangkirKopi * 1.5 * 1.1;

                    cout << "Efek sadar normal: " << efekNormal << " jam\n";
                    cout << "Efek sadar total (termasuk mode fokus): " << efekTotal << " jam\n";
                    break;
                case 3:
                    cout << ">> Penghitung Tingkat Produktivitas\n";
                    cout << "Udah Berapa Cangkir: ";
                    cin >> cangkirKopi;

                    if (cin.fail() || cangkirKopi < 0)
                    {
                        cin.clear();
                        cin.ignore(10000, '\n');
                        cout << "Kopinya Minus? Biar kutanyakan pada rumput yang bergoyang...\n";
                        break;
                    }

                    efekTotal = cangkirKopi * 1.5 * 1.1;
                    if (efekTotal < 3)
                    {
                        cout << "Kurang optimal, tambahin kopi dikit lagi\n";
                    }
                    else if (efekTotal >= 3 && efekTotal <= 6)
                    {
                        cout << "Produktivitas stabil, jaga ritme\n";
                    }
                    else
                    {
                        cout << "Overdrive mode aktif! Tapi jangan lupa istirahat\n";
                    }
                    break;
                case 4:
                    cout << "Keluar dari program...\n";
                    break;
                default:
                    cout << "Input invalid, coba lagi!\n";
                    break;
                }

                // Hold console agar user bisa baca output
                if (pilihan != 4)
                {
                    cout << "Press any key to continue...\n";
                    getch(); // Tunggu input user
                }

            } while (pilihan != 4);
            
        } 
    } 

    return 0;
}