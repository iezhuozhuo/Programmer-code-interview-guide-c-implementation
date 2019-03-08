/*
补充问题2：假设农场中成熟的母牛每年只会生一头小母牛，并且永远不会死。
		   第一年农场有１只成熟的牛，从第二年开始，母牛开始生小母牛。
		   每只小母牛３年之后 成熟又可以生小母牛。给定整数Ｎ，返回Ｎ年后牛的数量。
*/
#include <iostream>
#include <vector>
using namespace std;

int s1(int n){
	if(n < 1){
		return 0;
	}
	if(n == 1 || n ==2 || n == 3){
		return n;
	}
	return s1(n - 1) + s1(n - 3);
}

int s2(int n){
	if(n < 1){
		return 0;
	}
	if(n == 1 || n ==2 || n == 3){
		return n;
	}
	int prepre = 1;
	int pre = 2;
	int res = 3;
	for(int i = 4;i <= n;i++){
		int temp = res;
		res += prepre
		prepre = pre;
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
		temp = mulMatrix(temp,temp);
	}
	return res;
}

int s3(int n){
	if(n < 1){
		return 0;
	}
	if(n == 1 || n ==2 || n == 3){
		return n;
	}
	vector<vector<int>>base = {{1,1,0},{0,0,1},{1,0,0}};
	vector<vector<int>>result = matrixPower(base, n - 3);
	return 3 * result[0][0] + 2 * result[1][0] + result[2][0];
}