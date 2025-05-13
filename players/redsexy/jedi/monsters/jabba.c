#include "/players/redsexy/defs.h"
inherit "/obj/monster";
 
reset(arg) {
   ::reset(arg);
   if (!arg) {
   set_name("Jabba the Hutt");
   set_living_name("jabba");
   set_alt_name("hutt");
   set_alias("jabba");
   set_level(100);
   set_hp(30000);
   set_wc(110);
   set_ac(91);
   set_race("hutt");
   set_size(10);
   set_gender(1);
   load_chat(9,
      ({ 
      "Jabba says: What do you want???\n",
      "Jabba says: Go away, mortal.\n",
      "Jabba laughs at you.\n",
        }));
   load_a_chat(9,
      ({
      "Jabba says: You will never kill me, mortal!\n",
      "Jabba says: Heh, you are lame. \n",
      "Jabba says: Bite me!\n",
      "Jabba says: Screw you, puny mortal.\n",
      }));
   set_long("Jabba The Hutt\n"+
        "This is the almighty Jabba the Hutt, ruler of Mos Eisley and numerous\n"+      
        "other realms and cities.  He sits on his throne, eating slugs and snails\n"+
        "and laughing at those who enter his chambers.  He smells awful, like a \n"+
        "river full of putrid slime, and you do not think you should hang around here\n"+
        "too long.  A creature far more powerful than yourself, you don't fancy your\n"+
        "chances in a fight!\n");
  
   set_chance(20);
   set_spell_mess1("Jabba's breath makes you feel ill.\n");
   set_spell_mess2("Jabba growls as he knocks you to the floor!\n");
   set_spell_dam(150);
   set_no_steal();
   set_number_of_arms(2);
   add_money(1000+random(1000));
   move_object(clone_object("players/redsexy/jedi/objects/sceptre"), this_object());
   command("powerup");

   }
}


int query_str() {
    return 130;
}


hold() {
   write("\n\nYou cannot hold something this large\n\n");
  return 1;
}

int add_poison(int x) {
   return (x/30);
}


