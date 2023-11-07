// 0에서 9까지 숫자 표현을 위한 세그먼트 a, b, c, d, e, f, g, dp의 패턴
byte patterns[] = {0xFC, 0x60, 0xDA, 0xF2, 0x66, 0xB6, 0xBE, 0xE4, 0xFE, 0xE6};
int digit_select_pin[] = {66, 67, 68, 69};  // 자릿수 선택 픽

// 7세그먼트 모듈 연결 핀 'a, b, c, d, e, f, g, dp' 순서
int segment_pin[] = {58, 59, 60, 61, 62, 62, 63, 64, 65};

int SEGMENT_DELAY = 5;  // 숫자 표시 사이의 시간 간격

unsigned long time_previous, time_current;
int minutes = 0, seconds = 0;

void setup() {
  // put your setup code here, to run once:
  for(int i = 0; i < 4; i++) {
    pinMode(digit_select_pin[i], OUTPUT);
  }
  for(int i = 0; i < 8; i++) {
    pinMode(segment_pin[i], OUTPUT);
  }

  time_previous = millis();
}

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

void loop() {
  // put your main code here, to run repeatedly:
  time_current = millis();
  if(time_current - time_previous >= 1000) {  // 1초 경과
    time_previous = time_current;
    seconds++;
    if(seconds == 60) { // 60초가 되면 분 증가
      seconds = 0;
      minutes++;
    }
    if(minutes == 60) minutes = 0;  // 60분이 되면 0으로 되돌림
  }
  show_4_digit(minutes * 100 + seconds);  // 시간 표시를 위해 4자리 숫자로 만듦.
}
