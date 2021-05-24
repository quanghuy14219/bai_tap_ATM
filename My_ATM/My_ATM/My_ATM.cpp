#include "My_ATM.h"
void My_ATM::dangky() {
	cout << "Loading ... 99%";
	Sleep(500);
	system("cls");
	cout << endl;
	fstream f;
	//nhập tên đăng nhập
	cout << endl;
	cout << "Ten dang nhap cua ban:" << endl;
	string username;
	cin >> username;

	fstream ff;
	ff.open("Username_list.txt", ios::in);
	bool check = false;
	string name;
	while (!ff.eof()) {
		ff >> name;
		if (name == username) {
			check = true;
			break;
		}
	}
	ff.close();

	if (check) {
		cout << "  Ten dang nhap da ton tai!" << endl
			<< "Vui long dang ky voi ten khac!" << endl;
		Sleep(800);
		dangky();
		return;
	}
	else {
		fstream ff;
		//ghi ten dang nhap vao danh sach username
		ff.open("Username_list.txt", ios::app);
		ff << username << endl;
		ff.close();
		//tạo file người dùng
		string usernametxt = username + ".txt";
		f.open(usernametxt.c_str(), ios::out);
		//tạo file lịch sử của người dùng
		string lichsu = "ls" + usernametxt;
		fstream fff;
		fff.open(lichsu.c_str(), ios::out);
		fff << left << setw(75) << "DANG KY" << thoidiem() << endl;
		fff.close();
		//tao file khoa tai khoan
		fstream fk;
		fk.open(("k" + username + ".txt").c_str(), ios::out);
		fk << 1 << endl;
		fk << 5;
		fk.close();
		//nhap pass - ma PIN
		string PIN;
		bool checkmk = true;
		do {
			if (!checkmk) {
				cout << "Mat khau cua ban khong hop le" << endl
					<< "Vui long doc ki luu y va nhap lai mat khau khac" << endl;
				Sleep(1500);
			}
			system("cls");
			cout << "Mat khau moi la:" << endl;
			cout << "(Luu y: Mat khau phai gom 6 so tu nhien tu 0 den 9)" << endl;
			cin >> PIN;
			if (PIN.length() != 6) checkmk = false;
			else {
				checkmk = true;
				for (int i = 0; i < 6; i++) {
					if (PIN[i] > '9' || PIN[i] < '0') checkmk = false;
				}
			}
		} while (!checkmk);
		f << PIN << endl;
		//nhap so tien so huu ban dau
		long long money = 0;
		f << money << endl;
		f.close();
		//vao giao dien nguoi dung
		gduser(username);
	}
}
void My_ATM::dangnhap() {
	cout << "Loading ... 99%";
	Sleep(500);
	system("cls");
	cout << endl;
	cout << "Xin hay nhap ten dang nhap cua ban" << endl;
	string username;
	cin >> username;

	fstream ff;
	ff.open("Username_list.txt", ios::in);
	bool check = false;
	string name;
	while (!ff.eof()) {
		ff >> name;
		if (name == username) {
			check = true;
			break;
		}
	}
	ff.close();

	if (!check) {
		cout << "Loading ... 69%";
	A:
		Sleep(500);
		system("cls");
		cout << endl;
		cout << "Ten dang nhap cua ban khong ton tai!" << endl
			<< "Ban co muon nhap lai khong" << endl
			<< "1, Co" << endl
			<< "2, Khong" << endl;

		int choose;
		cin >> choose;
		if (choose == 2) {
			gd1();
		}
		else if (choose == 1) {
			dangnhap();
		}
		else {
			cout << "Chuc nang khong hop le";
			goto A;
		}

	}
	else {
		//check xem tai khoan co bi khoa?
		fstream fk;
		fk.open(("k" + username + ".txt").c_str(), ios::in);
		int check;
		fk >> check;
		fk.close();
		if (check) nhapmk(username);
		else {
			system("cls");
			cout << endl;
			cout << "Tai khoan cua ban da bi khoa!" << endl
				<< "Vui long lien he admin de giai quyet van de" << endl;
			Sleep(2000);

			gd1();
		}
	}
}
void My_ATM::nhapmk(string username) {
	int solannhapconlai;
	fstream fk;
	fk.open(("k" + username + ".txt").c_str(), ios::in);
	int check;
	fk >> check;
	fk >> solannhapconlai;
	solannhapconlai--;
	fk.close();

	cout << "Loading ... 99%";
	Sleep(500);
	system("cls");
	cout << endl;
	cout << "   Nhap mat khau:" << endl;
	cout << "(Luu y: Neu ban nhap mat khau sai qua " << solannhapconlai + 1 << " lan, tai khoan cua ban se bi khoa)" << endl;
	string pin;
	cin >> pin;

	fstream f;
	string filename = username + ".txt";
	f.open(filename.c_str(), ios::in);
	string PIN;
	f >> PIN;

	while (pin != PIN && solannhapconlai > 0) {
		A:
		system("cls");
		cout << "Mat khau sai!" << endl
			<< "Ban co muon nhap lai mat khau khong" << endl
			<< "1, Co" << endl
			<< "2, Khong" << endl;
		int choose;
		cin >> choose;
		if (choose == 2) {

			fstream fk;
			fk.open(("k" + username + ".txt").c_str(), ios::out);
			fk << 1 << endl;
			fk << solannhapconlai;
			fk.close();
			gd1();
		}
		else {
			if (choose == 1) {
				system("cls");
				cout << endl;
				cout << "Ban con " << solannhapconlai << " lan nhap nua" << endl;
				cin >> pin;
				solannhapconlai--;
			}
			else {
				cout << "Chuc nang khong hop le, xin hay lua chon lai chuc nang khac" << endl;
				Sleep(1000);
				goto A;
			}
		}
	}
	if (solannhapconlai <= 0) {
		cout << endl;
		cout << "Tai khoan cua ban da bi khoa" << endl;
		Sleep(2000);
		// luu vao file khoa
		fstream fk;
		fk.open(("k" + username + ".txt").c_str(), ios::out);
		fk << 0;
		fk.close();
		// luu vao lich su
		string lichsu = "ls" + username + ".txt";
		fstream ffk;
		ffk.open(lichsu.c_str(), ios::app);
		ffk << left << setw(75) << "KHOA TAI KHOAN" << thoidiem() << endl;
		ffk.close();

		gd1();
	}
	else {
		// luu vao lich su
		string lichsu = "ls" + username + ".txt";
		fstream fff;
		fff.open(lichsu.c_str(), ios::app);
		fff << left << setw(75) << "DANG NHAP" << thoidiem() << endl;
		fff.close();
		// chinh lai file khoa 
		fstream fk;
		fk.open(("k" + username + ".txt").c_str(), ios::out);
		fk << 1 << endl;
		fk << 5;
		fk.close();

		gduser(username);
	}
}
void My_ATM::gd0() {
	cout << endl << "    Chao mung ban den voi ATM cua Huy" << endl
		<< "  Chuc ban co mot ngay tot lanh (^-^)!!!  ";
	Sleep(1000);
	system("cls");
	gd1();
}
void My_ATM::gd1() {
A:
	system("cls");
	cout << endl << "Chung toi co the giup gi cho ban?" << endl
		<< " 1, Dang nhap" << endl
		<< " 2, Dang ky" << endl
		<< " 3, Lien he admin" << endl
		<< " 4, Thoat" << endl;
	int choose;
	cin >> choose;
	if (choose == 1) dangnhap();
	else if (choose == 2) dangky();
	else if (choose == 4) gdquit();
	else if (choose == 3) gdadmin();
	else {
		cout << " Chuc nang khong xac dinh, vui long chon lai!" << endl;
		Sleep(1000);
		goto A;
	}
}
void My_ATM::gdadmin() {
A:
	system("cls");
	cout << endl;
	cout << "ADMIN: NGUYEN QUANG HUY" << endl
		<< "MA FBI: 20021367" << endl
		<< "HOTLINE: 0968521211" << endl
		<< endl
		<< "Nhan 0 de quay lai";
	int choose;
	cin >> choose;
	if (choose == 0) gd1();
	if (choose == 1) {
	C:
		system("cls");
		cout << "Nhap username bi khoa:" << endl;
		string username;
		cin >> username;
		fstream ff;
		ff.open("Username_list.txt", ios::in);
		bool check = false;
		string name;
		while (!ff.eof()) {
			ff >> name;
			if (name == username) {
				check = true;
				break;
			}
		}
		ff.close();
		if (!check) {
		B:
			system("cls");
			cout << endl;
			cout << "Ten dang nhap cua ban khong ton tai!" << endl
				<< "Ban co muon nhap lai khong" << endl
				<< "1, Co" << endl
				<< "2, Khong" << endl;
			int choose;
			cin >> choose;
			if (choose == 2) {
				gd1();
			}
			else if (choose == 1) {
				goto C;
			}
			else {
				cout << "Chuc nang khong hop le";
				Sleep(500);
				goto B;
			}
		}
		else {
			unlocktk(username);
			gd1();
		}
	}
	else {
		cout << "Chuc nang khong hop le!" << endl;
		Sleep(500);
		goto A;
	}
}
void My_ATM:: unlocktk(string username) {
	// luu vao file khoa
	fstream fk;
	fk.open(("k" + username + ".txt").c_str(), ios::out);
	fk << 1 << endl << 5;
	fk.close();
	// luu vao lich su
	string lichsu = "ls" + username + ".txt";
	fstream ffk;
	ffk.open(lichsu.c_str(), ios::app);
	ffk << left << setw(75) << "MO KHOA TAI KHOAN" << thoidiem() << endl;
	ffk.close();
}
void My_ATM::gdquit() {
	system("cls");
	cout << endl;
	cout << "   Rat cam on ban da tin dung dich vu cua chung toi!!!";
	Sleep(1200);
}
void My_ATM::gduser(string username)
{
A:
	system("cls");
	cout << endl;
	cout << "Xin chao " << username << "!!" << endl
		<< "So du cua ban la: ";
	fstream f;
	string usernametxt = username + ".txt";
	f.open(usernametxt.c_str(), ios::in);
	string PIN;
	long long balance = 0;
	f >> PIN;
	f >> balance;
	cout << balance << " VND" << endl
		<< "1, Nap tien bang nop tien mat" << endl
		<< "2, Rut tien" << endl
		<< "3, Chuyen khoan" << endl
		<< "4, Xem lich su giao dich" << endl
		<< "5, Doi mat khau" << endl
		<< "6, Dang xuat" << endl;
	f.close();
	int choose;
	cin >> choose;
	if (choose == 1) naptien(username, PIN, balance);
	else if (choose == 2) ruttien(username, PIN, balance);
	else if (choose == 3) chuyenkhoan(username, PIN, balance);
	else if (choose == 4) xemlichsugd(username);
	else if (choose == 6) gd1();
	else if (choose == 5) doimatkhau(username, PIN, balance);
	else {
		cout << " Chuc nang khong hop le" << endl;
		Sleep(500);
		goto A;
	}
}
void My_ATM::naptien(string& username, string& PIN, long long& balance) {
A:
	system("cls");
	cout << endl;
	cout << "Chon menh gia tien ban muon nop" << endl
		<< "( Luu y: Menh gia toi thieu la 10,000 VND )" << endl
		<< "1,10,000 VND" << endl
		<< "2,20,000 VND" << endl
		<< "3,50,000 VND" << endl
		<< "4,100,000 VND" << endl
		<< "5,200,000 VND" << endl
		<< "6,500,000 VND" << endl;
	int choose;
	cin >> choose;
	if (choose == 1) {
		congtienvaotk(username, PIN, balance, 10000);
	}
	else if (choose == 2) {
		congtienvaotk(username, PIN, balance, 20000);
	}
	else if (choose == 3) {
		congtienvaotk(username, PIN, balance, 50000);
	}
	else if (choose == 4) {
		congtienvaotk(username, PIN, balance, 100000);
	}
	else if (choose == 5) {
		congtienvaotk(username, PIN, balance, 200000);
	}
	else if (choose == 6) {
		congtienvaotk(username, PIN, balance, 500000);
	}
	else {
		cout << "Chuc nang khong hop le";
		Sleep(500);
		goto A;
	}
}
void My_ATM::congtienvaotk(string& username, string& PIN, long long& balance, long long menhgia) {
	system("cls");
	cout << endl;
	long long soto;
	cout << "So to ban muon nop la: ";
	cin >> soto;

	cout << "Xin hay de tien vao khay! " << endl;
	Sleep(500);
	cout << "Dang kiem tra tien ..." << endl;
	Sleep(1000);
	cout << "Nap thanh cong!" << endl;
	Sleep(1000);
	balance += menhgia * soto;
	//luu vao lich su
	string lichsu = "ls" + username + ".txt";
	fstream fff;
	fff.open(lichsu.c_str(), ios::app);
	fff << left << setw(75) << ("NAP TIEN: +" + to_string(menhgia * soto) + " VND, SO DU: " + to_string(balance) + " VND") << thoidiem() << endl;
	fff.close();
	// luu vao so to trong may 
	thaydoisoto(menhgia, soto);
	// luu lai thong tin nguoi dung
	fstream f;
	f.open((username + ".txt").c_str(), ios::out);
	f << PIN << endl << balance;
	f.close();

A:
	system("cls");
	cout << "Ban co muon nap them khong?" << endl
		<< "1, Co " << endl
		<< "2, Khong " << endl;
	int choose;
	cin >> choose;
	if (choose == 1) naptien(username, PIN, balance);
	else if (choose == 2) gduser(username);
	else {
		cout << "Chuc nang khong hop le" << endl;
		Sleep(500);
		goto A;
	}
}
void My_ATM::ruttien(string& username, string& PIN, long long& balance) {
	system("cls");
	cout << endl;
	cout << "So du hien tai cua ban la: " << balance << endl;
	cout << "Nhap so tien ban muon rut: " << endl
		<< "(Luu y: So tien rut ra phai la boi so cua 10000 VND)" << endl;

	long long money;
	cin >> money;
	while (money % 10000 != 0) {
		system("cls");
		cout << "So tien rut ra khong hop le" << endl
			<< "(Luu y: So tien rut ra phai la boi so cua 10000 VND)" << endl
			<< "Nhap lai so tien muon rut" << endl;
		cin >> money;
	}
	if (money > balance) {
	A:
		system("cls");
		cout << "So du cua ban khong du" << endl;
		cout << "Ban co muon rut lai khong?" << endl
			<< "1, Co " << endl
			<< "2, Khong " << endl;
		int choose;
		cin >> choose;
		if (choose == 1) ruttien(username, PIN, balance);
		else if (choose == 2) gduser(username);
		else {
			cout << "Chuc nang khong hop le" << endl;
		Sleep(500);
		goto A;
		}
	}
	else {
		
		int t500, t200, t100, t50, t20, t10;
		int k500, k200, k100, k50, k20, k10;// so to co san trong ATM
		fstream f;
		f.open("Tienvasoto.txt", ios::in);
		f >> k10 >> k20 >> k50 >> k100 >> k200 >> k500;
		f.close();
		long long sum = (long long)k10 * 10000 + (long long)k20 * 20000 + (long long)k50 * 50000 + (long long)k100 * 100000 + (long long)k200 * 200000 + (long long)k500 * 500000;
		if (sum > money) {

			long long moneyreal;
			long long money1 = money;
			
			// greedy algorithm
			t500 = sotorutra(money, 500000, k500);
			t200 = sotorutra(money, 200000, k200);
			t100 = sotorutra(money, 100000, k100);
			t50 = sotorutra(money, 50000, k50);
			t20 = sotorutra(money, 20000, k20);
			t10 = sotorutra(money, 10000, k10);
			// luu lai so to 
			fstream ff;
			ff.open("Tienvasoto.txt", ios::out);
			ff << k10 << endl
				<< k20 << endl
				<< k50 << endl
				<< k100 << endl
				<< k200 << endl
				<< k500 << endl;
			ff.close();

			// kiem lai so tien rut duoc
			moneyreal = (long long)t10 * 10000 + (long long)t20 * 20000 + (long long)t50 * 50000 + (long long)t100 * 100000 + (long long)t200 * 200000 + (long long)t500 * 500000;
			if (moneyreal < money1) {
				system("cls");
				cout << endl;
				cout << "Mong ban thong cam vi so to tien trong cay ATM co gioi han" << endl
					<< "So tien ban muon rut la " << money1 << endl
					<< "So tien ban rut duoc la " << moneyreal << endl;
			}
			balance -= moneyreal;

			// luu vao lich su 
			string lichsu = "ls" + username + ".txt";
			fstream fff;
			fff.open(lichsu.c_str(), ios::app);
			fff << left << setw(75) << ("TRU TIEN: -" + to_string(moneyreal) + " VND, so du: " + to_string(balance) + " VND") << thoidiem() << endl;
			fff.close();
			// luu lao thong tin nguoi dung
			fstream fu;
			fu.open((username + ".txt").c_str(), ios::out);
			fu << PIN << endl << balance;
			fu.close();

			cout << "  So tien ban nhan duoc gom " << endl
				<< t500 << " to menh gia 500000 VND" << endl
				<< t200 << " to menh gia 200000 VND" << endl
				<< t100 << " to menh gia 100000 VND" << endl
				<< t50 << " to menh gia 50000 VND" << endl
				<< t20 << " to menh gia 20000 VND" << endl
				<< t10 << " to menh gia 10000 VND" << endl
				<< "Vui long kiem tra lai truoc khi tiep tuc!" << endl
				<< "Neu co van de gi xin lien he voi admin" << endl
				<< "Nhan 1 de tiep tuc" << endl;
			int choose;
			cin >> choose;
			gduser(username);
		}
		else {
		C:
			system("cls");
			cout << "Tong so tien trong cay ATM la: " << sum << " VND, khong dap ung duoc so tien cua ban!" << endl
				<< "Mong ban thong cam va lien he admin hoac rut so tien nho hon!" << endl
				<< "1, Rut tien lai" << endl
				<< "2, Quay lai";
			int choose;
			cin >> choose;
			if (choose == 1) ruttien(username, PIN, balance);
			else if (choose == 2) gduser(username);
			else {
				cout << "Chuc nang khong hop le" << endl;
				Sleep(500);
				goto C;
			}
		}
	}

}
int My_ATM::sotorutra(long long& money, long long menhgia, int& sotocosan) {
	int soto;
	if (sotocosan * menhgia <= money) soto = sotocosan;
	else soto = (int)(money / menhgia);
	money -= soto * menhgia;
	sotocosan -= soto;
	return soto;
}
void My_ATM::chuyenkhoan(string& username, string& PIN, long long& balance) {
	system("cls");
	cout << endl;
	cout << "Nhap ten dang nhap cua nguoi ban muon chuyen khoan" << endl;
	string username1;
	cin >> username1;
	fstream ff;
	ff.open("Username_list.txt", ios::in);
	bool check = false;
	string name;
	while (!ff.eof()) {
		ff >> name;
		if (name == username1) {
			check = true;
			break;
		}
	}
	ff.close();
	if (!check) {
		cout << "Loading ... 69%";
		Sleep(500);
	A:
		system("cls");
		cout << "Ten dang nhap khong ton tai!" << endl
			<< "Ban co muon nhap lai khong" << endl
			<< "1, Co" << endl
			<< "2, Khong" << endl;
		int choose;
		cin >> choose;
		if (choose == 2) {
			gduser(username);
		}
		else {
			if (choose == 1) {
				chuyenkhoan(username, PIN, balance);
			}
			else {
				cout << "Chuc nang khong hop le" << endl;
				Sleep(500);
				goto A;
			}
		}
	}
	else {
		fstream fff;
		fff.open((username1 + ".txt").c_str(), ios::in);
		string PIN1;
		long long balance1;
		fff >> PIN1;
		fff >> balance1;
		fff.close();
		long long money;
		cout << "Nhap so tien ban muon chuyen: " << endl
			<< "(Luu y: So tien muon chuyen phai la boi so cua 10000 VND)" << endl;
		cin >> money;
		cout << endl;
		if (money > balance) {

		B:
			system("cls");
			cout << "So du khong du"<< endl;
			cout << "Ban co muon thuc hien giao dich khac khong?" << endl
				<< "1, Co " << endl
				<< "2, Khong " << endl;
			int choose;
			cin >> choose;
			if (choose == 1) chuyenkhoan(username, PIN, balance);
			else if (choose == 2) gduser(username);
			else {
				cout << "Chuc nang khong hop le" << endl;
				Sleep(500);
				goto B;
			}
		}
		else {
			balance -= money;
			// luu vao lich su
			string lichsu = "ls" + username + ".txt";
			fstream fff1;
			fff1.open(lichsu.c_str(), ios::app);
			fff1 << left << setw(75) << ("CHUYEN KHOAN DEN " + username1 + ": -" + to_string(money) + " VND, SO DU: " + to_string(balance) + " VND") << thoidiem() << endl;
			fff1.close();

			balance1 += money;
			// luu vao lich su
			string lichsu1 = "ls" + username1 + ".txt";
			fstream fffff;
			fffff.open(lichsu1.c_str(), ios::app);
			fffff << left << setw(75) << ("CHUYEN KHOAN TU " + username + ": +" + to_string(money) + " VND, SO DU: " + to_string(balance1) + " VND") << thoidiem() << endl;
			fffff.close();

			fstream f;
			f.open((username + ".txt").c_str(), ios::out);
			f << PIN << endl << balance;
			f.close();

			fstream ffff;
			ffff.open((username1 + ".txt").c_str(), ios::out);
			ffff << PIN1 << endl << balance1;
			ffff.close();

			cout << "Loading 99% " << endl;
			Sleep(1000);
			cout << "Giao dich thanh cong!" << endl;
			Sleep(1000);

			gduser(username);
		}
	}
}
void My_ATM::xemlichsugd(string& username) {
	system("cls");
	cout << endl;
	cout << "Lich su giao dich cua ban:" << endl;
	fstream f;
	string lichsu = "ls" + username + ".txt";
	f.open(lichsu.c_str(), ios::in);
	string line;
	while (!f.eof()) {
		getline(f, line);
		cout << line << endl;
	}
	cout << endl << "Nhan so 0 de quay lai" << endl;
	int choose;
	cin >> choose;
	gduser(username);
}
string My_ATM::thoidiem() {
	time_t now = time(0);
	char* dt = new char[26];
	errno_t erro = ctime_s(dt, 26, &now);
	string time_now(dt);
	return time_now;
}
long long My_ATM::sotonow(long long menhgia) {
	fstream f;
	f.open("Tienvasoto.txt", ios::in);
	int k10, k20, k50, k100, k200, k500;
	f >> k10 >> k20 >> k50 >> k100 >> k200 >> k500;
	f.close();
	if (menhgia == 10000) return k10;
	if (menhgia == 20000) return k20;
	if (menhgia == 50000) return k50;
	if (menhgia == 100000) return k100;
	if (menhgia == 200000) return k200;
	if (menhgia == 500000) return k500;
	else {
		cout << "Menh gia khong ton tai" << endl;
		return 0;
	}
}
void My_ATM::thaydoisoto(long long menhgia, long long soto) {
	fstream f;
	f.open("Tienvasoto.txt", ios::in);
	long long k10, k20, k50, k100, k200, k500;
	f >> k10 >> k20 >> k50 >> k100 >> k200 >> k500;
	f.close();
	if (menhgia == 10000) k10 += soto;
	if (menhgia == 20000) k20 += soto;
	if (menhgia == 50000) k50 += soto;
	if (menhgia == 100000) k100 += soto;
	if (menhgia == 200000) k200 += soto;
	if (menhgia == 500000) k500 += soto;
	fstream ff;
	ff.open("Tienvasoto.txt", ios::out);
	ff << k10 << endl
		<< k20 << endl
		<< k50 << endl
		<< k100 << endl
		<< k200 << endl
		<< k500 << endl;
	ff.close();
}
void My_ATM::doimatkhau(string& username, string& PIN, long long& balance) {
	system("cls");
	cout << endl;
	cout << "Nhap mat khau cu cua ban: " << endl;
	string pin;
	cin >> pin;
	if (pin != PIN) {
	A:
		system("cls");
		cout << "Mat khau sai" << endl
			<< "Ban co muon nhap lai khong?" << endl
			<< "1, Co" << endl
			<< "2, Khong" << endl;
		int choose;
		cin >> choose;
		if (choose == 1) doimatkhau(username, PIN, balance);
		if (choose == 2) gduser(username);
		else {
			cout << "Chuc nang khong hop le" << endl;
			Sleep(500);
			goto A;
		}
	}
	else {
		system("cls");
		cout << "Nhap mat khau moi:" << endl;
		bool checkmk = true;
		do {
			if (!checkmk) {
				cout << "Mat khau cua ban khong hop le" << endl
					<< "Vui long doc ki luu y va nhap lai mat khau khac" << endl;
				Sleep(1500);
			}
			system("cls");
			cout << "Mat khau moi la:" << endl;
			cout << "(Luu y: Mat khau phai gom 6 so tu nhien tu 0 den 9)" << endl;
			cin >> PIN;
			if (PIN.length() != 6) checkmk = false;
			else {
				checkmk = true;
				for (int i = 0; i < 6; i++) {
					if (PIN[i] > '9' || PIN[i] < '0') checkmk = false;
				}
			}
		} while (!checkmk);
		fstream f;
		f.open((username + ".txt").c_str(), ios::out);
		f << PIN << endl << balance;
		f.close();
		cout << "Doi mat khau thanh cong!!!";
		Sleep(1500);
		gduser(username);
	}
}