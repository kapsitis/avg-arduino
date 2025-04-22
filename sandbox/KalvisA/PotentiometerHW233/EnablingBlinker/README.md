# LED ieslēgšana ar potenciometru

Šajā ķēdē pie noteikta sprieguma (aptuveni 2.5 volti jeb potenciometrs 
vidējā stāvoklī) kontakts **A0** saņems vērtību, kas ir vismaz 512
no intervāla [0; 1023]. Šajā brīdī LED lampiņu sāks mirkšķināt 
cits kontakts (kontakts **13**). 

Ja potenciometra vērtība ir zemāka, tad diodi izslēdz. 

![](EnablingBlinker_bb.png)

## Papildu vingrinājumi

1. Ieslēgt ķēdē dažādu krāsu diodes un noskaidrot, kādā potenciometra stāvoklī 
   tās (kaut vai ļoti blāvi) iedegas. 
   Pēc teorijas vajadzētu būt tā, ka sarkanās diodes iedegas pie viszemākā sprieguma, 
   bet zilās diodes - pie vislielākā sprieguma.
2. Mainīt programmu tā, lai diodei atkarībā no potenciometra stāvokļa 
   būtu četri dažādi mirkšķināšanās biežumi.