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
            std::cout << "�������� ��������:" << std::endl
                << "1 - ��������� ������� �����" << std::endl
                << "2 - ���������������� ������� �����" << std::endl
                << "3 - ���������� ������ �������� ������" << std::endl
                << "4 - ���������������� ������� �����" << std::endl
                << "5 - ���������� ������ �������� ������" << std::endl
                << "6 - ��������� ������� �����" << std::endl
                << "8 - �����" << std::endl;

            choice = getNum<int>(0, 8);

            switch (choice) {
            case 1:
                std::cout << "�������� ��� ��������:" << std::endl
                    << "1 - ������� ��������" << std::endl
                    << "2 - �������� � �������������" << std::endl
                    << "3 - �������� � �������" << std::endl;

                choice = getNum<int>(0, 3);

                switch (choice) {
                case 1:
                    std::cout << "������� �������� ���������:" << std::endl;
                    if (characteristic.check(characteristic) == 1) {
                        std::cout << "�������� ��������" << std::endl;
                    }
                    else {
                        std::cout << "�������� ���������" << std::endl;
                    }
                    break;
                case 2:
                    std::cout << "������� �������� ���������:" << std::endl;
                    if (characteristic.checkWithAdvantage(characteristic) == 1) {
                        std::cout << "�������� ��������" << std::endl;
                    }
                    else {
                        std::cout << "�������� ���������" << std::endl;
                    }
                    break;
                case 3:
                    std::cout << "������� �������� ���������:" << std::endl;
                    if (characteristic.checkWithDisadvantage(characteristic) == 1) {
                        std::cout << "�������� ��������" << std::endl;
                    }
                    else {
                        std::cout << "�������� ���������" << std::endl;
                    }
                    break;
                }
                break;
            case 2:
                std::cout << "�������� ������ �������������:" << std::endl
                    << "1 - ���������������� ��������" << std::endl
                    << "2 - ���������������� �������� � �������� ��������������" << std::endl;

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
                std::cout << "�������� ��������:" << std::endl
                    << "1 - ��������� �������� �������������� �� �������� �����" << std::endl
                    << "2 - ������� �������� ��������������" << std::endl;

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
                std::cout << "�������� ������ �������������:" << std::endl
                    << "1 - ���������������� ������ �������������" << std::endl
                    << "2 - ���������������� � ����� ���������������" << std::endl;

                choice = getNum<int>(0, 2);

                switch (choice) {
                case 1: {
                    int numElements;
                    std::cout << "������� ���������� ���������:" << std::endl;
                    numElements = getNum<int>(1);

                    Characteristic* characteristics = new Characteristic[numElements];

                    for (int i = 0; i < numElements; i++) {
                        std::cout << "������� ��������������:" << std::endl;
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
                std::cout << "�������� ��������:" << std::endl
                    << "1 - �������� �������������� �� � ��������" << std::endl
                    << "2 - �������� ����� ��������������" << std::endl
                    << "3 - ������� ������� �������������" << std::endl
                    << "4 - ������ ����� �������������� � ������������ ���������" << std::endl
                    << "5 - ������������� �� ����� ��������" << std::endl;

                choice = getNum<int>(0, 5);

                switch (choice) {
                case 1:
                    characteristic = characteristic.InitializaName();
                    std::cout << "�������������� " << characteristic.getName() << " = " << characteristicsArray[characteristic.getName()] << std::endl;
                    break;
                case 2:
                    characteristic = characteristic.Initializa();
                    characteristicsArray += characteristic;
                    break;
                case 3:
                    characteristicsArray.Print();
                    break;
                case 4:
                    std::cout << "������������ ��������������: " << characteristicsArray.findMaxCharacteristic() << std::endl;
                    break;
                case 5:
                    characteristicsArray.sortByName();
                    break;
                }
                break;
            case 6:
                std::cout << "�������� ��� ��������:" << std::endl
                    << "1 - ������� ��������" << std::endl
                    << "2 - �������� � �������������" << std::endl
                    << "3 - �������� � �������" << std::endl;

                choice = getNum<int>(0, 3);

                switch (choice) {
                case 1:
                    characteristic = characteristic.InitializaName();
                    std::cout << "�������������� " << characteristic.getName() << " = " << characteristicsArray[characteristic.getName()] << std::endl;
                    characteristic.set(characteristicsArray[characteristic.getName()]);
                    std::cout << "������� �������� ���������:" << std::endl;
                    if (characteristic.check(characteristic) == 1) {
                        std::cout << "�������� ��������" << std::endl;
                    }
                    else {
                        std::cout << "�������� ���������" << std::endl;
                    }
                    break;
                case 2:
                    characteristic = characteristic.InitializaName();
                    std::cout << "�������������� " << characteristic.getName() << " = " << characteristicsArray[characteristic.getName()] << std::endl;
                    characteristic.set(characteristicsArray[characteristic.getName()]);
                    std::cout << "������� �������� ���������:" << std::endl;
                    if (characteristic.checkWithAdvantage(characteristic) == 1) {
                        std::cout << "�������� ��������" << std::endl;
                    }
                    else {
                        std::cout << "�������� ���������" << std::endl;
                    }
                    break;
                case 3:
                    characteristic = characteristic.InitializaName();
                    std::cout << "�������������� " << characteristic.getName() << " = " << characteristicsArray[characteristic.getName()] << std::endl;
                    characteristic.set(characteristicsArray[characteristic.getName()]);
                    std::cout << "������� �������� ���������:" << std::endl;
                    if (characteristic.checkWithDisadvantage(characteristic) == 1) {
                        std::cout << "�������� ��������" << std::endl;
                    }
                    else {
                        std::cout << "�������� ���������" << std::endl;
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
