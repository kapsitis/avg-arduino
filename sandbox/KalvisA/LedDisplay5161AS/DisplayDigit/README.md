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
Tā jāpieslēdz pie (visām diodēm kopīgas) $220~\text{\Omega}$ 
pretestības un tālāk -- pie Arduino **GND** kontakta.

Kopīgā katoda displeju attēlo šāda elektriskā shēma:

![](common_cathode.png)

