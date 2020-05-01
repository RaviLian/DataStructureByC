#include<stdio.h>
#include<string.h>
/**
 * https://wiki.jikexueyuan.com/project/kmp-algorithm/define.html
 * 有一个文本串 S，和一个模式串 P，现在要查找 P 在 S 中的位置
*/

int next[8];

int BruteForce (char *s, char *p);
void GetNext(char* p,int next[]);
int KmpSearch (char *s, char *p);
void GetNextval(char* p, int next[]);
int KmpSearch_Modified(char* s, char* p);

int main() {
  char *s = "BBC ABCDAB ABCDABCDABDE";
  char *p = "ABCDABD";
  // printf("%d",BruteForce(s,p));
  GetNext(p,next);
  printf("%d\n",KmpSearch(s,p));

  GetNextval(p,next);
  printf("%d\n",KmpSearch_Modified(s,p));
  return 0;
}

/**暴力破解
 * ①如果当前字符匹配成功（即 S[i] == P[j]），则 i++，j++，继续匹配下一个字符；
 * ②如果失配（即 S[i]! = P[j]），令 i = i - (j - 1)，j = 0。
 *   相当于每次匹配失败时，i 回溯，j 被置为0。
*/
int BruteForce (char *s, char *p) {
  int sLen = strlen(s);
  int pLen = strlen(p);
  int i = 0;  
  int j = 0;  
  while (i < sLen && j < pLen)  
  {  
    if (s[i] == p[j])  
    {  
      //①如果当前字符匹配成功（即S[i] == P[j]），则i++，j++      
      i++;  
      j++;  
    }  
    else  
    {  
      //②如果失配（即S[i]! = P[j]），令i = i - (j - 1)，j = 0      
      i = i - j + 1;  
      j = 0;  
    }  
  }  
  //匹配成功，返回模式串p在文本串s中的位置，否则返回-1  
  if (j == pLen)  
    return i - j;  
  else  
    return -1;  
}

void GetNext(char* p,int next[])  
{  
    int pLen = strlen(p);  
    next[0] = -1;  
    int k = -1;  
    int j = 0;  
    while (j < pLen - 1)  
    {  
        //p[k]表示前缀，p[j]表示后缀  
        if (k == -1 || p[j] == p[k])   
        {  
            ++k;  
            ++j;  
            next[j] = k;  
        }  
        else   
        {  
            k = next[k];  
        }  
    }  
}  

/**
 * 假设现在文本串 S 匹配到 i 位置，模式串 P 匹配到 j 位置
 *  如果 j = -1，或者当前字符匹配成功（即 S[i] == P[j]），都令 i++，j++，继续匹配下一个字符；
 *  如果 j != -1，且当前字符匹配失败（即 S[i] != P[j]），则令 i 不变，j = next[j]。此举意
 *  味着失配时，模式串 P 相对于文本串 S 向右移动了 j - next [j] 位。
 *      当匹配失败时，模式串向右移动的位数为：失配字符所在位置 - 失配字符对应的 next 值
 *      即移动的实际位数为：j - next[j]，且此值大于等于1
 * 
 * next 数组各值的含义：代表当前字符之前的字符串中，有多大长度的相同前缀后缀。
*/
int KmpSearch (char *s, char *p) {
    int i = 0;  
    int j = 0;  
    int sLen = strlen(s);  
    int pLen = strlen(p);  
    while (i < sLen && j < pLen)  
    {  
        //①如果j = -1，或者当前字符匹配成功（即S[i] == P[j]），都令i++，j++      
        if (j == -1 || s[i] == p[j])  
        {  
            i++;  
            j++;  
        }  
        else  
        {  
            //②如果j != -1，且当前字符匹配失败（即S[i] != P[j]），则令 i 不变，j = next[j]      
            //next[j]即为j所对应的next值        
            j = next[j];  
        }  
    }  
    if (j == pLen)  
        return i - j;  
    else  
        return -1;  
}

void GetNextval(char* p, int next[]) {
    int pLen = strlen(p);  
    next[0] = -1;  
    int k = -1;  
    int j = 0;  
    while (j < pLen - 1)  
    {  
        //p[k]表示前缀，p[j]表示后缀    
        if (k == -1 || p[j] == p[k])  
        {  
            ++j;  
            ++k;  
            //较之前next数组求法，改动在下面4行  
            if (p[j] != p[k])  
                next[j] = k;   //之前只有这一行  
            else  
                //因为不能出现p[j] = p[ next[j ]]，所以当出现时需要继续递归，k = next[k] = next[next[k]]  
                next[j] = next[k];  
        }  
        else  
        {  
            k = next[k];  
        }  
    }  
}

int KmpSearch_Modified(char* s, char* p) {
    int i = 0;  
    int j = 0;  
    int sLen = strlen(s);  
    int pLen = strlen(p);  
    while (i < sLen && j < pLen)  
    {  
        //①如果j = -1，或者当前字符匹配成功（即S[i] == P[j]），都令i++，j++      
        if (j == -1 || s[i] == p[j])  
        {  
            i++;  
            j++;  
        }  
        else  
        {  
            //②如果j != -1，且当前字符匹配失败（即S[i] != P[j]），则令 i 不变，j = next[j]      
            //next[j]即为j所对应的next值        
            j = next[j];  
        }  
    }  
    if (j == pLen)  
        return i - j;  
    else  
        return -1;  
}