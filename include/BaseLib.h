/******************************************************************************
                                      
Developed and Copyright (c) by       
                                      
Erik Unger          
                                      
Contact: erik@erikunger.com
                                      
******************************************************************************/

#ifndef BaseLib_h
#define BaseLib_h



/**
@mainpage BaseLib Documentation

@section intro BaseLib ?

@subsection overview Overview:

-# @ref BuffersAndStreams
-# @ref Console
-# @ref Containers
-# @ref DataBases
-# @ref ErrorHandling
-# @ref Functors
-# @ref FunctorsAndContainers
-# @ref Network
-# @ref Reflection
-# @ref Strings
-# @ref System
-# @ref Trees
-# @ref Utilities
-# @ref Xml
-# @ref FAQ
-# @ref Download
-# @ref CodingStyle
*/



/**
@page Todo

*/



/**
@page FAQ

*/



/**
@page Download

*/

/**
@page CodingStyle

@section naming Benennung:

- Keine Polnische Notation, also keine Pr�fixe f�r Typ, global/member/lokal
- Wir verwenden so gut es geht keine Abk�rzungen!
- Alle Namen in Englisch
- Beschreibende Namen verwenden, Sinn und Verwendbarkeit sollten daraus hervorgehen
- Typen und Namespaces beginnen mit Gro�buchstaben, Variablen und Funktionen mit Kleinbuchstaben
- Bei zusammengesetzen W�rtern wird der erste Buchstabe des n�chsten Wortteils gro� geschrieben (MyType, myVariable, myFunction)
- Klassen und Interfaces beginnen wie andere Type mit einem Gro�buchstaben nicht mit C oder I
- Abstrakte Klassen beginnen normalerweise mit dem Wort Abstract, Ausnahmen f�r bessere Lesbarkeit sind m�glich
- Defines, Enums und Konstanten werden durchgehend gro� geschrieben mit einem Underline (_) als Trennzeichen bei zusammengesetzten W�rtern
- Jede Klasse (oder struct) bekommt eine eigene h + cpp Datei, die so heist wie die Klasse. Ausnahme sind kleine Hilfsklassen und Klassen in Klassen.
- Getter und Setter Methoden beginnen immer mit get (bei bool mit is) und set gefolgt vom Variablen/Property Namen. Der Parameter f�r einen neu zu setzenden Wert heist immer new gefolgt vom Variablen/Property Namen:
@code
class MyClass {
public:

    MyClass(int newColor, bool newTransparent)
        : color(newColor)
        , transparent(newTransparent)
    {
    }

    int getColor() const
    {
        return color;
    }

    void setColor(int newColor)
    {
        color = newColor;
    }

    bool isTransparent() const
    {
        return transparent;
    }

    void setTransparent(bool newTransparent)
    {
        transparent = newTransparent;
    }

private:
    int color;
    bool transparent;
};
@endcode

- Das Symbol um zu verhindern dass ein Header mehrfach inkludiert wird heist wie Namespace und Name der Klasse des Headers, getrennt durch Underlines (_) und gefolgt von _h. #pragma once wird nicht verwendet:
@code
#ifndef BaseLib_Strings_StringTokenizer_h
#define BaseLib_Strings_StringTokenizer_h

namespace BaseLib {
namespace Strings {

class StringTokenizer {
};

} // namespace Strings
} // namespace BaseLib

#endif // #ifndef BaseLib_Strings_StringTokenizer_h
@endcode

@section formating Formatierung:

- F�r Einr�ckungen Tabs verwenden
- Standard Tab-Breite ist 4
- F�r zeichengenaue Ausrichtung keine Tabs verwenden sonder Leerzeichen:
@code
// Eine derartige Ausrichtung ist �brigens nicht Pflicht,
// sondern individuell dem Programmierer �berlassen um besserere �bersicht zu schaffen:
float aLongName = 6;
int   x         = 5; // hier Leerzeichen verwenden
@endcode

- Jede Anweisung, Deklaration und Definition beginnt eine neue Zeile:
@code
int x, z = 0; // Falsch!!!
int x = 0;    // ok
int y = 0;    // ok
@endcode

- Pointer- (*) und Referenzzeichen (&) werden immer ohne Leerzeichen beim Typ geschrieben:
@code
int *x = NULL; // Falsch!!!
int* y = NULL; // ok
int& z = *y;   // ok
@endcode

- Abh�ngige Zuweisungen die nicht in eine Zeile passen sind folgenderma�en zu formatieren:
@code
aVeryLongVariableCalledX = anotherVeryLongVariableCalledY > 0 ?
    anotherVeryLongVariableCalledY :
    doSomeCalculationsToScretchTheLineWith(anotherVeryLongVariableCalledY, 7777777777);    
@endcode

- Bei Parameterlisten die nicht in eine Zeile passen, sind alle Parameter einger�ckt in einer neuen Zeile zu schreiben:
@code
// Richtig:
aFunctionWithLongParameterList(
    x,
    y, 
    z,
    aLongVariableNameCalledA,
    aLongVariableNameCalledB,
    aLongVariableNameCalledC,
    NULL);

// Falsch:
aFunctionWithLongParameterList(x,
                               y, z,
                               aLongVariableNameCalledA,
                               aLongVariableNameCalledB,
                               aLongVariableNameCalledC,
                               NULL
                              );
@endcode


- Ausf�hrungsbl�cke beginnen immer in einer neuen Zeile:
@code
void fill(int width, int height)
{
    for (int x = 0; x < width; ++x)
    {
        for (int y = 0; < height; ++y)
        {
            drawPixel(x, y);
        }
    }
}
@endcode

- Deklarations- und Initialiserungsbl�cke beginnen immer in der selben Zeile:
@code
class MyClass {
};

int smallArray[] = {0, 1, 2};

int bigArray[] = {
    0,
    1,
    2,
    3,
    4,
};

enum MyEnum {
    RED,
    GREEN,
    BLUE
};
@endcode

- Alles wird in Namespaces untergebracht. Der �usserste Namespace heist wie das Projekt. Formatierung folgenderma�en:
@code
namespace BaseLibEngine {
namespace OpenGLRenderer {
namespace SceneGraph {
namespace Visitors {



class MyVisitor {
};



} // namespace Visitors
} // namespace SceneGraph
} // namespace OpenGLRenderer
} // namespace BaseLibEngine
@endcode

- Ein Leerzeichen vor und nach einem Klammernblock wenn dieser nicht in weiteren Klammerbl�cken geschachtelt ist, ein Leerzeichen nach Beistrichen und Semikolons sowie ein Leerzeichen vor und hinter Operatoren:
@code
for (int i = 0; i < 100; ++i);
if ((x == 7) && (y == 8));
@endcode

- Bei Klassendeklarationen werden public, protected und private nicht einger�ckt:
@code
class MyClass {
public:
    MyClass(); 

protected:
    int x;

private:
    int y;
};
@endcode

- Bei Konstuktoren beginnt jede Initialisierung einger�ckt in einer eigenen Zeile:
@code
class MyClass {
public:
    MyClass()
        : x(0)
        , y(1)
        , z(2)
    {
    }

private:
    int x;
    int y;
    int z;
};
@endcode

- Bei Bl�cken auf Basisebene 3 Leerzeilen Abstand halten:
@code
// Example.h



namespace MyNameSpace {



class MyClass1 {
public:
    void memberFunction();
};



class MyClass2 {
public:
    void memberFunction();
};



} // namespace MyNameSpace



// Beispiel.cpp



#include "Example.h"



namespace MyNameSpace {



void MyClass1::memberFunction()
{
}



void MyClass2::memberFunction()
{
}



} // namespace MyNameSpace
@endcode

@section projectstructure Projektstruktur:

- Jedes Projekt hat einen Basis-Namespace mit dem Namen des Projekts
- Die Namespacestruktur wird im include-Verzeichnis als Verzeichnisstruktur abgebildet
- Im src-Verzeichnis wird ebenfalls die Namespacestruktur abgebildet, jedoch ohne den Basis-Namespace des Projektes. D.h. alle Dateien des Basis-Namespaces liegen direkt im src-Verzeichnis. Beispiel:
- BaseLib
	- trunk
		- include
			- BaseLib
				- Strings
					- StringTokenizer.h
		- source
			- Strings
				- StringTokenizer.cpp


- Im Header-Suchpfad werden die include-Verzeichnis der verwendeten Projekte eingetragen. Header werden dann immer mit der gesamten Namespace-Verzeichnisstruktur relativ zum include-Verzeichnis inkludiert:
@code
#include "BaseLib/Strings/StringTokenizer.h"
#include "BaseLib/Graphics/PixelBuffer.h"
@endcode

- using namespace ist in Headern verboten. Wenn es die Lesbarkeit erlaubt Namen aus anderen Namespaces mit vollem Namespace schreiben, ansonsten Namen einzeln mit using einbinden:
@code
#include "BaseLib/Strings/StringTokenizer.h"

using namespace BaseLib::Strings;        // Falsch!!!
using BaseLib::Strings::StringTokenizer; // ok
@endcode

@section common Allgemein:

- Code sollte ausdruckstark und m�glichst selbstkommentierend sein
- Lesbarkeit geht vor Kompaktheit (Hypergeile Konstrukte die m�glichst viel in einer Zeile unterbringen sind unerw�nscht)
- F�r alles weitere was hier nicht genormt wurde, ist Scott Meyers Effektiv C++ unsere Bibel!

*/

#include "BaseLib/Buffers.h"
#include "BaseLib/Common.h"
#include "BaseLib/Console.h"
#include "BaseLib/Containers.h"
#include "BaseLib/DataBases.h"
#include "BaseLib/Debuging.h"
#include "BaseLib/ErrorHandling.h"
#include "BaseLib/Functors.h"
#include "BaseLib/Graphics.h"
#include "BaseLib/Math.h"
#include "BaseLib/Network.h"
#include "BaseLib/Reflection.h"
#include "BaseLib/Streams.h"
#include "BaseLib/Strings.h"
#include "BaseLib/System.h"
#include "BaseLib/Testing.h"
#include "BaseLib/Trees.h"
#include "BaseLib/Types.h"
#include "BaseLib/Utilities.h"
#include "BaseLib/Xml.h"



#endif // #ifndef BaseLib_h
