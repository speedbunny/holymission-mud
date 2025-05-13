inherit "room/room";

reset(arg) {
  int i;
  if (!present("chasme")) {
    for (i=0;i<4;i++)
move_object(clone_object("/players/jewel/quest/hills/chasme"),this_object());
  }
  if (arg) return;
set_light(0);
short_desc="A cave with medium demons";
  long_desc=
("This cave is filled with demons, they hate you.\n");
  items=({ 
"cave","A cave full of demons"
        });
  dest_dir=({
    "/players/jewel/quest/hills/cave10","west",
"/players/jewel/quest/hills/cave8","up"
  });
}


 

