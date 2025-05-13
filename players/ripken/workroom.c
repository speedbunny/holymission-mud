#define NAME "ripken"
/* DEF_WORKROOM.C */
/* 300693: Ethereal Cashimor: Removed double define for NAME */
inherit "room/room";
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
	"You have entered the workroom of "+CNAME+".  It is possibly the \n"+
	"messiest room you have ever been in your entire life.  You are not\n"+
	"sure if you can walk to the desk in the middle of the room.  The \n"+
	"floor is covered with all kinds of stuff, books, clothing, junk, \n"+
	"and other assorted wierd things.  There are a few examples \n"+
	"of bad coding lying about in heaps.  There is a tv and computer \n"+
	"sitting on the desk.  There is also a bed off to one side. \n"+
	"\n";

	/* we need some exits too ... lets set the destination directions */
	dest_dir=({
	  "room/post", "post",
	  "room/church", "church",
	  "room/adv_guild", "guild", 
	  "players/mangla/guild/inner", "jed",
	  "players/helmut/workroom", "helmut",
	  "players/nylakoorub/workroom", "ant",
	});

	hidden_dir=({
	});
	/* here could follow some item descriptions, like ...*/
	items=({ 
	  "floor","Is there a floor under all this stuff?",
	  "junk","There is almost everything you can imagine on this floor!",
	  "bed","The bed looks well slept in, the sign of the truely lazy!",
          "tv","The television is showing Babylon 5.",
          "computer","The computer is surfing the net, without Windows 95!",
	  "desk","The desk looks like it has been rarely used, except for a few\nscattered papers and a nice paperweight",
	  "paperweight","An award from the American Chemical Society",
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
