#include <stdio.h>
#include<math.h>

class dipole_state
{
public:
  double arg = 0.0;
  double length = 1.0;
  double potential = 1.0;
  int enable =0;
};
void display_cell(dipole_state[][6]);


main()
{
  int i, j;
  dipole_state magnetic[6][6];
  dipole_state rand_magnetic;
  //角度の初期化
  for (i = 1; i <= 5; i++)
  {
    for (j = 1; j <= 5;j++)
    {
      magnetic[i][j].arg =rand()%360;
    }
  }
  //ポテンシャルの初期化
  for (i = 1; i <= 5; i++)
  {
    for (j = 1; j <= 5; j++)
    {
      magnetic[i][j].potential =
          cos(magnetic[i + 1][j].arg - rand_magnetic.arg) 
          + cos(magnetic[i - 1][j].arg - rand_magnetic.arg)
          + cos(magnetic[i][j + 1].arg - rand_magnetic.arg) 
          + cos(magnetic[i][j - 1].arg - rand_magnetic.arg);
    }
  }

  display_cell(magnetic);
 
  // for (i = 1; i <= 5; i++)
  // {
  //   for (j = 1; j <= 5; j < 5; j++)
  //   {
  //     rand_magnetic.arg = rand() % 360;
  //     rand_magnetic.potential =
  //         cos(magnetic[i + 1][j].arg - rand_magnetic.arg) 
  //         + cos(magnetic[i - 1][j].arg - rand_magnetic.arg)
  //         + cos(magnetic[i][j + 1].arg - rand_magnetic.arg) 
  //         + cos(magnetic[i][j - 1].arg - rand_magnetic.arg);

  //     if (rand_magnetic.potential < magnetic[i][j])
  //     {
  //       magnetic[i][j].arg = rand_magnetic.arg;
  //       magnetic[i][j].arg = rand_magnetic.arg;
  //     }
  //   }
  // }
}

void display_cell(dipole_state magnetic[][6])
{
  int i,j;
   //表示
  for (i = 1; i <= 5; i++)
  {
    for (j = 1; j <= 5; j++)
    {
      // printf("|U:%3.2f\t,arg:%3.2f\t|",magnetic[i][j].potential,magnetic[i][j].arg);
      printf("|arg:%3.2f\t|",magnetic[i][j].potential,magnetic[i][j].arg);

    }
    printf("\n");
  } 
  
}
