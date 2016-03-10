
int h;
int m;
int hbon;
int hwon;
int hboff;
int hwoff;
int mbon;
int mwon;
int mboff;
int mwoff;

int stateL = 0;
int stateBlue = 0;
int stateWhite = 0;
int stateOff = 0;
int timer = 0;

bool Run = false;

double config;
unsigned int address;

long time = 0;         // the last time the output pin was toggled
long debounce = 200;   // the debounce time, increase if the output flickers

int adc_key_in;
int k;


unsigned long currentMillis = 0;
unsigned long timeOnWhite = 21600000; //6 horas
unsigned long timeOnBlue = 600000; //10 minutos
unsigned long timeOn10 = 600000; //10 minutos
unsigned long timeOn2 = 120000; //2 minutos


/*
//For TESTS
unsigned long currentMillis = 0;
unsigned long timeOnWhite = 60000; //2 minutos
unsigned long timeOnBlue = 60000; //1 minutos
unsigned long timeOn10 = 60000; //2 minutos
unsigned long timeOn2 = 60000; //1 minutos
*/

int btstate = 0;
int EEsize = 1024;
unsigned long t = 0;
unsigned long a = 0 ;

int HighByte, LowByte, TReading, SignBit, Tc_100, Whole, Fract;
char buf[20];


byte i, sensor;
byte present = 0;
byte data[12];




















