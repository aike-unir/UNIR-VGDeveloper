// proyecto: Grupal/Tapete
// archivo:  CuadroIndica.h
// versión:  1.1  (9-Ene-2023)


#pragma once


namespace tapete {


    class ActorTablero;


    class CuadroNiveles {
    public:

        void prepara();
        void libera();

        void indica(Vector poscn, const wstring& cadena);
        void desindica();

    private:

        static constexpr Color colorNiveles{ 239, 228, 176, 255 };
        static constexpr Color colorNivel{ 100, 100, 100, 255 };


        ActorTablero* actor_tablero;

        unir2d::Rectangulo* rectangl_indica{};

        unir2d::Rectangulo* rectangl_n1{};
        unir2d::Textura* texturaNivel1{};
        unir2d::Imagen* imgNivel1{};

        unir2d::Rectangulo* rectangl_n2{};
        unir2d::Textura* texturaNivel2{};
        unir2d::Imagen* imgNivel2{};

        unir2d::Rectangulo* rectangl_n3{};
        unir2d::Textura* texturaNivel3{};
        unir2d::Imagen* imgNivel3{};

        unir2d::Rectangulo* rectangl_n4{};
        unir2d::Textura* texturaNivel4{};
        unir2d::Imagen* imgNivel4{};

        unir2d::Rectangulo* rectangl_n5{};
        unir2d::Textura* texturaNivel5{};
        unir2d::Imagen* imgNivel5{};


        explicit CuadroNiveles(ActorTablero* actor_tablero);
        ~CuadroNiveles();


        friend class ActorTablero;

    };


}


