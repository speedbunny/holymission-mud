inherit "/obj/monster";

#include "/players/skeeve/area.h"

string function, type, match;

reset(arg) {
  ::reset(arg);
  if (!arg) {
    set_name("monster");
    set_long("A tiny monster from the forest of druid Lakmir.\n");
    set_level(3);
    set_sp(0);
    set_ac(1);
    set_wc(1);
    set_gender(1+random(2));
    set_aggressive(0);
    set_whimpy(25);
    set_move_at_reset();
    set_dead_ob(this_object());
  }
  if (!function) {
    setup_arrays();
    set_match(this_object(), function, type, match);
  }
}

setup_arrays() {
  function = allocate(1);
  type = allocate(1);
  match = allocate(1);
  function[0] = "handle_arrive"; type[0] = "arrives"; match[0] = "";
} /* setup_arrays */

handle_arrive(arg) {
  string who,x;
  object player;
   
  if ( !arg ) return;
  sscanf(arg,"%s arrives%s",who,x);
  if ( (player=find_player(lower_case(who)))
       /* don't run away if player is a wizard */
     &&(!player->query_immortal())
       /* run away if player is to strong! */
     &&((query_level()+random(6)+random(6)) < (player->query_level())) 
       /* change to run away! */
       /* if wimpy = 0 then never run away! */
       /* if hp < wimpy then always run away */
     &&(random(query_hp())<query_wimpy()) 
     )
     random_move();
}

query_stay_garden() { return 1; }  

monster_died(ob) {
  object fur;
  fur = clone_object(ARMOURS+"fur");
  fur->set_value(5 + ob->query_size() * random (4));
  fur->set_size(ob->query_size());
  fur->set_short("A " + name + " fur");
  fur->set_long("It's a fine "+ name +" fur.\n");
  fur->set_alias( name +" fur");
  move_object(fur,this_object());
  return 0;
}

config(version){
  string *str;
  int which,ints;
  str = ({"row","rabbit","fox","wolf"});

  which = (stringp(version))? member_array(version,str) : version;
  if (which < 1) switch(random(9)) {
    case 0..2: which = 0; break;
    case 3..5: which = 1; break;
    case 6..7: which = 2; break;
    case 8: which = 3;
  };
  set_name (str[which]);

  str =({"A row","A rabbit","A smart red tailed fox","A wolf"});
  set_short(str[which]);
  
  str =({"This row is looking at you with big brown eyes.\n",
    "This rabbit is looking around for fresh vegetable to eat.\n",
    "It's looking very hungry. Maybe he wants to eat you?\n",
    "You see a wolf hungrily staring at you.\n"});
  set_long(str[which]);
  
  str = ({"mammal","mammal","animal","animal"});
  set_race(str[which]);
  
  ints = ({3,2,4,6});
  set_level(ints[which]);

  ints = ({7,6,8,10});
  set_wc(ints[which]);
  
  ints = ({2,1,2,2});
  set_ac(ints[which]);
  
  ints = ({25,-25,-50,-100});
  set_al(ints[which]);
   
  ints = ({2,0,0,1});  /* 0 means random */
  if (ints[which]) set_gender(ints[which]);
  
  ints = ({3,1,2,3});
  set_size(ints[which]);
  
  switch (which) {
    case 2: set_aggressive(random(2)); 
            load_a_chat(20,({ "Grrrrrrrrrr\n" }));
    break;
    case 3: set_aggressive(1); 
            set_whimpy(-1);
            load_a_chat(20,({ "Grrrrrrrrrr\n" }));
    break;
    default:;
  }
  set_alias("gmonster");
  return this_object();
}
