#include <iostream>
#include <string>
#include <time.h>
#include <stdlib.h>

using namespace std;

struct Player {

	string name;
	int score;
};

Player* gamePlayer = new Player[100];

string aleatoryName(int sizeName = 10) {

	string name;

	char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	for (int i = 0; i < sizeName; i++) {
		name += alphabet[rand() % (sizeof(alphabet) - 1)];
	}

	return name;
}

Player aleatoryPlayer() {

	Player player;

	player.name = aleatoryName();
	player.score = rand() % 100 + 1;

	return player;
}

void createPlayers() {

	for (int i = 0; i < 100; i++) {
		gamePlayer[i] = aleatoryPlayer();
	}
}

bool run = true;

int insertionSort(Player* player, int size)
{
	int i, j;
	Player aux;

	for (i = 1; i < size; i++) {
		aux = player[i];

		for (j = i - 1; j >= 0 && player[j].name > aux.name; j--) {
			player[j + 1] = player[j];
		}

		player[j + 1] = aux;
	}

	return 0;
}

void showNamesByOrder() {

	insertionSort(gamePlayer, 100);

	for (int i = 0; i < 100; i++) {
		cout << i + 1 << "º - " << gamePlayer[i].name <<": "<<gamePlayer[i].score<< " \n";
	}
	cout << endl;
}

int partition(Player* player, int left, int right) {

	int pivot = player[right].score;
	int i = left - 1;

	for (int j = left; j < right; j++) {
		if (player[j].score >= pivot) {
			i++;

			Player temp = player[i];
			player[i] = player[j];
			player[j] = temp;
		}
	}

	Player temp = player[i + 1];
	player[i + 1] = player[right];
	player[right] = temp;

	return i + 1;
}

void quickSort(Player* player, int left, int right) {

	if (left < right) {
		int pivot = partition(player, left, right);

		quickSort(player, left, pivot - 1);
		quickSort(player, pivot + 1, right);
	}
}

void showTenBestPositions() {

	quickSort(gamePlayer, 0, 99);

	for (int i = 0; i < 10; i++) {
		cout << i + 1 << "º - " << gamePlayer[i].name << ": " << gamePlayer[i].score << endl;
	}
}

int shellSort(Player* player, int size)
{
	int i, j, k;
	Player aux;

	for (i = 0; i < size; i++) {
		for (j = i; j < size; j++) {
			if (player[i].score > player[j].score) {
				aux = player[i];
				player[i] = player[j];
				player[j] = aux;
			}
		}
	}

	for (i = 0; i < size; i++) {
		for (j = i; j < size; j++) {
			if (player[i].score < player[j].score) {
				aux = player[i];
				player[i] = player[j];
				player[j] = aux;
			}
		}
	}

	for (i = 0; i < size; i++) {
		for (j = i; j < size; j++) {
			if (player[i].score == player[j].score) {
				for (k = 0; k < size; k++) {
					if (player[i].name > player[j].name) {
						aux = player[i];
						player[i] = player[j];
						player[j] = aux;
					}
				}
			}
		}
	}

	return 0;
}

void showHundredBestPositions() {

	shellSort(gamePlayer, 100);

	for (int i = 0; i < 100; i++) {
		cout << i + 1 << "º - " << gamePlayer[i].name << ": " << gamePlayer[i].score << endl;
	}
}

void showPlayers(){

	for (int i = 0; i < 100; i++) {
		cout << i + 1 << "º - " << gamePlayer[i].name << ": " << gamePlayer[i].score << endl;
	}
}

void menu() {

	while (run)
	{
		createPlayers();

		run = false;

		menu();
	}

	int choice;

	cout << "\t\tMENU\n\n";
    cout << "1 - Exibir jogadores e pontuações sem ordem\n";
	cout << "2 - Exibir jogadores em ordem alfabética\n";
	cout << "3 - Exibir as 10 melhores pontuações\n";
	cout << "4 - Exibir as 100 melhores pontuações\n";
	cout << "5 - Sair\n\n";
	cout << "Digite sua escolha: ";
	cin >> choice;

	switch (choice)
	{
    case 1:
		system("cls");
		cout << "Jogadores e pontuações\n\n";
		showPlayers();
		cout << "\n\n";
		system("pause");
		system("cls");
		menu();
		break;
	case 2:
		system("cls");
		cout << "Nome dos jogadores em ordem alfabética\n\n";
		showNamesByOrder();
		cout << "\n\n";
		system("pause");
		system("cls");
		menu();
		break;
	case 3:
		system("cls");
		cout << "10 melhores pontuações\n\n";
		showTenBestPositions();
		cout << "\n\n";
		system("pause");
		system("cls");
		menu();
		break;
	case 4:
		system("cls");
		cout << "100 melhores pontuações\n\n";
		showHundredBestPositions();
		cout << "\n\n";
		system("pause");
		system("cls");
		menu();
		break;
	case 5:
		system("cls");
		system("color 04");
		cout << "Saindo...";
		exit(1);
		break;
	default:
		cout << "\nValor inválido\n\n";
		system("pause");
		system("cls");
		menu();
		break;
	}
}

int main()
{
	setlocale(LC_ALL, "Portuguese");

	srand(time(NULL));

	menu();

	return 0;
}
