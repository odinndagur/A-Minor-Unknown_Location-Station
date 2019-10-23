# A-Minor-Unknown_Location-station
 Location based music player for art installation. Decawave DWM1001 sensors for location data, Teensy 3.6's for the rest.
 
 The unit knows where you are in a room and plays different audio files (music loops and interviews with the artists that worked on the show) depending on where you are, fading between them so you can make your own mix of the journey through the art show.

It was set up in two rooms at an art museum. Each room has 4 DWM1001 sensors on the walls that talk to a DWM1001 unit that's mounted on a pair of headphones, getting the x,y location of the person wearing them within the room. It has six Teensy 3.6 boards, all connected to a mixer with audio transformers for each track to isolate the grounds. The first Teensy sends a UART message to the DWM1001 so it starts sending its location data in the form of 'POS,xx.xx,yy.yy,zz.zz,aa.aa' where x,y,z are the coordinates in meters and a is the accuracy of the sent data.
The Teensies all listen on their Serial1 pins. The first one receives the DWM1001 data and then reformats it to send it forward. Each Teensy receives on Serial1 and then sends the same data on Serial channels 4 and 5.

Each Teensy gets the location data, calculates the distance from the tag's (the person) x,y coordinates to each audio file's hardcoded x,y coordinates. If the person is closer than x distance the loop starts playing and fades in until they've reached max volume.

This has been a ton of work, hitting walls and having to learn how to get past them over and over again. If you have any questions re: this project, working with DWM1001s or anything I can help with, feel free to send an issue here on Github or send me an email at odinnd@gmail.com
