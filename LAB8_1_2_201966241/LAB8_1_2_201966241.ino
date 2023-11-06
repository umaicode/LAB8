// 4자리 7세그먼트 표시 장치에 4자리 숫자를 표시하는 함수
// 3자리 7세그먼트의 경우 show_3_digit()을 구현. 일부 코드 수정 필요.
void show_4_digit(int number) {
  number = number % 10000;  // 4자리로 제한
  int thousands = number / 1000;  // 천 자리
  number = number % 1000;
  int hundreads =  number / 100;  // 백 자리
  number = number % 100;
  int tens = number / 10;         // 십 자리
  int ones = number % 10;         // 일 자리
  show_digit(1, thousands);
  delay(SEGMENT_DELAY);
  show_digit(2, hundreads);
  delay(SEGMENT_DELAY);
  show_digit(3, tens);
  delay(SEGMENT_DELAY);
  show_digit(4, ones);
  delay(SEGMENT_DELAY);
}
void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  // 잔상효과를 위해 빠른 속도로 쓰기를 반복해야 하므로 delay 함수를 사용할 수 없음.
  time_current = millis();
  if(time_current - time_previous >= 100) {
    time_previous = time_current;
    count++;
  }
  show_4_digit(count);
}
