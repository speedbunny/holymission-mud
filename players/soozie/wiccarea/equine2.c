#define NAME "soozie"
inherit "room/room";
#define CNAME   capitalize(NAME)

reset(arg) {
    if(!arg) {
	set_light(1);

	short_desc = "Never look a gift horse in the mouth. (e,w)";

	long_desc=
	"This room looks much like the last, excepting that the zebras have been\n"
"replaced by a stallion and his mare.  The stallion looks up and snorts as \n"
"you approach.  You're not quite sure if he's going to attack or run away.\n";

	dest_dir=({
	"/players/soozie/wiccarea/equine1.c","west",
	"/players/soozie/wiccarea/equine3.c","east",
	});

	items=({ 
	});
	property = ({
	  "no_teleport","no_sneak","no_steal",
	});
	smell = "Ah there's nothing quite like the smell of horses.";
    }
}

init()
{
    ::init();
}
