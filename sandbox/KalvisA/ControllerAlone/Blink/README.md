# Mirkšķināšana

Vienkārša Arduino programmiņa ieslēdz un izslēdz spriegumu uz 13.kontakta. 
13.kontakts ir *digitāls*, jo tas vienmēr strādā ar 
divām sprieguma vērtībām $0~\text{V}$ un $5~\text{V}$. 
13.kontakts mirkšķina arī mazu LED diodi uz pašas Arduino plates (var 
redzēt mirkšķināšanu), bet 
tam var pieslēgt arī ārēju LED diodi. 

Drusku uzskatāmāku šo pašu eksperimentu var padarīt, pievienojot 
ārēju LED diodi (tāpat kā iepriekš - kopā ar rezistoru saslēgtu virknē). 
Ievērosim, ka **HIGH** mūsu programmiņās ir 5 voltu spriegums. 

![](Blink_bb.png)

Šeit tā pati ķēde kā shēma: 

![](Blink_schem.png)
