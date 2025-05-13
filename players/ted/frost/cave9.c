inherit "room/room";
int cave_in, test;

reset(arg) {
  cave_in = 0;
  test = 1;
  ::reset(arg);
  if(!arg) {
    set_light(0);
    short_desc = "Dark Cave";
    long_desc =
"The cave turns north here. The floor and walls have been cut and\n"+
"shaped by tools. It is quite different than the natural cave\n"+
"you had been traveling through.\n";
    dest_dir = ({
"players/ted/frost/cave10", "north",
"players/ted/frost/cave8", "southeast"
    });
  }
}

id(str) {
  if(::id(str)) return 1;
  return (str == "rocks" || str == "pile" || str == "cave in");
}

long(str) {
  ::long(str);
  if((str == "rocks" || str == "pile" || str == "cave in") && cave_in) {
   write("This is part of the cave ceiling that has collapsed onto the floor\n");
   write("It looks quite new.......\n");
  }
 if(cave_in && !str)
   write("There is a pile of rocks blocking the north passage.\n");
}

init() {
  ::init();
  add_action("do_move"); add_verb("north");
}

do_move() {
  if(cave_in) {
    write("The cave in blocks you from going north.\n");
    say(call_other(this_player(),"query_name")+" is blocked from");
    say(" going north by the cave in.\n");
    return 1;
  }
  write("As you go north, you step on a counter balanced flagstone.\n");
  write("Suddenly part of the cave ceiling colapses. However, you\n");
  write("are quick enough to jump back to safety.\n");
  say("As "+capitalize(this_player()->query_name())+" leaves north,");
  say("they trip a hidden spring and cause a cave in!!!\n");
  cave_in = 1;
  return 1;
}
