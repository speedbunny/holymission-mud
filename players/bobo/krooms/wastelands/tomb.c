inherit "room/room";
 
reset(arg) {
  if (arg) return;
  set_light(1);
  short_desc="A great hall";
  long_desc="You're standing in a great which seems to be the burial place of a .\n"+
   "highlevel person. The room is strangly lit. In the middle of the room stands a\n"+
   "coffin on a podest. Beside this coffin nothing else is in the room\n";

  dest_dir=({
	"players/bobo/krooms/wastelands/grave_entr","south",
   });

   items=({
    "coffin","It's a coffin made of the finest wood and some strange figures are                         attached",
    "figures","These figures are called Cherubim, they look like eagles with human heads",
    "podest","It's made of one huge block of white marmor",
   });

   move_object(clone_object("players/bobo/kobj/coffin"),this_object());
}
 
