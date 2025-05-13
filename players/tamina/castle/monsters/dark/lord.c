#include "/players/tamina/defs.h"
#define AO  attacker_ob

inherit "/obj/monster";
object crown, sceptre;

void reset(int arg) 
{
  ::reset(arg);
  if(arg) return;

   set_name("Darkling Lord");
   set_alias("lord");
   set_race("darkling");
   set_gender(1);
   set_size(5);
   set_level(79);
   set_wc(60);
   set_ac(30);
   set_short("The Lord of Darkness");
   set_long("An 9 foot-tall spectre, that seems to simply absorb\n"+
	 "the light from the room.  He is in humanoid form,\n"+
	 "but possesses no features that suggest humanity.\n");
   set_al(-1000);
   set_aggressive(1);  
   set_dead_ob(TO);

   crown   = CLO ("obj/armour");
   sceptre = CLO ("obj/weapon");

   crown->set_name("crown of darkness");
   crown->set_alias("crown");
   crown->set_type("helmet");
   crown->set_ac(1);
   crown->set_short("Crown of Darkness");
   crown->set_long(
"This is the Crown worn for eons by the Darkling Lord, the menace of\n"+
"the Planes.  It has been crafted by outstanding expertise, made from\n"+
"what would appear to be ... solid darkness !!\n");
   crown->set_weight(4);
   crown->set_value(1000);
   crown->set_size(0);

   sceptre->set_name("sceptre of darkness");
   sceptre->set_alias("sceptre");
   sceptre->set_short("Sceptre of Darkness");
   sceptre->set_long(
"A magnificently wound rod of blackest metal that appears to have\n"+
"some extra properties...\n");
   sceptre->set_class(13);
   sceptre->set_weight(3);
   sceptre->set_value(1200);

   MO (sceptre, TO);
   MO (crown, TO);
   command("wear crown");

}

attack()
{
  object victim, retainer;
  string att_name;
  int p;

  if (::attack())
  {
    victim = TO->query_attack();
    att_name = victim->NAME;

    switch(random(101))
    {
      case 0:
        break;
      case 1 .. 24:
        TOBJ(victim, "The Darkling Lord clasps his ice-cold hands around your throat...\n"+
		     "And SQUEEZES!!!\n");
	say("The Darkling Lord grips "+att_name+" by the throat,\n"+
 	    "and tries to throttle "+victim->QOBJ+" !!\n");
	victim->hit_player(40 + random(51));
    	break;
      case 25 .. 39:
	say("The Darkling Lord casts a cloud of UTTERDARKNESS at "+att_name+" !!\n"+
	    "It presses, crushes, constricts "+victim->QOBJ+"...\n");
	victim->hit_player(60 + random(71));
    	break;
      case 40 .. 41:
	say("The Darkling Lord summons a few of his retainers to aid him in battle !!\n");
	retainer = CLO (DARK + "retainer");
	MO (retainer, TO);
    	break;
      case 42 .. 59:
     	say("The Darkling Lord shoots bolts of bristling Darkness at "+att_name+" !!\n");
  	victim->hit_player(30 + random(41));
    	break;
      case 60 .. 69:
	say("The Darkling Lord waves his sceptre at "+att_name+" !!\n");
  	victim->hit_player(20 + random(31));
    	break;
      default:
	return;

    }
    return 1;
  }
  return 0;
}

monster_died (ob) 
{
  object grail;

  shout("A great -= Evil Presence =- is now no more!\n"+
      	TPN+" has defeated the Darkling Lord!!\n");
        
  write("\nAs you remove your final thrust, and the Darkness around you\n"+
        "dissipates, you see a beautiful Chalice land softly on the floor.\n\n");

  if (present("grail", TP)) 
  {
    write("\nYou already have a Holy Grail in your possession.\n"+
 	  "You are not going to need two!!\n");
    return 0;
  }
  write("You decide to take it as a reward for your troubles.\n\n");

  grail = CLO(COBJ + "grail");
  TR (grail, TP);

  destruct (TO);
}

