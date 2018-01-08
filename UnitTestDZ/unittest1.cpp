#include "stdafx.h"
#include "CppUnitTest.h"
#define private public
#include "Source.cpp"
#include "Graf.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestDZ
{
	TEST_CLASS(DZtest)
	{
	public:
		
		//char* test1 = "C:\\Users\\J_BlaKk\\source\\repos\\DZ\\UnitTestDZ\\1.ans";
		char* test1 = "files\\1.ans";
		char* test1expected = "files\\1.dat";
		char* test1actual = "files\\1.txt";
		char* test2 = "files\\2.ans";
		char* test2expected = "files\\2.dat";
		char* test2actual = "files\\1.txt";
		char* test3 = "files\\3.ans";
		char* test3expected = "files\\3.dat";
		char* test3actual = "files\\1.txt";
		char* test4 = "files\\4.ans";
		char* test4expected = "files\\4.dat";
		char* test4actual = "files\\1.txt";
		TEST_METHOD(TEST_input_dz)
		{
			Graf graf1;
			int* expected1;
			expected1 = new int[16];
			expected1[0] = 4;
			expected1[1] = 3;
			expected1[2] = 3;
			expected1[3] = 3;
			expected1[4] = 3;
			expected1[5] = 0;
			expected1[6] = 3;
			expected1[7] = 3;
			expected1[8] = 3;
			expected1[9] = 3;
			expected1[10] = 0;
			expected1[11] = 3;
			expected1[12] = 3;
			expected1[13] = 3;
			expected1[14] = 3;
			expected1[15] = 0;
			int k = 0;
			for (int i = 0; i < graf1.input_dz(test1)[0][0]; i++) {
				for (int j = 0; j < graf1.input_dz(test1)[0][0]; j++)
				{
					Assert::AreEqual(expected1[k], graf1.input_dz(test1)[i][j]);
					k++;
				}
			}
			/////////////////////////////////////////////////////////////////////////////////
			Graf graf2;
			int* expected2;
			expected2 = new int[16];
			expected2[0] = 4;
			expected2[1] = 1;
			expected2[2] = 2;
			expected2[3] = 3;
			expected2[4] = 1;
			expected2[5] = 0;
			expected2[6] = 4;
			expected2[7] = 5;
			expected2[8] = 2;
			expected2[9] = 4;
			expected2[10] = 0;
			expected2[11] = 6;
			expected2[12] = 3;
			expected2[13] = 5;
			expected2[14] = 6;
			expected2[15] = 0;
			k = 0;
			for (int i = 0; i < graf2.input_dz(test2)[0][0]; i++) {
				for (int j = 0; j < graf2.input_dz(test2)[0][0]; j++)
				{
					Assert::AreEqual(expected2[k], graf2.input_dz(test2)[i][j]);
					k++;
				}
			}
			/////////////////////////////////////////////////////////////////////////////////
			Graf graf3;
			int* expected3;
			expected3 = new int[16];
			expected3[0] = 4;
			expected3[1] = 6;
			expected3[2] = 5;
			expected3[3] = 4;
			expected3[4] = 6;
			expected3[5] = 0;
			expected3[6] = 3;
			expected3[7] = 2;
			expected3[8] = 5;
			expected3[9] = 3;
			expected3[10] = 0;
			expected3[11] = 1;
			expected3[12] = 4;
			expected3[13] = 2;
			expected3[14] = 1;
			expected3[15] = 0;
			k = 0;
			for (int i = 0; i < graf3.input_dz(test3)[0][0]; i++) {
				for (int j = 0; j < graf3.input_dz(test3)[0][0]; j++)
				{
					Assert::AreEqual(expected3[k], graf3.input_dz(test3)[i][j]);
					k++;
				}
			}
			/////////////////////////////////////////////////////////////////////////////////
			Graf graf4;
			int* expected4;
			expected4 = new int[16];
			expected4[0] = 4;
			expected4[1] = 10;
			expected4[2] = 5;
			expected4[3] = 100;
			expected4[4] = 10;
			expected4[5] = 0;
			expected4[6] = 1;
			expected4[7] = 5;
			expected4[8] = 5;
			expected4[9] = 1;
			expected4[10] = 0;
			expected4[11] = 10;
			expected4[12] = 100;
			expected4[13] = 5;
			expected4[14] = 10;
			expected4[15] = 0;
			k = 0;
			for (int i = 0; i < graf4.input_dz(test4)[0][0]; i++) {
				for (int j = 0; j < graf4.input_dz(test4)[0][0]; j++)
				{
					Assert::AreEqual(expected4[k], graf4.input_dz(test4)[i][j]);
					k++;
				}
			}
		}
		TEST_METHOD(TEST_InitGraf)
		{
			Graf graf1;
			graf1.InitGraf(graf1.input_dz(test1));
			int num_vershin1 = 4;
			int num_rebro1 = 6;
			int *nodes1;
			nodes1 = new int[4];
			nodes1[0] = 0;
			nodes1[1] = 1;
			nodes1[2] = 2;
			nodes1[3] = 3;
			Graf::uzel *uzels1;
			uzels1 = new Graf::uzel[6];
			uzels1[0].v1 = 0;
			uzels1[0].v2 = 1;
			uzels1[0].wes = 3;
			uzels1[1].v1 = 0;
			uzels1[1].v2 = 2;
			uzels1[1].wes = 3;
			uzels1[2].v1 = 0;
			uzels1[2].v2 = 3;
			uzels1[2].wes = 3;
			uzels1[3].v1 = 1;
			uzels1[3].v2 = 2;
			uzels1[3].wes = 3;
			uzels1[4].v1 = 1;
			uzels1[4].v2 = 3;
			uzels1[4].wes = 3;
			uzels1[5].v1 = 2;
			uzels1[5].v2 = 3;
			uzels1[5].wes = 3;
			Assert::AreEqual(num_vershin1, graf1.num_vershin);
			Assert::AreEqual(num_rebro1, graf1.num_rebro);
			for (int k = 0;k < 4;k++)
				Assert::AreEqual(nodes1[k], graf1.nodes[k]);
			for (int k = 0;k < 6;k++)
			{
				Assert::AreEqual(uzels1[k].v1, graf1.uzels[k].v1);
				Assert::AreEqual(uzels1[k].v2, graf1.uzels[k].v2);
				Assert::AreEqual(uzels1[k].wes, graf1.uzels[k].wes);
			}
			/////////////////////////////////////////////////////////////////////////////////
			Graf graf2;
			graf2.InitGraf(graf2.input_dz(test2));
			int num_vershin2 = 4;
			int num_rebro2 = 6;
			int *nodes2;
			nodes2 = new int[4];
			nodes2[0] = 0;
			nodes2[1] = 1;
			nodes2[2] = 2;
			nodes2[3] = 3;
			Graf::uzel *uzels2;
			uzels2 = new Graf::uzel[6];
			uzels2[0].v1 = 0;
			uzels2[0].v2 = 1;
			uzels2[0].wes = 1;
			uzels2[1].v1 = 0;
			uzels2[1].v2 = 2;
			uzels2[1].wes = 2;
			uzels2[2].v1 = 0;
			uzels2[2].v2 = 3;
			uzels2[2].wes = 3;
			uzels2[3].v1 = 1;
			uzels2[3].v2 = 2;
			uzels2[3].wes = 4;
			uzels2[4].v1 = 1;
			uzels2[4].v2 = 3;
			uzels2[4].wes = 5;
			uzels2[5].v1 = 2;
			uzels2[5].v2 = 3;
			uzels2[5].wes = 6;
			Assert::AreEqual(num_vershin2, graf2.num_vershin);
			Assert::AreEqual(num_rebro2, graf2.num_rebro);
			for (int k = 0;k < 4;k++)
				Assert::AreEqual(nodes2[k], graf2.nodes[k]);
			for (int k = 0;k < 6;k++)
			{
				Assert::AreEqual(uzels2[k].v1, graf2.uzels[k].v1);
				Assert::AreEqual(uzels2[k].v2, graf2.uzels[k].v2);
				Assert::AreEqual(uzels2[k].wes, graf2.uzels[k].wes);
			}
			/////////////////////////////////////////////////////////////////////////////////
			Graf graf3;
			graf3.InitGraf(graf3.input_dz(test3));
			int num_vershin3 = 4;
			int num_rebro3 = 6;
			int *nodes3;
			nodes3 = new int[4];
			nodes3[0] = 0;
			nodes3[1] = 1;
			nodes3[2] = 2;
			nodes3[3] = 3;
			Graf::uzel *uzels3;
			uzels3 = new Graf::uzel[6];
			uzels3[0].v1 = 0;
			uzels3[0].v2 = 1;
			uzels3[0].wes = 6;
			uzels3[1].v1 = 0;
			uzels3[1].v2 = 2;
			uzels3[1].wes = 5;
			uzels3[2].v1 = 0;
			uzels3[2].v2 = 3;
			uzels3[2].wes = 4;
			uzels3[3].v1 = 1;
			uzels3[3].v2 = 2;
			uzels3[3].wes = 3;
			uzels3[4].v1 = 1;
			uzels3[4].v2 = 3;
			uzels3[4].wes = 2;
			uzels3[5].v1 = 2;
			uzels3[5].v2 = 3;
			uzels3[5].wes = 1;
			Assert::AreEqual(num_vershin3, graf3.num_vershin);
			Assert::AreEqual(num_rebro3, graf3.num_rebro);
			for (int k = 0;k < 4;k++)
				Assert::AreEqual(nodes3[k], graf3.nodes[k]);
			for (int k = 0;k < 6;k++)
			{
				Assert::AreEqual(uzels3[k].v1, graf3.uzels[k].v1);
				Assert::AreEqual(uzels3[k].v2, graf3.uzels[k].v2);
				Assert::AreEqual(uzels3[k].wes, graf3.uzels[k].wes);
			}
			/////////////////////////////////////////////////////////////////////////////////
			Graf graf4;
			graf4.InitGraf(graf4.input_dz(test4));
			int num_vershin4 = 4;
			int num_rebro4 = 6;
			int *nodes4;
			nodes4 = new int[4];
			nodes4[0] = 0;
			nodes4[1] = 1;
			nodes4[2] = 2;
			nodes4[3] = 3;
			Graf::uzel *uzels4;
			uzels4 = new Graf::uzel[6];
			uzels4[0].v1 = 0;
			uzels4[0].v2 = 1;
			uzels4[0].wes = 10;
			uzels4[1].v1 = 0;
			uzels4[1].v2 = 2;
			uzels4[1].wes = 5;
			uzels4[2].v1 = 0;
			uzels4[2].v2 = 3;
			uzels4[2].wes = 100;
			uzels4[3].v1 = 1;
			uzels4[3].v2 = 2;
			uzels4[3].wes = 1;
			uzels4[4].v1 = 1;
			uzels4[4].v2 = 3;
			uzels4[4].wes = 5;
			uzels4[5].v1 = 2;
			uzels4[5].v2 = 3;
			uzels4[5].wes = 10;
			Assert::AreEqual(num_vershin4, graf4.num_vershin);
			Assert::AreEqual(num_rebro4, graf4.num_rebro);
			for (int k = 0;k < 4;k++)
				Assert::AreEqual(nodes4[k], graf4.nodes[k]);
			for (int k = 0;k < 6;k++)
			{
				Assert::AreEqual(uzels4[k].v1, graf4.uzels[k].v1);
				Assert::AreEqual(uzels4[k].v2, graf4.uzels[k].v2);
				Assert::AreEqual(uzels4[k].wes, graf4.uzels[k].wes);
			}
		}
		TEST_METHOD(TEST_QuickSort)
		{
			Graf graf1;
			graf1.InitGraf(graf1.input_dz(test1));
			graf1.QuickSort(graf1.uzels, 0, graf1.num_rebro - 1);
			Graf::uzel *uzels1;
			uzels1 = new Graf::uzel[6];
			uzels1[0].v1 = 0;
			uzels1[0].v2 = 1;
			uzels1[0].wes = 3;
			uzels1[1].v1 = 0;
			uzels1[1].v2 = 2;
			uzels1[1].wes = 3;
			uzels1[2].v1 = 0;
			uzels1[2].v2 = 3;
			uzels1[2].wes = 3;
			uzels1[3].v1 = 1;
			uzels1[3].v2 = 2;
			uzels1[3].wes = 3;
			uzels1[4].v1 = 1;
			uzels1[4].v2 = 3;
			uzels1[4].wes = 3;
			uzels1[5].v1 = 2;
			uzels1[5].v2 = 3;
			uzels1[5].wes = 3;
			for (int k = 0;k < 6;k++)
			{
				Assert::AreEqual(uzels1[k].v1, graf1.uzels[k].v1);
				Assert::AreEqual(uzels1[k].v2, graf1.uzels[k].v2);
				Assert::AreEqual(uzels1[k].wes, graf1.uzels[k].wes);
			}
			/////////////////////////////////////////////////////////////////////////////////
			Graf graf2;
			graf2.InitGraf(graf2.input_dz(test2));
			graf2.QuickSort(graf2.uzels, 0, graf2.num_rebro - 1);
			Graf::uzel *uzels2;
			uzels2 = new Graf::uzel[6];
			uzels2[0].v1 = 0;
			uzels2[0].v2 = 1;
			uzels2[0].wes = 1;
			uzels2[1].v1 = 0;
			uzels2[1].v2 = 2;
			uzels2[1].wes = 2;
			uzels2[2].v1 = 0;
			uzels2[2].v2 = 3;
			uzels2[2].wes = 3;
			uzels2[3].v1 = 1;
			uzels2[3].v2 = 2;
			uzels2[3].wes = 4;
			uzels2[4].v1 = 1;
			uzels2[4].v2 = 3;
			uzels2[4].wes = 5;
			uzels2[5].v1 = 2;
			uzels2[5].v2 = 3;
			uzels2[5].wes = 6;
			for (int k = 0;k < 6;k++)
			{
				Assert::AreEqual(uzels2[k].v1, graf2.uzels[k].v1);
				Assert::AreEqual(uzels2[k].v2, graf2.uzels[k].v2);
				Assert::AreEqual(uzels2[k].wes, graf2.uzels[k].wes);
			}
			/////////////////////////////////////////////////////////////////////////////////
			Graf graf3;
			graf3.InitGraf(graf3.input_dz(test3));
			graf3.QuickSort(graf3.uzels, 0, graf3.num_rebro - 1);
			Graf::uzel *uzels3;
			uzels3 = new Graf::uzel[6];
			uzels3[0].v1 = 2;
			uzels3[0].v2 = 3;
			uzels3[0].wes = 1;
			uzels3[1].v1 = 1;
			uzels3[1].v2 = 3;
			uzels3[1].wes = 2;
			uzels3[2].v1 = 1;
			uzels3[2].v2 = 2;
			uzels3[2].wes = 3;
			uzels3[3].v1 = 0;
			uzels3[3].v2 = 3;
			uzels3[3].wes = 4;
			uzels3[4].v1 = 0;
			uzels3[4].v2 = 2;
			uzels3[4].wes = 5;
			uzels3[5].v1 = 0;
			uzels3[5].v2 = 1;
			uzels3[5].wes = 6;
			for (int k = 0;k < 6;k++)
			{
				Assert::AreEqual(uzels3[k].v1, graf3.uzels[k].v1);
				Assert::AreEqual(uzels3[k].v2, graf3.uzels[k].v2);
				Assert::AreEqual(uzels3[k].wes, graf3.uzels[k].wes);
			}
			/////////////////////////////////////////////////////////////////////////////////
			Graf graf4;
			graf4.InitGraf(graf4.input_dz(test4));
			graf4.QuickSort(graf4.uzels, 0, graf4.num_rebro - 1);
			Graf::uzel *uzels4;
			uzels4 = new Graf::uzel[6];
			uzels4[0].v1 = 1;
			uzels4[0].v2 = 2;
			uzels4[0].wes = 1;
			uzels4[1].v1 = 0;
			uzels4[1].v2 = 2;
			uzels4[1].wes = 5;
			uzels4[2].v1 = 1;
			uzels4[2].v2 = 3;
			uzels4[2].wes = 5;
			uzels4[3].v1 = 0;
			uzels4[3].v2 = 1;
			uzels4[3].wes = 10;
			uzels4[4].v1 = 2;
			uzels4[4].v2 = 3;
			uzels4[4].wes = 10;
			uzels4[5].v1 = 0;
			uzels4[5].v2 = 3;
			uzels4[5].wes = 100;
			for (int k = 0;k < 6;k++)
			{
				Assert::AreEqual(uzels4[k].v1, graf4.uzels[k].v1);
				Assert::AreEqual(uzels4[k].v2, graf4.uzels[k].v2);
				Assert::AreEqual(uzels4[k].wes, graf4.uzels[k].wes);
			}
		}
		TEST_METHOD(TEST_OutTree)
		{
			Graf graf1;
			Graf::uzel *actual1 = graf1.OutTree(graf1.input_dz(test1));
			Graf::uzel *expected1;
			expected1 = new Graf::uzel[3];
			expected1[0].v1 = 0;
			expected1[0].v2 = 1;
			expected1[0].wes = 3;
			expected1[1].v1 = 0;
			expected1[1].v2 = 2;
			expected1[1].wes = 3;
			expected1[2].v1 = 0;
			expected1[2].v2 = 3;
			expected1[2].wes = 3;
			for (int k = 0;k < 3;k++)
			{
				Assert::AreEqual(expected1[k].v1, actual1[k].v1);
				Assert::AreEqual(expected1[k].v2, actual1[k].v2);
				Assert::AreEqual(expected1[k].wes, actual1[k].wes);
			}
			/////////////////////////////////////////////////////////////////////////////////
			Graf graf2;
			Graf::uzel *actual2 = graf2.OutTree(graf2.input_dz(test2));
			Graf::uzel *expected2;
			expected2 = new Graf::uzel[3];
			expected2[0].v1 = 0;
			expected2[0].v2 = 1;
			expected2[0].wes = 1;
			expected2[1].v1 = 0;
			expected2[1].v2 = 2;
			expected2[1].wes = 2;
			expected2[2].v1 = 0;
			expected2[2].v2 = 3;
			expected2[2].wes = 3;
			for (int k = 0;k < 3;k++)
			{
				Assert::AreEqual(expected2[k].v1, actual2[k].v1);
				Assert::AreEqual(expected2[k].v2, actual2[k].v2);
				Assert::AreEqual(expected2[k].wes, actual2[k].wes);
			}
			/////////////////////////////////////////////////////////////////////////////////
			Graf graf3;
			Graf::uzel *actual3 = graf3.OutTree(graf3.input_dz(test3));
			Graf::uzel *expected3;
			expected3 = new Graf::uzel[3];
			expected3[0].v1 = 2;
			expected3[0].v2 = 3;
			expected3[0].wes = 1;
			expected3[1].v1 = 1;
			expected3[1].v2 = 3;
			expected3[1].wes = 2;
			expected3[2].v1 = 0;
			expected3[2].v2 = 3;
			expected3[2].wes = 4;
			for (int k = 0;k < 3;k++)
			{
				Assert::AreEqual(expected3[k].v1, actual3[k].v1);
				Assert::AreEqual(expected3[k].v2, actual3[k].v2);
				Assert::AreEqual(expected3[k].wes, actual3[k].wes);
			}
			/////////////////////////////////////////////////////////////////////////////////
			Graf graf4;
			Graf::uzel *actual4 = graf4.OutTree(graf4.input_dz(test4));
			Graf::uzel *expected4;
			expected4 = new Graf::uzel[3];
			expected4[0].v1 = 1;
			expected4[0].v2 = 2;
			expected4[0].wes = 1;
			expected4[1].v1 = 0;
			expected4[1].v2 = 2;
			expected4[1].wes = 5;
			expected4[2].v1 = 1;
			expected4[2].v2 = 3;
			expected4[2].wes = 5;
			for (int k = 0;k < 3;k++)
			{
				Assert::AreEqual(expected4[k].v1, actual4[k].v1);
				Assert::AreEqual(expected4[k].v2, actual4[k].v2);
				Assert::AreEqual(expected4[k].wes, actual4[k].wes);
			}
		}
		TEST_METHOD(TEST_unitenodes)
		{
			Graf graf1;
			graf1.OutTree(graf1.input_dz(test1));
			int *nodes1;
			nodes1 = new int[4];
			nodes1[0] = 0;
			nodes1[1] = 0;
			nodes1[2] = 0;
			nodes1[3] = 0;
			for (int k = 0;k < 3;k++)
				Assert::AreEqual(nodes1[k], graf1.nodes[k]);
			/////////////////////////////////////////////////////////////////////////////////
			Graf graf2;
			graf2.OutTree(graf2.input_dz(test2));
			int *nodes2;
			nodes2 = new int[4];
			nodes2[0] = 0;
			nodes2[1] = 0;
			nodes2[2] = 0;
			nodes2[3] = 0;
			for (int k = 0;k < 3;k++)
				Assert::AreEqual(nodes2[k], graf2.nodes[k]);
			/////////////////////////////////////////////////////////////////////////////////
			Graf graf3;
			graf3.OutTree(graf3.input_dz(test3));
			int *nodes3;
			nodes3 = new int[4];
			nodes3[0] = 0;
			nodes3[1] = 0;
			nodes3[2] = 0;
			nodes3[3] = 0;
			for (int k = 0;k < 3;k++)
				Assert::AreEqual(nodes3[k], graf3.nodes[k]);
			/////////////////////////////////////////////////////////////////////////////////
			Graf graf4;
			graf4.OutTree(graf4.input_dz(test4));
			int *nodes4;
			nodes4 = new int[4];
			nodes4[0] = 0;
			nodes4[1] = 0;
			nodes4[2] = 0;
			nodes4[3] = 0;
			for (int k = 0;k < 3;k++)
				Assert::AreEqual(nodes4[k], graf4.nodes[k]);
		}
		TEST_METHOD(TEST_output_dz)
		{
			Graf graf1;
			graf1.output_dz(graf1.input_dz(test1), test1actual);
			ifstream exp1(test1expected);
			ifstream act1(test1actual);
			string *stroka1expected;
			stroka1expected = new string[graf1.num_rebro];
			string *stroka1actual;
			stroka1actual = new string[graf1.num_rebro];
			int flag = 0;
			int k = 0;
			while (!exp1.eof() || !act1.eof())
			{
				getline(exp1, stroka1expected[k]);
				getline(act1, stroka1actual[k]);
				if (stroka1expected[k] != stroka1actual[k])
					flag = 1;
				k++;
			}
			exp1.close();
			act1.close();
			Assert::AreEqual(flag, 0, L"Wrong result");

			/////////////////////////////////////////////////////////////////////////////////
			Graf graf2;
			graf2.output_dz(graf2.input_dz(test2), test2actual);
			ifstream exp2(test2expected);
			ifstream act2(test2actual);
			string *stroka2expected;
			stroka2expected = new string[graf2.num_rebro];
			string *stroka2actual;
			stroka2actual = new string[graf2.num_rebro];
			flag = 0;
			k = 0;
			while (!exp2.eof() || !act2.eof())
			{
				getline(exp2, stroka2expected[k]);
				getline(act2, stroka2actual[k]);
				if (stroka2expected[k] != stroka2actual[k])
					flag = 1;
				k++;
			}
			exp2.close();
			act2.close();
			Assert::AreEqual(flag, 0, L"Wrong result");

			/////////////////////////////////////////////////////////////////////////////////
			Graf graf3;
			graf3.output_dz(graf3.input_dz(test3), test3actual);
			ifstream exp3(test3expected);
			ifstream act3(test3actual);
			string *stroka3expected;
			stroka3expected = new string[graf3.num_rebro];
			string *stroka3actual;
			stroka3actual = new string[graf3.num_rebro];
			flag = 0;
			k = 0;
			while (!exp3.eof() || !act3.eof())
			{
				getline(exp3, stroka3expected[k]);
				getline(act3, stroka3actual[k]);
				if (stroka3expected[k] != stroka3actual[k])
					flag = 1;
				k++;
			}
			exp3.close();
			act3.close();
			Assert::AreEqual(flag, 0, L"Wrong result");

			/////////////////////////////////////////////////////////////////////////////////
			Graf graf4;
			graf4.output_dz(graf4.input_dz(test4), test4actual);
			ifstream exp4(test4expected);
			ifstream act4(test4actual);
			string *stroka4expected;
			stroka4expected = new string[graf4.num_rebro];
			string *stroka4actual;
			stroka4actual = new string[graf4.num_rebro];
			flag = 0;
			k = 0;
			while (!exp4.eof() || !act4.eof())
			{
				getline(exp4, stroka4expected[k]);
				getline(act4, stroka4actual[k]);
				if (stroka4expected[k] != stroka4actual[k])
					flag = 1;
				k++;
			}
			exp4.close();
			act4.close();
			Assert::AreEqual(flag, 0, L"Wrong result");
		}
	};
}