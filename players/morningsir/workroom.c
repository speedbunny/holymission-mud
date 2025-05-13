#define NAME "morningsir"
/* DEF_WORKROOM.C */
/* 300693: Ethereal Cashimor: Removed double define for NAME */
inherit "room/room";
#define CNAME   capitalize(NAME)

#include "/players/morningsir/defs.h"

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
            "This is the workroom of Morningsir. It is not quite big, but\n" +
            "it's cozy after all. Bad thing is that it's all messed up.\n" +
            "You cannot see through the dense dust in the air, but you\n" +
            "hear some crazy sounds coming from the other side. Looks like\n" +
            "Morningsir is 'working' again. But feel free to stay. And\n" +
            "listen, you could make a dinner for him, while he works hard!\n";

        /* we need some exits too ... lets set the destination directions */
        dest_dir=({
            "room/post", "post",
          "room/church", "church",
       "room/adv_guild", "guild",
                 });

        /* here could follow some item descriptions, like ...*/
        items=({ 
            "air","It's very dusty!",
            "floor","You cannot see the floor, the air is so dusty.",
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
