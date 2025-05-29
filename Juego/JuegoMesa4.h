// proyecto: Grupal/Juego
// arhivo:   JuegoMesa.h
// versión:  1.1  (9-Ene-2023)


#pragma once


namespace juego4 {


    class JuegoMesa4 : public JuegoMesaBase {
    public:

        JuegoMesa4();

    private:

        ActorPersonaje* Guillermo{};
        ActorPersonaje* Wuuf{};
        ActorPersonaje* Rosa{};
        ActorPersonaje* Clint{};
        ActorPersonaje* Panoramix{};

        ActorPersonaje* CoyoteTormenta{};
        ActorPersonaje* CoyoteTormenta2{};



        Habilidad* ataqueEspadaNormal{};
        Habilidad* ataqueArco{};
        Habilidad* ataqueEspadaPoderoso{};
        Habilidad* defensaFerrea{};
        Habilidad* curacionSimple{};
        Habilidad* curacionGrupo{};
		Habilidad* revolverVeloz{};



        TipoAtaque* ataqueCuerpoACuerpo{};
        TipoAtaque* ataqueADistancia{};
        TipoDefensa* defensaCuerpoACuerpo{};
        TipoDefensa* defensaADistancia{};
        TipoDano* danoFisico{};

        GradoEfectividad* fallo{};
        GradoEfectividad* roce{};
        GradoEfectividad* impacto{};
        GradoEfectividad* critico{};


    private:

        static string carpeta_activos_juego;
        static string carpeta_retratos_juego;
        static string carpeta_habilids_juego;
        static string carpeta_sonidos_juego;

        const std::wstring tituloVentana() const override;

        void preparaTablero() override;
        void preparaPersonajes() override;
        void preparaHabilidades() override;
        void preparaTiposEstadisticas() override;
        void agregaHabilidadesPersonajes() override;
        void agregaEstadisticasHabilidades() override;
        void agregaEstadisticasPersonajes() override;
        void preparaSistemaAtaque() override;
        void configuraJuego() override;
        void termina() override;

    };


}


