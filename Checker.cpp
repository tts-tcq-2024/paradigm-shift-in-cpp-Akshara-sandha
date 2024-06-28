#include <assert.h>
#include <iostream>
using namespace std;

bool checkInRange(int value, const char* comment) {
  if (value==1) {
    cout << comment << endl;
    return false;
  }
  return true;
}
 
bool batteryIsOk(float temperature, float soc, float chargeRate) {
  
  int a =(temperature < 0 || temperature > 45) ? 1 : 0;
  bool temperatureOk = checkInRange(a, "Temperature out of range!");
  a =(soc < 20 || soc > 80) ? 1 : 0;
  bool socOk = checkInRange(a, "State of Charge out of range!");
  a =(chargeRate > 0.8) ? 1 : 0;
  bool chargeRateOk = checkInRange(a, "Charge Rate out of range!");
  return temperatureOk && socOk && chargeRateOk;
}

int main() {
  assert(batteryIsOk(25, 70, 0.7) == true);
  assert(batteryIsOk(50, 85, 0) == false);
}
