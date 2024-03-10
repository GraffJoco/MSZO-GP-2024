# Grafikus Felületek 1. ZH anyaga

## C++/CLI alapjai

A C++/CLI a Microsoft külön programnyelve, amivel a .NET platformra lehet C++ kódot írni. Emiatt gyakran a C# nyelvhez szokták hasonlítani.  

A C++/CLI egyik legfontosabb különbsége az, hogy a C++ alap típusai változtak: habár azonos a nevük, valójában osztályok. Az olyan átalakítások, mint a `double(valtozo)` helyett a `Convert::ToDouble`-höz hasonló szintaxot kell használni, valamint körülbelül minden típusnak van `.ToString()` tagfüggvénye.  

Ezen kívül a pointerek is mások lettek: azért, hogy ne kelljen a `delete`-t hívni mindenen, speciális típusok egy ú.n. garbage collector (GC) használatával szabadulnak fel. Ezeket csillag helyett a `^` karakterrel jelöljük, létrehozásuknál a `gcnew` kulcsszót használjuk:

```C++
String^ osztaly = gcnew String;

osztaly += L"ő-t használhatsz, ha az idézőjel előtt van L";
osztaly += label1->Text;

// nincs delete :)
```

Amint látni lehet, a `String` most nagy betűvel van, ugyanis a C++/CLI más osztályokkal dolgozik, mint amiket mi kezeltünk még MOO keretein belül (habár azok is alkalmazhatóak egyes esetekben).
A következők a legfontosabbak:

- `String`: szövegek
- `cli::array<T>^`: dinamikus tömb
- `List<T>^`: bővíthető tömb, mint a C++ vector, `lista->Add()` fv végére helyez elemeket
