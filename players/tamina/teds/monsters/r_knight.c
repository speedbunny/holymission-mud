#include "/players/tamina/defs.h"

inherit "obj/monster";
object knife;

reset(arg) 
{
  ::reset(arg);
  if(arg) return;

    set_name("Red Knight");
    set_alt_name("red knight");
    set_alias("knight");
    set_short("Red Knight");
    set_long(
 "This Knight is clad in blood red armor and carrys a Blood red shield.\n"+
 "He looks very dangerous, and menacing in his eerie armour...\n");
    set_gender(1);
    set_race("human");
    set_level(16);
    set_hp(900);
    set_al(-250);
    set_ac(9);
    set_wc(25);
    set_aggressive(1);
    add_money(50 + random(250));
    load_a_chat(33,
   ({"The Red Knight draws a puddle of blood from you!\n",
     "The Red Knight says: Why do you bother, weakling?\n",
     "The Red Knight says: Beware, foolish follower of the idiot, Arthur!\n",
     "The Red Knight says: Beware the castle known as Camelot!  You will not survive there!!\n"
      }) );

  MO(CLO(COBJ + "sac_knife2"), TO);
  command("powerup");

  
}


