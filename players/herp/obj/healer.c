/* 940414 mud@alijku05.edvz.uni-linz.ac.at Herbert Rosmanith */

/* Be nice to players */

id(str) { return str=="healing wand" || str=="healer"; }

get() { return 1; }

short() { return "A wand of healing"; }

long() { write( "This is the wand Herp created to save the players\n" +
		"of The Holy Mission from being captured by the evil.\n");
}

init() { add_action("heal","heal"); }

heal(str) {
object *u,env;
int i;

  if (str!="all") return;
  if (!this_player()->query_wizard()) {
     write("You are too inexperienced to use this wand.\n");
     return 1;
  }

  u=users();
  env=environment(this_player());
  for (i=0;i<sizeof(u);i++)
    if (!u[i]->query_wizard()) {
       this_player()->move_player("X",environment(u[i]));
       u[i]->heal_self(100000);
       say("You are healed by "+capitalize(this_player()->query_name())+".\n");
    }
  this_player()->move_player("X",env);
  return 1;
}


  
