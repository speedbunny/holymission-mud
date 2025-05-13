inherit "room/room";
int found;

init() {
  ::init();
 add_action("do_enter"); add_verb("enter");
 add_action("do_enter"); add_verb("north");
 add_action("search"); add_verb("search");
}

id(str) {
  if(::id(str)) return 1;
  return str == "cave";
}

reset(arg) {
  found = 0;
  ::reset(arg);
  if(!arg) {
    set_light(1);
    short_desc = "Base of Mountain";
    long_desc =
"You are standing at the base of a huge snow covered mountain.\n"+
"It's sides are to steep and slippery to climb. You notice\n"+
"something unusual about the mountain side\n";
    dest_dir = ({
"players/ted/cold/frost_giant", "south"
    });
    items = ({
"mountain side","You sense something is not quite as it seems here",
"mountain","You sense something is not quite as it seems here",
    });
  }
}

do_enter(str) {
  if(found) {
    write("You shove ice and snow out of your way and enter the cave.\n");
    call_other(this_player(),"move_player","into cave#players/ted/frost/cave1");
    return 1;
  }
}

long(str) {
  ::long(str);
  if(found && str == "cave") {
    write("This dark opening seems to lead deeper into the montain\n");
    write("It looks like you could enter the cave if you wished\n");
  }
  if(found && !str) {
    write("There is a cave half hiden in the snow covered mountain side\n");
  }
}

search(str) {
  if(found) {
    write("You don't find anything new.\n");
    say(capitalize(this_player()->query_name())+" searches.\n");
    return 1;
  }
  if(random(6) >= 1) {
    found = 1;
    write("You find a cave entrance hidden in the snow!\n");
    say(capitalize(this_player()->query_name())+" finds a cave entrace.\n");
  } else
    write("You don't find anything of intererest.\n");
  return 1;
}
