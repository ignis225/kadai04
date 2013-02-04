#include<stdio.h>

#define SEL_NUM 3 // �c���̃}�X�̐�

char g_Sel[SEL_NUM][SEL_NUM]; // �}�X�̔z��
char g_Player; // 0:���̔� / 1:�~�̔�

void Reset(); // ���Z�b�g
void Post(); // �R�}�̔z�u
char WinJudge(); // ��������(�c�E���E�΂ߑ����Ă邩�̔���)
void Draw(); // �{�[�h�̕\��


void main(){

int a, Judge;

while(1){

do{
printf("\n1.�X�^�[�g\n0.�I��\n->"); scanf("%d", &a);
if(a==0){ return; }
}
while(a<0 || a>1);

Reset(); // ���Z�b�g
Judge = (-1);

while(Judge==(-1)){
g_Player = !g_Player; // ���~�̌��(g_Player�̒l���O�Ȃ�P�A�P�Ȃ�O������)
Draw(); // �{�[�h�\��
Post(); // �R�}�̔z�u
Judge = WinJudge(); // ��������
}

Draw(); // �{�[�h�\��

switch(Judge){
case 0: printf("���̏���\n"); break;
case 1: printf("�~�̏���\n"); break;
case 2: printf("��������\n"); break;
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
case 0: printf("���̔ԁc\n"); break;
case 1: printf("�~�̔ԁc\n"); break;
}
printf("�z�u�F���̔ԍ������->"); scanf("%d", &x);
printf("�z�u�F�c�̔ԍ������->"); scanf("%d", &y);

if(x>=0 && x<SEL_NUM && y>=0 && y<SEL_NUM){
break;
}else{
printf("���͂Ɍ�肪����܂��I\n\n");
}
}

if(g_Sel[y][x] == (-1)){
g_Sel[y][x] = g_Player;
return;
}else{
printf("���̈ʒu�ɂ͒u���܂���I\n\n");
}
}
}


char WinJudge(){

// �y���e�z
// ��������(�c�E���E�΂ߑ����Ă邩�̔���)
// g_Player�̒l���O�Ȃ灛�̏������������
// g_Player�̒l���P�Ȃ�~�̏������������

// �y�߂�l�z
// (-1):�����ĂȂ� / 0:���̏��� / 1:�~�̏���
// 2:��������(�S�����܂������)

int i, j, Cnt;

// ���̔���
for(i=0; i<SEL_NUM; i++){
for(j=0, Cnt=0; j<SEL_NUM; j++){
if(g_Sel[i][j] == g_Player){ Cnt++; }else{ break; }
}
if(Cnt == SEL_NUM){ return g_Player; }
}

// �c�̔���
for(i=0; i<SEL_NUM; i++){
for(j=0, Cnt=0; j<SEL_NUM; j++){
if(g_Sel[j][i] == g_Player){ Cnt++; }else{ break; }
}
if(Cnt == SEL_NUM){ return g_Player; }
}

// �΂�(���ォ��E��)�̔���
for(i=0, Cnt=0; i<SEL_NUM; i++){
if(g_Sel[i][i] == g_Player){ Cnt++; }else{ break; }
}
if(Cnt == SEL_NUM){ return g_Player; }

// �΂�(�E�ォ�獶��)�̔���
for(i=0, j=SEL_NUM-1, Cnt=0; i<SEL_NUM; i++, j--){
if(g_Sel[i][j] == g_Player){ Cnt++; }else{ break; }
}
if(Cnt == SEL_NUM){ return g_Player; }

// �󂫂����邩�ǂ����̔���
for(i=0; i<SEL_NUM; i++){
for(j=0; j<SEL_NUM; j++){
if(g_Sel[i][j] == (-1)){ return (-1); }
}
}
return 2;
}


void Draw(){

int i,j;

printf("\n�E|");

for(i=0; i<SEL_NUM; i++){
printf("%2d", i);
}
printf("\n");

for(i=0; i<SEL_NUM; i++){

printf("%2d|",i);

for(j=0; j<SEL_NUM; j++){
switch(g_Sel[i][j]){
case ( 0): printf("��"); break;
case ( 1): printf("�~"); break;
case (-1): printf("��"); break;
}
}
printf("\n");
}
printf("\n");
}