#include <opencv2/highgui/highgui.hpp>
//Libreria para procesar la imagen, cambiar el color, recortar, etc.
#include <opencv2/imgproc/imgproc.hpp>
//Libreria que detecta objetos en imagenes
#include <opencv2/objdetect/objdetect.hpp>
#include "opencv2/opencv.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include "FaceDetector.h"

using namespace std;
using namespace cv;

//Se inicializa el nextFrame
void nextFrame(Mat frame);

//ubicacion de archivos para que el algoritmo sepa que es una cara
string face_cascade_name = "D:/OpenCV/opencv/user_build/install/etc/haarcascades/haarcascade_frontalface_alt.xml";

//Nombre de la ventana
string window_name = "Deteccion Facial";
//Tamaño inicial pequeño para mejorar eficiencia
int next_height = 40;

int main(int argc, const char **argv)
{
        //Variables de captura de imagen y matriz de valores donde se guardara esta captura
        VideoCapture capture;
        Mat frame;
        vector<Rect> faces;

        //llamar a la clase
        FaceDetector Detect(face_cascade_name, next_height, 1.1, 4, 40, 0);

        //Se asigna video en vivo a captura
        capture = VideoCapture(0);

        double fps = capture.get(CAP_PROP_FPS);
        cout << "FPS maximas: " << fps << endl; //Maximo FPS al que puede llegar al sistema
        //@ Si existe captura...
        if (capture.isOpened())
        {
                while (true)
                {
                        clock_t a = clock(); //Valor de reloj para FPS
                        capture >> frame;
                        //@ Si la matriz no se encuentra vacia...
                        if (!frame.empty())
                        {
                                //funcion de detectar
                                faces = Detect.nextFrame(frame);
                        }
                        else
                        {
                                //La matriz esta vacia, marcar error
                                printf("Error: No existe un frame capturado");
                                break;
                        }

                        //Hacer print a las coordenadas.

                        cout << "########################################" << endl;

                        for (int i = 0; i < faces.size(); i++)
                        {
                                cout << i << ": "
                                     << "(" << faces[i].x << "," << faces[i].y << ")" << endl;
                        }

                        cout << "#########################################" << endl;

                        fps = double(CLOCKS_PER_SEC) / double(clock() - a);

                        //imprimir FPS
                        cout << "FPS: " << fps << endl;

                        //    //mostrar video en vivo con lo que se obtuvo
                }
        }

        /*
        string test = "D:\\Fotos de Viajes\\2017\\Junio-Diciembre\\100ANDRO (1)\\DSC_0023.JPG";
        Mat img = imread(test, IMREAD_UNCHANGED);

        faces = Detect.ImgDetect(img); 
        //Para realizar la llamada, se tiene que mandar una imagen. Para mandar imagen desdee disco, se usa imread.

        cout << "########################################" << endl;

        for (int i = 0; i < faces.size(); i++)
        {
                cout << i << ": "
                     << "(" << faces[i].x << "," << faces[i].y << ")" << endl;
        }

        cout << "#########################################" << endl;

        char r = getchar();

        */

        return 0;

        /*
        Pasos para implementar detección de video:
        1. Instanciar a la clase FaceDetector
        2. crear una captura de video de tipo VideoCapture
        3. Realizar llamada a nextFrame dentro de un bucle, asignandole el resultado a un vector de tipo <Rect>
        4. Las coordenadas de las caras estaran dentro del vector
        */
}
