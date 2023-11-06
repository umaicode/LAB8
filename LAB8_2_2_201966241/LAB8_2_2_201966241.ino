#include <LiquidCrystal.h>

// 핀 번호 (RS, E, DB4, DB5, DB6, DB7)
LiquidCrystal lcd(44, 45, 46, 47, 48, 49);  // LCD 연결

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16, 2); // LCD 초기화
  lcd.setCursor(0, 0);  // 0행 0열로 이동
  lcd.write('1'); // 문자 단위 출력
  lcd.setCursor(5, 0);
  lcd.write('2');
  lcd.setCursor(0, 1);
  lcd.write('3');
  lcd.setCursor(5, 1);
  lcd.write('4');
}

void loop() {
  // put your main code here, to run repeatedly:

}
