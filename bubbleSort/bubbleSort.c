#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<sys/time.h>

void bubbleSort(int a[], int n)
{
    for(int i = 0; i < n - 1; i++) {

        for (int j = 0; j < n - i - 1; j++) {

            if(a[j] > a[j + 1]) {
                int temp = 0;
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }

}

int Rand()
{
    struct timeval tms;
    char tstr[100];
    timerclear(&tms);
    gettimeofday(&tms,NULL);
    strftime(tstr,100,"%X",localtime(&tms.tv_sec));
    // 微妙级的时间作为参数
	srand((unsigned)tms.tv_usec);
    
	int a=(rand()% 1000 + 1);
	return a;
}

void write(int yourNumbers[], int n)
{
    // 1.用户随机输入n个数字
    printf("请输入%d个随机数字\n", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &yourNumbers[i]);
        printf("第%d个数字：%d\n", i + 1, yourNumbers[i]);    
    }

}

void randWrite(int yourNumbers[], int n)
{
    // 2.利用随机数生成函数随机生成n个数字
    printf("以下是随机生成的%d个1000以内的自然数\n", n);

    for(int i = 0; i < n; i++) {
        yourNumbers[i] = Rand();
        printf("%d\t", yourNumbers[i]);
    }
    printf("\n");

}

int count(int n)
{
    printf("请输入数字的数量（不少于10个):\n");
    loop:
    scanf("%d", &n);
    if(n < 10) {
        printf("您输入的数字小于10，请重新输入:\n");
        goto loop;
    }

    return n;
}

void choose()
{

}

int main()
{
    // 不同的输入

    // 输入数字个数
    int n = 0;
    n = count(n);
    int yourNumbers[n];

    // 选择数字生成方式
    int choose = 0;
    printf("请选择数字生成方式:\n手动输入请输入‘1’\t自动生成请输入‘2’\n");
    scanf("%d", &choose);
    if(choose == 1) {
        write(yourNumbers, n);
    }else if(choose == 2) {
        randWrite(yourNumbers, n);
    }else {
        printf("输入有误\n");
        return 0;
    }
    
    // 调用冒泡排序
    printf("以下是冒泡排序法的排序结果\n");
    bubbleSort(yourNumbers, n);

    // 打印排序后的数字
    for(int i = 0; i < n; i++) {
        printf("%d\t", yourNumbers[i]);
    }
    printf("\n");


    return 0;
}
