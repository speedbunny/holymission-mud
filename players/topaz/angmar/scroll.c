reset(arg) {
  if(arg) return;
  /* */
}
query_weight() { return 1; }
query_value() { return 40; }
short() { return "A magic scroll"; }
get() { return 1; }
long() { 
  write("According to the ancient runes this scroll can\n");
  write("revive petrified people.\n");
}

init() {
  add_action("read_scroll", "read");
}

id(str) { return str== "scroll"; }

read_scroll(str) {
  if(!id(str)) return 0;
  revive();
  return 1;
}

revive() {
  object statue;
  statue=present("stone statue", environment(this_player()));
  write("The scroll vanishes as you read it.\n");
  say("The scroll vanishes as ");
  say(this_player()->query_name(0));
  say(" reads it.\n");
  if(statue) statue->revive(0);
  else {
    write("Nothing happens.\n");
    say("Nothing happens.\n");
   
  }
  destruct(this_object());
  return 1;
}
