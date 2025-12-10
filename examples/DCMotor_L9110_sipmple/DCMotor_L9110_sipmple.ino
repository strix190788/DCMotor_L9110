#include <DCMotor_L9110.h>

// левый двигатель подключен к контактам 2 и 3. 3- ШИМ сигнал.
DCMotor_L9110 motorLeft(4, 5);
// правый двигатель подключен к контактам 4 и 5. 5- ШИМ сигнал.
// Положительно направление вращения правого двигателя обратное.
DCMotor_L9110 motorRight(2, 3, 1);

void setup() {
  motorRight.on(40);  // включить на мощность 40
  delay(1500);
  motorRight.off();  // выключить двигатель.
  delay(500);
  motorRight.on(-40, 1500);  // включить на мощность -40 на 1,5с

}

void loop() {
  motorLeft.on(80, 1500);
  motorLeft.reverse();
}
