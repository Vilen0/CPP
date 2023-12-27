/* #include <iostream>
#include <bitset>
#include <cassert>
#include <sstream>
//абстрактный класс
class BaseClass {
public:

        BaseClass(const string& id) : id(id) {}

        void ShowId() const {
            cout << "ID: " << id << endl;
        }
        //чисто виртуальная функция
        //абстрактные методы
        virtual void ShowBin() const = 0;
        virtual void ShowOct() const = 0;
        virtual void ShowHex() const = 0;
        virtual void ShowValue() const = 0;
        
        protected:
        string id;
 };
   


class T1 : public BaseClass {
public:

    T1(const string& id, const string& value) : BaseClass(id), value(value) {}

    void ShowBin() const override {
        cout << "Двоичная строка: " << "Не реализовано" << endl;
    }

    void ShowOct() const override {
        cout << "Восьмеричная строка: " << "Не реализовано" << endl;
    }

    void ShowHex() const override {
        cout << "Шестнадцатеричная строка: " << "Не реализовано" << endl;
    }

    void ShowValue() const override {
        cout << "Значение: " << value << endl;
    }
    
    private:
    string value;
};

class T2 : public BaseClass {
    public:
    T2(const string& id, int value) : BaseClass(id), value(value) {}

    void ShowBin() const override {
        cout << "Двоичная строка: " << bitset<32>(value) << endl;
    }

    void ShowOct() const override {
        cout << "Восьмеричная строка: " << oct << value << endl;
    }

    void ShowHex() const override {
        cout << "Шестнадцатеричная строка: " << hex << value << endl;
    }

    void ShowValue() const override {
        cout << "Значение: " << value << endl;
    }
        
    private:
    int value;
};

class Factory {
public:
    static BaseClass* CreateT1(const string& id, const string& value) {
        return new T1(id, value);
    }

    static BaseClass* CreateT2(const string& id, int value) {
        return new T2(id, value);
    }

    static void DeleteObject(BaseClass* obj) {
        delete obj;
    }
};

void testT1() {
    // Создаем объект T1
    BaseClass* obj = Factory::CreateT1("ID_T1", "Value_T1");

    // Захватываем стандартный вывод
    stringstream output;
    streambuf* coutBuffer = cout.rdbuf();
    cout.rdbuf(output.rdbuf());

    // Вызываем методы для вывода
    obj->ShowId();
    obj->ShowValue();
    obj->ShowBin();
    obj->ShowOct();
    obj->ShowHex();

    // Сравниваем полученный вывод с ожидаемым результатом
    assert(output.str() == "ID: ID_T1\nЗначение: Value_T1\nДвоичная строка: Не реализовано\nВосьмеричная строка: Не реализовано\nШестнадцатеричная строка: Не реализовано\n");

    // Освобождаем ресурсы
    cout.rdbuf(coutBuffer);
    Factory::DeleteObject(obj);
}


void testT2() {
    // Создаем объект T2
    BaseClass* obj = Factory::CreateT2("ID_T2", 42);

    // Захватываем стандартный вывод
    stringstream output;
    streambuf* coutBuffer = cout.rdbuf();
    cout.rdbuf(output.rdbuf());

    // Вызываем методы для вывода
    obj->ShowId();
    obj->ShowValue();
    obj->ShowBin();
    obj->ShowOct();
    obj->ShowHex();

    // Сравниваем полученный вывод с ожидаемым результатом
    assert(output.str() == "ID: ID_T2\nЗначение: 42\nДвоичная строка: 00000000000000000000000000101010\nВосьмеричная строка: 52\nШестнадцатеричная строка: 2a\n");

    // Освобождаем ресурсы
    cout.rdbuf(coutBuffer);
    Factory::DeleteObject(obj);
}



int main() {
    setlocale(LC_ALL, "Russian");
    // Вызываем тесты
    testT1();
    testT2();

    cout << "Все тесты пройдены успешно!" << endl;


    BaseClass* obj = nullptr;
    int choice;
    

    do {
        cout << "\n1. Создать и выполнить операции для T1" << endl;
        cout << "2. Создать и выполнить операции для T2" << endl;
        cout << "0. Выход \n" << endl;

        cout << "Введите команду: \n";
        cin >> choice;

        switch (choice) {
        case 1: {
            string id, value;
            cout << "Введите ID для T1: ";
            cin >> id;
            cout << "Введите Значение для T1: ";
            cin >> value;
            obj = Factory::CreateT1(id, value);
            break;
        }
        case 2: {
            string id;
            int value;
            cout << "Введите ID для T2: ";
            cin >> id;
            cout << "Введите Значение для T2: ";
            cin >> value;
            obj = Factory::CreateT2(id, value);
            break;
        }
        case 0:
            cout << "Выход из программы." << endl;
            break;
        default:
            cout << "Неизвестная команда." << endl;
        }

        // Проверяем, что obj не равен nullptr, перед выполнением операций
        if (obj != nullptr) {
            obj->ShowId();
            obj->ShowValue();
            obj->ShowBin();
            obj->ShowOct();
            obj->ShowHex();
            Factory::DeleteObject(obj);
            obj = nullptr;
        }

    } while (choice != 0);

    return 0;
}
*/