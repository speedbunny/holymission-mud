#define NAME "helmut"
/* DEF_WORKROOM.C */
/* 300693: Ethereal Cashimor: Removed double define for NAME */
inherit "room/room";
#define CNAME   capitalize(NAME)

/* This procedure is called every hour at the mom. The first time it
   is call with the arg==0, after that arg is always 1. */

int _sword() {

    "players/helmut/weapons/longsword"->short();
    return 1;
}


reset(arg) {
    /* do the following block only the first time !! */
    if(!arg) {
	/* first we need some light in here */
	set_light(1);

	/* then lets set a short description in case we are in brief-mode */
	short_desc=CNAME + "' workroom",

	/* now the long standard room description */
	/* change this to fit your style *grin* */
	long_desc=
	"Helmut's workroom is well lit, but you cannot see the light\n"+
	"source.  The walls themselves seem to give off a soft glow,\n"+
	"and your eyes adjust quite easily.  Out the window, you see a\n"+
	"magnificent view of a many-towered castle.  So vast is this\n"+
	"castle that you realize that you are INSIDE it, even though\n"+
	"you see many towers outside.  Carved into the stone above the\n"+
	"great, stone fireplace is one word...A'sua...\n";
	"source.  It is as if the very walls themselves\n";

	/* we need some exits too ... lets set the destination directions */
	dest_dir=({
	  "players/helmut/rooms/jungle1","area",
	  "room/church", "church",
	  "room/adv_guild", "guild", 
	});

	/* here could follow some item descriptions, like ...*/
	items=({ 
	  "air","It's very thin up here",
	  "floor","The floor is dirty",
	});
	/* Properties can be set like the following */
	property = ({
	  "no_teleport","no_sneak","no_steal",
	});
	/* Smell is set like this... */
	smell = "This place is a bit dusty";
    }
}

init()
{
   add_action("_sword","swords");
    ::init();
}
