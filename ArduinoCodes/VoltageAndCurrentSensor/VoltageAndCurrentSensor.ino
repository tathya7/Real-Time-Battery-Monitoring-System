// Define analog input

#define ANALOG_IN_PIN A2 // Volatge A0
#define sensorPin A0 // LM35 is connected to this PIN
 
// Floats for ADC voltage & Input voltage
float adc_voltage = 0.0;
float in_voltage = 0.0;
 
// Floats for resistor values in divider (in ohms)
float R1 = 30000.0;
float R2 = 7500.0; 
 
// Float for Reference Voltage
float ref_voltage = 5.0;
 
// Integer for ADC value
int adc_value = 0;
 
void setup()
{
   // Setup Serial Monitor
   Serial.begin(9600);
   Serial.println("DC Voltage Test");
   Serial.println("Temp");
}
 
void loop(){
   // Read the Analog Input
   adc_value = analogRead(ANALOG_IN_PIN);
   
   // Determine voltage at ADC input
   adc_voltage  = (adc_value * ref_voltage) / 1024.0; 
   
   // Calculate voltage at divider input
   in_voltage = adc_voltage / (R2/(R1+R2)) ; 
   
   // Print results to Serial Monitor to 2 decimal places
  Serial.print("Input Voltage = ");
  Serial.println(in_voltage, 2);
  
  // Short delay
  delay(1000);


// Temperature 

 //Read Raw ADC Data
  int adcData = analogRead(sensorPin);
  // Convert that ADC Data into voltage
  float voltage = adcData * (5.0 / 1024.0);
  // Convert the voltage into temperature 
  float temperature = voltage * 100;
  // Print the temperature data
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println("*C");
  delay(1000); // wait a second between readings



}