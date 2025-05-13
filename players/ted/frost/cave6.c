inherit "room/room";
int trap, found;

reset(arg) {
  trap = 1;
  found = 0;
  ::reset(arg);
  if(!arg) {
    set_light(0);
    short_desc = "Dark Cave";
    long_desc =
"The cave turns north here. It is also getting more humid.\n";
    dest_dir = ({
"players/ted/frost/cave7", "north",
"players/ted/frost/cave5", "east"
    });
  }
}

long(str) {
  ::long(str);
  if(str == "trap" && found && trap) {
    write("It looks like some kind of dart trap.\n");
    write("Maybe you could disarm it?\n");
  }
  if(str == "trap" && !trap)
    write("A disarmed trap.\n");
  if(!str && found && trap) 
    write("There is a trap here.\n");
  if(!str && !trap)
    write("There is a disarmed trap here.\n");
}

id(str) {
 if(::id(str)) return 1;
 if(found)
   return str == "trap";
}

init() {
  ::init();
  add_action("north");  add_verb("north");
  add_action("search"); add_verb("search");
  add_action("disarm"); add_verb("disarm");
}

north() {
 if(random(10) <= 7 && trap) {
  write("As you travel through the northern passage you step on ");
  write("something!!\nSuddenly you are hit by a small dart!\n");
  call_other(this_player(),"reduce_hit_point", random(20));
 }
}

search(str) {
  if(random(6) >= 3 && !found) {
    write("You find a trap!\n");
    say(capitalize(this_player()->query_name())+" finds a trap!\n");
    found = 1;
    return 1;
  }
  if(!trap) {
    write("You find a disarmed trap.\n");
    return 1;
  }
  if(found) {
    write("Besides the trap, there is nothing of interest.\n");
    return 1;
  }
  write("You don't find anything of interest.\n");
  say(capitalize(this_player()->query_name())+" searches.\n");
  return 1;
}

disarm(str) {
  if(trap && found) {
    if(this_player()->query_dex() >= random(20)) {
      write("You disarm the trap!\n");
      say(capitalize(this_player()->query_name())+" disarms a trap.\n");
      trap = 0;
      return 1;
    }
    write("You fail to disarm the trap and accidently set it off!!!\n");
    this_player()->hit_player(random(20));
    write("You are hit by a small dart!\n");
    say(capitalize(this_player()->query_name())+" is hit by a small dart!\n");
    return 1;
  }
  if(!trap && found) {
    write("The trap has already been disarmed.\n");
    return 1;
  }
}
