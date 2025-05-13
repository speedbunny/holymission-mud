inherit "/obj/monster";

void reset(int arg)
 {

 ::reset(arg);
if (arg) return;
set_name("bunny");
set_race("animal");
set_short("A little bunny");
set_long("A little bunny. It's eating grass and loking around.\n");
set_level(2);
set_wc(3);
set_ac(1);
set_al(20);
set_size(1);          
}

string query_plural(){
  return "bunnies";
}
