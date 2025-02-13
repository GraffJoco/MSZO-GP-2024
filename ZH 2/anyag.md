# Tartalom

- [Matlab alapjai](#matlab-alapjai)
  [Műveletek a matlabban](#matlab-alapjai)

# Matlab alapjai

A Matlab (Matrix Laboratory) egy matematikai célú programnyelv, mely szintaktiailag és programszerkezetileg is jelentősen eltér a C++-tól, helyette a Pythonnal legegyszerűbb összehasonlítani: mindkettő interpretes (fordító nélküli), dinamikus típusokkal ellátott nyelv, ahol a változókat nem kell külön deklarálni.

A nyelvben az egyes utasításokat pontosvesszővel tudjuk elválasztni. Futások között a `clear` utasítással lehet törölni az ezelőtti értékeket (mert a fordító megjegyzi azokat).  
Kiíratáshoz a `disp` vagy a `fprintf` függvényt használjuk. Kommentekhez a százalékjel `%` karaktert használjuk.

~~~matlab
% Törli az eddigi értékeket
clear;

% Nem kell a változót kiírni
t = 5 * pi;

% Kiírási módok:
fprintf("t erteke: %f", t);
disp(['t erteke: ', num2str(t)]);
~~~

Ebben a kódban még egy dolgot is lehet észrevenni: a stringeknek két különböző fajtája van, egy sima, egy dupla macskakörömmel. Ezekre úgy lehet gondolni, mint a C stringjei (egy macskaköröm, primitív), és a C++ stringje (két macskaköröm, komplexebb, van összeadási művelet).

A numerikus típusok is máshogy működnek: minden szám valós vagy komplex, és vagy 4 vagy 8 byte méretűek. Ezért ajánlott minden program elejére rakni a következő sort:

~~~Matlab
format long;
~~~

## Műveletek a Matlabban

A Matlabban azok a matematikai függvények és konstansok megtalálhatóak, mint amik a C-ben, de vannak újak is. Ebben a táblázatban gyűjtöttem össze őket

| Matlab szintaxis | Matematikai leírás | C kód | Megjegyzés |
| :-- | :-: | :-- | :-- |
| a^b | $a^b$ | pow(a, b) | A kalap itt tényleg hatványoz |
| exp(a) | $e^a$ | exp(a) | e konstans nincs, ajánlott `e = exp(1);` |
| cos(a) | $cos(a)$ | cos(a) | Radián, többi trig. függvény is működik |
| pi | $\pi$ | M_PI | |
| a + b * 1i | $a + bi$ | - | MOO kereteiben implementáltunk csak komplex számokat |

A matlab egyik fő funkciója a beépített mátrixkönyvtára. Mátrixokat szögletes zárójelek közé kell írni, a soron belüli elemeknél szóköz vagy vessző, sor végén pontosvessző az elválasztójel.

~~~Matlab
mat = [5, 3; 6 2];
disp(mat);
%{
Konzolban:
    5    3
    6    2
}%
~~~

Természetesen minden szükséges mátrixművelet bele van építve a nyelvbe:

~~~Matlab
A = [1 2 1;
    5 3 2;
    2 1 0];

B = [2 3; 5 4; 7 8];

C = [8 7; 5 6; 3 2];

% Összeadás
disp(B + C);

% Szorzás
disp(A * B);

% Inverz
disp(inv(A));

% Mátrix hatvány
disp(A ^ 3);
~~~

## Feltételek

Ezek nem változtak sokat a C/C++-hoz képest, csak kicsit máshogy néznek ki:

~~~Matlab
% if: FELTELEL, if után end
if a > 0
    fprintf("a pozitiv\n");
else
    fprintf("a negativ\n");
end

if a == 5
    fprintf("a 5\n");
end

% switch: hasonló, mint C-ben, de minden előtt case
% végén end, és default helyett switch
switch a
    case 2
        fprintf("paros prim\n");
    case 3
        fprintf("paratlan prim\n");
    case 420
        fprintf("funni");
    otherwise
        fprintf("nemtom, kifogytam az otletekbol");
end
~~~

## Függvények

Matlabban egy függvény több kimenettel és bemenettel is rendelkezhet. Ezek mindegyikét el kell nevezni függvény írásánál, és - szép szóval - szintaktikailag nem a leg szebben néznek ezek ki.

Ha van egy $F(\underline{x}) \rightarrow \underline{y}$ függvényünk, ahol $\underline{x} \in \R^n$ és $\underline{y} \in \R^m$ azt a következő módon kell deklarálni

~~~Matlab
function [y1, y2, ..., ym] = F(x1, x2, ..., xN)
  y1 = %eredmény1
  % ....
  ym = %eredménym
end
~~~

Például egy másodfokú megoldó a következő módon néz ki:

~~~Matlab
function [x1, x2] = gyokok(a, b, c)
    D = sqrt(b^2 - 4 * a * c);
    x1 = (-b + D) / (2 * a);
    x2 = (-b - D) / (2 * a);
end

% Több eredménynél szögletes zárójelben kell deklarálni őket
[e1, e2] = gyokok(1, 2, 1);
fprintf("%f %f", e1, e2);
~~~

Ezek a függvények lehetnek rekurzívak is természetesen, és egy kimenet esetén szerencsére a szögletes zárójel mellőzhető:

~~~Matlab
function res = fib(x)
    if x <= 1
        res = 1;
    else
        res = fib(x - 1) + fib(x - 2);
    end
end

fprintf("F(5) = %f\n", fib(5));
~~~
