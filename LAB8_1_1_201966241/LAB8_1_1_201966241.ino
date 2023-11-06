// 0에서 9까지 숫자 표현을 위한 세그먼트 a, b, c, d, e, f, g, dp의 패턴
byte patterns[] = {0xFC, 0x60, 0xDA, 0xF2, 0x66, 0xB6, 0xBE, 0xE4, 0xFE, 0xE6};
int digit_select_pin[] = {66, 67, 68, 69};  // 자릿수 선택 픽
// 7세그먼트 모듈 연결 핀 'a, b, c, d, e, f, g, dp' 순서
int segment_pin[] = {58, 59, 60, 61, 62, 62, 63, 64, 65};

// 해당 자리에 숫자 하나를 표시하는 함수
void show_digit(int pos, int number) {  // (위치, 출력할 숫자)
  for(int i= 0; i < 4; i++) {
    if(i + 1 == pos)  // 해당 자릿수의 선택 핀만 LOW로 설정
      digitalWrite(digit_select_pin[i], LOW);
    else  // 나머지 자리는 HIGH로 설정
      digitalWrite(digit_select_pin[i], HIGH);
  }
  for(int i = 0; i < 8; i++) {
    boolean on_off = bitRead(patterns[number], 7 - i);
    digitalWrite(segment_pin[i], on_off);
  }
}

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
