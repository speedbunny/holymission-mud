#include "/players/tamina/defs.h"
#define AO  attacker_ob

inherit "obj/monster";
object hat,cloak;

reset(arg) 
{
  ::reset(arg);
  if (!arg) 
  {
    set_name("merlin");
    set_alias("wizard");
    set_level(60);
    set_race("human");
    set_gender(1);
    set_short("Merlin the Wizard");
    set_long(
      "An apparently feeble old man, who looks at you with bleary eyes.\n"+
      "He is wearing a large robe that seems to be too heavy for him.\n"+
      "His hands seem to shake, perhaps due to age...\n"+
      "But you sense an aura of hidden power about this man, despite \n"+
      "his obvious frail exterior.\n");
    set_wc(29);
    set_ac(19);
    add_money(5000 + random(4001));
    load_a_chat(30,
  ({"Merlin says: Thou darest to attack me ?!\n",
    "Merlin says: Thou art a fool to pit thine attempts at me !!\n",
    "Merlin's Wizardhood protects him from death.\n"+
    "You missed.\n",
    "Merlin says: I shall kill thee for this insult !\n",
    "Merlin prepares to cast a Death-Spell...\n", }) );

  hat   = CLO("obj/armour");
  cloak = CLO("obj/armour");

  hat->set_name("felt hat");
  hat->set_alias("hat");
  hat->set_type("helmet");
  hat->set_short("A Felt Hat");
  hat->set_long(
   "A large, pointed hat, made of a dark, soft material that is very\n"+
   "comfortable to wear.  However, a strange aura of power eminating \n"+
   "the hat seems to suggest some magical properties of a sort...\n");
  hat->set_value(1000);
  hat->set_ac(1);
  hat->set_weight(2);

  cloak->set_name("felt cloak");
  cloak->set_alias("cloak");
  cloak->set_type("cloak");
  cloak->set_short("A Felt Cloak");
  cloak->set_long(
   "A heavy-loking cloak, made of a dark, soft material.  There are\n"+
   "a multitude of pin-points of stars and constellations dotted \n"+
   "across the cloak.  But despite its shabby appearance, it does\n"+
   "have a distinct aura of protection about it...\n");
  cloak->set_value(1500);
  cloak->set_ac(1);
  cloak->set_weight(4);

  MO(hat, TO);
  MO(cloak, TO);
  command("wear hat");
  command("wear cloak");

   }

}

init()
{
  ::init();
  set_heart_beat(1);
  AA("_give", "give");
}

int check_item(object ob)
{
  if (ob->NAME == "whistle") 
    return 1;
  else
  return 0;
}

int _give (string arg)
{
  object wand, obj, p;
  string what, who;
  int val;

  if (!arg)
    return 0;
  if (sscanf(arg, "%s to %s", what, who) != 2) 
    return 0;
  if (!id(who)) 
    return 0;
  
  p = TP;
  obj = present(what, p);

  if (!obj)
    return 0;
  if (MO (obj, TO))
  {
    write("You cannot do that!\n");
    return 1;
  }
  write("You give the "+obj->NAME+" to Merlin.\n");
  say(TPN+" gives a "+obj->NAME+" to Merlin.\n", p);

  val = check_item(obj);
  if (!val)
  {
    TRM(ENV, "\n");	
    write("Merlin gives the item back to you.  He does not like junk.\n");
    say("He gives it back to "+p->NAME+".\n");
    TR(obj, p);
    return 1;
  }
  else
  {
    TRM (ENV, 
   "Merlin says: Thou hast discovered my whistle!!\n"+
   "             Thou art a brave adventurer to have wandered down here.\n"+
   "             P'raps thou art suitable for the task in hand...\n\n"+
   "             As thou may knowest, King Arthur has gone.  He must return.\n"+
   "             If thou canst defeat that sorceress, Morgan le Fey,\n"+  
   "             then perhaps Arthur can return!  \n"+
   "             I can aid thee only so much in this, since I am merely\n"+
   "             a feeble old man, and can do very little on my own...\n");

    wand = CLO(COBJ + "mg_wand");
    TR (wand, p);
    destruct (obj);

    TRM (ENV, 
   "Merlin says: Be careful of young Morgan !!\n"+
   "             She hath more than a few tricks up her sleeve...'\n"
   "             So I will aid thee to defeat her, since I am no longer\n"+
   "             in a proper condition to complete such a task myself.\n"+
   "             Here is a magical wand that may give thee some \n"+
   "             advantage over her, and her evil spawn in battle.'\n");
    return 1;
  }
  return 0;
}


attack()                          /* This re-defines the spell_attacks 	*/
{				  /* of the monster.			*/
  object victim, dragon;          /* This is desired, principally       */
  string att_name;		  /* because Merlin is a Wizard, and 	*/
				  /* ought to have more spells at his  	*/
  if (::attack()) 		  /* disposal   =)			*/
  { 				  
   victim = TO->query_attack(); 
   att_name = victim->NAME;

    switch(random(101))
    {
      case 0:
	say("Merlin summons the foul Dragon to do his bidding !!!\n");
	if (!dragon = present("dragon") && !living(dragon))
        MO (CLO (CMONS + "dragon"), TO);
	say("Merlin screams: Kill the fiend !!\n");
	break;
      case 1 .. 27:
        say("Merlin throws a Bolt of Ice at "+att_name+" !!\n");
        victim->hit_player(15 + random(16));
	break;
      case 46 .. 59:
        say("Merlin throws a bristling Bolt of blue Plasma at "+att_name+" !!\n"); 
        victim->hit_player(30 + random(31));
	break;
      case 60 .. 67:
        say("Lightning ZzAaPpPsS into "+att_name+".  "+CAP(victim->QPRO)+" smells well done.\n"); 
        victim->hit_player(50 + random(51));
	break;
      case 68 .. 71:
        say("A Bolt of pure Nether is hurled at "+att_name+" !!\n"+
            "Maybe "+victim->QPRO+" will survive...\n");
        victim->hit_player(75 + random(76));
	break;
      case 28 .. 45: 
        return;
      case 72 .. 100: 
	return;
      default:
	  say(
"Merlin creats a powerful Whirlwind, and directs it at "+att_name+".\n\n"+
"You see that "+victim->QPRO+" is swiftly spirited away by the winds.\n");
	  victim->hit_player(20 + random(21)); 

	  switch(random(75))
  	  {
	    case 0:
	      victim->move_player("into the sky!#/players/whisky/magic/mages_bar");
	      TRM("/players/whisky/magic/mages_bar", att_name+" lands with a thump.\n");
 	      command("look", victim);
	      break;
	    case 1 .. 15:
	      victim->move_player("into the sky!#/players/tamina/castle/rooms/entrance");
	      TRM(CROOMS + "entrance", att_name+" lands with a thump.\n");
 	      command("look", victim);
	      break;
	    case 16 .. 26:
	      victim->move_player("into the sky!#/players/ted/forest/forest23");
	      TRM("/players/ted/forest/forest23", att_name+" lands with a thump.\n");
 	      command("look", victim);
	      break;
	    case 27 .. 37:
	      victim->move_player("into the sky!#/room/vill_road1");
	      TRM("/room/vill_road1", att_name+" lands with a thump.\n");
 	      command("look", victim);
	      break;
	    case 38 .. 47:
	      victim->move_player("into the air!#/players/whisky/seaword/room/sw_shop");
	      TRM("/players/whisky/seaworld/room/sw_shop", att_name+" lands with a thump.\n");
 	      command("look", victim);
	      break;
	    case 48 .. 58:
	      victim->move_player("into the air!#/players/meecham/tower/hole/path_to_col");
	      TRM("/players/meecham/tower/hole/path_to_col", att_name+" lands with a thump.\n");
 	      command("look", victim);
	      break;
	    case 59 .. 65:
	      victim->move_player("into the air!#/room/forest11");
	      TRM("/room/forest11", att_name+" lands with a thump.\n");
 	      command("look", victim);
	      break;
	    case 66 .. 75:
	      victim->move_player("into the air!#/players/matt/newworld/plains/rooms/plain17");
	      TRM("/players/matt/newworld/plains/rooms/plain17", att_name+" lands with a thump.\n");
 	      command("look", victim);
	      break;
          }  
	  break;
	}
      return 1;
      
    } 
  
  return 0;  
}

heart_beat() 
{
  ::heart_beat();

  write("Heart Beat activated.\n");
  
  if (AO && present(AO, environment()) ) 
  {
    if (random(111) < 15)
    {
      TOBJ(AO, "Merlin has cast a hold spell at you !!\n");
      say("Merlin has cast a hold spell at "+AO->NAME+".\n", AO);

      AO->hold(TP, random(7));
    }
  }
}

hold_end (obj) 
{
   TOBJ (obj, "The Hold spell has worn off.\n");
   return 1;
}
