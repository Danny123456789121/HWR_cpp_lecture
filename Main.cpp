#include "Wetterstation.h"
using namespace std;

int main() {
    Wetterstation ws;

    ws.addMesswert(Messure(1, 20));
    ws.addMesswert(Messure(5, 40));

    cout << ws.getMesswerte();
    cout << "------------------" << endl;
    cout << ws.getLightnings();
    cout << "------------------" << endl;
    cout << ws.getTemperatures();

}
