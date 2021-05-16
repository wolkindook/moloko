#include <iostream>
#include <string>

using namespace std;

int main() {
	setlocale(0, "");

	int num;
	cout << "¬ведите:\n1 - если хотите «јЎ»‘–ќ¬ј“№ текст\n2 - если хотите –ј—Ў»‘–ќ¬ј“№ текст\n»ли любую другую клавишу, чтобы выйти\n";
	cin >> num;
	cin.ignore();
	do {

		if (num == 1) {
			string text;
			string key;

			cout << "¬ведите текст, который нужно зашифровать:\n";
			getline(cin, text);

			//условие осуществлени€ шифровани€
			do {
				cout << "\n¬ведите ключ-слово длиной равной длине текста (" << text.size() << " символ.):\n";
				getline(cin, key);
			} while (key.size() != text.size());

			//массивы с алфавитом
			char eng_alph_a[] = "abcdefghijklmnopqrstuvwxyz";
			char eng_alph_A[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

			//создаем массив длиной текста дл€ хранени€ пор€дкового номера букв в тексте
			int *arr_text = new int[text.size()];

			//посимвольное сравнивание и добавление в массив
			int n = 0;
			for (int i = 0; i <= text.size(); i++) {
				for (int j = 0; j <= 26; j++) {
					if ((text[i] == eng_alph_a[j]) || (text[i] == eng_alph_A[j])) {
						arr_text[n] = j;
						n++;
					}
				}
			}

			//создаем массив длиной ключа дл€ хранени€ пор€дкового номера букв в ключе
			int *arr_key = new int[key.size()];

			//посимвольное сравнивание и добавление в массив
			n = 0;
			for (int i = 0; i <= key.size(); i++) {
				for (int j = 0; j <= 26; j++) {
					if ((key[i] == eng_alph_a[j]) || (key[i] == eng_alph_A[j])) {
						arr_key[n] = j;
						n++;
					}
				}
			}


			cout << "\n–езультат шифровани€:\n";
			// сложение элементов в массиве
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
			cout << "¬ведите текст, который нужно расшифровать:\n";
			getline(cin, shifr_text);

			//условие осуществлени€ расшифровани€
			do {
				cout << "\n¬ведите ключ-слово длиной равной длине текста (" << shifr_text.size() << " символ.):\n";
				getline(cin, key);
			} while (key.size() != shifr_text.size());

			//массивы с алфавитом
			char eng_alph_a[] = "abcdefghijklmnopqrstuvwxyz";
			char eng_alph_A[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

			//создаем массив длиной текста дл€ хранени€ пор€дкового номера букв в тексте
			int *arr_shifr_text = new int[shifr_text.size()];

			//посимвольное сравнивание и добавление в массив
			int n = 0;
			for (int i = 0; i <= shifr_text.size(); i++) {
				for (int j = 0; j <= 26; j++) {
					if ((shifr_text[i] == eng_alph_a[j]) || (shifr_text[i] == eng_alph_A[j])) {
						arr_shifr_text[n] = j;
						n++;
					}
				}
			}

			//создаем массив длиной ключа дл€ хранени€ послед. пор€дуовых номеров букв в ключе
			int *arr_key = new int[key.size()];

			//посимвольное сравнивание и добавление в массив
			n = 0;
			for (int i = 0; i <= key.size(); i++) {
				for (int j = 0; j <= 26; j++) {
					if ((key[i] == eng_alph_a[j]) || (key[i] == eng_alph_A[j])) {
						arr_key[n] = j;
						n++;
					}
				}
			}


			cout << "\n–езультат расшифровани€:\n";
			// поиск зашифрованного слова
			for (int k = 0; k <= shifr_text.size() - 1; k++) {
				if ((arr_shifr_text[k] - arr_key[k]) < 0)
					cout << eng_alph_a[26 + (arr_shifr_text[k] - arr_key[k])];
				else {
					cout << eng_alph_a[arr_shifr_text[k] - arr_key[k]];
				}
			}
		}

		cout << "\n¬ведите:\n1 - если хотите «јЎ»‘–ќ¬ј“№ текст\n2 - если хотите –ј—Ў»‘–ќ¬ј“№ текст\n»ли другую любую клавишу, чтобы выйти\n";
		cin >> num;

	} while (num == 1 || num == 2);

	return 0;
}