#pragma once
//---------------------------------------------------------------------------------------//
//           BP�㷨���ӣ���һ������������ȥ�ƽ�����            //
//           f(x1,x2)=pow(x1-1,4)+2*pow(x2,2)                                       //
//                                 ���ߣ�MaxMatrix                                             //
//                                 2004.5.9��ͨ ������VC++6.0                     //
//--------------------------------------------------------------------------------------//
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <fstream>
//---------------------------------------------------------------------
#define RANDOM rand()/32767.0  //0~1��������ɺ���
   
const int Layer_Max=5;//������Ĳ���
const double PI=3.1415927;//Բ����
const int Layer_number[Layer_Max]={2,4,4,2,1};//������������Ԫ����
const int Neural_Max=4;//��������������Ԫ����
const int InMax=21;//��������ĸ���


//������ BP
class BP
{
public:
 BP(); //BP��Ĺ��캯��
 ~BP(void);
 void BP_Print();//��ӡȨϵ��
 double F(double x);//��Ԫ�ļ�������
 double Y(double x1,double x2);//Ҫ�ƽ��ĺ���
                               // 
 double NetWorkOut(int x1 , int x2);//�����������������Ϊ
                              //��input������
 void AllLayer_D(int x1 , int x2);//��������Ԫ��������΢��
 
 void Change_W();   //�ı�Ȩϵ��
    
 void Train();     //ѵ������
 void After_Train_Out(); //����ѵ����21���������������
 double Cost(double out,double Exp);//���ۺ���
private:
 double W[Layer_Max][Neural_Max][Neural_Max];//����Ȩϵ��
        //�涨W[i][j][k]��ʾ�����i��ĵ�j����Ԫ���ӵ�
        //��i��1���k����Ԫ��Ȩϵ��
 double Input_Net[2][InMax];//21����������,Լ��Input_Net[0][i]
                            //��ʾ��i������������x1
                            //�� Input_Net[1][i]��ʾ��i������������x2
 double Out_Exp[InMax][InMax];//�������
 
 double Layer_Node[Layer_Max][Neural_Max];//�������Ԫ�����
     //�涨Layer_Node[i][j]��ʾ��i��ĵ�j����Ԫ�����
 double D[Layer_Max][Neural_Max];//�������Ԫ�����΢��
     //�涨D[i][j]��ʾ��i���j����Ԫ�����΢��
 double Study_Speed;//ѧϰ�ٶ�
 
 double e;//���
};



