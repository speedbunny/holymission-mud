#include "/players/redsexy/defs.h"
inherit "/obj/monster";
 
reset(arg) {
   ::reset(arg);
   if (!arg) {
   set_name("The Sarlacc");
   set_living_name("sarlacc");
   set_alt_name("creature");
   set_alias("sarlacc");
   set_level(100);
   set_hp(30000);
   set_race("demon");
   set_size(10);
   set_gender(1);
   load_chat(9,
      ({ 
      "The Sarlacc moves and his feet just miss your head\n",
      "The Sarlacc breathes and you nearly lose your balance\n",
      "The Sarlacc's tail swishes past your ears\n",
        }));
   load_a_chat(9,
      ({
      "The Sarlacc grunts loudly as if he is laughing at you.\n",
      "The Sarlacc stamps on your head. \n",
      "The Sarlacc's tail belts you around the ears.\n",
      "The Sarlacc breathes right in your face.\n",
      }));
   set_long("The Sarlacc\n"+
        "This is the Sarlacc you have heard so many tales about.  You stand\n"+      
        "just short of the height of his foot, and it is a wonder he did not\n"+
        "eat you upon entry to the pit.  Perhaps he has not noticed you?  His\n"+
        "neck is many giants tall, and his eyes are twice your height.  His\n"+
        "teeth are surprisingly blunt, but as he swallows his prey whole, he has\n"+
        "no need for sharp incisors.  It is rumoured it can take upto a thousand\n"+
        "years to digest in the stomach of the Sarlacc. Beware.\n");

   set_chance(80);
   set_spell_dam(150);
   set_no_steal();
   set_n_ac(30);
   set_number_of_arms(0);
   add_money(100000+random(1000));


   }
}

  heart_beat(){
    ::heart_beat();
    attack();
    attack();
    attack();
    attack();

}

int query_str() {
    return 130;
}


/*int monster_died(object mob) {
   object ob;
   if (!TP->query_immortal()) {
      shout(this_player()->query_name()+" has defeated the Sarlacc.\n");    }

   if (ob)
      destruct(ob);
   return 0;
} */



hold() {
   write("\n\nYou cannot hold something this large\n\n");
  return 1;
}

int add_poison(int x) {
   return (x/30);
}


