#include <stdio.h>   
#include <stdlib.h>  
typedef struct member  
{  
    int number;  
    struct member * next;  
} Member;  
typedef Member* list;  
Member* ADD(list * plist, int num);  
void SUB(list * pre, list * cur, int x, int y);  
int main(void)  
{  
    int i,fina;  
    int n, m, f;  
    list one;  
    Member * last;  
    Member * fore;  
    while (scanf("%d %d %d", &n, &f, &m) == 3 && n!=0)  
    {  
        one = NULL;  
        for (i=1;i<=n;i++)  
        {  
            last = ADD(&one,i);  
        }  
        last->next = one;  
        fore = last;  
        while (one->next != one)  
        {  
            for (i=1;i<m;i++)  
            {  
                fore = one;  
                one = one->next;  
            }  
            SUB(&fore,&one,n, f);  
        }  
        fina = (one->number+f-1);  
        fina = (fina>n) ? fina%n : fina;  
        printf("The last one is No.%d\n",fina);  
        free(one);  
    }  
    return 0;  
}  
Member * ADD(list * plist, int num)  
{  
    Member* pnew = (Member*)malloc(sizeof(Member));  
    if (pnew == NULL)  
        return NULL;  
    Member* scan = *plist;  
    pnew->number = num;  
    pnew->next = NULL;  
    if (scan==NULL)  
        *plist = pnew;  
    else  
    {  
        while (scan->next != NULL)  
            scan = scan->next;  
        scan->next = pnew;  
    }  
    return pnew;  
}  
void SUB(list*pre, list*cur, int x,int y )  //传入总人数,与起报人数  
{  
    int moved;  
    Member* pre_ = *pre;  
    Member* cur_ = *cur;  
    moved = cur_->number+y-1;  
    moved = (moved > x) ? moved%x : moved;  
    printf("No.%d has been moved.\n",moved);  
    pre_->next = cur_->next;  
    *cur = cur_->next;  
    free(cur_);  
}  
