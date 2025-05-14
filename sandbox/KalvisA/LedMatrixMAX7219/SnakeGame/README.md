# Mēģinājums zīmēt kustīgu čūsku

LED matricu pieslēdz pie Arduino kā parasti (sk. maketēšanas shēmu). 
Vajadzētu būt tā, ka ik pēc dažām sekundēm uzzīmējas čūska, kura sastāv no 5 iedegtām 
LED spuldzītēm. Pēc tam tā palien uz priekšu par vienu vienību un zīmējas atkal. 

![](SnakeGame_bb.png)

Šobrīd čūskas spēle ir ļoti primitīva - čūsku nevar kontrolēt, tās galva nejauši izvēlas 
nākamo blakus rūtiņu (ar vienādām varbūtībām uz augšu, uz leju, pa labi vai pa kreisi)
un pārvietojas uz turieni. Čūskas "astei" toties pēdējā LED lampiņa nodziest, lai čūskas
garums nemainītos. 

## Arduino kontroliera pārstartēšana

Čūska nevar iziet ārpus 8x8 matricas un arī nevar pati sevi krustot. Ja čūskai 
iegadās komanda uz turieni doties, viņa šo gājienu izlaiž.
Pēc kāda laika čūskas galva neizbēgami nonāk kādā no stūriem un vairs nevar izkļūt
no stūra, jo abas kaimiņu rūtiņas stūrim aizņem pašas čūskas ķermenis. 
Ja čūska iestrēgst kādā stūrī, to var palaist atkal, nospiežot **Reset** podziņu 
uz Arduino kontroliera -- tas uzsāk skriptu atkal no jauna.


## Animāciju programmēšana

Regulārus laika intervālus animācijās var panākt, izmantojot pašreizējā laika iegūšanas 
funkciju `millis()` (nevis `delay(...)`), jo mērķis NAV noteiktu laiku neko nedarīt - 
kas var novest pie nevienmērīgas kustības, ja Arduino ir noslogots. , 
Animācijas mērķis ir nodrošināt to, lai pēc atļautā laika (piemēram, ik pēc 200 milisekundēm) 
čūska nejauši pārvietotos. Gaidīšanu nodrošina sekojošs koda gabals cikla sākumā: 

```
void loop() {
    unsigned long now = millis();
    if (now - lastMoveTime < interval)
        return;
    lastMoveTime = now;
    // pārējā daļa galvenajam ciklam "loop()"
}
```


## Uzdevumi 

1. Pievienot spēlei kursorsviru (*joystick*) - ja **VRX** vai **VRY** nolasa pietiekami 
   lielu vai pietiekami mazu skaitli (piemēram, no intervāliem $[768; 1023]$ vai 
   $[0;256]$), tad čūska izvēlas kustības virzienu kursorsviras norādītajā virzienā. 
   Šajā gadījumā nav vajadzīgs nejauši izvēlētais kustības virziens, jo to norāda lietotājs.
2. Laiku pa laikam iedegt uz matricas mirkšķinošu punktu -- spēlētāja uzdevums 
   ir aiziet līdz šim punktam ar čūskas galvu un ar kursorsviras pogas klikšķi 
   "apēst" šo punktu. Apēšanas faktu un sakrātos punktus var 
   drukāt uz seriālā monitora. 
3. Pievienot spēlei 4 LED ciparu displeju, kas skaita apēstos punktus.



