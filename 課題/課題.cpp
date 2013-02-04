#include<stdio.h>

#define SEL_NUM 3 // 縦横のマスの数

char g_Sel[SEL_NUM][SEL_NUM]; // マスの配列
char g_Player; // 0:○の番 / 1:×の番

void Reset(); // リセット
void Post(); // コマの配置
char WinJudge(); // 勝利判定(縦・横・斜め揃ってるかの判定)
void Draw(); // ボードの表示


void main(){

int a, Judge;

while(1){

do{
printf("\n1.スタート\n0.終了\n->"); scanf("%d", &a);
if(a==0){ return; }
}
while(a<0 || a>1);

Reset(); // リセット
Judge = (-1);

while(Judge==(-1)){
g_Player = !g_Player; // ○×の交替(g_Playerの値が０なら１、１なら０が入る)
Draw(); // ボード表示
Post(); // コマの配置
Judge = WinJudge(); // 勝利判定
}

Draw(); // ボード表示

switch(Judge){
case 0: printf("○の勝ち\n"); break;
case 1: printf("×の勝ち\n"); break;
case 2: printf("引き分け\n"); break;
}
}
}


void Reset(){

int i,j;

g_Player = 1;

for(i=0; i<SEL_NUM; i++){
for(j=0; j<SEL_NUM; j++){
g_Sel[i][j] = (-1);
}
}
}


void Post(){

int x, y;

while(1){
while(1){
switch(g_Player){
case 0: printf("○の番…\n"); break;
case 1: printf("×の番…\n"); break;
}
printf("配置：横の番号を入力->"); scanf("%d", &x);
printf("配置：縦の番号を入力->"); scanf("%d", &y);

if(x>=0 && x<SEL_NUM && y>=0 && y<SEL_NUM){
break;
}else{
printf("入力に誤りがあります！\n\n");
}
}

if(g_Sel[y][x] == (-1)){
g_Sel[y][x] = g_Player;
return;
}else{
printf("その位置には置けません！\n\n");
}
}
}


char WinJudge(){

// 【内容】
// 勝利判定(縦・横・斜め揃ってるかの判定)
// g_Playerの値が０なら○の勝利判定をする
// g_Playerの値が１なら×の勝利判定をする

// 【戻り値】
// (-1):揃ってない / 0:○の勝ち / 1:×の勝ち
// 2:引き分け(全部埋まった状態)

int i, j, Cnt;

// 横の判定
for(i=0; i<SEL_NUM; i++){
for(j=0, Cnt=0; j<SEL_NUM; j++){
if(g_Sel[i][j] == g_Player){ Cnt++; }else{ break; }
}
if(Cnt == SEL_NUM){ return g_Player; }
}

// 縦の判定
for(i=0; i<SEL_NUM; i++){
for(j=0, Cnt=0; j<SEL_NUM; j++){
if(g_Sel[j][i] == g_Player){ Cnt++; }else{ break; }
}
if(Cnt == SEL_NUM){ return g_Player; }
}

// 斜め(左上から右下)の判定
for(i=0, Cnt=0; i<SEL_NUM; i++){
if(g_Sel[i][i] == g_Player){ Cnt++; }else{ break; }
}
if(Cnt == SEL_NUM){ return g_Player; }

// 斜め(右上から左下)の判定
for(i=0, j=SEL_NUM-1, Cnt=0; i<SEL_NUM; i++, j--){
if(g_Sel[i][j] == g_Player){ Cnt++; }else{ break; }
}
if(Cnt == SEL_NUM){ return g_Player; }

// 空きがあるかどうかの判定
for(i=0; i<SEL_NUM; i++){
for(j=0; j<SEL_NUM; j++){
if(g_Sel[i][j] == (-1)){ return (-1); }
}
}
return 2;
}


void Draw(){

int i,j;

printf("\n・|");

for(i=0; i<SEL_NUM; i++){
printf("%2d", i);
}
printf("\n");

for(i=0; i<SEL_NUM; i++){

printf("%2d|",i);

for(j=0; j<SEL_NUM; j++){
switch(g_Sel[i][j]){
case ( 0): printf("○"); break;
case ( 1): printf("×"); break;
case (-1): printf("■"); break;
}
}
printf("\n");
}
printf("\n");
}