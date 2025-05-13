inherit "room/room";
#define CNAME   capitalize(NAME)
#define NAME    "meechams"

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
            "This is the workroom of "+CNAME+".\n" +
	    "It looks empty ...\n";

        /* we need some exits too ... lets set the destination directions */
        dest_dir=({
            "players/meecham/workroom","south",
            "players/meecham/nowimpy","nowimpy",
                 });

        /* Properties can be set like the following */
        property = ({
                     "no_sneak",
                    });
    }
}

init()
{
  ::init();
}
