#define MAX_LIST 20

inherit "obj/monster.c";
#include "/players/trout/defs.h"

int concentrating;

reset(arg) 
{
  ::reset(arg);
  if(arg)return;
	set_name("lo pan");
	set_alias("pan");
	set_alt_name("lo");
	set_number_of_arms(2);
	set_race("human");
    set_gender(1);
	set_level(35);
	set_al(-725);
    set_language_skill(2, 100);
	set_dead_ob(TO());

	change_spell("magic missle", 95, 95, 0);
	change_spell("faerie fire", 90, 95, 0);
	change_spell("lightning bolt", 85, 95, 0);
	change_spell("fire ball", 80, 95, 1);
	change_spell("fireshield", 75, 95, 1);
	change_spell("chainlightning", 70, 95, 1);
	change_spell("heal major", 50, 95, 2);
switch(RAN(2)){
	case 0:
		set_long("This is the famous immortal, Lo-pan. 2000 years ago"+
		" he angered the God of the east, Ching Dai. He appears "+
		"before you in his 'no-flesh' form. He can become intangible "+
		"at will. It would not be wise to fight this 6 foot road "+
		"block! \n");
		set_size(3);
		set_ac(55);
		set_hp(3000);
		set_wc(15);
		GP(10000);
		break;
	case 1:
		set_long("This is the famous immortal, Lo-pan. 2000 years ago"+
		" he angered the God of the east, Ching Dai. He appears "+
		"before you in his crippled human form. It would not be wise "+
		"to fight this basket case on wheels! \n");
		set_size(2);
		set_hp(2300);
		set_wc(30);
		set_ac(33);
		GP(12000);
		break;
		}
  }

int concentrate(object vic)
{
  int rnd;

  if (vic && !query_concentrating())
  {
    rnd = random(100);
    switch(rnd)
    {
	case 0..16:
       concentrating = 1;
       npc_process_spell("lightning bolt", vic);
      break;

      case 17..32:
       concentrating = 1;
       npc_process_spell("faerie fire", vic);
      break;

      case 33..48:
       concentrating = 1;
       npc_process_spell("chainlightning", vic);
      break;

      case 49..65:
       concentrating = 1;
	npc_process_spell("fireball", vic);
      break;

      case 66..84:
       concentrating = 1;
	npc_process_spell("magic missle", vic);
      break;

      case 85..99:
       concentrating = 1;
	npc_process_spell("fireshield", vic);
      break;
    }
  }
if(this_object()->query_hp()<500){
	concentrating = 1;
	npc_process_spell("heal major", TO());
	return 1;
	}
  concentrating = 0;
  return 1;
}

int query_concentrating()
{
  return concentrating;
}
monster_died(ob){
	MO(CO(YY+"/obj/key1"), TO());
	MO(CO(YY+"/obj/paper"), TO());
	return 0; }
