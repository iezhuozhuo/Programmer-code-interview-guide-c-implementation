/*
原始问题：给定整数Ｎ，返回斐波那契数列的第Ｎ项
*/

//原始问题求解

//时间复杂度是O(2^N)的
int fibonacci1(int n){
	if(n < 1){
		return 0;
	}
	if(n == 1 || n == 2){
		return 1;
	}
	return fibonacci1(n - 1) + fibonacci1(n - 2);
}

//时间复杂度是O(N)
int fibonacci2(int n){//从左往右扫描一直走到N处
	if(n < 1){
		return 0;
	}
	if(n == 1 || n == 2){
		return 1;
	}
	int pre = 1;
	int result = 1;
	for(int i = 3;i <= n;i++){
		int temp = result;
		result = result + pre;
		pre = temp;
	}
	return result;
}

//时间复杂度是O(logN)
//将其转换为求一个矩阵的N次方的问题

vector<vector<int>> mulMatrix(vector<vector<int>>& m1, vector<vector<int>>& m2){//矩阵乘法对应行列先乘后加
	vector<vector<int>> res(m1.size(), vector<int>(m2.size()));
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
	vector<vector<int>> res(m.size(), vector<int>(m[0].size()));//创建二维矩阵
	for(int i = 0;i < m.size();i++){//将其转换成单位矩阵
		res[i][i] = 1;
	}
	
	vector<vector<int>> temp = m;
	for(;p != 0;p >>= 1){//右移一位
		if(p & 1){//只有当前位置为一才能与结果相乘
			res = mulMatrix(res, temp);
		}
		temp = mulMatrix(temp, temp);
	}
	return res;
}


int fibonacci3(int n){
	if(n < 1){
		return 0;
	}
	if(n == 1 || n == 2){
		return 1;
	}
	vector<vector<int>>base = {{1,1}, {1,0}};
	vector<vector<int>>res = matrixPower(base, n - 2);
	return res[0][0] + res[1][0];
}
