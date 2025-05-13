#define NAME "calvyn"
inherit "room/room";
#define CNAME   capitalize(NAME)

reset(arg) {
    if(!arg) {
	set_light(1);

	short_desc = "Room6 (nw,w,se)";

	long_desc=
	
	"First you notice that the ground here is quite wrinkly here. It dosen't\n"
"seem to look or feel like any ground that you've ever been on before. To the\n"
"west you seem to notice the area almost identical to the one you're at now. To\n"
"the northwest you hear a terrible rumbling sound, and to the southeast you see\n"
"that the area becomes more peaceful.\n";

	dest_dir=({
	"/players/calvyn/body/room5.c", "southeast"
	"/players/calvyn/body/room12.c", "northwest"
	"/players/calvyn/body/room7.c", "west"
	});

	items=({ 
	"ground","Quite the wrinkly bit.\n",
	"sky","A deep blue sky is over head.\n",
	});
	property = ({
	  "no_teleport","no_sneak","no_steal",
	});
	smell = "Fresh air flows through your nostrils";
    }
}

init()
{
    ::init();
}
