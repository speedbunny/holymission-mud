#define NAME "calvyn"
inherit "room/room";
#define CNAME   capitalize(NAME)

reset(arg) {
    if(!arg) {
	set_light(1);

	short_desc = "Room7 (sw,e,ne)";

	long_desc=
	
	"Again you notice that the ground is quite wrinkly here. It dosen't\n"
"seem to look or feel like any ground that you've ever been on before. To the\n"
"east you seem to notice the area almost identical to the one you're at now. To\n"
"the northeast you hear a terrible rumbling sound, and to the southwest you see\n"
"that the area becomes peaceful again.\n";

	dest_dir=({
	"/players/calvyn/body/room8.c", "southwest"
	"/players/calvyn/body/room12.c", "northeast"
	"/players/calvyn/body/room6.c", "east"
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
