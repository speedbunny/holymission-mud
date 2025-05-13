inherit "obj/npc";
#include "../walhalla.h"
#include "../walhalla.h"

reset(arg) 
{ ::reset(arg);
  if(!arg) 
  { set_name("thor");
    set_alt_name("god");
    set_race("god");

    set_short("thor");
    set_long("This is Thor. The fignter of the nordic gods. He is very\n" +
             "this moment and wants to kill something. Perhaps he is\n" +
             "going to kill you....\n");
    set_gender(1);
    set_dead_ob(this_object());

    set_level(50);
    set_hp(18000);
    set_attacks_change(100);
    set_attacks(7);    
    set_dodge(35);

    set_al(1000);
    set_aggressive(0);
    add_money(7000+random(6000));

    set_spell_mess2("TRUMP - TRUMP - TRUMP - TRUMP\n"+
                    "What a hard attack... \n");
    set_chance(10);
    set_spell_dam(100);
    CO("thammer");
    init_command("powerup");

  }
}

int monster_died(object mob)
{
   object ob;

   ob=find_object("/players/beardy/walhalla/monster/thor");
 if (!this_player()->query_immortal())
   {
   shout(this_player()->query_name()+
   " gets the famous war hammer from god Thor.\n");
   }

   if (ob)
       destruct(ob);
  return 0;
}
