inherit "/obj/board";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_file("players/llort/arch_guild/proboard");
  set_name("pro");
  set_short("The pro wizzards board");
}

init() {
  if(!this_player()->query_archwiz()) return;
  ::init(); 
  add_action("cn","pronote");
  add_action("cr","proread");
  add_action("cre","proremove");
}

cn(arg) { return ::new_msg(arg); }
cr(arg) { return ::read_msg(arg); }
cre(arg) { return ::remove_msg(arg); }
