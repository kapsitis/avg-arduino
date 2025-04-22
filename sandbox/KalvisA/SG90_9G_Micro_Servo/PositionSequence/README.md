# Motora pagriezieni par noteiktiem leņķiem

Panākt, lai servo motors dara to, ko vajag, nav ļoti vienkārši. 
Tas saprot komandas, ko padod no kāds no pulsa platuma modulācijas (PWM) kontaktiem 
(tie ir 3., 5., 6., 9., 10., 11. kontakti Arduino platei). 
Visas komandas, ko var nosūtīt ir veseli skaitļi intervālā $[0;180]$. 
Nekustīgais jeb "neitrālais" stāvoklis ir $90$; 
visi leņķi, kas mazāki par $90$ liek motoram griezties 
pretēji pulksteņa rādītājiem; leņķi, kas lielāki par $90$ liek griezties 
pulksteņa rādītāju virzienā. 

Lai labāk saprastu, kā motors kārtējā solī griežas, 
piedāvājam uzdevumu, kurš groza servo motoru nedaudz uz vienu vai 
otru pusi. Programma arī attēlo ar LED gaismiņu, kurš no četriem griezieniem pašlaik notiek.

Šajā piemērā ir saslēgta ķēde, kura cikliski dod vienas un tās 
pašas 4 komandas servo motoram:  
**(1)** 1 sekundi griežas pretēji pulksteņa rādītājiem (vērtība ``LEFT_POS`` jeb $80$);  
**(2)** Uz 1 sekundi apstājas (vērtība ``NEUTRAL_POS`` jeb $90$)  
**(3)** 1 sekundi griežas pulksteņa rādītāju virzienā (vērtība ``RIGHT_POS`` jeb $100^{\circ}$)  
**(4)** Uz 1 sekukndi apstājas (vērtība ``NEUTRAL_POS`` jeb $90$)


Elektriskajā shēmā ir pieliktas arī trīs diodes: 


A. Sarkana diode norāda, ka motors griežas virzienā uz ``RIGHT_POS``
B. Zaļa diode norāda, ka motors griežas virzienā uz ``LEFT_POS``
C. Zila diode norāda, ka motors atgriežas neitrālajā stāvoklī jeb ``NEUTRAL_POS``. 

Uz sarkano un zaļo diodi ir kopīgs $220~\Omega$ rezistors, 
bet zilajai diodei ir pašai savs. 


## Leņķa pozīcija vai leņķiskais ātrums?

Ir iespējami divu veidu servo motori. 

* **Pozīcijas kontrolēšana:** Šiem motoriem uz I/O nosūtītais signāls 
  pasaka leņķi, kurā motoram ir jānostājas. Šoreiz motora griešanās ātrumu 
  nevar tieši kontrolēt; SG90 ražotājs to parasti uzstāda 0.1 sekundes (jeb sekundes desmitdaļa), lai pagrieztos par $60^{\circ}$. 
* **Leņķiskā ātruma kontrolēšana:** Šiem motoriem uz I/O nosūtītais signāls 
  pasaka leņķisko ātrumu, ar kuru motoram ir jāgriežas. Kamēr nenosūta 
  citu ātrumu, motors turpina griezties. Tam nav nekādas leņķa gala pozīcijas, 
  kurā tam būtu jānostājas. 

Visas pazīmes liecina, ka komplektā esošie motori kontrolē griešanās ātrumu 
(nevis pozīciju). Tomēr tradīcijas dēļ arī šiem motoriem vērtība $90$ apzīmē 
"neitrālu" stāvokli (nulles ātrumu), kaut arī tai nav sakara ar $90^{\circ}$ 
leņķa pozīciju, kurā motoram vajadzētu nostāties.




Elektriskā shēma:

![](PositionSequence_schem.png)

Maketēšanas plates attēls:

![](PositionSequence_bb.png)