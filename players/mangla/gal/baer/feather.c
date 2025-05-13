inherit "obj/treasure";

reset(arg) {
  if(arg) return;
  set_id("pigeon feather");
  set_alias("feather");
  set_weight(1);
  set_value(8);
  set_short("A pigeon feather");
  set_long("A pigeon feather. You can tickle people with it, even if\n"
	+ "they aren't in the same room as you! Use \"tickle <name>\".\n");
}

init() { ::init(); add_action("tickle", "tickle"); }

tickle(str) {
  object victim;
  victim=find_living(str);
  if(!victim) return write("There is no " + capitalize(str) + " on the game!\n");
  write("You tickle " + capitalize(str) + " mercilessly!\n");
  say(this_player()->query_name() + " tickles " + capitalize(str) +
	" mercilessly!\n",victim);
  tell_object(victim,this_player()->query_name() + " tickles you mercilessly!\n");
  if(random(2)) command("giggle",victim);
  else command("laugh",victim);
  return 1;
}
