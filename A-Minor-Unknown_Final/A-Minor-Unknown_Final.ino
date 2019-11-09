#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioPlaySdWav           playSdWav1;     //xy=317.50000762939453,260.00000381469727
AudioOutputI2S           i2s1;           //xy=1873,253
AudioConnection          patchCord1(playSdWav1, 0, i2s1, 0);
AudioConnection          patchCord2(playSdWav1, 1, i2s1, 1);
AudioControlSGTL5000     sgtl5000_1;     //xy=168.5000114440918,180.00000381469727
// GUItool: end automatically generated code

// Use these with the Teensy 3.5 & 3.6 SD card
#define SDCARD_CS_PIN    BUILTIN_SDCARD
#define SDCARD_MOSI_PIN  11  // not actually used
#define SDCARD_SCK_PIN   13  // not actually used

float tagPosX = 100; // float for tag x position
float tagPosY = 100;; // float for tag y position
float tagPosZ; // float for tag z position
float tagPosAcc; // float for accuracy percentage

#define TEENSY6 // set to #define TEENSY1, TEENSY2 all the way to 6, the loop
                // positions, names, play and fade distances as well as min/max
                // volumes are set for the selected Teensy

#ifdef TEENSY1
 //teensy folder 1
         const int loopCount = 6; // const int to define how many loops there are in total
         const char* loopNames[loopCount] = {"D6-T_C.WAV", "I1.WAV", "J3.WAV", "L6A-T.WAV", "S_COMP.WAV", "V_COMP.WAV"}; // const char* array for loop names on sd card

         float loopPosX[loopCount] = {39.00, 2.52, 19.66, 18.30, 10.86, 34.37}; // float array for x position of music loops
         float loopPosY[loopCount] = {6.00, 0.71, 9.01, 3.70, 6.82, 11.90}; // float array for y position of music loops

         float playDist[loopCount] = {4.0, 4.0, 3.4, 2.2, 4.7, 6.2}; // float for distance to start playing loop at
         float distMinVol[loopCount] = {2.6, 3.0, 2.0, 1.7, 3.7, 4.6}; // float for distance for fade to start (maximum distance, minimum volume)
         float distMaxVol[loopCount] = {2.4, 2.4, 1.9, 1.0, 2.7, 4.2}; // float for distance for max volume (maximum volume, minimum distance)

         float fadeDist[loopCount] = {1.0, 0.8, 2.0, 0.8, 1.2, 1.5}; // float for distance to fade from min to max vol

         float minVol = 0.2;
         float maxVol = 0.6;
#endif

#ifdef TEENSY2

 //teensy folder 2
         const int loopCount = 5; // const int to define how many loops there are in total
         const char* loopNames[loopCount] = {"B_COMP.WAV", "DR_I.WAV", "E1.WAV", "L4B-T.WAV", "S3-T.WAV"}; // const char* array for loop names on sd card
         //
         float loopPosX[loopCount] = {41.10, 34.58, 27.01, 14.75, 12.21}; // float array for x position of music loops
         float loopPosY[loopCount] = {10.90, 19.40, 8.06, 1.50, 6.61}; // float array for y position of music loops
         //
         float playDist[loopCount] = {4.4, 5.0, 4.4, 3.0, 2.6}; // float for distance to start playing loop at
         float distMinVol[loopCount] = {3.0, 3.2, 3.0, 2.7, 2.0}; // float for distance for fade to start (maximum distance, minimum volume)
         float distMaxVol[loopCount] = {2.6, 2.0, 2.0, 2.2, 1.2}; // float for distance for max volume (maximum volume, minimum distance)

         float fadeDist[loopCount] = {0.6, 1.8, 1.2, 0.7, 0.9}; // float for distance to fade from min to max vol

         float minVol = 0.2;
         float maxVol = 0.5;
#endif

#ifdef TEENSY3

//teensy folder 3
            const int loopCount = 5; // const int to define how many loops there are in total
            const char* loopNames[loopCount] = {"E2.WAV", "G_COMP.WAV", "H3-T-S.WAV", "L_COMP.WAV", "S4-T.WAV"}; // const char* array for loop names on sd card
            //
            float loopPosX[loopCount] = {27.36, 41.00, 5.32, 17.10, 10.08}; // float array for x position of music loops
            float loopPosY[loopCount] = {10.47, 18.80, 4.89, 2.27, 6.78}; // float array for y position of music loops
            //
            float playDist[loopCount] = {3.5, 5.8, 2.6, 5.5, 2.8}; // float for distance to start playing loop at
            float distMinVol[loopCount] = {2.5, 4.0, 2.0, 4.0, 2.0}; // float for distance for fade to start (maximum distance, minimum volume)
            float distMaxVol[loopCount] = {2.3, 3.1, 1.7, 3.2, 1.2}; // float for distance for max volume (maximum volume, minimum distance)

            float fadeDist[loopCount] = {0.6, 1.5, 0.6, 0.6, 1.0}; // float for distance to fade from min to max vol

            float minVol = 0.2;
            float maxVol = 0.5;
#endif

#ifdef TEENSY4

 //teensy folder 4
         const int loopCount = 5; // const int to define how many loops there are in total
         const char* loopNames[loopCount] = {"D_COMP.WAV", "H1.WAV", "J_COMP.WAV", "R_C-1.WAV", "V4-TH.WAV"}; // const char* array for loop names on sd card
         //
         float loopPosX[loopCount] = {32.56, 5.72, 16.11, 30.08, 33.40}; // float array for x position of music loops
         float loopPosY[loopCount] = {5.83, 6.89, 8.5, 19.73, 13.15}; // float array for y position of music loops
         //
         float playDist[loopCount] = {5.0, 3.7, 3.3, 4.0, 3.0}; // float for distance to start playing loop at
         float distMinVol[loopCount] = {4.0, 2.7, 2.3, 3.0, 2.0}; // float for distance for fade to start (maximum distance, minimum volume)
         float distMaxVol[loopCount] = {2.9, 2.0, 2.1, 2.7, 1.7}; // float for distance for max volume (maximum volume, minimum distance)

         float fadeDist[loopCount] = {1.3, 2.7, 0.6, 0.6, 0.6}; // float for distance to fade from min to max vol

         float minVol = 0.2;
         float maxVol = 0.5;
#endif

#ifdef TEENSY5

 //teensy folder 5
         const int loopCount = 5; // const int to define how many loops there are in total
         const char* loopNames[loopCount] = {"D34TC.WAV", "L5C-T.WAV", "R_C-2.WAV", "T_C1.WAV", "V5-TL.WAV"}; // const char* array for loop names on sd card
         //
         float loopPosX[loopCount] = {31.50, 17.00, 28.51, 7.81, 35.50}; // float array for x position of music loops
         float loopPosY[loopCount] = {6.55, 1.50, 16.18, 1.50, 11.05}; // float array for y position of music loops
         //
         float playDist[loopCount] = {2.7, 2.1, 4.2, 4.7, 3.0}; // float for distance to start playing loop at
         float distMinVol[loopCount] = {2.2, 2.1, 3.2, 3.7, 2.0}; // float for distance for fade to start (maximum distance, minimum volume)
         float distMaxVol[loopCount] = {1.7, 1.7, 2.7, 2.2, 1.7}; // float for distance for max volume (maximum volume, minimum distance)

         float fadeDist[loopCount] = {0.7, 0.4, 0.7, 2.4, 0.6}; // float for distance to fade from min to max vol

         float minVol = 0.2;
         float maxVol = 0.5;
#endif

#ifdef TEENSY6

//teensy folder 6
          const int loopCount = 5; // const int to define how many loops there are in total
          const char* loopNames[loopCount] = {"BRI.WAV", "D5-T.WAV", "H2.WAV", "R45T.WAV", "T_C2.WAV"}; // const char* array for loop names on sd card
          
          float loopPosX[loopCount] = {0.00, 34.95, 3.51, 31.41, 12.65}; // float array for x position of music loops
          float loopPosY[loopCount] = {0.00, 6.15, 4.63, 19.81, 1.50}; // float array for y position of music loops
          
          float playDist[loopCount] = {0.0, 2.7, 3.2, 2.5, 4.0}; // float for distance to start playing loop at
          float distMinVol[loopCount] = {0.0, 2.2, 2.2, 2.0, 3.0}; // float for distance for fade to start (maximum distance, minimum volume)
          float distMaxVol[loopCount] = {0.0, 1.7, 2.0, 1.7, 2.0}; // float for distance for max volume (maximum volume, minimum distance)
          
          float fadeDist[loopCount] = {0.0, 0.7, 1.0, 0.6, 1.2}; // float for distance to fade from min to max vol
          
          float minVol = 0.2;
          float maxVol = 0.5;
#endif


float loopPosDiff[loopCount]; // float array for distance between tag and each music loop

int nowPlaying = 8; // variable to contain now playing file
float loopVolume = 0.8; // temp variable to contain loop volume
float constrainedLoopVolume; // variable to contain constrained loop volume between min and max volumes

String posString; // string to keep message from DWM1001 while parsing the data

unsigned long currentMillis; // millis timer
unsigned long previousMillis; // millis timer

int lepTimer = 3000; // how long to wait until sending for new data from DWM1001

String c; // temporary string variable


void setup() {
  Serial.begin(115200); // begin serial at 115200 baud rate
  Serial1.begin(115200); // dwm1001 requires 115200 baud rate
  Serial4.begin(115200); // to send data to next teensies
  Serial5.begin(115200); // to send data to next teensies

  // Audio connections require memory to work.  For more
  // detailed information, see the MemoryAndCpuUsage example
  AudioMemory(8);

  // Comment these out if not using the audio adaptor board.
  // This may wait forever if the SDA & SCL pins lack
  // pullup resistors
  sgtl5000_1.enable(); // enable audio chip on the audio board
  sgtl5000_1.volume(maxVol);

  SPI.setMOSI(SDCARD_MOSI_PIN);
  SPI.setSCK(SDCARD_SCK_PIN);
  if (!(SD.begin(SDCARD_CS_PIN))) {
    // stop here if the sd card won't load, but print a message repetitively
    while (1) {
      Serial.println("Unable to access the SD card");
      delay(500);
    }
  }
}


void loop() {
  //   put your main code here, to run repeatedly:
  //char posString[] = "POS,130.85,200.05,420.45,950"; // example of message received from DWM_1001

  currentMillis = millis(); // set currentMillis to the time at beginning of loop

  if ((!(Serial1.available() > 0)) && currentMillis - previousMillis > lepTimer) {
    previousMillis = currentMillis; // reset timer as soon as Serial is received
    Serial.print("currentMillis = ");
    Serial.println(currentMillis);
    Serial.print("previousMillis = ");
    Serial.println(previousMillis);
    Serial.print("Serial available status: ");
    Serial.println(Serial1.available());

    Serial1.write(0x0D); //send the first "Enter"
    delay(20);
    Serial1.write(0x0D); //send the second "Enter" to get into Shell Mode

    c = Serial1.readString(); //read the response from dwm1001
    Serial.print("String c is: ");
    Serial.println(c);

    Serial1.write(0x6C); //send "l"
    Serial1.write(0x65); //send "e"
    //    Serial1.write(0x63); //send "c"
    Serial1.write(0x70); //send "p"
    Serial1.write(0x0D); //send "Enter"
  }



  if (Serial1.available() > 0) {
    previousMillis = millis(); // reset timer as soon as Serial is received
    posString = Serial1.readStringUntil('\n'); // read message from DWM1001 all the way until the newline character
    Serial.println(posString);

    char posString_array[posString.length()];     // char array to hold the message string
    posString.toCharArray(posString_array, posString.length()); // put the string into the char array


    char* posString1 = strtok(posString_array, ","); // strtok parses the array, splits on the commas
    char* posString2 = strtok(NULL, ",");           // making different char* elements for each value, pos X
    char* posString3 = strtok(NULL, ",");          // pos Y
    char* posString4 = strtok(NULL, ",");         // pos Z
    char* posString5 = strtok(NULL, ",");        // pos Accuracy


    tagPosAcc = atoi(posString5); // make variable tagPosAcc = the tag's position accuracy
    if (tagPosAcc > 40) {         // if accuracy is 40+
      tagPosX = atof(posString2); // make variable tagPosX = the tag's X location
      tagPosY = atof(posString3); // make variable tagPosY = the tag's Y location
      tagPosZ = atof(posString4); // make variable tagPosZ = the tag's Z location
      tagPosAcc = atoi(posString5); // make variable tagPosAcc = the tag's position accuracy
      sendPos();
    }

  }

  for (int i = 0; i < loopCount; i++) {
    loopPosDiff[i] = positionDifference(tagPosX, tagPosY, loopPosX[i], loopPosY[i]); // loopPosDiff[i] = the linear distance between the tag and current loop
    if ((loopPosDiff[i] < playDist[i]) && (!playSdWav1.isPlaying())) { // if distance to loop for i in array loopPosDiff is less than playDist for i
      playFile(loopNames[i]);
      nowPlaying = i;
    }
  }

  // set loopVolume to a map of the nowplaying position difference, the fade values and the volume levels possible
  loopVolume = mapf(loopPosDiff[nowPlaying], distMinVol[nowPlaying], (distMinVol[nowPlaying] - fadeDist[nowPlaying]), minVol, maxVol); // loopVolume is a point between minVol and maxVol depending on how big loopPosDiff is
  constrainedLoopVolume = constrain(loopVolume, minVol, maxVol); // map function can output higher or lower numbers, make sure they fit in minVol - maxVol range
  sgtl5000_1.volume(constrainedLoopVolume); // set output volume to the constrainedLoopVolume

  if ((loopPosDiff[nowPlaying] > playDist[nowPlaying])) { // if loop is out of range stop playing it
    playSdWav1.stop();
    Serial.println("Stopped");
    nowPlaying = 8;
  }


}


float positionDifference(float tagX, float tagY, float loopX, float loopY) {
  // function that takes as arguments the tag's x and y coordinates and
  // the current loop's x and y coordinates and calculates the linear
  // distance between them

  float xDiff = fabs(tagX - loopX);
  float yDiff = fabs(tagY - loopY);

  float positionDifference = sqrt((pow(xDiff, 2)) + pow(yDiff, 2));

  return positionDifference;

}

void sendLep() {
  // function that sends lep to DWM1001 to start receiving data
  // to communicate with the DWM1001 chip you have to send
  // enter twice to open communication, then send lep to start 
  // receiving the position data when available, max 10hz

  Serial1.write(0x0D); //send the first "Enter"
  delay(20);
  Serial1.write(0x0D); //send the second "Enter" to get into Shell Mode
  // String c = Serial1.readString(); //read the response from dwm1001
  Serial1.write(0x6C); //send "l"
  Serial1.write(0x65); //send "e"
  //Serial1.write(0x63); //send "c"
  Serial1.write(0x70); //send "p"
  Serial1.write(0x0D); //send "Enter"
}

void playFile(const char *filename)
{
  Serial.print("Playing file: ");
  Serial.println(filename);

  // Start playing the file.  This sketch continues to
  // run while the file plays.
  playSdWav1.play(filename);

  // A brief delay for the library read WAV info
  delay(5);

}

double mapf(double x, double in_min, double in_max, double out_min, double out_max)
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

void sendPos() {
  // function that sends the current tagPosX, Y, Z and accuracy and sends as a string with the same format as DWM1001
  // so that one arduino can receive the dwm1001 string and then pays it forward
  Serial4.print("POS");
  Serial4.print(',');
  Serial4.print(tagPosX);
  Serial4.print(',');
  Serial4.print(tagPosY);
  Serial4.print(',');
  Serial4.print(tagPosZ);
  Serial4.print(',');
  Serial4.print(tagPosAcc);
  Serial4.print('\n');

  Serial5.print("POS");
  Serial5.print(',');
  Serial5.print(tagPosX);
  Serial5.print(',');
  Serial5.print(tagPosY);
  Serial5.print(',');
  Serial5.print(tagPosZ);
  Serial5.print(',');
  Serial5.print(tagPosAcc);
  Serial5.print('\n');
}
