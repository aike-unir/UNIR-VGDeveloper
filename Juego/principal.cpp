// proyecto: Grupal/Juego
// arhivo:   principal.cpp
// versión:  1.1  (9-Ene-2023)


#include "juego.h"


int main () {

    juegoNivel::JuegoNivel* niveles = new juegoNivel::JuegoNivel{};

    niveles->seleccionNivel(0);
   
    return 0;    
}
