#include "/players/gareth/define.h"
#define TPRN capitalize(TPN)
inherit "/obj/monster";

 object bracers,xplate,xblade,sword;

reset(arg) {
   ::reset(arg);
   if (!arg) {
   set_name("Xena the Warrior Wench");
   set_living_name("xena");
   set_alt_name("wench");
   set_alias("xena");
   set_level(75);
   set_hp(8000);
   set_race("human");
   set_size(3);
   set_gender(2);
   load_chat(9,
      ({ 
      "Xena the warrior wench struts her stuff.\n",
      "Xena says: Don't even think about it - PUNK !\n",
      "Xena says: You can have anything but me.\n",
      "Xena worries about Gabby!\n",
      }));
   load_a_chat(10,
      ({
      "Xena growls: Back off You low life scum !!!\n",
      "Xena howls: I'm a woman and I won't be taken for granted !!\n",
      "Xena screams: I'll teach you for calling me a wench !!\n",
      "Xena shouts: Your mother was a bitch!!!\n",
      }));
   set_long(
      "Before you stands Xena, the warrior wench, she's sometimes \n"+
      "known as the lesbian princess. She is a big, brawny woman with \n"+
      "beautiful blue eyes and the body of athletic wench. She smiles\n"+
      "seductively at you. As with all people a look can be deceiving\n"+
      "and a touch can be lethal.  She smirks at you and says:\n\n"+
      "     You should NEVER hit a woman! \n\n");
   set_spell_mess1("Xena somersaults and kicks her oppenent in the head!\n");
   set_spell_mess2("Xena drop kicks you! \n");
   set_chance(50);
   set_dead_ob(TO);
   set_spell_dam(80);
   set_no_steal();
   set_n_ac(40);
   set_number_of_arms(2);
   add_money(5000+random(1000));
   sword= TR(CO("/players/gareth/guild/obj/bas_sword"), TO);
   bracers= TR(CO(PG+"guild/obj/bracers"),TO);
   xplate= TR(CO(PG+"guild/obj/xplate"), TO);
   xblade= TR(CO(PG+"guild/obj/xblade"), TO);
   init_command("wield blade");
   init_command("wield sword");
   init_command("wear bracers");
   init_command("wear armour");

   }
}

  heart_beat(){
    ::heart_beat();
    attack();
    attack();
}

int query_str() { return 100; }

int monster_died(object mob) {
   object ob;
   if (!TP->query_immortal()) {
      shout("Xena the Warrior Wench shouts: "+TPRN+" is a pig! \n\n"+
            TPRN+" defeated Xena the Warrior Wench !\n");
   }

   if (ob)
      destruct(ob);
   return 0;
}

hold() {
   write("\n\n Xena laughs: Fool, I'm too fast to be held !!!\n\n");
  return 1;
}

int add_poison(int x) { return (x/15); }


