#define TP	this_player()
munch() {
  object ob;
  int heal;

  if(TP->query_ghost()) {
    write("You wouldn't even be able to lick some blood from the corpse.\n");
  }

  ob = present("corpse",environment(TP));
  if(!ob) ob=present("corpse",TP);
  if(!ob) {
    write("Which corpse do you want to eat ?\n");
    return 1;
  }
  heal = random( 2 * (ob->query_weight() + TP->query_level()) + 8);
  if(heal==0) heal=1;
  if(TP->eat_food(heal/4)) {
     TP->heal_self( 10 + heal/2);
     write("You munch the corpse.\n");
     say(TP->query_name() + " munches the corpse.\n");
     destruct(ob);
  }
  return 1;
}
