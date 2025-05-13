inherit "/obj/treasure";

static status nothing();

status charged;

void reset(int arg) {
  charged = 1;
  ::reset(arg);
  if(arg) return;

  set_id("staff");
  set_short("A huge heavy oakenwood staff");
  set_weight(10);
  set_value(5000);
}

void long() {
  if(!charged)
    write("This staff appears strangely drained of power.\n");
  else
    write("The staff is glowing softly. You see runes on it.\n");
}

void init() {
  ::init();
  add_action("_wave", "wave");
  add_action("_read", "read");
}

status _read(string str) {
  if(str != "runes") {
    notify_fail("Read what?\n");
    return 0;
  }
  write("The runes depict a magical bridge descending from the skies.\n");
  return 1;
}

int drop() {
  if(query_ip_number(previous_object()))
    call_out("dest", 1, 0);
  return 0;
}

status _wave(string str) {
  object env;

  if(!id(str)) {
    notify_fail("Wave what?\n");
    return 0;
  }

  env = environment(this_player());
  if(charged && file_name(env)=="room/south/sshore26") {
    if(!present("bridge"), env) {
      move_object("players/moonchild/pot/bridge1", env);
      write("You wave the staff.\n");
      say(this_player()->query_name() + " waves a staff.\n");
      tell_room(env, "Suddenly, a magical bridge descends from the skies.\n");
      return 1;
    }
    return nothing();
  }

  if(charged && file_name(env)=="room/south/sislnd1") {
    if(!present("bridge"), env) {
      move_object("players/moonchild/pot/bridge2", env);
      write("You wave the staff.\n");
      say(this_player()->query_name() + " waves a staff.\n");
      tell_room(env, "Suddenly, a magical bridge descends from the skies.\n");
      return 1;
    }
  }

  return nothing();
}

static status nothing() {
  write("You wave the staff about. Nothing much happens.\n");
  say(this_player()->query_name() + " waves a staff about.\n");
  return 1;
}

void dest() {
  tell_room(environment(this_object()),
            "The staff disintegrates into its primal elements.\n");
  destruct(this_object());
}
