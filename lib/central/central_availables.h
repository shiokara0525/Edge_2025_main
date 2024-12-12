#pragma once

#include<Sup.h>

#define KICK_ON 1
#define KICK_OFF 0

#define MOTOR_STOP 0
#define MOTOR_ON 1
#define MOTOR_AC_ONLY 2
#define MOTOR_TEST_0 3
#define MOTOR_TEST_1 4
#define MOTOR_TEST_2 5
#define MOTOR_TEST_3 6


#define AC_ALL 0
#define AC_BACK_ONLY 1



class central_aveilables{
public:
  State main_mode;  //モードの状態変数（予定）
  int Mode;         //モードの状態変数
  int Mode_old;
  int test_mode = 0;//テストのモード変数

  int color;        //ゴールの色
  int ac_tirget;    //角度の目標値



  int Values[6];    //ESPから送られてくる変数

  timer Main_timer; //１周期の秒数のタイマー
  timer Mode_timer; //モードに居続けた変数

  timer Ball_period;//ボールの更新を管理するタイマー
  timer Line_period;//ラインの更新を管理するタイマー

  timer ball_Get;   //ボールの情報が送られてくる周期を測るタイマー
  timer line_Get;   //ラインの情報が送られてくる周期を測るタイマー

  void set_states(Vector2D go_vec,int motor_value,int motor_on,int AC_value,int AC_flag,int Kick_on);  //状態設定するやつ
  int return_AC_value();
  int return_AC_flag();
  int return_Motor_on();
  int return_Motor_value();
  int return_Kick_on();
  Vector2D return_go_vector();
private:

  Vector2D go_vector;

  float AC_value;
  float Kick_on;
  int AC_flag;
  int Motor_on;     //0　モーターなし 1 普通に動かす 2 姿勢制御だけ
  int val_max = 200;//モーターの出力
};

extern central_aveilables central;