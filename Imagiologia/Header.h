//
//  Header.h
//  Imagiologia
//
//  Created by Fabio França on 31/05/14.
//  Copyright (c) 2014 UM. All rights reserved.
//

#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <math.h>
#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>

#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <opencv2/core/core.hpp>
#include <opencv2/ml/ml.hpp>

#include <cstring>
#include <cfloat>
#include <string>
//#include "Descriptors/ColorLayout.h"
//#include "ColorLayoutExtraction.h"
#include <stdio.h>
#include <iostream>
#include "Convert.h"
#include "Frame.h"
#include "Feature.h"
#include "ScalableColor.h"

#include <iostream>
#include <sstream>

#include <vector>
#include <stdexcept>

#ifndef Imagiologia_Header_h
#define Imagiologia_Header_h


using namespace cv;
using namespace std;



double * ExtFeat(IplImage* image){
    Mat cinz;
    Mat mat;
    
    double *res = new double[600];
       Frame* frame = new Frame( image->width, image->height, true, true, true);
    mat = Mat( image, false) ;
    frame->setImage(mat );
    
    
    
    //Escala de Cinzentos
    IplImage* gray = cvCreateImage( cvGetSize(image), 8, 1 );
    cinz = Mat( image, false) ;
    cvtColor( mat,cinz, CV_RGB2GRAY);
    
    frame->setGray( cinz );
    cvReleaseImage(&gray);
    
    
    
    //YCrCb
    
    XM::ColorLayoutDescriptor feat = *Feature::getColorLayoutD(frame,64,15);
    //   feat.Print();
    int * YCoeff= feat.GetYCoeff();
    double sum = 0;
    for (int i = 0; i<64; i++) {
        sum += YCoeff[i];
            }

    double Ydev , Ysdev = 0,Yvar,Ysd,Ycv;

    double Ymedia = sum/64;
    
    for(int i = 0; i < 64; ++i){
        Ydev = (YCoeff[i] - Ymedia)*(YCoeff[i] - Ymedia);
        Ysdev = Ysdev + Ydev;
    }

    Yvar = Ysdev / (64 - 1);
    Ysd = sqrt(Yvar);
    Ycv = (Ysd / Ymedia) * 100;
    
//     res[0] = Ymedia;
//   res[1] = Yvar;
//    res[2] = Ysd;
//   res[3] = Ycv;
//
    
//    
    for (int i = 0; i<64; i++) {
               res[i] = YCoeff[i];
    }
    
//    printf("SUM - %.2f \n",sum);
//    printf("MEDIA - %.2f \n",Ymedia);
//    printf("Variacao - %.2f",Yvar);
//    printf("Standard Devietion - %.2f \n",Ysd);
//    printf("Correlation - %.2f \n",Ycv);
  //  printf("Skew - %.2f \n",skew);
//    printf("Kurt - %.2f \n",kurt);
    
    int * CrCoeff = feat.GetCrCoeff();
    
    sum = 0;
    
    for (int i = 0; i<15; i++) {
        sum += CrCoeff[i];
    }
    
    double Crdev , Crsdev = 0,Crvar,Crsd,Crcv;

    double Crmedia = sum/15;
    
    for(int i = 0; i < 15; ++i){
        
        Crdev = (CrCoeff[i] - Crmedia)*(CrCoeff[i] - Crmedia);
     //   printf("CrDev - %.2f\n",Crdev);
        Crsdev = Crsdev + Crdev;
    }
    Crvar = Crsdev / (15 - 1);
    Crsd = sqrt(Crvar);
    Crcv = (Crsd / Crmedia) * 100;
//    
//    res[68] = Crmedia;
//    res[69] = Crvar;
//    res[70] = Crsd;
//    res[71] = Crcv;
//
    
    for (int i = 0; i<15; i++) {
     //   printf("TESTE -  %d\n",CrCoeff[i]);
        res[i+64] = CrCoeff[i];
    }

//    
//    printf("\n SUM - %.2f \n",sum);
//    
//    printf("Crsdev - %.2f \n\n",Crsdev);
//    printf("MEDIA - %.2f \n",Crmedia);
//    printf("Variacao - %.2f",Crvar);
//    printf("Standard Devietion - %.2f \n",Crsd);
//    printf("Correlation - %.2f \n",Crcv);

    
    int * CbCoeff = feat.GetCbCoeff();
    
    sum = 0;
    
    for (int i = 0; i<15; i++) {
        sum += CbCoeff[i];
    }
    
    double Cbdev , Cbsdev = 0,Cbvar,Cbsd,Cbcv;
    
    double Cbmedia = sum/15;
    for(int i = 0; i < 15; ++i){
        Cbdev = (CbCoeff[i] - Cbmedia)*(CbCoeff[i] - Cbmedia);
        Cbsdev = Cbsdev + Cbdev;
    }
    Cbvar = Cbsdev / (15 - 1);
    Cbsd = sqrt(Cbvar);
    Cbcv = (Cbsd / Cbmedia) * 100;
   
//    
//    res[87] = Cbmedia;
//    res[88] = Cbvar;
//    res[89] = Cbsd;
//    res[90] = Cbcv;

    
    for (int i = 0; i<15; i++) {
       // printf("TESTE -  %d\n",CbCoeff[i]);
       res[i+79] = CbCoeff[i];
    }
    
    
//    printf("\n SUM - %.2f \n",sum);
//    
//    printf("Crsdev - %.2f \n\n",Cbsdev);
//    printf("MEDIA - %.2f \n",Cbmedia);
//    printf("Variacao - %.2f",Cbvar);
//    printf("Standard Devietion - %.2f \n",Cbsd);
//    printf("Correlation - %.2f \n",Cbcv);
//
//    

    
  //     feat.Print();
    //Extracao do Scalable Color

    
    XM::ScalableColorDescriptor scd =  *Feature::getScalableColorD(frame);
    
    

    double soma = 0;
    
    int * sca = new int[scd.GetNumberOfCoefficients()];
    

    for(int i = 0 ; i < scd.GetNumberOfCoefficients(); i++){
        
        sca[i] = (int) scd.GetCoefficient(i);
        //      std::cout << sca[i] << '\n';
        
        soma+=sca[i];
        
    }
    
    double SCmedia = (soma/scd.GetNumberOfCoefficients());
   
    
    
    double SCdev, SCsdev = 0, SCvar, SCsd,SCcv;
    
    for(int i = 0; i < scd.GetNumberOfCoefficients(); ++i){
        SCdev = (sca[i] - SCmedia)*(sca[i] - SCmedia);
        SCsdev = SCsdev + SCdev;
    }
    
    SCvar = SCsdev / (scd.GetNumberOfCoefficients() - 1);
    SCsd = sqrt(SCvar);
    SCcv = (SCsd / SCmedia) * 100;
//
//       res[106] = SCmedia;
//       res[107] = SCvar;
//       res[108] = SCsd;
//       res[109] = SCcv;
//
   
    
    for (int i = 0; i< scd.GetNumberOfCoefficients(); i++) {
     //   printf("TESTE -  %d\n",sca[i]);
       res[i+94] = sca[i];
    }
    
//    
//    printf("\n SUM - %.2f \n",soma);
//    
//    printf("Crsdev - %.2f \n\n",SCsdev);
//    printf("MEDIA - %.2f \n",SCmedia);
//    printf("Variacao - %.2f",SCvar);
//    printf("Standard Devietion - %.2f \n",SCsd);
//    printf("Correlation - %.2f \n",SCcv);
  //  scd.Print();
    //Extracao do Homogeneos Texture
    
    
    sum = 0;
    XM::HomogeneousTextureDescriptor ht = *Feature::getHomogeneousTextureD(frame);
    
    
    int * htext= ht.GetHomogeneousTextureFeature();
 //   ht.Print();
    
    int * HE = new int[30];
    
    //ENERGY
    for (int i = 2; i<32; i++) {
        sum = sum + htext[i];
        HE[i-2] = htext[i];
    }
        double HEmedia  = sum/30;
    
    double HEdev, HEsdev = 0, HEvar, HEsd,HEcv;
    
    for(int i = 0; i < 30; ++i){
        HEdev = (HE[i] - HEmedia)*(HE[i] - HEmedia);
        HEsdev = HEsdev + HEdev;
    }
    
    HEvar = HEsdev / (29);
    HEsd = sqrt(HEvar);
    HEcv = (HEsd / HEmedia) * 100;
    
  
//    
//    res[110] = HEmedia;
//    res[111] = HEvar;
//    res[112] = HEsd;
//    res[113] = HEcv;
//

    
    for (int i = 0; i< 30; i++) {
       // printf("TESTE -  %d\n",HE[i]);
        res[i+350] = HE[i];
    }
    
    
//    printf("\n SUM - %.2f \n",sum);
//    
//    printf("Crsdev - %.2f \n\n",HEsdev);
//    printf("MEDIA - %.2f \n",HEmedia);
//    printf("Variacao - %.2f",HEvar);
//    printf("Standard Devietion - %.2f \n",HEsd);
//    printf("Correlation - %.2f \n",HEcv);

    
    
    
    
    double HEDdev, HEDsdev = 0, HEDvar, HEDsd,HEDcv;
    
    //ENERGY DEVIATION
     int * HED = new int[30];
    
    sum = 0;
    for(int i = 32 ; i < 62; i++ ){
        sum = sum + htext[i];
        HED[i-32] = htext[i];
            }
    double HEDmedia = sum/30;
   // printf("\nEnergy Deviation MEDIA - %.2f \n",HEDmedia);
   

    
    for(int i = 1; i < 30; ++i){
        HEDdev = (HED[i] - HEDmedia)*(HED[i] - HEDmedia);
        HEDsdev = HEDsdev + HEDdev;
    }
    
    HEDvar = HEDsdev / (30 - 1);
    HEDsd = sqrt(HEDvar);
    HEDcv = (HEDsd / HEDmedia) * 100;
    

//    
//    res[144] = HEDmedia;
//    res[145] = HEDvar;
//    res[146] = HEDsd;
//    res[147] = HEDcv;


    
    for (int i = 0; i< 30; i++) {

        res[i+380] = HED[i];

    }
    
//    
//    printf("\n SUM - %.2f \n",sum);
//    
//    printf("Crsdev - %.2f \n\n",HEDsdev);
//   printf("MEDIA - %.2f \n",HEDmedia);
//    printf("Variacao - %.2f",HEDvar);
//   printf("Standard Devietion - %.2f \n",HEDsd);
//    printf("Correlation - %.2f \n",HEDcv);
    
//    
//    for(int i = 0; i<410;i++){
//        printf(" %d RES - %.2f \n",i,res[i]);
//    }
//
    
    
    return res;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

double * ExDirectoria(String pasta,int total,String caso){

    IplImage* image =  0;
    IplImage* image1 = 0;
    IplImage* image2 = 0;

    std::stringstream ss;
    String diretoria, diretoria1,diretoria2 ;

    double *res = new double[total*410];
    int contador = 0;

    int z =0;
for (int i = 0; i<400; i++) {
    ss << i;
    
    if(contador-1 == total){
        return res;
    }else if(i < 10){
        diretoria = ("/Users/fabiofranca/Desktop/Imagiologia/TP-OPENCV/"+caso+"/"+pasta+"/000"+ss.str()+".jpg");
        diretoria1 = ("/Users/fabiofranca/Desktop/Imagiologia/TP-OPENCV/"+caso+"/"+pasta+"/000"+ss.str()+".tif");
           diretoria2 = ("/Users/fabiofranca/Desktop/Imagiologia/TP-OPENCV/"+caso+"/"+pasta+"/000"+ss.str()+".png");
        image = cvLoadImage(diretoria.c_str());
        image1 = cvLoadImage(diretoria1.c_str());
        image2 = cvLoadImage(diretoria2.c_str());
        if(!image && !image1 && !image2){
            // printf( "No image data \n" );
            
        }else{
            
            if(!image && !image1){
            contador++;
//           printf( "ENTROU\n" );
//            printf("%s",diretoria2.c_str());
           
            double * temp = ExtFeat(image2);
            for(int j = 0; j<410;j++ ){
                res[z] = temp[j];
                z++;
            }
            }else if(!image && !image2){
                contador++;
//                printf( "ENTROU\n" );
//                
//                printf("%s",diretoria1.c_str());
                double * temp = ExtFeat(image1);
                for(int j = 0; j<410;j++ ){
                    res[z] = temp[j];
                    z++;
                }
            }else{
                contador++;
//                printf("%s",diretoria.c_str());
//                printf( "ENTROU\n" );
                                           double * temp = ExtFeat(image);
                for(int j = 0; j<410;j++ ){
                    res[z] = temp[j];
                    z++;
            }
            }
        }
    }else if(i>= 10 && i< 100){
        diretoria = ("/Users/fabiofranca/Desktop/Imagiologia/TP-OPENCV/"+caso+"/"+pasta+"/00"+ss.str()+".jpg");
        diretoria1 = ("/Users/fabiofranca/Desktop/Imagiologia/TP-OPENCV/"+caso+"/"+pasta+"/00"+ss.str()+".tif");
        diretoria2 = ("/Users/fabiofranca/Desktop/Imagiologia/TP-OPENCV/"+caso+"/"+pasta+"/00"+ss.str()+".png");
        image = cvLoadImage(diretoria.c_str());
        image1 = cvLoadImage(diretoria1.c_str());
        image2 = cvLoadImage(diretoria2.c_str());
        
        if(!image && !image1 && !image2){
           // printf( "No image data \n" );
            
        }else{
            
            if(!image && !image1){
                contador++;
          //      printf( "ENTROU\n" );
//                printf("%s",diretoria2.c_str());
                double * temp = ExtFeat(image2);
                for(int j = 0; j<410;j++ ){
                    res[z] = temp[j];
                    z++;
                }
            }else if(!image && !image2){
                contador++;
          //      printf( "ENTROU\n" );
                
//                printf("%s",diretoria1.c_str());
                double * temp = ExtFeat(image1);
                for(int j = 0; j<410;j++ ){
                    res[z] = temp[j];
                    z++;
                }
            }else{
                contador++;
            //    printf( "ENTROU\n" );
//                printf("%s",diretoria.c_str());

                               double * temp = ExtFeat(image);
                for(int j = 0; j<410;j++ ){
                    res[z] = temp[j];
                    z++;
                }

            
            }
        }
        
    }else{
        
        
        
        diretoria = ("/Users/fabiofranca/Desktop/Imagiologia/TP-OPENCV/"+caso+"/"+pasta+"/0"+ss.str()+".jpg");
        diretoria1 = ("/Users/fabiofranca/Desktop/Imagiologia/TP-OPENCV/"+caso+"/"+pasta+"/0"+ss.str()+".tif");
        diretoria2 = ("/Users/fabiofranca/Desktop/Imagiologia/TP-OPENCV/"+caso+"/"+pasta+"/0"+ss.str()+".png");
        image = cvLoadImage(diretoria.c_str());
        image1 = cvLoadImage(diretoria1.c_str());
        image2 = cvLoadImage(diretoria2.c_str());
        
        if(!image && !image1 && !image2){
         //   printf( "No image data \n" );
          //  printf("%s",diretoria.c_str());
            
        }else{
            if(!image && !image1){
                contador++;
             //   printf( "ENTROU\n" );
//                printf("%s",diretoria2.c_str());
                               double * temp = ExtFeat(image2);
                for(int j = 0; j<410;j++ ){
                    res[z] = temp[j];
                    z++;
                }
            }else if(!image && !image2){
                contador++;
              //  printf( "ENTROU\n" );
               //  printf("%s",diretoria1.c_str());
                                double * temp = ExtFeat(image1);
                for(int j = 0; j<410;j++ ){
                    res[z] = temp[j];
                    z++;
                }
            }else{
                contador++;
            
               // printf( "ENTROU\n" );
               // printf("%s",diretoria.c_str());

                               double * temp = ExtFeat(image);
                for(int j = 0; j<410;j++ ){
                    res[z] = temp[j];
                    z++;
                }

            
        }
        }
        
    }
 //   printf("%d",contador+1);
    ss.str("");
    }
    return res;
}



#endif
