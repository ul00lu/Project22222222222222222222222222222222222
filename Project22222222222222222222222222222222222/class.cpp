#include "class.h"

namespace Prog2 {
   
    //чтобы объекты могли корректно копироваться и присваиваться друг другу.
    CharacteristicsTable& CharacteristicsTable::operator=(const CharacteristicsTable& other) {   // реализацию оператора присваивания для класса. другой объект 
        if (this != &other) { //не являются ли текущий объект и объект other одним и тем же объектом
          
            delete[] characteristicsArray;

         
            size = other.size;   //копируется размер (size) массива из объекта other в текущий объект, чтобы размеры соответствовали.
            characteristicsArray = new Characteristic[size];//массив такого же размера, как у объекта other

            
            for (int i = 0; i < size; i++) {   //копирование данных характеристик из объекта other в текущий объект. 
                characteristicsArray[i].set(other.characteristicsArray[i].getName());   //проходим по массиву характеристик объекта other, копируя их имена и значения в новый массив характеристик текущего объекта.
                characteristicsArray[i].set(other.characteristicsArray[i].getvalue());
            }
        }
        return *this;
    }
    //Оператор перемещения позволяет эффективно передавать ресурсы из одного объекта в другой без копирования данных.
    CharacteristicsTable& CharacteristicsTable::operator=(CharacteristicsTable&& other) noexcept { //реализацию оператора перемещения.из объекта other в текущий объект *this.
        if (this != &other) {
            delete[] characteristicsArray;
            size = other.size; //копируется размер (size) массива из объекта other в текущий объект, чтобы размеры соответствовали.
            characteristicsArray = other.characteristicsArray;// перемещает указатель на массив characteristicsArray из объекта other в текущий объект.
            other.size = 0;
            other.characteristicsArray = nullptr;
        }
        return *this;
    }
     
    void CharacteristicsTable::addCharacteristic(const Characteristic& other) { // Этот метод служит для добавления новой характеристики в массив характеристик
        Characteristic* Newcharacteristic = new Characteristic[size + 1];  //делается для того, чтобы увеличить размер массива и добавить новую характеристику.

        for (int i = 0; i < size; i++) {  //копирование существующих характеристик из массива characteristicsArray во временный массив Newcharacteristic
            Newcharacteristic[i] = characteristicsArray[i];
        }
        Newcharacteristic[size].set(other.get()); // добавляется новая характеристика в конец временного массива
        Newcharacteristic[size].set(other.getName()); //

        delete[] characteristicsArray;
        characteristicsArray = Newcharacteristic;
        size++;
    }
    //обновив размер массива и скопировав все старые характеристики в новый массив.

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

    int Characteristic::check(Characteristic& characteristic) const {   //проверкd характеристики на основе атаки и защиты, используя метод check 
        int protection, attack;
        protection = getNum<int>(0);
        attack = characteristic.randd();
        return characteristic.check(attack, protection, characteristic.getvalue());
    }

    int Characteristic::checkWithAdvantage(Characteristic& characteristic) const {  // метод выполняет проверку характеристики с преимуществом, где кубик бросается два раза, и выбирается наибольшее значение. 
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

    int Characteristic::checkWithDisadvantage(Characteristic& characteristic) const {  //выполняет проверку характеристики с преимуществом, где кубик бросается два раза, и выбирается наиvtymittшее значение.
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
        Characteristic other;// создается локальный объект
        std::cout << "Название характеристики " << std::endl;//будет использоваться для хранения данных, которые будут введены пользователем.
        other.name = getNum();
        return other;
    }

    Characteristic Characteristic::Initializa() {
        Characteristic other;
        std::cout << "Введите харктеристику и ее значение  " << std::endl;
        other.name = getNum();
        other.value = getNum<int>(1, 20);
        return other;
    }













    std::string getNum() {
        std::string str;
        while (true) {
            std::cin >> str;
            if (std::cin.eof()) // обнаружен конец файла
                throw std::runtime_error("Не удалось прочитать строку EOF");
            else if (std::cin.bad()) // обнаружена невосстановимая ошибка входного потока
                throw std::runtime_error(std::string("Не удалось прочитать номер: "));
            // прочие ошибки (неправильный формат ввода) либо число не входит в заданный диапазон
            else if (std::cin.fail()) {
                std::cin.clear(); // очищаем флаги состояния потока
                // игнорируем все символы до конца строки
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Ошибка ввода. Повторите ввод " << std::endl;
            }
            else // успешный ввод
                return str;
        }
    }








}







