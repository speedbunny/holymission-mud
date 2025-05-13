inherit "obj/monster";

#include "/players/morningsir/defs.h"

object weap1;

reset(arg) 
{
  ::reset(arg);    /* This was missing !!  */
  if (arg) return;

  set_name("death");
  set_alias("death");
  set_alt_name("zombie");
  set_race("skeleton");
  set_gender(2);     /* 0 = neuter, 1 = male, 2 = female */
  set_level(30);
  set_hp(800000);
  set_al(-1000);
  set_short("A Death warrior.");
  set_long("The Death warrior is not deadly, it's the death itself!\n" +
           "You'd better run away...\n");
  set_wc(400);  /*  ???  */
  set_ac(100);
  set_aggressive(1);
  set_chance( 75);
  set_spell_dam(100);
  set_spell_mess1("The Death warrior swings his scythe at his attacker's head.\n");
  set_spell_mess2("The Death warrior swings his scythe at you!\n" +
                  "You feel your life draining from your throat...\n");
  add_money(666);
  set_dead_ob(TO);

/* inventory */

  weap1 = clone_object(PATHW + "scythe.c");
  move_object(weap1, TO);
  command("wield scythe");
}

monster_died(mob) 
{
  write("Deeath grins evilly at you.\n\n"+
        "The zombie screams in fear and suddenly explodes into million pieces.\n");


  say("As "+TPN+" blows the final hit to the zombie, it explodes\n"+
      "into a million pieces !!\n");

  shout("Death shouts: I will kill you next time, "+TPN+" !!\n");
  return 1;
}


/*  Do not use init_command
 *  command(str, ob) is better
 *
 *  the shouts do not have to be commands...
 *
 */
/*  rom=environment(TO); */

/*  set_ep(900000);
    This command actually is supposed to _reduce_ the amount of EXP
    given to a player...  */
/*  set_al(-5000 );    too much   */

/*
  set_move_at_reset(0);    Unnecessary - default settings anyway  ;-)
  set_whimpy(  0);
*/

/*  say("As "+TPN->query_name()+" blows the final hit to the zombie it 
explodes\n" +  "into million pieces.\n");  ->wrong macro  ;-)<-  
*/


/*  init_command("shout I will kill you next time, " + TPN->query_name() + " !!!");
  init_command("laugh evilly");
  init_command("drop scythe");
*/
/*  destruct(present("corpse",TO)); */

