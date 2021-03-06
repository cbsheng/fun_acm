#求最长回文子串之Manacher算法

##目录
  - [简述](#简述)
  - [原理](#原理)
    - [基本思想](#基本思想)
    - [算法步骤](#算法步骤)
    - [预处理的作用](#预处理的作用)
    - [如何构造数组p](#如何构造数组p)
  - [参考代码](#参考代码)
  - [练习题目](#练习题目)
  - [参考资料](#参考资料)
  
  
### 简述
  Manacher 算法由[Glenn K Manacher](http://dl.acm.org/author_page.cfm?id=81100608621&coll=DL&dl=ACM&trk=0&cfid=525101898&cftoken=42942920)发明，发表于1975年的[论文](http://dl.acm.org/citation.cfm?doid=321892.321896)，用来解决在某个字符串中寻找最长的[回文子串](https://en.wikipedia.org/wiki/Palindrome)。回文串指一个字符串从左至右和从右至左读都是一样的。例如：'abcdcba'。
  
  解决最长回文串这个问题不只有 Manacher 算法，还是诸如O(nlogn)的后缀数组或 O(n^2)的 DP 解法。但Manacher 可以在线性时间内解决。是一个十分高效的算法。空间的话，则需要两个长度都为 len*2+1 的 S 数组和 p 数组。前者用来存储预处理后的原始字符串，后者用来记录以 S[i] 的中心的回文子串向左或向右扩展的长度。
  
---

### 原理
#### 基本思想
  Manacher 算法主要优化了每次以 S[i] 为中心向两边扩展以检查回文子串长度时所做的重复性工作。这是根据回文串的左右两边对称的特点。例如有字符串 s=“abcdcba”：
  
元素值 | a | b | c | d | c | b | a
--- | --- | --- | --- | --- | --- | --- | ---
下标   | 0 | 1 | 2 | 3 | 4 | 5 | 6

  求以 s[5] 为中心的回文串长度，我们就可以利用 s[1] 为中心的回文串长度减少重复性工作。所以就要用 数组p 记录前面已经做过的工作。
  

#### 算法步骤
  1. 先对原始字符串进行预处理(在每个字符两边加上字符#，在字符串最开始加上字符$。例：'abc'-> '$abc')
  2. 然后线性构造出数组p。
  3. 找出数组p 中最大值，(最大值-1）即是最长回文串的长度。
  
详细如下表：原始字符串 s=“ababcbaba”。

预处理后S' | $ | # | a | # | b | # | a | # | b | # | c | # | b | # | a | # | b | # | a | # | ‘\0’
--- | ---  | ---  | ---  | ---  | ---  | ---  | ---  | ---  | ---  | ---  | ---  | ---  | ---  | ---  | ---  | ---  | ---  | ---  | ---  | ---  | ---
数组 p   | 0 | 1 | 2 | 1 | 2 | 1 | 4 | 1 | 2 | 1 | 10 | 1 | 2 | 1 | 4 | 1 | 4 | 1 | 2 | 1 | 0
下标     | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 | 15 | 16 | 17 | 18 | 19 | 20


字符串 s 的最长的回文子串是 p[10] - 1 = 9。


#### 预处理的作用
预处理主要是两步：
  1. 加'#'。这样就将字符串长度可能是偶数或奇数的情况统一转换为奇数，len(s)*2+1 是奇数，无论 len(s)是偶或奇。
  2. 加'$'。这样为了方便比较。例如以S'[1]为中心时，两边的比较。


#### 如何构造数组p
  Manacher 算法设两个变量 id 和 mx 。前者指代回文串中心字符的下标，后者mx = p[id] + id，即回文串的边界。
  
  那么每一个 p[i]都有这样的递推式：
  
    p[i] = min{ p[2 * id - i], mx - i }     仅当 mx > i 时
    p[i] = 1    当 mx <= i 时

  
  

---

### 参考代码

```c++
int longest_plalindrome_substring(char *s)
{//p[i] = min{p[2 * id - 1], mx - i}
	int id = 0, mx = 0, max = 0;
	for (int i = 1; s[i] != '\0'; ++i) {
		p[i] = mx > i ? min(p[2 * id - i], mx - i) : 1;
		while (s[i + p[i]] == s[i - p[i]]) p[i]++;
		if ((i + p[i]) > mx) {
			mx = i + p[i];
			id = i;
		}
		if (max < p[i]) max = p[i];
	}
	return max - 1;
}
```

---

### 练习题目
- [hihocoder 1032](http://hihocoder.com/problemset/problem/1032)
- [hdu 3294](http://acm.hdu.edu.cn/showproblem.php?pid=3294)


---

### 参考资料
- [The-Art-Of-Programming-By-July之最长回文子串](https://github.com/julycoding/The-Art-Of-Programming-By-July/blob/master/ebook/zh/01.05.md)
- [Longest palindromic substring](https://en.wikipedia.org/wiki/Longest_palindromic_substring#CITEREFApostolicoBreslauerGalil1995)
