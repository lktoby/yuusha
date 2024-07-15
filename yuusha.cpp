#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

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
    yuusha[strcspn(yuusha, "\n")] = 0;
    printf("ゆうしゃ%sのすらいむをたおすものがたりがはじまりました！\n\n", yuusha);

    //hpなどの数字の初期化
    int yuusha_hp = 10;
    int slime_hp = 10;
    int slime_heal = 0;
    int yuusha_choice;
    int yuusha_damage;
    int yuusha_shield = 0;
    int flag = 0;
    srand(time(NULL));

    //hpを表示
    printf("ゆうしゃ%sのhp:%d\n", yuusha, yuusha_hp);
    printhp(yuusha_hp);
    printf("すらいむのhp:%d\n", slime_hp);
    printhp(slime_hp);

    //勇者のhpが0じゃないとゲームが続く
    while (yuusha_hp > 0) {
        printf("ゆうしゃ%sのターン\n", yuusha);
        printf("Please choose to attack (0) or defend (1): ");
        scanf("%d", &yuusha_choice);
        while (yuusha_choice != 0 && yuusha_choice != 1){
            printf("Please enter 0 or 1:");
            scanf("%d", &yuusha_choice);
        }
        
        if (yuusha_choice == 0){ //Attack Mode (Forgive my format i'm using online compiler)
        printf("ダメージを入力してください（999を入力してあきらめる）:");
        scanf("%d", &yuusha_damage);
        //入力したダメージを10より小さくする
        while (yuusha_damage > 5) {
            if (yuusha_damage == 999) {
                flag = 1;
                break;
            }
            printf("5よりちいさいダメージを入力してください。\n");
            printf("ダメージを入力してください（999を入力してあきらめる）:");
            scanf("%d", &yuusha_damage);
            if (yuusha_damage <= 5) {
                break;
            }
        }
        //途中で諦める場合
        if (flag == 1) {
            printf("ゆうしゃ%sがにげた！\nすらいむがかった！\n", yuusha);
            break;
        }
        slime_hp -= yuusha_damage;
        printf("すらいむが%dダメージをうけた！\n\n", yuusha_damage);
        //すらいむのhpが1になる場合
        if (slime_hp == 1) {
            slime_heal = rand() % 5 + 1; //スライムのhp回復量を1~5からランダムにする
            slime_hp += slime_heal;
            printf("すらいむがみずをすって%d hpをかいふくした！\n\n", slime_heal);
        }
        //すらいむを倒した場合
        if (slime_hp <= 0) {
            slime_hp = 0;
            printf("ゆうしゃ%sのhp:%d\n", yuusha, yuusha_hp);
            printhp(yuusha_hp);
            printf("すらいむのhp:%d\n", slime_hp);
            printhp(slime_hp);
            printf("すらいむをたおした！\n");
            break;
        }
        }
        //Defense mode
        else if (yuusha_choice == 1){
            yuusha_shield = rand() % 5 + 1;
            printf("Yuusha has initiated shield!\n");
        }
        printf("すらいむのターン\n");
        
        
        int slime_damage = rand() % 5 + 1; //すらいむが1~5からランダムのダメージをゆうしゃに与える
        printf("Slime does %d damage!\n", slime_damage);
        if (slime_damage > yuusha_shield) {
            slime_damage -= yuusha_shield; //Shield reduces slime's damage
        } else {
            slime_damage = 1; //At least does 1 damage
        }
        yuusha_hp -= slime_damage;
        printf("ゆうしゃ%sが%dダメージをうけた！\n\n", yuusha, slime_damage);
        //ゆうしゃのhpが1になる場合
        if (yuusha_hp == 1) {
            yuusha_hp += 5;
            printf("ゆうしゃ%sがパワーをもらって5 hpをかいふくした！\n\n", yuusha);
        }
        //ゆうしゃが倒れた場合
        if (yuusha_hp <= 0) {
            yuusha_hp = 0;
            printf("ゆうしゃ%sのhp:%d\n", yuusha, yuusha_hp);
            printhp(yuusha_hp);
            printf("すらいむのhp:%d\n", slime_hp);
            printhp(slime_hp);
            printf("ゆうしゃ%sがたおれた！\n", yuusha);
            break;
        }
        yuusha_shield = 0; //Reset shield
        //ターンが終わったのhpを表示
        printf("ゆうしゃ%sのhp:%d\n", yuusha, yuusha_hp);
        printhp(yuusha_hp);
        printf("すらいむのhp:%d\n", slime_hp);
        printhp(slime_hp);
    }

    return 0;
}
