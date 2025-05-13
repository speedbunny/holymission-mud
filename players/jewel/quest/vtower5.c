inherit "room/room";

reset(arg) {
  int i;
  if (!present("vampire lady")) {
    for (i=0;i<3;i++)
      move_object(clone_object("/players/jewel/quest/vampire6"),this_object());
  }
  if (arg) return;
  set_light(1);
  short_desc="On the top of the vampire tower";
  long_desc=
    ("You are standing on the top of the vampire tower, in a far distance\n"+
     "to the north you can see a castle. There are some unfriendly vampires\n"+
     "here\n");
  items=({ 
        "castle","The Overlords castle, it looks like a pile of huge skulls"
        });
  dest_dir=({
    "/players/jewel/quest/vtower4","down"
  });
}


 

