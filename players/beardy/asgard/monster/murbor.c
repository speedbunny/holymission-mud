inherit "obj/npc";
#include "../asgard.h"

#define potions_max 10
int num;
object potion,bag;

reset(int arg) 
{ ::reset(arg);
  if(!arg) 
  { set_name("murbor");
    set_alt_name("murbor");
    set_race("wizard");

    set_short("Murbor the Wizard");
    set_long("This is Murbor the Wizard.\n");
    set_gender(1);

    set_level(60);
    set_attacks_change(100);
    set_attacks(2);    

    set_al(-200);
    set_aggressive(1);
    add_money(4000);

    set_spell_mess1("Murbor utters the words '##-* uhJi'");
    set_spell_mess2("Murbor utters the words '##-* uhJi'.\n"+
                    "You feel very unpleasant");
    set_chance(30);
    set_spell_dam(120);

/*
    bag=clone_object("/obj/bag");
    bag->set_short("Wizard's bag");

    for(num=0;num<potions_max;num++)
    { switch(random(12))
      { case 1 : potion=clone_object("/players/beardy/walhalla/obj/str_potion"); break;
	case 2 : potion=clone_object("/players/beardy/walhalla/obj/wis_potion"); break;
	case 3 : potion=clone_object("/players/beardy/walhalla/obj/int_potion"); break;
	case 5 : potion=clone_object("/players/whisky/obj/invis_potion"); break;
	case 6 : potion=clone_object("/players/whisky/obj/haste_potion"); break;
	case 7 : potion=clone_object("/players/beardy/walhalla/obj/cure_potion"); break;
	case 8 : potion=clone_object("/players/beardy/walhalla/obj/cure_ser_potion"); break;
	case 9 : potion=clone_object("/players/beardy/walhalla/obj/heal_potion"); break;
	default : potion=clone_object("/players/beardy/walhalla/obj/cure_crit_potion"); break;
      }
     move_object(potion,bag);
    }
    move_object(bag,TO);
*/
  }
}

int attack()
{ int i,j;
  object *env;

  if(TO->query_hp()<=350)
  { tell_room(environment(TO),"Murbor fades away.\n");
    switch(random(20))
    {   case 0 : transfer(TO,ROOM + "asg001");
        case 1 : transfer(TO,ROOM + "asg011");
        case 4 : transfer(TO,ROOM + "asg024");
        case 5 : transfer(TO,ROOM + "asg007");
        case 6 : transfer(TO,ROOM + "asg004");
	case 10: transfer(TO,ROOM + "asg039");
	case 11: transfer(TO,ROOM + "asg035");
	case 12: transfer(TO,ROOM + "asg031");
	case 13: transfer(TO,ROOM + "asg029");
	case 14: transfer(TO,ROOM + "asg027");
	case 15: transfer(TO,ROOM + "asg025");
	case 2 : transfer(TO,ROOM + "shore019");
	case 7 : transfer(TO,ROOM + "start003");
	case 8 : transfer(TO,ROOM + "shore001");
	case 9 : transfer(TO,ROOM + "shore003");
	case 16: transfer(TO,ROOM + "shore041");
	case 17: transfer(TO,ROOM + "shore039");
	case 18: transfer(TO,ROOM + "shore037");
	case 19: transfer(TO,ROOM + "shore033");
    }
  }

  env=all_inventory(environment(TO));

  if(::attack() && TO->query_attack())
  { for(i=0,j=sizeof(env);i<j;i++)
    { write(env[i]->query_name());
      if(env[i]->query_player())
        switch(random(10))
        { case 0 : tell_room(environment(TO),env[i]->query_name()+" were hit by a magic missile.\n");
                   env[i]->reduce_hit_point(-random(30)-20);
                   return 1;
                   break;
          case 1 : tell_room(environment(TO),"Murbor utters some strange words and a poisonous dart hit "+env[i]->query_name()+".\n");
                   env[i]->query_attack()->reduce_hit_point(-random(40)+20);
                   env[i]>query_attack()->add_poison(random(20)+10);
                   return 1;
                   break;
/*
          case 2 : if(!present("coneofcold",all_inventory(environment(TO)))
                     tell_room(environment(TO),"Murbor summons a little cone of cold\n");
  	           return 1;
  	           break;
*/
          case 3 : tell_room(environment(TO),"Murbor chuckles and drains some of "+env[i]->query_name()+"'s energy.\n");
                   env[i]->reduce_hit_point(-random(30)-10);
		   return 1;
	  case 4 : tell_room(environment(TO),env[i]->query_name()+" got little damage by one of Murbor's spells.\n");
                   env[i]->reduce_hit_point(-random(10)-5);
                   return 1;
	  case 5 : tell_room(environment(TO),env[i]->query_name()+" got some damage by one of Murbor's spells.\n");
                   env[i]->reduce_hit_point(-random(10)-15);
                   return 1;
	  case 6 : tell_room(environment(TO),env[i]->query_name()+" got severe damage by one of Murbor's spells.\n");
 		   env[i]->reduce_hit_point(-random(15)-30);
                   return 1;
          default : if(random(20)<10)
                    { tell_room(environment(TO),"The great Murbor misspelled the magic words.\n");
                      return 1;
                    }
 		    else
			return 0;
      }
    }
  }
  return 0;
}

