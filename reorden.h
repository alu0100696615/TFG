#ifndef REORDEN_H
#define REORDEN_H



#include <QWidget>
#include <QGridLayout>
#include <QDialog>
#include "reescritura.h"




class QDataWidgetMapper;
class QLabel;
class QLineEdit;
class QPushButton;
class QSpinBox;
class QGroupBox;
class QStandardItemModel;
class QTextEdit;
class Reescritura;


class Reorden : public QWidget
{


public:
    Reorden(int ta, int nav, int npi, QString fe, QString *noV, QString *ori, QString *des, QString *pi, float *ini, float *fin, QString *avi, int taAr, QWidget *parent = 0);
    void algoritmo(QString vuelo,float retraso);
    int busquedaPosicion(QString vuelo);
    QString busquedaVueloPilotoSiguiente(QString vuelo);
    QString busquedaVueloAvionSiguiente(QString vuelo);
    void busquedaPilotoSustitucion(int posicionActual, int idCaminoPadre);
    void busquedaAvionSustitucion(int posicionActual, int idCaminoPadre);
    void busquedaPilotoYAvionSustitucion(int posicionActual,int idCaminoPadre);
    void retrasarAviones(int posicionActual, int idCaminoPadre);
    void cancelar(int posicionActual, int idCaminoPadre);
    bool pilotoPuedeVolver(int posicionActual,int posicionDondeVa);
    bool avionPuedeVolver(int posicionActual,int posicionDondeVa);
    int sePuedeCancelar(int posicionActual,int posicionDondeVa);


public slots:
//    void algoritmo(QString vuelo, float retraso);



private:

    //COSTE
    int *listaAbierta;
    int *listaCerrada;
    int caminosComprobados;
    int numeroDeElementosEnListaAbierta;
    int numeroDeElementosEnListaCerrada;
    float *costF;
    QStringList *vuelosRutaSeguida;
    QString *vuelosLista;

    int *tipoOperacion;
    int *vueloOperacion;
    int *listaDondeEsta;

    bool *dosReordenamientos;
    unsigned *dosReordenamientosElementoForaneo;
    unsigned *dosReordenamientosPrimerElemento;

    float retraso;



    QString fecha;
    QString *nomVuelo;
    QString *origen;
    QString *destino;
    float *hInicio;
    float *hFin;
    QString *piloto;
    QString *avion;

    int numeroAviones;
    int numeroPilotos;
    int tam;
    int tamArchivo;

    float *retrasoIndividual;

//    SI DESPUES DE REALIZAR UN CAMBIO DE VUELO O PILOTO HAY QUE SEGUIR CON EL ALGORITMO
//    QString *nomVueloAvionUsado;
//    QString *origenAvionUsado;
//    QString *destinoAvionUsado;
//    float *hInicioAvionUsado;
//    float *hFinAvionUsado;
//    int numAvionesUsados;

    Reescritura *writing;



    void algoritmoComun();
    void insertarListaAbierta(QString vuelo, int operacion, int posVueloAnterior, int dosRutasReorden);
    int borrarListaAbierta(int devolver);
    void nuevoEnListaCerrada(QString vuelo, QString vueloAnterior, int idCaminoPadre);
    void insertarListaCerrada(int id);
    float devolverCostF(int posicion);
    void insertarCostF(int posicion, float coste);
    void insertar3enLista(QString vueloAnterior, int operacionAnterior, QString vuelo, int dosRutasReorden);
    int buscarVuelo(QString vuelo,int operacionAnterior);
//    void sustituirAbierta(int id1,int id2);
//    void sustituirCerrada(int id1,int id2);
    void reordenAbierta(int id);
    void reordenCerrada(int id);
    int posicionCerrada(int id);
    int posicionAbierta(int id);
    void colocarAscendenteAbierta(int pos);
    void colocarAscendenteCerrada(int pos);
    void insertarRutaSeguida(int posVueloAnterior);
    void calcularRetraso(int posVueloAnterior, int posActual, int posAnterior);
    int hayMasVuelosAfectados(int posActual);
    QStringList buscarOtraRutaSeguida();





};


#endif // REORDEN_H
