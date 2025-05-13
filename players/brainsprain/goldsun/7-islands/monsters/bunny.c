inherit "/obj/monster";

void reset(int arg)
 {

 ::reset(arg);
if (arg) return;
set_name("bunny");
set_race("animal");
set_short("A little bunny");
set_long(
"A little white bunny hops about in this area.  Its nose wriggles up and "+
"down as it sniffs the air for foxes. It's eating grass and looking around.  "+
"One of its ears has a small tear on it a drying scab covers the fresh wound.\n");
set_level(2);
set_wc(3);
set_ac(1);
set_al(20);
set_size(1);          
}

string query_plural(){
  return "bunnies";
}
