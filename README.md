**Konteinerių testavimas v1.0**

Makefile set-up:
**Makefile idiegimas naudojant Chocolatey (Windows)**

Isitikinkite, kad turite Chocolatey idiegima: patikrinkite, ar jusu kompiuteryje yra idiegta Chocolatey. Jei ne, idiekite pagal instrukcijas https://chocolatey.org/install.

Idiekite Makefile: atidarykite PowerShell kaip administratorius ir ivykdykite sia komanda:

choco install make

Patikrinkite idiegima: patikrinkite, ar Makefile sekmingai idiegtas, vykdydami komanda:

make --version

Jei viskas sekminga, turetumete pamatyti Make versijos informacija

Makefile idiegimas naudojant kitus metodus
**MacOS:** Makefile iprastai yra idiegtas standartinėje MacOS distribucijoje, todel papildomu veiksmu paprastai nereikia

**Linux:** Daugumoje Linux distribuciju Makefile taip pat yra idiegtas is anksto. Jei reikia, naudokite savo paketu tvarkykle, pvz., apt-get, yum, dnf, arba kita pagal distribucija

**Windows (be Chocolatey):** Noredami idiegti Makefile Windows sistemoje be Chocolatey, galite naudoti rankinius idiegimo failus, kuriuos galite rasti internete. Paprastai tie failai turi .exe pletini ir gali buti lengvai idiegti, sekdamie pridedamas instrukcijas

Norint pradeti, i terminala reikia ivesti "make", kai viskas bus sukompiliuota, galima testi su programa, jei norima, galima rasyti "make clean" norint istrinti .o ir .exe failus

**Programos naudojimas veikimo metu:**

Vartotojas pasirenka, su kokiu konteineriu norima vygdyti programa ir pasirinktinai i terminala parasoma: ./vektoriai , ./list arba ./deque

Vos paleidus programa atsiras pasirinkimas ar norime ivesti duomenis ar skaityti is failo

1. Jei bus pasirenkamas duomenu ivedimas, bus reikalaujama pasirinkti ar norima ivesti/generuoti duomenis
   
1.1 Ar vienu, ar kitu budu reikes ivesti studentu vardus ir pavardes, toliau reikes ivesti studentu namu darbu ir egzamino pazymius

1.2 Jei bus pasirinktas duomenu generavimas, po vardu ir pavardziu irasymo nieko daryti nebereikes

1.3 Galiausiai reikes pasirinkti kur norime matyti duomenis ekrane ar faile

2. Jei pacioje pradzioje bus pasirinktas skaitymas, jusu bus klausiama ar norite generuoti naujus failus, jei ivesite 't'(taip), bus generuojami nauji failai, jei ivesite bet koki kita simboli, programa veiks toliau

2.1 Toliau, jusu bus klausiama ar norite skaityti naujai sukurtus failus, ar jau turimus

2.2 Bus prasoma ivesti, pasirinktinai, turimu/nauju failu kieki, jie bus nuskaitomi, isvedami apytiksliai testavimu laikai ekrane bei sukuriami nauji failai, kuriuose yra surusiuoti studentai pagal vidurki (nuskriaustieji/mokslinciai)

2.3 Galiausiai, kaip ir anksciau, bus isvedami apytiksliai testavimu laikai ekrane bei sukuriami nauji failai, kuriuose yra surusiuoti studentai pagal vidurki (nuskriaustieji/mokslinciai)

**Sistemos specifikacijos:**

CPU: 12th Gen Intel(R) Core(TM) i5-12450H

RAM: 16.0 GB 3200 MHz SODIMM

Disk: SSD 477 GB

**Testavimas su 100000 ir 1000000 dydzio failais naudojant Vector konteinerius bei efektyviausias strategijas**

| Test type | Size (elements) | Reading time (s) | Ascending student sorting (s) | Student distribution (s) | The whole program time (s) |
|-------------|-------------------|-----------------------|----------------------------------------|-------------------------|---------------------|
| 3 strategy with structure | 100000 | 0.319553 | 0.141024 | 0.0175034 | 0.47808 |
| 3 strategy with structure | 1000000 | 5.06984 | 1.7883 | 0.143022 | 7.00116 |
| 2 strategy with class | 100000 | 0.340054 | 0.271545 | 0.0195832 | 0.642104 |
| 2 strategy with class | 1000000 | 5.18636 | 3.56959 | 0.42957 | 9.18552 |

**Tyrimas su flag'ais: O1, O2, O3. Naudojant 1000, 10000, 100000, 1000000, 10000000 dydzio failus:**

Tyrimas su struktura ir O1 flag'u:

| Container Type | Execution Time (s) | Read Time (s) | Sorting Time (s) | Distribution Time (s) | Total Program Time (s) |
|----------------|---------------------|----------------|-------------------|-----------------------|------------------------|
| Vector         |                     |                |                   |                       |                        |
| Program 0      | 0.0050002           | 0.0034997      | 0.0010005         | 0.0005                | 0.0050002              |
| Program 1      | 0.0390076           | 0.0285069      | 0.0095015         | 0.0009992             | 0.0390076              |
| Program 2      | 0.484587            | 0.345561       | 0.125522          | 0.0135038             | 0.484587               |
| Program 3      | 4.64331             | 2.93551        | 1.58228           | -                     | 4.64331                |
| Program 4      | 45.4899             | 23.0585        | 21.2812           | 1.1502                | 45.4899                |
| Exe File Size  | 3,236,057 bytes     |                |                   |                       |                        |
| List           |                     |                |                   |                       |                        |
| Program 0      | 0.0019998           | 0.0080038      | 0.0005005         | 0.0014993             | 0.0019998              |
| Program 1      | 0.0175032           | 0.065011       | 0.0050017         | 0.0125015             | 0.0175032              |
| Program 2      | 0.274548            | 0.949292       | 0.0740129         | 0.200535              | 0.274548               |
| Program 3      | 4.25874             | 7.66134        | 1.6998            | -                     | 4.25874                |
| Program 4      | 101.9545             | 56.2608        | 20.1495           | 28.805                | 101.9545                |
| Exe File Size  | 3,191,154 bytes     |                |                   |                       |                        |
| Deque          |                     |                |                   |                       |                        |
| Program 0      | 0.0035005           | 0.0049535      | 0.0020005         | 0.0015                | 0.0035005              |
| Program 1      | 0.0440086           | 0.0430076      | 0.0290056         | 0.015003              | 0.0440086              |
| Program 2      | 0.551095            | 0.505588       | 0.383567          | 0.167529              | 0.551095               |
| Program 3      | 12.21393             | 4.79334        | 6.01705           | 2.19688               | 12.21393                |
| Program 4      | 159.944             | 42.5389        | 67.4136           | 51.5299               | 159.944                |
| Exe File Size  | 3,327,606 bytes     |                |                   |                       |                        |

Tyrimas su klase ir O1 flag'u:

| Container Type | Execution Time (s) | Read Time (s) | Sorting Time (s) | Distribution Time (s) | Total Program Time (s) |
|----------------|---------------------|----------------|-------------------|-----------------------|------------------------|
| Vector         |                     |                |                   |                       |                        |
| Program 0      | 0.0050012           | 0.004501       | 0                 | 0.0005002             | 0.0050012              |
| Program 1      | 0.0460066           | 0.0385062      | 0.0055005         | 0.0019999             | 0.0460066              |
| Program 2      | 0.5716              | 0.461081       | 0.0810144         | 0.0295049             | 0.5716                 |
| Program 3      | 5.67849             | 3.85667        | 1.49576           | 0                     | 5.67849                |
| Program 4      | 46.9982             | 31.2865        | 13.5789           | 2.13287               | 46.9982                |
| Exe File Size  | 3,208,169 bytes     |                |                   |                       |                        |
| List           |                     |                |                   |                       |                        |
| Program 0      | 0.0020008           | 0.0080007      | 0.0005009         | 0.0014999             | 0.0020008              |
| Program 1      | 0.0350069           | 0.0645114      | 0.0050007         | 0.0300062             | 0.0350069              |
| Program 2      | 0.382567            | 0.871736       | 0.0785142         | 0.304052              | 0.382567               |
| Program 3      | 8.7107              | 7.33478        | 1.41175           | 0                     | 8.7107                 |
| Program 4      | 88.8049             | 50.2698        | 17.9646           | 20.8403               | 88.8049                |
| Exe File Size  | 3,199,927 bytes     |                |                   |                       |                        |
| Deque          |                     |                |                   |                       |                        |
| Program 0      | 0.0050018           | 0.0055003      | 0.0030009         | 0.0020007             | 0.0050018              |
| Program 1      | 0.0720122           | 0.0420061      | 0.0510085         | 0.0210037             | 0.0720122              |
| Program 2      | 0.869152            | 0.501586       | 0.617108          | 0.252044              | 0.869152               |
| Program 3      | 10.3083             | 4.34372        | 8.04791           | 0                     | 10.3083                |
| Program 4      | 260.117             | 35.5537        | 132.357           | 127.76                | 260.117                |
| Exe File Size  | 3,360,857 bytes     |                |                   |                       |                        |

Tyrimas su struktura ir O2 flag'u:

| Container Type | Execution Time (s) | Read Time (s) | Sorting Time (s) | Distribution Time (s) | Total Program Time (s) |
|----------------|---------------------|----------------|-------------------|-----------------------|------------------------|
| Vector         |                     |                |                   |                       |                        |
| Program 0      | 0.0047067           | 0.0042062      | 0.0005005         | 0                     | 0.0047067              |
| Program 1      | 0.042008            | 0.0300052      | 0.0105019         | 0.0015009             | 0.042008               |
| Program 2      | 0.520761            | 0.364734       | 0.142024          | 0.0140026             | 0.520761               |
| Program 3      | 7.86073             | 3.09642        | 1.63228           | 0                     | 7.86073                |
| Program 4      | 48.4715             | 24.6913        | 22.4154           | 1.36474               | 48.4715                |
| Exe File Size  | 3,236,057 bytes     |                |                   |                       |                        |
| List           |                     |                |                   |                       |                        |
| Program 0      | 0.0015002           | 0.0082244      | 0.0005            | 0.0010002             | 0.0015002              |
| Program 1      | 0.0175029           | 0.0650114      | 0.0050007         | 0.0125022             | 0.0175029              |
| Program 2      | 0.272547            | 0.857124       | 0.0740121         | 0.198535              | 0.272547               |
| Program 3      | 8.91368             | 7.78652        | 1.61828           | 0                     | 8.91368                |
| Program 4      | 87.4335             | 53.7364        | 16.5079           | 17.9256               | 87.4335                |
| Exe File Size  | 3,199,927 bytes     |                |                   |                       |                        |
| Deque          |                     |                |                   |                       |                        |
| Program 0      | 0.0034996           | 0.0050002      | 0.0020002         | 0.0014994             | 0.0034996              |
| Program 1      | 0.0435079           | 0.0425067      | 0.0280048         | 0.0155031             | 0.0435079              |
| Program 2      | 0.552596            | 0.50953        | 0.381066          | 0.17153               | 0.552596               |
| Program 3      | 13.75585             | 5.40969        | 5.44395           | 2.3119                | 13.75585                |
| Program 4      | 162.333             | 40.3203        | 71.137            | 51.1956               | 162.333                |
| Exe File Size  | 3,360,857 bytes     |                |                   |                       |                        |

Tyrimas su klase ir O2 flag'u:

| Container Type | Execution Time (s) | Read Time (s) | Sorting Time (s) | Distribution Time (s) | Total Program Time (s) |
|----------------|---------------------|----------------|-------------------|-----------------------|------------------------|
| Vector         |                     |                |                   |                       |                        |
| Program 0      | 0.0055011           | 0.0050007      | 0.0005004         | 0                     | 0.0055011              |
| Program 1      | 0.0470063           | 0.0390066      | 0.0055005         | 0.0024992             | 0.0470063              |
| Program 2      | 0.582602            | 0.475583       | 0.0780137         | 0.0290053             | 0.582602               |
| Program 3      | 5.46307             | 4.14984        | 1.06418           | 0                     | 5.46307                |
| Program 4      | 48.639              | 33.6619        | 13.0023           | 1.97484               | 48.639                 |
| Exe File Size  | 3,208,169 bytes     |                |                   |                       |                        |
| List           |                     |                |                   |                       |                        |
| Program 0      | 0.0024999           | 0.008003       | 0.0004995         | 0.0020004             | 0.0024999              |
| Program 1      | 0.0210038           | 0.0730135      | 0.0050009         | 0.0160029             | 0.0210038              |
| Program 2      | 0.407571            | 0.865819       | 0.106519          | 0.301053              | 0.407571               |
| Program 3      | 9.91518             | 7.49181        | 1.23422           | 0                     | 9.91518                |
| Program 4      | 89.8424             | 52.4482        | 16.5879           | 21.2545               | 89.8424                |
| Exe File Size  | 3,199,927 bytes     |                |                   |                       |                        |
| Deque          |                     |                |                   |                       |                        |
| Program 0      | 0.005002            | 0.0055015      | 0.0030009         | 0.0020011             | 0.005002               |
| Program 1      | 0.0745136           | 0.042508       | 0.0535094         | 0.0210042             | 0.0745136              |
| Program 2      | 0.986671            | 0.511088       | 0.673116          | 0.313556              | 0.986671               |
| Program 3      | 14.6769             | 4.6168         | 8.16593           | 2.51094               | 14.6769                |
| Program 4      | 418.046             | 38.8396        | 160.951           | 226.095               | 418.046                |
| Exe File Size  | 3,360,857 bytes     |                |                   |                       |                        |

Tyrimas su struktura ir O3 flag'u:

| Container Type | Execution Time (s) | Read Time (s) | Sorting Time (s) | Distribution Time (s) | Total Program Time (s) |
|----------------|---------------------|----------------|-------------------|-----------------------|------------------------|
| Vector         |                     |                |                   |                       |                        |
| Program 0      | 0.0045014           | 0.004001       | 0.0005004         | 0                     | 0.0045014              |
| Program 1      | 0.041007            | 0.0300054      | 0.0095018         | 0.0014998             | 0.041007               |
| Program 2      | 0.509153            | 0.368628       | 0.127022          | 0.0135029             | 0.509153               |
| Program 3      | 4.9417              | 3.10938        | 1.7033            | 0.129023              | 4.9417                 |
| Program 4      | 45.977              | 24.2637        | 20.6526           | 1.06069               | 45.977                 |
| Exe File Size  | 3,236,057 bytes     |                |                   |                       |                        |
| List           |                     |                |                   |                       |                        |
| Program 0      | 0.0015006           | 0.008001       | 0.0005004         | 0.0010002             | 0.0015006              |
| Program 1      | 0.0195033           | 0.0710122      | 0.0049995         | 0.0145038             | 0.0195033              |
| Program 2      | 0.303553            | 0.876629       | 0.0800141         | 0.223539              | 0.303553               |
| Program 3      | 9.26857             | 7.39279        | 1.30823           | 1.96034               | 9.26857                |
| Program 4      | 85.1036             | 52.6155        | 16.4499           | 16.6538               | 85.1036                |
| Exe File Size  | 3,191,154 bytes     |                |                   |                       |                        |
| Deque          |                     |                |                   |                       |                        |
| Program 0      | 0.0035008           | 0.0050004      | 0.0020001         | 0.0015007             | 0.0035008              |
| Program 1      | 0.0560091           | 0.0435075      | 0.0395067         | 0.0165024             | 0.0560091              |
| Program 2      | 0.613107            | 0.522592       | 0.415073          | 0.198034              | 0.613107               |
| Program 3      | 13.41147             | 5.44945        | 6.04506           | 2.36641               | 13.41147                |
| Program 4      | 199.657             | 44.1667        | 74.1381           | 80.5185               | 199.657                |
| Exe File Size  | 3,360,857 bytes     |                |                   |                       |                        |

Tyrimas su klase ir O3 flag'u:

| Container Type | Execution Time (s) | Read Time (s) | Sorting Time (s) | Distribution Time (s) | Total Program Time (s) |
|----------------|---------------------|----------------|-------------------|-----------------------|------------------------|
| Vector         |                     |                |                   |                       |                        |
| Program 0      | 0.0055017           | 0.0055017      | 0                 | 0                     | 0.0055017              |
| Program 1      | 0.0475074           | 0.0400064      | 0.0055013         | 0.0019997             | 0.0475074              |
| Program 2      | 0.597408            | 0.480888       | 0.085515          | 0.0310053             | 0.597408               |
| Program 3      | 5.42704             | 3.97929        | 1.17671           | 0.109842              | 5.42704                |
| Program 4      | 45.735              | 30.8484        | 12.7782           | 2.10837               | 45.735                 |
| Exe File Size  | 3,208,169 bytes     |                |                   |                       |                        |
| List           |                     |                |                   |                       |                        |
| Program 0      | 0.0019997           | 0.0080013      | 0.0004997         | 0.0015                | 0.0019997              |
| Program 1      | 0.0240043           | 0.0665113      | 0.0055013         | 0.018503              | 0.0240043              |
| Program 2      | 0.382566            | 0.867648       | 0.080514          | 0.302052              | 0.382566               |
| Program 3      | 8.75816             | 7.11774        | 1.21421           | 0                     | 8.75816                |
| Program 4      | 84.3958             | 50.4263        | 15.4762           | 18.9196               | 84.3958                |
| Exe File Size  | 3,199,927 bytes     |                |                   |                       |                        |
| Deque          |                     |                |                   |                       |                        |
| Program 0      | 0.0045012           | 0.005501       | 0.0030008         | 0.0015004             | 0.0045012              |
| Program 1      | 0.068011            | 0.0424404      | 0.0465076         | 0.0215034             | 0.068011               |
| Program 2      | 0.903157            | 0.508089       | 0.63511           | 0.268046              | 0.903157               |
| Program 3      | 16.6034             | 4.56399        | 8.29845           | 2.3049                | 16.6034                |
| Program 4      | 436.001             | 36.8229        | 150.043           | 164.958               | 436.001                |
| Exe File Size  | 3,360,857 bytes     |                |                   |                       |                        |
