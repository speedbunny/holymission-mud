#define NAME "calvyn"
inherit "room/room";
#define CNAME   capitalize(NAME)

reset(arg) {
    if(!arg) {
	set_light(1);

	short_desc = "Room10. (n,sw)";

	long_desc=
	
	"The ground here is very hilly and some what difficult to walk on. You\n"
"notice that the gap between you and the other side is quite large, but\n"
"still to far to jump. To the north the ground looks hilly, and to the\n"
"southeast comes a smell that you'd rather not know about.\n";

	dest_dir=({
	"/players/calvyn/body/room9.c", "north"
	"/players/calvyn/body/room11.c", "southwest"
	});

	items=({ 
	"gap","Closer then what is to the southwest but still to far to jump.\n",
	"ground","Quite the variation of bumps and curves.\n",
	});
	property = ({
	  "no_teleport","no_sneak","no_steal",
	});
	smell = "Otherwise plesent except for a familiar oder comming from the south.";
    }
}

init()
{
    ::init();
}
