void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  int reading = analogRead(A0);
  
  show_4_digit(reading);  // 가변저항 값 표시
}
