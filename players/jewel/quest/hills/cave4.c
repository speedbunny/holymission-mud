inherit "room/room";

reset(arg) {
  int i;
  if (!present("grazzt")) {
move_object(clone_object("/players/jewel/quest/hills/grazzt"),this_object());
  }
  if (arg) return;
  set_light(0);
short_desc="The living room of Grazzt the Tana-Ri Lord";
  long_desc=
("You are in the living room of Grazzt the Tana-Ri Lord. Better run you fool.\n");
  items=({ 
"living room","The Demonlords living room"
        });
  dest_dir=({
"/players/jewel/quest/hills/cave3","west"
  });
}


 

