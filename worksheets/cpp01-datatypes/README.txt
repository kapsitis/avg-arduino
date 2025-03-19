
**Oma likums:** 
  Elektriskā ķēdē :math:`I = U/R`, kur :math:`U` ir *spriegums* (piemēram, :math:`5~\text{V}` jeb 
  :math:`5` volti), 
  :math:`R` ir *pretestība* (piemēram, :math:`220~\Omega` jeb :math:`220` omi). Tad :math:`I` 
  ir *strāvas stiprums* (piemēram, :math:`I = 5/220` jeb :math:`0.023~\text{A}` jeb :math:`0.023`
  ampēri). 

**Citi Oma likuma varianti:** 
  Ja strāvas stiprums :math:`I` un pretestība :math:`R` ir zināmi, tad var atrast *potenciālu starpību* 
  jeb *sprieguma kritumu* uz šīs pretestības: :math:`U = IR`.
  Tas ir tas pats Oma likums, pierakstīts ar reizinājumu nevis dalījumu.
  Ja zināms spriegums un strāva, var atrast pretestību: :math:`R = U/I`.

**Piemērs 1:** 
  * Elektrisku ierīci ar diviem poliem, kura māk radīt noteiktu spriegumu jeb potenciālu starpību 
    (vienreizlietojama baterija ar :math:`1.5~\text{V}`, atkaluzlādējama baterija
    ar :math:`1.2~\text{V}` vai Arduino plate ar :math:`5~\text{V}`) sauc par *strāvas avotu*.
  * Elektrisku ierīci ar diviem izvadiem un fiksētu pretestību sauc par *rezistoru*. 
    (Komplektā ir rezistori ar pretestību :math:`220~\Omega`.)
  * Elektrisku ierīci ar diviem izvadiem, kurai vienā virzienā 
    ir ļoti maza pretestība, bet pretējā virzienā ir 
    ļoti liela pretestība (strāvu šajā virzienā cauri nelaiž) sauc par *diodi*.
    Dažas diodes izstaro gaismu - un tās tad sauc par gaismas diodēm 
    (jeb LED -- *light-emitting diode*). 

**Analoģija:**
  Ja iztēlojamies elektrisko strāvu kā ūdeni, tad:
  
  * *strāvas stiprums* (ampēri) līdzinās ūdens plūsmas ātrumam (piemēram, kubikmetri sekundē), 
  * *spriegums* (volti) līdzinās ūdenskrituma augstumam vai (slēgtā trubā) ūdens spiedienam.
  * Rezistors līdzinās trubas sašaurinājumam, caur kuru ūdenim grūtāk plūst cauri. 
  * Diode līdzinās vārstam, kurš laiž ūdeni cauri tikai vienā virzienā (un pretējā virzienā aizkrīt ciet).

  Elektriskā strāva vienmēr plūst no plusa (+) uz mīnusu (-). (Negatīvi lādētie elektroni strāvas vadiņos
  faktiski pārvietojas pretēji elektriskās strāvas virzienam.)

**Virknes slēgums:** 
  Ja virknē saslēdz divas pretestības :math:`R_1` un :math:`R_2` 
  (rezistorus, diodes vai jebko citu), tad kopīgā ķēdes pretestība ir :math:`R = R_1 + R_2`. 

**Piemērs 2:** 
  Pieņemsim, ka elektriskā ķēdē (ar kopīgo spriegumu :math:`5~\text{V}`) 
  ir virknē saslēgts viens rezistors un 
  viena gaismas diode ar nulles pretestību un maksimālo strāvas stiprumu  
  :math:`20~\text{mA}` (miliampēri) un ar sprieguma kritumu :math:`2~\text{V}`. 
  Atrast, kādai jābūt rezistora pretestībai, lai diode nepārsniegtu maksimālo strāvas stiprumu. 

**Atrisinājums:**
  Apzīmējam sprieguma kritumu uz diodes ar :math:`U_1 = 2~\text{V}` un
  sprieguma kritumu uz pretestības ar :math:`U_2`. Izpildās vienādība: :math:`U = U_1 + U_2`. 
  Tāpēc sprieguma kritums uz rezistora ir :math:`U_2 = 5~\text{V} - 2~\text{V} = 3~\text{V}`. 
  Dalām to ar maksimāli atļauto strāvu jeb :math:`20~\text{mA} = 0.020~\text{A}`. 
  Iegūstam :math:`R = U_2/I = 3/0.020 = 150~\Omega` jeb :math:`150` omi. 
  (Kastītēs atrodamās pretestības ir :math:`220` omi, bet arī tās var izmantot - strāva caur 
  diodi šajā gadījumā būs vēl mazāka.)

.. only:: Internal
  
  Rezistoru krāsas. 
  https://www.blikai.com/blog/decoding-resistor-color-bands-a-beginner-s-guide