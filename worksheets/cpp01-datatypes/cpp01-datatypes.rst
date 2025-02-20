C++ tipi un sintakse. Mirkšķināšana
======================================

* Elektriskās ķēdes, virknes slēgums, Oma likums
* Diodes, priekšējais spriegums, maksimālā strāva
* Stringi, simboli, veselie skaitļi un peldošā punkta skaitļi
* Drukāšana uz seriālā porta, bitu pārraides ātrums (*baud rate*, bps)



Mirkšķināšana
---------------






Ārējas diodes pievienošana
----------------------------

Rezistoru krāsas. 
https://www.blikai.com/blog/decoding-resistor-color-bands-a-beginner-s-guide


https://www.blikai.com/blog/decoding-resistor-color-bands-a-beginner-s-guide


.. |circuit01| image:: figs/circuit1.png
   :width: 400px
   :align: middle

.. |circuit02| image:: figs/circuit2.png
   :width: 400px
   :align: middle

.. list-table:: 
   :widths: 45 45
   :align: center
   :header-rows: 0

   * - |circuit01|
     - |circuit02|



**Jautājums**
  Daži cilvēki ir jūtīgi pret signāllampiņu mirkšķināšanu 
  noteiktās frekvencēs. Šādas frekvences mēdz būt starp :math:`3~\mathrm{Hz}`
  :math:`30~\mathrm{Hz}` (īpaši problemātiskas ir :math:`15` līdz :math:`20` 
  hercu frekvences). 
  Kā jāizvēlas abi gaidīšanas laiki izsaukumos ``delay(milliseconds)``, lai 
  panāktu šādu mirkšķināšanas frekvenci? 