int pins[] = {3, 5, 6, 9, 10, 11};
int isBlink[] = {LOW, LOW, LOW, LOW, LOW, LOW};
long times[] = {0, 0, 0, 0, 0, 0};
long interval[]= {500, 9000, 80000, 100000, 150000, 300000};
void setup() {
  int i = 0;
  while (i < 6){
    pinMode(pins[i], OUTPUT);
    i++;
  }
}
void loop() {
  long tmpTime = micros();
  int i = 0;
  while (i < 6){
  if (tmpTime - times[i] >= interval[i]) {
    times[i] = tmpTime;
    isBlink[i] = isBlink[i] == LOW ? HIGH : LOW;
    digitalWrite(pins[i], isBlink[i]); }
    i++;
  }
}
