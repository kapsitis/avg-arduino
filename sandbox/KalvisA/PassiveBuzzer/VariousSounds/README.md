# Dažādas skaņas ar dūcēju

Dūcējam var likt atskaņot dažādas vienbalsīgas melodijas. 
Šīs ir komandas, ar kurām var atskaņot skaņas:

``` cpp
// sāk atskaņot kvadrātveida signālu ar doto frekvenci no kontakta "pin"
tone(pin, frequency); 

// tas pats (tikai uz noteiktu laiku milisekundēs)
tone(pin, frequency, duration); 

// pārstāj atskaņot signālu
noTone(pin);
```

Mūsu gadījumā Arduino plate reaģēs uz pogām (4x4 pogu panelim 
piestiprināti kontakti **C1**, **R1**, **C2**, **R2**, **C3**, **R3**). 
Tiklīdz kā nospiesta kāda no pogām S1, S6, S11 (pirmā poga pirmajā rindā, 
otrā poga otrajā rindā vai trešā poga trešajā rindā), 
kontakts 5, 6, vai 7 aiziet uz **GND** (0V spriegumu). Tas ieslēdz attiecīgu 
melodiju. Mums ir 3 melodijas: 

1. Hromatiska gamma (pa pustoņiem 12 soļi uz priekšu un atpakaļ).
2. Aijā žūžū. 
3. 


Ja gribas uzprogrammēt kaut ko izaicinošāku, var apskatīties, teiksim, 
"ņau-ņau" dziesmas augšējo melodiju un nokodēt to.

Mūzikas fragments 
[YouTube: What was I made for (Meow)](https://youtu.be/3-y0p0GL4TI?si=0z6BQxvuVBKV_-7Z). 
Finneas O'Connell, Billie Eilish. 

![](what_was_i_made_for.png)




## Vienādi temperēta gamma

Par hromatisko gammu uzskatām augošu skaņu virkni - parasti vienas oktāvas 
ietvaros: 


| Nota (Italiana) | do  | do# | re  | re# | mi  | fa  | fa# | sol | sol# | la  | la# | si  | do'  |
|-----------------|-----|-----|-----|-----|-----|-----|-----|-----|------|-----|-----|-----|------|
| Nota (Tedesca)  | C   | C#  | D   | D#  | E   | F   | F#  | G   | G#   | A   | A#  | B   | C'   |
| Frequenza (Hz)  | 261.63 | 277.18 | 293.66 | 311.13 | 329.63 | 349.23 | 369.99 | 392.00 | 415.30 | 440.00 | 466.16 | 493.88 | 523.25 |

Mūzikā vēsturiski izveidojušās dažādas temperācijas sistēmas 
(mūzikas instrumentu uzskaņošanas veidi).
Kopš 19.gadsimta beigām parasti cenšas visus instrumentus 
uzskaņot "vienādi temperēti" (*equal temperament*), t.i. viena oktāva (frekvenču attiecība 2:1)
satur 12 pilnīgi vienādus pustoņus: frekvence "do# pret do", "re pret do#" utt. 
"si pret augšējo do" visas ir vienādas. Ja šo attiecību vienā pustonī 
apzīmē ar $x$, iegūstam vienādojumu:

$$x^{12} = 2,\;\;\text{ jeb }\;\;x=\sqrt[12]{2} = 1.059463.$$

To, ka skaņas veido ģeometrisko progresiju, var labi redzēt uz ģitāras grifa, uz kura 
nevienādos attālumos izvietotas *ladas*. 

![](fretboard.png)

Kā izklausās vienādi temperētas klavieres (salīdzinot ar dažādiem vēsturiskiem temperējumiem 
jeb skaņošanas veidiem) var redzēt šajā 
[YouTube: Piano TEMPERAMENT comparison](https://youtu.be/3O5J6A4uh30?si=WbQmXgOKgec7At60). 

*Piezīme:* Tas, ko J.S.Bahs sauca par "labi temperētām klavierēm", 
visticamāk bija pāreja no kādas Baroka agrīnā posmā izplatīta temperējuma (piemēram, Meantone)
uz modernāku (piemēram, Kirnberger 2). Sal. [labais temperaments](https://en.wikipedia.org/wiki/Well_temperament). 



