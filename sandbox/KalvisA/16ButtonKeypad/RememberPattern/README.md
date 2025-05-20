# Pogu kombinācijas iegaumēšana

Šajā praktiskajā darbā jāizvieto $3 \times 4$ LED lampiņas
trīs rindās un četrās kolonnās un uz tām jāattēlo kaut kāda 
nospiesto pogu kombinācija. 

Pogu kombināciju iegūst, tās nospiežot pa vienai jebkurā secībā 
uz $4 \times 4$ pogu matricas (apakšējā pogu rinda **S13**, 
**S14**, **S15**, **S16** šajā kombinācijā nepiedalās - tās 
izmantosim sistēmas vadībai). 

**Iegaumēšanas projekta uzvedība:** 

1. Visas LED led lampiņas ir iespraustas maketēšanas platē - tās 
   izvietotas trīs rindās un četrās kolonnās (sk. shēmu). 
2. Katra LED lampiņa saslēgta virknē ar savu $220~\Omega$ rezistoru (gaiši zilu). 
3. $4 \times 4$ pogu matrica ir piesprausta tieši pie Arduino 
   (piemēram, tā, kā attēlots zīmējumā - izmantojot 4 digitālos kontaktus un 
   četrus analogos kontaktus), bet varat arī citādi). 
4. No Arduino uz maketēšanas plati ved tieši 4 vadi (visticamāk, Jums gribēsies 
   izmantot digitālos kontaktus kā zīmējumā, bet varat jebkurus). 
5. Ja uz pogu matricas nospiež jebkuru pogu (no **S1** līdz **S12**), tad 
   attbilstošā LED lampiņa (tajā pašā rindā un kolonnā, kurā nospiestā poga)
   mums trīsreiz pamirkšķina, lai lietotājs zinātu, ka poga tiešām nospiesta. 
   Lietotājs var vēlēties tās pašas pogas spiest atkārtoti un tad arī jāmirkšķina 
   atkārtoti. 
6. Ja lietotājs nospiež **S13** pogu, tad vienlaikus iedegas visas 
   LED lampiņas, kuras lietotājs bija nospiedis. Tās turpina degt arī pēc 
   tam, kad **S13** poga ir atlaista. Tās LED lampiņas, kuru pogas nebija nospiestas, 
   netiek iedegtas -- tāpēc var uzzīmēt uz LED lampiņu "ekrāna" nelielu bildīti.
7. Ja lietotājs nospiež **S14** pogu, tad visas LED lampiņas nodziest. 
   Lietotājs var turpināt spiest pogas (no **S1** līdz **S12**) un pievienot 
   attēlam vēl kādu iedegtu lampiņu (arī tā trīsreiz pamirkšķina). 
8. Ja lietotājs nospiež **S15** vai **S16** pogu, tad Arduino "aizmirst" 
   esošo pogu kombināciju un var sākt ievadīt jaunu.

*Piezīme:* No minētajiem noteikumiem grūti izpildāms 
varētu būt ceturtais (kā panākt, ka 
uz maketēšanas plati ar LED lampiņām ved tieši 4 vadi)? 
No $12$ LED lampiņām, tās jebkādā veidā ieslēdzot vai izslēdzot, var 
izveidot ļoti daudz kombināciju: 

$$2^{12} = 4096.$$

Izrādās, ka visus šos $4096$ variantus ne vien var atcerēties programma uz 
Arduino kontroliera, bet arī attiecīgo informāciju "aizsūtīt" maketēšanas 
plates lampiņām, izmantojot tikai četrus vadus. 

Pirms ķerties pie šī darba veikšanas, ieteicams veikt šādas darbības:

1. Salikt elektrisko shēmu kā parādīts attēlā. 
2. Nosūtīt Arduino kontrolierim programmiņu, kas nolasa pogas: `RememberPattern.ino`.
3. Atvērt uz Arduino IDE **Tools** > **Serial Monitor**.  
4. Pārliecināties, ka seriālais ports pareizi izdrukā podziņas, ja 
   tās spiež pa vienai. 

Pēc tam var izdomāt, kā pievienot četrus ienākošos vadus 
maketēšanas plates LED lampiņām (un pielabot programmu `RememberPattern.ino`)
tā, lai izpildītos minētās 8 prasības. Pēc tam savu shēmiņu var testēt.