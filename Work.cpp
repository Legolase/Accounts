#include <iostream>
#include "stdio.h"
#include "conio.h"
#include <string>
#include <vector>
#include <random>
#include <fstream>
#include <filesystem>
#include <windows.h>
#include <ctime>

using namespace std;
namespace fs = std::filesystem;

int rand(int min, int max) {
	mt19937 gen{ random_device()() };
	uniform_int_distribution<int> dist(min, max);
	return dist(gen);
}
//

//work files
//const string home = "\\\\NIKITA-LAPTOP\\Game";
const string home = "c:\\\\Game";
const string dir_clients = home + "\\Clients";
const string file_clients = home + "\\Accounts.txt";
const string warns = home + "\\Warnings.txt";
const string info_client = "\\Information.txt";
const string permit_commands_ca = home + "\\Permissions\\Cool Admin.txt";
const string permit_commands_a = home + "\\Permissions\\Admin.txt";
const string permit_commands_g = home + "\\Permissions\\Gamer.txt";
const string ban = home + "\\Ban.txt";
const string shop = home + "\\Shop.txt";
const string purchase = "\\Purchase.txt";
const string persent_of_casino = home + "\\Casino persent.txt";
const string dictionary = home + "\\Dictionary.txt";
const string dir_messenger = "\\Messenger";
const string file_messenger = dir_messenger + "\\Clients.txt";
const string file_black_list = "\\Black_list.txt";
const string mi_shop = "\\My_shop.txt";
const string file_news = home + "\\News.txt";
const string new_messeges = dir_messenger + "\\New_messege.txt";
const string file_preparation = "\\Prepar.txt";
const string craft = home + "\\Crafting.txt";

//warnings
const int w_login = 0;
const int w_password = 1;
const int w_no_log = 2;
const int w_change_login = 3;
const int w_no_password = 4;
const int w_not_found_login = 5;
const int w_successful_regist = 6;
const int w_incorrect_password = 7;
const int w_no_permissions = 8;
const int w_balance = 9;
const int w_no_clients = 10;
const int w_coin = 11;
const int w_no_purchase = 12;
const int w_ask_number = 13;
const int w_low_int = 14;
const int w_no_int = 15;
const int w_not_enough_money = 16;
const int w_successful_buying = 17;
const int w_you_buy = 18;
const int w_no_buying = 19;
const int w_not_right_index = 20;
const int w_success_sale = 21;
const int w_ask_stack = 22;
const int w_you_lose = 23;
const int w_you_win = 24;
const int w_level = 25;
const int w_not_right = 26;
const int w_right = 27;
const int w_false = 28;
const int w_translate_from = 29;
const int w_status = 30;
const int w_sure = 31;
const int w_you_ban = 32;
const int w_address = 33;
const int w_messege = 34;
const int w_you_blocked = 35;
const int w_chat = 36;
const int w_not_chat = 37;
const int w_you_delete = 38;
const int w_price = 39;
const int w_code = 40;
const int w_no_mi_shop = 41;
const int w_mi_shop = 42;
const int w_sale = 43;
const int w_fence = 44;
const int w_no_purch = 45;
const int w_protect = 46;
const int w_unprotect = 47;
const int w_your_news = 48;
const int w_no_news = 49;
const int w_persent = 50;
const int w_successed_changes = 51;
const int w_no_new_messege = 52;
const int w_using = 53;
const int w_ability_to_craft = 54;
const int w_no_ability_to_craft = 55;
const int w_suc_craft = 56;
const int w_no_preparation = 57;
const int w_success_set_mi_shop = 58;

//important names
const int start_coin = 40;
const string adm_off = "false";
const string adm_on = "true";
const string Adm_on = "True";
const string first = "Админ";
const string second = "Шпион";
const string gamer = "игрок";
const int max_per = 1000;
const string fen = "=========";
const string sblock = "Защищено";
const string sunblock = "Не защищено";
const string syst = "Система";
const int minus_time = 1000000000;
const string ready = "Готово";

//defenitions
void mk_message(string, string, string);
void messege(string);
void show_messege(string);
void show_writers(string);

void ClearBuffer() {
	while (_kbhit())
		_getch();
}

string tram(string s) {
	if (s.size() > 0) {
		bool clear = false;
		while (clear == false) {
			if (s.size() == 0)
				clear = true;
			else if ((s[0] != ' ') && (s[s.size() - 1] != ' '))
				clear = true;
			else {
				if (s[0] == ' ')
					s = s.erase(0, 1);
				if (s[s.size() - 1] == ' ')
					s = s.erase(s.size() - 1, 1);
			}
		}
	}
	else {
		/*cout << "Error: line \"" + s + "\" very short to tram it.\n";
		system("pause >nul");
		exit;*/
		return "";
	}
	return s;
}

int quan(string s, char symbol) {
	int count = 0;
	for (size_t i = 0; i <= s.size() - 1; ++i)
		if (s[i] == symbol)
			++count;
	return count;
}

vector<int> msort(vector<int> v) {
	bool all_right = false;
	while (all_right == false) {
		int quan_right{};
		for (int i = 0; i < v.size() - 1; ++i) {
			if (v[i] < v[i + 1])
				++quan_right;
			else {
				int x = v[i];
				v[i] = v[i + 1];
				v[i + 1] = x;
			}
		}
		if (quan_right == v.size() - 1)
			all_right = true;
	}
	return v;
}

vector<int> make_unrepeated(vector<int> v) {
	vector<int> new_v;
	for (int i = 0; i < v.size(); ++i) {
		bool unic = true;
		for (int j = 0; j < new_v.size(); ++j)
			if (v[i] == new_v[j])
				unic = false;
		if (unic == true)
			new_v.push_back(v[i]);
	}
	return new_v;
}

string mkdhms(int sec) {
	if (sec == 0)
		return " 0 sec";
	else {
		sec = abs(sec);
		string sday{}, shour{}, smin{}, ssec{};
		if (sec >= 86400) {
			int day = sec / 86400;
			sday = to_string(day) + " day ";
			sec = sec - (day * 86400);
		}
		if (sec >= 3600) {
			int hour = sec / 3600;
			shour = to_string(hour) + " hour ";
			sec = sec - (hour * 3600);
		}
		if (sec >= 60) {
			int min = sec / 60;
			smin = to_string(min) + " min ";
			sec = sec - (min * 60);
		}
		if (sec > 0)
			ssec = to_string(sec) + " sec ";
		return sday + shour + smin + ssec;
	}
}

string del_all_space(string s) {
	string res = "";
	for (int i = 0; i < s.size(); ++i) {
		if ((s[i] != ' ') && (s[i] != '\t'))
			res = res + s[i];
	}
	return res;
}

string del_symbol(string s, size_t index) {
	if ((index <= s.size() - 1) && (index >= 0)) {
		return s.erase(index, 1);
	}
	else
		return "";
}

int lastsign(string s, char symbol) { //return index of finding last symbol
	int index = -1;
	if (s.size() != 0) {
		for (int i = s.size() - 1; i >= 0; --i)
			if (s[i] == symbol) {
				index = i;
				break;
			}
	}
	return index;
}

string parse(string s, char fence, char mode) {
	if (s.size() > 0) {
		string right_word = "", left_word = "";
		bool pass_fence = false;
		for (size_t i = 0; i < s.size(); ++i) {
			if ((s[i] == fence) && (pass_fence == false))
				pass_fence = true;
			else if (pass_fence == false)
				left_word += s[i];
			else
				right_word += s[i];
		}
		if (mode == 'r')
			return right_word;
		else if (mode = 'l')
			return left_word;
		else {
			cout << "The mode wasn't correctly written in function parse " << s;
			system("pause >nul");
			exit;
		}
	}
	else {
		cout << "Vary small string " << char(34) << s << char(34) << endl;
		system("pause >nul");
		exit;
	}
}

vector<int> random_line(int min, int max) {
	mt19937 gen{ random_device()() };
	uniform_int_distribution<int> dist(min, max);
	vector<int> v;
	for (int i = 0; i <= max - min; ++i) {
		while (true) {
			int a = dist(gen);
			bool b = true;
			if (v.size() > 0) {
				for (int j = 0; j <= v.size() - 1; ++j)
					if (v[j] == a) {
						b = false;
						break;
					}
			}
			if (b == true) {
				v.push_back(a);
				break;
			}
		}
	}
	return v;
}

void mkfile(string way_to_file, vector<string> lines) { //create a file with default lines in this
	string w = way_to_file.substr(0, lastsign(way_to_file, '\\'));
	fs::create_directories(w);
	ofstream f(way_to_file);
	if (lines.size() == 0)
		f << "";
	else
		for (size_t i = 0; i <= lines.size() - 1; ++i)
			f << lines[i] << endl;
	f.close();
}

bool isfile(string way_to_file) {
	ifstream f(way_to_file);
	if (!f)
		return false;
	return true;
}

void stop_if_nofile(string way_to_file) {
	if (isfile(way_to_file) == false) {
		cout << "File (" << way_to_file << ") wasn't found";
		system("pause >nul");
		exit;
	}
	return;
}

int filesize(string way_to_file) {//return quantity of strings in file
	stop_if_nofile(way_to_file);
	int i = 0; string s; ifstream f(way_to_file);
	while (!f.eof()) {
		getline(f, s);
		++i;
	}
	f.close();
	return i;
}

string filestr(string way_to_file, int index) {
	stop_if_nofile(way_to_file);
	if ((index > filesize(way_to_file) - 1) || (index < 0)) {
		cout << "Index: " << index << " don't get line of file (" << way_to_file << "): " << filesize(way_to_file) - 1 << endl;
		system("pause >nul");
		exit;
	}
	ifstream f(way_to_file); string s = "";
	if ((f.is_open() == true) && (index <= filesize(way_to_file) - 1)) {
		for (int i = 0; i <= index; ++i)
			getline(f, s);
	}
	f.close();
	return s;
}

int indexStrFile(string way_to_file, string line) { //return index of line from File
	bool foundstr = false;
	int x = -1;
	for (int i = 0; i <= filesize(way_to_file) - 1; ++i) {
		if (line == filestr(way_to_file, i)) {
			foundstr = true;
			x = i;
			break;
		}
	}
	return x;
}

void set_warn(int code, int mode) {
	stop_if_nofile(warns);
	for (int i = 0; i <= filesize(warns) - 1; ++i) {
		string s = filestr(warns, i);
		if (parse(s, '\t', 'l') == to_string(code)) {
			cout << parse(s, '\t', 'r');
			break;
		}
	}
	if (mode == 1)
		cout << endl;
	else if (mode == 0) {}
	else {
		cout << "mode in function set_warn wasn't correctly written";
		system("pause >nul");
		exit;
	}
}

void SetBackToFile(string way_to_file, string line) {
	vector <string> v;
	string s;
	for (int i = 0; i <= filesize(way_to_file) - 1; ++i) {
		s = filestr(way_to_file, i);
		if (s != "")
			v.push_back(s);
	}
	v.push_back(line);
	mkfile(way_to_file, v);
}

void SetFrontToFile(string way_to_file, string line) {
	vector <string> v = { line };
	string s;
	for (int i = 0; i <= filesize(way_to_file) - 1; ++i) {
		s = filestr(way_to_file, i);
		if (s != "")
			v.push_back(s);
	}
	mkfile(way_to_file, v);
}

void del_str(string way_to_file, int index) {
	if ((index > filesize(way_to_file) - 1) || (index < 0)) {
		cout << "Index: " << index << " don't get line of file (" << way_to_file << "): " << filesize(way_to_file) - 1 << endl;
		system("pause >nul");
		exit;
	}
	else {
		vector <string> v;
		string s;
		for (int i = 0; i < index; ++i) {
			s = filestr(way_to_file, i);
			if (s != "")
				v.push_back(s);
		}
		for (int i = index + 1; i < filesize(way_to_file); ++i) {
			s = filestr(way_to_file, i);
			if (s != "")
				v.push_back(s);
		}
		mkfile(way_to_file, v);
	}
}

bool find_str(string way_to_file, string line) {
	ifstream f(way_to_file);
	string chcklog = "";
	for (int i = 0; i <= filesize(way_to_file) - 1; ++i) {
		getline(f, chcklog);
		if (chcklog == line) {
			f.close();
			return true;
		}
	}
	f.close();
	return false;
}

bool chck_is_double(string s) {
	char c[] = { '0', '1', '2', '3', '4', '5', '6', '7','8', '9' };
	bool point = false, minus = false;
	for (size_t i = 0; i <= s.size() - 1; ++i) {
		for (int j = 0; j <= 9; ++j) {
			if (s[i] == c[j]) {
				break;
			}
			else if ((s[i] == '-') && (i == 0)) {
				if (minus == false) {
					minus = true;
					break;
				}
				else if (minus == true)
					return false;
			}
			else if ((s[i] == '.') && (point == false)) {
				point = true;
				break;
			}
			else if (j == 9)
				return false;
		}
	}
	return true;
}

double to_double(string s) {
	if (chck_is_double(s) == true) {
		bool minus = false, point = false;
		double bit = 1;
		int p = -1;
		if (quan(s, '-') == 1) {
			minus = true;
			s = s.substr(1);
		}
		if (quan(s, '.') == 1) {
			point = true;
			p = ((s.size() - 1) - (lastsign(s, '.')));
			bit = pow(10, -p);
			s = del_symbol(s, s.size() - 1 - p);
		}
		double num = 0;
		char a[] = { '0','1','2','3','4','5','6','7','8','9' };
		for (int i = s.size() - 1; i >= 0; --i) {
			for (int j = 0; j <= 9; ++j) {
				if (s[i] == a[j]) {
					num = num + (j * bit);
					bit = bit * 10;
					break;
				}
			}
		}
		if (minus == true)
			return -num;
		else
			return num;
	}
	else
		return -1000;
}

double get_double(int code) {
	double pric;
	while (true) {
		string quantity;
		set_warn(code, 0);
		cin >> quantity;
		/*if (quantity == "стоп") {
			return -1;
		}*/
		if (chck_is_double(quantity) == true) {
			pric = to_double(quantity);
			break;
		}
		else
			set_warn(w_no_int, 1);
	}
	return pric;
}

void system_news(string news) {
	int size_news = quan(news, '\t') + 1;
	vector<string> vnews(size_news);
	for (int i = 0; i < size_news; ++i) {
		vnews[i] = parse(news, '\t', 'l');
		news = parse(news, '\t', 'r');
	}

	SetBackToFile(file_news, fen + syst + fen);
	for (int i = 0; i < size_news; ++i)
		SetBackToFile(file_news, vnews[i]);

	SetBackToFile(file_news, " ");
}

void balance(string login) {
	string way_to_file = dir_clients + '\\' + login + info_client;
	set_warn(w_balance, 0);
	cout << filestr(way_to_file, 1);
	set_warn(w_coin, 1);
}

void csort(string way_to_file) {
	if (filesize(way_to_file) > 2) {
		vector <string> v;
		for (int i = 0; i <= filesize(way_to_file) - 1; ++i) {
			string s = filestr(way_to_file, i);
			if (s != "")
				v.push_back(s);
		}
		bool all_right = false;
		while (all_right == false) {
			int right = 0;
			for (int i = 0; i <= v.size() - 2; ++i) {
				if (v[i] > v[i + 1]) {
					string s = v[i];
					v[i] = v[i + 1];
					v[i + 1] = s;
				}
				else
					++right;
			}
			if (right == v.size() - 1)
				all_right = true;
		}
		mkfile(way_to_file, v);
	}
}

void accounts(string login) {
	if (filestr(file_clients, 0) != "") {
		vector<string> accounts;
		int size = filesize(file_clients) - 1;
		for (int i = 0; i < size; ++i) {
			string login_to = filestr(file_clients, i);
			string status = filestr(dir_clients + '\\' + login_to + info_client, 2);
			{
				if (status == Adm_on)
					status = first;
				else if (status == adm_on)
					status = second;
				else
					status = gamer;
			}
			accounts.push_back(to_string(i + 1) + '\t' + login_to + '\t' + '[' + status + ']');
		}
		if (accounts.size() > 0) {
			for (int i = 0; i < accounts.size(); ++i)
				printf("%4s %20s %10s\n", parse(accounts[i], '\t', 'l').c_str(), parse(parse(accounts[i], '\t', 'r'), '\t', 'l').c_str(), parse(parse(accounts[i], '\t', 'r'), '\t', 'r').c_str());
		}
		else
			set_warn(w_no_log, 1);
	}
	else
		set_warn(w_no_clients, 1);
}

void ban_list() {
	if (filestr(ban, 0) != "") {
		csort(ban);
		for (int i = 0; i < filesize(ban); ++i)
			if (filestr(ban, i) != "") {
				cout << i + 1 << ". " << filestr(ban, i);
				if (filestr(dir_clients + "\\" + filestr(ban, i) + info_client, 2) == "true")
					cout << '[' << second << ']';
				if (filestr(dir_clients + "\\" + filestr(ban, i) + info_client, 2) == "True")
					cout << '[' << first << ']';
				cout << ";" << endl;
			}
	}
	else
		set_warn(w_no_clients, 1);
}

void show_shop() {
	if ((filesize(shop) == 1) && (filestr(shop, 0) == ""))
		set_warn(w_no_purchase, 1);
	else {
		string s{};
		int size = filesize(shop) - 1;
		for (size_t i = 0; i < size; ++i) {
			s += '№' + to_string(i + 1) + ". " + parse(filestr(shop, i), '\t', 'l') + " -> " + parse(filestr(shop, i), '\t', 'r') + '\n';
		}
		cout << s;
	}
}

void buy(string login) {
	int long long number_of_product = 0;
	number_of_product = get_double(w_ask_number);
	if (number_of_product == -1)
		return;
	else if ((number_of_product > filesize(shop) - 1) || (number_of_product <= 0))
		set_warn(w_not_right_index, 1);
	else {
		string str = filestr(shop, number_of_product - 1);
		string product = parse(str, '\t', 'l');
		int price = to_double(parse(str, '\t', 'r'));
		int balance = to_double(filestr(dir_clients + '\\' + login + info_client, 1));
		if (price > balance) {
			set_warn(w_not_enough_money, 0);
			cout << price - balance;
			set_warn(w_coin, 1);
		}
		else {
			string password = filestr(dir_clients + '\\' + login + info_client, 0);
			string status = filestr(dir_clients + '\\' + login + info_client, 2);
			vector <string> v;
			v.push_back(password);
			v.push_back(to_string(balance - price));
			v.push_back(status);
			mkfile(dir_clients + '\\' + login + info_client, v);
			SetBackToFile(dir_clients + '\\' + login + purchase, str);
			set_warn(w_successful_buying, 0);
			cout << product << endl;
		}
	}
}

void show_buying(string login) {
	string way_to_prepar = dir_clients + '\\' + login + file_preparation;

	if (filesize(way_to_prepar) > 1) {
		vector<int> ready_prepar;
		time_t now = time(NULL) - minus_time;
		int size = filesize(way_to_prepar) - 1;
		for (int i = 0; i < size; ++i) {
			int future = to_double(parse(parse(filestr(way_to_prepar, i), '\t', 'r'), '\t', 'r'));
			if (future < now)
				ready_prepar.push_back(i);
		}

		if (ready_prepar.size() > 0)
			ready_prepar = msort(ready_prepar);

		for (int i = ready_prepar.size() - 1; i > -1; --i) {
			string result = filestr(way_to_prepar, ready_prepar[i]);
			string product = parse(result, '\t', 'l');
			string Price = parse(parse(result, '\t', 'r'), '\t', 'l');
			del_str(way_to_prepar, ready_prepar[i]);
			SetBackToFile(dir_clients + '\\' + login + purchase, product + '\t' + Price);
		}
	}

	if (filesize(dir_clients + '\\' + login + purchase) > 1) {
		string way_to_purch = dir_clients + '\\' + login + purchase;
		int size = filesize(way_to_purch);

		set_warn(w_fence, 1);
		set_warn(w_you_buy, 1);
		set_warn(w_fence, 1);
		csort(way_to_purch);
		for (size_t i = 0; i < size-1; ++i) {
			string s = filestr(way_to_purch, i);
			string name = parse(s, '\t', 'l');
			string price = parse(s, '\t', 'r');
			printf("%5d || %20s || %10s||\n", i + 1, name.c_str(), price.c_str());
		}
		set_warn(w_fence, 1);
	}
	else
		set_warn(w_no_buying, 1);
}

void sale(string login) {
	if (filesize(dir_clients + '\\' + login + purchase) > 1) {
		int number_of_buying = get_double(w_ask_number);
		if ((number_of_buying > filesize(dir_clients + '\\' + login + purchase)) || (number_of_buying <= 0))
			set_warn(w_not_right_index, 1);
		else {
			string product = parse(filestr(dir_clients + '\\' + login + purchase, number_of_buying - 1), '\t', 'l');
			int price = to_double(parse(filestr(dir_clients + '\\' + login + purchase, number_of_buying - 1), '\t', 'r'));
			int balance = to_double(filestr(dir_clients + '\\' + login + info_client, 1));
			string password = filestr(dir_clients + '\\' + login + info_client, 0);
			string status = filestr(dir_clients + '\\' + login + info_client, 2);

			{// changing price of product if he is known
				bool found = false;
				for (int i = 0; i < filesize(shop) - 1; ++i) {
					string ch_product = filestr(shop, i);
					string purch = parse(ch_product, '\t', 'l');
					if (purch == product) {
						price = to_double(parse(ch_product, '\t', 'r'));
						found = true;
					}
				}
				if (found == false) {
					price = 0;
				}
			}

			del_str(dir_clients + '\\' + login + purchase, number_of_buying - 1);
			mkfile(dir_clients + '\\' + login + info_client, { password, to_string(balance + int(price / 3)), status });
			set_warn(w_success_sale, 0);
			cout << product << endl;
		}
	}
	else
		set_warn(w_no_buying, 1);
}

void casino(string login) {
	int stack, balance = to_double(filestr(dir_clients + '\\' + login + info_client, 1));
	stack = get_double(w_ask_stack);
	if (stack < 10) {
		set_warn(w_not_enough_money, 0);
		cout << 10 - stack;
		set_warn(w_coin, 1);
	}
	else if (stack > balance) {
		set_warn(w_not_enough_money, 0);
		cout << stack - balance;
		set_warn(w_coin, 1);
	}
	else {
		string password = filestr(dir_clients + '\\' + login + info_client, 0);
		string status = filestr(dir_clients + '\\' + login + info_client, 2);
		int number = rand(0, max_per);
		{// downloading
			char c[] = "-\\|/";
			int cur = 0;
			for (int i = 0; i < 40; ++i) {
				if (++cur > (sizeof(c) - 1 / sizeof(c[0])) - 1)
					cur = 0;
				cout << c[cur];
				Sleep(100);
				cout << char(8);
			}
		}
		if (double(number) > to_double(filestr(persent_of_casino, 0))) {
			set_warn(w_you_lose, 1);
			mkfile(dir_clients + '\\' + login + info_client, { password, to_string(balance - stack), status });
		}
		if (double(number) <= to_double(filestr(persent_of_casino, 0))) {
			set_warn(w_you_win, 1);
			mkfile(dir_clients + '\\' + login + info_client, { password, to_string(balance + (stack * rand(1, 3))), status });
		}
	}

}

void counting_game(string login) {
	int level = get_double(w_level);
	if ((level > 5) || (level < 1))
		set_warn(w_not_right, 1);
	else {
		int diaposon, qsize = rand(10, 15), persent = 0, right_answer = 0;
		switch (level) {
		case 1:
			diaposon = 10;
			break;
		case 2:
			diaposon = 20;
			break;
		case 3:
			diaposon = 40;
			break;
		case 4:
			diaposon = 50;
			break;
		case 5:
			diaposon = 100;
			break;
		}
		for (int i = 0; i <= qsize - 1; ++i) {
			int a = rand(1, diaposon), b = rand(1, diaposon), minus = rand(0, 1), res, answer;
			cout << i + 1 << ". " << a;
			if (minus == 0) {
				cout << " - ";
				res = a - b;
			}
			else {
				cout << " + ";
				res = a + b;
			}
			cout << b << " == ";
			answer = get_double(-2);
			if (answer == res) {
				set_warn(w_right, 1);
				++right_answer;
			}
			else {
				set_warn(w_false, 0);
				cout << " " << res << endl;
			}
		}

		{
			persent = round((double(right_answer) / qsize) * 100);
			string password = filestr(dir_clients + '\\' + login + info_client, 0);
			string status = filestr(dir_clients + '\\' + login + info_client, 2);
			int balance = to_double(filestr(dir_clients + '\\' + login + info_client, 1));
			vector< vector<int> > arr = { {-10, 50}, {5, 75}, {10, 85}, {15, 101} };
			for (int i = 0; i <= arr.size() - 1; ++i) {
				if (persent < arr[i][1]) {
					balance += arr[i][0];
					break;
				}
			}
			if (balance < 0)
				balance = 0;
			mkfile(dir_clients + '\\' + login + info_client, { password, to_string(balance), status });
		}
	}
}

void translate(string login) {
	char mode;
	const int quantity = 10;
	int right_answer = 0;
	int balance = to_double(filestr(dir_clients + '\\' + login + info_client, 1));
	string password = filestr(dir_clients + '\\' + login + info_client, 0);
	string status = filestr(dir_clients + '\\' + login + info_client, 2);
	int start = rand(0, filesize(dictionary) - quantity);
	vector<int> order = random_line(start, start + quantity - 1);
	vector<string> ru;
	vector<string> en;

	set_warn(w_translate_from, 0);
	cin >> mode;

	if ((mode == 'р') || (mode == 'а')) {
		int right_answer = 0, persent = 0;

		for (int i = 0; i <= quantity - 1; ++i) {
			string s = filestr(dictionary, order[i]);
			en.push_back(parse(s, '\t', 'l'));
			ru.push_back(parse(s, '\t', 'r'));
		}

		for (int i = 0; i <= quantity - 1; ++i) {
			string from, to, word;
			if (mode == 'р') {
				from = ru[i];
				to = en[i];
			}
			else {
				from = en[i];
				to = ru[i];
			}
			cout << i + 1 << ". " << from << " == ";
			getline(cin, word);
			if (word == "")
				getline(cin, word);
			if (word == to) {
				set_warn(w_right, 1);
				++right_answer;
			}
			else {
				set_warn(w_false, 0);
				cout << " " << to << endl;
			}
		}

		persent = round((double(right_answer) / quantity) * 100);
		vector< vector<int> > arr = { {-20, 50}, {10, 75}, {15, 85}, {25, 101} };
		for (int i = 0; i <= arr.size() - 1; ++i) {
			if (persent < arr[i][1]) {
				balance += arr[i][0];
				break;
			}
		}
		if (balance < 0)
			balance = 0;
		mkfile(dir_clients + '\\' + login + info_client, { password, to_string(balance), status });
	}
	else
		set_warn(w_false, 1);
}

void game_snake(string login) {
	system("chcp 866 >nul");
	const char file_background = '-';
	const vector< vector <int> > neightbour = { {0, -1}, {1, 0}, {0, 1}, {-1,0} };
	const char button[] = { 's', 'd', 'w', 'a' };
	const char alive = char(178), death = ' ', berry = char(253), head = char(258);
	int pause = 75;
	vector< vector<int> > body = { {0, 0}, {1, 0}, {2,0} }; //from end to start. it's easier to to make longer snake, when it eats.
	bool eat = true;
	char cberry[2];
	int course[] = { 1, 0 };
	int new_speed = 0;
	int length = 20;
	int height = 20;

	vector< vector<char> > space(length, vector<char>(height, death));

	for (int i = 0; i < (int)body.size() - 1; ++i) //adding alive places of snake's body
		space[body[i][0]][body[i][1]] = alive;

	space[body[(int)body.size() - 1][0]][body[(int)body.size() - 1][1]] = head;

	while (true) {
		//Sleep(pause);
		system("cls");

		if (eat == true) {
			++new_speed;
			bool b = false;
			int x, y;
			while (true) {
				x = rand(0, length - 1);
				y = rand(0, height - 1);
				if (space[x][y] == death)
					break;
			}
			cberry[0] = x;
			cberry[1] = y;
			eat = false;
		}

		space[cberry[0]][cberry[1]] = berry;

		{
			string s = "";
			for (int y = height - 1; y > -1; --y) { //showing place
				for (int x = 0; x < length; ++x)
					s += space[x][y];
				s += "||\n";
			}
			for (int i = 0; i < length + 2; ++i)
				s += '=';
			cout << s << ' ' << to_string((int)body.size() - 3) << endl;
		}

		int new_x, new_y;

		Sleep(pause);
		if (_kbhit()) {
			char move = _getch();
			for (int i = 0; i < neightbour.size(); ++i) {
				if (move == button[i]) {
					if ((abs(neightbour[i][0]) + abs(course[0]) != 2) && (abs(neightbour[i][1]) + abs(course[1]) != 2)) {
						course[0] = neightbour[i][0];
						course[1] = neightbour[i][1];
						break;
					}
				}
			}
		}
		new_x = body[body.size() - 1][0] + course[0];
		new_y = body[body.size() - 1][1] + course[1];

		if (new_x > length - 1)
			new_x -= length;
		if (new_y > height - 1)
			new_y -= height;
		if (new_x < 0)
			new_x += length;
		if (new_y < 0)
			new_y += height;


		if (space[new_x][new_y] == berry) {
			int size = (int)body.size();
			space[body[(int)body.size() - 1][0]][body[(int)body.size() - 1][1]] = alive;
			body.resize(size + 1, vector<int>(2));
			body[(int)body.size() - 1][0] = new_x;
			body[(int)body.size() - 1][1] = new_y;
			space[new_x][new_y] = head;
			eat = true;
			Sleep(pause * 0.33333);
		}
		else if (space[new_x][new_y] == death) {
			space[body[0][0]][body[0][1]] = death;
			for (int i = 0; i < (int)body.size() - 1; ++i) {
				body[i][0] = body[i + 1][0];
				body[i][1] = body[i + 1][1];
			}
			body[(int)body.size() - 1][0] = new_x;
			body[(int)body.size() - 1][1] = new_y;
			space[body[(int)body.size() - 2][0]][body[(int)body.size() - 2][1]] = alive;
			space[new_x][new_y] = head;
		}
		else {
			cout << "!!!Game over!!!\n";
			ClearBuffer();
			while (!_kbhit()) {}
			_getch();
			break;
		}
		if (new_speed >= 10) {
			pause = double(pause) * 0.9;
			new_speed = 0;
		}
	}
	if ((int)body.size() - 3 > 0) {
		string password = filestr(dir_clients + '\\' + login + info_client, 0);
		int balance = to_double(filestr(dir_clients + '\\' + login + info_client, 1));
		string status = filestr(dir_clients + '\\' + login + info_client, 2);
		mkfile(dir_clients + '\\' + login + info_client, { password, to_string(balance + (int)body.size() - 3), status });
	}
	system("cls");
	system("chcp 1251 >nul");
}

void mkcraft(string login) {
	const string way_to_purchase = dir_clients + '\\' + login + purchase;
	int sizePurch = filesize(way_to_purchase) - 1;
	if (sizePurch > 0) {
		const string way_to_prepar = dir_clients + '\\' + login + file_preparation;
		vector<string> info_of_products;
		vector<string> products;
		vector<int> number_list;
		vector<string> can_craft;
		int code{};

		show_buying(login);

		{
			int quantity{};
			vector<string> vs;
			string s{};

			set_warn(w_using, 0);
			getline(cin, s);
			if (s == "")
				getline(cin, s);

			if ((s == "стоп") || (s == ""))
				return;

			s = tram(s);

			{	// checking that string s doesn't contain double spaces
				bool b = true;
				for (int i = 0; i < s.size() - 1; ++i)
					if ((s[i] == ' ') && (s[i + 1] == ' ')) {
						b = false;
						break;
					}
				if (b == false) {
					set_warn(w_not_right, 1);
					return;
				}
			}

			quantity = quan(s, ' ') + 1;
			for (int i = 0; i < quantity; ++i) {
				vs.push_back(parse(s, ' ', 'l'));
				s = parse(s, ' ', 'r');
			}

			{	// checking that all parts of vector vs has only numbers and after fill this vector to number_list;
				bool b = true;
				for (int i = 0; i < vs.size(); ++i)
					if (chck_is_double(vs[i]) == false) {
						b = false;
						break;
					}
				if (b == false) {
					set_warn(w_not_right, 1);
					return;
				}
			}

			for (int i = 0; i < vs.size(); ++i)
				number_list.push_back(to_double(vs[i]));

			{//sorting all vector and making it unrepeative
				number_list = make_unrepeated(number_list);
				number_list = msort(number_list);
			}

			{//checking that all parts of vector number_list doesn't go out of purchase list
				int sizefile = filesize(way_to_purchase) - 1;
				for (int i = 0; i < number_list.size(); ++i)
					if ((number_list[i] < 1) || (number_list[i] > sizefile)) {
						set_warn(w_not_right, 1);
						return;
					}
			}
		}

		for (int i = 0; i < number_list.size(); ++i) {
			string name = filestr(way_to_purchase, number_list[i] - 1);
			info_of_products.push_back(name);
		}

		for (int i = 0; i < info_of_products.size(); ++i)
			products.push_back(parse(info_of_products[i], '\t', 'l'));

		for (int i = 0; i < filesize(craft) - 1; ++i) {
			vector<string> need_products;
			vector<string> result{};
			string info_craft = filestr(craft, i), left{}, right{};
			int quantity_left{}, quantity_right{};

			left = tram(parse(info_craft, '=', 'l'));
			right = tram(parse(parse(info_craft, '=', 'r'), '\t', 'l'));
			quantity_left = quan(left, '+') + 1;

			for (int j = 0; j < quantity_left; ++j) {
				need_products.push_back(tram(parse(left, '+', 'l')));
				left = parse(left, '+', 'r');
			}

			int counter{};
			for (int j = 0; j < need_products.size(); j++) {
				for (int q = 0; q < products.size(); q++) {
					if (need_products[j] == products[q]) {
						++counter;
						products[q] += '\t';
						break;
					}
				}
			}

			for (int i = 0; i < products.size(); ++i)
				if (products[i][products[i].size() - 1] == '\t')
					products[i].erase(products[i].size() - 1, 1);

			if (counter == need_products.size())
				can_craft.push_back(to_string(i) + '\t' + right);
		}

		if (can_craft.size() > 0) {
			set_warn(w_ability_to_craft, 1);
			for (int i = 0; i < can_craft.size(); ++i) {
				printf("#%4d || %4d ||  ", i + 1, int(to_double(parse(can_craft[i], '\t', 'l')) + 1));
				cout << parse(can_craft[i], '\t', 'r') << endl;
			}
		}
		else {
			set_warn(w_no_ability_to_craft, 1);
			return;
		}

		code = get_double(w_code) - 1;
		if ((code > -1) && (code < filesize(craft))) {}
		else {
			set_warn(w_not_right, 1);
			return;
		}

		{//checking than code is contained in list of can_craft
			bool have = false;
			for (int i = 0; i < can_craft.size(); ++i)
				if (code == int(to_double(parse(can_craft[i], '\t', 'l'))))
					have = true;
			if (have == false) {
				set_warn(w_not_right, 1);
				return;
			}
		}


		{
			vector<string> need_products;
			vector<int> delete_index;
			vector<string> result;
			string info = filestr(craft, code);
			int Price = 0;
			{
				string prod = tram(parse(info, '=', 'l'));
				int quantity = quan(tram(prod), '+') + 1;

				for (int i = 0; i < quantity; ++i) {
					need_products.push_back(tram(parse(prod, '+', 'l')));
					prod = parse(prod, '+', 'r');
				}
			}
			{
				string res = tram(parse(parse(info, '=', 'r'), '\t', 'l'));
				int quantity = quan(res, '+') + 1;
				for (int i = 0; i < quantity; ++i) {
					result.push_back(tram(parse(res, '+', 'l')));
					res = parse(res, '+', 'r');
				}
			}
			for (int i = 0; i < need_products.size(); ++i) {
				for (int j = 0; j < products.size(); ++j) {
					if (need_products[i] == products[j]) {
						delete_index.push_back(number_list[j] - 1);
						products[j] += '\t';
						break;
					}
				}
			}

			for (int i = 0; i < products.size(); ++i)
				if (products[i][products[i].size() - 1] == '\t')
					products[i] = products[i].erase(products[i].size() - 1, 1);

			delete_index = msort(delete_index);

			for (int i = delete_index.size() - 1; i > -1; --i) {
				Price += to_double(parse(filestr(way_to_purchase, delete_index[i]), '\t', 'r'));
				del_str(way_to_purchase, delete_index[i]);
			}

			time_t future_unlock = time(NULL) + to_double(parse(info, '\t', 'r')) - minus_time;
			for (int i = 0; i < result.size(); ++i) {
				SetBackToFile(way_to_prepar, result[i] + '\t' + to_string(int(double(Price) / result.size())) + '\t' + to_string(future_unlock));
			}
			set_warn(w_suc_craft, 0);
			cout << tram(parse(tram(parse(info, '=', 'r')), '\t', 'l')) << endl;
		}
	}
}

void show_possible_craft(string login) {
	string way_to_purch = dir_clients + '\\' + login + purchase;
	int size_of_purch = filesize(way_to_purch)-1;
	if (size_of_purch > 0) {
		show_buying(login);
		int number = get_double(w_ask_number) - 1;
		if ((number > -1) && (number < size_of_purch)) {
			string result = fen + fen + '\n';
			string info_purch = filestr(way_to_purch, number);
			string name = parse(info_purch, '\t', 'l');
			int size_of_craft = filesize(craft) - 1;
			for (int i = 0; i < size_of_craft; ++i) {
				vector<string> need_products;
				string info = filestr(craft, i);
				string left = tram(parse(info, '=', 'l'));
				int size_left = quan(left, '+') + 1;
				bool have = false;
				for (int i = 0; i < size_left; ++i) {
					need_products.push_back(tram(parse(left, '+', 'l')));
					left = parse(left, '+', 'r');
				}
				for (int i = 0; i < need_products.size(); ++i)
					if (name == need_products[i]) {
						have = true;
						break;
					}
				if (have == true) {
					int time_wait = to_double(parse(info, '\t', 'r'));
					result += tram(parse(info, '\t', 'l')) + ' ' + mkdhms(time_wait) + '\n' + fen + fen + '\n';
				}
			}
			if (result == fen + fen + '\n')
				set_warn(w_no_ability_to_craft, 1);
			else
				cout << result;
		}
		else
			set_warn(w_not_right, 1);
	}
	else
		set_warn(w_no_buying, 1);
}

void show_preparation(string login) {
	string way_to_preparation = dir_clients + '\\' + login + file_preparation;
	while (true) {
		int size_of_prepar = filesize(way_to_preparation);
		if (size_of_prepar > 1) {
			csort(way_to_preparation);
			string result = fen + fen + '\n';
			for (int i = 0; i < size_of_prepar - 1; ++i) {
				string info = filestr(way_to_preparation, i);
				int wait = to_double(parse(parse(info, '\t', 'r'), '\t', 'r')) - (time(NULL) - minus_time);
				string swait{};
				if (wait <= 0)
					swait = ready;
				else
					swait = mkdhms(wait);
				info = parse(info, '\t', 'l') + '\t' + parse(parse(info, '\t', 'r'), '\t', 'l');
				result += info + '\t' + swait + '\n' + fen + fen + '\n';
			}
			cout << result;
		}
		else {
			set_warn(w_no_preparation, 1);
			break;
		}
		
		if (_kbhit())
			break;
		else {
			Sleep(1000);
			system("cls");
		}
	}
}

void make_purchase(string login) {
	int number_of_product = get_double(w_ask_number);
	if ((number_of_product > filesize(dir_clients + '\\' + login + purchase) - 1) || (number_of_product < 1))
		set_warn(w_not_right_index, 1);
	else {
		int price = get_double(w_price);
		if (price >= 0) {
			bool code = false;
			string scode;
			set_warn(w_code, 0);
			cin.clear();
			cin.ignore(100, '\n');
			getline(cin, scode);
			scode = tram(scode);
			if (scode != "")
				code = true;

			string product = parse(filestr(dir_clients + '\\' + login + purchase, number_of_product - 1), '\t', 'l');
			string result_line = product + '\t' + to_string(price);
			if (code == true)
				result_line += '\t' + scode;

			del_str(dir_clients + '\\' + login + purchase, number_of_product - 1);
			SetFrontToFile(dir_clients + '\\' + login + mi_shop, result_line);
			set_warn(w_success_set_mi_shop, 0);
			cout << '\"' << product << "\"\n";
		}
		else
			set_warn(w_not_right, 1);
	}
}

void show_my_mi_shop(string login) {
	if (filesize(dir_clients + '\\' + login + mi_shop) > 1) {
		set_warn(w_mi_shop, 0); cout << char(34) << login << char(34) << endl;
		set_warn(w_fence, 1);
		for (int i = 0; i < filesize(dir_clients + '\\' + login + mi_shop); ++i) {
			string s = filestr(dir_clients + '\\' + login + mi_shop, i);
			if (s != "") {
				string product = parse(s, '\t', 'l');
				string price = parse(parse(s, '\t', 'r'), '\t', 'l');
				string code = parse(parse(s, '\t', 'r'), '\t', 'r');

				cout << i + 1 << ' ';
				set_warn(w_sale, 0);
				cout << product << endl;
				set_warn(w_price, 0);
				cout << price << endl;
				if (code != "") {
					set_warn(w_code, 0);
					cout << '\"' << code << "\"\n";
				}
				set_warn(w_fence, 1);
			}
		}
	}
	else
		set_warn(w_no_mi_shop, 1);
}

void delete_purch(string login) {
	int index = get_double(w_ask_number) - 1;
	string way_to_file = dir_clients + '\\' + login + mi_shop;
	if ((index < filesize(way_to_file) - 1) && (index > -1)) {
		string product_information = filestr(way_to_file, index);
		string product = parse(product_information, '\t', 'l');
		string Price = parse(parse(product_information, '\t', 'r'), '\t', 'l');
		
		SetBackToFile(dir_clients + '\\' + login + purchase, product + '\t' + Price);
		del_str(way_to_file, index);
	}
	else
		set_warn(w_not_right_index, 1);
}

void show_privet_purchase() {
	string login_to{};
	set_warn(w_login, 0);
	cin >> login_to;
	if ((find_str(file_clients, login_to) == true) || (find_str(ban, login_to) == true)) {
		string way_to_file{};
		way_to_file = dir_clients + '\\' + login_to + mi_shop;
		if (filesize(way_to_file) > 1) {
			int siz = filesize(way_to_file);

			set_warn(w_fence, 1);
			for (int i = 0; i < siz - 1; ++i) {
				string purchase_info = filestr(way_to_file, i);
				string product = parse(purchase_info, '\t', 'l');
				string Price = parse(parse(purchase_info, '\t', 'r'), '\t', 'l');
				cout << '№' << i + 1 << ". " << product << " -> " << Price;
				set_warn(w_coin, 0);
				cout << ' ';
				if (quan(purchase_info, '\t') > 1)
					set_warn(w_protect, 0);
				else
					set_warn(w_unprotect, 0);
				cout << " ;\n";
			}
			set_warn(w_fence, 1);
		}
		else
			set_warn(w_no_purch, 1);
	}
	else
		set_warn(w_not_found_login, 1);
}

void buy_privet_purch(string login_from) {
	string login_to{};

	set_warn(w_login, 0);
	cin >> login_to;
	if (login_from != login_to) {
		if ((find_str(file_clients, login_to) == true) || (find_str(ban, login_to) == true)) {
			string way_to_file_to = dir_clients + '\\' + login_to + mi_shop;
			if (filesize(way_to_file_to) > 1) {
				int index = get_double(w_ask_number) - 1;
				if ((index < filesize(way_to_file_to) - 1) && (index > -1)) {
					string purchase_info = filestr(way_to_file_to, index);
					int Price = to_double(parse(parse(purchase_info, '\t', 'r'), '\t', 'l'));
					int balance_to = to_double(filestr(dir_clients + '\\' + login_to + info_client, 1));
					int balance_from = to_double(filestr(dir_clients + '\\' + login_from + info_client, 1));
					bool buyin = false;
					if (Price <= balance_from) {
						if (quan(purchase_info, '\t') > 1) {
							string cod = tram(parse(parse(purchase_info, '\t', 'r'), '\t', 'r'));
							string check_cod{};
							set_warn(w_code, 0);
							getline(cin, check_cod);
							if (check_cod == "")
								getline(cin, check_cod);
							if (check_cod == cod)
								buyin = true;
							else
								set_warn(w_not_right, 1);
						}
						else buyin = true;
					}
					else {
						set_warn(w_not_enough_money, 0);
						cout << Price - balance_from << endl;
					}
					if (buyin == true) {
						string way_to_file_from = dir_clients + '\\' + login_from + purchase;
						string product = parse(purchase_info, '\t', 'l');
						string password_to = filestr(dir_clients + '\\' + login_to + info_client, 0);
						string password_from = filestr(dir_clients + '\\' + login_from + info_client, 0);
						string status_to = filestr(dir_clients + '\\' + login_to + info_client, 2);
						string status_from = filestr(dir_clients + '\\' + login_from + info_client, 2);
						del_str(way_to_file_to, index);
						SetBackToFile(way_to_file_from, product + '\t' + to_string(Price));
						mkfile(dir_clients + '\\' + login_to + info_client, { password_to, to_string(balance_to + Price), status_to });
						mkfile(dir_clients + '\\' + login_from + info_client, { password_from, to_string(balance_from - Price), status_from });
						mk_message(login_from, login_to, login_from + " <- " + product + ' ' + to_string(Price) + " <- " + login_to);
						mk_message(login_to, login_from, login_from + " <- " + product + ' ' + to_string(Price) + " <- " + login_to);
						set_warn(w_successful_buying, 0);
						cout << '\"' << product << "\"\n";
					}
				}
				else set_warn(w_not_right, 1);
			}
			else set_warn(w_no_purch, 1);
		}
		else set_warn(w_not_found_login, 1);
	}
	else
		set_warn(w_not_right, 1);
}

void show_all_purch() {
	vector<string> vpurch;
	for (int i = 0; i < filesize(file_clients) - 1; ++i) {
		string login = filestr(file_clients, i);
		string way_to_login = dir_clients + '\\' + login + mi_shop;
		int size = filesize(dir_clients + '\\' + login + mi_shop);
		if (size > 1) {
			vpurch.push_back(fen + login + fen);
			for (int j = 0; j < size - 1; ++j) {
				string purchase_info = filestr(way_to_login, j);
				string product = parse(purchase_info, '\t', 'l');
				string Price = parse(parse(purchase_info, '\t', 'r'), '\t', 'l');
				string ress = product + " -> " + Price + ' ';
				if (quan(purchase_info, '\t') > 1)
					ress += sblock;
				else
					ress += sunblock;
				vpurch.push_back(ress);
			}
		}
	}
	if (vpurch.size() == 0)
		set_warn(w_no_purch, 1);
	else {
		for (int i = 0; i < vpurch.size(); ++i)
			cout << vpurch[i] << endl;
		set_warn(w_fence, 1);
	}
}

void cl_balance(string login_from) {
	string login_to;
	set_warn(w_login, 0);
	cin >> login_to;
	if ((find_str(file_clients, login_to) == true) || (find_str(ban, login_to) == true)) {
		bool law = false;
		if (filestr(dir_clients + '\\' + login_from + info_client, 2) == Adm_on) {
			if (filestr(dir_clients + '\\' + login_to + info_client, 2) != Adm_on)
				law = true;
		}
		else
			if (filestr(dir_clients + '\\' + login_to + info_client, 2) == adm_off)
				law = true;
		if (law == true) {
			int balance = to_double(filestr(dir_clients + '\\' + login_to + info_client, 1));
			set_warn(w_balance, 0);
			cout << balance;
			set_warn(w_coin, 1);
		}
		else
			set_warn(w_not_right, 1);
	}
	else
		set_warn(w_not_found_login, 1);
}

void change_balance(string login_from) {
	string login_to;
	set_warn(w_login, 0);
	cin >> login_to;
	if ((find_str(file_clients, login_to) == true) || (find_str(ban, login_to) == true)) {
		bool law = false;
		if (login_from == login_to)
			law = true;
		if (filestr(dir_clients + '\\' + login_from + info_client, 2) == Adm_on) {
			if (filestr(dir_clients + '\\' + login_to + info_client, 2) != Adm_on)
				law = true;
		}
		else
			if (filestr(dir_clients + '\\' + login_to + info_client, 2) == adm_off)
				law = true;
		if (law == true) {
			int balance = get_double(w_balance);
			string password = filestr(dir_clients + '\\' + login_to + info_client, 0);
			string status = filestr(dir_clients + '\\' + login_to + info_client, 2);
			mkfile(dir_clients + '\\' + login_to + info_client, { password, to_string(balance), status });
		}
		else
			set_warn(w_not_right, 1);
	}
	else
		set_warn(w_not_found_login, 1);
}

void cl_password(string login_from) {
	string login_to;
	set_warn(w_login, 0);
	cin >> login_to;
	if ((find_str(file_clients, login_to) == true) || (find_str(ban, login_to) == true)) {
		bool law = false;
		if (login_from == login_to)
			law = true;
		if (filestr(dir_clients + '\\' + login_from + info_client, 2) == Adm_on) {
			if (filestr(dir_clients + '\\' + login_to + info_client, 2) != Adm_on)
				law = true;
		}
		else
			if (filestr(dir_clients + '\\' + login_to + info_client, 2) == adm_off)
				law = true;
		if (law == true) {
			string password = filestr(dir_clients + '\\' + login_to + info_client, 0);
			set_warn(w_password, 0);
			cout << password << endl;
		}
		else
			set_warn(w_not_right, 1);
	}
	else
		set_warn(w_not_found_login, 1);
}

void change_password(string login_from) {
	string login_to;
	set_warn(w_login, 0);
	cin >> login_to;
	if ((find_str(file_clients, login_to) == true) || (find_str(ban, login_to) == true)) {
		bool law = false;
		if (login_from == login_to)
			law = true;
		if (filestr(dir_clients + '\\' + login_from + info_client, 2) == Adm_on) {
			if (filestr(dir_clients + '\\' + login_to + info_client, 2) != Adm_on)
				law = true;
		}
		else
			if (filestr(dir_clients + '\\' + login_to + info_client, 2) == adm_off)
				law = true;
		if (law == true) {
			string password;
			string balance = filestr(dir_clients + '\\' + login_to + info_client, 1);
			string status = filestr(dir_clients + '\\' + login_to + info_client, 2);
			set_warn(w_password, 0);
			cin >> password;
			mkfile(dir_clients + '\\' + login_to + info_client, { password, balance, status });
		}
		else
			set_warn(w_not_right, 1);
	}
	else
		set_warn(w_not_found_login, 1);
}

void change_status(string login_from) {
	string login_to;
	set_warn(w_login, 0);
	cin >> login_to;
	if (((find_str(file_clients, login_to) == true) || (find_str(ban, login_to) == true)) && (login_to != login_from)) {
		bool law = false;
		if (filestr(dir_clients + '\\' + login_from + info_client, 2) == Adm_on) {
			if (filestr(dir_clients + '\\' + login_to + info_client, 2) != Adm_on)
				law = true;
		}
		else
			if (filestr(dir_clients + '\\' + login_to + info_client, 2) == adm_off)
				law = true;
		if (law == true) {
			string old_status = filestr(dir_clients + '\\' + login_to + info_client, 2);
			string status;
			string syst_messege{};
			{
				if (old_status == adm_off)
					old_status = gamer;
				else
					old_status = second;
			}

			set_warn(w_status, 0);
			cin >> status;
			syst_messege = login_to + " получил(а) статус [" + status + "].\tПредыдущий статус [" + old_status + "]\tИзменил(а) статус " + login_from;

			if (status == second)
				status = adm_on;
			else if (status == gamer)
				status = adm_off;

			if ((status == adm_on) || (status == adm_off)) {
				string password = filestr(dir_clients + '\\' + login_to + info_client, 0);
				string balance = filestr(dir_clients + '\\' + login_to + info_client, 1);
				mkfile(dir_clients + '\\' + login_to + info_client, { password, balance, status });
				system_news(syst_messege);
			}
			else
				set_warn(w_false, 1);
		}
		else
			set_warn(w_not_right, 1);
	}
	else
		set_warn(w_not_found_login, 1);
}

void fban(string login_from) {
	string login_to;
	set_warn(w_login, 0);
	cin >> login_to;
	if ((find_str(file_clients, login_to) == true) && (login_to != login_from)) {
		bool law = false;
		if (filestr(dir_clients + '\\' + login_from + info_client, 2) == Adm_on) {
			if (filestr(dir_clients + '\\' + login_to + info_client, 2) != Adm_on)
				law = true;
		}
		else
			if (filestr(dir_clients + '\\' + login_to + info_client, 2) == adm_off)
				law = true;
		if (law == true) {
			del_str(file_clients, indexStrFile(file_clients, login_to));
			SetBackToFile(ban, login_to);
			csort(ban);
			system_news(login_to + " забанен(а) " + login_from);
		}
		else
			set_warn(w_not_right, 1);
	}
	else
		set_warn(w_not_found_login, 1);
}

void pardon(string login_from) {
	string login_to;
	set_warn(w_login, 0);
	cin >> login_to;
	if ((find_str(ban, login_to) == true) && (login_from != login_to)) {
		bool law = false;
		if (filestr(dir_clients + '\\' + login_from + info_client, 2) == Adm_on) {
			if (filestr(dir_clients + '\\' + login_to + info_client, 2) != Adm_on)
				law = true;
		}
		else
			if (filestr(dir_clients + '\\' + login_to + info_client, 2) == adm_off)
				law = true;
		if (law == true) {
			del_str(ban, indexStrFile(ban, login_to));
			SetBackToFile(file_clients, login_to);
			csort(file_clients);
			system_news(login_to + " разбанен(а) " + login_from);
		}
		else
			set_warn(w_not_right, 1);
	}
	else
		set_warn(w_not_found_login, 1);
}

void del_cl(string login) {
	string ask = "";
	set_warn(w_sure, 0);
	cin >> ask;
	if (ask == "да") {
		if (find_str(file_clients, login) == true) {
			del_str(file_clients, indexStrFile(file_clients, login));
			fs::remove_all(dir_clients + '\\' + login);
		}
		else if (find_str(ban, login) == true) {
			del_str(ban, indexStrFile(ban, login));
			fs::remove_all(dir_clients + '\\' + login);
			system_news(login + "удалил(а) свой аккаунт");
		}
		else
			set_warn(w_not_found_login, 1);
	}
	else if (ask == "нет")
		return;
	else
		set_warn(w_false, 1);
}

void adm_del_acc(string login_from) {
	string login_to;
	set_warn(w_login, 0);
	cin >> login_to;
	if (((find_str(file_clients, login_to) == true) || (find_str(ban, login_to) == true)) && (login_from != login_to)) {
		bool law = false;
		if (filestr(dir_clients + '\\' + login_from + info_client, 2) == Adm_on) {
			if (filestr(dir_clients + '\\' + login_to + info_client, 2) != Adm_on)
				law = true;
		}
		else
			if (filestr(dir_clients + '\\' + login_to + info_client, 2) == adm_off)
				law = true;
		if (law == true) {
			del_cl(login_to);
		}
		else
			set_warn(w_not_right, 1);
	}
	else
		set_warn(w_not_found_login, 1);
}

void mk_message(string login_from, string login_to, string mess) {
	string way_to_list_of_chat = dir_clients + '\\' + login_to + file_messenger;
	string way_to_chat = dir_clients + '\\' + login_to + dir_messenger + '\\' + login_from + ".txt";
	if (find_str(way_to_list_of_chat, login_from) == false) {
		SetBackToFile(way_to_list_of_chat, login_from);
		csort(way_to_list_of_chat);
		mkfile(way_to_chat, {});
	}
	SetFrontToFile(way_to_chat, mess);
}

void messege(string login_from) {
	string login_to, mess;
	set_warn(w_address, 0);
	cin >> login_to;
	if (login_to != login_from) {
		if ((find_str(file_clients, login_to) == true) || (find_str(ban, login_to) == true)) {
			if (find_str(dir_clients + '\\' + login_to + file_black_list, login_from) == false) {
				set_warn(w_messege, 0);
				cin.clear();
				cin.ignore(100, '\n');
				getline(cin, mess);
				mess = login_from + ":> " + mess;
				mk_message(login_from, login_to, mess);
				mk_message(login_to, login_from, mess);
				if (find_str(dir_clients + '\\' + login_to + new_messeges, login_from) == false)
					SetFrontToFile(dir_clients + '\\' + login_to + new_messeges, login_from);
				csort(dir_clients + '\\' + login_to + new_messeges);
			}
			else {
				cout << login_to;
				set_warn(w_you_blocked, 1);
			}
		}
		else
			set_warn(w_not_found_login, 1);
	}
	else
		set_warn(w_not_right, 1);
}

void show_messege(string login) {
	string login_from;
	char mode;
	int imod;
	set_warn(w_login, 0);
	cin >> login_from >> mode;
	switch (mode) {
	case 'н':
		imod = 9;
		break;
	case 'с':
		imod = 19;
		break;
	case 'д':
		imod = 49;
		break;
	default:
		set_warn(w_not_right, 1);
		return;
		break;
	}
	if (find_str(dir_clients + '\\' + login + file_messenger, login_from) == true) {
		if (filesize(dir_clients + '\\' + login + dir_messenger + '\\' + login_from + ".txt") - 1 < imod)
			imod = filesize(dir_clients + '\\' + login + dir_messenger + '\\' + login_from + ".txt") - 1;
		set_warn(w_chat, 1);
		for (int i = imod; i > -1; --i)
			if (filestr(dir_clients + '\\' + login + dir_messenger + '\\' + login_from + ".txt", i) != "")
				cout << filestr(dir_clients + '\\' + login + dir_messenger + '\\' + login_from + ".txt", i) << ";\n";
		del_str(dir_clients + '\\' + login + new_messeges, indexStrFile(dir_clients + '\\' + login + new_messeges, login_from));
	}
	else
		set_warn(w_not_found_login, 1);
}

void show_writers(string login) {
	if ((filesize(dir_clients + '\\' + login + file_messenger) == 1) && (filestr(dir_clients + '\\' + login + file_messenger, 0) == ""))
		set_warn(w_not_chat, 1);
	else
		for (size_t i = 0; i < filesize(dir_clients + '\\' + login + file_messenger); ++i)
			if (filestr(dir_clients + '\\' + login + file_messenger, i) != "")
				cout << i + 1 << ". " << filestr(dir_clients + '\\' + login + file_messenger, i) << ";\n";
}

void show_new_messegenger(string login) {
	string way_to_file = dir_clients + '\\' + login + new_messeges;
	if (filesize(way_to_file) > 1) {
		int size = filesize(way_to_file) - 1;
		for (int i = 0; i < size; ++i)
			printf("%3d%20s\n", i + 1, filestr(way_to_file, i).c_str());
	}
	else
		set_warn(w_no_new_messege, 1);
}

void add_black_list(string login) {
	string login_to;
	set_warn(w_login, 0);
	cin >> login_to;
	if (login != login_to) {
		if ((find_str(file_clients, login_to) == true) || (find_str(ban, login_to) == true)) {
			SetBackToFile(dir_clients + '\\' + login + file_black_list, login_to);
			csort(dir_clients + '\\' + login + file_black_list);
		}
		else
			set_warn(w_not_found_login, 1);
	}
	else
		set_warn(w_not_right, 1);
}

void del_black_list(string login) {
	string login_to;
	set_warn(w_login, 0);
	cin >> login_to;
	if (find_str(dir_clients + '\\' + login + file_black_list, login_to) == true)
		del_str(dir_clients + '\\' + login + file_black_list, indexStrFile(dir_clients + '\\' + login + file_black_list, login_to));
	else
		set_warn(w_not_found_login, 1);
}

void give_money(string login_from) {
	string login_to;
	set_warn(w_login, 0);
	cin >> login_to;
	if (login_to != login_from) {
		if ((find_str(file_clients, login_to) == true) || (find_str(ban, login_to) == true)) {
			int balance_login_from = to_double(filestr(dir_clients + '\\' + login_from + info_client, 1));
			int balance_login_to = to_double(filestr(dir_clients + '\\' + login_to + info_client, 1));
			string password_login_from = filestr(dir_clients + '\\' + login_from + info_client, 0);
			string password_login_to = filestr(dir_clients + '\\' + login_to + info_client, 0);
			string status_login_from = filestr(dir_clients + '\\' + login_from + info_client, 2);
			string status_login_to = filestr(dir_clients + '\\' + login_to + info_client, 2);
			int money = 0;

			money = get_double(w_coin);

			if (money > 0) {
				if (money <= balance_login_from) {
					string mess;
					balance_login_from -= money;
					balance_login_to += money;
					mkfile(dir_clients + '\\' + login_from + info_client, { password_login_from, to_string(balance_login_from), status_login_from });
					mkfile(dir_clients + '\\' + login_to + info_client, { password_login_to, to_string(balance_login_to), status_login_to });
					mess = login_from + " -> " + to_string(money) + " -> " + login_to;
					mk_message(login_from, login_to, mess);
					mk_message(login_to, login_from, mess);
				}
				else {
					set_warn(w_not_enough_money, 0);
					cout << money - balance_login_from;
					set_warn(w_coin, 1);
				}
			}
			else
				set_warn(w_low_int, 1);

		}
		else
			set_warn(w_not_found_login, 1);
	}
	else
		set_warn(w_not_right, 1);
}

void mknews(string login) {
	int balance = to_double(filestr(dir_clients + '\\' + login + info_client, 1));
	if (balance < 10) {
		set_warn(w_not_enough_money, 0);
		cout << 10 - balance;
		set_warn(w_coin, 1);
	}
	else {
		string password = filestr(dir_clients + '\\' + login + info_client, 0);
		string status = filestr(dir_clients + '\\' + login + info_client, 2);
		balance -= 10;
		mkfile(dir_clients + '\\' + login + info_client, { password, to_string(balance), status });

		string News{};
		set_warn(w_your_news, 0);
		getline(cin, News);

		int size_news = quan(News, '\t') + 1;
		vector<string> vnews(size_news);
		for (int i = 0; i < size_news; ++i) {
			vnews[i] = parse(News, '\t', 'l');
			News = parse(News, '\t', 'r');
		}

		SetBackToFile(file_news, fen + login + fen);
		for (int i = 0; i < size_news; ++i)
			SetBackToFile(file_news, vnews[i]);
		SetBackToFile(file_news, " ");
	}
}

void show_news() {
	if (filesize(file_news) == 1)
		set_warn(w_no_news, 1);
	else {
		if (filesize(file_news) > 201) {
			vector<string> buf;
			for (int i = 0; i < 150; ++i)
				buf.push_back(filestr(file_news, i));
			mkfile(file_news, buf);
		}
		for (int i = 0; i < filesize(file_news) - 1; ++i)
			cout << filestr(file_news, i) << endl;
	}
}

void admin_news() {
	string News{};
	set_warn(w_your_news, 0);
	getline(cin, News);

	int size_news = quan(News, '\t') + 1;
	vector<string> vnews(size_news);
	for (int i = 0; i < size_news; ++i) {
		vnews[i] = parse(News, '\t', 'l');
		News = parse(News, '\t', 'r');
	}

	SetBackToFile(file_news, fen + first + fen);
	for (int i = 0; i < size_news; ++i)
		SetBackToFile(file_news, vnews[i]);
	SetBackToFile(file_news, " ");
}

void casino_percent() {
	cout << filestr(persent_of_casino, 0);
	set_warn(w_persent, 1);
}

void change_casino_percent() {
	int percent = get_double(w_persent);
	mkfile(persent_of_casino, { to_string(percent) });
	set_warn(w_successed_changes, 1);
}

void show_all_balance(string login_from) {
	vector<string> accounts;
	string status_from = filestr(dir_clients + '\\' + login_from + info_client, 2);
	{//filling vector of accounts
		int size_on = filesize(file_clients) - 1;
		int size_off = filesize(ban) - 1;
		for (int i = 0; i < size_on; ++i)
			accounts.push_back(filestr(file_clients, i));
		for (int i = 0; i < size_off; ++i)
			accounts.push_back(filestr(ban, i));
	}
	if (accounts.size() > 0) {
		vector<string> res;
		for (int i = 0; i < accounts.size(); ++i) {
			string login_to = accounts[i];
			string status_to = filestr(dir_clients + '\\' + login_to + info_client, 2);
			bool add = false;
			if (login_from == login_to)
				add = true;
			else if (status_from == Adm_on) {
				if (status_to != Adm_on)
					add = true;
			}
			else {
				if (status_to == adm_off)
					add = true;
			}
			if (add == true) {
				res.push_back(login_to + "\t" + filestr(dir_clients + '\\' + accounts[i] + info_client, 1));
			}
		}
		for (int i = 0; i < res.size(); ++i)
			printf("%4d %20s %10s \n", i + 1, parse(res[i], '\t', 'l').c_str(), parse(res[i], '\t', 'r').c_str());
	}
	else
		set_warn(w_no_log, 1);
}

void regist() {
	string login = "";
	set_warn(w_login, 0);
	while (cin >> login) {
		if (login == "стоп")
			return;
		if ((login.size() >= 6) && (login.size() < 20))
			break;
		else {
			set_warn(w_no_log, 1); set_warn(w_login, 0);
		}
	}
	if ((find_str(file_clients, login) == true) || (find_str(ban, login) == true)) {
		set_warn(w_change_login, 1);
	}
	else if (find_str(file_clients, login) == false) {
		vector <string> mkclient;
		string password;
		string news = "Встречаем нового игрока \"" + login + '\"' ;
		set_warn(w_password, 0);
		while (cin >> password) {
			if (password == "стоп")
				return;
			if ((password.size() >= 8) && (password.size() < 20))
				break;
			else {
				set_warn(w_no_password, 1); set_warn(w_password, 0);
			}
		}
		mkclient.push_back(password);
		mkclient.push_back(to_string(start_coin));
		mkclient.push_back(adm_off);
		mkfile(dir_clients + "\\" + login + info_client, mkclient);
		mkfile(dir_clients + "\\" + login + purchase, { });
		mkfile(dir_clients + '\\' + login + file_messenger, { });
		mkfile(dir_clients + '\\' + login + file_black_list, { });
		mkfile(dir_clients + '\\' + login + mi_shop, { });
		mkfile(dir_clients + '\\' + login + new_messeges, { });
		mkfile(dir_clients + '\\' + login + file_preparation, { });
		SetBackToFile(file_clients, login);
		csort(file_clients);
		system_news(news);
		set_warn(w_successful_regist, 1);
	}
}

void working(string login) {
	//system("cls");
	string command;
	while (true) {
		{
			if (find_str(ban, login) == true) {
				set_warn(w_you_ban, 1);
				return;
			}
			else if (find_str(file_clients, login) == false) {
				set_warn(w_you_delete, 1);
				return;
			}
		}
		string status = "", file_status = filestr(dir_clients + '\\' + login + info_client, 2);
		{
			if (file_status == adm_off) {
				file_status = permit_commands_g;
				status = gamer;
			}
			else if (file_status == adm_on) {
				file_status = permit_commands_a;
				status = second;
			}
			else if (file_status == Adm_on) {
				file_status = permit_commands_ca;
				status = first;
			}
		}

		cout << login << '[' << status << "]> ";

		getline(cin, command);
		if (command == "")
			getline(cin, command);

		system("cls");

		{
			if (find_str(ban, login) == true) {
				set_warn(w_you_ban, 1);
				return;
			}
			else if (find_str(file_clients, login) == false) {
				set_warn(w_you_delete, 1);
				return;
			}
		}

		if (find_str(file_status, command) == true) {
			if (command == "выход")
				break;
			else if (command == "баланс")
				balance(login);
			else if (command == "аккаунты")
				accounts(login);
			else if (command == "фабрика")
				show_shop();
			else if (command == "заказать")
				buy(login);
			else if (command == "покупки")
				show_buying(login);
			else if (command == "вернуть")
				sale(login);
			else if (command == "казино")
				casino(login);
			else if (command == "подсчёты")
				counting_game(login);
			else if (command == "переводчик")
				translate(login);
			else if (command == "баланс игрок")
				cl_balance(login);
			else if (command == "изменить баланс")
				change_balance(login);
			else if (command == "пароль")
				cl_password(login);
			else if (command == "изменить пароль")
				change_password(login);
			else if (command == "изменить статус")
				change_status(login);
			else if (command == "бан")
				fban(login);
			else if (command == "пардон")
				pardon(login);
			else if (command == "удалить аккаунт") {
				del_cl(login);
				break;
			}
			else if (command == "удалить клиента")
				adm_del_acc(login);
			else if (command == "письмо")
				messege(login);
			else if (command == "прочитать")
				show_messege(login);
			else if (command == "все письма")
				show_writers(login);
			else if (command == "письма")
				show_new_messegenger(login);
			else if (command == "перевод")
				give_money(login);
			else if (command == "блок")
				add_black_list(login);
			else if (command == "разблок")
				del_black_list(login);
			else if (command == "продать")
				make_purchase(login);
			else if (command == "продажи")
				show_my_mi_shop(login);
			else if (command == "удалить товар")
				delete_purch(login);
			else if (command == "магазин")
				show_privet_purchase();
			else if (command == "купить")
				buy_privet_purch(login);
			else if (command == "змейка")
				game_snake(login);
			else if (command == "бан лист")
				ban_list();
			else if (command == "создать новость")
				mknews(login);
			else if (command == "новости")
				show_news();
			else if (command == "оповещение")
				admin_news();
			else if (command == "магазины")
				show_all_purch();
			else if (command == "изменить казино")
				change_casino_percent();
			else if (command == "казино процент")
				casino_percent();
			else if (command == "балансы")
				show_all_balance(login);
			else if (command == "крафт")
				mkcraft(login);
			else if (command == "инст")
				show_possible_craft(login);
			else if (command == "подготовки")
				show_preparation(login);
			cout << endl;
		}
		else
			set_warn(w_no_permissions, 1);
	}
	system("cls");
}

void checkin() {
	string login = "";
	set_warn(w_login, 0);
	cin >> login;
	if (!find_str(file_clients, login))
		set_warn(w_not_found_login, 1);
	else {
		string password = "";
		char symbol = ' ';
		set_warn(w_password, 0);
		while (symbol = _getch()) {
			if (symbol == '\r')
				break;
			else if ((symbol == '\b') && (password.size() > 0)) {
				password = password.substr(0, password.size() - 1);
				cout << "\b \b";
			}
			else if ((symbol == '\b') && (password.size() == 0)) {}
			else {
				password += symbol;
				cout << '*';
			}
		}
		cout << endl;
		string way_to_file = dir_clients + '\\' + login + info_client;
		if (filestr(way_to_file, 0) == password) {
			working(login);
			return;
		}
		else
			set_warn(w_incorrect_password, 1);
	}
}
