#include <iostream>
#include <fstream>
#include "Graf.h"
#include <string>
using namespace std;


int** Graf::input_dz(char* nfaila1)
{
	setlocale(LC_ALL, "Russian");
	int n=0;
	int **cost=0;
	ifstream in(nfaila1);

	if (!in.is_open())
	{
		cout << "Файл не найден"<<endl;
		return 0;
	}
	if ((n = in.get()) == EOF) 
	{
		cout << "Файл пуст"<<endl;
	    return 0;
	}
	in.seekg(0, ios::beg);
	in.clear();

	if (!in.eof())  
		in >> n;
	in.seekg(0, ios::beg);
	in.clear();
	if (n == 1)
	{
		cout << "На местности только один объект"<<endl;
		return 0;
	}
	if (n<0)
	{
		cout << "Количество объектов не может быть отрицательным"<<endl;
		return 0;
	}
	string stroka;
	int k = 0;
	while (!in.eof())
	{
		getline(in, stroka);
		k++;
	}
	in.seekg(0, ios::beg);
	in.clear();
	if (k != n)
	{
		cout << "Ошибка при вводе входных данных"<<endl;
		return 0;
	}
	k = 0;
	int temp;
	while (!in.eof())
	{
		in >> temp;
		k++;
	}
	in.seekg(0, ios::beg);
	in.clear();
	if (k != n*n)
	{
		cout << "Не все расстояния заданы"<<endl;
		return 0;
	}
	cost = new int*[n];
	for (int i = 0; i < n; i++) 
		cost[i] = new int[n];
	for (int i = 0; i < n; i++) 
	{
		for (int j = 0; j < n; j++) 
			in >> cost[i][j];
	}
	in.close();
	for (int i = 0; i < n; i++)
	{
		for (int j = i+1; j < n; j++)
		{
			if (cost[i][j] != cost[j][i])
			{
				cout << "Ошибка при вводе входных данных"<<endl;
				return 0;
			}
			if (cost[i][j] == 0)
			{
				cout << "Расстояние не может быть равно 0" << endl;
				return 0;
			}
		}
	}
	return (cost);
}
void Graf::InitGraf(int** cost)
{
	num_vershin = cost[0][0];
	num_rebro = (num_vershin*(num_vershin - 1)) / 2;
	nodes = new int[num_vershin];
	uzels = new uzel[num_rebro];
	for (int i = 0;i < num_vershin;i++)
		nodes[i] = i;
	int k = 0;
	for (int i = 0;i < num_vershin;i++)
	{
		for (int j = i+1;j < num_vershin;j++)
		{
			uzels[k].v1=i;
			uzels[k].v2=j;
			uzels[k].wes=cost[i][j];
			k++;
		}
	}
	
}
void Graf::QuickSort(uzel *uzels, int left, int right)
{
	uzel pivot; 
	int l_hold = left; 
	int r_hold = right; 
	pivot = uzels[left];
	while (left < right) 
	{
		while ((uzels[right].wes >= pivot.wes) && (left < right))
			right--; 
		if (left != right) 
		{
			uzels[left] = uzels[right]; 
			left++; 
		}
		while ((uzels[left].wes <= pivot.wes) && (left < right))
			left++; 
		if (left != right) 
		{
			uzels[right] = uzels[left]; 
			right--; 
		}
	}
	uzels[left] = pivot; 
	int q = left;
	left = l_hold;
	right = r_hold;
	if (left < q) 
		QuickSort(uzels, left, q - 1);
	if (right > q)
		QuickSort(uzels, q + 1, right);
}

void Graf::unitenodes(int n1, int n2)
{
	int t = nodes[n2];
	for (int i = 0;i < num_vershin;i++)
	{
		if (nodes[i] == t)
			nodes[i] = nodes[n1];
	}
}
	
Graf::uzel* Graf::OutTree(int** cost)
{
	InitGraf(cost);
	QuickSort(uzels, 0, num_rebro - 1);
	uzel *vivod = new uzel[num_vershin-1];
	int k = 0;
	for (int i = 0;i < num_rebro;i++)
	{
		if (nodes[uzels[i].v1] != nodes[uzels[i].v2])
		{
			unitenodes(uzels[i].v1, uzels[i].v2);
			vivod[k] = uzels[i];
			k++;
		}
	}
	return (vivod);

}

void Graf::output_dz(int** cost,char *nfaila)
{
	uzel *vivod1=OutTree(cost);
	ofstream out(nfaila);
	if (out.is_open())
	{
		for (int i = 0;i < num_vershin - 1;i++)
			out << vivod1[i].v1 << "-" << vivod1[i].v2 << "->" << vivod1[i].wes << endl;
	}
	out.close();
	
}
int main(int argc, char *argv[])
{
	
	Graf graf;
	int **matrix = graf.input_dz(argv[1]);
	if (matrix == 0)
	{
		system("pause");
		return 0;
	}
	graf.output_dz(matrix, argv[2]);
	system("pause");
	return 0;
}


