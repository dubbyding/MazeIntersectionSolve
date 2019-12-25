#include<stdio.h>
#include<conio.h>
//this whole thing can be removed
int input(int *a, int *b, int *c){
    int left[] ={1,1,0};
    int right[] = {1,0,0};
    int cond = *c;
    *a = left[cond];
    *b = right[cond];
    if(cond==3){
        return 0;
    }else{
        return 1;
    }
}
void Direction(){
    int q1[100],i=0,j=0,stop=0;
    char q2[100];
    int l,ri,f=1,flag = 0,num=0,p=0;//num is for number of inputs
     while(input(&l,&ri,&num)){ //condition for maze to be solved

        stop++;
        if(stop>=10){
            break;
        }
       // printf("%d%d%d",l,ri,flag);
        //if not found anypath rotate
        if(l == 0 && ri == 0){
                //rotate 360
                printf("Rotate");
                flag = 1;
        }
        //check for intersection
        if(l == 1 && ri==1){
            q1[i] = 1;
            q2[j] = 'O';
            j++;
            q2[j] = 'R';
            printf("%c",q2[j]);
            j++;
            i++;
            p = 1;
        }if(l!=1||ri!=1){
            if((l==1)&&(ri==0)){
                //Go Left
                printf("L");
                if(p==1){
                    q2[j] = 'L';
                    j++;
                }
            }else if(ri==1&&l==0){
                //Go Right
                printf("R");
                if(p==1){
                    q2[j] = 'R';
                    j++;
                }
            }
        }

            //returning path
            if(flag==1){
                if(j>1){
                    while(j>=1){
                        j--;
                        if(q2[j-1]=='O'){
                            flag = 0;
                            printf("Go anywhere except %c's opposite",q2[j]);
                            continue;
                        }
                        if(q2[j] == 'L'){
                            //Go Right if last curve we took was left
                            printf("R");
                        }else if(q2[j] == 'R'){
                            //Go Left if last curve we took was right
                            printf("L");
                        }
                    }
                }
            }


        if(flag!=1){
            num++; //can remove cause no need to check for one

        }
     }
    }


int main(){
    Direction();
    return 1;
}
