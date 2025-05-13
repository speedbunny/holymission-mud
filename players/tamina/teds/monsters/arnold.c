#define MAX_LIST 20
#define ENV environment()

inherit "/obj/monster.c";
#include "/obj/monsoul.c" 

object last;
int concentrating;

void reset(int arg) 
{
  object ob;
  ::reset(arg);
  if(!arg) 
  {
    set_name("Arnold, the Artificer");
    set_alias("arnold");
    set_short("Arnold, the Artificer");
    set_race("human");
    set_gender(1);
    set_long(
  "Arnold is a small man, who works hard to make superb wands.\n"+
  "He is the younger brother of Wuntvor, the mighty Archmage,\n"+
  "and looks just as adept in the magical arts as his brother.\n");
    set_level(60);
    set_hp(9000);
    set_wc(5);
    set_ac(25);
    set_language_skill(0,100);
    set_language_skill(2,100);
    set_speaks_in(0);

    change_spell("fireball", 75, 95, 2);
    change_spell("lightning bolt", 85, 95, 1);
    change_spell("magic missile", 95, 95, 0);
    change_spell("chainlightning", 70, 80, 2);
    change_spell("fear", 95, 95, 1);

    ob = clone_object("/obj/shadows/fireshield_shad");
    ob->start_shadow(this_object(), 0, 3);

    ob = clone_object("/obj/shadows/true_sight_shad");
    ob->start_shadow(this_object(), 0);

    ob = clone_object("/players/llort/animals_stuff/phylactery");
    move_object(ob,this_object());
    init_command("wear phylactery");
  }
  sreset(arg);
}

query_no_summon() { return 1; }

no_clean_up() { return 1; }

int concentrate( object vic )
{
  int rnd;

  if (vic && !query_concentrating() ) 
  {
    rnd = random(100);
    if (rnd < 5)
    {
      npc_process_spell("chainlightning", vic);
      concentrating = 1; 
    }
   else if (rnd < 25)
    {
      npc_process_spell("magic missile", vic);
      concentrating = 1; 
    }
    else if (rnd < 50)
    {
      npc_process_spell("lightning bolt", vic);
      concentrating = 1; 
    }
    else if (rnd < 75)
    {
      npc_process_spell("fireball", vic);
      concentrating = 1; 
    }
    else
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

int query_int() {  return 90;  }
int query_wis() {  return 75;  }
int query_str() {  return 45;  }

