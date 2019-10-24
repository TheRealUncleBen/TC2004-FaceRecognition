==================================================================================
	FaceDetection With OpenCV
==================================================================================

This Document was created with the purpose of making easier the use
of the methods from the "FaceDetector" object. The FaceDetector was
implemented with the C++ programming language, the object makes use
of the OpenCV library which is required for FeceDetector to work.

//////////////////////////////////////////////////////////////////////////////////

Contents:

 -OpenCV website
 -FaceDetector.h
   ~Description
 -FaceDetector.cpp
   ~General Description
   ~Methods with explanation and usage example
 -main.cpp
   ~General Description

//////////////////////////////////////////////////////////////////////////////////

OpenCV website:
 -You can find the instalation process for OpenCV on their website: 
  https://opencv.org

//////////////////////////////////////////////////////////////////////////////////

FaceDetector.h
 -This file contains the class: FaceDetector. No further alterations
  are needed for it to operate.

//////////////////////////////////////////////////////////////////////////////////

FaceDetector.cpp
 -This file includes the definition for the Methods and Constructors.
 
 -Methods:
 
   FaceDetector::FaceDetector()
     This is the default constructor which loads the default haar cascade
     training and our recomended initial settings.
     
     *Example:
	    FaceDetector Detect();

   FaceDetector::FaceDetector(string face_cascade_name,
			      int next_height_,
			      double scale_factor,
			      int minConsensus, 
			      int next_height_img, 
			      int flag)
     This constructor may be used for a more customized use of the 
     face detector. Should only be used if the user has enough experience.

      >string face_cascade_name	
        This string is used to load a XML or a YAML file 
        for the training.
      >int next_height_
        next_height is used through the whole program to establish
        the size of the initial sampling size for each sampling square
      >double scale_factor
        This multiple determines the size increase for the 
        sampling square for each time the sampling square yields
        no match after every passing.
      >int minConsensus
        This number establishes how many neighbours each square
        must have to retain it, which modifies the similarity percent 
        needed to be considered a face
      >int next_height_img
        Instructs to the object the size of the image to analyze
      >int flag
        This is where the user can indicate if a flag is needed

     *Example:
	    FaceDetector Detect(face_cascade_name, next_height, 1.1, 4, 40, 0);

   vector<Rect> FaceDetector::nextFrame(Mat frame)
     nextFrame contains the main functionality. The method returns a vector
     of rectangles containing the coordinates of all the faces found on the
     frame, even when no face was found; in which case the vector will be empty.

      >Mat frame
        The frame of a video to be analyzed in a Mat format. If the
        frame sent is empty or the classifier is not found, the 
        program will let you know by printing the corresponding message.

     *Example:
      vector<Rect> faces;
      Mat frame;
      faces = Detect.nextFrame(frame);

   vector<Rect> FaceDetector::ImgDetect(Mat img)
     ImgDetect is a simpler version of the nextFrame method aimed to be used only
     on images, as mentioned it is only to be used for individual images instead 
     of a secence of frames from a video. As the other method, this one still 
     returns a vector with the coordinates of the faces detected.

      >Mat img
        The image to be analyzed must have been loaded into a Mat format,
        otherwise the method will not work and will print "Image not found"

     *Example:
      vector<Rect> faces;
      string test = "D:\\VacationPictures\\2017\\beach.JPG";
      Mat img = imread(test, IMREAD_UNCHANGED);
      faces = Detect.ImgDetect(img); 

//////////////////////////////////////////////////////////////////////////////////

 -Main.cpp
     This main Sample can give you a better idea of how a regular program would 
     look like. It also includes insightful comments which can give you an idea of
     what each part does.

/////////////////////////////////////////////////////////////////////////////////
