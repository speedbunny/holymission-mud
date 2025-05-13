#define MAX_LIST 20

inherit "obj/monster.c";
#include "/obj/monsoul.c"
#include "/players/tamina/defs.h"

int concentrating;

reset(arg) 
{
  ::reset(arg);
  if(!arg)
  {
    set_name("satyr");
    set_race("faerie");
    set_short("Satyr");
    set_long(
"This fey creature has the upper body of a man, and the legs\n"+
"of a goat.  He is a very mischeivous creature, powerful in magic\n"+
"and not very easy to kill.\n");
    set_gender(1);
    set_level(30);
    set_hp(2500);
    set_wc(31);
    set_ac(20);
    set_size(2);
    set_al(100);
    set_aggressive(0);
    add_money(1000);
    set_language_skill(0, 100);
    set_language_skill(2, 100);
    set_speaks_in(0);

    change_spell("mirror image", 95, 95, 1);
    change_spell("colorspray", 60, 95, 0);
    change_spell("entangle", 80, 95, 1);
    change_spell("faerie fire", 95, 95, 0);
    change_spell("bolt", 95, 95, 0);
    change_spell("magic missile", 90, 95, 0);
  }
  sreset(arg);
}

int query_dex() { return 80;  }
int query_int() { return 60;  }
int query_wis() { return 70;  }
int query_chr() { return 75;  }

int concentrate(object vic)
{
  int rnd;

  if (vic && !query_concentrating())
  {
    rnd = random(100);
    switch(rnd)
    {
      case 0 .. 22:
       concentrating = 1;
       npc_process_spell("bolt", vic);
      break;

      case 23 .. 43:
       concentrating = 1;
       npc_process_spell("faerie fire", vic);
      break;

      case 44 .. 60:
       concentrating = 1;
       npc_process_spell("entangle", vic);
      break;

      case 61 .. 79:
       concentrating = 1;
       npc_process_spell("bolt", vic);
      break;

      case 80 .. 94:
       concentrating = 1;
       npc_process_spell("colorspray", vic);
      break;

      default:
       concentrating = 1;
       npc_process_spell("mirror image", vic);
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
