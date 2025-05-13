inherit "room/room";

void reset(int arg) {
object ob;
  if(!ob =  present("labdemon",this_object())) {
    ob = clone_object("/players/uglymouth/testchar/labdemon");
    move_object(ob,this_object());
  }
  if(arg) return;

  set_light(1);
  short_desc = "Uglymouth's testlab";
  long_desc = "Uglymouth's testlab is a large cave of crude rock.\n"
    + "Everything around you is black and deformed by explosions.\n"
    + "On the floor lie the marks of what once was a mighty\n"
    + "pentagram of summoning.\n";
  dest_dir = ({
    "/players/uglymouth/workroom","out",
  });
  items = ({
    "cave","A large, gloomy cave",
    "rock","At various places the rock has been deformed weirdly",
    "floor","Among the blackened rock, lie parts of a pentagram",
    "pentagram","It must have been a mighty one, but it's destroyed now.\n"
      + "You start wondering by whom... and if it still around..",
  });
  property = ({ "has_fire", "no_teleport" });
  smell = "The smell of unknown materials burning overwhelms you.\n";
}
