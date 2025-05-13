#define NAME "unuscione"
/* DEF_WORKROOM.C */
/* 300693: Ethereal Cashimor: Removed double define for NAME */
inherit "room/room";
object filename;
#define CNAME   capitalize(NAME)

/* This procedure is called every hour at the mom. The first time it
   is call with the arg==0, after that arg is always 1. */
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
	"This is Unuscione's workroom, and as you step onto the plush green "+
	" carpet, you realize that this room is only ythe beginnings of the "+
	"works of Unuscione in this game. All over the walls are pictures "+
	"of all of his friends. Have fun!\n"
	"It looks empty ...\n";

	/* we need some exits too ... lets set the destination directions */
	dest_dir=({
	  "room/post", "post",
	  "room/church", "church",
	  "room/church", "church",
	  "/players/tatsuo/workroom", "Tatsuo",
	});
	filename = clone_object("players/unuscione/filename.c");
	move_object(filename,this_object());

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
    ::init();
}
