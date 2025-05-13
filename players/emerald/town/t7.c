inherit "/room/room";

int found;

reset(arg) {
  object flask;
  found=0;

  set_light(1);

  short_desc="A side street";

  long_desc="This street is mostly residential.  There are well-kept houses " +
            "on both sides of the street.  Children are running around and " +
            "playing games.  Some dogs wander through the street, letting " +
            "out an occasional yelp as a child steps on its tail.  The " +
            "paving cobbles below your feet are worn, but still in good " +
            "shape.\n";

  dest_dir=({"/players/emerald/town/t8","east",
             "/players/emerald/town/t6","west",
           });

  items=({"cobbles","Old paving cobbles.  One of them seems to be loose",
          "cobble","It's loose.  You might be able to lift it",
          "street","A small side street",
          "dogs","They appear to be well-fed and well taken care of",
          "children","Smaller versions of human beings",
          "houses","Comfortable-looking houses",
  });

  ::reset(arg);

}
init() {

  ::init();

  add_action("_lift","lift");

}
_lift(str) {
object flask;

  if(!id(str)) {
    write("Lift what?\n");

    return 1;
  }
  if(str=="cobble" && !found) {
    write("You find a flask.\n");
    move_object(flask=clone_object("players/emerald/quest/bflask"),
        this_object());
    found=1;
    return 1;
  }
  say(this_player()->query_name() + "lifts the " + str + " and \n"
           "finds nothing.\n");
  write("You lift the cobble and find nothing.\n");
  return 1;

}
