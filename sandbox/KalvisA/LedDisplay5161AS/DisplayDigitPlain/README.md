# Cipara zīmēšana uz 7 posmu LED displeja

<table>
  <tr>
    <td><img src="segment_names.png" width="200px"/></td>
    <td><img src="7_segment_display.png" width="200px"/></td>
  </tr>
</table>

LED displeju veido vairākas gaismas diodes. Ir populāri 7 posmu displeji, 
kuros segmenti izkārtoti kā cipars "astoņi" un, ieslēdzot vai izslēdzot 
atsevišķus posmus, var attēlot visādus ciparus apmēram tāpat kā kalkulatora ekrānā.

Visām diodēm ir kopīgs "katods" jeb diodes īsākā kājiņa, kura atrodas pretī 
simbolam "-" -- tā atbilst vidējai kājiņai gan augšējā, gan apakšējā 5 kontaktu rindā. 


Kopīgā katoda displeju attēlo šāda elektriskā shēma:

![](common_cathode.png)

Tā kā arī LED displeja diodēm ir ieteicams 2 voltu sprieguma kritums un 20 miliampēru 
strāvas stiprums, tad shēmai jāpieslēdz rezistors. Šis rezistors ir kopīgs 
visam ciparam; tā elektriskā pretestība ir $220~\Omega$ 
un tālāk tas pieslēgts pie **GND** kontakta. (Teorētiski varētu arī pieslēgt pretestības 
arī otrā pusē - pie visām LED diožu kājiņām, bet tad vajadzētu astoņas pretestības.)

Elektriskā shēma izskatās šādi:

![](DisplayDigitPlain_schem.png)

Maketēšanas plates attēls izskatās šādi: 

![](DisplayDigitPlain_bb.png)

