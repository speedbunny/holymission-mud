inherit "obj/thing";

reset(arg) {
  ::reset(arg);
  if(!arg) {
    set_name("breath_of_air");
    set_alias("allows_breathing");
    set_short(0);
    set_can_get(1);
    set_weight(0);
    set_value(0);
  }
}

drop() {
  return 1;
}

init() {
  ::init();
  call_out("no_air_left",30);
}

no_air_left() {
  if(environment(this_player())->query_danger()) {
    write("You run out of air!\n");
  }
  call_out("destruct_me",1);
}

destruct_me() {
object room;

  room=environment(this_player());
  set_alias(0);
  if(room->query_env_name()=="water") room->drown_player();
  destruct(this_object());
}

