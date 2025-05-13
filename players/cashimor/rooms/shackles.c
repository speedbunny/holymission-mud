/* Shackles, version 2.00 */
/* BUGS: Teleporting still possible... */

inherit "room/room";

string bound;
reset(arg) {
  if (!arg) {
    set_light(1);
    short_desc="The Ring of Sacrifice";
    long_desc=
      "You're near a great stone covered with snow. There is sea to all\n"
    + "directions except for the east, where a long path of stones\n"
    + "coming above the sea lead to a land of mountains.\n";
    items=( { "stone",
      "There are two great iron rings in it, an armlength apart...\n",
              "sea",
      "It looks cold and lonely, with mist above it.\n",
              "snow",
      "You think even you might consider freezing when immobile...\n",
              "path",
      "The path looks very slippery, but it is walkable.\n",
              "mountains",
      "They look very high, even from this distance.\n" });
    dest_dir=( { "players/cashimor/rooms/rockpath","east" });
    bound = "no body";
  }
}

init() {
  ::init();
  add_action ("bind","bind");
  add_action ("bind","chain");
  add_action ("east","east");
  add_action ("free","free");
  add_action ("free","release");
  add_action ("quit","quit");
}

quit() {
  if (bound == this_player()->query_real_name()) {
    write("You can't quit since you're bound with chains...\n");
    say (this_player()->query_real_name()+" tries to quit,\n"
       + "but fails, being bound to the rock...\n");
    return 1;
  }
  this_player()->quit(0);
}
 
bind(str) {
  object who;
  if (!str) return 0;
  who = present(lower_case(str), environment(this_player()));
  if (!who || !living(who))
    return 0;
  if (!(bound == "no body")) {
    write("Someone is already chained to the stone!\n");
    return 1;
  }
  if (!present ("chain",this_player())) {
    write("You don't have a chain to bind " + call_other(who,"query_name")
        + ".\n");
    return 1;
  }
  if (who->query_name() == this_player()->query_name()) {
    write("You can't bind yourself to the rock!\n");
  }
  bound = who->query_real_name();
  write ("You bind "+who->query_name()+" to the rock.\n");
  say (who->query_name()+" is bound to the rock by "+this_player()->
    query_name()+".\n");
  destruct(present("chain",this_player()));
  return 1;
}

east() {
  if (bound == this_player()->query_real_name()) {
    write("You try to break free from the chain binding you to the rock,\n"
        + "but you are unable to do it...\n");
    say(this_player()->query_name()+" is struggling with the chains.\n");
    return 1;
  }
  this_player()->move_player("east#players/cashimor/rooms/rockpath");
  return 1;
}

free(str) {
  object who,chain;
  if (!str) return 0;
  who = present(lower_case(str), environment(this_player()));
  if (!who || !living(who))
    return 0;
  if (bound == "no body") {
    write("There's nobody here to free!\n");
    return 1;
  }
  if (bound == this_player()->query_real_name()) {
    say(this_player()->query_name()+ "tries to find a way to get loose,\n"
      + "but doesn't succeed.\n");
    write("You fail. Maybe you should ask somebody else to do it...\n");
    return 1;
  }
  bound = "no body";
  say (this_player()->query_name()+" frees "+who->query_name()
     + " from the rock...\n");
     write ("You free the poor person from the chains...\n");
  chain = clone_object("/players/cashimor/objects/chain");
  move_object(chain,this_object());
  return 1;
}

realm() { return "NT"; }
