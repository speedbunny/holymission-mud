/* Test OutGrounds */

#include "room.h"

#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

int i;
object halfw;

extra_reset()
{
  i = 0;
  if (!present("halfw"))
  {
   while (i < 5)
   {
     i+=1;
    halfw = clone_object("obj/monster");
    halfw->set_name("halfwit");
    halfw->set_alias("halfwit");
    halfw->set_race("human");
    halfw->set_level(18);
    halfw->set_hp(280);
    halfw->set_ep(3000);
    halfw->set_al(-200);
    halfw->set_short("A halfwit");
    halfw->set_wc(13);
    halfw->set_ac(5);
    halfw->set_aggressive(0);
    halfw->set_sp(200);
    halfw->set_str(15);
    halfw->set_dex(15);
    halfw->set_con(15);
    halfw->set_wis(15);
    halfw->set_chr(15);
    halfw->set_int(15);
    transfer(halfw,this_object());
   }
  }
}

ONE_EXIT("players/kbl/kblroom","north",
         "The HalfWit House\n",
         "The HalfWit House\n"+
         "You are standing just outside of a Large castle set into a mountain\n"        +"top.  The view here is outstanding, for you can look below and see\n"
       +"the tops of the clouds passing by. The wind feels cool on your\n"
        +"face as you look around.\n", 1)
