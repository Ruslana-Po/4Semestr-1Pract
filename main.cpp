
#include "Header.h"

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
	//Авторизация
    while (true) {
        cout << "Меню:\n";
        cout << "1. Войти\n";
        cout << "2. Зарегистрироваться\n";
        cout << "3. Выйти\n";
        cout << "Выберите действие (1-3): ";
        int number;
        cin >> number;
        if (number == 1) {
            system("pause");
            system("cls");
            login();
        }
        else if (number == 2) {
            system("pause");
            system("cls");
            registerUsers();
        }
        else if (number == 3) {
            break;
        }
        else {
            cout << "Неверный ввод значений. Попробуйте, пожалуйста, еще раз.\n";
            system("pause");
            system("cls");
        }
    }
}
