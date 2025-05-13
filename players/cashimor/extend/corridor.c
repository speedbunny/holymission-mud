/* CORRIDOR.C - Programmed by Ethereal Cashimor */
/* 090693: Ethereal Cashimor: kitchen added. */

inherit "room/room";

reset(arg) {
  ::reset(arg);
  if(!arg) {
    short_desc="Corridor";
    long_desc="You are standing in the corridor of a house. Tapestries cover "
            + "the wall and the floor. The temperature is pleasant here. "
            + "Light streams in from a great window above the door. There are "
            + "stairs leading up and down.\n";
    smell="There is a faint tinge of the sea here.";
    items=({"corridor","It is very inviting",
            "tapestries","There are lots of fairies painted on them",
            "wall","There are lots of green and blue tapestries on it",
            "floor","A brown tapestry forms the floor",
            "window","Light streams in through it",
            "light","It's sunlight",
            "stairs","Made of wood, but still very sturdy"});
    set_light(1);
    dest_dir=({"players/cashimor/extend/cashroom","east",
               "players/cashimor/extend/floor","up",
               "players/cashimor/extend/kitchen","south",
               "players/cashimor/extend/cellar","down"});
  }
}

door_knock() {
  tell_room(this_object(),"Someone knocks loudly on the door.\n");
  "players/cashimor/extend/cashroom"->door_knock();
  "players/cashimor/extend/floor"->door_knock();
  "players/cashimor/extend/kitchen"->door_knock();
  "players/cashimor/extend/cellar"->door_knock();
}
