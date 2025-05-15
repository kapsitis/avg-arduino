# Loģiskā NOT ķēde

Matemātiskā loģika darbojas ar izteikumiem, kuri var būt patiesi vai aplami.
Elektriskajās ķēdēs notiek objektīvi fizikāli 
procesi (kuri paši par sevi nav ne patiesi, ne aplami - 
pirms tos kaut kā nepaskaidro jeb neinterpretē.)
Biežākās interpretācijas var būt šādas: 

**Datu ievade:**

* Patiess/True - "ieejas vads" ir savienots ar HIGH jeb 5V; poga ir nospiesta vai slēdzis ir aizvērtā 
  stāvoklī. 
* Aplams/False - "ieejas vads" ir savienots ar LOW jeb 0V; poga nav nospiesta vai slēdzis ir atvērtā
  jeb nesavienotā stāvoklī. 

**Datu izvade:** 

* Patiess/True - spriegums uz "izejas vada" (salīdzinot ar **GND** kontaktu) ir HIGH jeb 5V. 
  Vai, teiksim, ķēdē ieslēgtā LED lampiņa deg. 
* Aplams/False - spriegums uz "izejas vada" (salīdzinot ar **GND** kontaktu) ir LOW jeb 0V. 
  Vai, teiksim, ķēdē ieslēgtā LED lampiņa nedeg. 

Negācija var nozīmēt šādu uzvedību: 

* **Ievade:** Lietotājs nospiež pogu, aizver/noslēdz slēdzi, 
  pieslēdz "ieejas vadu" 5V spriegumam. 
* **Izvade:** Izejas vadā spriegums nokrīt uz LOW jeb 0V. 
  Vai arī LED diode pārstāj degt tieši pogas nospiešanas brīdī.

Kā to panākt: 

* Viegli noorganizēt, lai LED diode nodzistu, ja kāds spriegums 
  uzkāpj no 0V uz 5V: Var LED pieslēgt pie otra vada, kurš vienmēr ir 5V; 
  tad LED lampiņa nodziest precīzi tad, ja pirmais vads no 0V arī kļūst 5V. 
* Mazliet grūtāk ir panākt, lai spriegums uz kāda cita vada mainītos no 5V uz 0V tad, 
  ja uz pirmā vada tas mainījās no 0V uz 5V. (Negācija apmaina "HIGH" un "LOW" vērtības.)
  Parasti  pkārt LED diodei izveido "apvedceļu" ar daudz mazāku pretestību. 
  Šajā gadījumā abos LED diodes galos būs vienāds spriegums un tā nedegs 
  (Šāda ķēde patērē strāvu arī tad, kad LED lampiņa ir izslēgta, jo cauri pretestība
  visu laiku plūst strāva.)


## NOT ķēde ar vienu pogu

<table>
  <tr>
    <td><img src="NotGateButton_bb.png" width="300px"/></td>
    <td><img src="NotGateButton_schem.png" width="300px"/></td>
  </tr>
</table>


## NOT ķēde ar vienu transistoru

Izmantota shēma no [theorycircuit.com](https://theorycircuit.com/digital-electronics/design-logic-gates-using-transistors/): 

![](NotGate_schem.png)

Negācija (NOT) ir vienvietīgs operators; to pielieto tikai vienam 
Būla mainīgajam. Tas apgriež izteiksmes patiesuma vērtību. 

<table>
<tr><th>A</th><th>(NOT A)</th></tr>
<tr><td>False</td><td>True</td></tr>
<tr><td>True</td><td>False</td></tr>
</table>

Loģikas piemēri parastās valodas teikumos: 

* Negācija no "šonakt bija sniegs" ir "šonakt nebija sniega". 
* Negācija no "$x > 3$" (mainīgais $x$ *lielāks* par $3$) ir $x \leq 3$ 
  ($x$ *nav lielāks* par $3$ jeb *nepārsniedz* $3$). 
* Negācija no "Šodien visi bija skolā" ir "Šodien visi nebija skolā" jeb 
  "Eksistē kāds, kurš nebija skolā".
* Negācija no "Neviens šodien nebija skolā" ir "Atradīsies kāds, kurš 
  šodien bija skolā".

Noliegums izteikumam "Šodien visi bija skolā", protams, nav 
"Šodien neviens nebija skolā" (tās ir divas atšķirīgas, bet ne pretējas 
situācijas - jo tās nepārklāj gadījumus, kur daži ir skolā, bet daži citi nav.)



## Jautājumi 

1. Vai ir pamatoti teikt, ka NOT ķēde ar pogu izraisa ķēdē īsslēgumu? 
2. Kurā situācijā ķēde patērē vairāk jaudas -- tad, kad LED diode 
   deg vai arī tad, kad LED diode nedeg? 
   
*Piezīme:* Patērēto enerģiju iegūst pēc formulas 
$P = UI$, kur $P$ ir jauda (*power*), $U$ ir spriegums (*voltage*), 
bet $I$ ir strāvas stiprums (*current*). 
