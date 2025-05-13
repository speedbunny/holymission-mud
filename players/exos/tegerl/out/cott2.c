

/* Coded by Tegerl, 7.3.1995 */
/* rooms/out/cott2 */


inherit "room/room";
#define PATH "players/tegerl/jabberwocky/"

void reset(int arg) 
{
    if (!arg)
    {
	clone_list=({1,1,"barrelmaker",PATH+"monsters/bmaker",0,
	  2,4,"old woman",PATH+"monsters/owoman",0,
	  3,1,"preacher",PATH+"monsters/preacher",0});

	set_light(1);
	short_desc="A bedroom in cottage";

	long_desc=
	"This is the bedroom of the cottage. " +
	"The room is only furnished with a bed. " +
	"There are many people and they are all sad.\n";

	dest_dir=({
	  "players/tegerl/jabberwocky/rooms/out/cott1", "northeast",
	});

	items=({
	  "cottage","It is a very small and dirty cottage",
	  "bedroom","It is the bedroom of a very poor man, there is only a bed in it",
	  "bed","It is a simple wooden bed",  
	});

	smell = "You smell the odem of death.";

    }
    ::reset(arg);
    replace_program("room/room");
}

