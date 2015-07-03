#求最长回文子串之Manacher算法

##目录
  - [简述](#简述)
  - [原理](#原理)
    - [基本思想](#基本思想)
    - [算法步骤](#算法步骤)
    - [如何构造 数组p](#如何构造 数组p)
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

#### 如何构造 数组p

---

### 参考代码

---

### 练习题目

---

### 参考资料
[The-Art-Of-Programming-By-July之最长回文子串](https://github.com/julycoding/The-Art-Of-Programming-By-July/blob/master/ebook/zh/01.05.md)
[Longest palindromic substring](https://en.wikipedia.org/wiki/Longest_palindromic_substring#CITEREFApostolicoBreslauerGalil1995)
