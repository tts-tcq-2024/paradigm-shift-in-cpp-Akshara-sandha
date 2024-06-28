#include <assert.h>
#include <iostream>
using namespace std;

bool Rangechecker(float battery_value, float min_value, float max_value, const char* comment);
bool batteryIsOk(float temperature_value, float soc_value, float chargeRate_value) {
  bool temperature_ok = Rangechecker(temperature_value, 0, 45, "Temperature out of range!");
  bool soc_ok = Rangechecker(soc_value, 20, 80, "State of Charge out of range!");
  bool chargeRate_ok = Rangechecker(chargeRate_value, 0, 0.8, "Charge Rate out of range!");
  return temperature_ok && soc_ok && chargeRate_ok;
}
bool Rangechecker(float battery_value, float min_value, float max_value, const char* comment) {
  if (battery_value < min_value || battery_value > max_value) {
    cout << comment << endl;
    return false;
  }
  return true;
}

int main() {
  assert(batteryIsOk(25, 70, 0.7) == true);
  assert(batteryIsOk(50, 85, 0) == false);
}
