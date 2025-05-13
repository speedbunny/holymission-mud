#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();


string shortname, the_file_name;
object the_env;

int flights;


reset(arg) {
  if(arg) return;
  set_heart_beat(0);
  shortname="Fairy dust";
}

heart_beat() {
    if(!living(environment())) {
      write("The fairy dust disappears.\n");
      set_heart_beat(0);
      destruct(this_object());
    }
}

query_weight() { return 0; }
query_value() { return 0; }

short() {
  return shortname;
}

get() {
  if(!this_player()->query_npc(0)) {
    write("You feel the dust drop all over you.\n");

    set_heart_beat(1);
  }
  return 1;
}

long() {
  write("The fairy dust glitters in yellow and gold reminding you of\n");
  write("the many happy thoughts you once had.\n");
}

init() {
  add_action("quit", "quit");
  add_action("think", "think");
  flights=5;
}

extra_reset() {
  flights=flights-1;
  if (flights == -1) {
    write("The fairy powder disappears...\n");
    set_heart_beat(0);
    destruct(this_object());
  }
}



id(str) { return str == "dust"; }

destring() {
    write("The dust glitters as it falls and disappears.\n");
    say("The dust glitters as it falls and disappears.\n");
    set_heart_beat(0);
    destruct(this_object());
}

drop(silent) {
  call_out("destring", 4);
  return 1;
}

quit() {
  write("The fairy powder glitters as it falls and disappears.\n");
  say("The fairy powder glitters as it falls and disappers.\n");
  set_heart_beat(0);
  destruct(this_object());
  this_player()->quit(0);
}

id2(str) {
    return str == "happy";
}

think(str) {
     if (!id2(str))
       return 0;
     if (environment(this_object()) != this_player()) return 0;
     the_env = environment(this_player());
     the_file_name = file_name(the_env);
     if (the_file_name == "players/kantele/snake_pit") {
     write("You fly out of the snakepit!\n");
     this_player()->move_player("flying upward#players/kantele/stairway_top");
        return 1; }
     if (the_file_name == "players/quantos/under/sinkhole") {
     write("You fly out of the desertpit!\n");
       this_player()->move_player("flying upward#players/quantos/plateau/fsplat");
        return 1; }
     write("You circle a few times in the air and land.\n");
     say(call_other(this_player(), "query_name") + " flies a few circles.\n");
     flights=flights-1;
     if (flights == -1) {
       write("The fairy dust disappears...\n");
       set_heart_beat(0);
       destruct (this_object());
     }
     return 1;
}

