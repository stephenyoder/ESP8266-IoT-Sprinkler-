const int S = D0;

#define m_c 3830 // 261 Hz 

#define d 3400 // 294 Hz 

#define e 3038 // 329 Hz 

#define f 2864 // 349 Hz 

#define g 2550 // 392 Hz 


#define a 2272 // 440 Hz 

#define b 2028 // 493 Hz 

#define C 1912 // 523 Hz 

// Define a special note, 'R', to represent a rest

#define R 0

 

// MELODY and TIMING =======================================

// melody[] is an array of notes, accompanied by beats[], 

// which sets each note's relative length (higher #, longer note) 

int melody[] = { g, g, a, a, g, g, e, g, g, e, e, d };

int beats[] = { 16, 16, 16, 16, 8, 8, 32, 16, 16, 8, 8, 16 };

int MAX_COUNT = sizeof(melody) / 2; // Melody length, for looping.

 

// Set overall tempo

long tempo = 40000; //10000

// Set length of pause between notes

int pause = 1000; //1000

// Loop variable to increase Rest length

int rest_count = 100; //<-BLETCHEROUS HACK; See NOTES

 

// Initialize core variables

int tone_ = 0;

int beat = 0;

long duration_buzzer = 0;

 

// PLAY TONE ==============================================

// Pulse the speaker to play a tone for a particular duration_buzzer

void playTone() {

 long elapsed_time = 0;

 if (tone_ > 0) { // if this isn't a Rest beat, while the tone has 

 // played less long than 'duration_buzzer', pulse speaker HIGH and LOW

 while (elapsed_time < duration_buzzer) {

 

 digitalWrite(S, HIGH);

 delayMicroseconds(tone_ / 2);

 

 // DOWN

 digitalWrite(S, LOW);

 delayMicroseconds(tone_ / 2);

 

 // Keep track of how long we pulsed

 elapsed_time += (tone_);

 }

 }

 else { // Rest beat; loop times delay

 for (int j = 0; j < rest_count; j++) { // See NOTE on rest_count

 delayMicroseconds(duration_buzzer);

 }

 }

}


void setup()

{


  pinMode(S, OUTPUT);

  delay(1000);

}


void loop()

{


  tone_ = melody[2];

  beat = beats[2];

 

  duration_buzzer = beat * tempo; // Set up timing

 

  playTone();

  // A pause between notes...

  delayMicroseconds(pause); 


}
