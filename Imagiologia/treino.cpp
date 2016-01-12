//
//  main.cpp
//  Imagiologia
//
//  Created by Fabio França on 18/05/14.
//  Copyright (c) 2014 UM. All rights reserved.
//


#include "Header.h"

using namespace cv;
using namespace XM;
//using namespace std;

int main( int argc, char* argv[] ) {
   // IplImage* teste = cvLoadImage(argv[1]);
    

    std::stringstream ss;
    
    String cabecalho = "1";
    
    for (int i = 2; i <=411; i++) {
        ss << i ;
        cabecalho = cabecalho +","+ ss.str();
        ss.str("");
    }
    cabecalho = cabecalho + "\n";
    
    
    String stri;
    String x;
    int contador = 0;
    FILE * pFile;
    pFile = fopen ("/Users/fabiofranca/Documents/XCode/Imagiologia/Imagiologia/dataset.csv","w+");
    double* treino = new double[410*(74+39+87+14)];
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////ESTOMAGO//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
   double* esofago = ExDirectoria("esofago/treino",49,"caso2");
    
    
    for (int i = 0; i<49*410; i++) {
        treino[i] = esofago[i];
    }
    if (pFile!=NULL)
    {
        
        fputs (cabecalho.c_str(),pFile);
        
    }else{
        printf("Ficheiro nao encontrado");
        
    }
    
    
    for (int i = 0; i<=(49*410); i++) {
                      if(contador == 410){
            contador = 0;
            if(i!=(49*410)){
            fputs("esofago\n", pFile);
            x= std::to_string(esofago[i]).c_str();
            stri = ( x+ ",");
            fputs(stri.c_str(), pFile);
            contador++;
            }
        }else{
        x= std::to_string(esofago[i]).c_str();
        stri = ( x+ ",");
        fputs(stri.c_str(), pFile);
        contador++;
      
 
        }
       
            }
     fputs("esofago\n", pFile);
    
    

        //
//
//    
    
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////ANTRUM//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    
//    
//    
//    
    double * estomago  = ExDirectoria("estomago/treino", 26,"caso2");
    contador = 0;

    for (int i = 0; i<=26*410; i++) {
        

        if(contador == 410){
            contador = 0;
            if(i!=26*410){
            fputs("estomago\n", pFile);
            x= std::to_string(estomago[i]).c_str();
            stri = ( x+ ",");
            fputs(stri.c_str(), pFile);
            contador++;
            }
        }else{
            
        x= std::to_string(estomago[i]).c_str();
        stri = ( x+ ",");
        fputs(stri.c_str(), pFile);
            contador++;
                   }
       
    }

        fputs("estomago\n", pFile);

    for (int i = 0; i<26*410; i++) {
        treino[i+(410*49)] = estomago[i];
       // printf("%d TREINO -  %.2f \n",i+(410*74),treino[i+(410*74)]);
    }

//    double * antrum  = ExDirectoria("antrum", 18,"caso3");
//    contador = 0;
//    
//    for (int i = 0; i<=18*410; i++) {
//        if(contador == 410){
//            contador = 0;
//            if(i!=18*410){
//                fputs("antrum\n", pFile);
//                x= std::to_string(antrum[i]).c_str();
//                stri = ( x+ ",");
//                fputs(stri.c_str(), pFile);
//                contador++;
//            }
//        }else{
//            
//            x= std::to_string(antrum[i]).c_str();
//            stri = ( x+ ",");
//            fputs(stri.c_str(), pFile);
//            contador++;
//        }
//        
//    }
//    
//    fputs("antrum\n", pFile);

    

    
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////BODY//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//    
  double * duodeno = ExDirectoria("duodeno/treino", 58,"caso2");
    contador = 0;
    for (int i = 0; i<=410*58; i++) {
       
        if(contador==410){
            
            contador=0;
            
            if(i!=410*58){
            fputs("duodeno\n", pFile);
            x= std::to_string(duodeno[i]).c_str();
            stri = ( x+ ",");
            fputs(stri.c_str(), pFile);
            contador++;
            
            }
        }else{
        x= std::to_string(duodeno[i]).c_str();
        stri = ( x+ ",");
        fputs(stri.c_str(), pFile);
            contador++;
              }
    
    }
    fputs("duodeno\n", pFile);
    
    for (int i = 0; i<58*410; i++) {
        treino[i+(410*(49+26))] = duodeno[i];
       // printf("%d TREINO -  %.2f \n",i+(410*(74+39)),treino[i+(410*(74+39))]);
    }


    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////Cardia//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
//    double * cardia = ExDirectoria("cardia", 2);
//    contador = 0;
//    for (int i = 0; i<=2*410; i++) {
//        
//        if(contador==410){
//            contador=0;
//            if(i!=2*410){
//            fputs("cardia\n", pFile);
//                x= std::to_string(cardia[i]).c_str();
//                stri = ( x+ ",");
//                fputs(stri.c_str(), pFile);
//                contador++;
//            }
//        }else{
//        x= std::to_string(cardia[i]).c_str();
//        stri = ( x+ ",");
//        fputs(stri.c_str(), pFile);
//            contador++;
//        }
//        
//    }
//    fputs("cardia\n", pFile);
//
    
    
    
    
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////Colon//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//    
//    double * colon = ExDirectoria("colon", 5);
//    contador = 0;
//    for (int i = 0; i<=410*5; i++) {
//        
//        if(contador==410){
//            contador = 0;
//            if(i!=410*5){
//            fputs("colon\n", pFile);
//                x= std::to_string(colon[i]).c_str();
//                stri = ( x+ ",");
//                fputs(stri.c_str(), pFile);
//                contador++;
//                
//            }
//        }else{
//        x= std::to_string(colon[i]).c_str();
//        stri = ( x+ ",");
//        fputs(stri.c_str(), pFile);
//       contador++;
//        }
//     
//    }
//    fputs("colon\n", pFile);
    
    
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////Duodenum//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//    
//    double * body = ExDirectoria("body", 15,"caso3");
//    contador = 0;
//    for (int i = 0; i<=410 * 15; i++) {
//        
//        if(contador==410){
//            contador =0;
//            if(i!=410*15){
//            fputs("body\n", pFile);
//            x= std::to_string(body[i]).c_str();
//            stri = ( x+ ",");
//            fputs(stri.c_str(), pFile);
//             contador++;
//            }
//        }else{
//        x= std::to_string(body[i]).c_str();
//        stri = ( x+ ",");
//        fputs(stri.c_str(), pFile);
//        contador++;
//        }
//        
//    }
//    fputs("body\n", pFile);
    
    
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////Fundus//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//    
//    double* fundus = ExDirectoria("fundus", 16,"caso3");
//    contador = 0;
//    for (int i = 0; i<=16*410; i++) {
//        
//        if(contador==410){
//            contador = 0;
//            if(i!=16*410){
//                
//            fputs("fundus\n", pFile);
//                x= std::to_string(fundus[i]).c_str();
//                stri = ( x+ ",");
//                fputs(stri.c_str(), pFile);
//                contador++;
//            }
//        }else{
//        x= std::to_string(fundus[i]).c_str();
//        stri = ( x+ ",");
//        fputs(stri.c_str(), pFile);
//            contador++;
//
//        }
//           }
//    fputs("fundus\n", pFile);
    
    
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////Ileum//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
//    double * ileum = ExDirectoria("ileum", 8);
//    contador = 0;
//    for (int i = 0; i<=8*410; i++) {
//        
//        if(contador==410){
//            contador = 0;
//            if(i!=8*410){
//            fputs("ileum\n", pFile);
//                x= std::to_string(ileum[i]).c_str();
//                stri = ( x+ ",");
//                fputs(stri.c_str(), pFile);
//                contador++;    
//            }
//        }else{
//        x= std::to_string(ileum[i]).c_str();
//        stri = ( x+ ",");
//        fputs(stri.c_str(), pFile);
//             contador++;
//        }
//       
//    }
//    fputs("ileum\n", pFile);
    


    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////Cardia//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    double * indef = ExDirectoria("exterior/treino", 11, "caso2");
    contador=0;
    for (int i = 0; i<=11*410; i++) {
     
        if(contador==410){
            contador = 0;
            if(i!=11*410){
            fputs("indefenido\n", pFile);
                x= std::to_string(indef[i]).c_str();
                stri = ( x+ ",");
                fputs(stri.c_str(), pFile);
                contador++;
            }
        }else{
        x= std::to_string(indef[i]).c_str();
        stri = ( x+ ",");
        fputs(stri.c_str(), pFile);
            contador++;
         

        }
           }
    fputs("indefenido\n", pFile);
    
    
    for (int i = 0; i<11*410; i++) {
        treino[i+(410*(49+26+58))] = indef[i];
        printf("%d TREINO -  %.2f \n",i+(410*(49+26+58)),treino[i+(410*(49+26+58))]);
    }
    
    
    float labels[144];
	float trainingData[144][410];
    
    int cont = 0;
    
    for(int i = 0; i<144;i++){
      //  printf("I - %d \n",i);
        
        if(i < 49){
        labels[i] = 1;
        }else if(i >= 49 && i<75){
            labels[i] = 2;
        }else if(i >= 75 && i<133){
            labels[i] = 3;
        }else{
            labels[i] = 4;
        }
        for (int j = 0; j< 410; j++) {
            
            trainingData[i][j] = treino[(410*cont)+j];
                    //printf("J*i - %d \n",j*i);
          //  printf("trainingData - %.2f",trainingData[i][j]);
            if (j==409){
                cont=cont+1;
            }
        }
       
    }
    
    

    
 
     cv::Mat layers = cv::Mat(11, 1, CV_32S);
    layers.at<int>(0,0) = 410;//input layer
    
    layers.at<int>(1,0) = 400;

    layers.at<int>(2,0) = 400;

    layers.at<int>(3,0) = 400;
       layers.at<int>(4,0) = 400;
       layers.at<int>(5,0) = 400;
       layers.at<int>(6,0) = 400;
       layers.at<int>(7,0) = 400;
       layers.at<int>(8,0) = 400;
       layers.at<int>(9,0) = 400;
    
    layers.at<int>(10,0) = 1;
    
    
    Mat labelsMat(144, 1, CV_32FC1, labels);
    
	Mat trainingDataMat(144, 410, CV_32FC1, trainingData);
    
    printf("%lu - %lu ",trainingDataMat.total(),labelsMat.total());
    
    CvANN_MLP ann;
    
    //ANN criteria for termination
    CvTermCriteria criter;
    criter.max_iter = 500;

    criter.type = CV_TERMCRIT_ITER;
    
    //ANN parameters
    CvANN_MLP_TrainParams params;
    params.train_method = CvANN_MLP_TrainParams::BACKPROP;
    params.bp_dw_scale = 0.1;
    params.bp_moment_scale = 0.1;
    params.term_crit = criter;
    
    ann.create(layers,CvANN_MLP::SIGMOID_SYM);
    printf("Erroyo");
    
    ann.train(trainingDataMat, labelsMat, cv::Mat(), cv::Mat(), params);
    ann.save("treino");
    
   
    
    
    
    
    
    
}

