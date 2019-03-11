/*

*/

#include<vector>
#include<iostream>

void spiralOrderPrint(vector<vector<int>> m){
	if(m.size() == 0){
		count<<0<<endl;
		return;
	}
	int tr = 0;
	int tc = 0;
	int dr = m.size() - 1;
	int dc = m[0].size() - 1;
	while(tr <= dr && tc <= dc){
		if(tr == dr){
			for(int i = tc;i <= dc;i++){
				cout<<m[tr][i]<<",";
			}
		}
		else if(tc == dc){
			for(int i = tr;i <= dr;i++){
				cout<<m[i][tr]<<",";
			}
		}
		else{
			int curC = tc;
			int curR = tr;
			while(curC != dc){
				cout<<m[tr][curC]<<",";
				curC++;
			}
			while(curR != dr){
				cout<<m[curR][dc]<<",";
				curR++;
			}
			while(curC != tc){
				cout<<m[dr][curC]<<",";
				curC--;
			}
			while(curR != tr){
				cout<<m[curR][tc]<<",";
				curR--;
			}
		}
		tr += 1;
		tc += 1;
		dr -= 1;
		dc -= 1;
	}
}
/*
思路：
一层一层的打印矩阵。在矩阵中用左上角(tR, tC)和右下角(dR, dC)就可以表示一个子矩阵。比如，题目中的矩阵，当(tR, tC) = (0,0), (dR, dC) = (3,3)。表示的子矩阵就是整个矩阵，它的最外圈的部分如下： 
　　１ 　２　 ３ 　４ 
　　５ 　　 　 　　８ 
　　９ 　 　　 　　12 
　　13　14 　15　16 
转圈把这个外层打印出来，然后令tR, tC加１，dR, dC减１，这时所表示的子矩阵就是： 
　　6　 ７ 
　　10　11 
继续转圈打印出来即可。

LeetCode 54 Spiral Matrix
https://leetcode-cn.com/problems/spiral-matrix/submissions/
*/