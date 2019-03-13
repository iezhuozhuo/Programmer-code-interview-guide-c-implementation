/*
给定一个以p概率产生0，以1-p概率产生1的随机函数rand01p	
除此之外，不使用任何额外的随机机制，请用rand01p实现等概率随机产生1~6的随机函数rand1To6
*/

//虽然rand01p方法是以p的概率产生0，以1-p的概率产生1
//但是rand01p产生01和10的概率却都是p(1-p)，可以利用两次随机来实现等概率随机产生0和1的函数
//假设rand01p存在，构造等概率随机产生0和1的函数rand01
int rand01(){
	int num = 0;
	do{
		num = rand01p();
	}while(num == rand01p());
	return num; //num的概率是p(1-p)
}

//构造随机数6 但是6 > 2*2 = 4 又因为6 < 4*4 所以要构造rand3函数(从0到3 4个数)
int rand3(){
	int num = 0;
	num = 2 * rand01() + rand01();//这时num 取值 0、1、2、3等概率
	return num;
}

//构造1-6的随机函数rand1To6
int rand1To6(){
	int num = 0;
	do{
		num = 4 * rand3() + rand3();
	}while(num > 11);//这时可以等产生0-12的数
	return num % 6 + 1;
}

