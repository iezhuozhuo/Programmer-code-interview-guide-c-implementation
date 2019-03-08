bool isDeformation(string&, s1, string& s2){
	if(s1 == NULL || s2 == NULL || s1.length() != s2.length()){
		return false;
	}
	int[256] str = {0};
	for(char& c : s1){
		str[c]++;
	}
	for(char& c : s2){
		str[c]--;
		if(str[c] < 0){
			return false;
		}
	}
	return true;
}

/*
如果两个字符串的长度不相同，直接返回False

假设出现的字符的编码值在0~255之间，即是ASCII编码，那么先申请一个长度为256的整型数组array，arr[a] = b，表示字符a出现的次数是b，依次遍历字符串str1，统计每种字符出现的数量，相当于统计每种字符的词频。

遍历字符串str2，每遍历到一个字符都在array数组中把词频减1，如果减少之后的值小于0，直接返回False。如果遍历完str2，array中的值也没有成为负数，则返回True。

为什么只考虑词频最后是否有负数？因为如果最后有的词频为正数，说明str1的长度一定大于str2，这种情况在步骤一的时候就已经剔除了
*/