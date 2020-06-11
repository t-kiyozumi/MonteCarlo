#include <stdio.h>
#include <math.h>
#include <time.h>

class dipole_state
{
public:
  double arg = 0.0;
  double length = 1.0;
  double potential = 1.0;
  int enable = 1;
};
void display_cell(dipole_state[][6]);

main()
{
  long cpu_time;
  double sec;

  int i, j;
  double k;
  double torialNo = 10000000;
  dipole_state magnetic[6][6];
  dipole_state rand_magnetic;

  //無効セルの設定
  //0行,0列,6行,6列を全て無効化
  for (i = 0; i < 6; i++)
  {
    magnetic[i][0].enable = 0;
  }
  for (i = 0; i < 6; i++)
  {
    magnetic[i][6].enable = 0;
  }
  for (j = 0; j < 6; j++)
  {
    magnetic[1][j].enable = 0;
  }
  for (j = 0; j < 6; j++)
  {
    magnetic[6][j].enable = 0;
  }

  //角度の初期化
  for (i = 1; i <= 5; i++)
  {
    for (j = 1; j <= 5; j++)
    {
      magnetic[i][j].arg = rand() % 360;                            //乱数で初期化，単位は[deg]
      magnetic[i][j].arg = ((2 * M_PI) / 360) * magnetic[i][j].arg; //[rad]に変換
    }
  }
  //ポテンシャルの初期化
  for (i = 1; i <= 5; i++)
  {
    for (j = 1; j <= 5; j++)
    {
      magnetic[i][j].potential =
          -1.0 * (cos(magnetic[i + 1][j].arg - magnetic[i][j].arg) * magnetic[i + 1][j].enable + cos(magnetic[i - 1][j].arg - magnetic[i][j].arg) * magnetic[i - 1][j].enable + cos(magnetic[i][j + 1].arg - magnetic[i][j].arg) * magnetic[i][j + 1].enable + cos(magnetic[i][j - 1].arg - magnetic[i][j].arg) * magnetic[i][j - 1].enable);
    }
  }

  display_cell(magnetic);

  for (k = 0; k < torialNo; k++)
  {
    printf("processing:%f %\n", (k / torialNo) * 100.0);
    for (i = 1; i <= 5; i++)
    {
      for (j = 1; j <= 5; j++)
      {

          rand_magnetic.arg = rand() % 360;
          rand_magnetic.arg = ((2 * M_PI) / 360) * rand_magnetic.arg; //[rad]に変換
          rand_magnetic.potential =
              -1.0 * (cos(magnetic[i + 1][j].arg - rand_magnetic.arg) * magnetic[i + 1][j].enable 
                + cos(magnetic[i - 1][j].arg - rand_magnetic.arg) * magnetic[i - 1][j].enable
                + cos(magnetic[i][j + 1].arg - rand_magnetic.arg) * magnetic[i][j + 1].enable 
                + cos(magnetic[i][j - 1].arg - rand_magnetic.arg) * magnetic[i][j - 1].enable);
          if (rand_magnetic.potential < magnetic[i][j].potential)
          {
            magnetic[i][j].arg = rand_magnetic.arg;
            magnetic[i][j].potential = rand_magnetic.potential;
          }
      }
    }
  }
  display_cell(magnetic);
  sec = (double)cpu_time / CLOCKS_PER_SEC;
  printf("%fsec\n", sec);
  return 0;
}

void display_cell(dipole_state magnetic[][6])
{
  printf("-----------------------------------------------------------------------------------------------------------------------------------------\n");
  int i, j;
  //表示
  for (i = 1; i <= 5; i++)
  {
    for (j = 1; j <= 5; j++)
    {
      printf("|U=%3.2f:arg=%3.2f[deg]|", magnetic[i][j].potential, magnetic[i][j].arg*(360.0/(2*M_PI)));
      //printf("|arg:%3.2f\t|", magnetic[i][j].potential, magnetic[i][j].arg);
    }
    printf("\n");
  }
}
