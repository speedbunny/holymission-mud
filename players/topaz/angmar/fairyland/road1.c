reset(arg) {
  if(!arg) set_light(1);
}

init() {
  add_action("open", "open");
  add_action("close", "close");
  add_action("enter", "enter");
  add_action("north", "north");
  add_action("south", "south");
}

short() { return "You are standing on a road in fairyland"; }
long(str) {
  if(str=="door" || str=="wardrobe") {
    if(!call_other("players/topaz/angmar/wardrobe2", "query_door", 0))
        write("It is open.\n");
    else
        write("It is closed.\n");
    return 1;
  }
  write("You are standing on a road in fairyland. The road\n");
  write("continues north. A wardrobe floating in the air can\n");
  write("be dimly seen.\n");
  write("There are two obvious exits, north and south.\n");
}

id(str) {
  return str=="door" || str=="wardrobe";
}

open(str) {
  if(str!="door"&&str!="wardrobe") return 0;
  call_other("players/topaz/angmar/wardrobe2", "open_door", "door");
  return 1;
}
close(str) {
  if(str!="door"&&str!="wardrobe") return 0;
  call_other("players/topaz/angmar/wardrobe2", "close_door", "door");
  return 1;
}
enter(str) {
  if(str!="door"&&str!="wardrobe") return 0;
  if(call_other("players/topaz/angmar/wardrobe2", "query_door", 0)) {
    write("The door is closed.\n");
    return 1;
  }
  this_player()->move_player("into wardrobe", "players/topaz/angmar/wardrobe2");
  return 1;
}

north() {
  this_player()->move_player("north", "players/topaz/angmar/fairyland/road2");
  return 1;
}

south() {
  this_player()->move_player("south", "players/topaz/angmar/fairyland/edge1");
  return 1;
}
