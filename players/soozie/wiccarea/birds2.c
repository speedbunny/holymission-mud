#define NAME "soozie"
inherit "room/room";
#define CNAME   capitalize(NAME)

reset(arg) {
    if(!arg) {
	set_light(1);

	short_desc = "Polly want a....small mammal?? (n,s)";

	long_desc=
	"As you enter this room, you realise that the bird housed here is a predator\n"
"to be reckoned with.  Bones of small animals lie about and you can tell from \n"
"the talon marks on the tree branches where the falcon's favorite spot is.\n";

	dest_dir=({
	"/players/soozie/wiccarea/birds1.c","north",
	"/players/soozie/wiccarea/birds3.c","south",
	});

	items=({ 
	"bones","Some are old and bleached by the sun, others are fresh...\n"
	"marks","The marks are gouged into the flesh of the branch.\n"
	"branches","Most are dead or dying from having their bark stripped by claws.\n"
	});
	property = ({
	  "no_teleport","no_sneak","no_steal",
	});
	smell = "Smells quite a bit like blood...both fresh and rancid.";
    }
}

init()
{
    ::init();
}
