// proyecto: Grupal/Tapete
// arhivo:   CuadroIndica.cpp
// versión:  1.1  (9-Ene-2023)


#include "tapete.h"


namespace tapete {


    CuadroNiveles::CuadroNiveles(ActorTablero* actor_tablero) {
        this->actor_tablero = actor_tablero;
    }

    CuadroNiveles::~CuadroNiveles() {
        actor_tablero = nullptr;
    }


    void CuadroNiveles::prepara() {

        rectangl_indica = new unir2d::Rectangulo();
        rectangl_indica->ponIndiceZ(2);
        rectangl_indica->ponVisible(true);

        actor_tablero->agregaDibujo(rectangl_indica);
       
        rectangl_indica->ponPosicion(Vector {0 , 0});
        rectangl_indica->ponBase(PresenciaTablero::tamanoTablero.x());
        rectangl_indica->ponAltura(PresenciaTablero::tamanoTablero.y());

        rectangl_indica->ponColor(colorNiveles);


        // Nivel 1
        rectangl_n1 = new unir2d::Rectangulo();
        rectangl_n1->ponIndiceZ(2);
        rectangl_n1->ponVisible(true);

       // actor_tablero->agregaDibujo(rectangl_n1);

        rectangl_n1->ponPosicion(Vector{ 142 , 250 });
        rectangl_n1->ponBase(285);
        rectangl_n1->ponAltura(285);
        rectangl_n1->ponColor(colorNivel);


        texturaNivel1 = new unir2d::Textura();
        texturaNivel1->carga(JuegoMesaBase::carpetaActivos() + "level1.png");

        imgNivel1 = new unir2d::Imagen();
        imgNivel1->asigna(texturaNivel1);
        imgNivel1->ponIndiceZ(2);
        imgNivel1->ponPosicion(Vector{ 142 , 250 });

        actor_tablero->agregaDibujo(imgNivel1);

        // Nivel 2
        rectangl_n2 = new unir2d::Rectangulo();
        rectangl_n2->ponIndiceZ(2);
        rectangl_n2->ponVisible(true);

       // actor_tablero->agregaDibujo(rectangl_n2);

        rectangl_n2->ponPosicion(Vector{ 712 , 250 });
        rectangl_n2->ponBase(285);
        rectangl_n2->ponAltura(285);
        rectangl_n2->ponColor(colorNivel);


        texturaNivel2 = new unir2d::Textura();
        texturaNivel2->carga(JuegoMesaBase::carpetaActivos() + "level2.png");

        imgNivel2 = new unir2d::Imagen();
        imgNivel2->asigna(texturaNivel2);
        imgNivel2->ponIndiceZ(2);
        imgNivel2->ponPosicion(Vector{ 712 , 250 });

        actor_tablero->agregaDibujo(imgNivel2);

        // Nivel 3
        rectangl_n3 = new unir2d::Rectangulo();
        rectangl_n3->ponIndiceZ(2);
        rectangl_n3->ponVisible(true);

      // actor_tablero->agregaDibujo(rectangl_n3);

        rectangl_n3->ponPosicion(Vector{ 1282 , 250 });
        rectangl_n3->ponBase(285);
        rectangl_n3->ponAltura(285);
        rectangl_n3->ponColor(colorNivel);


        texturaNivel3 = new unir2d::Textura();
        texturaNivel3->carga(JuegoMesaBase::carpetaActivos() + "level3.png");

        imgNivel3 = new unir2d::Imagen();
        imgNivel3->asigna(texturaNivel3);
        imgNivel3->ponIndiceZ(2);
        imgNivel3->ponPosicion(Vector{ 1282 , 250 });

        actor_tablero->agregaDibujo(imgNivel3);

        // Nivel 4
        rectangl_n4 = new unir2d::Rectangulo();
        rectangl_n4->ponIndiceZ(2);
        rectangl_n4->ponVisible(true);

      //  actor_tablero->agregaDibujo(rectangl_n4);

        rectangl_n4->ponPosicion(Vector{ 427 , 550 });
        rectangl_n4->ponBase(285);
        rectangl_n4->ponAltura(285);
        rectangl_n4->ponColor(colorNivel);


        texturaNivel4 = new unir2d::Textura();
        texturaNivel4->carga(JuegoMesaBase::carpetaActivos() + "level4.png");

        imgNivel4 = new unir2d::Imagen();
        imgNivel4->asigna(texturaNivel4);
        imgNivel4->ponIndiceZ(2);
        imgNivel4->ponPosicion(Vector{ 427 , 550 });

        actor_tablero->agregaDibujo(imgNivel4);

        // Nivel 5
        rectangl_n5 = new unir2d::Rectangulo();
        rectangl_n5->ponIndiceZ(2);
        rectangl_n5->ponVisible(true);

      //  actor_tablero->agregaDibujo(rectangl_n5);

        rectangl_n5->ponPosicion(Vector{ 997 , 550 });
        rectangl_n5->ponBase(285);
        rectangl_n5->ponAltura(285);
        rectangl_n5->ponColor(colorNivel);


        texturaNivel5 = new unir2d::Textura();
        texturaNivel5->carga(JuegoMesaBase::carpetaActivos() + "level5.png");

        imgNivel5 = new unir2d::Imagen();
        imgNivel5->asigna(texturaNivel5);
        imgNivel5->ponIndiceZ(2);
        imgNivel5->ponPosicion(Vector{ 997 , 550 });

        actor_tablero->agregaDibujo(imgNivel5);


        unir2d::Textura *texturaJerarquia = new unir2d::Textura();
        texturaJerarquia->carga(JuegoMesaBase::carpetaActivos() + "jerarquia.png");

        unir2d::Imagen *imgJerarquia = new unir2d::Imagen();
        imgJerarquia->asigna(texturaJerarquia);
        imgJerarquia->ponIndiceZ(2);
        imgJerarquia->ponPosicion(Vector{ 1500 , 780 });

        actor_tablero->agregaDibujo(imgJerarquia);


        unir2d::Textura* texturaLogo = new unir2d::Textura();
        texturaLogo->carga(JuegoMesaBase::carpetaActivos() + "logo.png");

        unir2d::Imagen* imgLogo = new unir2d::Imagen();
        imgLogo->asigna(texturaLogo);
        imgLogo->ponIndiceZ(2);
        imgLogo->ponPosicion(Vector{ 0 , 850 });

        actor_tablero->agregaDibujo(imgLogo);


        unir2d::Textura* texturaTitulo = new unir2d::Textura();
        texturaTitulo->carga(JuegoMesaBase::carpetaActivos() + "fondo_niveles.png");

        unir2d::Imagen* imgTitulo = new unir2d::Imagen();
        imgTitulo->asigna(texturaTitulo);
        imgTitulo->ponIndiceZ(2);
        imgTitulo->ponPosicion(Vector{ 0 , 10 });

        actor_tablero->agregaDibujo(imgTitulo);
        

    }


    void CuadroNiveles::libera() {
        delete rectangl_indica;
        rectangl_indica = nullptr;

        delete rectangl_n1;
        rectangl_n1 = nullptr;
        delete texturaNivel1;
        texturaNivel1 = nullptr;
        delete imgNivel1;
        imgNivel1 = nullptr;

        delete rectangl_n2;
        rectangl_n2 = nullptr;
        delete texturaNivel2;
        texturaNivel2 = nullptr;
        delete imgNivel2;
        imgNivel2 = nullptr;

        delete rectangl_n3;
        rectangl_n3 = nullptr;
        delete texturaNivel3;
        texturaNivel3 = nullptr;
        delete imgNivel3;
        imgNivel3 = nullptr;

        delete rectangl_n4;
        rectangl_n4 = nullptr;
        delete texturaNivel4;
        texturaNivel4 = nullptr;
        delete imgNivel4;
        imgNivel4 = nullptr;

        delete rectangl_n5;
        rectangl_n5 = nullptr;
        delete texturaNivel5;
        texturaNivel5 = nullptr;
        delete imgNivel5;
        imgNivel5 = nullptr;

    }


    void CuadroNiveles::indica(Vector poscn, const wstring& cadena) {

    }


    void CuadroNiveles::desindica() {
        rectangl_indica->ponVisible(false);
    }


}