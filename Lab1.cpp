#include <iostream>
#include <string>

using namespace std;

int main() {
	setlocale(0, "");

	int num;
	cout << "�������:\n1 - ���� ������ ����������� �����\n2 - ���� ������ ������������ �����\n��� ����� ������ �������, ����� �����\n";
	cin >> num;
	cin.ignore();
	do {

		if (num == 1) {
			string text;
			string key;

			cout << "������� �����, ������� ����� �����������:\n";
			getline(cin, text);

			//������� ������������� ����������
			do {
				cout << "\n������� ����-����� ������ ������ ����� ������ (" << text.size() << " ������.):\n";
				getline(cin, key);
			} while (key.size() != text.size());

			//������� � ���������
			char eng_alph_a[] = "abcdefghijklmnopqrstuvwxyz";
			char eng_alph_A[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

			//������� ������ ������ ������ ��� �������� ����������� ������ ���� � ������
			int *arr_text = new int[text.size()];

			//������������ ����������� � ���������� � ������
			int n = 0;
			for (int i = 0; i <= text.size(); i++) {
				for (int j = 0; j <= 26; j++) {
					if ((text[i] == eng_alph_a[j]) || (text[i] == eng_alph_A[j])) {
						arr_text[n] = j;
						n++;
					}
				}
			}

			//������� ������ ������ ����� ��� �������� ����������� ������ ���� � �����
			int *arr_key = new int[key.size()];

			//������������ ����������� � ���������� � ������
			n = 0;
			for (int i = 0; i <= key.size(); i++) {
				for (int j = 0; j <= 26; j++) {
					if ((key[i] == eng_alph_a[j]) || (key[i] == eng_alph_A[j])) {
						arr_key[n] = j;
						n++;
					}
				}
			}


			cout << "\n��������� ����������:\n";
			// �������� ��������� � �������
			for (int k = 0; k <= text.size() - 1; k++) {
				if ((arr_text[k] + arr_key[k]) >= 26) {
					cout << eng_alph_a[abs(26 - (arr_text[k] + arr_key[k]))];
				}
				else {
					cout << eng_alph_a[(arr_text[k] + arr_key[k])];
				}
			}
		}

		else {
			string shifr_text;
			string key;

			cin.ignore();
			cout << "������� �����, ������� ����� ������������:\n";
			getline(cin, shifr_text);

			//������� ������������� �������������
			do {
				cout << "\n������� ����-����� ������ ������ ����� ������ (" << shifr_text.size() << " ������.):\n";
				getline(cin, key);
			} while (key.size() != shifr_text.size());

			//������� � ���������
			char eng_alph_a[] = "abcdefghijklmnopqrstuvwxyz";
			char eng_alph_A[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

			//������� ������ ������ ������ ��� �������� ����������� ������ ���� � ������
			int *arr_shifr_text = new int[shifr_text.size()];

			//������������ ����������� � ���������� � ������
			int n = 0;
			for (int i = 0; i <= shifr_text.size(); i++) {
				for (int j = 0; j <= 26; j++) {
					if ((shifr_text[i] == eng_alph_a[j]) || (shifr_text[i] == eng_alph_A[j])) {
						arr_shifr_text[n] = j;
						n++;
					}
				}
			}

			//������� ������ ������ ����� ��� �������� ������. ���������� ������� ���� � �����
			int *arr_key = new int[key.size()];

			//������������ ����������� � ���������� � ������
			n = 0;
			for (int i = 0; i <= key.size(); i++) {
				for (int j = 0; j <= 26; j++) {
					if ((key[i] == eng_alph_a[j]) || (key[i] == eng_alph_A[j])) {
						arr_key[n] = j;
						n++;
					}
				}
			}


			cout << "\n��������� �������������:\n";
			// ����� �������������� �����
			for (int k = 0; k <= shifr_text.size() - 1; k++) {
				if ((arr_shifr_text[k] - arr_key[k]) < 0)
					cout << eng_alph_a[26 + (arr_shifr_text[k] - arr_key[k])];
				else {
					cout << eng_alph_a[arr_shifr_text[k] - arr_key[k]];
				}
			}
		}

		cout << "\n�������:\n1 - ���� ������ ����������� �����\n2 - ���� ������ ������������ �����\n��� ������ ����� �������, ����� �����\n";
		cin >> num;

	} while (num == 1 || num == 2);

	return 0;
}