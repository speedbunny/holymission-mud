#include "/players/tamina/defs.h"
#define AO  attacker_ob

inherit "/obj/monster";

reset(arg) {
  ::reset(arg);
  if (!arg) {

	set_name("Morgan le Fey");
	set_alt_name("morgan");
	set_race("human");
	set_gender(2);
	set_level(55);
	set_short("Morgan le Fey");
	set_long(
"You see a darkly handsome woman, who appears to look directly at you, with\n"+ 
"a peculiar grin on her face.  She is wearing a black robe that appears\n"+
"indistinct to your eyes... You do not think you would like to anger this\n"+
"woman, as you can sense an aura of power around her.\n");
	set_al(-1000);
	set_aggressive(1);
	set_hp(8000);
        set_wc(30);
        set_ac(19);
	set_spell_mess2(
"Morgan's fingers sparkle with energy as your hair stands on end!\n");
	set_spell_mess1(
"Lightning zZaAaPpPss into Morgan Le Fey's victim.  "+capitalize(TP->QPRO)+" smells well-done.\n");
	set_spell_dam(80+random(55));
	set_chance(35);
        add_money(5000);
        set_dead_ob(TO);
   }
}

attack() 
{
  object victim;


  if (::attack()) 
  { 
    victim = TO->query_attack(); 

     if (random(101) < 76 ) 
     { 
       victim->hit_player(75+random(75));
       message(victim);
     }
     else 
     {
       victim->hit_player(50+random(50));
       message(victim);
             }
     return 1;  
   } /*end if*/

 return 0;  
}


message(victim) 
{  
string att_name;

   att_name = victim->NAME;
      if (random(10) < 5) 
      {
          write("The Queen casts a snowstorm at you.\n");
          say("The Queen casts a snowstorm at "+att_name+".\n");
      }
        else  
      {
          write("The Queen strucks you with a blast of evil.\n");
          say("The Queen hits "+att_name+" with a blast of evil.\n");
       }
 return 1;
}

monster_died (ob) {
 object key;

  TRM (E (TO),
    "\nMorgan lets out a terrible wail as she falls over, dead!\n\n");

  write("You notice a very valuable looking key fall from\n"+
        "Morgan's robes as she dies...\n\n");

  key = CLO(OTH + "gen_key");

  key->set_key_data("ivory keym1");

  MO (key, TO);

}

init() {
  ::init();
  set_heart_beat(1);
}

heart_beat() {
  ::heart_beat();

  write("Heart Beat activated.\n");
  
  if(AO && present(AO, environment()) ) {
    if(random(101) < 8) {
      TOBJ(AO, "Morgan casts a hold spell at you!!\n");
      say("Morgan has cast a hold spell at "+AO->NAME+".\n", AO);

	 AO->hold(TP, 6);
      }
 
   }

}

hold_end(obj) {
    TOBJ(obj, "The Hold spell has worn off.\n");
    return 1;
}


