/* 
 * ©KartikeyaWalia
 * 
 * This lets you control 5 servos using a nextion display and an arduino.
 * NOTE: Nextion library isn't required.
 * 
 * 
 * data from nextion is sent through a single serial but is labled with a prefix to denote which slider it corresponds to
 */
 
 
 
 #include <Servo.h>
int pos1,pos2,pos3,pos4,pos5; 
Servo s1,s2,s3,s4,s5;
String dfd_global;

void setup() {
 Serial.begin(9600);
  s1.attach(3);// 3,5,6,9,14,15 are PWM pins on pro mini
  s2.attach(5);
  s3.attach(6);
  s4.attach(10);
  s5.attach(11);
}

void loop() {

  if(Serial.available()){  ///////receiving from nextion without library
    char character;
    String dfd; //dfd stands for data from display, feel free to change variable names! doesn't matter
    delay(30);
    while(Serial.available()){
      character=char(Serial.read()); //reading data from the serial port
      dfd += character;
          }  
    //Serial.println(dfd);
    dfd_global=dfd; //dfd was not a global variable so wont work outside this loop
    }


  if (dfd_global.startsWith("A")){    // to check which slider is the data coming from
      dfd_global.remove(0,1);         // removing the prefix
      //Serial.println("A= " + dfd_global);
      int pos1=dfd_global.toInt(); 
     // Serial.println(pos1);
       s1.write(pos1); //run servo 1
       delay(10);
     }

  else if (dfd_global.startsWith("B")){    // to check which slider is the data coming from
      dfd_global.remove(0,1);         // removing the prefix
      //Serial.println("B= " + dfd_global);
      int pos2=dfd_global.toInt(); 
      //Serial.println(pos2);
      s2.write(pos2); //run servo 2
      delay(10);
     }

  else if (dfd_global.startsWith("C")){    // to check which slider is the data coming from
      dfd_global.remove(0,1);         // removing the prefix
      //Serial.println("C= " + dfd_global);
      int pos3=dfd_global.toInt(); 
      //Serial.println(pos3);
      s3.write(pos3); // run servo 3
      delay(10);
     }
     
  else if (dfd_global.startsWith("D")){    // to check which slider is the data coming from
      dfd_global.remove(0,1);         // removing the prefix
      //Serial.println("D= " + dfd_global);
      int pos4=dfd_global.toInt(); 
      //Serial.println(pos4);
      s4.write(pos4); // run servo 4
      delay(10);
     }   
     
  else if (dfd_global.startsWith("E")){    // to check which slider is the data coming from
      dfd_global.remove(0,1);         // removing the prefix
      //Serial.println("E= " + dfd_global);
      int pos5=dfd_global.toInt(); 
      //Serial.println(pos5);
      s5.write(pos5); // run servo 5
      delay(10);
     }   

  else if (dfd_global.startsWith("Z")){  // this is just a reset button on the nextion display, 
      s1.write(0);                       //that changes the angle of all the servos to 0°
      s2.write(0);
      s3.write(0);
      s4.write(0);
      s5.write(0);
      delay(10);
      }
      
  else{
    }
    
  }
