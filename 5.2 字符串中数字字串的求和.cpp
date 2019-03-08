#include<string>
using namespace std;

int numSum(string& str){
	if(str.length() == 0){
		return 0;
	}
	
	int res = 0;//局部变量定义的时候一定要初始化！！！
	int num = 0;
	int cur = 0;
	bool posi = true;
	for(int i = 0;i < str.length();i++){
		cur = str[i] - '0';
		if(cur < 0 || cur > 9){
			res += num;
			num = 0;
			if(str[i] == '-'){
				if(i - 1 >= 0 && str[i - 1] == '-'){
					posi = !posi;
				}
				else posi = false;
			}
		}
		else num = num * 10 + (posi ? cur : -cur);
	}
	res += num;//防止字符串最后一个是数字而没有累加上
	return res;
}

/*
思路：
使用三个变量：res，num和posi。res表示目前的累加和，num表示当前收集到的数字，posi表示数字num是正数还是负数，True表示正数，初始时res = 0, num = 0, posi = True。

从左到右依次遍历字符串，假设遍历到的字符为char。情况分析如下：

1）如果char是 ‘0’ ~ ‘9’，假设之前收集的数字为num，则可以根据posi更新num的值，如果posi == True，则num = num×10 + (char - ‘0’)，否则num = num×10 - (char - ‘0’)。posi的更新方法之后解释。

2）如果char不是 ‘0’ ~ ‘9’，则说明num已经是一个完整的数字了，该累加到res了，所以res += num，然后令num = 0。累加完后观察此时char的值，如果此时的字符不是“-”，则令posi = True，如果此时的字符为“-”，判断前一个字符是否也是“-”，如果是的话，令 posi = ！posi，否则令posi = False。

累加的时机放在了char不是数字字符的时候，但如果str是以数字字符结尾的，那么就会出现最后一个字符没有累加的情况。所以遍历完成后，还要再加一次num。

*/