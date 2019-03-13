/*
给定一个等概率产生1~5的随机函数 rand1To5
除此之外，不使用任何额外的随机机制，请用rand1To5实现等概率随机产生1～7的随机函数rand1To7。
*/

//假设rand1To5已经定义好,可以产生均匀分布[1,5]的随机数
int rand1To7(){
	int val = 0;
	int t = 21;//7 < 5*5的最大倍数
	do{
		val = 5 * (rand1To5() - 1) + rand1To5();
	}while(val > t);
	return val % 7 + 1;
}