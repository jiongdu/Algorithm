题目描述:
利用字符重复出现的次数，编写一个方法，实现基本的字符串压缩功能。比如，字符串“aabcccccaaa”经压缩会变成“a2b1c5a3”。若压缩后的字符串没有变短，则返回原先的字符串。
给定一个string iniString为待压缩的串(长度小于等于10000)，保证串内字符均由大小写英文字母组成，返回一个string，为所求的压缩后或未变化的串。

测试样例
"aabcccccaaa"
返回："a2b1c5a3"
"welcometonowcoderrrrr"
返回："welcometonowcoderrrrr"

题目解析:
做的时候，开始选择的是char类型来保存连续字符的个数，忽略了如果连续字符的个数大于10时的情况，所以，使用了C++11新特性to_string。

题目地址:
http://www.nowcoder.com/practice/21f3a84300c94db092e0b5a7bf2d0ad1?tpId=8&tqId=10998&rp=1&ru=/ta/cracking-the-coding-interview&qru=/ta/cracking-the-coding-interview/question-ranking