#include "class.h"
using namespace Prog2;

int main() {
    setlocale(LC_ALL, "Russian");
    srand(time(NULL));

    try {
        int choice;
        Characteristic characteristic;
        CharacteristicsTable characteristicsArray;

        while (true) {
            std::cout << "Выберите действие:" << std::endl
                << "1 - Проверить простой класс" << std::endl
                << "2 - Инициализировать простой класс" << std::endl
                << "3 - Посмотреть методы простого класса" << std::endl
                << "4 - Инициализировать сложный класс" << std::endl
                << "5 - Посмотреть методы сложного класса" << std::endl
                << "6 - Проверить сложный класс" << std::endl
                << "8 - Выйти" << std::endl;

            choice = getNum<int>(0, 8);

            switch (choice) {
            case 1:
                std::cout << "Выберите тип проверки:" << std::endl
                    << "1 - Обычная проверка" << std::endl
                    << "2 - Проверка с преимуществом" << std::endl
                    << "3 - Проверка с помехой" << std::endl;

                choice = getNum<int>(0, 3);

                switch (choice) {
                case 1:
                    std::cout << "Введите значение сложности:" << std::endl;
                    if (characteristic.check(characteristic) == 1) {
                        std::cout << "Проверка пройдена" << std::endl;
                    }
                    else {
                        std::cout << "Проверка провалена" << std::endl;
                    }
                    break;
                case 2:
                    std::cout << "Введите значение сложности:" << std::endl;
                    if (characteristic.checkWithAdvantage(characteristic) == 1) {
                        std::cout << "Проверка пройдена" << std::endl;
                    }
                    else {
                        std::cout << "Проверка провалена" << std::endl;
                    }
                    break;
                case 3:
                    std::cout << "Введите значение сложности:" << std::endl;
                    if (characteristic.checkWithDisadvantage(characteristic) == 1) {
                        std::cout << "Проверка пройдена" << std::endl;
                    }
                    else {
                        std::cout << "Проверка провалена" << std::endl;
                    }
                    break;
                }
                break;
            case 2:
                std::cout << "Выберите способ инициализации:" << std::endl
                    << "1 - Инициализировать название" << std::endl
                    << "2 - Инициализировать название и значение характеристики" << std::endl;

                choice = getNum<int>(0, 2);

                switch (choice) {
                case 1:
                    characteristic = characteristic.InitializaName();
                    break;
                case 2:
                    characteristic = characteristic.Initializa();
                    break;
                }
                break;
            case 3:
                std::cout << "Выберите действие:" << std::endl
                    << "1 - Увеличить значение характеристики на заданное число" << std::endl
                    << "2 - Вывести итоговую характеристику" << std::endl;

                choice = getNum<int>(0, 2);

                switch (choice) {
                case 1:
                    int SetCharacteristic;
                    SetCharacteristic = getNum<int>(0);
                    characteristic += SetCharacteristic;
                    std::cout << characteristic.getvalue() << std::endl;
                    break;
                case 2:
                    std::cout << characteristic << std::endl;
                    break;
                }
                break;
            case 4:
                std::cout << "Выберите способ инициализации:" << std::endl
                    << "1 - Инициализировать массив характеристик" << std::endl
                    << "2 - Инициализировать с одной характеристикой" << std::endl;

                choice = getNum<int>(0, 2);

                switch (choice) {
                case 1: {
                    int numElements;
                    std::cout << "Введите количество элементов:" << std::endl;
                    numElements = getNum<int>(1);

                    Characteristic* characteristics = new Characteristic[numElements];

                    for (int i = 0; i < numElements; i++) {
                        std::cout << "Введите характеристику:" << std::endl;
                        characteristics[i].set(getNum());
                    }

                    characteristicsArray = CharacteristicsTable(characteristics, numElements);

                    delete[] characteristics;
                    break;
                }
                case 2: {
                    Characteristic characteristic1;
                    characteristic1 = characteristic1.Initializa();
                    characteristicsArray = CharacteristicsTable(characteristic1);
                    break;
                }
                }
                break;
            case 5:
                std::cout << "Выберите действие:" << std::endl
                    << "1 - Получить характеристику по её названию" << std::endl
                    << "2 - Добавить новую характеристику" << std::endl
                    << "3 - Вывести таблицу характеристик" << std::endl
                    << "4 - Начать поиск характеристики с максимальным значением" << std::endl
                    << "5 - Отсортировать по длине названия" << std::endl;

                choice = getNum<int>(0, 5);

                switch (choice) {
                case 1:
                    characteristic = characteristic.InitializaName();
                    std::cout << "Характеристика " << characteristic.getName() << " = " << characteristicsArray[characteristic.getName()] << std::endl;
                    break;
                case 2:
                    characteristic = characteristic.Initializa();
                    characteristicsArray += characteristic;
                    break;
                case 3:
                    characteristicsArray.Print();
                    break;
                case 4:
                    std::cout << "Максимальная характеристика: " << characteristicsArray.findMaxCharacteristic() << std::endl;
                    break;
                case 5:
                    characteristicsArray.sortByName();
                    break;
                }
                break;
            case 6:
                std::cout << "Выберите тип проверки:" << std::endl
                    << "1 - Обычная проверка" << std::endl
                    << "2 - Проверка с преимуществом" << std::endl
                    << "3 - Проверка с помехой" << std::endl;

                choice = getNum<int>(0, 3);

                switch (choice) {
                case 1:
                    characteristic = characteristic.InitializaName();
                    std::cout << "Характеристика " << characteristic.getName() << " = " << characteristicsArray[characteristic.getName()] << std::endl;
                    characteristic.set(characteristicsArray[characteristic.getName()]);
                    std::cout << "Введите значение сложности:" << std::endl;
                    if (characteristic.check(characteristic) == 1) {
                        std::cout << "Проверка пройдена" << std::endl;
                    }
                    else {
                        std::cout << "Проверка провалена" << std::endl;
                    }
                    break;
                case 2:
                    characteristic = characteristic.InitializaName();
                    std::cout << "Характеристика " << characteristic.getName() << " = " << characteristicsArray[characteristic.getName()] << std::endl;
                    characteristic.set(characteristicsArray[characteristic.getName()]);
                    std::cout << "Введите значение сложности:" << std::endl;
                    if (characteristic.checkWithAdvantage(characteristic) == 1) {
                        std::cout << "Проверка пройдена" << std::endl;
                    }
                    else {
                        std::cout << "Проверка провалена" << std::endl;
                    }
                    break;
                case 3:
                    characteristic = characteristic.InitializaName();
                    std::cout << "Характеристика " << characteristic.getName() << " = " << characteristicsArray[characteristic.getName()] << std::endl;
                    characteristic.set(characteristicsArray[characteristic.getName()]);
                    std::cout << "Введите значение сложности:" << std::endl;
                    if (characteristic.checkWithDisadvantage(characteristic) == 1) {
                        std::cout << "Проверка пройдена" << std::endl;
                    }
                    else {
                        std::cout << "Проверка провалена" << std::endl;
                    }
                    break;
                }
                break;
            case 8:
                return 0;
            }
        }
    }
    catch (const std::exception& re) {
        std::cerr << re.what() << std::endl;
        return 1;
    }
}
