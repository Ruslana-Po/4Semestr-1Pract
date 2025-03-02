#include<iostream>
#include<vector>
#include<string>
#include <Windows.h>
#include <thread>
#include <chrono>

using namespace std;

// База данных пользователей 
class DataBase {
    struct User {
        string name;
        string password;
        string role; 
    };

    struct Test{
        string name;
        string description;
        string role;
    };

    struct Information{
        string name;
        string description;
        string role;
    };

    vector<User> users;
    vector<Test> test;
    vector<Information> infa;

public:
    DataBase() {
        test.push_back({ "Первая помощь", "Основы оказания первой помощи", "сотрудник" });
        test.push_back({ "Эвакуация при ЧС", "Правила эвакуации в ЧС и план здания", "посититель" });
        infa.push_back({ "Первая помощь", "Основы оказания первой помощи", "сотрудник" });
        infa.push_back({ "Эвакуация при ЧС", "Правила эвакуации в ЧС и план здания", "посититель" });
        test.push_back({ "ЧС", "Правила поведения сотрудников", "сотрудник" });
        test.push_back({ "Как спасти себя", "Описание разных ситуаций и способов выжить в них", "посититель" });
        infa.push_back({ "ЧС", "Правила поведения сотрудников", "сотрудник" });
        infa.push_back({ "Как спасти себя", "Описание разных ситуаций и способов выжить в них", "посититель" });
    }


    void addUser(string& name, string& password, string& role) {
        users.push_back({name, password, role});
    }

    string findUser(string& name) {
        for (auto& user : users) {
            if (user.name == name) {
                return "Найден";
            }
        }
        return "Не найден";
    }

    vector<Test> availableTests(string& role) {
        vector<Test> newUser;
        for (auto user : test) {
            if (user.role == role) {
                newUser.push_back(user);
            }
        }
        return newUser;
    }

    vector<Information> availableInfo(string& role) {
        vector<Information> newUser;
        for (auto user : infa) {
            if (user.role == role) {
                newUser.push_back(user);
            }
        }
        return newUser;
    }

    string whatRole(string name) {
        for (auto& user : users) {
            if (user.name == name) {
                return user.role;
            }
        }
        return "Не найден";
    }

    bool whatPassword(string name, string password) {
        for (auto& user : users) {
            if (user.name == name) {
                if (user.password == password) {
                    return true;
                }
            }
        }
        return false;
    }

};


void login();
void registerUsers();
