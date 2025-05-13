inherit "obj/monster";
#include "../walhalla.h"

reset(arg) 

{  ::reset(arg);
 if(!arg)
  { set_name("housemaid");
    set_alt_name("maid");
    set_race("semi-god");
    set_short("housemaid");
    set_long("This is a semi-god housemaid. She looks\n" +
             "pretty nice to you, but she is already\n" +
             "married to the great Ottocar. As ever\n" +
             "god she has got lots of HP.\n");

    set_gender(2);

    set_level(15);
    set_hp(2000);

    set_al(0);
    set_aggressive(0);
    add_money(40);
    set_spell_mess1("");
    set_spell_mess2("SCHWUP ! Her dirty broomstick hits you very hard...\n");
    set_chance(15);
    set_spell_dam(50);

    set_dead_ob(this_object());
    move_object(clone_object("/players/beardy/walhalla/obj/broom"),this_object());
    init_command("wield broom");
  }
}

monster_died(ob)
{ 
  object otto;
  
 tell_room(environment(this_object()),
      "Suddenly the very angry Ottocar appears\n"+
      " and his only wish is to KILL YOU !\n");
  otto=clone_object("/players/beardy/walhalla/monster/ottocar");
  move_object(otto,environment(this_object()));
  otto->attack_object(this_object()->query_attack());
  destruct(TO);
  return 1;
}
