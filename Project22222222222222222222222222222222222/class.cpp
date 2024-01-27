#include "class.h"

namespace Prog2 {
   
    //����� ������� ����� ��������� ������������ � ������������� ���� �����.
    CharacteristicsTable& CharacteristicsTable::operator=(const CharacteristicsTable& other) {   // ���������� ��������� ������������ ��� ������. ������ ������ 
        if (this != &other) { //�� �������� �� ������� ������ � ������ other ����� � ��� �� ��������
          
            delete[] characteristicsArray;

         
            size = other.size;   //���������� ������ (size) ������� �� ������� other � ������� ������, ����� ������� ���������������.
            characteristicsArray = new Characteristic[size];//������ ������ �� �������, ��� � ������� other

            
            for (int i = 0; i < size; i++) {   //����������� ������ ������������� �� ������� other � ������� ������. 
                characteristicsArray[i].set(other.characteristicsArray[i].getName());   //�������� �� ������� ������������� ������� other, ������� �� ����� � �������� � ����� ������ ������������� �������� �������.
                characteristicsArray[i].set(other.characteristicsArray[i].getvalue());
            }
        }
        return *this;
    }
    //�������� ����������� ��������� ���������� ���������� ������� �� ������ ������� � ������ ��� ����������� ������.
    CharacteristicsTable& CharacteristicsTable::operator=(CharacteristicsTable&& other) noexcept { //���������� ��������� �����������.�� ������� other � ������� ������ *this.
        if (this != &other) {
            delete[] characteristicsArray;
            size = other.size; //���������� ������ (size) ������� �� ������� other � ������� ������, ����� ������� ���������������.
            characteristicsArray = other.characteristicsArray;// ���������� ��������� �� ������ characteristicsArray �� ������� other � ������� ������.
            other.size = 0;
            other.characteristicsArray = nullptr;
        }
        return *this;
    }
     
    void CharacteristicsTable::addCharacteristic(const Characteristic& other) { // ���� ����� ������ ��� ���������� ����� �������������� � ������ �������������
        Characteristic* Newcharacteristic = new Characteristic[size + 1];  //�������� ��� ����, ����� ��������� ������ ������� � �������� ����� ��������������.

        for (int i = 0; i < size; i++) {  //����������� ������������ ������������� �� ������� characteristicsArray �� ��������� ������ Newcharacteristic
            Newcharacteristic[i] = characteristicsArray[i];
        }
        Newcharacteristic[size].set(other.get()); // ����������� ����� �������������� � ����� ���������� �������
        Newcharacteristic[size].set(other.getName()); //

        delete[] characteristicsArray;
        characteristicsArray = Newcharacteristic;
        size++;
    }
    //������� ������ ������� � ���������� ��� ������ �������������� � ����� ������.

    int Characteristic::check(int valueD20, const int valueprotection, const int valuevalue) {
        if (valueD20 == 1) {
            return 0;
        }
        else if (valueD20 == 20) {
            return 1;
        }
        else {
            valueD20 += valuevalue;
            if (valueD20 > valueprotection) {
                return 1;
            }
            else {
                return 0;
            }
        }
    }

    int Characteristic::check(Characteristic& characteristic) const {   //�������d �������������� �� ������ ����� � ������, ��������� ����� check 
        int protection, attack;
        protection = getNum<int>(0);
        attack = characteristic.randd();
        return characteristic.check(attack, protection, characteristic.getvalue());
    }

    int Characteristic::checkWithAdvantage(Characteristic& characteristic) const {  // ����� ��������� �������� �������������� � �������������, ��� ����� ��������� ��� ����, � ���������� ���������� ��������. 
        int protection, i, i1;
        protection = getNum<int>(0);
        i1 = characteristic.randd();
        i = characteristic.randd();
        if (i >= i1) {
            return characteristic.check(i, protection, characteristic.getvalue());
        }
        else if (i <= i1) {
            return characteristic.check(i1, protection, characteristic.getvalue());
        }
    }

    int Characteristic::checkWithDisadvantage(Characteristic& characteristic) const {  //��������� �������� �������������� � �������������, ��� ����� ��������� ��� ����, � ���������� ���vtymitt��� ��������.
        int protection, i, i1;
        protection = getNum<int>(0);
        i1 = characteristic.randd();
        i = characteristic.randd();
        if (i >= i1) {
            return characteristic.check(i1, protection, characteristic.getvalue());
        }
        else if (i <= i1) {
            return characteristic.check(i, protection, characteristic.getvalue());
        }
    }

    Characteristic Characteristic::InitializaName() {
        Characteristic other;// ��������� ��������� ������
        std::cout << "�������� �������������� " << std::endl;//����� �������������� ��� �������� ������, ������� ����� ������� �������������.
        other.name = getNum();
        return other;
    }

    Characteristic Characteristic::Initializa() {
        Characteristic other;
        std::cout << "������� ������������� � �� ��������  " << std::endl;
        other.name = getNum();
        other.value = getNum<int>(1, 20);
        return other;
    }













    std::string getNum() {
        std::string str;
        while (true) {
            std::cin >> str;
            if (std::cin.eof()) // ��������� ����� �����
                throw std::runtime_error("�� ������� ��������� ������ EOF");
            else if (std::cin.bad()) // ���������� ��������������� ������ �������� ������
                throw std::runtime_error(std::string("�� ������� ��������� �����: "));
            // ������ ������ (������������ ������ �����) ���� ����� �� ������ � �������� ��������
            else if (std::cin.fail()) {
                std::cin.clear(); // ������� ����� ��������� ������
                // ���������� ��� ������� �� ����� ������
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "������ �����. ��������� ���� " << std::endl;
            }
            else // �������� ����
                return str;
        }
    }








}







