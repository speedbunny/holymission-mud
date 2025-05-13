
inherit "room/room";

/* This procedure is called every hour at the mom. The first time it
   is call with the arg==0, after that arg is always 1. */
reset(arg) {
    /* do the following block only the first time !! */
    if(!arg) {
        /* first we need some light in here */
        set_light(1);

        /* then lets set a short description in case we are in brief-mode */
        short_desc="Nowimpy room",

        /* now the long standard room description */
        /* change this to fit your style *grin* */
        long_desc=
            "This is the nowimpy room.\n" +
            "This is where monsters who move are tested.\n" ;

        /* here could follow some item descriptions, like ...*/

        items=({ 
            "air","It's very thin up here",
            "floor","The floor is dirty",
              });
        /* Properties can be set like the following */
        property = ({
                     "no_sneak",
                    });
        /* Smell is set like this... */
        smell = "This place is a bit dusty";
    }
}

init()
{
  ::init();
}
