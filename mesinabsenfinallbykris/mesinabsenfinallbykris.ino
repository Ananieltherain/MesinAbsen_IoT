/*Program by: Kris Muliawan
tgl: 10/05/24
Program: uji coba sistem absensi berbasis RFID
update 27/07/24
project tjkt
program by Kris Muliawan
wiring by Claudio Romeo Lona
SD card module
RTC DS3231
RFID MRFC 522
LCD 16x2
Arduino Mega 2560
*/

#include <SD.h>
#include <SPI.h> 
#include <MFRC522.h>
#include <RTClib.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
const int ss=53;  //pin sda mrfc522
const int rst=5;  //pin rst mrfc522 
const int cs=48; // pin sd card yang cs
const int relay=8;
//int count=0;
//int LastState=HIGH;
LiquidCrystal_I2C lcd(0x27, 16, 2);

bool on=LOW;
bool off=HIGH;

int const buzzer = 2;
int pb_mode = A0;
String name;
String id;
String tanggal;
String waktu;

byte readCard[4];
//untuk menambahkan kartu:kris
int cards1[4] = {243 ,143 ,54 ,16};  
int cards2[4] = {84 ,203 ,80 ,113};  
int cards3[4] = {227 ,81 ,252 ,247};  
int cards4[4] = {3 ,73 ,29 ,248};  
int cards5[4] = { 3 ,169 ,39 ,248};  
int cards6[4] = {193 ,166 ,78 ,15};  
int cards7[4] = {112 ,93 ,126 ,88};  
int cards8[4] = {193 ,126 ,174 ,15};  
int cards9[4] = {112 ,21 ,98 ,19};  
int cards10[4] = {227 ,127 ,50 ,248};  
int cards11[4] = {35 ,186 ,254 ,247}; 
int cards12[4] = {115 ,57 ,13 ,248};  
int cards13[4] = {99 ,17 ,7 ,248};  
int cards14[4] = {227 ,205 ,5 ,248};  
int cards15[4] = {168 ,89 ,14 ,152};  
int cards16[4] = {152 ,58 ,231 ,153};  
int cards17[4] = {200 ,57 ,6 ,152};  
int cards18[4] = {112 ,112 ,152 ,88};  
int cards19[4] = {83 ,96 ,48 ,248};  
int cards20[4] = {120 ,27 ,30 ,153};  
int cards21[4] = {152 ,123 ,245 ,153};  
int cards22[4] = {115 ,254 ,5 ,248};  
int cards23[4] = {145 ,223 ,153 ,15};  
int cards24[4] = {145 ,181 ,18 ,15};  
int cards25[4] = {104 ,226 ,254 ,153};  
int cards26[4] = {243 ,126 ,247 ,247};  
int cards27[4] = {120 ,60 ,150 ,153};  
int cards28[4] = {248 ,197 ,85 ,152};  
int cards29[4] = {40 ,191 ,228 ,153};  
int cards30[4] = {227 ,219 ,21 ,248};  
int cards31[4] = {144 ,123 ,16 ,19};  
int cards32[4] = {51 ,215 ,235 ,26};  
int cards33[4] = {145 ,182 ,33 ,15};  
int cards34[4] = {112 ,113 ,14 ,88};  
int cards35[4] = {195 ,90 ,40 ,248};  
int cards36[4] = {145 ,156 ,218 ,15};  
int cards37[4] = {88 ,23 ,72 ,153};  
int cards38[4] = {115 ,18 ,251 ,247};  
int cards39[4] = {112 ,107 ,233 ,88};  
int cards40[4] = {216 ,160 ,130 ,152};  
int cards41[4] = {99 ,239 ,12 ,248};  
int cards42[4] = {243 ,163 ,2 ,248};  
int cards43[4] = {24 ,211 ,142 ,153};
int cards44[4] = {51 ,226 ,20 ,248};  
int cards45[4] = {243 ,11 ,39 ,248};  
int cards46[4] = {67 ,208 ,255 ,247};  
int cards47[4] = {147 ,185 ,142 ,13};  
int cards48[4] = {144 ,123 ,15 ,19}; 
int cards49[4] = {211 ,13 ,50 ,248};  
int cards50[4] = {112 ,69 ,230 ,88};  
int cards51[4] = {179 ,168 ,241 ,247};  
int cards52[4] = {163 ,253 ,137 ,79};  
int cards53[4] = {90 ,70 ,107 ,129};
int cards54[4] = {227 ,100 ,194 ,2};
int cards55[4] = {160 ,44 ,110 ,88};
int cards56[4] = {1 , 1, 1 ,1};     
int cards57[4] = {1 , 1, 1 ,1};     
int cards58[4] = {1 , 1, 1 ,1};     
int cards59[4] = {1 , 1, 1 ,1};     
int cards60[4] = {1 , 1, 1 ,1};                                          
int cards61[4] = {1 , 1, 1 ,1};     
int cards62[4] = {1 , 1, 1 ,1};     
int cards63[4] = {1 , 1, 1 ,1};     
int cards64[4] = {1 , 1, 1 ,1};     
int cards65[4] = {1 , 1, 1 ,1};     
int cards66[4] = {1 , 1, 1 ,1};     
int cards67[4] = {1 , 1, 1 ,1};     
int cards68[4] = {1 , 1, 1 ,1};     
int cards69[4] = {1 , 1, 1 ,1};     
int cards70[4] = {1 , 1, 1 ,1};     
int cards71[4] = {1 , 1, 1 ,1};     
int cards72[4] = {1 , 1, 1 ,1};     
int cards73[4] = {1 , 1, 1 ,1};     
int cards74[4] = {1 , 1, 1 ,1};     
int cards75[4] = {1 , 1, 1 ,1};     
int cards76[4] = {1 , 1, 1 ,1};     
int cards77[4] = {1 , 1, 1 ,1};     
int cards78[4] = {1 , 1, 1 ,1};     
int cards79[4] = {1 , 1, 1 ,1};     
int cards80[4] = {1 , 1, 1 ,1};     
int cards81[4] = {1 , 1, 1 ,1};     
int cards82[4] = {1 , 1, 1 ,1};     
int cards83[4] = {1 , 1, 1 ,1};
int cards84[4] = {1 , 1, 1 ,1};
int cards85[4] = {1 , 1, 1 ,1};
int cards86[4] = {1 , 1, 1 ,1};
int cards87[4] = {1 , 1, 1 ,1};
int cards88[4] = {1 , 1, 1 ,1};
int cards89[4] = {1 , 1, 1 ,1};
int cards90[4] = {1 , 1, 1 ,1};
int cards91[4] = {1 , 1, 1 ,1};     
int cards92[4] = {1 , 1, 1 ,1};
int cards93[4] = {1 , 1, 1 ,1};
int cards94[4] = {1 , 1, 1 ,1};
int cards95[4] = {1 , 1, 1 ,1};
int cards96[4] = {1 , 1, 1 ,1};
int cards97[4] = {1 , 1, 1 ,1};
int cards98[4] = {1 , 1, 1 ,1};
int cards99[4] = {1 , 1, 1 ,1};
int cards100[4] = {1 , 1, 1 ,1};     
int cards101[4] = {1 , 1, 1 ,1};
int cards102[4] = {1 , 1, 1 ,1};
int cards103[4] = {1 , 1, 1 ,1};
int cards104[4] = {1 , 1, 1 ,1};
int cards105[4] = {1 , 1, 1 ,1};
int cards106[4] = {1 , 1, 1 ,1};
int cards107[4] = {1 , 1, 1 ,1};
int cards108[4] = {1 , 1, 1 ,1};
int cards109[4] = {1 , 1, 1 ,1};     
int cards110[4] = {1 , 1, 1 ,1};
int cards111[4] = {1 , 1, 1 ,1};
int cards112[4] = {1 , 1, 1 ,1};
int cards113[4] = {1 , 1, 1 ,1};
int cards114[4] = {1 , 1, 1 ,1};
int cards115[4] = {1 , 1, 1 ,1};
int cards116[4] = {1 , 1, 1 ,1};
int cards117[4] = {1 , 1, 1 ,1};
int cards118[4] = {1 , 1, 1 ,1};     
int cards119[4] = {1 , 1, 1 ,1};
int cards120[4] = {1 , 1, 1 ,1};
int cards121[4] = {1 , 1, 1 ,1};
int cards122[4] = {1 , 1, 1 ,1};
int cards123[4] = {1 , 1, 1 ,1};
int cards124[4] = {1 , 1, 1 ,1};
int cards125[4] = {1 , 1, 1 ,1};
int cards126[4] = {1 , 1, 1 ,1};
int cards127[4] = {1 , 1, 1 ,1};     
int cards128[4] = {1 , 1, 1 ,1};
int cards129[4] = {1 , 1, 1 ,1};
int cards130[4] = {1 , 1, 1 ,1};
int cards131[4] = {1 , 1, 1 ,1};
int cards132[4] = {1 , 1, 1 ,1};
int cards133[4] = {1 , 1, 1 ,1};
int cards134[4] = {1 , 1, 1 ,1};
int cards135[4] = {1 , 1, 1 ,1};
int cards136[4] = {1 , 1, 1 ,1};     
int cards137[4] = {1 , 1, 1 ,1};
int cards138[4] = {1 , 1, 1 ,1};
int cards139[4] = {1 , 1, 1 ,1};
int cards140[4] = {1 , 1, 1 ,1};
int cards141[4] = {1 , 1, 1 ,1};
int cards142[4] = {1 , 1, 1 ,1};
int cards143[4] = {1 , 1, 1 ,1};
int cards144[4] = {1 , 1, 1 ,1};
int cards145[4] = {1 , 1, 1 ,1};
int cards146[4] = {1 , 1, 1 ,1};
int cards147[4] = {1 , 1, 1 ,1};
int cards148[4] = {1 , 1, 1 ,1};
int cards149[4] = {1 , 1, 1 ,1};
int cards150[4] = {1 , 1, 1 ,1};
int cards151[4] = {1 , 1, 1 ,1};
int cards152[4] = {1 , 1, 1 ,1};
int cards153[4] = {1 , 1, 1 ,1};
int cards154[4] = {1 , 1, 1 ,1};
int cards155[4] = {1 , 1, 1 ,1};
int cards156[4] = {1 , 1, 1 ,1};
int cards157[4] = {1 , 1, 1 ,1};
int cards158[4] = {1 , 1, 1 ,1};
int cards159[4] = {1 , 1, 1 ,1};
int cards160[4] = {1 , 1, 1 ,1};
int cards161[4] = {1 , 1, 1 ,1};
int cards162[4] = {1 , 1, 1 ,1};
int cards163[4] = {1 , 1, 1 ,1};
int cards164[4] = {1 , 1, 1 ,1};
int ID;
String nama;
String kelas;
bool status_kartu = false;
bool sudah_absen = false;
//boolean mode_pulang = false; (kesalahan koding)??
bool mode_pulang= false;
RTC_DS3231 rtc;
MFRC522 mfrc522(ss, rst);
File file;
char daysOfTheWeek[7][12] = {"Minggu", "Senin", "Selasa", "Rabu", "Kamis", "Jum'at", "Sabtu"};


void setup() {
  Serial.begin(9600);
  rtc.begin();
  pinMode(relay,OUTPUT);
  pinMode(cs,OUTPUT);
  lcd.backlight();
  lcd.init();
  while(!Serial){
    ;
  }
  SPI.begin();
  digitalWrite(relay,off);
  digitalWrite(cs,off);
  delay(100);
  mfrc522.PCD_Init();
  pinMode(pb_mode, INPUT_PULLUP); //pushbutton
  pinMode(buzzer, OUTPUT); //buzzer
  digitalWrite(buzzer, LOW); //buzzer
  //jika waktu rtc eror perbaiki di kodingan ini *kris
  //rtc.adjust(DateTime(tahun, bulan, tanggal, jam, menit, detik.)); *Kris
  
  if (! rtc.begin()) {
    Serial.println("RTC tidak terhubung, Cek kembali wiring!");
    while (1);
  }
  if (rtc.lostPower()) {
    Serial.println("RTC tidak bekerja, Setel ulang waktu!");
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }

  Serial.println("CLEARSHEET");
  Serial.println("LABEL,ID,Date,Name,Card ID,kelas,Time IN,Time OUT");
  
  lcd.setCursor(1, 0);
  lcd.print("System Absensi");
  lcd.setCursor(0, 1);
  lcd.print("by: Kris & Dio");

  delay(5000);
  lcd.clear();
  delay(50);
}

//atur jadwal otomatis made by.Kris
void loop() {
  DateTime now = rtc.now();
  int day = now.day();
  int month = now.month();
  int year = now.year();
  int hour = now.hour();
  int minute = now.minute();
  int second = now.second();

  String dateStr = String(day) + "/" + String(month) + "/" + String(year);
  String timeStr = String(hour) + ":" + String(minute) + ":" + String(second);

  if (digitalRead(pb_mode) == LOW) {

    mode_pulang = !mode_pulang;
  }
  
  if (now.hour() == 5 && now.minute() == 0 && now.second() == 0){
    mode_pulang = false;
    Serial.println("Absen masuk");
    delay(1000);
  }

  if (now.hour() == 12 && now.minute() == 0 && now.second() == 0){
    mode_pulang = true;
    Serial.println("Absen pulang");
    delay(1000);
  }

    {
    delay(500);
  }

  lcd.setCursor(4, 1);
  printposisilcd(now.hour());
  lcd.print(":");
  printposisilcd(now.minute());
  lcd.print(":");
  printposisilcd(now.second());

  if (mode_pulang == true) {
    lcd.setCursor(2, 0);
    lcd.print("Absen Pulang");
  }
  else {
    lcd.setCursor(2, 0);
    lcd.print("Absen Masuk ");
  }


  if ( ! mfrc522.PICC_IsNewCardPresent()) {
    return;
  }

  if ( ! mfrc522.PICC_ReadCardSerial()) {
    return;
  }

  if (mfrc522.uid.uidByte[0] != readCard[0] ||
      mfrc522.uid.uidByte[1] != readCard[1] ||
      mfrc522.uid.uidByte[2] != readCard[2] ||
      mfrc522.uid.uidByte[3] != readCard[3] ) {

    Serial.println("");
    Serial.print("UID : ");
    for (byte i = 0; i < mfrc522.uid.size; i++) {
      readCard[i] = mfrc522.uid.uidByte[i];
      Serial.print(readCard[i]);
      if (i < mfrc522.uid.size - 1) {
        Serial.print(" ,");
      }
      else {
        Serial.println("");
      }

      sudah_absen = false;
      status_kartu = true;

      //admin
      if ((readCard[i] == cards1[i]) && (readCard[i-1] == cards1[i-1]) && (readCard[i-2] == cards1[i-2]) && (readCard[i-3] == cards1[i-3])) {
        ID = 1;
        nama = "Kris";
        kelas = "ADMIN";
      }   
      else if ((readCard[i] == cards2[i]) && (readCard[i-1] == cards2[i-1]) && (readCard[i-2] == cards2[i-2]) && (readCard[i-3] == cards2[i-3])) {
        ID = 2;
        nama = "Claudio";
        kelas = "ADMIN";
      }
      else if ((readCard[i] == cards3[i]) && (readCard[i-1] == cards3[i-1]) && (readCard[i-2] == cards3[i-2]) && (readCard[i-3] == cards3[i-3])) {
        ID = 3;
        nama = "Aby";
        kelas = "XI-TO";
      }
      //XI-TO
      else if ((readCard[i] == cards4[i]) && (readCard[i-1] == cards4[i-1]) && (readCard[i-2] == cards4[i-2]) && (readCard[i-3] == cards4[i-3])) {
        ID = 4;
        nama = "Ahmad.F)";
        kelas = "XI-TO";
      }
      else if ((readCard[i] == cards5[i]) && (readCard[i-1] == cards5[i-1]) && (readCard[i-2] == cards5[i-2]) && (readCard[i-3] == cards5[i-3])) {
        ID = 5;
        nama = "A. Rizky";
        kelas = "XI-TO";
      }
      else if ((readCard[i] == cards6[i]) && (readCard[i-1] == cards6[i-1]) && (readCard[i-2] == cards6[i-2]) && (readCard[i-3] == cards6[i-3])) {
        ID = 6;
        nama = "Alvin.M.N";
        kelas = "XI-TO";
      }
             else if ((readCard[i] == cards7[i]) && (readCard[i-1] == cards7[i-1]) && (readCard[i-2] == cards7[i-2]) && (readCard[i-3] == cards7[i-3])) {
        ID = 7;
        nama = "Aria.S.P";
        kelas = "XI-TO";
      }
             else if ((readCard[i] == cards8[i]) && (readCard[i-1] == cards8[i-1]) && (readCard[i-2] == cards8[i-2]) && (readCard[i-3] == cards8[i-3])) {
        ID = 8;
        nama = "Fiky.N";
        kelas = "XI-TO";
      }
             else if ((readCard[i] == cards9[i]) && (readCard[i-1] == cards9[i-1]) && (readCard[i-2] == cards9[i-2]) && (readCard[i-3] == cards9[i-3])) {
        ID = 9;
        nama = "Joshua.C";
        kelas = "XI-TO";
      }
             else if ((readCard[i] == cards10[i]) && (readCard[i-1] == cards10[i-1]) && (readCard[i-2] == cards10[i-2]) && (readCard[i-3] == cards10[i-3])) {
        ID = 10;
        nama = "M.adam.R";
        kelas = "XI-TO";
      }
             else if ((readCard[i] == cards11[i]) && (readCard[i-1] == cards11[i-1]) && (readCard[i-2] == cards11[i-2]) && (readCard[i-3] == cards11[i-3])) {
        ID = 11;
        nama = "M.Gilang.E.S";
        kelas = "XI-TO";
      }
             else if ((readCard[i] == cards12[i]) && (readCard[i-1] == cards12[i-1]) && (readCard[i-2] == cards12[i-2]) && (readCard[i-3] == cards12[i-3])) {
        ID = 12;
        nama = "M.Rifqi.S";
        kelas = "XI-TO";
      }
             else if ((readCard[i] == cards13[i]) && (readCard[i-1] == cards13[i-1]) && (readCard[i-2] == cards13[i-2]) && (readCard[i-3] == cards13[i-3])) {
        ID = 13;
        nama = "Oka.S.P";
        kelas = "XI-TO";
      }
             else if ((readCard[i] == cards14[i]) && (readCard[i-1] == cards14[i-1]) && (readCard[i-2] == cards14[i-2]) && (readCard[i-3] == cards14[i-3])) {
        ID = 14;
        nama = "Ragil.F";
        kelas = "XI-TO";
      }
             else if ((readCard[i] == cards15[i]) && (readCard[i-1] == cards15[i-1]) && (readCard[i-2] == cards15[i-2]) && (readCard[i-3] == cards15[i-3])) {
        ID = 15;
        nama = "Raihan.S";
        kelas = "XI-TO";
      }
             else if ((readCard[i] == cards16[i]) && (readCard[i-1] == cards16[i-1]) && (readCard[i-2] == cards16[i-2]) && (readCard[i-3] == cards16[i-3])) {
        ID = 16;
        nama = "Rasta.E.V";
        kelas = "XI-TO";
      }
             else if ((readCard[i] == cards17[i]) && (readCard[i-1] == cards17[i-1]) && (readCard[i-2] == cards17[i-2]) && (readCard[i-3] == cards17[i-3])) {
        ID = 17;
        nama = "Steven.G";
        kelas = "XI-TO";
      }
             else if ((readCard[i] == cards18[i]) && (readCard[i-1] == cards18[i-1]) && (readCard[i-2] == cards18[i-2]) && (readCard[i-3] == cards18[i-3])) {
        ID = 18;
        nama = "Syahrul.M";
        kelas = "XI-TO";
      }
             else if ((readCard[i] == cards19[i]) && (readCard[i-1] == cards19[i-1]) && (readCard[i-2] == cards19[i-2]) && (readCard[i-3] == cards19[i-3])) {
        ID = 19;
        nama = "Yazul.J";
        kelas = "XI-TO";
      }
             else if ((readCard[i] == cards20[i]) && (readCard[i-1] == cards20[i-1]) && (readCard[i-2] == cards20[i-2]) && (readCard[i-3] == cards20[i-3])) {
        ID = 20;
        nama = "M.Ridwan";
        kelas = "XI-TO";
      }
             else if ((readCard[i] == cards21[i]) && (readCard[i-1] == cards21[i-1]) && (readCard[i-2] == cards21[i-2]) && (readCard[i-3] == cards21[i-3])) {
        ID = 21;
        nama = "M.Rafli";
        kelas = "XI-TO";
      }
      //XI-TJKT
             else if ((readCard[i] == cards22[i]) && (readCard[i-1] == cards22[i-1]) && (readCard[i-2] == cards22[i-2]) && (readCard[i-3] == cards22[i-3])) {
        ID = 22;
        nama = "Bagas.A.P";
        kelas = "XI-TJKT";
      }
             else if ((readCard[i] == cards23[i]) && (readCard[i-1] == cards23[i-1]) && (readCard[i-2] == cards23[i-2]) && (readCard[i-3] == cards23[i-3])) {
        ID = 23;
        nama = "Devan Orlando";
        kelas = "XI-TJKT";
      }
             else if ((readCard[i] == cards24[i]) && (readCard[i-1] == cards24[i-1]) && (readCard[i-2] == cards24[i-2]) && (readCard[i-3] == cards24[i-3])) {
        ID = 24;
        nama = "Faiz.AR";
        kelas = "XI-TJKT";
      }
             else if ((readCard[i] == cards25[i]) && (readCard[i-1] == cards25[i-1]) && (readCard[i-2] == cards25[i-2]) && (readCard[i-3] == cards25[i-3])) {
        ID = 25;
        nama = "Fajar.M";
        kelas = "XI-TJKT";
      }
             else if ((readCard[i] == cards26[i]) && (readCard[i-1] == cards26[i-1]) && (readCard[i-2] == cards26[i-2]) && (readCard[i-3] == cards26[i-3])) {
        ID = 26;
        nama = "Keisha.D";
        kelas = "XI-TJKT";
      }
             else if ((readCard[i] == cards27[i]) && (readCard[i-1] == cards27[i-1]) && (readCard[i-2] == cards27[i-2]) && (readCard[i-3] == cards27[i-3])) {
        ID = 27;
        nama = "Malik.A.A";
        kelas = "XI-TJKT";
      }
             else if ((readCard[i] == cards28[i]) && (readCard[i-1] == cards28[i-1]) && (readCard[i-2] == cards28[i-2]) && (readCard[i-3] == cards28[i-3])) {
        ID = 28;
        nama = "Marcel";
        kelas = "XI-TJKT";
      }
             else if ((readCard[i] == cards29[i]) && (readCard[i-1] == cards29[i-1]) && (readCard[i-2] == cards29[i-2]) && (readCard[i-3] == cards29[i-3])) {
        ID = 29;
        nama = "Nazril.I";
        kelas = "XI-TJKT";
      }
              else if ((readCard[i] == cards30[i]) && (readCard[i-1] == cards30[i-1]) && (readCard[i-2] == cards30[i-2]) && (readCard[i-3] == cards30[i-3])) {
        ID = 30;
        nama = "Raja.P.C";
        kelas = "XI-TJKT";
      }
               else if ((readCard[i] == cards31[i]) && (readCard[i-1] == cards31[i-1]) && (readCard[i-2] == cards31[i-2]) && (readCard[i-3] == cards31[i-3])) {
        ID = 31;
        nama = "Sarifah.F.A.O";
        kelas = "XI-TJKT";
      }
               else if ((readCard[i] == cards32[i]) && (readCard[i-1] == cards32[i-1]) && (readCard[i-2] == cards32[i-2]) && (readCard[i-3] == cards32[i-3])) {
        ID = 32;
        nama = "Aldiansyah.P";
        kelas = "XI-DKV";
      }
      //XI-DKV
                else if ((readCard[i] == cards33[i]) && (readCard[i-1] == cards33[i-1]) && (readCard[i-2] == cards33[i-2]) && (readCard[i-3] == cards33[i-3])) {
        ID = 33;
        nama = "Anggun.O";
        kelas = "XI-DKV";
      }
                else if ((readCard[i] == cards34[i]) && (readCard[i-1] == cards34[i-1]) && (readCard[i-2] == cards34[i-2]) && (readCard[i-3] == cards34[i-3])) {
        ID = 34;
        nama = "Anisa.O";
        kelas = "XI-DKV";
      }
                else if ((readCard[i] == cards35[i]) && (readCard[i-1] == cards35[i-1]) && (readCard[i-2] == cards35[i-2]) && (readCard[i-3] == cards35[i-3])) {
        ID = 35;
        nama = "Celia.A";
        kelas = "XI-DKV";
      }         else if ((readCard[i] == cards36[i]) && (readCard[i-1] == cards36[i-1]) && (readCard[i-2] == cards36[i-2]) && (readCard[i-3] == cards36[i-3])) {
        ID = 36;
        nama = "Christian.F.A.J";
        kelas = "XI-DKV";
      }         else if ((readCard[i] == cards37[i]) && (readCard[i-1] == cards37[i-1]) && (readCard[i-2] == cards37[i-2]) && (readCard[i-3] == cards37[i-3])) {
        ID = 37;
        nama = "Eliyah.A.C";
        kelas = "XI-DKV";
      }         else if ((readCard[i] == cards38[i]) && (readCard[i-1] == cards38[i-1]) && (readCard[i-2] == cards38[i-2]) && (readCard[i-3] == cards38[i-3])) {
        ID = 38;
        nama = "Gerald.J.R";
        kelas = "XI-DKV";
      }
                else if ((readCard[i] == cards39[i]) && (readCard[i-1] == cards39[i-1]) && (readCard[i-2] == cards39[i-2]) && (readCard[i-3] == cards39[i-3])) {
        ID = 39;
        nama = "G.Gita.L";
        kelas = "XI-DKV";
      }
                else if ((readCard[i] == cards40[i]) && (readCard[i-1] == cards40[i-1]) && (readCard[i-2] == cards40[i-2]) && (readCard[i-3] == cards40[i-3])) {
        ID = 40;
        nama = "Intan.A.P";
        kelas = "XI-DKV";
      }
                else if ((readCard[i] == cards41[i]) && (readCard[i-1] == cards41[i-1]) && (readCard[i-2] == cards41[i-2]) && (readCard[i-3] == cards41[i-3])) {
        ID = 41;
        nama = "Luna.S";
        kelas = "XI-DKV";
      }
                else if ((readCard[i] == cards42[i]) && (readCard[i-1] == cards42[i-1]) && (readCard[i-2] == cards42[i-2]) && (readCard[i-3] == cards42[i-3])) {
        ID = 42;
        nama = "Miquita.K";
        kelas = "XI-DKV";
      }
                else if ((readCard[i] == cards43[i]) && (readCard[i-1] == cards43[i-1]) && (readCard[i-2] == cards43[i-2]) && (readCard[i-3] == cards43[i-3])) {
        ID = 43;
        nama = "Najwa.N";
        kelas = "XI-DKV";
      }
                else if ((readCard[i] == cards44[i]) && (readCard[i-1] == cards44[i-1]) && (readCard[i-2] == cards44[i-2]) && (readCard[i-3] == cards44[i-3])) {
        ID = 44;
        nama = "Naufal.E";
        kelas = "XI-DKV";
      }
                else if ((readCard[i] == cards45[i]) && (readCard[i-1] == cards45[i-1]) && (readCard[i-2] == cards45[i-2]) && (readCard[i-3] == cards45[i-3])) {
        ID = 45;
        nama = "Reyna.C";
        kelas = "XI-DKV";
      }
                else if ((readCard[i] == cards46[i]) && (readCard[i-1] == cards46[i-1]) && (readCard[i-2] == cards46[i-2]) && (readCard[i-3] == cards46[i-3])) {
        ID = 46;
        nama = "Rohimah.S";
        kelas = "XI-DKV";
      }
                else if ((readCard[i] == cards47[i]) && (readCard[i-1] == cards47[i-1]) && (readCard[i-2] == cards47[i-2]) && (readCard[i-3] == cards47[i-3])) {
        ID = 47;
        nama = "Ronaldo.C.W";
        kelas = "XI-DKV";
      }
                else if ((readCard[i] == cards48[i]) && (readCard[i-1] == cards48[i-1]) && (readCard[i-2] == cards48[i-2]) && (readCard[i-3] == cards48[i-3])) {
        ID = 48;
        nama = "Sakira.D.J";
        kelas = "XI-DKV";
      }
                else if ((readCard[i] == cards49[i]) && (readCard[i-1] == cards49[i-1]) && (readCard[i-2] == cards49[i-2]) && (readCard[i-3] == cards49[i-3])) {
        ID = 49;
        nama = "Sherina.C";
        kelas = "XI-DKV";
      }
                else if ((readCard[i] == cards50[i]) && (readCard[i-1] == cards50[i-1]) && (readCard[i-2] == cards50[i-2]) && (readCard[i-3] == cards50[i-3])) {
        ID = 50;
        nama = "Shinta.A.R.M.J";
        kelas = "XI-DKV";
      }
                else if ((readCard[i] == cards51[i]) && (readCard[i-1] == cards51[i-1]) && (readCard[i-2] == cards51[i-2]) && (readCard[i-3] == cards51[i-3])) {
        ID = 51;
        nama = "Wulandari";
        kelas = "XI-DKV";
      }
                else if ((readCard[i] == cards52[i]) && (readCard[i-1] == cards52[i-1]) && (readCard[i-2] == cards52[i-2]) && (readCard[i-3] == cards52[i-3])) {
        ID = 52;
        nama = "Yesi.F.D";
        kelas = "XI-DKV";
      }
                else if ((readCard[i] == cards53[i]) && (readCard[i-1] == cards53[i-1]) && (readCard[i-2] == cards53[i-2]) && (readCard[i-3] == cards53[i-3])) {
        ID = 53;
        nama = "Yohana";
        kelas = "XI-DKV";
      }
      //XII-TO
                else if ((readCard[i] == cards54[i]) && (readCard[i-1] == cards54[i-1]) && (readCard[i-2] == cards54[i-2]) && (readCard[i-3] == cards54[i-3])) {
        ID = 54;
        nama = "Hafidz Vaqihu Zzein";
        kelas = "XII-TO";
      }    
                else if ((readCard[i] == cards55[i]) && (readCard[i-1] == cards55[i-1]) && (readCard[i-2] == cards55[i-2]) && (readCard[i-3] == cards55[i-3])) {
        ID = 55;
        nama = "Ivan Cristian Damanik";
        kelas = "XII-TO";
      } 
                else if ((readCard[i] == cards56[i]) && (readCard[i-1] == cards56[i-1]) && (readCard[i-2] == cards56[i-2]) && (readCard[i-3] == cards56[i-3])) {
        ID = 56;
        nama = "Ivan Ibrahim";
        kelas = "XII-TO";
      }
                else if ((readCard[i] == cards57[i]) && (readCard[i-1] == cards57[i-1]) && (readCard[i-2] == cards57[i-2]) && (readCard[i-3] == cards57[i-3])) {
        ID = 57;
        nama = "Jaenal Aripin";
        kelas = "XII-TO";
      }
                else if ((readCard[i] == cards58[i]) && (readCard[i-1] == cards58[i-1]) && (readCard[i-2] == cards58[i-2]) && (readCard[i-3] == cards58[i-3])) {
        ID = 58;
        nama = "Muhamad Alfarizi Fisabiliah";
        kelas = "XII-TO";
      }
                else if ((readCard[i] == cards59[i]) && (readCard[i-1] == cards59[i-1]) && (readCard[i-2] == cards59[i-2]) && (readCard[i-3] == cards59[i-3])) {
        ID = 59;
        nama = "M. Fikri Nur Riduan";
        kelas = "XII-TO";
      }
                else if ((readCard[i] == cards60[i]) && (readCard[i-1] == cards60[i-1]) && (readCard[i-2] == cards60[i-2]) && (readCard[i-3] == cards60[i-3])) {
        ID = 60;
        nama = "M. Salman Al Fauzi";
        kelas = "XII-TO";
      }
                else if ((readCard[i] == cards61[i]) && (readCard[i-1] == cards61[i-1]) && (readCard[i-2] == cards61[i-2]) && (readCard[i-3] == cards61[i-3])) {
        ID = 61;
        nama = "Putra Kristian Marbun";
        kelas = "XII-TO";
      }
                else if ((readCard[i] == cards62[i]) && (readCard[i-1] == cards62[i-1]) && (readCard[i-2] == cards62[i-2]) && (readCard[i-3] == cards62[i-3])) {
        ID = 62;
        nama = "Raehan Tri Hidayat";
        kelas = "XII-TO";
      }
                else if ((readCard[i] == cards63[i]) && (readCard[i-1] == cards63[i-1]) && (readCard[i-2] == cards63[i-2]) && (readCard[i-3] == cards63[i-3])) {
        ID = 63;
        nama = "Raya Saputra";
        kelas = "XII-TO";
      }
                else if ((readCard[i] == cards64[i]) && (readCard[i-1] == cards64[i-1]) && (readCard[i-2] == cards64[i-2]) && (readCard[i-3] == cards64[i-3])) {
        ID = 64;
        nama = "Rayhan Radhitya";
        kelas = "XII-TO";
      }
                else if ((readCard[i] == cards65[i]) && (readCard[i-1] == cards65[i-1]) && (readCard[i-2] == cards65[i-2]) && (readCard[i-3] == cards65[i-3])) {
        ID = 65;
        nama = "Riyo Febrian Ependi";
        kelas = "XII-TO";
      }
                else if ((readCard[i] == cards66[i]) && (readCard[i-1] == cards66[i-1]) && (readCard[i-2] == cards66[i-2]) && (readCard[i-3] == cards66[i-3])) {
        ID = 66;
        nama = "Rizky Adi Ramadhan";
        kelas = "XII-TO";
      }
                else if ((readCard[i] == cards67[i]) && (readCard[i-1] == cards67[i-1]) && (readCard[i-2] == cards67[i-2]) && (readCard[i-3] == cards67[i-3])) {
        ID = 67;
        nama = "Teguh Lasaro";
        kelas = "XII-TO";
      }
                else if ((readCard[i] == cards68[i]) && (readCard[i-1] == cards68[i-1]) && (readCard[i-2] == cards68[i-2]) && (readCard[i-3] == cards68[i-3])) {
        ID = 68;
        nama = "Farel Prasetiawan";
        kelas = "XII-TO";
      }
                else if ((readCard[i] == cards69[i]) && (readCard[i-1] == cards69[i-1]) && (readCard[i-2] == cards69[i-2]) && (readCard[i-3] == cards69[i-3])) {
        ID = 69;
        nama = "Arya Sheva Al Aliyyu";
        kelas = "XII-TJKT";
      }
                else if ((readCard[i] == cards70[i]) && (readCard[i-1] == cards70[i-1]) && (readCard[i-2] == cards70[i-2]) && (readCard[i-3] == cards70[i-3])) {
        ID = 70;
        nama = "Catherine Imanuel Wibisono";
        kelas = "XII-TJKT";
      }
                else if ((readCard[i] == cards71[i]) && (readCard[i-1] == cards71[i-1]) && (readCard[i-2] == cards71[i-2]) && (readCard[i-3] == cards71[i-3])) {
        ID = 71;
        nama = "Claudio Romeo Lona";
        kelas = "XII-TJKT";
      }
                else if ((readCard[i] == cards72[i]) && (readCard[i-1] == cards72[i-1]) && (readCard[i-2] == cards72[i-2]) && (readCard[i-3] == cards72[i-3])) {
        ID = 72;
        nama = "Fauzan Julianus Al-Wafi";
        kelas = "XII-TJKT";
      }
                else if ((readCard[i] == cards73[i]) && (readCard[i-1] == cards73[i-1]) && (readCard[i-2] == cards73[i-2]) && (readCard[i-3] == cards73[i-3])) {
        ID = 73;
        nama = "Kris Muliawan";
        kelas = "XII-TJKT";
      }
                else if ((readCard[i] == cards74[i]) && (readCard[i-1] == cards74[i-1]) && (readCard[i-2] == cards74[i-2]) && (readCard[i-3] == cards74[i-3])) {
        ID = 74;
        nama = "Muhamad Aria Khalil.M";
        kelas = "XII-TJKT";
      }
                else if ((readCard[i] == cards75[i]) && (readCard[i-1] == cards75[i-1]) && (readCard[i-2] == cards75[i-2]) && (readCard[i-3] == cards75[i-3])) {
        ID = 75;
        nama = "Muhammad Abdul Rozaki";
        kelas = "XII-TJKT";
      }
                else if ((readCard[i] == cards76[i]) && (readCard[i-1] == cards76[i-1]) && (readCard[i-2] == cards76[i-2]) && (readCard[i-3] == cards76[i-3])) {
        ID = 76;
        nama = "Muhammad Rayhan";
        kelas = "XII-TJKT";
      }
                else if ((readCard[i] == cards77[i]) && (readCard[i-1] == cards77[i-1]) && (readCard[i-2] == cards77[i-2]) && (readCard[i-3] == cards77[i-3])) {
        ID = 77;
        nama = "Muhammad Robby Maulana";
        kelas = "XII-TJKT";
      }
                else if ((readCard[i] == cards78[i]) && (readCard[i-1] == cards78[i-1]) && (readCard[i-2] == cards78[i-2]) && (readCard[i-3] == cards78[i-3])) {
        ID = 78;
        nama = "Putraku Bangsawan A.S";
        kelas = "XII-TJKT";
      }
                else if ((readCard[i] == cards79[i]) && (readCard[i-1] == cards79[i-1]) && (readCard[i-2] == cards79[i-2]) && (readCard[i-3] == cards79[i-3])) {
        ID = 79;
        nama = "Revaldo Natanael .D";
        kelas = "XII-TJKT";
      }
                else if ((readCard[i] == cards80[i]) && (readCard[i-1] == cards80[i-1]) && (readCard[i-2] == cards80[i-2]) && (readCard[i-3] == cards80[i-3])) {
        ID = 80;
        nama = "Shella";
        kelas = "XII-TJKT";
      }
                else if ((readCard[i] == cards81[i]) && (readCard[i-1] == cards81[i-1]) && (readCard[i-2] == cards81[i-2]) && (readCard[i-3] == cards81[i-3])) {
        ID = 81;
        nama = "Agni Ayuningsih";
        kelas = "XII-DKV";
      }
                else if ((readCard[i] == cards82[i]) && (readCard[i-1] == cards82[i-1]) && (readCard[i-2] == cards82[i-2]) && (readCard[i-3] == cards82[i-3])) {
        ID = 82;
        nama = "Aldo";
        kelas = "XII-DKV";
      }
                else if ((readCard[i] == cards83[i]) && (readCard[i-1] == cards83[i-1]) && (readCard[i-2] == cards83[i-2]) && (readCard[i-3] == cards83[i-3])) {
        ID = 83;
        nama = "Andayani Sulistia Sella.M.P";
        kelas = "XII-DKV";
      }
                else if ((readCard[i] == cards84[i]) && (readCard[i-1] == cards84[i-1]) && (readCard[i-2] == cards84[i-2]) && (readCard[i-3] == cards84[i-3])) {
        ID = 84;
        nama = "Anggi satia";
        kelas = "XII-DKV";
      }
                else if ((readCard[i] == cards85[i]) && (readCard[i-1] == cards85[i-1]) && (readCard[i-2] == cards85[i-2]) && (readCard[i-3] == cards85[i-3])) {
        ID = 85;
        nama = "Arnestian";
        kelas = "XII-DKV";
      }
                else if ((readCard[i] == cards86[i]) && (readCard[i-1] == cards86[i-1]) && (readCard[i-2] == cards86[i-2]) && (readCard[i-3] == cards86[i-3])) {
        ID = 86;
        nama = "Bagas Irfan Zuhdi";
        kelas = "XII-DKV";
      }
                else if ((readCard[i] == cards87[i]) && (readCard[i-1] == cards87[i-1]) && (readCard[i-2] == cards87[i-2]) && (readCard[i-3] == cards87[i-3])) {
        ID = 87;
        nama = "Derren Roosevelt Wijaya";
        kelas = "XII-DKV";
      }
                else if ((readCard[i] == cards88[i]) && (readCard[i-1] == cards88[i-1]) && (readCard[i-2] == cards88[i-2]) && (readCard[i-3] == cards88[i-3])) {
        ID = 88;
        nama = "Diandra Rossa";
        kelas = "XII-DKV";
      }
                else if ((readCard[i] == cards89[i]) && (readCard[i-1] == cards89[i-1]) && (readCard[i-2] == cards89[i-2]) && (readCard[i-3] == cards89[i-3])) {
        ID = 89;
        nama = "Febrianto";
        kelas = "XII-DKV";
      }
                else if ((readCard[i] == cards90[i]) && (readCard[i-1] == cards90[i-1]) && (readCard[i-2] == cards90[i-2]) && (readCard[i-3] == cards90[i-3])) {
        ID = 90;
        nama = "Garda Muhamad Alif";
        kelas = "XII-DKV";
      }
                else if ((readCard[i] == cards91[i]) && (readCard[i-1] == cards91[i-1]) && (readCard[i-2] == cards91[i-2]) && (readCard[i-3] == cards91[i-3])) {
        ID = 91;
        nama = "Hana Mutia";
        kelas = "XII-DKV";
      }
                else if ((readCard[i] == cards92[i]) && (readCard[i-1] == cards92[i-1]) && (readCard[i-2] == cards92[i-2]) && (readCard[i-3] == cards92[i-3])) {
        ID = 92;
        nama = "Jehezkiel Christopher";
        kelas = "XII-DKV";
      }
                else if ((readCard[i] == cards93[i]) && (readCard[i-1] == cards93[i-1]) && (readCard[i-2] == cards93[i-2]) && (readCard[i-3] == cards93[i-3])) {
        ID = 93;
        nama = "Kezia Forisa Andi";
        kelas = "XII-DKV";
      }
                else if ((readCard[i] == cards94[i]) && (readCard[i-1] == cards94[i-1]) && (readCard[i-2] == cards94[i-2]) && (readCard[i-3] == cards94[i-3])) {
        ID = 94;
        nama = "M. Rully Rabbani";
        kelas = "XII-DKV";
      }
                else if ((readCard[i] == cards95[i]) && (readCard[i-1] == cards95[i-1]) && (readCard[i-2] == cards95[i-2]) && (readCard[i-3] == cards95[i-3])) {
        ID = 95;
        nama = "Marceline Christianto Pranadjaya";
        kelas = "XII-DKV";
      }
                else if ((readCard[i] == cards96[i]) && (readCard[i-1] == cards96[i-1]) && (readCard[i-2] == cards96[i-2]) && (readCard[i-3] == cards96[i-3])) {
        ID = 96;
        nama = "Ray Hartanto";
        kelas = "XII-DKV";
      }
                else if ((readCard[i] == cards97[i]) && (readCard[i-1] == cards97[i-1]) && (readCard[i-2] == cards97[i-2]) && (readCard[i-3] == cards97[i-3])) {
        ID = 97;
        nama = "Renno Christian Trisno";
        kelas = "XII-DKV";
      }
                else if ((readCard[i] == cards98[i]) && (readCard[i-1] == cards98[i-1]) && (readCard[i-2] == cards98[i-2]) && (readCard[i-3] == cards98[i-3])) {
        ID = 98;
        nama = "Sabela Wijaya";
        kelas = "XII-DKV";
      }
                else if ((readCard[i] == cards99[i]) && (readCard[i-1] == cards99[i-1]) && (readCard[i-2] == cards99[i-2]) && (readCard[i-3] == cards99[i-3])) {
        ID = 99;
        nama = "Salpa Nurzakiah";
        kelas = "XII-DKV";
      }
                else if ((readCard[i] == cards100[i]) && (readCard[i-1] == cards100[i-1]) && (readCard[i-2] == cards100[i-2]) && (readCard[i-3] == cards100[i-3])) {
        ID = 100;
        nama = "Silva Azzahra";
        kelas = "XII-DKV";
      }
                else if ((readCard[i] == cards102[i]) && (readCard[i-1] == cards102[i-1]) && (readCard[i-2] == cards102[i-2]) && (readCard[i-3] == cards102[i-3])) {
        ID = 102;
        nama = "Stefanny Dwi Sandra";
        kelas = "XII-DKV";
      }
                else if ((readCard[i] == cards103[i]) && (readCard[i-1] == cards103[i-1]) && (readCard[i-2] == cards103[i-2]) && (readCard[i-3] == cards103[i-3])) {
        ID = 103;
        nama = "Theresia Cantika Wijaya";
        kelas = "XII-DKV";
      }
                else if ((readCard[i] == cards104[i]) && (readCard[i-1] == cards104[i-1]) && (readCard[i-2] == cards104[i-2]) && (readCard[i-3] == cards104[i-3])) {
        ID = 104;
        nama = "Timotius Feivel Christian Lie";
        kelas = "XII-DKV";
      }
                else if ((readCard[i] == cards105[i]) && (readCard[i-1] == cards105[i-1]) && (readCard[i-2] == cards105[i-2]) && (readCard[i-3] == cards105[i-3])) {
        ID = 105;
        nama = "Zefanya Ristabelle Prabowo";
        kelas = "XII-DKV";
      }
      //X-TO
                else if ((readCard[i] == cards106[i]) && (readCard[i-1] == cards106[i-1]) && (readCard[i-2] == cards106[i-2]) && (readCard[i-3] == cards106[i-3])) {
        ID = 106;
        nama = "Adriyan";
        kelas = "X-TO";
      }
                else if ((readCard[i] == cards107[i]) && (readCard[i-1] == cards107[i-1]) && (readCard[i-2] == cards107[i-2]) && (readCard[i-3] == cards107[i-3])) {
        ID = 107;
        nama = "Daniel Rildo Mondoringin";
        kelas = "X-TO";
      }
                else if ((readCard[i] == cards108[i]) && (readCard[i-1] == cards108[i-1]) && (readCard[i-2] == cards108[i-2]) && (readCard[i-3] == cards108[i-3])) {
        ID = 108;
        nama = "Eric Susanto";
        kelas = "X-TO";
      }
                else if ((readCard[i] == cards109[i]) && (readCard[i-1] == cards109[i-1]) && (readCard[i-2] == cards109[i-2]) && (readCard[i-3] == cards109[i-3])) {
        ID = 109;
        nama = "Fabian Pratama Putra";
        kelas = "X-TO";
      }
                else if ((readCard[i] == cards110[i]) && (readCard[i-1] == cards110[i-1]) && (readCard[i-2] == cards110[i-2]) && (readCard[i-3] == cards110[i-3])) {
        ID = 110;
        nama = "Ferdy Wijaya";
        kelas = "X-TO";
      }
                else if ((readCard[i] == cards111[i]) && (readCard[i-1] == cards111[i-1]) && (readCard[i-2] == cards111[i-2]) && (readCard[i-3] == cards111[i-3])) {
        ID = 111;
        nama = "Grenno Widi Adinugroho";
        kelas = "X-TO";
      }
                else if ((readCard[i] == cards112[i]) && (readCard[i-1] == cards112[i-1]) && (readCard[i-2] == cards112[i-2]) && (readCard[i-3] == cards112[i-3])) {
        ID = 112;
        nama = "M. Ibnu Prasetya";
        kelas = "X-TO";
      }
                else if ((readCard[i] == cards113[i]) && (readCard[i-1] == cards113[i-1]) && (readCard[i-2] == cards113[i-2]) && (readCard[i-3] == cards113[i-3])) {
        ID = 113;
        nama = "Muhamad Renaldi";
        kelas = "X-TO";
      }
                else if ((readCard[i] == cards114[i]) && (readCard[i-1] == cards114[i-1]) && (readCard[i-2] == cards114[i-2]) && (readCard[i-3] == cards114[i-3])) {
        ID = 114;
        nama = "Resky Ananda Aulia";
        kelas = "X-TO";
      }
                else if ((readCard[i] == cards115[i]) && (readCard[i-1] == cards115[i-1]) && (readCard[i-2] == cards115[i-2]) && (readCard[i-3] == cards115[i-3])) {
        ID = 115;
        nama = "Tomas";
        kelas = "X-TO";
      }
                else if ((readCard[i] == cards116[i]) && (readCard[i-1] == cards116[i-1]) && (readCard[i-2] == cards116[i-2]) && (readCard[i-3] == cards116[i-3])) {
        ID = 116;
        nama = "Yosep Hadianja";
        kelas = "X-TO";
      }
      //X-TJKT
                else if ((readCard[i] == cards117[i]) && (readCard[i-1] == cards117[i-1]) && (readCard[i-2] == cards117[i-2]) && (readCard[i-3] == cards117[i-3])) {
        ID = 117;
        nama = "Adam Muhamad Rizki";
        kelas = "X-TJKT";
      }
                else if ((readCard[i] == cards118[i]) && (readCard[i-1] == cards118[i-1]) && (readCard[i-2] == cards118[i-2]) && (readCard[i-3] == cards118[i-3])) {
        ID = 118;
        nama = "Cindy Claudia Putri";
        kelas = "X-TJKT";
      }
                else if ((readCard[i] == cards119[i]) && (readCard[i-1] == cards119[i-1]) && (readCard[i-2] == cards119[i-2]) && (readCard[i-3] == cards119[i-3])) {
        ID = 119;
        nama = "Gisella Abigail";
        kelas = "X-TJKT";
      }
                else if ((readCard[i] == cards120[i]) && (readCard[i-1] == cards120[i-1]) && (readCard[i-2] == cards120[i-2]) && (readCard[i-3] == cards120[i-3])) {
        ID = 120;
        nama = "Intan Nur Afifah";
        kelas = "X-TJKT";
      }
                else if ((readCard[i] == cards121[i]) && (readCard[i-1] == cards121[i-1]) && (readCard[i-2] == cards121[i-2]) && (readCard[i-3] == cards121[i-3])) {
        ID = 121;
        nama = "Jodie Irpan Sugiarto";
        kelas = "X-TJKT";
      }
                else if ((readCard[i] == cards122[i]) && (readCard[i-1] == cards122[i-1]) && (readCard[i-2] == cards122[i-2]) && (readCard[i-3] == cards122[i-3])) {
        ID = 122;
        nama = "Keyla Agustini Kurniawan";
        kelas = "X-TJKT";
      }
                else if ((readCard[i] == cards123[i]) && (readCard[i-1] == cards123[i-1]) && (readCard[i-2] == cards123[i-2]) && (readCard[i-3] == cards123[i-3])) {
        ID = 123;
        nama = "Marchel Chandra Limbu";
        kelas = "X-TJKT";
      }
                else if ((readCard[i] == cards124[i]) && (readCard[i-1] == cards124[i-1]) && (readCard[i-2] == cards124[i-2]) && (readCard[i-3] == cards124[i-3])) {
        ID = 124;
        nama = "Moreno Joseph Christian.T";
        kelas = "X-TJKT";
      }
                else if ((readCard[i] == cards125[i]) && (readCard[i-1] == cards125[i-1]) && (readCard[i-2] == cards125[i-2]) && (readCard[i-3] == cards125[i-3])) {
        ID = 125;
        nama = "Muhamad Arda Al Izma";
        kelas = "X-TJKT";
      }
                else if ((readCard[i] == cards126[i]) && (readCard[i-1] == cards126[i-1]) && (readCard[i-2] == cards126[i-2]) && (readCard[i-3] == cards126[i-3])) {
        ID = 126;
        nama = "Muhamad Raffail Damis";
        kelas = "X-TJKT";
      }
                else if ((readCard[i] == cards127[i]) && (readCard[i-1] == cards127[i-1]) && (readCard[i-2] == cards127[i-2]) && (readCard[i-3] == cards127[i-3])) {
        ID = 127;
        nama = "Nandiwa Syafi Arruziq";
        kelas = "X-TJKT";
      }
                else if ((readCard[i] == cards128[i]) && (readCard[i-1] == cards128[i-1]) && (readCard[i-2] == cards128[i-2]) && (readCard[i-3] == cards128[i-3])) {
        ID = 128;
        nama = "Paulina Michelle Weruin";
        kelas = "X-TJKT";
      }
                else if ((readCard[i] == cards129[i]) && (readCard[i-1] == cards129[i-1]) && (readCard[i-2] == cards129[i-2]) && (readCard[i-3] == cards129[i-3])) {
        ID = 129;
        nama = "Putri Anastasya";
        kelas = "X-TJKT";
      }
                else if ((readCard[i] == cards130[i]) && (readCard[i-1] == cards130[i-1]) && (readCard[i-2] == cards130[i-2]) && (readCard[i-3] == cards130[i-3])) {
        ID = 130;
        nama = "Rifa Putra Aditiya";
        kelas = "X-TJKT";
      }
                else if ((readCard[i] == cards131[i]) && (readCard[i-1] == cards131[i-1]) && (readCard[i-2] == cards131[i-2]) && (readCard[i-3] == cards131[i-3])) {
        ID = 131;
        nama = "Syifa Annisa Ramadhani";
        kelas = "X-TJKT";
      }
                else if ((readCard[i] == cards132[i]) && (readCard[i-1] == cards132[i-1]) && (readCard[i-2] == cards132[i-2]) && (readCard[i-3] == cards132[i-3])) {
        ID = 132;
        nama = "Taufik Mauladi";
        kelas = "X-TJKT";
      }
                else if ((readCard[i] == cards133[i]) && (readCard[i-1] == cards133[i-1]) && (readCard[i-2] == cards133[i-2]) && (readCard[i-3] == cards133[i-3])) {
        ID = 133;
        nama = "Valen Surya Mahendra";
        kelas = "X-TJKT";
      }
                else if ((readCard[i] == cards134[i]) && (readCard[i-1] == cards134[i-1]) && (readCard[i-2] == cards134[i-2]) && (readCard[i-3] == cards134[i-3])) {
        ID = 134;
        nama = "Vio Venerando Vinansius";
        kelas = "X-TJKT";
      }
                else if ((readCard[i] == cards135[i]) && (readCard[i-1] == cards135[i-1]) && (readCard[i-2] == cards135[i-2]) && (readCard[i-3] == cards135[i-3])) {
        ID = 135;
        nama = "Yanuar Eki Andaru";
        kelas = "X-TJKT";
      }
      //X-DKV
                else if ((readCard[i] == cards136[i]) && (readCard[i-1] == cards136[i-1]) && (readCard[i-2] == cards136[i-2]) && (readCard[i-3] == cards136[i-3])) {
        ID = 136;
        nama = "Adnan Saputra";
        kelas = "X-DKV";
      }
                else if ((readCard[i] == cards137[i]) && (readCard[i-1] == cards137[i-1]) && (readCard[i-2] == cards137[i-2]) && (readCard[i-3] == cards137[i-3])) {
        ID = 137;
        nama = "Agnes Priscilla";
        kelas = "X-DKV";
      }
                else if ((readCard[i] == cards137[i]) && (readCard[i-1] == cards137[i-1]) && (readCard[i-2] == cards137[i-2]) && (readCard[i-3] == cards137[i-3])) {
        ID = 137;
        nama = "Aura Amelia";
        kelas = "X-DKV";
      }
                else if ((readCard[i] == cards138[i]) && (readCard[i-1] == cards138[i-1]) && (readCard[i-2] == cards138[i-2]) && (readCard[i-3] == cards138[i-3])) {
        ID = 138;
        nama = "Cindy Laura Meyllano";
        kelas = "X-DKV";
      }
                else if ((readCard[i] == cards139[i]) && (readCard[i-1] == cards139[i-1]) && (readCard[i-2] == cards139[i-2]) && (readCard[i-3] == cards139[i-3])) {
        ID = 139;
        nama = "Debi Sintia";
        kelas = "X-DKV";
      }
                else if ((readCard[i] == cards140[i]) && (readCard[i-1] == cards140[i-1]) && (readCard[i-2] == cards140[i-2]) && (readCard[i-3] == cards140[i-3])) {
        ID = 140;
        nama = "Dewi Nur Ramadani";
        kelas = "X-DKV";
      }
                else if ((readCard[i] == cards141[i]) && (readCard[i-1] == cards141[i-1]) && (readCard[i-2] == cards141[i-2]) && (readCard[i-3] == cards141[i-3])) {
        ID = 141;
        nama = "Dita Keristiana";
        kelas = "X-DKV";
      }
                else if ((readCard[i] == cards142[i]) && (readCard[i-1] == cards142[i-1]) && (readCard[i-2] == cards142[i-2]) && (readCard[i-3] == cards142[i-3])) {
        ID = 142;
        nama = "Falih Muhammad Rizqullah";
        kelas = "X-DKV";
      }
                else if ((readCard[i] == cards143[i]) && (readCard[i-1] == cards143[i-1]) && (readCard[i-2] == cards143[i-2]) && (readCard[i-3] == cards143[i-3])) {
        ID = 143;
        nama = "Flynn Mathew Tandra";
        kelas = "X-DKV";
      }
                else if ((readCard[i] == cards144[i]) && (readCard[i-1] == cards144[i-1]) && (readCard[i-2] == cards144[i-2]) && (readCard[i-3] == cards144[i-3])) {
        ID = 144;
        nama = "Irel Ramadani";
        kelas = "X-DKV";
      }
                else if ((readCard[i] == cards145[i]) && (readCard[i-1] == cards145[i-1]) && (readCard[i-2] == cards145[i-2]) && (readCard[i-3] == cards145[i-3])) {
        ID = 145;
        nama = "Juditha Thesalonika Taringan";
        kelas = "X-DKV";
      }
                else if ((readCard[i] == cards146[i]) && (readCard[i-1] == cards146[i-1]) && (readCard[i-2] == cards146[i-2]) && (readCard[i-3] == cards146[i-3])) {
        ID = 146;
        nama = "Josephine Aurelie";
        kelas = "X-DKV";
      }
                else if ((readCard[i] == cards147[i]) && (readCard[i-1] == cards147[i-1]) && (readCard[i-2] == cards147[i-2]) && (readCard[i-3] == cards147[i-3])) {
        ID = 147;
        nama = "Keyra Azalia Putri";
        kelas = "X-DKV";
      }
                else if ((readCard[i] == cards148[i]) && (readCard[i-1] == cards136[i-1]) && (readCard[i-2] == cards136[i-2]) && (readCard[i-3] == cards136[i-3])) {
        ID = 148;
        nama = "Keysha Dwi Sentosa";
        kelas = "X-DKV";
      }
                else if ((readCard[i] == cards149[i]) && (readCard[i-1] == cards149[i-1]) && (readCard[i-2] == cards149[i-2]) && (readCard[i-3] == cards149[i-3])) {
        ID = 149;
        nama = "Khaiqal Febrian N";
        kelas = "X-DKV";
      }
                else if ((readCard[i] == cards150[i]) && (readCard[i-1] == cards150[i-1]) && (readCard[i-2] == cards150[i-2]) && (readCard[i-3] == cards150[i-3])) {
        ID = 150;
        nama = "Livina Andryyani";
        kelas = "X-DKV";
      }
                else if ((readCard[i] == cards151[i]) && (readCard[i-1] == cards151[i-1]) && (readCard[i-2] == cards151[i-2]) && (readCard[i-3] == cards151[i-3])) {
        ID = 151;
        nama = "Lucas Ehi Yang";
        kelas = "X-DKV";
      }
                else if ((readCard[i] == cards152[i]) && (readCard[i-1] == cards152[i-1]) && (readCard[i-2] == cards152[i-2]) && (readCard[i-3] == cards152[i-3])) {
        ID = 152;
        nama = "Maulida Dwi Aprilia";
        kelas = "X-DKV";
      }
                else if ((readCard[i] == cards153[i]) && (readCard[i-1] == cards153[i-1]) && (readCard[i-2] == cards153[i-2]) && (readCard[i-3] == cards153[i-3])) {
        ID = 153;
        nama = "Mella Aulia";
        kelas = "X-DKV";
      }                
                else if ((readCard[i] == cards154[i]) && (readCard[i-1] == cards154[i-1]) && (readCard[i-2] == cards154[i-2]) && (readCard[i-3] == cards154[i-3])) {
        ID = 154;
        nama = "Muhammad Reihan Sulaiman";
        kelas = "X-DKV";
      }
                else if ((readCard[i] == cards155[i]) && (readCard[i-1] == cards155[i-1]) && (readCard[i-2] == cards155[i-2]) && (readCard[i-3] == cards155[i-3])) {
        ID = 155;
        nama = "Mutiara Nur Afriani";
        kelas = "X-DKV";
      }
                else if ((readCard[i] == cards156[i]) && (readCard[i-1] == cards156[i-1]) && (readCard[i-2] == cards156[i-2]) && (readCard[i-3] == cards156[i-3])) {
        ID = 156;
        nama = "Nipsi Agustina";
        kelas = "X-DKV";
      }
                else if ((readCard[i] == cards157[i]) && (readCard[i-1] == cards157[i-1]) && (readCard[i-2] == cards157[i-2]) && (readCard[i-3] == cards157[i-3])) {
        ID = 157;
        nama = "Silpi Rianti";
        kelas = "X-DKV";
      }
                else if ((readCard[i] == cards158[i]) && (readCard[i-1] == cards158[i-1]) && (readCard[i-2] == cards158[i-2]) && (readCard[i-3] == cards158[i-3])) {
        ID = 158;
        nama = "Vaffian Adi Putra";
        kelas = "X-DKV";
      }
                else if ((readCard[i] == cards159[i]) && (readCard[i-1] == cards159[i-1]) && (readCard[i-2] == cards159[i-2]) && (readCard[i-3] == cards159[i-3])) {
        ID = 159;
        nama = "Valencia Carren Aletha";
        kelas = "X-DKV";
      }
                else if ((readCard[i] == cards160[i]) && (readCard[i-1] == cards160[i-1]) && (readCard[i-2] == cards160[i-2]) && (readCard[i-3] == cards160[i-3])) {
        ID = 160;
        nama = "Villy Veneranda Vinansius";
        kelas = "X-DKV";
      }
                else if ((readCard[i] == cards161[i]) && (readCard[i-1] == cards161[i-1]) && (readCard[i-2] == cards161[i-2]) && (readCard[i-3] == cards161[i-3])) {
        ID = 161;
        nama = "Vyno Cristian";
        kelas = "X-DKV";
      }
                else if ((readCard[i] == cards162[i]) && (readCard[i-1] == cards162[i-1]) && (readCard[i-2] == cards162[i-2]) && (readCard[i-3] == cards162[i-3])) {
        ID = 162;
        nama = "Yosefine Chiquita Reyna";
        kelas = "X-DKV";
      }
                else if ((readCard[i] == cards163[i]) && (readCard[i-1] == cards163[i-1]) && (readCard[i-2] == cards163[i-2]) && (readCard[i-3] == cards163[i-3])) {
        ID = 163;
        nama = "Zahra Sifa Safana";
        kelas = "X-DKV";
      }
                else if ((readCard[i] == cards164[i]) && (readCard[i-1] == cards164[i-1]) && (readCard[i-2] == cards164[i-2]) && (readCard[i-3] == cards164[i-3])) {
        ID = 164;
        nama = "Caroline";
        kelas = "X-DKV";
      }
      else {
        status_kartu = false;
      }
    }
  }
  else {
    sudah_absen = true;
    Serial.println("sudah absen");
    lcd.setCursor(2, 1);
    lcd.print("Sudah Absen");
  }

  if (status_kartu == true && sudah_absen == false) {
    if (mode_pulang == false) {
      Serial.print("DATA,");
      Serial.print(ID);
      Serial.print(",");
      printtanggal();
      Serial.print(",");
      Serial.print(nama);
      Serial.print(",");
      printHex(mfrc522.uid.uidByte, mfrc522.uid.size);
      Serial.print(",");
      Serial.print(kelas);
      Serial.print(",");
      printwaktu();
      Serial.print(",");
      Serial.println("");
      lcd.setCursor(2, 1);
      lcd.print("Terima Kasih");
    }

    if (mode_pulang == true) {
      Serial.print("DATA,");
      Serial.print(ID);
      Serial.print(",");
      printtanggal();
      Serial.print(",");
      Serial.print(nama);
      Serial.print(",");
      printHex(mfrc522.uid.uidByte, mfrc522.uid.size);
      Serial.print(",");
      Serial.print(kelas);
      Serial.print(",");
      Serial.print("");
      Serial.print(",");
      printwaktu();
      Serial.print(",");
      Serial.println("");
      lcd.setCursor(2, 1);
      lcd.print("Terima Kasih");
    }
  }
      
  digitalWrite(buzzer, HIGH);
  delay(200);
  digitalWrite(buzzer, LOW);
  delay(2000);
  lcd.clear();
  delay(50);
  mfrc522.PICC_HaltA();
  mfrc522.PCD_StopCrypto1();
  inputData();
}


void printtanggal() {
  DateTime now = rtc.now();
  Serial.print(daysOfTheWeek[now.dayOfTheWeek()]);
  Serial.print('/');
  Serial.print(now.day());
  Serial.print('/');
  Serial.print(now.month());
  Serial.print('/');
  Serial.print(now.year());
}

void printwaktu() {
  DateTime now = rtc.now();
  printposisi(now.hour());
  Serial.print(':');
  printposisi(now.minute());
  Serial.print(':');
  printposisi(now.second());
}

void printHex(byte * buffer, byte bufferSize) {
  for (byte i = 0; i < bufferSize; i++) {
    Serial.print(buffer[i] < 0x10 ? " 0" : " ");
    Serial.print(buffer[i], HEX);
  }
}

void printposisi(int digits) {
  if (digits < 10)
    Serial.print("0");
  Serial.print(digits);
}

void printposisilcd(int digits) {
  if (digits < 10)
    lcd.print("0");
  lcd.print(digits);
}

void inputData(){
  DateTime now = rtc.now();
  String hari = getDayOfWeek(now.dayOfTheWeek());
  String jam = String(now.hour()) + ":" + String(now.minute()) + ":" + String(now.second());
  String tanggal = String(now.day()) + "/" + String(now.month()) + "/" + String(now.year());
  // Read RFID tag ID
 // String id = readRFIDTagID(); // Implement this function to read the RFID tag ID
  digitalWrite(relay,on);
  digitalWrite(cs,on);
  SD.begin(cs);
  file=SD.open("test.txt", FILE_WRITE);
  if(file){
    file.print(nama);
    file.print(",");
    file.print(id);
    file.print(",");
    file.print(kelas);
    file.print(",");
    file.print(hari);
    file.print(",");
    file.print(jam);
    file.print(",");
    file.print(tanggal);
    file.print(",");
    file.println(waktu);
    Serial.println(id);
    Serial.println("Data berhasil ditambahkan!!");
    file.close();
  }else{
    Serial.println("Data error, gagal menyimpan!!");
  }
  digitalWrite(relay,off);
  digitalWrite(cs,off);
}
String getDayOfWeek(int dayOfWeek) {
  switch (dayOfWeek) {
    case 1:
      return "Minggu";
    case 2:
      return "Senin";
    case 3:
      return "Selasa";
    case 4:
      return "Rabu";
    case 5:
      return "Kamis";
    case 6:
      return "Jumat";
    case 7:
      return "Sabtu";
    default:
      return "";
  }
}