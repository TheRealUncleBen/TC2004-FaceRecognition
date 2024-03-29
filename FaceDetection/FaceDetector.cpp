#include "FaceDetector.h"
using namespace cv;
using namespace std;

FaceDetector::FaceDetector()
{
        face_cascade.load("D:/OpenCV/opencv/user_build/install/etc/haarcascades/haarcascade_frontalface_alt.xml"); //Hay que hacer esto genericamente

        //Se pueden incluir otros xmls, dependiendo de como apareceran las caras, como haarcascade_frontalface_alt_tree o haarcascade_frontalface_alt2
        next_height = 40;
        window_scaling = 1.1;
        minClassifiers = 4;
        imgHeight = 40;
        flags = 0;
}

FaceDetector::FaceDetector(string face_cascade_name, int next_height_, double scale_factor, int minConsensus, int next_height_img, int flag)
{
        next_height = next_height_;
        face_cascade.load(face_cascade_name);
        window_scaling = scale_factor;
        minClassifiers = minConsensus;
        imgHeight = next_height_img;
        flags = flag;
}

//# funcion detectar
vector<Rect> FaceDetector::nextFrame(Mat frame)
{
        //declarar arreglo de rectangulos donde se guardan las caras existentes en la matriz
        //declarar nueva matriz para grises

        vector<Rect> faces;
        Mat frame_gray;

        if (face_cascade.empty())
        {
                cout << "Cascade data file reference not found";
        }
        if (frame.empty())
        {
                cout << "No more frames";
        }

        //convertir la matriz a una matriz de escala de grises
        cvtColor(frame, frame_gray, COLOR_BGR2GRAY);
        //
        equalizeHist(frame_gray, frame_gray);

        //@ si la cara es menor a 40px se asignan 40px
        if (next_height < 40)
        {
                next_height = 40;
        }

        //Detectar caras (∆)
        //@ Params: frame en gris, vector de caras, factor de expansion de imagen, clasificadores necesarios para deteccion, flags, tamaño de la ventana de busqueda.
        face_cascade.detectMultiScale(frame_gray, faces, window_scaling, minClassifiers, flags, Size(next_height, next_height));

        //@ for para remarcar cada cara detectada y guardada en el arreglo
        for (size_t i = 0; i < faces.size(); i++)
        {

                if (i == 0)
                {
                        next_height = faces[0].height;
                }

                //@ encuentra la cara mas pequeña existente
                if ((next_height > faces[i].height) && (i > 0))
                {
                        next_height = faces[i].height;
                }

                //obtener el 80% del tamaño de la imagen
                next_height = next_height * 0.8;
        }

        return faces;
}

vector<Rect> FaceDetector::ImgDetect(Mat img)
{
        vector<Rect> faces;
        if (img.empty())
        {
                cout << "No se encontro imagen";
                exit(0);
        }
        else
        {
                face_cascade.detectMultiScale(img, faces, window_scaling, minClassifiers, flags, Size(imgHeight, imgHeight));
        }

        return faces;
}

/*
   ∆ = Se detectan las caras existentes en la matriz en escala de grises y las guarda en el
   arreglo de faces, para esto revisa la cara con un cuadro que va incrementando en window_scaling veces
   su tamaño y necesita que un numero de clasificadores por lo menos igual a minClassifiers den positivo para decir que una cara fue detectada
   ,para revisar la imagen se hacen matrices del 80% del tamaño de la cara mas pequeña detectada en el ultimo
   frame.
 */
