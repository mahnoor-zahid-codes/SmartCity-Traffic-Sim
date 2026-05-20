#include <iostream>
#include <string>
using namespace std;
class TrafficSignal  //base class
{
protected:
    string location;
    string currentLight;
    int timer;
public:
    TrafficSignal(string loc, string light, int t)    //constructor
    {
        location = loc;
        currentLight = light;
        timer = t;
    }
        void startSignal()
    {
        cout << "Signal Started Successfully.\n";
    }
    void changeLight()      // Change Light Automatically
    {
        if (currentLight == "RED")
            currentLight = "GREEN";

        else if (currentLight == "GREEN")
            currentLight = "YELLOW";
        else
            currentLight = "RED";
        cout << "Light Changed To: " << currentLight << endl;
    }
        void showSignalData()   // Display Signal Data
    {
        cout << "\n----- Traffic Signal Information -----\n";
        cout << "Location      : " << location << endl;
        cout << "Current Light : " << currentLight << endl;
        cout << "Timer         : " << timer << " seconds" << endl;
    }
};
class SmartSignal : public TrafficSignal   // Derived Class
{
private:
    int vehicleCount;
public:
    SmartSignal(string loc, string light, int t) : TrafficSignal(loc, light, t)
            {
        vehicleCount = 0;
    }
        void detectTraffic(int count)
    {
        vehicleCount = count;
        if (vehicleCount > 50)
        {
            timer = 60;
            cout << "\nHeavy Traffic Detected.\n";
            cout << "Green Time Increased To 60 Seconds.\n";
        }
        else
        {
            timer = 30;
            cout << "\nNormal Traffic.\n";
            cout << "Green Time Set To 30 Seconds.\n";
        }
    }
    void emergencyMode()
    {
        currentLight = "GREEN";
        cout << "\nEmergency Vehicle Detected!\n";
        cout << "Signal Changed To GREEN.\n";
    }
    void pedestrianCrossing()
    {
        currentLight = "RED";
        cout << "\nPedestrian Crossing Activated.\n";
        cout << "Signal Changed To RED.\n";
    }
    void displaySmartData()
    {
        showSignalData();
        cout << "Vehicle Count : " << vehicleCount << endl;
    }
};
int main()
{
    SmartSignal s1("Murree Road", "RED", 30);

    s1.startSignal();
    s1.changeLight();
    s1.detectTraffic(80);
    s1.emergencyMode();
    s1.pedestrianCrossing();
    s1.displaySmartData();
    return 0;
}


output:
Signal Started Successfully.
Light Changed To: GREEN

Heavy Traffic Detected.
Green Time Increased To 60 Seconds.
Emergency Vehicle Detected!
Signal Changed To GREEN. 
Pedestrian Crossing Activated.
Signal Changed To RED.
----- Traffic Signal Information -----
Location     : Murree Road
Current Light : RED
Timer   : 30 seconds
 Vehicle Count : 80



