#define MAX_LIST 20

inherit "/obj/monster";
#include "/obj/monsoul.c"
#include "/players/tamina/defs.h"

object robe, ob;
status doing;

reset(arg) 
{
  ::reset(arg);
  if (!arg) 
  {
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
    set_hp(7500);
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
    set_language_skill(0, 100);
    set_language_skill(2, 100);
    set_speaks_in(0);

    change_spell("meteor swarm", 65, 75, 2);
    change_spell("chainlightning", 75, 80, 1);
    change_spell("entangle", 75, 80, 1);
    change_spell("lightning bolt", 80, 95, 1);
    change_spell("fireball", 80, 95, 1);
    change_spell("magic missile", 95, 95, 0);
    change_spell("fear", 95, 95, 1);

    ob = clone_object("/obj/shadows/fireshield_shad");
    ob->start_shadow(this_object(), 0, 4);

    ob = clone_object("/obj/shadows/true_sight_shad");
    ob->start_shadow(this_object(), 0);

    robe = clone_object("/players/tamina/castle/obj/robe");
    MO(robe, TO);
    command("wear robe", TO);
  }
  sreset(arg);
}

int concentrate(object vic)
{
  int rnd;

  if (vic && !query_concentrating())
  {
    rnd = random(100);
    switch(rnd)
    {
      case 0 .. 16:
      npc_process_spell("magic missile", vic);
      doing = 1;
      break;

      case 17 .. 29:
      npc_process_spell("entangle", vic);
      doing = 1;
      break;

      case 30 .. 42:
      npc_process_spell("fireball", vic);
      doing = 1;
      break;

      case 43 .. 57:
      npc_process_spell("lightning bolt", vic);
      doing = 1;
      break;

      case 58 .. 73:
      npc_process_spell("fear", vic);
      doing = 1;
      break;

      case 74 .. 87:
      npc_process_spell("chainlightning", vic);
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

int query_wis() { return 75; }
int query_str() { return 60; }
int query_chr() { return 60; }

int query_concentrating()
{
  return doing;
}

void init()
{
  ::init();
  add_action("no_hold", "hold");
}

int no_hold()
{
  if (!random(2))
  {
    write("Morgan le Fey counters your hold spell !!\n");
    return 1;
  }
}

