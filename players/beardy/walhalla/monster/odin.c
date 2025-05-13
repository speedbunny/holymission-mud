inherit "obj/npc";
#include "../walhalla.h"

reset(arg) 
{ ::reset(arg);
  if(!arg) 
  { set_name("odin");
    set_alt_name("god");
    set_race("god");

    set_short("Odin");
    set_long("This is Odin. He is the ruler of the nordic gods. His power\n" +
             "is even greater than Thors. I hope you dont think of attacking\n" +
             "him. He might not pleased with you if you do so.\n");
    set_gender(1);

    set_level(70);
    set_hp(24000);
    set_attacks_change(100);
    set_attacks(9);    

    set_al(1000);
    set_dead_ob(this_object());
    set_aggressive(0);
    add_money(1000+random(3000));

    set_spell_mess2("BBBBBAAAAANNNNNGGGG \n"+
                    "Odin hit you with his migty head...");
    set_chance(60);
    set_spell_dam(100);

/*
    CO("heal_potion");
    CO("str_potion");
    CO("int_potion");
    CO("wis_potion");
    CO("gray_potion");
*/
    CO("osword");
    CO("oarmour");
    CO("oshield");
    init_command("wield sword");
    init_command("wear shield");
    init_command("wear armour");
  }
}

int monster_died(object mob)
{
   object ob;

  ob=find_object("/players/beardy/walhalla/monster/odin");
  if(!this_player()->query_immortal())
   {
   shout(this_player()->query_name()+
         " killed the famous Odin, leader of the Nordic gods !\n");
   }

   if (ob)
       destruct(ob);
  return 0;
}
