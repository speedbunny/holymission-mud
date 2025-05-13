//  The Elemental Lord

#define MAX_LIST 20

inherit "obj/monster";
#include "/obj/monsoul.c"
#include "/players/tamina/defs.h"

object armour;
int concentrating;

reset(arg) 
{
  ::reset(arg);
  if(!arg)
  {
    set_name("Elemental Lord");
    set_alt_name("lord");
    set_race("elemental");
    set_short("The Lord of the Elements");
    set_long(
"A 9 foot-tall spectre that seems to simply absorb the light from\n"+
"the room.  He is in humanoid form, but possesses no features which\n"+
"suggest any degree of humanity.\n");
    set_gender(1);
    set_level(88);
    set_hp(13600);
    set_wc(60);
    set_ac(30);
    set_size(5);
    set_al(-1000);
    set_aggressive(1);
    set_dead_ob(TO);
    add_money(20000);
    set_language_skill(0, 100);
    set_language_skill(2, 100);
    set_speaks_in(0);

    change_spell("fireball", 95, 95, 0); 
    change_spell("meteor swarm", 60, 95, 1); 
    change_spell("chainlightning", 80, 95, 1);
    change_spell("lightning bolt", 95, 95, 0);
    change_spell("acid blast", 95, 95, 1);
    change_spell("magic missile", 95, 95, 0);  
    change_spell("fear", 90, 95, 0);
  }
  sreset(arg);
}

int query_dex() { return 110;  }
int query_str() { return 130;  }
int query_int() { return 120;  }

monster_died(ob)
{
  object grail;

  shout("A great -= Evil Presence =- is now no more !\n"+
	TPN+" has defeated the Elemental Lord !!\n");
  write("\nAs you remove your final thrust, and the darkness around you\n"+
	"dissipates, you see a beautiful chalice land softly on the floor.\n");

  if (present("grail", TP))
  {
    write("\nYou already have a Holy Grail in your possession.\n"+
	  "You are not going to need two.\n");
    write("The Holy Grail fades into an insubstantial mist...\n");
    return 0;
  }
  write("You decide to take it as a reward for your troubles.\n");

  grail = clone_object(COBJ + "grail");
  transfer(grail, TP);
  destruct(TO);
}

int concentrate(object vic)
{
  int rnd;

  if (vic && !query_concentrating())
  {
    rnd = random(111);
    switch(rnd)
    {
      case 0 .. 20:
       concentrating = 1;
       npc_process_spell("fireball", vic);
      break;

      case 21 .. 34:
       concentrating = 1;
       npc_process_spell("magic missile", vic);
      break;

      case 35 .. 57:
       concentrating = 1;
       npc_process_spell("chainlightning", vic);
      break;

      case 58 .. 70:
       concentrating = 1;
       npc_process_spell("lightning bolt", vic);
      break;

      case 71 .. 75:
       concentrating = 1;
       npc_process_spell("fear", vic);
      break;

      case 76 .. 95:
       concentrating = 1;
       npc_process_spell("acid blast", vic);
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

int no_hold()
{
  if (!random(3))
  {
    write("The Elemental Lord sneers at your puny magics.\n");
    return 1;
  }
}
