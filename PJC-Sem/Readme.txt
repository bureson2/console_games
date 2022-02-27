Zadání je herní aplikace, ve které je možné se pohybovat a spouštět různé konzolové minihry
Ovládání a manipulace se zkompilovaným programem a ovládání jednotlivých her je popsáno v --help přepínači
Aplikace je napsaná pro Linux a využívá přetvořenou knihovnu Conio.h,
která komplikuje spuštění, ale pro zpracování tohoto tématu byla téměř nezbytná.


Zde je návod na zprovoznění této přepsané knihovny.
https://github.com/zoelabbb/conio.h

Možnosti originální windows knihovny Conio jsou k dispozici, ale 
tato verze knihovny je velmi špatně napsána, a tak při vícenásobném použití v jednom programu
vyhazuje i za použití PRAGMA ONCE a dalších postupů chybu.

Nakonec jsem situaci vyřešil tak, že mám vytvořené větší množství samostatných projektů s jednotlivými hrami,
u kterých by po jejich kompilaci mělo dojít kpřesunu do složky games v ConsoleGame.
ConsoleGame je hlavní část programu, která umožňuje fungovat v malém "herním světe" a přecházet pomocí něj mezi jednotlivými hrami.
