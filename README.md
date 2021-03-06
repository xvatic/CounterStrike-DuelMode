# Akční hra

Implementujte jednoduchou střílecí hru alespoň jednoho hráče proti počítači.

## Základní funkcionality

* Zničení zničitelných předmětů
* Pohyb hráče na mapě
* Jednoduchý "fyzikální" model (kolize s překážkami)
* Načítání mapy ze souboru.
* Načítání tabulky ze souboru.

## Pokročilé funkcionality

* Hra obsahuje hlavní menu.
* Hra umožňuje hráči zvolit si jméno.
* Tato hra může ukázat výsledek bitvy.
* Tato hra má tréninkový režim.

## Využití polymorfismu

* Hráč a nepřítel. Za pohyb a střelbu hráče je zodpovědné zpracování stisků kláves. Pro nepřítele to odpovídá jednoduchá umělá inteligence.
* Herní mód. Přechod do konkrétního herního režimu je implementován předáním objektu třídy CGame.
* K dispozici jsou celkem 4 režimy:
    * Hlavní menu,
    * Demonstrace výsledků,
    * Tréninkový režim,
    * Herní režim.
* V neherních režimech metoda fetchInput čeká na další pokyny hráče. V herních režimech tato metoda zpracovává stisknutí klávesnice (sleduje ovládání hry). Zpočátku hra začíná v režimu MainMenu, podle volby hráče se hra přepne do tréninkového nebo herního režimu, na konci hry je zapnutý režim předvádění výsledků. Herní režim se od tréninkového liší tím, že nepřítel v tréninovém režimu nic nedělá.
* Ve hře jsou dva typy střel. Jeden z nich zobrazuje použití zbraní na blízko. Druhý zobrazuje létající kulku. Mají rozdíly v poškození. Létající kulka se může pohybovat v prostoru (měnit souřadnice).
* Textury. Ve hře jsou tři typy textur:
    * Cihla
    * Strom
    * Nic
* Hlavním důvodem pro použití polymorfismu jsou kolize. Cihla má kolize se všemi objekty ve hře. Nelze to zlomit. Strom má kolize s hráčem, ale kulky ho mohou zlomit. Dokud není strom zlomen, kulka nemůže projít. Po zasažení kulkou se na místě stromu nic neobjeví. Nic nemá kolize. 