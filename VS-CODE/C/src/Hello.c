
  #include<miracl.h>
  #include<mirdef.h>
  #include <stdio.h>
  
  int main() 
 {
     FILE *fp;
     int i = 0, k, probability = 1;//k是安全参数，pr是概率
     printf("请输入安全参数k：");
     scanf("%d",&k);
     big m, r, g, a, b, m_4;
     miracl *mip = mirsys(4000, 10);//初始化MIRACL系统,4000位的10进制数
     m = mirvar(0);//big类型初始化函数
     m_4 = mirvar(0);
     r = mirvar(0);
     g = mirvar(0);
     a = mirvar(0);
     b = mirvar(1);
     fp = fopen("20.txt", "r+");
     mip->IOBASE = 10; 
     cinnum(m, fp);//将大数字符串转换成大数
     fclose(fp);
     //奇数m,若取任意整数2<=a<=m-2，gcd（a，m）=1，使得a^(m-1)=1（mod m），则m有1/2的概率为素数
     for (i = 0;i<k;i++) 
     {
         probability = probability * 2;
         decr(m, 4, m_4);//m_4=m-4
         bigrand(m_4, a);//产生一个小于m-4的大数随机数a
         printf("随机数a=");
         cotnum(a, stdout);
         incr(a, 2, a);//a=a+2，这样可以保证a>=2且a<=m-2
         decr(m, 1, g);//g=m-1，作为计算模的指数
         powmod(a, g, m, r);//r=a^g （mod m），如果r=1，那么m就有二分之一的概率为素数
         egcd(a, m, g);//g=gcd(a,m)
         if (mr_compare(g, b) || mr_compare(b, r))//如果gcd(a,m)不等于1或模值r不等于1，不是素数，跳出
 {
             printf("gcd(a.m)不等于1或r不等于1\n");
             break;
         }
         else
             printf("最大公约数为1，模值为1，因此输入有%d/%d可能为素数\n",probability - 1, probability);
     }
     printf("由此可得所输入的数字：\n");
    cotnum(m, stdout);//输出m
     if (i == k)
        printf("有%d/%d的可能性输入的是素数\n",probability - 1, probability);
     else 
         puts("不是素数\n");
     mirexit();
    return 0;
}