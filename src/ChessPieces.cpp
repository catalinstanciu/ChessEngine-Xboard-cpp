#include "ChessPieces.h"

ChessPieces::ChessPieces()
{
    //ctor
}

ChessPieces::~ChessPieces()
{
    //dtor
}

Moves ChessPieces::pawn_moves(int poz,Elemente b[])
{
    Moves x;
    x.size = 0;
    if (poz/10 == 8 && b[poz-10].type == '0'  && b[poz-20].type=='0'){
         x.m[x.size] = poz-20;
        x.size++;
    }
    if (b[poz-10].type=='0'){
            x.m[x.size] = poz-10;
            x.size++;
        }
    if (b[poz-11].color==2 &&b[poz-11].type !='0'){
                    x.m[x.size] = poz-11;
                    x.size++;
    }
    if (b[poz-9].color==2 &&b[poz-9].type !='0'){
            x.m[x.size] = poz-9;
            x.size++;
        }
    return x;
}
Moves ChessPieces::nite_moves(int poz,Elemente b[]){
    Moves x;
    x.size = 0;
    if (b[poz+21].type=='0' || b[poz+21].color==2){
        x.m[x.size]=poz+21;
        x.size++;
    }
    if (b[poz+19].type=='0' || b[poz+19].color==2){
        x.m[x.size]=poz+19;
        x.size++;
    }
    if (b[poz-19].type=='0' || b[poz-19].color==2){
        x.m[x.size]=poz-19;
        x.size++;
    }
    if (b[poz-21].type=='0' || b[poz-21].color==2){
        x.m[x.size]=poz-21;
        x.size++;
    }
    if (b[poz-12].type=='0' || b[poz-12].color==2){
        x.m[x.size]=poz-12;
        x.size++;
    }
    if (b[poz+8].type=='0' || b[poz+8].color==2){
        x.m[x.size]=poz+8;
        x.size++;
    }
    if (b[poz-8].type=='0' || b[poz-8].color==2){
        x.m[x.size]=poz-8;
        x.size++;
    }
    if (b[poz+12].type=='0' || b[poz+12].color==2){
        x.m[x.size]=poz+12;
        x.size++;
    }
    return x;
}
Moves ChessPieces:: rock_moves(int poz,Elemente b[]){
    Moves x;
    x.size = 0;
    int i=1;
    while (b[poz+i].type=='0'){
        x.m[x.size]=poz+i;
        x.size++;
        i++;
    }
    if(b[poz+i].color==2){

        x.m[x.size]=poz+i;
        x.size++;

    }
    i=1;
    while (b[poz-i].type=='0'){
        x.m[x.size]=poz-i;
        x.size++;
        i++;
    }
    if(b[poz-i].color==2){
        x.m[x.size]=poz-i;
        x.size++;

    }
    i=10;
    while (b[poz-i].type=='0'){
        x.m[x.size]=poz-i;
        x.size++;
        i=i+10;
    }
    if(b[poz-i].color==2){
        x.m[x.size]=poz-i;
        x.size++;

    }
     i=10;
    while (b[poz+i].type=='0'){
        x.m[x.size]=poz+i;
        x.size++;
        i=i+10;
    }
    if(b[poz+i].color==2){
        x.m[x.size]=poz+i;
        x.size++;

    }
    return x;
}
Moves ChessPieces:: bishop_moves(int poz ,Elemente b[]){
    Moves x;
    x.size = 0;
    int i=9;
    while (b[poz+i].type=='0'){
        x.m[x.size]=poz+i;
        x.size++;
        i+=9;
    }
    if(b[poz+i].color==2){
        x.m[x.size]=poz+i;
        x.size++;

    }
    i=9;
    while (b[poz-i].type=='0'){
        x.m[x.size]=poz-i;
        x.size++;
        i+=9;
    }
    if(b[poz-i].color==2){
        x.m[x.size]=poz-i;
        x.size++;

    }
    i=11;
    while (b[poz-i].type=='0'){
        x.m[x.size]=poz-i;
        x.size++;
        i=i+11;
    }
    if(b[poz-i].color==2){
        x.m[x.size]=poz-i;
        x.size++;

    }
     i=11;
    while (b[poz+i].type=='0'){
        x.m[x.size]=poz+i;
        x.size++;
        i=i+11;
    }
    if(b[poz+i].color==2){
        x.m[x.size]=poz+i;
        x.size++;
    }
    return x;
}
Moves ChessPieces:: king_moves(int poz,Elemente b[]){
    Moves x;
    x.size = 0;
    if (b[poz+1].type=='0' || b[poz+1].color==2){
        x.m[x.size]=poz+1;
        x.size++;
    }
    if (b[poz-1].type=='0' || b[poz-1].color==2){
        x.m[x.size]=poz-1;
        x.size++;
    }
    if (b[poz+9].type=='0' || b[poz+9].color==2){
        x.m[x.size]=poz+9;
        x.size++;
    }
    if (b[poz-9].type=='0' || b[poz-9].color==2){
        x.m[x.size]=poz-9;
        x.size++;
    }
    if (b[poz+11].type=='0' || b[poz+11].color==2){
        x.m[x.size]=poz+11;
        x.size++;
    }
    if (b[poz+10].type=='0' || b[poz+10].color==2){
        x.m[x.size]=poz+10;
        x.size++;
    }
    if (b[poz-10].type=='0' || b[poz-10].color==2){
        x.m[x.size]=poz-10;
        x.size++;
    }
    if (b[poz-11].type=='0' || b[poz-11].color==2){
        x.m[x.size]=poz-11;
        x.size++;
    }

    return x;
}
Moves ChessPieces:: queen_moves(int poz,Elemente b[]){
    Moves x, y;
    x =  bishop_moves(poz , b);
    y = rock_moves(poz , b);
    int n = x.size+y.size;
    for (int i = x.size;i<n;i++){
        x.m[i] = y.m[i-x.size];
    }
    x.size = n;
    return x;
}
Moves ChessPieces:: random_move_gen(Elemente b[]){
    Moves x;
    srand(time(0));
  //  ofstream g("aaa.txt");
    while(1){

        int r = rand();
        r = r % 78 + 21;

       // Moves x;
       x.size=0;
       // std::cout<<"ajun"<<r<<"sss"<<b[r].color<<endl;
        if (b[r].color == 1 ){
        //std::cout<<"ajunge2"<<endl;
            switch (b[r].type) {
            case 'p':{x = pawn_moves(r , b);x.poz = r;}break;
            case 'r':{x = rock_moves(r , b);x.poz = r;}break;
            case 'b':{x = bishop_moves(r , b);x.poz = r;}break;
            case 'k':{x = king_moves(r , b);x.poz = r;}break;
            case 'q':{x = queen_moves(r , b);x.poz = r;}break;
            case 'n':{x = nite_moves(r , b);x.poz = r;}break;
            }
            if (x.size != 0){
                    //g<<"ajunge"<<x.size<<endl;
                return x;
            }
        }
    }
    return x;
}
Moves ChessPieces:: isChess(int poz,Elemente b[]){
    Moves x;

    x.size = 0;
    int i=9;
    while (b[poz+i].type=='0'){
        i+=9;
    }
    if(b[poz+i].color==2&&(b[poz+i].type=='q'||b[poz+i].type == 'b')){
        x.m[x.size]=poz+i;
        x.size++;
    }
    i =11;
      while (b[poz+i].type=='0'){
        i+=11;
    }
    if(b[poz+i].color==2&&(b[poz+i].type=='q'||b[poz+i].type == 'b')){
        x.m[x.size]=poz+i;
        x.size++;
    }
    i=9;
    while (b[poz-i].type=='0'){
        i+=9;
    }
    if(b[poz-i].color==2&&(b[poz-i].type=='q'||b[poz-i].type == 'b')){
        x.m[x.size]=poz-i;
        x.size++;    }
    i =11;
      while (b[poz-i].type=='0'){
        i+=11;
    }
    if(b[poz-i].color==2&&(b[poz-i].type=='q'||b[poz-i].type == 'b')){
        x.m[x.size]=poz-i;
        x.size++;
    }
    i=1;
    while (b[poz+i].type=='0'){
        i+=1;
    }
    if(b[poz+i].color==2&&(b[poz+i].type=='q'||b[poz+i].type == 'r')){
        x.m[x.size]=poz+i;
        x.size++;
    }
        i=1;
    while (b[poz-i].type=='0'){
        i+=1;
    }
    if(b[poz-i].color==2&&(b[poz-i].type=='q'||b[poz-i].type == 'r')){
        x.m[x.size]=poz-i;
        x.size++;
    }
    i=10;
    while (b[poz+i].type=='0'){
        i+=10;
    }
    if(b[poz+i].color==2&&(b[poz+i].type=='q'||b[poz+i].type =='r')){
        x.m[x.size]=poz+i;
        x.size++;
    }
        i=10;
    while (b[poz-i].type=='0'){
        i+=10;
    }
    if(b[poz-i].color==2&&(b[poz-i].type=='q'||b[poz-i].type == 'r')){
        x.m[x.size]=poz-i;
        x.size++;
    }

    if (b[poz+21].type=='n' && b[poz+21].color==2){
        x.m[x.size]=poz+21;
        x.size++;
    }
    if (b[poz+19].type=='n' && b[poz+19].color==2){
        x.m[x.size]=poz+19;
        x.size++;
    }
    if (b[poz-19].type=='n' && b[poz-19].color==2){
        x.m[x.size]=poz-19;
        x.size++;
    }
    if (b[poz-21].type=='n' && b[poz-21].color==2){
        x.m[x.size]=poz-21;
        x.size++;
    }
    if (b[poz-12].type=='n' && b[poz-12].color==2){
        x.m[x.size]=poz-12;
        x.size++;
    }
    if (b[poz+8].type=='n' && b[poz+8].color==2){
        x.m[x.size]=poz+8;
        x.size++;
    }
    if (b[poz-8].type=='n' && b[poz-8].color==2){
        x.m[x.size]=poz-8;
        x.size++;
    }
    if (b[poz+12].type=='n' && b[poz+12].color==2){
        x.m[x.size]=poz+12;
        x.size++;
    }
    if (b[poz-11].color== 2 &&b[poz-11].type =='p'){
                    x.m[x.size] = poz-11;
                    x.size++;
    }
    if (b[poz-9].color== 2 &&b[poz-9].type =='p'){
            x.m[x.size] = poz-9;
            x.size++;
        }
return x;
}
