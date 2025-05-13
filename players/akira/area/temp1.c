inherit "room/room";
reset(tick){
if(tick) return;
set_light(1);
short_desc= ("A small room in the temple");
long_desc= ("This part of the temple seems much older than the rest of "+
            "the temple. It looks like the new temple was built on the "+
            "runes of a much older temple. The walls of this room are "+
            "covered with some kind of magic runes. In the far corner of "+
            "the room is a set of stairs leading down.\n");
move_object(clone_object("/players/akira/mobs/old"), this_object());
items= ({ "runes", "They seem to glowing with some king of magic." });
dest_dir= ({ "/players/akira/area/temp", "down",
             "/players/beelzebub/guild/rooms/shrine", "west" });
}
