inherit "room/room";

reset(arg) {
  int i;
  if (!present("manes demon")) {
    for (i=0;i<8;i++)
move_object(clone_object("/players/jewel/quest/hills/manes"),this_object());
  }
  if (arg) return;
set_light(0);
  short_desc="A cave with tiny demons";
  long_desc=
("This cave is filled with tiny demons, they attack you with their claws.\n");
  items=({ 
"cave","A cave full of tiny demons"
        });
  dest_dir=({
    "/players/jewel/quest/hills/cave5","west",
"/players/jewel/quest/hills/cave7","down"
  });
}


 

