inherit"room/room";
object ob;
int i;
reset(arg) {
    ::reset(arg);
    if (!ob) {
	for( i=0; i < 10; i++) {
	    move_object("players/warlord/trans/broc",this_object());
	}
    }
    if(arg) return;
    set_light(1);
    short_desc = "[Warlord's Castle] Dragon Port 1";
    long_desc="This is one of the many ports of Dragon Airways. If you wait here long \n"+
    "enough a Dragon will be by to pick you up.\n";
    dest_dir=({
      "/players/warlord/road1","down",
    });
    "players/mangla/std/dragair"->short();
}
