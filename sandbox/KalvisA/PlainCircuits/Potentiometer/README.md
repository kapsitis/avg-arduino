# LED ķēde ar potenciometru

Šajā vingrinājumā pieslēdzam potenciometru, lai varētu mainīt 
spriegumu, kuru saņem LED diodes un $220~\Omega$ rezistora ķēde.

**Viena LED lampiņa ar potenciometru: Maketēšanas shēma:**

![](Potentiometer_bb.png)

**Viena LED lampiņa ar potenciometru: Elektriskā shēma:** 

![](Potentiometer_schem.png)


## Potenciometrs

Potenciometrs ir ierīce, ko lieto diviem mērķiem:

* Kā mainīgas pretestības rezistoru (ja tam pieslēdz tikai 2 kontaktus).
  Mūsu komplektā esošais potenciometrs māk mainīt pretestību no 
  $0~\Omega$ līdz $10000~\Omega$ (10,000 omi jeb $10$ kiloomi).  
* Kā ierīci sprieguma mainīšanai (ja tam pieslēdz visus 3 kontaktus). 
  Šajā gadījumā spriegums starp **GND** un **5V** kontaktiem 
  vienmēr ir $5~\text{V}$, bet spriegums uz trešā kontakta **OTA** vai **OTB**
  (sprieguma starpība starp **OTA** un **GND**) 
  var būt jebkāda no $0~\text{V}$ līdz $5~\text{V}$ (starp 0 un 5 voltiem).

Šajā vingrinājumā var saslēgt LED un rezistoru virknē un 
mainīt uz tiem spriegumu. Tā kā ķēde bija aprēķināta 5V (maksimālajam spriegumam), 
tad drīkst padot arī mazāku spriegumu, neriskējot nodedzināt LED diodi. 

## Uzdevumi

1. Pārbaudīt sprieguma izmaiņas starp **GND** un **OTA** ar multimetru 
   (ieslēgt to 20 voltu diapazonā). 
2. Pārbaudīt, pie kāda sprieguma iedegas dažādu krāsu LED. 
   Katras krāsas LED ieslēgt sākotnējā ķēdē. Vispirms ar potenciometru (pārbīdot 
   regulatoru uz maksimumu)
   pārbauda, vai diode ieslēgta pareizi. Pēc tam spriegumu lēnām kāpina no nulles 
   līdz maksimumam un atrod to mirkli, kurā diode sāk dot nelielu, blāvu gaismu. 
   Šo sprieguma vērtību pieraksta.
   Pēc teorijas vajadzētu būt tā, ka sarkanā diode iedegas pie viszemākā sprieguma 
   (ap $1.7~\text{V}$), bet zilā un arī baltā (caurspīdīgā) diodes iedegas pie 
   augstāka sprieguma (ap $2.5~\text{V}$). Palielinot spriegumu, lampiņas iedegas 
   varavīksnes krāsu secībā: Vispirms sarkanā, tad oranžā, tad dzeltenā, 
   tad zaļā un visbeidzot zilā. 
3. Tam pašam spriegumam paralēli pieslēdz divas LED lampiņas dažādās krāsās. 
   Noskaidro, kurām no tām viena lampiņa (pat pie maksimāla sprieguma uz potenciometra)
   pilnībā nomāc otru un deg viena pati, bet kuras lampiņas var degt vienlaicīgi. 
   Divu lampiņu paralēls slēgums parādīts attēlos.

**Divas LED lampiņas paralēli pie potenciometra: Maketēšanas shēma**

![](Potentiometer_multiple_LED_bb.png)

**Divas LED lampiņas paralēli pie potenciometra: Elektriskā shēma**

![](Potentiometer_multiple_LED_schem.png)

