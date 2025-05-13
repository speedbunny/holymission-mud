#include "/players/tamina/defs.h"

inherit "obj/monster";
  int count;

reset(arg) {
  ::reset(arg);
  if(arg) return;

     set_name("hound");
     set_short("A Hound");
     set_long("A large supernatural hound, with eyes of fire.\n");
     set_level(23);
     set_gender(1);
     set_al(-90);
     set_aggressive(1);
     set_hp(800);
     set_wc(28);
     set_ac(11);
     set_spell_mess2("The Hound's eyes sear you with a burning flash!\n");
     set_spell_mess1("Flames streak from the Hound's eyes to its victim!\n");
     set_spell_dam(39+random(39));
     set_chance(9);
     add_money(150);
     load_a_chat(30,
       ({"The Hound sends shivers up your spine as it howls!\n",
         "The Hound's eyes blaze with a fire!\n"}) );
     random_move(1);

}

heart_beat()
{
  if (++count > 4)
  {
    random_move(); 
    count = 0;
  }
  ::heart_beat();
}

