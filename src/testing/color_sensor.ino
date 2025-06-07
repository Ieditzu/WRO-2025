#include <OzIDManager.h>
#include <OzRGB_Sensor.h>

OzIDManager* manager;
OzRGB_Sensor* RGB_sensor;

void setup() 
{
  Serial.begin(115200);

  manager = new OzIDManager;
  manager->_sendACK = true;
  manager->_checksum = true;

  OzCommunication::setIDManager(manager);

  //S0, S1, S2, S3, OE, sensorOut
  RGB_sensor = new OzRGB_Sensor(2, 3, 4, 5, 7, 8);

  int x=1;
  manager->sendLinkSetup();
  manager->PrintWelcomeLine(RGB_sensor, x++, "MyRGB_Sensor");
}

void loop()
{
  OzCommunication::communicate();
  RGB_sensor->ownLoop();
}
