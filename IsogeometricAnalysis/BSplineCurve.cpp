
#include"BSplineCurve.h"
BSplineCurve::BSplineCurve(int n, int p)
{
	this->n = n;
	this->p = p;
	this->m = n + 1 + p;
	//��ʼ�����ƶ�������P�ͽڵ���������U

	U.resize(get_m()+ 1);          //��Ϊ�����Եģ����Զ���һά����
	P.resize(n + 1);
}
BSplineCurve::BSplineCurve()
{

}

BSplineCurve::~BSplineCurve()
{

}
vector<double >BSplineCurve::getU()
{
	return U;
}
void BSplineCurve::setU(vector<double >U)
{
	this->U = U;
}
vector<Vector3 >BSplineCurve::getP()
{
	return P;
}
void BSplineCurve::setP(vector<Vector3 >P)
{
	this->P = P;
}
//-------------------------------------------------------------
int BSplineCurve::get_m()
{
	return m;
}
void BSplineCurve::set_m(int m)
{
	this->m = m;
}

int BSplineCurve::get_n()
{
	return n;
}
void BSplineCurve::set_n(int n)
{
	this->n = n;
}

int BSplineCurve::get_p()
{
	return p;
}
void BSplineCurve::set_p(int p)
{
	this->p = p;
}

//-------------------------------------------------------------
Vector3 BSplineCurve::paintBSplineCurve(double u)    //���������ϵ�һ�㣬����u=uiʱ�����ߵ�ֵ
{
	Vector3 C=*new Vector3(0,0,0);
	double t=0;
	for (int i = 0; i <= get_n(); i++)
	{
		t = computerN(i, get_p(), u);
		//cout << t << endl;
		C += P[i] * t;
	}
	return C;
}
double BSplineCurve::computerN(int i,int p,double u)
{

	if ( p == 0)             //���ݹ鵽0��ʱ
	{
		if (u == U[m])
		{
			return 1;
		}
		else if (U[i] <= u &&u< U[i + 1])
		{
          return 1;
		}
		else
		{
			return 0;
		}	
	}
	else
	{
		return ((u - U[i]) / (U[i + p] - U[i]))*computerN(i, p - 1, u) + ((U[i + p + 1] - u) / (U[i + p + 1] - U[i + 1]))*computerN(i + 1, p - 1, u);
	}
}
