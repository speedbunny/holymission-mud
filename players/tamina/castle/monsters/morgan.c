#include "/players/tamina/defs.h"
#define AO  attacker_ob

inherit "/obj/monster";

reset(arg) {
  ::reset(arg);
  if (!arg) {

	set_name("Morgan le Fey");
	set_alt_name("morgan le fey");
	set_alias("morgan");
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
	set_hp(2500);
        set_wc(25);
        set_ac(15);
        add_money(1500 + random(3001));
        set_dead_ob(TO);
	load_a_chat(13,
    ({"Morgan's Wizardhood protects her from death !!\n"+
      "You missed.\n",
      "Morgan screams something in Celtic, which you cannot understand.\n",
      "Morgan weaves her fingers about in a violent motion.\n",
      "Morgan says: Thou foolish mortal ! \n"+
      "             Thinkest thou that I can be defeated by thee ?!\n",
      "Morgan screams for her personal guards.\n", }) );

     }
}

attack()                      /* This re-defines the spell_attacks 	*/
{			      /* of the monster.			*/
  object victim;	      /* This is desired, principally because	*/
  string att_name;	      /* Morgan le Fey is a Sorceress, and 	*/
  int p;                      /* ought to have more spells at her	*/
  if (::attack()) 	      /* disposal  =)	        		*/
    { 				  
      victim = TO->query_attack(); 
      att_name = victim->NAME;

        switch(random(101)) 
	{
	case 1 .. 27:
	  say("Morgan le Fey throws a Bolt of Ice at "+att_name+" !!\n");
	  victim->hit_player(15 + random(16));
	  break;
	case 46 .. 59:
	  say("Morgan le Fey throws a bristling Bolt of blue Plasma at "+att_name+" !!\n"); 
	  victim->hit_player(30 + random(21));
	  break;
	case 60 .. 67:
	  say("Lightning ZzAaPpPsS into "+att_name+".  "+CAP(victim->QPRO)+" smells well done.\n"); 
	  victim->hit_player(50 + random(31));
	  break;
	case 68 .. 71:
	  say("A Bolt of pure Nether is hurled at "+att_name+" !!\n"+  
              "Maybe "+victim->QPRO+" will survive...\n");
	  victim->hit_player(60 + random(41));
	  break;
	case 78 .. 84:
	  say(
"Morgan creats a powerful Whirlwind, and directs it at "+att_name+".\n\n"+
"You see that "+victim->QPRO+" is swiftly spirited away by the winds.\n");
	  victim->hit_player(10 + random(21)); 

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
	      victim->move_player("into the air!#/players/wolfi/room/enter_hall");
	      TRM("/players/wolfi/room/enter_hall", att_name+" lands with a thump.\n");
 	      command("look", victim);
	      break;
	    case 59 .. 65:
	      victim->move_player("into the air!#/room/forest11");
	      TRM("/room/forest11", att_name+" lands with a thump.\n");
 	      command("look", victim);
	      break;
	    case 66 .. 75:
	      victim->move_player("into the air!#/players/matt/newworld/plains/rooms/hut01");
	      TRM("/players/matt/newworld/plains/rooms/hut01", att_name+" lands with a thump.\n");
 	      command("look", victim);
	      break;
          }  
	  break;
	case 0:
	  return;
	case 28 .. 45: 
	  return;
	case 72 .. 77: 
	  return;
	case 85 .. 100:
	  return;
	default: 
	  return;
	}
      return 1;
      
    } 
  
  return 0;  
}

monster_died (ob) 
{
  object key, wand;

  wand = present("red wand", TP);
  if (wand)
  {
    write("The Red Wand disolves into mist...\n");
    destruct(wand);
  }
  TRM (E (TO),
    "\nMorgan lets out a terrible wail as she falls over, dead!\n\n");

  write("You notice a very valuable looking key fall from\n"+
        "Morgan's robes as she dies...\n\n");

  key = CLO (OTH + "gen_key");

  key->set_key_data("ivory keym1");

  MO (key, TO);

}

init() 
{
  ::init();
  set_heart_beat(1);
}

heart_beat() 
{
  ::heart_beat();

  write("Heart Beat activated.\n");
  
  if (AO && present(AO, ENV)) 
  {
    if (!random(9))
    {
      TOBJ(AO, "Morgan casts a hold spell at you !!\n");
      say("Morgan has cast a hold spell at "+AO->NAME+".\n", AO);

	 AO->hold(TP, (1 + random(7)));
    }
  }
}

hold_end(obj) 
{
  TOBJ(obj, "Morgan's Hold spell has worn off.\n");
  return 1;
}
