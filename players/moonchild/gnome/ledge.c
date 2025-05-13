inherit "room/room";

reset(arg) {
  if(!present("crystal")) {
    object ob;
    move_object(ob=clone_object("players/moonchild/gnome/crystal"), this_object());
    ob->set_type(4);
  }
  if(arg) return;
  set_light(1);
  short_desc="Rock ledge";
  long_desc="You are high up on a rock ledge. The only way seems to be down a rocky path.\n";
  dest_dir=({ "players/moonchild/gnome/wroad3", "down" });
  property=({ "no_teleport" });
}

move(str) {
  write("You slip and slide down the path.\n");
  return ::move(str);
}
