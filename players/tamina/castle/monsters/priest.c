#define MAX_LIST 20

inherit "/obj/monster";
#include "/obj/monsoul.c"
#include "/players/tamina/defs.h"

object robe, knife;
int doing;

reset(arg) 
{
  object ob;
  ::reset(arg);
  if(!arg) 
  { 
    set_name("Sacrificial Priest");
    set_alt_name("sacrificial");
    set_alias("priest");
    set_race("human");
    set_gender(1);
    set_level(40);
    set_short("A Sacrificial Priest");
    set_long(
"A seven-foot tall, bald man with glowing red eyes, who wears a voluminous\n"+
"red robe.  His fingers are so long and spindly, and his neck so long that he\n"+
"has the look of a spider in human form...\n"+
"The occasional red spark that flashes from his fingers suggests that he knows\n"+
"a thing or two about sorcery\n");
    set_al(-900);
    set_aggressive(1);
    set_size(4);
    set_hp(5555);
    set_wc(35);
    set_ac(25);
    load_a_chat(30,
     ({"The Priest screams at your sacrilege!!\n",
       "The Priest mutters a quick prayer to his foul God for strength.\n",
       "The Sacrificial Priest says: What are you doing here?!  Get out!\n",
       "The Priest calls for his guards!\n"}) );
    set_language_skill(0, 100);
    set_language_skill(2, 100);
    set_speaks_in(0);
   
    change_spell("cause light", 95, 95, 0);
    change_spell("cause serious", 85, 85, 1);
    change_spell("cause critic", 75, 75, 2);
    change_spell("entangle", 90, 90, 0);
    change_spell("firestorm", 70, 95, 1);
    change_spell("slay living", 40, 65, 3);

    ob = clone_object("/obj/shadows/true_sight_shad");
    ob->start_shadow(this_object(), 0);

    robe  = CLO (COBJ + "sac_robe");
   knife = CLO (COBJ + "sac_knife");
    MO (robe,  TO);
    MO (knife, TO);
    command("wield knife");
    command("wear robe");

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
      case 0 .. 5:
       npc_process_spell("slay living", vic);
       doing = 1;
      break;

      case 6 .. 25:
       npc_process_spell("cause light", vic);
       doing = 1;
      break;

      case 26 .. 39:
       npc_process_spell("cause serious", vic);
       doing = 1;
      break;

      case 40 .. 50:
       npc_process_spell("cause critic", vic);
       doing = 1;
      break;

      case 51 .. 75:
       npc_process_spell("entangle", vic);
       doing = 1;
      break;

      case 76 .. 83:
       npc_process_spell("firestorm", vic);
       doing = 1;
      break;

      default:
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

int query_chr() { return 30; }
int query_int() { return 60; }
int query_str() { return 55; }
