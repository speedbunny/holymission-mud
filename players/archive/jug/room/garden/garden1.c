inherit "room/room";
 
void reset(int arg) {
  set_light(1);
  short_desc = "Entrance to the inner garden";
  long_desc =
    "You have arrived in the royal garden of the WORLDS OF WONDER. "+
    "The beauty of this place overwhelms you. Flowers in different "+
    "colours, shapes and sizes grow here, including many unknown "+
    "kinds. The gardener does really good work here. The golden hedge "+
    "continues to the west.\n";
 
  items = ({
    "flowers", "As you look around you notice roses, daisies, baby "+
               "breaths, lillies, and much, much more",
    "hedge","The golden hedge keeps out the wild animals so they "+
            "won't eat the flowers",
  });
 
  dest_dir = ({
      "/players/jug/room/garden/gar_cor3", "north",
      "/players/jug/room/garden/garden2", "south",
      "/players/jug/room/garden/garden4", "east",
  });
 
  clone_list = ({
    1,2,"rabbit","/players/jug/monster/rabbit",0,
  });
 
  ::reset(arg);
  replace_program("/room/room");
}
