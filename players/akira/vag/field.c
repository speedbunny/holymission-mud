inherit "room/room";
reset(tick){
if(tick) return;
set_light(1);
short_desc=("In a large field");
long_desc=("Looking around you can't seem to tell were you are. This\n"+
         "world has two suns, and the sky is a blood red. Something\n"+
         "about this place just does not feel right.\n");
items= ({ "suns", "There are two bright yellow suns.",
          "sky", "It is blood red." });
dest_dir= ({ "players/akira/vag/field1", "north",
                 });
property= ({"vag_quest", "no_teleport"});
}
