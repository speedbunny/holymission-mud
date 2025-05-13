//  Misthena, the 5-Headed Primsatic Dragon.  Her heads:
//  Red - Fire
//  Black - Earth
//  Blue - Electricity
//  Green - Acid
//  White - Wind

#define MAX_LIST 20

inherit "obj/monster";
#include "/obj/monsoul.c"
#include "/players/tamina/defs.h"

object armour, ob;
int concentrating;

reset(arg) 
{
  ::reset(arg);
  if(!arg)
  {
    set_name("misthena");
    set_alt_name("dragon");
    set_race("dragon");
    set_short("Misthena, the Prismatic Dragon");
    set_long(
"This is a huge Prismatic dragon, with five snaking heads, of differing \n"+
"colours Red, Black, Blue, Green, and White.  The presence of Misthena\n"+
"is utterly awesome, so much so that you find it hard to be anywhere\n"+
"near her.\n");
    set_gender(2);
    set_level(76);
    set_hp(13600);
    set_wc(75);
    set_ac(25);
    set_size(5);
    set_al(-900);
    set_aggressive(1);
    set_dead_ob(TO);
    add_money(10000);
    set_language_skill(0, 100);
    set_language_skill(2, 100);
    set_speaks_in(0);

    ob = clone_object("/obj/shadows/resist_acid_shad");
    ob->start_shadow(this_object(), 0);

    ob = clone_object("/obj/shadows/resist_fire_shad");
    ob->start_shadow(this_object(), 0);

    ob = clone_object("/obj/shadows/resist_elect_shad");
    ob->start_shadow(this_object(), 0);    

    armour = clone_object("/players/tamina/teds/armors/prism_armour");
    transfer(armour, this_object());

    change_spell("fireball", 95, 95, 1);       //Red for Fire
    change_spell("meteor swarm", 75, 95, 2);   //Black for Lava
    change_spell("chainlightning", 80, 95, 1); //Blue for lightning
    change_spell("lightning bolt", 95, 95, 0);
    change_spell("acid blast", 95, 95, 0);     //Green for acid
    change_spell("acid rain", 80, 95, 1);     
    change_spell("summon wind", 95, 95, 1);    //White for wind
    change_spell("fear", 90, 95, 0);           //DragonFear
  }
  sreset(arg);
}

int query_dex() { return 80;  }
int query_str() { return 100; }
int query_wis() { return 90;  }

 /*    Sorry Tamina trying to reduce the amount of shouts from non quest 
        monsters.
monster_died(ob)
{
  shout(TPN+" has dealt the killing blow to Misthena, the Prismatic Dragon !!\n");
  write("You have killed Misthena, the Primsatic Dragon !!\n");
}
   */

int concentrate(object vic)
{
  int rnd;

  if (vic && !query_concentrating())
  {
    rnd = random(111);
    switch(rnd)
    {
      case 0 .. 16:
       concentrating = 1;
       npc_process_spell("fireball", vic);
      break;

      case 17 .. 33:
       concentrating = 1;
       npc_process_spell("summon wind", vic);
      break;

      case 34 .. 45:
       concentrating = 1;
       npc_process_spell("acid rain", vic);
      break;

      case 46 .. 57:
       concentrating = 1;
       npc_process_spell("lightning bolt", vic);
      break;

      case 58 .. 74:
       concentrating = 1;
       npc_process_spell("chainlightning", vic);
      break;

      case 75 .. 83:
       concentrating = 1;
       npc_process_spell("fear", vic);
      break;

      case 84 .. 99:
       concentrating = 1;
       npc_process_spell("acid rain", vic);
      break;

      default:
       concentrating = 1;
       npc_process_spell("meteor swarm", vic);
      break;
    }
  }
  concentrating = 0;
  return 1;
}

int query_concentrating()
{
  return concentrating;
}

void init()
{
  ::init();
  add_action("no_hold", "hold");
}

no_hold()
{
  if (!random(4))
  {
    write("Misthena counters your hold spell !!!\n");
    return 1;
  }
}
