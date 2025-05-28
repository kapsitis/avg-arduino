# Čārlija multipleksēšana

Nereti vajag maksimāli daudzas LED lampiņas kontrolēt ar nelielu 
daudzumu pievienoto vadu. Viens no šādiem trikiem ir
parasta multipleksēšana, kas izmanto cilvēka acij neuztveramu 
mirgošanu un rada vienlaicīguma 
iespaidu ātri pārslēdzoties starp dažādiem LED lampiņu blokiem.
Bet šāda multipleksēšana ir piemērota tad, ja vajag 
neatkarīgi vienu no otra darbināt vairākus lampiņu blokus. 

Cita situācija rodas tad, ja vajag LED ieslēgt/izslēgt 
stingri pa vienai. Šādā situācijā teorētiskais 
maksimums ar lampiņām, ko var kontrolēt ar $n$ vadiem 
ir $n(n-1)$ (cik dažādos veidos var izvēlēties vienu 
no $n$ vadiem, ko pieslēgt dotās LED katodam, un otru 
no atlikušajiem $n-1$ vadiem, ko pieslēgt dotās 
LED anodam). 

Ja $n=3$, tad var vienlaikus kontrolēt $n(n-1) = 3 \cdot 2 = 6$ 
LED lampiņas. Sal. shēmu. 
Ievērojiet, ka shēma nav pieslēgta **GND** vai **5V** kontaktiem. 
 







## ESP32 instrukcijas

Uz Arduino IDE atvērt **File** > **Preferences** (uz Mac OS X: **Settings** > **Preferences**). 
Sadaļā ``Additional boards manager URLs``, ierakstīt šo vērtību:
```
https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json
```

Tad atvērt **Tools** > **Board** > **Boards Manager**, ierakstīt meklēšanas lodziņā 
"ESP32", un instalēt "ESP32 by Espressif Systems" (nevajag izvēlēties
otru -- "Arduino ESP32 Boards by Arduino"). 
Pagaidīt, kamēr viss ieinstalējas.

* Pievienot ESP32 plati ar USB (parasti datoram piespraužams 
  kabeļa gals, kas ir USB-A, bet ESP32 moduļa pusē tas 
  ir USB-Micro). 
* No **Tools** > **Board**, izvēlēties "ESP32 Dev Module".
* No **Tools** > **Port** izvēlēties COM seriālo portu 
  (tas var būt COM3, COM4, COM5 - atkarībā no Jūsu datora). 
* Nospiest **Upload** pogu vai no izvēlnes **Sketch** > **Upload**.

