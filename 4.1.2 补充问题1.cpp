/*
补充问题1：
	给定整数N，代表台阶数，一次可以跨2个或者1个台阶，返回有多少种走法
*/
#include <iostream>
#include <vector>
using namespace std;

int s1(int n){
	if(n < 1){
		return 0;
	}
	if(n ==1 || n == 2){
		return n;
	}
	return s1(n - 1) + s2(n - 2);
}

int s2(int n){
	if(n < 1){
		return 0;
	}
	if(n ==1 || n == 2){
		return n;
	}
	int res = 2;
	int pre = 1;
	for(int i = 3;i <= n;i++){
		int temp = res;
		res += pre;
		pre = temp;
	}
	return res;
}

vector<vector<int>> mulMatrix(vector<vector<int>>& m1, vector<vector<int>>& m2){
	vector<vector<int>>res(m1.size(), vector<int>(m2[0].size()));
	for(int i = 0;i < m1.size();i++){
		for(int j = 0;j < m2[0].size();j++){
			for(int k = 0;k < m2.size();k++){
				res[i][j] += m1[i][k] * m2[k][j];
			}
		}
	}
	return res;
}

vector<vector<int>> matrixPower(vector<vector<int>>& m, int p){
	vector<vector<int>>res(m.size(), vector<int>(m[0].size()));
	for(int i = 0;i < res.size();i++){
		res[i][i] = 1;
	}
	vector<vector<int>>temp = m;
	for(;p != 0;p >>= 1){
		if(p & 1){
			res = mulMatrix(res, temp);
		}
		temp = mulMatrix(temp, temp);
	}
	return res;
}

int s3(int n){
	if(n < 1){
		return 0;
	}
	if(n ==1 || n == 2){
		return n;
	}
	vector<vector<int>>base = {{1, 1},{1, 0}};
	vector<vector<int>>res = matrixPower(base, n - 2);
	return 2 * res[0][0] + res[0][1];
	
}

