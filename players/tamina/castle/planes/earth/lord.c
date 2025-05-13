#define MAX_LIST 20

inherit "/obj/monster";
#include "/obj/monsoul.c"
#include "/players/tamina/defs.h"

object ring;
int doing;

reset(arg) 
{
  object ob;
  ::reset(arg);
  if(!arg) 
  { 
    set_name("Lord of Earth");
    set_alias("lord");
    set_race("elemental");
    set_gender(1);
    set_level(60);
    set_short("Lord of Earth");
    set_long(
  "This is a huge Elemental constructed entirely from earth and stone.\n"+
  "He looks so solid, you fear striking him with your weapons...\n");
    set_al(-900);
    set_aggressive(1);
    set_size(5);
    set_hp(10000);
    set_wc(50);
    set_ac(20);
    set_dead_ob(clone_object(EARTH + "corpse"));
    set_language_skill(0, 100);
    set_language_skill(2, 100);
    set_speaks_in(0);
   
    change_spell("magic missile", 85, 95, 0);
    change_spell("fear", 75, 95, 0);
    change_spell("entangle", 90, 95, 0);
    change_spell("firestorm", 75, 95, 1);
    change_spell("meteor swarm", 50, 70, 2);

    ob = clone_object("/obj/shadows/true_sight_shad");
    ob->start_shadow(this_object(), 0);

    ob = clone_object("/obj/shadows/stoneskin_shad");
    ob->start_shadow(this_object(), 0);

    ring = CLO (COBJ + "d_ring");
    MO (ring,  TO);
  }
  sreset(arg);
}

int concentrate(object vic)
{
  int rnd;

  if(vic && !query_concentrating())
  {
    rnd = random(100);
    switch(rnd)
    {
      case 0 .. 20:
       npc_process_spell("magic missile", vic);
       doing = 1;
      break;

      case 21 .. 46:
       npc_process_spell("fear", vic);
       doing = 1;
      break;

      case 47 .. 69:
       npc_process_spell("entangle", vic);
       doing = 1;
      break;

      case 70 .. 85:
       npc_process_spell("firestorm", vic);
       doing = 1;
      break;

      default:
       npc_process_spell("meteor swarm", vic);
       doing = 1;
      break;
    }
  }
  doing = 0;
  return 1;
}

int query_concentrating()
{
  return doing;
}

int query_con() { return 90; }
int query_str() { return 100; }
