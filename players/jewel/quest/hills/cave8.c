inherit "room/room";

reset(arg) {
  int i;
  if (!present("babau")) {
    for (i=0;i<6;i++)
move_object(clone_object("/players/jewel/quest/hills/babau"),this_object());
  }
  if (arg) return;
set_light(0);
  short_desc="A cave with small demons";
  long_desc=
("This cave is filled with small demons, they dislike you.\n");
  items=({ 
"cave","A cave full of small demons"
        });
  dest_dir=({
    "/players/jewel/quest/hills/cave7","west",
"/players/jewel/quest/hills/cave9","down"
  });
}


 

