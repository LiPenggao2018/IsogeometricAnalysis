#pragma once
#include<iostream>
#include"Vector3.h"

#include<vector>
using namespace std;
class BSplineCurve
{
public:
	BSplineCurve(int n,int p);
	BSplineCurve();
	~BSplineCurve();
	vector<double >getU();
	void setU(vector<double >U);
	vector<Vector3 >getP();
	void setP(vector<Vector3 >P);
	//------------------------���ߵĻ���-------------------------------
	Vector3 paintBSplineCurve(double u);                                  //����һ��uֵ�����������ϵ�һ����������
	double computerN(int i,int p,double u);
	int get_m();
	void set_m(int m);

	int get_n();
	void set_n(int n);

	int get_p();
	void set_p(int p);
private:                                                                                                                                                         
	vector<double >U;                                            //ע�⣬Ҫ��vector����ʱ��һ���Ȱ����ú������ڵ���������ռ䣬��Ȼ��ʾ������
	vector<Vector3 >P;                                           //����һ�����ƶ�����������P
	int m;          //�ڵ���Ϊm+1,���Զ���ڵ����������СΪm+1.U[m]��Ϊ���һ���ڵ㡣
	int n;          //���ƶ�����Ϊn+1,����ƶ��������СΪP[n+1],P[n]��Ϊ���һ�����ƶ��㡣
	int p;          //��������Ĵ���,p>=0
};

