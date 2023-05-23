/**********************************************************************
Faire varie la tension aux bornes d'une LED. 
A l'aide d'un potentiomètre on fais varier l'intensité l'umineuse de la LED 
on pourras trouver le schéma du montage dans le fichier ci-joint 
***skech 09.1_ADC_DAC
Anode la la Led reliée à la broche 25 à travers une résistance 
cathode --> GND 
milieu du potentiomètre --> broche 4 
une broche extreme--> 3,3v et l'autre -->GND 
**********************************************************************/
#define PIN_ANALOG_IN  4

void setup() {
  Serial.begin(115200);
}

void loop() {
  int adcVal = analogRead(PIN_ANALOG_IN);
  int dacVal = map(adcVal, 0, 4095, 0, 255);
  double voltage = adcVal / 4095.0 * 3.3;
  dacWrite(DAC1, dacVal);
  Serial.printf("ADC Val: %d, \t DAC Val: %d, \t Voltage: %.2fV\n", adcVal, dacVal, voltage);
  delay(200);
}
