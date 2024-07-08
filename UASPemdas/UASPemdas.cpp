#include <iostream>
#include <string>
using namespace std;

class MasukUniversitas {
protected:
	int uangPendaftaran;
	int uangSemesterPertama;
	int uangBangunan;
	int totalBiaya;

public:
	MasukUniversitas() {
		uangPendaftaran = 0;
		uangSemesterPertama = 0;
		uangBangunan = 0;
		totalBiaya = 0;
	}
	virtual void namaJalurMasuk() { return; }
	virtual string namaJalurMasuk() const = 0;
	virtual void hitungTotalBiaya() { return; }
	virtual void tampilkanTotalBiaya() { return; }
	virtual void input() { return; }

	void setUangPendaftaran(int nilai) {
		this->uangPendaftaran = nilai;
	}
	float getUangPendaftaran() {
		return uangPendaftaran;
	}

	void setUangSemesterPertama(int nilai) {
		this->uangSemesterPertama = nilai;
	}
	float getUangSemesterPertama() {
		return uangSemesterPertama;
	}

	void setUangBangunan(int nilai) {
		this->uangBangunan = nilai;
	}
	float getUangBangunan() {
		return uangBangunan;
	}

	void setTotalBiaya(int nilai) {
		this->totalBiaya = nilai;
	}
	float getTotalBiaya() {
		return totalBiaya;
	}
};

class SNBT : public MasukUniversitas {
public:
	string namaJalurMasuk() const override {
		return "SNBT";
	}

	void input() override {
		cout << "Masukan uang pendaftaran: ";
		cin >> uangPendaftaran;
		cout << "Masukan uang semester pertama: ";
		cin >> uangSemesterPertama;
		cout << "Masukan uang bangunan: ";
		cin >> uangBangunan;
	}

	void hitungTotalBiaya() override {
		totalBiaya = uangPendaftaran + uangSemesterPertama + uangBangunan;
	}

	void tampilkanTotalBiaya() override {
		cout << "Total Biaya: " << totalBiaya << endl;
		if (totalBiaya > 9110000)
			cout << "Kategori: Mahal" << endl;
		else if (totalBiaya > 5000000)
			cout << "Kategori: Sedang" << endl;
		else {
			cout << "Kategori: Murah" << endl;
		}
		cout << "Rekomendasi: Tidak Direkomendasikan";
	}
};

class SNBP : public MasukUniversitas {
public:
	string namaJalurMasuk() const override {
		return "SNBP";
	}

	void input() override {
		cout << "Masukan uang pendaftaran: ";
		cin >> uangPendaftaran;
		cout << "Masukan uang semester pertama: ";
		cin >> uangSemesterPertama;
	}
	void hitungTotalBiaya() override {
		totalBiaya = uangPendaftaran + uangSemesterPertama;
	}

	void tampilkanTotalBiaya() override {
		cout << "Total Biaya: " << totalBiaya << endl;
		if (totalBiaya > 9110000)
			cout << "Kategori: Mahal" << endl;
		else if (totalBiaya > 5000000)
			cout << "Kategori: Sedang" << endl;
		else {
			cout << "Kategori: Murah" << endl;
		}
		cout << "Rekomendasi: Dipertimbangkan";
	}
};

int main() {
	cout << "Pilih jalur masuk: " << endl;
	cout << "1. SNBT" << endl;
	cout << "2. SNBP" << endl;
	cout << "3. Keluar" << endl;
	int pilihan;
	cout << "Masukkan pilihan anda: ";
	cin >> pilihan;

	MasukUniversitas* jalurMasuk = nullptr;

	if (pilihan == 1) {
		jalurMasuk = new SNBT();
	}
	else if (pilihan == 2) {
		jalurMasuk = new SNBP();
	}
	else {
		cout << "Pilihan tidak valid" << endl;
		return 1;
	}
	jalurMasuk->input();
	jalurMasuk->hitungTotalBiaya();
	jalurMasuk->tampilkanTotalBiaya();

	delete jalurMasuk;
	return 0;
}