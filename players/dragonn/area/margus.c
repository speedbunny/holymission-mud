#include "/players/dragonn/defs.h"
#define AO attacker_ob
inherit "/obj/monster";

object crown;
int concentrating;

reset(arg) {
  ::reset(arg);
  if(arg) return;

        set_name("Margus");
        set_alias("margus");
        set_alt_name("margus");
        set_race("Idiotic");
        set_gender(1);
        set_level(86);
        set_short("The beloved concubine of the Lord of Darkness");
 set_long("Margus sits behind his bar serving drinks, he is a rather \n"+
           "large man with a heavy black beard and long black eyelashes, \n"+
           "he seems to have had his share of breaking up bar fights, he \n"+
           "is a cheerfull man with a calm smile.\n");
        set_al(-400);
        set_aggressive(1);
        set_weight(3);
        set_wc(70);
        set_ac(50);
load_chat(20,({
    "Margus warns you: No FIGHTS HERE !!!\n",
    "You take one look at Margus and say to yourself 'NO FUCKIN' WAY !!'\n",
    "Margus cheers with a calm smile like an assasin.\n",  
}));
        set_dead_ob(TO);
    set_language_skill(0, 100);
    set_language_skill(2, 100);
    set_speaks_in(0);
    crown = CLO ("obj/armour");

    crown->set_name("Dark crown");
    crown->set_alias("crown");
    crown->set_type("helmet");
    crown->set_short("Dark crown [glowing]");
    crown->set_long("The legendary Dark crown. You feel that glowing \n"+
     "aura surrounds it.\n");
    crown->set_ac(9);
    crown->set_weight(2);
    crown->set_value(2550);
    crown->set_arm_light(-1);

        MO (crown, TO);
        command("wear crown");

        }

attack()
{
  object victim;
  string att_name;
  int p;

  if (::attack())
  {
    victim = TO->query_attack();
    att_name = victim->NAME;

    switch (random(101))
    {
  case 0:
    return;
  case 1 .. 31:
    say(att_name+" is hit by POWER BLAST !!\n");
    victim->hit_player(30 + random(31));
    break;
  case 32 .. 40:
    say("Mario STRIKES "+att_name+" !!\n");
    victim->hit_player(70 + random(41));
    break;
  case 41 .. 43:
    say("Mario screams and hits you in the face!!\n");
    victim->hit_player(70 + random(51));
    break;
  default:
    return;
    }
  return 1;
  }
}

monster_died()
{

  TRM (E (TO),
   "\nMargus screams 'I will be back .... I will pay that back !!!'\n");
shout(TPN+" drains last force from Margus.\n");
  destruct(TO);
  return 1;
}
/*
void init(){
::init();
add_action("no_choke","choke");
}
no_choke(){
write("You feel that you can not do that here.\n");
return 1;
}
*/
