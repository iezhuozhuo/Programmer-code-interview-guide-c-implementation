#include<vector>

void rotateEdge(vector<vector<int>>& m, int tc, int tr, int dc, int dr){
	int time = dc - tc;
	for(int i = 0;i != time;i++){
		int temp = m[tr][tc + i];
		m[tr][tc + i] = m[dr - i][tc];
		m[dr - i][tc] = m[dr][dc - i];
		m[dr][dc - i] = m[tr + i][dc];
		m[tr + i][dc] = temp;
	}
}

void rotate(vector<vector<int>>& m){
	if(m.size() == 0){
		return;
	}
	int tc = 0;
	int tr = 0;
	int dc = m[0].size() - 1;
	int dr = m.size() - 1;
	while(tr < dr){
		rotateEdge(m, tc++, tr++, dc--, dr--);
	}
}
/*
思路：
	分圈处理。在矩阵中用左上角(tR, tC)和右下角(dR, dC)就可以表示一个子矩阵。比如，题目中的矩阵，当(tR, tC) = (0,0), (dR, dC) = (3,3)。表示的子矩阵就是整个矩阵，它的最外圈的部分如下： 
　　１ 　２　 ３ 　４ 
　　５ 　　 　 　　８ 
　　９ 　 　　 　　12 
　　13　14 　15　16 
　　在这个外圈中，1,4,16,13为一组，然后让1占据4的位置，4占据16的位置，16占据13的位置，13占据1的位置，这样一组就调整完了。然后2,8,15,9为一组，继续调整。最后3,12,14,5为一组，继续调整。都调整完之后，这一圈就旋转完毕。令tR, tC加1，dR,dC减1，开始处理下一个子矩阵的外圈。原理同上。

*/