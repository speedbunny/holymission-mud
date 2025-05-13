inherit "obj/npc";
#include "../harbour.h"

reset(int arg) 
{ ::reset(arg);
  if(!arg) 
  { set_name("sailor");
    set_alt_name("sailor");
    set_race("");

    set_short("sailor");
    set_long("It's a strong trained sailor\n");
    set_gender(1);

    set_level(15);
    set_attacks_change(100);
    set_attacks(4);    

    set_al(100);
    set_aggressive(0);
    add_money(30);

    set_spell_mess1("The sailor throws his fist against a face");
    set_spell_mess2("The sailor throws his fist against a face.\n"+
		    "Sorry - it was yours");
    set_chance(40);
    set_spell_dam(60);

   move_object(clone_object("/obj/rope"),TO);
   CO("sail");

  }
}
