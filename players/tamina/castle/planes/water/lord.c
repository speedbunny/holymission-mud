#define MAX_LIST 20

inherit "/obj/monster.c";
#include "/obj/monsoul.c" 
#include "/players/tamina/defs.h"

object pipe;
int concentrating;

void reset(int arg) 
{
  object ob;
  ::reset(arg);
  if(!arg) 
  {
    set_name("Lord of Water");
    set_alias("lord");
    set_short("Lord of Water");
    set_race("elemental");
    set_gender(1);
    set_long(
  "This is an incredibly supernatural being made entirely out of\n"+
  "waves of water. He stands incredibly tall, dressed in all manner\n"+
  "of shimmering armours.  He looks very powerful. \n"+
  "Dare you confront it?\n");
    set_level(60);
    set_hp(10000);
    set_wc(50);
    set_ac(25);
    set_aggressive(1);
    set_dead_ob(clone_object(WATER + "corpse"));
    set_language_skill(0, 100);
    set_language_skill(2, 100);
    set_speaks_in(0);

    change_spell("lightning bolt", 85, 95, 1);
    change_spell("bolt", 95, 95, 0);
    change_spell("lightning", 95, 95, 0);
    change_spell("chainlightning", 70, 95, 2);
    change_spell("fear", 95, 95, 0);

    pipe = clone_object(COBJ + "pipe");
    MO(pipe, TO);

    ob = clone_object("/obj/shadows/true_sight_shad");
    ob->start_shadow(this_object(), 0);
  }
  sreset(arg);
}

int concentrate(object vic)
{
  int rnd;

  if (vic && !query_concentrating()) 
  {
    rnd = random(100);
    if (rnd < 5)
    {
      npc_process_spell("chainlightning", vic);
      concentrating = 1; 
    }
    else if (rnd < 20)
    {
      npc_process_spell("lightning bolt", vic);
      concentrating = 1; 
    }
    else if (rnd < 40)
    {
      npc_process_spell("bolt", vic);
      concentrating = 1; 
    }
    else if (rnd < 60)
    {
      npc_process_spell("lightning", vic);
      concentrating = 1; 
    }
    else if (rnd < 85)
    {
      npc_process_spell("fear", vic);
      concentrating = 1; 
    }
   }
   concentrating = 0;
   return(1);
}

int query_concentrating()
{
  return concentrating;
}

int query_dex() {  return 90;  }
int query_con() {  return 80;  }
int query_str() {  return 90;  }

