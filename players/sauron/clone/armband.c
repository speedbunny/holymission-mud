inherit "/obj/armour";

int get() {
  return present("armband",this_player())?0:1;
}

int drop(int silent) {
  return query_verb()=="quit";
}

string query_auto_load() {
  return "/players/sauron/clone/armband:";
}

void reset(int arg) {
  ::reset(arg);
  if(!arg) {
    set_name("black armband");
    set_alias("armband");
   set_short("A black armband");
    set_long("A black armband, in memorium of Diana, Princess of Wales.\n");
    set_weight(0);
    set_ac(0);
  }
}
