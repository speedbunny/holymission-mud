#define NAME "soozie"
inherit "room/room";
#define CNAME   capitalize(NAME)

reset(arg) {
    if(!arg) {
	set_light(1);

	short_desc = "You can lead a horse to water...(e,w)";

	long_desc=
	"As you enter this room you behold a beautiful sight:The mystical unicorn!\n"
"His coat is white as snow, and he tosses his mane and prances for you.  His\n"
"golden horn gleams in the sun.\n";

	dest_dir=({
	"/players/soozie/wiccarea/equine2.c","west",
	"/players/soozie/wiccarea/equine4.c","east",
	});

	items=({ 
	});
	property = ({
	  "no_teleport","no_sneak","no_steal",
	});
	smell = "It smells clean in here.";
    }
}

init()
{
    ::init();
}
