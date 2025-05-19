// proyecto: Grupal/Juego
// arhivo:   JuegoMesa.cpp
// versión:  1.1  (9-Ene-2023)


#include "juego.h"


namespace juego3 {

    string JuegoMesa3::carpeta_activos_juego{ "./activos/" };
    string JuegoMesa3::carpeta_retratos_juego{ "./retratos/" };
    string JuegoMesa3::carpeta_habilids_juego{ "./habilidades/" };
    string JuegoMesa3::carpeta_sonidos_juego{ "./sonidos/" };


    const std::wstring JuegoMesa3::tituloVentana() const {
        return L"Nivel 3 - Espacio exterior";
    }


    JuegoMesa3::JuegoMesa3() {
        ModoJuegoEquipo* modo = new ModoJuegoEquipo{ this };
        SucesosJuegoEquipo* sucesos = new SucesosJuegoEquipo{ this, modo };

        JuegoMesaBase::configura(sucesos, modo);
    }



    static ActorTablero::GraficoMuros grafico_muros_vacio{
        "-     -     -     -     -     -     -     -     -",
        "   -     -     -     -     O     -     -     -   ",
        "-     -     -     -     -     O     -     -     -",
        "   -     -     -     -     -     O     -     -   ",
        "-     -     -     F     -     -     O     -     -",
        "   -     -     -     -     -     -     O     -   ",
        "-     -     -     -     F     -     O     -     -",
        "   -     -     -     -     -     O     -     -   ",
        "-     -     -     -     -     O     O     -     -",
        "   -     -     -     -     -     O     -     -   ",
        "-     -     -     -     -     -     -     -     -",
        "   -     -     -     -     F     -     -     -   ",
        "-     -     -     -     -     -     -     -     -" };



    void JuegoMesa3::preparaTablero() {
        agregaTablero(new ActorTablero(this));

        tablero()->ponArchivoBaldosas(carpeta_activos_juego + "estampas_fondo.png");
        tablero()->ponArchivoFondo(carpeta_activos_juego + "fondo_volcanes.png");

        tablero()->equipa(LadoTablero::Izquierda, L"Devils", carpeta_activos_juego + "escudo_devils.png");
        tablero()->equipa(LadoTablero::Derecha, L"Tusk", carpeta_activos_juego + "escudo_tusk.png");

        tablero()->situaMuros(grafico_muros_vacio);

    }


    void JuegoMesa3::preparaPersonajes() {

        Guillermo = new ActorPersonaje{ this, LadoTablero::Izquierda, 0, L"Guillerm2" , Elemento::Fuego };
        Wuuf = new ActorPersonaje{ this, LadoTablero::Izquierda, 1, L"Wuuf", Elemento::Hielo };
        Rosa = new ActorPersonaje{ this, LadoTablero::Izquierda, 2, L"Rosa", Elemento::Rayo };
        Clint = new ActorPersonaje{ this, LadoTablero::Izquierda, 3, L"Clint", Elemento::Piedra };
        Panoramix = new ActorPersonaje{ this, LadoTablero::Izquierda, 4, L"Panoramix", Elemento::Veneno };

        Enemigo1 = new ActorPersonaje{ this, LadoTablero::Derecha,   0, L"Enemigo1", Elemento::nulo };
        Enemigo2 = new ActorPersonaje{ this, LadoTablero::Derecha,   1, L"Enemigo2", Elemento::nulo };


        //
        Guillermo->ponArchivoRetrato(carpeta_retratos_juego + "male1_75.png");
        Wuuf->ponArchivoRetrato(carpeta_retratos_juego + "male1_75.png");
        Rosa->ponArchivoRetrato(carpeta_retratos_juego + "male1_75.png");
        Clint->ponArchivoRetrato(carpeta_retratos_juego + "male1_75.png");
        Panoramix->ponArchivoRetrato(carpeta_retratos_juego + "male1_75.png");

        Enemigo1->ponArchivoRetrato(carpeta_retratos_juego + "aristocrat_75.png");
        Enemigo2->ponArchivoRetrato(carpeta_retratos_juego + "aristocrat_75.png");

        //
        Guillermo->ponArchivoFicha(carpeta_retratos_juego + "sprite1.png");
        Wuuf->ponArchivoFicha(carpeta_retratos_juego + "sprite1.png");
        Rosa->ponArchivoFicha(carpeta_retratos_juego + "sprite1.png");
        Clint->ponArchivoFicha(carpeta_retratos_juego + "sprite1.png");
        Panoramix->ponArchivoFicha(carpeta_retratos_juego + "sprite1.png");

        Enemigo1->ponArchivoFicha(carpeta_retratos_juego + "sprite2.png");
        Enemigo2->ponArchivoFicha(carpeta_retratos_juego + "sprite2.png");

        //
        Guillermo->ponIniciativa(20);
        Wuuf->ponIniciativa(18);
        Rosa->ponIniciativa(16);
        Clint->ponIniciativa(15);
        Panoramix->ponIniciativa(22);

        Enemigo1->ponIniciativa(19);
        Enemigo2->ponIniciativa(17);

        //
        agregaPersonaje(Guillermo);
        agregaPersonaje(Wuuf);
        agregaPersonaje(Rosa);
        agregaPersonaje(Clint);
        agregaPersonaje(Panoramix);

        agregaPersonaje(Enemigo1);
        agregaPersonaje(Enemigo2);

    }


    void JuegoMesa3::preparaHabilidades() {

        ataqueEspadaNormal = new Habilidad{
                L"Ataque cuerpo a cuerpo normal",
                EnfoqueHabilidad::personaje, AccesoHabilidad::directo,   Antagonista::oponente, Elemento::nulo };
        ataqueArco = new Habilidad{
                L"Ataque a distancia normal",
                EnfoqueHabilidad::personaje, AccesoHabilidad::directo,   Antagonista::oponente, Elemento::nulo };
        ataqueEspadaPoderoso = new Habilidad{
                L"Ataque poderoso",
                EnfoqueHabilidad::personaje, AccesoHabilidad::directo,   Antagonista::oponente, Elemento::Fuego };
        defensaFerrea = new Habilidad{
                L"Defensa férrea",
                EnfoqueHabilidad::si_mismo,  AccesoHabilidad::ninguno,   Antagonista::si_mismo, Elemento::nulo };
        curacionSimple = new Habilidad{
                L"Curación",
                EnfoqueHabilidad::personaje, AccesoHabilidad::directo,   Antagonista::aliado, Elemento::nulo };
        curacionGrupo = new Habilidad{
                L"Curación en grupo",
                EnfoqueHabilidad::area,      AccesoHabilidad::directo,   Antagonista::aliado, Elemento::nulo };

        //
        ataqueEspadaNormal->ponDescripcion(
            L"El personaje usa su espada para atacar a un enemigo que se encuentra en una casilla próxima.");
        ataqueArco->ponDescripcion(
            L"El personaje usa su arco para atacar a un enemigo que se encuentra en una casilla próxima.");
        ataqueEspadaPoderoso->ponDescripcion(
            L"El personaje blande su espada con fuerza para atacar a un enemigo que se encuentra en una casilla próxima.");
        defensaFerrea->ponDescripcion(
            L"El personaje aumenta su defensa hasta su próximo ronda.");
        curacionSimple->ponDescripcion(
            L"El personaje canaliza poder divino para sanar a un aliado.");
        curacionGrupo->ponDescripcion(
            L"El personaje canaliza poder divino para sanar a todos los personajes en un área.");

        //
        ataqueEspadaNormal->ponArchivosImagenes(
            carpeta_habilids_juego + "espada.png", carpeta_habilids_juego + "fondo_5.png");
        ataqueArco->ponArchivosImagenes(
            carpeta_habilids_juego + "arco_flecha.png", carpeta_habilids_juego + "fondo_5.png");
        ataqueEspadaPoderoso->ponArchivosImagenes(
            carpeta_habilids_juego + "espada_poderosa.png", carpeta_habilids_juego + "fondo_5.png");
        defensaFerrea->ponArchivosImagenes(
            carpeta_habilids_juego + "escudo.png", carpeta_habilids_juego + "fondo_5.png");
        curacionSimple->ponArchivosImagenes(
            carpeta_habilids_juego + "vela.png", carpeta_habilids_juego + "fondo_5.png");
        curacionGrupo->ponArchivosImagenes(
            carpeta_habilids_juego + "vela_triple.png", carpeta_habilids_juego + "fondo_5.png");

        //
        ataqueEspadaNormal->ponArchivoSonido(carpeta_sonidos_juego + "Magic Missiles.wav");
        ataqueArco->ponArchivoSonido(carpeta_sonidos_juego + "Magic Missiles.wav");
        ataqueEspadaPoderoso->ponArchivoSonido(carpeta_sonidos_juego + "Magic Missiles.wav");
        defensaFerrea->ponArchivoSonido(carpeta_sonidos_juego + "Magic Missiles.wav");
        curacionSimple->ponArchivoSonido(carpeta_sonidos_juego + "Magic Missiles.wav");
        curacionGrupo->ponArchivoSonido(carpeta_sonidos_juego + "Magic Missiles.wav");

        //
        agregaHabilidad(ataqueEspadaNormal);
        agregaHabilidad(ataqueArco);
        agregaHabilidad(ataqueEspadaPoderoso);
        agregaHabilidad(defensaFerrea);
        agregaHabilidad(curacionSimple);
        agregaHabilidad(curacionGrupo);


    }


    void JuegoMesa3::preparaTiposEstadisticas() {

        //
        ataqueCuerpoACuerpo = new TipoAtaque{ L"Ataque cuerpo a cuerpo" };
        ataqueADistancia = new TipoAtaque{ L"Ataque a distancia" };
        defensaCuerpoACuerpo = new TipoDefensa{ L"Defensa cuerpo a cuerpo" };
        defensaADistancia = new TipoDefensa{ L"Defensa a distancia" };
        danoFisico = new TipoDano{ L"Daño físico" };
        //
        agregaAtaque(ataqueCuerpoACuerpo);
        agregaAtaque(ataqueADistancia);
        agregaDefensa(defensaCuerpoACuerpo);
        agregaDefensa(defensaADistancia);
        agregaDano(danoFisico);

    }


    void JuegoMesa3::agregaHabilidadesPersonajes() {

        Guillermo->agregaHabilidad(ataqueEspadaNormal);
        Guillermo->agregaHabilidad(ataqueArco);
        Guillermo->agregaHabilidad(ataqueEspadaPoderoso);
        Guillermo->agregaHabilidad(defensaFerrea);


        Wuuf->agregaHabilidad(ataqueEspadaNormal);
        Wuuf->agregaHabilidad(ataqueArco);
        Wuuf->agregaHabilidad(ataqueEspadaPoderoso);
        Wuuf->agregaHabilidad(defensaFerrea);

        Rosa->agregaHabilidad(ataqueEspadaNormal);
        Rosa->agregaHabilidad(ataqueArco);
        Rosa->agregaHabilidad(ataqueEspadaPoderoso);
        Rosa->agregaHabilidad(defensaFerrea);

        Clint->agregaHabilidad(ataqueEspadaNormal);
        Clint->agregaHabilidad(ataqueArco);
        Clint->agregaHabilidad(ataqueEspadaPoderoso);
        Clint->agregaHabilidad(defensaFerrea);

        Panoramix->agregaHabilidad(ataqueEspadaNormal);
        Panoramix->agregaHabilidad(ataqueArco);
        Panoramix->agregaHabilidad(ataqueEspadaPoderoso);
        Panoramix->agregaHabilidad(defensaFerrea);

        //
        Enemigo1->agregaHabilidad(ataqueEspadaNormal);
        Enemigo1->agregaHabilidad(ataqueArco);
        Enemigo1->agregaHabilidad(ataqueEspadaPoderoso);
        Enemigo1->agregaHabilidad(defensaFerrea);


        Enemigo2->agregaHabilidad(ataqueEspadaNormal);
        Enemigo2->agregaHabilidad(ataqueArco);
        Enemigo2->agregaHabilidad(ataqueEspadaPoderoso);
        Enemigo2->agregaHabilidad(defensaFerrea);

    }


    void JuegoMesa3::agregaEstadisticasHabilidades() {

        //
        ataqueEspadaNormal->ponCoste(3);
        ataqueEspadaNormal->ponAlcance(1);
        ataqueEspadaNormal->asignaAtaque(ataqueCuerpoACuerpo);
        ataqueEspadaNormal->asignaDefensa(defensaCuerpoACuerpo);
        ataqueEspadaNormal->asignaDano(danoFisico, 20);
        //
        ataqueArco->ponCoste(5);
        ataqueArco->ponAlcance(15);
        ataqueArco->asignaAtaque(ataqueADistancia);
        ataqueArco->asignaDefensa(defensaADistancia);
        ataqueArco->asignaDano(danoFisico, 20);
        //
        ataqueEspadaPoderoso->ponCoste(5);
        ataqueEspadaPoderoso->ponAlcance(1);
        ataqueEspadaPoderoso->asignaAtaque(ataqueCuerpoACuerpo);
        ataqueEspadaPoderoso->asignaDefensa(defensaCuerpoACuerpo);
        ataqueEspadaPoderoso->asignaDano(danoFisico, 50);
        //
        defensaFerrea->ponCoste(3);
        defensaFerrea->agregaEfectoDefensa(defensaCuerpoACuerpo, 30);
        defensaFerrea->agregaEfectoDefensa(defensaADistancia, 30);
        //
        curacionSimple->ponCoste(5);
        curacionSimple->ponAlcance(3);
        curacionSimple->asignaCuracion(40);
        //
        curacionGrupo->ponCoste(10);
        curacionGrupo->ponAlcance(3);
        curacionGrupo->ponRadioAlcance(3);
        curacionGrupo->asignaCuracion(40);
        //

    }


    void JuegoMesa3::agregaEstadisticasPersonajes() {

        //
        Guillermo->agregaAtaque(ataqueCuerpoACuerpo, 70);
        Guillermo->agregaAtaque(ataqueADistancia, 50);
        Guillermo->agregaDefensa(defensaCuerpoACuerpo, 70);
        Guillermo->agregaDefensa(defensaADistancia, 70);
        Guillermo->agregaReduceDano(danoFisico, 10);

        Wuuf->agregaAtaque(ataqueCuerpoACuerpo, 70);
        Wuuf->agregaAtaque(ataqueADistancia, 50);
        Wuuf->agregaDefensa(defensaCuerpoACuerpo, 70);
        Wuuf->agregaDefensa(defensaADistancia, 70);
        Wuuf->agregaReduceDano(danoFisico, 10);

        Rosa->agregaAtaque(ataqueCuerpoACuerpo, 70);
        Rosa->agregaAtaque(ataqueADistancia, 50);
        Rosa->agregaDefensa(defensaCuerpoACuerpo, 70);
        Rosa->agregaDefensa(defensaADistancia, 70);
        Rosa->agregaReduceDano(danoFisico, 10);

        Clint->agregaAtaque(ataqueCuerpoACuerpo, 70);
        Clint->agregaAtaque(ataqueADistancia, 50);
        Clint->agregaDefensa(defensaCuerpoACuerpo, 70);
        Clint->agregaDefensa(defensaADistancia, 70);
        Clint->agregaReduceDano(danoFisico, 10);

        Panoramix->agregaAtaque(ataqueCuerpoACuerpo, 70);
        Panoramix->agregaAtaque(ataqueADistancia, 50);
        Panoramix->agregaDefensa(defensaCuerpoACuerpo, 70);
        Panoramix->agregaDefensa(defensaADistancia, 70);
        Panoramix->agregaReduceDano(danoFisico, 10);

        //

        //                       
        Enemigo1->agregaAtaque(ataqueCuerpoACuerpo, 70);
        Enemigo1->agregaAtaque(ataqueADistancia, 50);
        Enemigo1->agregaDefensa(defensaCuerpoACuerpo, 70);
        Enemigo1->agregaDefensa(defensaADistancia, 70);
        Enemigo1->agregaReduceDano(danoFisico, 10);

        Enemigo2->agregaAtaque(ataqueCuerpoACuerpo, 70);
        Enemigo2->agregaAtaque(ataqueADistancia, 50);
        Enemigo2->agregaDefensa(defensaCuerpoACuerpo, 70);
        Enemigo2->agregaDefensa(defensaADistancia, 70);
        Enemigo2->agregaReduceDano(danoFisico, 10);
        //                       


    }


    void JuegoMesa3::preparaSistemaAtaque() {

        //
        GradoEfectividad* fallo = new GradoEfectividad{ L"Fallo" };
        GradoEfectividad* roce = new GradoEfectividad{ L"Roce" };
        GradoEfectividad* impacto = new GradoEfectividad{ L"Impacto" };
        GradoEfectividad* critico = new GradoEfectividad{ L"Impacto crítico" };
        //
        fallo->estableceRango(INT_MIN, 9, 0);
        roce->estableceRango(10, 49, 50);
        impacto->estableceRango(50, 89, 100);
        critico->estableceRango(90, INT_MAX, 150);
        //
        agregaEfectividad(fallo);
        agregaEfectividad(roce);
        agregaEfectividad(impacto);
        agregaEfectividad(critico);

    }


    void JuegoMesa3::configuraJuego() {
        agregaMusica(new ActorMusica{ this });

        modo()->configuraDesplaza(RejillaTablero::distanciaCeldas);
        //
        Guillermo->ponSitioFicha(Coord{ 1,1 });
        Wuuf->ponSitioFicha(Coord{ 3,1 });
        Rosa->ponSitioFicha(Coord{ 5,1 });
        Clint->ponSitioFicha(Coord{ 7,1 });
        Panoramix->ponSitioFicha(Coord{ 9,1 });

        Enemigo1->ponSitioFicha(Coord{ 5,17 });
        Enemigo2->ponSitioFicha(Coord{ 9,17 });

        //
        tablero()->asignaSonidoEstablece(carpeta_sonidos_juego + "Metal Click.wav", 100);
        tablero()->asignaSonidoDesplaza(carpeta_sonidos_juego + "SnowWalk.ogg", 100);
        musica()->asignaMusica(carpeta_sonidos_juego + "Track_1.ogg", 100);
        //
        agregaNombreAlumno(L"Maksym Chernykh");
        agregaNombreAlumno(L"Aike Fernández Roza");
        agregaNombreAlumno(L"Julián Guérrez Losada");
        agregaNombreAlumno(L"Carlos Pablos Rivero");
        agregaNombreAlumno(L"Vidal Rodrigo Mínguez");
        indicaCursoAcademico(L"2024 - 2025");

    }


    void JuegoMesa3::termina() {
        //
        // JuegoMesaBase::termina();
        //
        Guillermo = nullptr;
        Wuuf = nullptr;
        Rosa = nullptr;
        Clint = nullptr;
        Panoramix = nullptr;
        Enemigo1 = nullptr;
        Enemigo2 = nullptr;

        //
        ataqueEspadaNormal = nullptr;
        ataqueArco = nullptr;
        ataqueEspadaPoderoso = nullptr;
        defensaFerrea = nullptr;
        curacionSimple = nullptr;
        curacionGrupo = nullptr;

        //
        ataqueCuerpoACuerpo = nullptr;
        ataqueADistancia = nullptr;
        defensaCuerpoACuerpo = nullptr;
        defensaADistancia = nullptr;
        danoFisico = nullptr;
    }


}