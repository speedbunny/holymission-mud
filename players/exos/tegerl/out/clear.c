/* Coded by Tegerl, 4.3.1995 */
/* rooms/out/clear */
/* Exos - 04-29-97 Added clone_list and replace_program */


inherit "room/room";
void reset(int arg) 
{
    if(!arg) {
	set_light(1);
	short_desc="A small clearing";
	long_desc=
	"Finally you managed to escape that forest for a while. " +
	"The forest opened to a small clearing. You can see a dirty cottage to the " +
	"west, it seems as it is inhabited. In front of the cottage you can see " +
	"a lot of barrels. \n" +
	"To the east the forest continues and to the north the path leads further to its end.\n";
	dest_dir=({
	  "players/tegerl/jabberwocky/rooms/out/path2", "south",
	  "players/tegerl/jabberwocky/rooms/out/path3", "north",
	  "players/tegerl/jabberwocky/rooms/out/cott1", "west",
	});
	items=({
	  "forest","The forest is very dark, you wonder what creatures could live in it. You decide to stay away",
	  "ground","The ground here is muddy with many footprints and trails on it",
	  "footprints","Yes, footprints, and they are human",
	  "trails","As you look at tho trails you think that maybe a carriage used this path",
	  "trail","As you look at the trail you think that maybe a carriage used this path",
	  "barrels","You can see various barrels, completed and unfinished ones",
	  "cottage","It is a small, dirty cottage. There is a sloppy sign on the wall",
	  "sign"," -----------------\n"  
	  + "|                 |\n"
	  + "|     BARRELS     |\n"
	  + "|                 |\n"
	  + " -----------------", 

	});
	smell = "The air is dry here and you smell fresh wood.";
	clone_list=({
	  1,3,"barrel","/players/tegerl/jabberwocky/obj/barrel",0,
	});
    }
    ::reset(arg);
    replace_program("room/room");
}
