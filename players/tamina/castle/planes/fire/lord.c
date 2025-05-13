#define MAX_LIST 20

inherit "/obj/monster.c";
#include "/obj/monsoul.c" 
#include "/players/tamina/defs.h"

object last, ruby;
int concentrating;

void reset(int arg) 
{
  object ob;
  ::reset(arg);
  if(!arg) 
  {
    set_name("Lord of Fire");
    set_alias("lord");
    set_short("Lord of Fire");
    set_race("elemental");
    set_gender(1);
    set_long(
  "This is the Lord of the Elemental Plane of Fire.  He stands incredibly\n"+
  "tall, with immense arms constructed of pure fire.  \n"+
  "Dare you challenge him?\n");
    set_level(60);
    set_hp(10000);
    set_wc(30);
    set_ac(25);
    set_dead_ob(clone_object(FIRE + "corpse"));
    set_aggressive(1);
    set_language_skill(0, 100);
    set_language_skill(2, 100);
    set_speaks_in(0);

    change_spell("meteor swarm", 85, 95, 1);
    change_spell("fireball", 80, 100, 1);
    change_spell("fire shuriken", 95, 100, 0);
    change_spell("faerie fire", 95, 100, 0);
    change_spell("firestorm", 70, 95, 1);
    change_spell("fear", 95, 95, 0);

    ruby = clone_object(COBJ + "ruby");
    MO(ruby, TO);

    ob = clone_object("/obj/shadows/fireshield_shad");
    ob->start_shadow(this_object(), 0, 1);

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
    rnd = random(91);
    switch(rnd)
    {
      case 0 .. 12:
      npc_process_spell("fireball", vic);
      concentrating = 1; 
      break;

      case 13 .. 27:
      npc_process_spell("fire shuriken", vic);
      concentrating = 1; 
      break;

      case 28 .. 43:
      npc_process_spell("heat armor", vic);
      concentrating = 1; 
      break;

      case 44 .. 54:
      npc_process_spell("fear", vic);
      concentrating = 1; 
      break;

      case 55 .. 70:
      npc_process_spell("faerie fire", vic);
      concentrating = 1; 
      break;

      case 71 .. 85:
      npc_process_spell("firestorm", vic);
      concentrating = 1; 
      break;

      default:
      npc_process_spell("meteor swarm", vic);
      concentrating = 1; 
      break;
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

