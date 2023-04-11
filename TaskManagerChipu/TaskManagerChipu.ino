
// To use task manager we must include the library
#include <Arduino.h>
#include "TaskManagerIO.h"
#include <TaskManagerIO.h>
int switch_(int &isBlink)
{
  return isBlink = isBlink == LOW ? HIGH : LOW;
}
int pins[] = {3, 5, 6, 9, 10, 11};
int isBlink[] = {LOW, LOW, LOW, LOW, LOW, LOW};
long interval[]= {500, 9000, 80000, 100000, 150000, 300000};
void setup() {
  int i = 0;
  while (i < 6){
    pinMode(pins[i], OUTPUT);
    i++;
  }
  taskManager.scheduleFixedRate(500, [] {
      switch_(isBlink[0]) == LOW ? digitalWrite(3, LOW) : digitalWrite(3, HIGH);;
    }, TIME_MICROS);
  taskManager.scheduleFixedRate(9000, [] {
      switch_(isBlink[1]) == LOW ? digitalWrite(5, LOW) : digitalWrite(5, HIGH);;
    }, TIME_MICROS);
  taskManager.scheduleFixedRate(80000, [] {
      switch_(isBlink[2]) == LOW ? digitalWrite(6, LOW) : digitalWrite(6, HIGH);;
    }, TIME_MICROS);
  taskManager.scheduleFixedRate(100000, [] {
      switch_(isBlink[3]) == LOW ? digitalWrite(9, LOW) : digitalWrite(9, HIGH);;
    }, TIME_MICROS);
  taskManager.scheduleFixedRate(150000, [] {
      switch_(isBlink[4]) == LOW ? digitalWrite(10, LOW) : digitalWrite(10, HIGH);;
    }, TIME_MICROS);
  taskManager.scheduleFixedRate(300000, [] {
      switch_(isBlink[5]) == LOW ? digitalWrite(11, LOW) : digitalWrite(11, HIGH);;
    }, TIME_MICROS);  
}
void loop() {
  taskManager.runLoop();
}
