#ifndef OOPPROG2_CIRCLE_H
#define OOPPROG2_CIRCLE_H

#include <iostream>
#include <string>
#include <ctime>


namespace Prog2 {
	std::string getNum();
	class Characteristic {
	private:
		std::string name;   //��� ��������������
		int value;  //�������� ��������������
	public:
		//����������
		Characteristic() : name(""), value(0) {}    //������ ��� �������� ����� �������������� � ���������� ��������
		Characteristic(std::string valueName) : name(valueName), value(0) {} //������ ��� �������������� �������� ��������
		Characteristic(std::string valueName, int valuevalue) : name(valueName), value(valuevalue) {} //��� ��������������, � ��������� ��������.
		Characteristic(const Characteristic& other) : name(other.name), value(other.value) {} //����������� ����������� 

		
		Characteristic& operator=(const Characteristic& other) {    //��������� ������������.��������� ����������� ���� ������ ������ Characteristic ������� ������� ���� �� ������.
			if (this != &other) {     //��������.��� ������� ������, ����� �������� ������ �������
				name = other.name;
				value = other.value;
			}
			return *this;
		}
		
		//������ 
		Characteristic InitializaName();   // ������������� ������ ����� ��������������
		Characteristic Initializa();  // ���, ��� � ��������. 
		std::string getName() const { return name; }   //���������� ��� ��������������.
		int get() const { return value; }  //���������� �������� ��������������.
		//int& getvalue() { return value; }  //��������� ������ �������� �������� �������� ����� ��� ������
		const int& getvalue() const { return value; }  // �������� �������� �������������� �� ������, �� ��� ���� �� �������� ��������� �������. 
		void set(std::string other) { name = other; }  // ������������� ����� ��� ��������������.
		void set(int x) { value = x; }   // ����� �������� ��������������.
		void operator +=(int valuevalue) { value += valuevalue; }   //��������� ��������� �������� �������������� �� �������� ����� 


		

		
		int check(Characteristic& characteristic)const;   //��� �������� ������. 
		int checkWithAdvantage(Characteristic& characteristic)const;//  ��� �������� �������������� � ������������� (����� ����������� �������� �� ���� ������� ������).
		int checkWithDisadvantage(Characteristic& characteristic)const;  //��� �������� �������������� � ������� (����� ����������� �������� �� ���� ������� ������).


		int check(int valueD20, const int valueprotection, const int valuevalue);  //����������. ������ ������ D20.��������� ��������
		
		
		int randd()const {
			int D20 = 0;
			D20 = rand() % 20 + 1;
			std::cout << "D20 " << D20 << std::endl;
			return D20;

		}


	
		friend std::ostream& operator << (std::ostream& os, const Characteristic& obj) {    //�������������� ��������� ������  ��� ������������� ������� � ������ 
			os << "�������� ��������������: " << obj.getName() << "\n�������� �������������� " << obj.get();
			return os;
		}
		friend std::istream& operator >> (std::istream& is, Characteristic& obj) {   // �������������� ��������� ����� 
			std::string Name;
			int value;

			is >> Name;    //������ ������ � ����� 
			is >> value;

			if (is.good() && value >= 0 && value<=20) {    //�������� ���� ��� ��� � ��������� �� 1 �� 20
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
		Characteristic* characteristicsArray;    // ��� �������� ������� �������������
		int size;
	public:

		// Constructors and Destructor
		CharacteristicsTable() {       //����������� �� ���������
			characteristicsArray = nullptr;
			size = 0;
		}
		CharacteristicsTable(const Characteristic* valuecharacteristic, int valuei) {  //��������� ������� ������� �� ������ ������� �������������,
			size = valuei;//������ �������
			characteristicsArray = new Characteristic[size];//������������ ������
			for (int i = 0; i < size; i++) {
				characteristicsArray[i] = valuecharacteristic[i].getName();   //������ �������������� �� valuecharacteristic ���������� � ������.��� ������ ��������
			}
		}

		CharacteristicsTable(const Characteristic& characteristic) { // �� ������  ����� ��������������
			size = 1;
			characteristicsArray = new Characteristic[size];
			characteristicsArray[0] = characteristic;
		}

		CharacteristicsTable(const CharacteristicsTable& other) : size(other.size) {  // ����������� �����������
			characteristicsArray = new Characteristic[size];////////////////
			for (int i = 0; i < size; i++) {
				characteristicsArray[i] = other.characteristicsArray[i];
			}
		}

		CharacteristicsTable(CharacteristicsTable&& other) noexcept {  //����������� �����������.������� ����� ������  ��������� ������ �� ������� other � ����� ������.
			size = other.size;
			characteristicsArray = other.characteristicsArray;
			other.size = 0;
			other.characteristicsArray = nullptr;  //����� �������� ������ ������
		}

		~CharacteristicsTable() {
			delete[] characteristicsArray;
		}


		
		CharacteristicsTable& operator=(const CharacteristicsTable& other); //���������� ��������� ������������ ��� ����������� ������ �� ������� other � ������� ������
		CharacteristicsTable& operator=(CharacteristicsTable&& other) noexcept;  //���������� ��������� ������������ ��� ����������� ������ �� ������� other � ������� ������ 
		CharacteristicsTable& operator+=(const Characteristic& other) { //���������� ��������� +=, ������� ��������� �������� ����� �������������� � �������.
			for (int i = 0; i < size; i++) {
				if (characteristicsArray[i].getName() == other.getName()) {
					throw std::runtime_error("�������������� � ����� ������ ���������� ");
				}
			}

			addCharacteristic(other);  // ��������� ����� �������������� other � �������.
			return *this;
		}
		//���������� ���������� ������������ � ���������� ������������� � ������� ������

		
		int& operator[](const std::string& voidname) {   //����������� ���������� (���������) ������������� �� �� �����. 
			for (int i = 0; i < size; i++) {
				if (characteristicsArray[i].getName() == voidname) { //���� ��� ������� �������������� ��������� � ������ voidname

					return characteristicsArray[i].getvalue();  //������������ ������ �� �������� (int) �������������� 
				}
			}
			throw std::runtime_error("�������������� � ����� ������ �� ���������� ");
		}
		const int& operator[](const std::string& voidname)const {   //(���������) �������������� �� ����� �� �������
			for (int i = 0; i < size; i++) {
				if (characteristicsArray[i].getName() == voidname) {

					return characteristicsArray[i].getvalue();
				}
			}
			throw std::runtime_error("�������������� � ����� ������ �� ���������� ");
		}
		//���������� ������� ������ � ��������������� � ������� CharacteristicsTable �� �� �����.



	
		void addCharacteristic(const Characteristic& other);    //��� ���������� ����� �������������� � �������.����� ��������� �������� �� ������� �������������� � ����� �� ������ � �������. ���� �������������� � ����� ������ ��� ����������, ������������� ����������.

		std::string findMaxCharacteristic() const {  //��������������� ��� ������ �������������� � ������������ ��������� � �������.
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
		//���������� ����� ������������� � ������� � ����� �������������� � ������������ ��������� ����� ������������ ������������� � �������.



		void sortByName() {    //��������������� ��� ���������� ������������� � ������� �� �� ����� � ���������� �������.
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

		void Print()const {    //��������������� ��� ������ ������������� �� ������� �� �����
			for (int i = 0; i < size; i++) {
				std::cout << characteristicsArray[i] << std::endl;
			}
		}
	};


	//���������� ���������� ������������� � ������� �� ����� � ����� ���� ������������� �� ����� ��� �������� ����������� � ������� ������.


	template<class T>
	T getNum(T min = std::numeric_limits<T>::lowest(), T max = std::numeric_limits<T>::max()) {
		T a;
		while (true) {
			std::cin >> a;
			if (std::cin.eof()) // ��������� ����� �����
				throw std::runtime_error("�� ������� ��������� ����� EOF");
			else if (std::cin.bad()) // ���������� ��������������� ������ �������� ������
				throw std::runtime_error(std::string("�� ������� ��������� �����: "));
			// ������ ������ (������������ ������ �����) ���� ����� �� ������ � �������� ��������
			else if (std::cin.fail() || a < min || a > max) {
				std::cin.clear(); // ������� ����� ��������� ������
				// ���������� ��� ������� �� ����� ������
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "������ �����. ��������� ���� " << std::endl;
			}
			else // �������� ����
				return a;
		}
	}





}




#endif //OOPPROG2_CIRCLE_H