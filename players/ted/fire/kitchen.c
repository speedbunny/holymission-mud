inherit "room/room";

object cook;

reset(arg){
  ::reset(arg);
  if(!arg) {
    set_light(1);
    short_desc = "Small Kitchen";
    long_desc =
"This is a small kitchen. Pots and pans are stacked on shelves\n"+
"while herbs and spices sit in small glass containers on the\n"+
"counter. An empty bottle sits next to them on the counter.\n";
    dest_dir = ({
"players/ted/fire/whall2", "south"
    });
    items = ({
"glass", "This bottle used to contain some type of alcohol.......",
"bottle", "This bottle used to contain some type of alcohol......."
    });
  }
  if(!present("fire giant cook")) {
    cook = clone_object("players/ted/monsters/fire_giant_cook");
    move_object(cook, this_object());
  }
}
