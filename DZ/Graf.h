#pragma once
class Graf
{
private:

	int *nodes;
	int num_vershin;
	int num_rebro;
		struct uzel
	{
		int v1;
		int v2;
		int wes;
	} *uzels;
	void InitGraf(int** cost);
	uzel* OutTree(int** cost);
	void QuickSort(uzel *uzels, int left, int right);
	void unitenodes(int n1, int n2);
public:
	int** input_dz(char* nfaila1);
	void output_dz(int** cost, char *nfaila);
};



