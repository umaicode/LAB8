#include <LiquidCrystal.h>

// 핀 번호 (RS, E, DB4, DB5, DB6, DB7)
LiquidCrystal lcd(44, 45, 46, 47, 48, 49);  // LCD 연결

// 사용자 정의 문자 데이터
byte user1[8] = {B00000, B10001, B00000, B00000, B10001, B01110, B00000, B00000};
byte user2[8] = {B00000, B10001, B01010, B10001, B00000, B10001, B01110, B00000};

void setup() {
  // put your setup code here, to run once:
  lcd.createChar(0, user1); // 사용자 정의 문자 1 생성
  lcd.createChar(1, user2); // 사용자 정의 문자 2 생성
  lcd.begin(16, 2); // LCD 크기 설정
  lcd.clear();  // LCD 화면 지우기
  lcd.write(byte(0)); // 사용자 정의 문자 1 출력
  lcd.setCursor(0, 1);  // 두 번째 행으로 이동 
  lcd.write(byte(1)); // 사용자 정의 문자 2 출력
}

void loop() {
  // put your main code here, to run repeatedly:

}
