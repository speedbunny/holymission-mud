#define MAX_LIST 20

inherit "obj/monster";
#include "/players/saffrin/defs.h"

object armour;
int concentrating;

reset(arg) 
{
  ::reset(arg);
  if(!arg)
  {
    set_name("Mage-Master Cherlindrea");
    set_alt_name("cherlindrea");
    set_race("fairy");
    set_short("Mage-Master Cherlindrea");
    set_long(
      "This is an impressive fairy with long silver wings and flowing "+
      "red hair.  Her emerald green eyes flash at you with a smile.  "+
      "She is a master of the mages.\n");
    set_gender(2);
    set_level(100);
    set_hp(18000);
    set_wc(75);
    set_ac(45);
    set_al(500);
    set_dead_ob(TO);
    add_money(10000);

    armour = clone_object("/players/saffrin/area/tower/obj/cherrobe");
    transfer(armour, this_object());
    init_command("wear robe");

     //  Mage-Master spells
    change_spell("fireball", 75, 95, 2);
    change_spell("chainlightning", 95, 95, 1);
    change_spell("lightning bolt", 95, 95, 0);
    change_spell("meteor swarm", 90, 95, 0);
    change_spell("fear", 95, 95, 1);
    change_spell("fear", 90, 95, 0);
  }
#if 0
// Sauron: Do not call this specifically - it's called in reset() in
//         monster.c
  sreset(arg);
#endif
}


monster_died(ob)
{
  shout(CRN+" has destroyed Mage-Master Cherlindrea!\n");
  write("You have destroyed Mage-Master Cherlindrea!\n");
}

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
       npc_process_spell("meteor swarm", vic);
      break;

      case 34 .. 45:
       concentrating = 1;
       npc_process_spell("fear", vic);
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
       npc_process_spell("meteor swarm", vic);
      break;

      case 84 .. 99:
       concentrating = 1;
       npc_process_spell("lightning bolt", vic);
      break;

      default:
       concentrating = 1;
       npc_process_spell("fear", vic);
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
  if (!random(3))
  {
    write("Mage-Master Cherlindrea resists your hold!\n");
    return 1;
  }
}
