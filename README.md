# avg-arduino

ĀVĢ Arduino projekti

ĀVĢ Arduino projektu mājaslapu ar paskaidrojumiem par katru atsevišķo projektu sk. 
[ĀVĢ Arduino projekti](https://ej.uz/avg-arduino). 

C++ valodas zināšanas, kas var noderēt Arduino projektos. 

1. **Pamatsintakse un datu tipi:**
   - Ieviešam mainīgos un datu tipus (int, float, char, bool), darbības ar tiem.
   - Var mirkšķināt iebūvēto LED uz kontroliera; 
     mirkšķināšanas laikus var uzglabāt mainīgajos. 
     Var arī iedegt ārējas LED dažādās krāsās; izmantojot simbolu mainīgos.

2. **Zarošanās un cikli**
   - Komandas **if-else** (varbūt arī **switch-case**) un cikli **for** un 
     **while**. 
   - Var izmantot zarošanos, lai iedegtu LED atkarībā no pogas vai potenciometra 
     stāvokļa. Pogas vai potenciometra stāvokli pārbaudīt ciklā. 
     Mirkšķināšanu uzticēt veikt funkcijai; funkcijas var mirkšķināt 
     vairākos raksturīgos veidos (*patterns*). 

3. **Masīvi**
   - Datu virkņu uzglabāšana masīvos. 
   - Var kontrolēt vairāku 7-segmentu LED displeju; glabāt datus 
     pareizo segmentu iedegšanai masīvos. Izvadīt secīgus paziņojumus, 
     nejaušus skaitļus (kā metamajam kauliņam) vai arī skrejošu gaismu efektus.

4. **Digitālā un analogā ievade/izvade**
   - Lasīt sensoru ievadi; izvadīt datus kontrolierim un seriālajam portam. 
   - Kontrolēt LED spožumu (vai iedegtā LED krāsu) ar 
     potenciometru. Izmantot ``analogRead()`` lai nolasītu potenciometra 
     vērtību un `analogWrite()` lai izmainītu LED spožumu.
     Pievienot arī temperatūras sensoru seriālajam monitoram. 

5. **Objektorientācija**
   - Pastāstīt par klasēm, objektiem un metodēm. 
   - Izveidot klasi, lai iekapsulētu motora uzvedību (metodes start, stop, 
     stāvokļa pārbaudes). 
     