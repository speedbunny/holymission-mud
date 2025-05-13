#define NAME "ace"
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
	    "Welcome to Ace's workroom!  If you never though you'd live to see the day,\n" +
	    "guess again!  The Prince of Thieves welcomes you into his home away from \n" +
	    "home, and to look around and make yourself comfy.  Ignore the mess on the \n" +
	    "floor, he'll clean it...eventually.\n";

        /* we need some exits too ... lets set the destination directions */
        dest_dir=({
            "room/post", "post",
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
  ::init();
}
