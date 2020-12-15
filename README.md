# ohm-meter
this is a ohm meter prototype using AVR atmega32 Microcontroller at 8 MHz and its ADC on ADC0 in polling mode with the highest prescale 
This output voltage is now fed into the micro controllerADC port.The ADC here used is of 10 bit with 5 volt reference voltage.(ie VREF=5).
so each bit has a resolution of 5/1024=4.88 mV.
The ADC  calculates the voltage and using the following formula the Unknown resistance is measured.
let u=(ADC output voltage)/5
R(unknown)=(u*R2)/(1-u)
The result is the Displayed onto the LCD.

# Pros:
Simple Design (proteus v7 design which is attatched with projct files)
Straight Forward Concept (only voltage divider concept)
Range can be expanded (by changing R1 value in desgin and R1 value in the code)

# Cons:
Limited Range.
Range Expansion possible but with reduction in accuracy.

This is not a very good design because from the above formula we infer that the output voltage
and unknown Resistances are not linearly related.we will get a good accuracy when fixed and 
unknown resistance do not differ by much.
If the unknown resistance is too high then all voltage will drop across it,So all lareger 
resistance values will be mapped to short range of values near to VREF causing more error.
And if the unknown resistance is too small compared to the fixed one no voltage will drop
across the unknown resistor then the ADC will not read the voltage as its below the minimum 
resolution(Here 4.88 mV)

A numerical Example:
R fixed is 10 k,let unknown=120k
then output Voltage =4.6153 V
let unknown=121k
then output Voltage =4.6183 V.
let unknown=121k
output Voltage =4.6296 V
The voltage difference between them is 3 mV which is less than ADC resolution.So after 120 it will simply read 121 or above.This is more dominant at higher
resistance values.

R fixed is 10 k,let unknown=1 ohm
output Voltage =.4 mV
which is not detected by the ADC.

#Modification

A Better way to measure the Resistance would be to a varying voltage divider according to the unknown
resistances range so as to get better result Or one could measure resistance by simply Using a high 
precision Current source to allow a fixed current to pass through the resistance and then measure the 
Voltage using ADC to get better result.
