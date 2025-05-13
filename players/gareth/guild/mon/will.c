#include "/players/gareth/define.h"
#define TPRN capitalize(TPN)
inherit "/obj/monster";

 object ring,arms,shield,armour,helm,sword;

reset(arg) {
   ::reset(arg);
   if (!arg) {
   set_name("William the Conqueror");
   set_living_name("william");
   set_alt_name("conqueror");
   set_alias("william");
   set_level(100);
   set_hp(30000);
   set_race("human");
   set_size(3);
   set_gender(1);
   load_chat(9,
      ({ 
      "William the Conqueror prepares to win more glorious battles.\n",
      "William says: Only a Fool is not afraid of combat !\n",
      "William says: There's no honor in destroying the weak.\n",
      "William the Conqueror says: Let those who fear you follow you, those who oppose you - DIE!\n",
      "William says: Even the wolf can be prey to the tiger\n",
      "Sir William grins evilly.\n",
      }));
   load_a_chat(9,
      ({
      "William growls: Come on punk!!!! Let's Fight!!\n",
      "William howls: I'm going to kick your Ass now!\n",
      "William says: Mess with me will ya? I'll teach you!\n",
      "William GROWLS in anger.\n",
      }));
   set_long(
      "You see a big, muscular Human Fighter. He is well known\n"+
      "as one of the best fighters in this world. With his grinning\n"+
      "face he looks at you like he would say:\n\n"+
      "             Mess with me and I'll kick yer puny Ass PUNK !\n");
   set_spell_mess1("William The conquerer disembowels you!\n");
   set_spell_mess2("William smashes his head in your face.\n");
   set_chance(80);
   set_dead_ob(TO);
   set_spell_dam(150);
   set_no_steal();
   set_n_ac(30);
   set_number_of_arms(2);
   add_money(1+random(1000));
   sword= TR(CO("/players/gareth/guild/obj/bas_sword"), TO);
   ring= TR(CO("/players/llort/animals_stuff/diring"), TO);
   arms= TR(CO("/players/whisky/obj/arms"),TO);
   armour= TR(CO(PG+"guild/obj/aarmour"), TO);
   shield= TR(CO("/players/gareth/guild/obj/ashield"), TO);
   helm= TR(CO("/players/uglymouth/vikings/items/vikhelm"),TO);
   sword= TR(CO(WEP+"frost"), TO);
   init_command("wield frostbite");
   init_command("wield sword 2");
   init_command("wear arms");
   init_command("wear armour");
   init_command("wear shield");
   init_command("wear helm");
   init_command("wear ring");

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

int monster_died(object mob) {
   object ob;
   if (!TP->query_immortal()) {
      shout(TPRN+" defeated William the conqueror !\n");
   }

   if (ob)
      destruct(ob);
   return 0;
}

hold() {
   write("\n\n William The Conqueror growls: Pathetic Fool!! You CAN'T hold me!!!\n\n");
  return 1;
}

int add_poison(int x) {
   return (x/30);
}


