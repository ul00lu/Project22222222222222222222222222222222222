#ifndef OOPPROG2_CIRCLE_H
#define OOPPROG2_CIRCLE_H

#include <iostream>
#include <string>
#include <ctime>


namespace Prog2 {
	std::string getNum();
	class Characteristic {
	private:
		std::string name;   //имя характеристики
		int value;  //значения характеристики
	public:
		//конструтор
		Characteristic() : name(""), value(0) {}    //объект без указания имени характеристики и начального значения
		Characteristic(std::string valueName) : name(valueName), value(0) {} //только имя характеристики принимае параметр
		Characteristic(std::string valueName, int valuevalue) : name(valueName), value(valuevalue) {} //имя характеристики, и начальное значение.
		Characteristic(const Characteristic& other) : name(other.name), value(other.value) {} //Конструктор копирования 

		
		Characteristic& operator=(const Characteristic& other) {    //оператора присваивания.позволяет присваивать один объект класса Characteristic другому объекту того же класса.
			if (this != &other) {     //проверка.что объекты разные, чтобы избежать лишних операци
				name = other.name;
				value = other.value;
			}
			return *this;
		}
		
		//методы 
		Characteristic InitializaName();   // инициализации только имени характеристики
		Characteristic Initializa();  // имя, так и значение. 
		std::string getName() const { return name; }   //возвращает имя характеристики.
		int get() const { return value; }  //возвращает значение характеристики.
		//int& getvalue() { return value; }  //возращает ссылку изменять значение напрямую через эту ссылку
		const int& getvalue() const { return value; }  // получать значение характеристики по ссылке, но при этом не изменять состояние объекта. 
		void set(std::string other) { name = other; }  // устанавливает новое имя характеристики.
		void set(int x) { value = x; }   // новое значение характеристики.
		void operator +=(int valuevalue) { value += valuevalue; }   //Позволяет увеличить значение характеристики на заданное число 


		

		
		int check(Characteristic& characteristic)const;   //для проверки ростой. 
		int checkWithAdvantage(Characteristic& characteristic)const;//  для проверки характеристики с преимуществом (выбор наибольшего значения из двух бросков кубика).
		int checkWithDisadvantage(Characteristic& characteristic)const;  //для проверки характеристики с помехой (выбор наименьшего значения из двух бросков кубика).


		int check(int valueD20, const int valueprotection, const int valuevalue);  //перегружен. броска кубика D20.сложность проверки
		
		
		int randd()const {
			int D20 = 0;
			D20 = rand() % 20 + 1;
			std::cout << "D20 " << D20 << std::endl;
			return D20;

		}


	
		friend std::ostream& operator << (std::ostream& os, const Characteristic& obj) {    //перегруженного оператора вывода  как дружественной функции в классе 
			os << "Название характеристики: " << obj.getName() << "\nЗначение характеристики " << obj.get();
			return os;
		}
		friend std::istream& operator >> (std::istream& is, Characteristic& obj) {   // перегруженного оператора ввода 
			std::string Name;
			int value;

			is >> Name;    //читает строку и число 
			is >> value;

			if (is.good() && value >= 0 && value<=20) {    //проверка чисо что оно в диапазоне от 1 до 20
				obj.set(Name);
				obj.set(value);
			}
			else {
				is.setstate(std::ios_base::failbit);
			}


			return is;
		}

	};

	class CharacteristicsTable {
	private:
		Characteristic* characteristicsArray;    // для хранения массива характеристик
		int size;
	public:

		// Constructors and Destructor
		CharacteristicsTable() {       //конструктор по умолчанию
			characteristicsArray = nullptr;
			size = 0;
		}
		CharacteristicsTable(const Characteristic* valuecharacteristic, int valuei) {  //позволяет создать таблицу на основе массива характеристик,
			size = valuei;//размер таблицы
			characteristicsArray = new Characteristic[size];//динамический массив
			for (int i = 0; i < size; i++) {
				characteristicsArray[i] = valuecharacteristic[i].getName();   //каждая характеристика из valuecharacteristic копируется в массив.это массив объектов
			}
		}

		CharacteristicsTable(const Characteristic& characteristic) { // на основе  одной характеристики
			size = 1;
			characteristicsArray = new Characteristic[size];
			characteristicsArray[0] = characteristic;
		}

		CharacteristicsTable(const CharacteristicsTable& other) : size(other.size) {  // конструктор копирования
			characteristicsArray = new Characteristic[size];////////////////
			for (int i = 0; i < size; i++) {
				characteristicsArray[i] = other.characteristicsArray[i];
			}
		}

		CharacteristicsTable(CharacteristicsTable&& other) noexcept {  //конструктор перемещения.создает новый объект  перемещая данные из объекта other в новый объект.
			size = other.size;
			characteristicsArray = other.characteristicsArray;
			other.size = 0;
			other.characteristicsArray = nullptr;  //чтобы избежать утечки памяти
		}

		~CharacteristicsTable() {
			delete[] characteristicsArray;
		}


		
		CharacteristicsTable& operator=(const CharacteristicsTable& other); //перегрузка оператора присваивания для копирования данных из объекта other в текущий объект
		CharacteristicsTable& operator=(CharacteristicsTable&& other) noexcept;  //перегрузка оператора присваивания для перемещения данных из объекта other в текущий объект 
		CharacteristicsTable& operator+=(const Characteristic& other) { //перегрузка оператора +=, которая позволяет добавить новую характеристику в таблицу.
			for (int i = 0; i < size; i++) {
				if (characteristicsArray[i].getName() == other.getName()) {
					throw std::runtime_error("Характеристика с таким именем сушествует ");
				}
			}

			addCharacteristic(other);  // добавляет новую характеристику other в таблицу.
			return *this;
		}
		//обеспечить правильное присваивание и добавление характеристик к объекту класса

		
		int& operator[](const std::string& voidname) {   //обеспечения индексации (получения) характеристик по их имени. 
			for (int i = 0; i < size; i++) {
				if (characteristicsArray[i].getName() == voidname) { //если имя текущей характеристики совпадает с именем voidname

					return characteristicsArray[i].getvalue();  //возвращается ссылка на значение (int) характеристики 
				}
			}
			throw std::runtime_error("Характеристика с таким именем не сушествует ");
		}
		const int& operator[](const std::string& voidname)const {   //(получения) характеристики по имени из объекта
			for (int i = 0; i < size; i++) {
				if (characteristicsArray[i].getName() == voidname) {

					return characteristicsArray[i].getvalue();
				}
			}
			throw std::runtime_error("Характеристика с таким именем не сушествует ");
		}
		//обеспечить удобный доступ к характеристикам в объекте CharacteristicsTable по их имени.



	
		void addCharacteristic(const Characteristic& other);    //для добавления новой характеристики в таблицу.Метод выполняет проверку на наличие характеристики с таким же именем в таблице. Если характеристика с таким именем уже существует, выбрасывается исключение.

		std::string findMaxCharacteristic() const {  //предназначенный для поиска характеристики с максимальным значением в таблице.
			int i = 0, i1 = 0, max = characteristicsArray[0].getvalue();
			while (i < size) {
				if (characteristicsArray[i].getvalue() > max) {
					i1 = i;
					max = characteristicsArray[i].getvalue();
				}
				i++;
			}
			return characteristicsArray[i1].getName();

		}
		//добавление новых характеристик в таблицу и поиск характеристики с максимальным значением среди существующих характеристик в таблице.



		void sortByName() {    //предназначенный для сортировки характеристик в таблице по их имени в алфавитном порядке.
			for (int i = 0; i < size - 1; i++) {
				for (int j = 0; j < size - i - 1; j++) {
					if (characteristicsArray[j].getName() > characteristicsArray[j + 1].getName()) {
						int q = characteristicsArray[j].getvalue();
						characteristicsArray[j].set(characteristicsArray[j + 1].getvalue());
						characteristicsArray[j + 1].set(q);
						std::string l = characteristicsArray[j].getName();
						characteristicsArray[j].set(characteristicsArray[j + 1].getName());
						characteristicsArray[j + 1].set(l);
					}
				}
			}
		}

		void Print()const {    //предназначенный для вывода характеристик из таблицы на экран
			for (int i = 0; i < size; i++) {
				std::cout << characteristicsArray[i] << std::endl;
			}
		}
	};


	//обеспечить сортировку характеристик в таблице по имени и вывод всех характеристик на экран для удобства отображения и анализа данных.


	template<class T>
	T getNum(T min = std::numeric_limits<T>::lowest(), T max = std::numeric_limits<T>::max()) {
		T a;
		while (true) {
			std::cin >> a;
			if (std::cin.eof()) // обнаружен конец файла
				throw std::runtime_error("Не удалось прочитать номер EOF");
			else if (std::cin.bad()) // обнаружена невосстановимая ошибка входного потока
				throw std::runtime_error(std::string("Не удалось прочитать номер: "));
			// прочие ошибки (неправильный формат ввода) либо число не входит в заданный диапазон
			else if (std::cin.fail() || a < min || a > max) {
				std::cin.clear(); // очищаем флаги состояния потока
				// игнорируем все символы до конца строки
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "Ошибка ввода. Повторите ввод " << std::endl;
			}
			else // успешный ввод
				return a;
		}
	}





}




#endif //OOPPROG2_CIRCLE_H