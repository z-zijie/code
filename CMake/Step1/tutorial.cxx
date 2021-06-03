#include <TutorialConfig.h>
#include <cmath>
#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
  if (argc < 2) {
    // report version
    cout << argv[0] << " Version " << Tutorial_VERSION_MAJOR << "."
         << Tutorial_VERSION_MINOR << endl;
    cout << "Usage: " << argv[0] << " number" << endl;
    return 1;
  }
  const double inputValue = stod(argv[1]);
  cout << "SQUARE ROOT OF " << inputValue << " is " << sqrt(inputValue) << endl;
  return 0;
}
