inherit "/obj/board";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_file("players/llort/arch_guild/lvlboard");
  set_name("level");
  set_short("The promoted wizzards level board");
}

init() {
  if(!this_player()->query_archwiz()) return;
  ::init();
  add_action("ln","levelnote");
  add_action("lr","levelread");
  add_action("lre","levelremove");
}

ln(arg) { return ::new_msg(arg); }
lr(arg) { return ::read_msg(arg); }
lre(arg) { return ::remove_msg(arg); }
