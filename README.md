**v1.2**

**Apie programa:**

Programa yra skirta valdyti mokiniu duomenis. Ji igyvendina Mokinio klase, kuri leidzia saugoti studentu vardus, pavardes, namu darbu rezultatus, egzamino pazymius ir kitus duomenis

**Pridėtos funkcijos v1.2:**

1. Pilnai realizuoti visi "Rule of five" metodai (Destructor, Copy Constructor, Copy Assignment Operator, Move Constructor, Move Assignment Operator)
2. Pridėti įvesties/išvesties metodu persidengimai

**Kas yra "Rule of five" metodai?**

**Destruktorius:** sis metodas atsakingas uz resursu atlaisvinima, kurie buvo isskirti objekto gyvavimo metu. Kai objektas yra sunaikinamas arba iseina is scopo, destruktorius yra automatiskai iskvieciamas

**Kopijavimo konstruktorius:** kopijavimo konstruktorius yra metodas, kuris sukuria nauja objekta pagal esama objekta. Tai reikalinga, kai norite nukopijuoti viena objekta i kita

**Kopijavimo priskyrimo operatorius:** kopijavimo priskyrimo operatorius yra metodas, kuris nukopijuoja vieno objekto busena i kita esama objekta

**Perkelimo konstruktorius:** perkelimo konstruktorius yra specialus metodas, kuris perkelia resursus is vieno objekto i kita, paliekant pirmini objekta tuscia

**Perkelimo priskyrimo operatorius:** perkelimo priskyrimo operatorius yra metodas, kuris perkelia resursus is vieno objekto i kita, panaikinant pirmini objekta

**Kaip atrodo mano igyvendinti "Rule of five" metodai:**

"Rule of five" metodai(vector konteineriai):

![image](https://github.com/Ignas420/Objekt_prog2/assets/145566919/3c8e266a-bbb7-4b6e-a0bf-de8faffcdb1c)

Perdengti metodai:

![image](https://github.com/Ignas420/Objekt_prog2/assets/145566919/1b41f44a-a76c-44e3-b5b3-0bb64f80720d)

**Perdengtu metodu duomenu ivestis - rankiniu budu, o duomenys isvedami i faila**

**Taip pat, vartotojui yra galimybe pasirinkti koki "Rule of five" metoda norima testuoti:**

![image](https://github.com/Ignas420/Objekt_prog2/assets/145566919/b429c4da-7f6f-4a40-bce7-697017c714c8)

Isvedimas atrodo kazkas panasaus i tai:

![image](https://github.com/Ignas420/Objekt_prog2/assets/145566919/8da40a0e-d4b2-4794-9bb6-f2f105a2a5c3)



