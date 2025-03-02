
#include "Header.h"

class Application {
    DataBase data;
public:
    bool registerUser(string& name, string& password, string& role) {
        if (data.findUser(name) != "Не найден") {
            cout << "Пользователь с таким именем уже существует.\n";
            return false;
        }
        data.addUser(name, password, role);
        cout << "Пользователь " << name << " зарегистрирован.\n";
        return true;
    }

    bool entranceUser(string& name, string password) {
        if (data.findUser(name) == "Не найден") {
            cout << "Пользователь не найден.\n";
            return false;
        }
        else if (!data.whatPassword(name,password)) {
            cout << "Пароль неверный.\n";
            return false;
        }
        cout << "Добро пожаловать, " << name << ".\n";
        return true;
    }

    void showTest(string& role) {
        auto test = data.availableTests(role);
        cout << "Доступные для "<<role<<" тесты:\n";
        for (int i = 0; i < test.size(); ++i) {
            cout << i + 1 << " " << test[i].name << ": " << test[i].description << "\n";
        }
    }
    void showInfa(string& role) {
        auto infa = data.availableInfo(role);
        cout << "Доступная для " << role << " информация:\n";
        for (int i = 0; i < infa.size(); ++i) {
            std::cout << i + 1 << " " << infa[i].name << ": " << infa[i].description << "\n";
        }
    }
    string Roles(string name) {
        string role = data.whatRole(name);
        return role;
    }
    
    void readTest(string& role, string name) {
        auto test = data.availableTests(role);
        for (int i = 0; i < test.size(); ++i) {
            if (test[i].name == name) {
                cout << "Тест пройден" << endl;
                return;
            }
        }
        cout << "Данного теста нету или для вас он недоступен" << endl;
    }
    void readInfa(string& role, string name) {
        auto infa = data.availableInfo(role);
        for (int i = 0; i < infa.size(); ++i) {
            if (infa[i].name == name) {
                cout << "Информация прочитана" << endl;
                return;
            }
        }
        cout << "Данной информации нету или для вас она недоступна" << endl;
    }

};

Application Mall;
void ShowMenu(string role) {
    Application Mall;
    while (true) {
        cout << "\nМеню пользователя:\n";
        cout << "1. Показать доступную информацию\n";
        cout << "2. Показать доступные тесты\n";
        cout << "3. Прочитать информацию\n";
        cout << "4. Пройти тест\n";
        if (role == "сотрудник") {
            cout << "5. Подать сигнал тревоги\n";
            cout << "6. Выйти в главное меню\n";
        }
        else {
            cout << "6. Выйти в главное меню\n";
        }
        cout << "Выберите опцию: ";

        int number;
        cin >> number;

        if (number == 2) {
            Mall.showTest(role);
            system("pause");
            system("cls");
        } else if (number == 1) {
            Mall.showInfa(role);
            system("pause");
            system("cls");
        }else if (number == 3) {
            cout << "Введите название заголовка информации: ";
            string nameInf;
            cin.ignore();
            getline(cin, nameInf);
            Mall.readInfa(role, nameInf);
            system("pause");
            system("cls");
        }else if (number == 4) {
            cout << "Введите название заголовка теста: ";
            string nameInf;
            cin.ignore();
            getline(cin, nameInf);
            Mall.readInfa(role, nameInf);
            system("pause");
            system("cls");
        }else if (number == 6) {
            system("cls");
            break;
        }else if (number == 5 && role == "сотрудник") {
            int k = 10;
            system("cls");
            while (k>0) {
                cout << "SOS!" << endl;
                this_thread::sleep_for(chrono::milliseconds(500));
                system("cls");
                this_thread::sleep_for(chrono::milliseconds(500));
                k--;
            }

            system("pause");
            system("cls");
        }
        else {
            cout << "Неверный выбор. Попробуйте снова.\n";
            system("pause");
            system("cls");
        }
    }
};

void registerUsers(){
    string name;
    int role;
    string password;
    while (true) {
        cout << "Введите ваше имя: ";
        cin >> name;
        cout << "Придумайте пароль: ";
        cin >> password;
        cout << "Кто вы? \n 1 - сотрудник ТЦ \n 2 - посетитель \n";
        cin >> role;
        if (role != 1 && role != 2) {
            cout << "Неверная роль. Попробуйте еще раз. Выберите 1 или 2.\n";
            system("pause");
            system("cls");
        }else {
            break;
        }
    }
    string nameRole;
    if (role == 1) {
        nameRole = "сотрудник";
    }else {
        nameRole = "посетитель";
    }
    bool user = Mall.registerUser(name, password, nameRole);
    if (user) {
        cout << "Добро пожаловать!" << endl;
        system("pause");
        system("cls");
        ShowMenu(nameRole);
    }else {
        system("pause");
        system("cls");
    }
    
}

void login() {
    string name;
    string password;
    cout << "Введите ваше имя: ";
    cin >> name;
    cout << "Введите пароль: ";
    cin >> password;
    bool user = Mall.entranceUser(name, password);
    //Узнать роль
    string role = Mall.Roles(name);
    system("pause");
    system("cls");
    if (user) {
        ShowMenu(role);
    }
}

