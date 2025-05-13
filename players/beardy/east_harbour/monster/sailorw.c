inherit "obj/npc";
#include "/players/beardy/east_harbour/monster/buy.h"

reset(int arg) 
{ ::reset(arg);
  if(!arg) 
  { set_name("old sailor");
    set_alt_name("sailor");
    set_race("human");

    set_short("old sailor");
    set_long("It is an old sailor, who tries to keep up with selling tickets.\n" +
             "As you see his old worn out shoes and fell the wind blowing all\n" +
             "around this poor figure, you fell very sad now.\n");
    set_gender(1);

    set_level(4);
    set_hp(10000);

   heart_beat(1);
    set_al(100);
    add_money(40);
  }
}

attack() 
{ if(attacker_ob) query_ghost();
}

int query_ghost() {
  object *o;
  int i;

  tell_room(environment(),"The sailor lies down kissing you feet and you can't help stopping the fight.\n");
  o=all_inventory(environment());
  for(i=0;i<sizeof(o);i++) {
    o[i]->stop_fight();
    o[i]->stop_fight();
    o[i]->stop_hunter(1);
  }
  return 1;
}

void init()
{ ::init();
  add_action("mybuy","buy");
}

void heart_beat()
{ switch(random(20))
  { case 0 : command("north",this_object()); break;
    case 1 : command("south",this_object()); break;
    case 2 : command("east",this_object()); break;
    case 3 : command("west",this_object()); break;
    default : if(random(5)==0)
              say("The sailor shouts:\n"+
		  "  Who wanna buy a ticket?\n"+
		  "Use 'buy ticket' to get one.\n");
              break;
  }
}
