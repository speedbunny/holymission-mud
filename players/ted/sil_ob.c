inherit "obj/treasure";
inherit "players/ted/silence";

reset(arg) {
  if(arg) return;
  set_id("silence_ob");
}

init() {
  ::init();
  add_action("new_stuff"); add_verb("gg");
}

new_stuff(str) {
  ::guild_tell(str);
  return 1;
}
