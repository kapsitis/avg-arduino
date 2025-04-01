# 2 LED cipariņi ar multipleksēšanu

Lai varētu zīmēt skaitļus (piemēram, visus skaitļus no "00" līdz "99")
uz divu LED diožu ekrāna, abus cipariņus nevar pieslēgt Arduino kontrolierim 
pa taisno. Katram no cipariņiem ir 10 kājiņas; katrai vajadzētu kādu 
diskrēto kontaktu. Bet mums ir tikai kontakti no 0. līdz 13. (pavisam 14 kontakti). 

Lai ar Arduino kontrolētu lielāku skaitu cipariņu (tsk. kalkulatoros vai 
līdzīgos lietojumos), jāizmanto multipleksēšana. 
(Šī ideja parādījās arī agrīnajās televīzijas tehnoloģijās - kurās viens un tas
pats kineskops ar elektronu plūsmu "zīmēja" punktus uz televizora ekrāna, ļoti 
strauji skrienot pa visām rindiņām.)

Lai panāktu multipleksēšanu, saslēgt diagrammu, kas redzama šajā elektriskajā shēmā: 

![](MultiplexingDisplays_schem.png)

Vai maketēšanas plates zīmējumā: 

![](MultiplexingDisplays_bb.png)

Ievērosim, ka tikai iezemējumus katram cipariņam kontrolē katram atsevišķi. 
Visas citas diodes ir saslēgtas tā, ka vienu un to pašu posmiņu kontrolē tas 
pats Arduino kontakts (bet tikai tad, ja iezemējums ir pieslēgts pie **GND**). 
Tas var šķist neparasti - lai kādu LED displeja posmu ieslēgtu, iezemējums 
ir jāpieslēdz pie **LOW** (0 voltu sprieguma). Lai visus posmus izslēgtu
(lai šajā laikā varētu zīmēt blakusesošo cipariņu)
LED displeja iezemējumu pieslēdz pie **HIGH** (5 voltu sprieguma). T.i. 5V spriegums 
visas diodes izslēgs, jo tām vai nu uz attiecīgā LED displeja diodes 
posma kājiņas arī būs 5 voltu spriegums 
(nav spriegumu starpības), vai nu arī uz šīs kājiņas būs 0 volti (bet tad diode 
arī nespīdēs, jo būs ieslēgta nepareizā virzienā). 

Pievērsiet uzmanību šim trikam programmiņā:

```
          displayNumber(k / 10, 12);
          displayNumber(k % 10, 13);
```

Ja "k" ir skaitlis robežās no 0 līdz 99, tad "k%10" (atlikums, dalot ar 10) ir 
skaitļa pēdējais cipars. Bet "k/10" (dalījums, dalot ar 10) ir 
skaitļa priekšpēdējais cipars. s 