reset(arg) {
  object notebook;
  object statue;
  if(!arg) set_light(1);

  notebook=present("notebook");
  if(notebook) destruct(notebook);
  notebook=move_object(clone_object("players/topaz/angmar/notebook"), this_object());

  if(!present("stone statue")&&!present("elfwarrior")) {
    statue=move_object(clone_object("players/topaz/angmar/statue"), this_object());
  }
}

init() {
  add_action("open", "open");
  add_action("close", "close");
  add_action("enter", "enter");
  add_action("east", "east");
}

short() { return "The library. There is a magic wardrobe here"; }
long(str) {
  if(str=="door" || str=="wardrobe") {
    if(!call_other("players/topaz/angmar/wardrobe1", "query_door", 0)) {
        write("It can take you to fairyland.\n");
        write("The door is open.\n");
        }
    else {
        write("It can take you to fairyland.\n");
        write("The door is closed.\n");
    }
    return 1;
  }
  write("This is the library. Along the walls are shelves full of books,\n");
  write("papers and magic scrolls.\n");
  write("There is a magic wardrobe in a corner.\n");
}

id(str) {
  return str=="door" || str=="wardrobe";
}

east() {
  this_player()->move_player("east", "players/topaz/angmar/magroom");
  return 1;
}

open(str) {
  if(str!="door"&&str!="wardrobe") return 0;
  call_other("players/topaz/angmar/wardrobe1", "open_door", "door");
  return 1;
}
close(str) {
  if(str!="door"&&str!="wardrobe") return 0;
  call_other("players/topaz/angmar/wardrobe1", "close_door", "door");
  return 1;
}
enter(str) {
  if(str!="door"&&str!="wardrobe") return 0;
  if(call_other("players/topaz/angmar/wardrobe1", "query_door", 0)) {
    write("The door is closed.\n");
    return 1;
  }
  this_player()->move_player(
        "into wardrobe#players/topaz/angmar/wardrobe1");
  return 1;
}
