#define NAME "calvyn"
inherit "room/room";
#define CNAME   capitalize(NAME)

reset(arg) {
    if(!arg) {
	set_light(1);

	short_desc = "Room3. (n,se)";

	long_desc=
	
	"The ground here is very hilly and somewhat difficult to walk on. You\n"
"notice that the gap between you and the other side is getting smaller, but\n"
"still too far to jump across. To the north the ground still looks hilly and\n"
"a hideous stench wafts over from the southeast.\n";

	dest_dir=({
	"/players/calvyn/body/room4.c", "north"
	"/players/calvyn/body/room2.c", "southeast"
	});

	items=({ 
	"gap","Closer then what it was to the southeast but still to far to jump.\n",
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
