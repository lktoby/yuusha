﻿#include <stdio.h>
#include <time.h>
#include <stdlib.h>

//hpを表示する関数
void printhp(int hp) {
    for (int i = 0; i < 10; i++) {
        if (i < hp) {
            printf("■");
        }
        else if (i >= hp) {
            printf("□");
        }
    }
    printf("\n\n");
}

int main(void)
{
    //ゆうしゃの名前を入力
    char yuusha[10] = "";
    printf("ゆうしゃのなまえ:");
    fgets(yuusha, sizeof(yuusha), stdin);
    printf("ゆうしゃ%sのすらいむをたおすものがたりがはじまりました！\n\n", yuusha);

    //hpなどの数字の初期化
    int yuusha_hp = 10;
    int slime_hp = 10;
    int yuusha_damage;
    srand(time(NULL));

    //hpを表示
    printf("ゆうしゃ%sのhp:%d\n", yuusha, yuusha_hp);
    printhp(yuusha_hp);
    printf("すらいむのhp:%d\n", slime_hp);
    printhp(slime_hp);

    //勇者のhpが0じゃないとゲームが続く
    while (yuusha_hp > 0) {
        printf("ゆうしゃ%sのターン\n", yuusha);
        printf("ダメージを入力してください:");
        scanf_s("%d", &yuusha_damage);
        //入力したダメージを10より小さくする
        while (yuusha_damage > 10) {
            printf("10よりちいさいダメージを入力してください。\n");
            printf("ダメージを入力してください:");
            scanf_s("%d", &yuusha_damage);
            if (yuusha_damage <= 10) {
                break;
            }
        }
        slime_hp -= yuusha_damage;
        printf("すらいむが%dダメージをうけました！\n\n", yuusha_damage);
        //すらいむのhpが1になる場合
        if (slime_hp == 1) {
            slime_hp += 3;
            printf("すらいむがみずをすって3 hpをかいふくしました！\n\n");
        }
        //すらいむを倒した場合
        if (slime_hp <= 0) {
            slime_hp = 0;
            printf("ゆうしゃ%sのhp:%d\n", yuusha, yuusha_hp);
            printhp(yuusha_hp);
            printf("すらいむのhp:%d\n", slime_hp);
            printhp(slime_hp);
            printf("すらいむをたおしました！\n");
            break;
        }
        printf("すらいむのターン\n");
        int slime_damage = rand() % 5 + 1; //すらいむが1~5からランダムのダメージをゆうしゃに与える
        yuusha_hp -= slime_damage;
        printf("ゆうしゃ%sが%dダメージをうけました！\n\n", yuusha, slime_damage);
        //ゆうしゃのhpが1になる場合
        if (yuusha_hp == 1) {
            yuusha_hp += 5;
            printf("ゆうしゃ%sがパワーをもらって5 hpをかいふくしました！\n\n", yuusha);
        }
        //ゆうしゃが倒れた場合
        if (yuusha_hp <= 0) {
            yuusha_hp = 0;
            printf("ゆうしゃ%sのhp:%d\n", yuusha, yuusha_hp);
            printhp(yuusha_hp);
            printf("すらいむのhp:%d\n", slime_hp);
            printhp(slime_hp);
            printf("ゆうしゃ%sがたおれました！\n", yuusha);
            break;
        }
        //ターンが終わったのhpを表示
        printf("ゆうしゃ%sのhp:%d\n", yuusha, yuusha_hp);
        printhp(yuusha_hp);
        printf("すらいむのhp:%d\n", slime_hp);
        printhp(slime_hp);
    }

    return 0;
}