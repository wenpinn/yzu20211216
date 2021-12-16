/*
 *  @author : wen-pinn fang <wpfang@saturn.yzu.edu.tw>
 *  @version : 1.0
*/

/*
 *  @author : DaynaLin <s1102008@mail.yzu.edu.tw>
*/

#include "stdafx.h"
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	int card[52];
	int player[2][13];
	char suit[] = { 'C', 'D', 'H', 'S' };
	char rank[13] = { 'A', '2', '3', '4', '5', '6', '7', '8', '9', '10', 'J', 'Q', 'K' };
	srand(time(0));
	int i;
	//----- initial -----
	for (i = 0; i < 52; i++)
		card[i] = i;
	//---- shuffle ------
	int r1, r2;
	for (i = 0; i < 104; i++)
	{
		r1 = rand() % 52;
		r2 = rand() % 52;
		int temp;
		temp = card[r1];
		card[r1] = card[r2];
		card[r2] = temp;
	}
	//----show result of shuffle -----
	for (i = 0; i < 52; i++)
	{
		cout << card[i] << "\t";
	}
	cout << endl;
	cout << "--------------------------" << endl;
	//---- send two hands
	int j;
	int k = 0;
	for (i = 0; i < 13; i++)
	for (j = 0; j < 2; j++)
	{
		player[j][i] = card[k];
		k++;
	}
	//--- show table ----
	for (i = 0; i < 2; i++)
	{

		for (j = 0; j < 13; j++)
		{
			cout  << suit[player[i][j] / 13] << rank[player[i][j] % 13]<<" ";
		}
		cout << endl;
	}
	return 0;
}

