// proyecto: Grupal/Juego
// arhivo:   JuegoMesa.cpp
// versi�n:  1.1  (9-Ene-2023)


#include "juego.h"


namespace juego4 {

    string JuegoMesa4::carpeta_activos_juego{ "./activos/" };
    string JuegoMesa4::carpeta_retratos_juego{ "./retratos/" };
    string JuegoMesa4::carpeta_habilids_juego{ "./habilidades/" };
    string JuegoMesa4::carpeta_sonidos_juego{ "./sonidos/" };


    const std::wstring JuegoMesa4::tituloVentana() const {
        return L"Nivel 4 - Salvaje Oeste";
    }


    JuegoMesa4::JuegoMesa4() {
        ModoJuegoEquipo* modo = new ModoJuegoEquipo{ this };
        SucesosJuegoEquipo* sucesos = new SucesosJuegoEquipo{ this, modo };

        JuegoMesaBase::configura(sucesos, modo);
    }



    static ActorTablero::GraficoMuros grafico_muros_vacio{
        "-     -     -     -     -     -     T     -     -",
        "   -     -     T     O     -     -     -     -   ",
        "-     -     -     -     -     -     O     O     -",
        "   -     -     -     O     -     -     -     O   ",
        "-     -     O     -     -     -     O     -     -",
        "   -     O     O     -     -     -     -     O   ",
        "-     -     O     -     -     -     -     -     -",
        "   -     -     -     -     -     -     T     O   ",
        "-     -     -     -     -     -     O     -     -",
        "   -     T     O     -     O     -     O     O   ",
        "-     -     O     O     O     -     O     -     -",
        "   -     O     O     O     O     -     O     -   ",
        "-     O     O     O     O     -     -     -     -" };



    void JuegoMesa4::preparaTablero() {
        agregaTablero(new ActorTablero(this));

        tablero()->ponArchivoMuro(carpeta_activos_juego + "muro_piedra2.png");
        tablero()->ponArchivoBaldosas(carpeta_activos_juego + "estampa_desierto.png");
       // tablero()->ponArchivoBaldosas(carpeta_activos_juego + "estampas_fondo.png");

        tablero()->ponArchivoFondo(carpeta_activos_juego + "FondoDesierto.png");

        tablero()->equipa(LadoTablero::Izquierda, L"Devils", carpeta_activos_juego + "escudo_devils.png");
        tablero()->equipa(LadoTablero::Derecha, L"Tusk", carpeta_activos_juego + "escudo_tusk.png");

        tablero()->situaMuros(grafico_muros_vacio);

    }


    void JuegoMesa4::preparaPersonajes() {

        Guillermo = new ActorPersonaje{ this, LadoTablero::Izquierda, 0, L"Guillermo" , Elemento::Fuego };
        Wuuf = new ActorPersonaje{ this, LadoTablero::Izquierda, 1, L"Wuuf", Elemento::Hielo };
        Rosa = new ActorPersonaje{ this, LadoTablero::Izquierda, 2, L"Rosa", Elemento::Rayo };
        Clint = new ActorPersonaje{ this, LadoTablero::Izquierda, 3, L"Clint", Elemento::Piedra };

        CoyoteTormenta = new ActorPersonaje{ this, LadoTablero::Derecha,   0, L"Coyote", Elemento::Rayo };
        CoyoteTormenta2 = new ActorPersonaje{ this, LadoTablero::Derecha,   1, L"Coyote", Elemento::Rayo };


        //
        Guillermo->ponArchivoRetrato(carpeta_retratos_juego + "guillermo_retrato.png");
        Wuuf->ponArchivoRetrato(carpeta_retratos_juego + "male1_75.png");
        Rosa->ponArchivoRetrato(carpeta_retratos_juego + "male1_75.png");
        Clint->ponArchivoRetrato(carpeta_retratos_juego + "retrato_clint.png");

        CoyoteTormenta->ponArchivoRetrato(carpeta_retratos_juego + "retrato_coyote_rayo.png");
        CoyoteTormenta2->ponArchivoRetrato(carpeta_retratos_juego + "retrato_coyote_rayo.png");

        //
        Guillermo->ponArchivoFicha(carpeta_retratos_juego + "guillermo_idle.png");
        Wuuf->ponArchivoFicha(carpeta_retratos_juego + "sprite1.png");
        Rosa->ponArchivoFicha(carpeta_retratos_juego + "sprite1.png");
        Clint->ponArchivoFicha(carpeta_retratos_juego + "Clint.png");

        CoyoteTormenta->ponArchivoFicha(carpeta_retratos_juego + "coyote_rayo.png");
        CoyoteTormenta2->ponArchivoFicha(carpeta_retratos_juego + "coyote_rayo.png");

        //
        Guillermo->ponIniciativa(20);
        Wuuf->ponIniciativa(18);
        Rosa->ponIniciativa(16);
        Clint->ponIniciativa(15);

        CoyoteTormenta->ponIniciativa(19);
        CoyoteTormenta2->ponIniciativa(17);

        //
        agregaPersonaje(Guillermo);
        agregaPersonaje(Wuuf);
        agregaPersonaje(Rosa);
        agregaPersonaje(Clint);

        agregaPersonaje(CoyoteTormenta);
        agregaPersonaje(CoyoteTormenta2);

    }


    void JuegoMesa4::preparaHabilidades() {

        ataqueEspadaNormal = new Habilidad{
                L"Ataque cuerpo a cuerpo normal",
                EnfoqueHabilidad::personaje, AccesoHabilidad::directo,   Antagonista::oponente, Elemento::nulo };
        ataqueArco = new Habilidad{
                L"Ataque a distancia normal",
                EnfoqueHabilidad::personaje, AccesoHabilidad::directo,   Antagonista::oponente, Elemento::nulo };
        ataqueEspadaPoderoso = new Habilidad{
                L"Ataque poderoso de hielo",
                EnfoqueHabilidad::personaje, AccesoHabilidad::directo,   Antagonista::oponente, Elemento::Hielo };
        llamarada = new Habilidad{
              L"Ataque poderoso de fuego",
              EnfoqueHabilidad::personaje, AccesoHabilidad::directo,   Antagonista::oponente, Elemento::Fuego };
        defensaFerrea = new Habilidad{
                L"Defensa f�rrea",
                EnfoqueHabilidad::si_mismo,  AccesoHabilidad::ninguno,   Antagonista::si_mismo, Elemento::nulo };
        curacionSimple = new Habilidad{
                L"Curaci�n",
                EnfoqueHabilidad::personaje, AccesoHabilidad::directo,   Antagonista::aliado, Elemento::nulo };
        curacionGrupo = new Habilidad{
                L"Curaci�n en grupo",
                EnfoqueHabilidad::area,      AccesoHabilidad::directo,   Antagonista::aliado, Elemento::nulo };
		revolverVeloz = new Habilidad{
				L"Revolver veloz",
				EnfoqueHabilidad::personaje, AccesoHabilidad::directo, Antagonista::oponente, Elemento::Piedra };
		ataquePunal = new Habilidad{
				L"Ataque cuerpo a cuerpo con puñal",
				EnfoqueHabilidad::personaje, AccesoHabilidad::directo,   Antagonista::oponente, Elemento::nulo };
		ataqueGarraRelampago = new Habilidad{
				L"Ataque cuerpo a cuerpo con garra relampago",
				EnfoqueHabilidad::personaje, AccesoHabilidad::directo,   Antagonista::oponente, Elemento::Rayo };
		ataqueMordiscoTormenta = new Habilidad{
			L"Ataque cuerpo a cuerpo con mordisco tormenta",
			EnfoqueHabilidad::personaje, AccesoHabilidad::directo,   Antagonista::oponente, Elemento::Hielo };

        //
        ataqueEspadaNormal->ponDescripcion(
            L"El personaje usa su espada para atacar a un enemigo que se encuentra en una casilla pr�xima.");
        ataqueArco->ponDescripcion(
            L"El personaje usa su arco para atacar a un enemigo que se encuentra en una casilla pr�xima.");
        ataqueEspadaPoderoso->ponDescripcion(
            L"El personaje blande su espada con fuerza para atacar a un enemigo que se encuentra en una casilla pr�xima.");
        llamarada->ponDescripcion(
            L"El personaje lanza fuego para atacar a un enemigo que se encuentra en una casilla próxima.");
        defensaFerrea->ponDescripcion(
            L"El personaje aumenta su defensa hasta su pr�ximo ronda.");
        curacionSimple->ponDescripcion(
            L"El personaje canaliza poder divino para sanar a un aliado.");
        curacionGrupo->ponDescripcion(
            L"El personaje canaliza poder divino para sanar a todos los personajes en un �rea.");
		revolverVeloz->ponDescripcion(
			L"El personaje dispara r�pidamente con su revolver a un enemigo que se encuentra en una casilla pr�xima.");
		ataquePunal->ponDescripcion(
			L"El personaje usa su puñal para atacar a un enemigo que se encuentra en una casilla pr�xima.");
		ataqueGarraRelampago->ponDescripcion(
			L"El personaje utiliza sus afiladas garras imbuidas en rayo para atacar.");
		ataqueMordiscoTormenta->ponDescripcion(
			L"El personaje utiliza su poderoso mordisco de tormenta para atacar a un enemigo que se encuentra en una casilla pr�xima.");

        //
        ataqueEspadaNormal->ponArchivosImagenes(
            carpeta_habilids_juego + "espada.png", carpeta_habilids_juego + "fondo_5.png");
        ataqueArco->ponArchivosImagenes(
            carpeta_habilids_juego + "arco_flecha.png", carpeta_habilids_juego + "fondo_5.png");
        ataqueEspadaPoderoso->ponArchivosImagenes(
            carpeta_habilids_juego + "espada_poderosa.png", carpeta_habilids_juego + "fondo_hielo.png");
        llamarada->ponArchivosImagenes(
            carpeta_habilids_juego + "llamarada.png", carpeta_habilids_juego + "fondo_fuego.png");
        defensaFerrea->ponArchivosImagenes(
            carpeta_habilids_juego + "escudo.png", carpeta_habilids_juego + "fondo_5.png");
        curacionSimple->ponArchivosImagenes(
            carpeta_habilids_juego + "vela.png", carpeta_habilids_juego + "fondo_5.png");
        curacionGrupo->ponArchivosImagenes(
            carpeta_habilids_juego + "vela_triple.png", carpeta_habilids_juego + "fondo_5.png");
		revolverVeloz->ponArchivosImagenes(
			carpeta_habilids_juego + "revolver.png", carpeta_habilids_juego + "fondo_tierra.png");
		ataquePunal->ponArchivosImagenes(
			carpeta_habilids_juego + "puñal.png", carpeta_habilids_juego + "fondo_5.png");
		ataqueGarraRelampago->ponArchivosImagenes(
			carpeta_habilids_juego + "garra_relampago.png", carpeta_habilids_juego + "fondo_rayo.png");
		ataqueMordiscoTormenta->ponArchivosImagenes(
			carpeta_habilids_juego + "mordisco_tormenta.png", carpeta_habilids_juego + "fondo_hielo.png");

        //
        ataqueEspadaNormal->ponArchivoSonido(carpeta_sonidos_juego + "sword.wav");
        ataqueArco->ponArchivoSonido(carpeta_sonidos_juego + "arrow.wav");
        ataqueEspadaPoderoso->ponArchivoSonido(carpeta_sonidos_juego + "sword.wav");
        llamarada->ponArchivoSonido(carpeta_sonidos_juego + "arrowFire.wav");
        defensaFerrea->ponArchivoSonido(carpeta_sonidos_juego + "Magic Missiles.wav");
        curacionSimple->ponArchivoSonido(carpeta_sonidos_juego + "Magic Missiles.wav");
        curacionGrupo->ponArchivoSonido(carpeta_sonidos_juego + "Magic Missiles.wav");
		revolverVeloz->ponArchivoSonido(carpeta_sonidos_juego + "shoot.wav");
		ataquePunal->ponArchivoSonido(carpeta_sonidos_juego + "sword.wav");
		ataqueGarraRelampago->ponArchivoSonido(carpeta_sonidos_juego + "Magic Missiles.wav");
		ataqueMordiscoTormenta->ponArchivoSonido(carpeta_sonidos_juego + "Magic Missiles.wav");

        //
        agregaHabilidad(ataqueEspadaNormal);
        agregaHabilidad(ataqueArco);
        agregaHabilidad(ataqueEspadaPoderoso);
        agregaHabilidad(llamarada);
        agregaHabilidad(defensaFerrea);
        agregaHabilidad(curacionSimple);
        agregaHabilidad(curacionGrupo);
		agregaHabilidad(revolverVeloz);
		agregaHabilidad(ataquePunal);
		agregaHabilidad(ataqueGarraRelampago);
		agregaHabilidad(ataqueMordiscoTormenta);


    }


    void JuegoMesa4::preparaTiposEstadisticas() {

        //
        ataqueCuerpoACuerpo = new TipoAtaque{ L"Ataque cuerpo a cuerpo" };
        ataqueADistancia = new TipoAtaque{ L"Ataque a distancia" };
        defensaCuerpoACuerpo = new TipoDefensa{ L"Defensa cuerpo a cuerpo" };
        defensaADistancia = new TipoDefensa{ L"Defensa a distancia" };
        danoFisico = new TipoDano{ L"Da�o f�sico" };
        //
        agregaAtaque(ataqueCuerpoACuerpo);
        agregaAtaque(ataqueADistancia);
        agregaDefensa(defensaCuerpoACuerpo);
        agregaDefensa(defensaADistancia);
        agregaDano(danoFisico);

    }


    void JuegoMesa4::agregaHabilidadesPersonajes() {

        Guillermo->agregaHabilidad(ataqueEspadaNormal);
        Guillermo->agregaHabilidad(ataqueArco);
        Guillermo->agregaHabilidad(ataqueEspadaPoderoso);
        Guillermo->agregaHabilidad(defensaFerrea);
        Guillermo->agregaHabilidad(llamarada);


        Wuuf->agregaHabilidad(ataqueEspadaNormal);
        Wuuf->agregaHabilidad(ataqueArco);
        Wuuf->agregaHabilidad(ataqueEspadaPoderoso);
        Wuuf->agregaHabilidad(defensaFerrea);

        Rosa->agregaHabilidad(ataqueEspadaNormal);
        Rosa->agregaHabilidad(ataqueArco);
        Rosa->agregaHabilidad(ataqueEspadaPoderoso);
        Rosa->agregaHabilidad(defensaFerrea);

        Clint->agregaHabilidad(ataquePunal);
        Clint->agregaHabilidad(defensaFerrea);
        Clint->agregaHabilidad(revolverVeloz);


        //
		CoyoteTormenta->agregaHabilidad(ataqueGarraRelampago);
		CoyoteTormenta->agregaHabilidad(ataqueMordiscoTormenta);

        CoyoteTormenta2->agregaHabilidad(ataqueGarraRelampago);
		CoyoteTormenta2->agregaHabilidad(ataqueMordiscoTormenta);
        
    }


    void JuegoMesa4::agregaEstadisticasHabilidades() {

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
        llamarada->ponCoste(5);
        llamarada->ponAlcance(1);
        llamarada->asignaAtaque(ataqueCuerpoACuerpo);
        llamarada->asignaDefensa(defensaCuerpoACuerpo);
        llamarada->asignaDano(danoFisico, 50);
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
		revolverVeloz->ponCoste(7);
		revolverVeloz->ponAlcance(15);
		revolverVeloz->asignaAtaque(ataqueADistancia);
		revolverVeloz->asignaDefensa(defensaADistancia);
        revolverVeloz->asignaDano(danoFisico, 30);
        //
		ataquePunal->ponCoste(3);
		ataquePunal->ponAlcance(1);
		ataquePunal->asignaAtaque(ataqueCuerpoACuerpo);
		ataquePunal->asignaDefensa(defensaCuerpoACuerpo);
		ataquePunal->asignaDano(danoFisico, 18);
		//
		ataqueGarraRelampago->ponCoste(5);
		ataqueGarraRelampago->ponAlcance(1);
		ataqueGarraRelampago->asignaAtaque(ataqueCuerpoACuerpo);
		ataqueGarraRelampago->asignaDefensa(defensaCuerpoACuerpo);
		ataqueGarraRelampago->asignaDano(danoFisico, 25);
		//
		ataqueMordiscoTormenta->ponCoste(10);
		ataqueMordiscoTormenta->ponAlcance(1);
		ataqueMordiscoTormenta->asignaAtaque(ataqueCuerpoACuerpo);
		ataqueMordiscoTormenta->asignaDefensa(defensaCuerpoACuerpo);
		ataqueMordiscoTormenta->asignaDano(danoFisico, 35);
		//

    }


    void JuegoMesa4::agregaEstadisticasPersonajes() {

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


        //

        //                       
        CoyoteTormenta->agregaAtaque(ataqueCuerpoACuerpo, 70);
        CoyoteTormenta->agregaAtaque(ataqueADistancia, 50);
        CoyoteTormenta->agregaDefensa(defensaCuerpoACuerpo, 55);
        CoyoteTormenta->agregaDefensa(defensaADistancia, 30);
        CoyoteTormenta->agregaReduceDano(danoFisico, 10);

        CoyoteTormenta2->agregaAtaque(ataqueCuerpoACuerpo, 70);
        CoyoteTormenta2->agregaAtaque(ataqueADistancia, 50);
        CoyoteTormenta2->agregaDefensa(defensaCuerpoACuerpo, 55);
        CoyoteTormenta2->agregaDefensa(defensaADistancia, 30);
        CoyoteTormenta2->agregaReduceDano(danoFisico, 10);
        //                       


    }


    void JuegoMesa4::preparaSistemaAtaque() {

        //
        GradoEfectividad* fallo = new GradoEfectividad{ L"Fallo" };
        GradoEfectividad* roce = new GradoEfectividad{ L"Roce" };
        GradoEfectividad* impacto = new GradoEfectividad{ L"Impacto" };
        GradoEfectividad* critico = new GradoEfectividad{ L"Impacto cr�tico" };
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


    void JuegoMesa4::configuraJuego() {
        agregaMusica(new ActorMusica{ this });

        modo()->configuraDesplaza(RejillaTablero::distanciaCeldas);
        //
        Guillermo->ponSitioFicha(Coord{ 1,1 });
        Wuuf->ponSitioFicha(Coord{ 5,1 });
        Rosa->ponSitioFicha(Coord{ 9,1 });
        Clint->ponSitioFicha(Coord{ 13,1 });

        CoyoteTormenta->ponSitioFicha(Coord{ 5,17 });
        CoyoteTormenta2->ponSitioFicha(Coord{ 9,17 });


        //
        tablero()->asignaSonidoEstablece(carpeta_sonidos_juego + "Metal Click.wav", 100);
        tablero()->asignaSonidoDesplaza(carpeta_sonidos_juego + "SnowWalk.ogg", 100);
        musica()->asignaMusica(carpeta_sonidos_juego + "track_desierto.ogg", 50);
        //
        agregaNombreAlumno(L"Maksym Chernykh");
        agregaNombreAlumno(L"Aike Fern�ndez Roza");
        agregaNombreAlumno(L"Juli�n Gu�rrez Losada");
        agregaNombreAlumno(L"Carlos Pablos Rivero");
        agregaNombreAlumno(L"Vidal Rodrigo M�nguez");
        indicaCursoAcademico(L"2024 - 2025");

    }


    void JuegoMesa4::termina() {
        //
       // JuegoMesaBase::termina();
        //
        Guillermo = nullptr;
        Wuuf = nullptr;
        Rosa = nullptr;
        Clint = nullptr;
        CoyoteTormenta = nullptr;
        CoyoteTormenta2 = nullptr;

        //
        ataqueEspadaNormal = nullptr;
        ataqueArco = nullptr;
        ataqueEspadaPoderoso = nullptr;
        llamarada = nullptr;
        defensaFerrea = nullptr;
        curacionSimple = nullptr;
        curacionGrupo = nullptr;
		revolverVeloz = nullptr;

        //
        ataqueCuerpoACuerpo = nullptr;
        ataqueADistancia = nullptr;
        defensaCuerpoACuerpo = nullptr;
        defensaADistancia = nullptr;
        danoFisico = nullptr;
    }


}