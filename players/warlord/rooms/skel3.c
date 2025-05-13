inherit"room/room";
reset (arg) {
if (arg) return;
set_light(1);
short_desc="Skeleton hallway\n";
long_desc="The hallway is cluttered with skeletons of dead adventures. You\n"+
          "feel a strong presence near.\n";
items=({
     "skeletons","These are the skeletons of dead adventures",
     });
dest_dir=({
"players/warlord/rooms/skel1","north",
"players/warlord/rooms/slordroom","east",
"players/warlord/rooms/skel4","west",
         });
}
