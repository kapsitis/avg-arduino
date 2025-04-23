# Skaitītājs uz LED displeja

LED displejs ar četriem 14-segmentu cipariem (5141AS)
atšķiras no tiem LED displejiem, ar kuriem darbojāmies līdz šim. 
Lietotājs tam nekontrolē katra 14-segmentu cipara katru 
atsevišķo segmentu kā atsevišķu diodi; nav arī vajadzības pieslēgt 
papildu rezistorus, jo tie visi ir iebūvēti modulī. 

Modulim ir 5 kontakti; Arduino ar šo ierīci sazinās ar I2C protokolu
un pats modulis izdomā, kurus segmentus iezīmēt. 
Vienlaikus lietotājam ir pilna kontrole pār jebkuru no 4*14 = 56 segmentiem, 
uz tiem var attēlot jebkuru bildi - nav obligāti jāzīmē cipariņi. 

