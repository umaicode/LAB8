void setup() {
  // put your setup code here, to run once:

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
