/*
  Библиотека управления двигателем постоянного тока с помощью драйвера  L9110.
  Для управления двигателем используются 2 контакта D - направление и S - скорость.
  Библиотека написана ПДО IT-cube Баландиным Л.С.
  
*/

/**
 Описание класса мотора постоянного тока
 */
class DCMotor_L9110 {
public:

	/**
     Конструктор для создания объекта двигателя.
	 dirpin - любой цифровой контакт.
	 PWMpin - контакт для ШИМ сигнала.
	 needToReverse - параметр для изменения стартового направления вращения.
     */
	DCMotor_L9110(byte dirpin, byte PWMpin, bool needToReverse = 0) {
		_dirPin = dirpin;
		_PWMpin = PWMpin;
		if (needToReverse) _direction = 0;
		else _direction = 1;
		pinMode(_PWMpin, OUTPUT);
		pinMode(_dirPin, OUTPUT);
	}
  
   //метод включает двигатель на определённую мощность (-255...255)
    void on(int power){
		power = constrain(power, -255, 255); 
		if (power > 0) {
		  digitalWrite(_dirPin, _direction);
		  analogWrite(_PWMpin, abs(power));
		} 
		else if (power < 0){
		  digitalWrite(_dirPin, !_direction);
		  analogWrite(_PWMpin, abs(power));
		}
		else off();		
	}
   
   //метод включает двигатель на определённую мощность (-255...255) и на определённое время.
    void on(int power, unsigned long millisec){
		on(power);
		delay(millisec);
		off();
	} 

   // метод выключает подачу питания на двигатель. (остановка)
    void off(){
		digitalWrite(_PWMpin, 0);
		digitalWrite(_dirPin, 0);
	}
	
	void reverse(){
		_direction = not _direction;
	}
	
	private:
		bool _direction; 	// Переменная хранит текущее направление вращения.
		byte _PWMpin; 		// Переменная хранит номер контакта для управления скоростью (ШИМ сигнал)
		byte _dirPin;		// Переменная хранит номер контакта для управления направлением вращения
};