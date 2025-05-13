#define NAME    "baalthasar"
#define CNAME	capitalize(NAME)
inherit "room/room";

/* This procedure is called every hour at the mom. The first time it
   is call with the arg==0, after that arg is always 1. */
reset(arg) {
    /* do the following block only the first time !! */
    if(!arg) {
        /* first we need some light in here */
        set_light(1);

        /* then lets set a short description in case we are in brief-mode */
short_desc = "The workroom of the powerful Demonlord Baalthasar",

        /* now the long standard room description */
        /* change this to fit your style *grin* */
        long_desc=
   "      You are totally and completely lost...the great evil \n"
+"surrounding you indicates you probably shouldn't be here..... \n\n";

        /* we need some exits too ... lets set the destination directions */
        dest_dir=({
            "obj/tick","tick",
	    "room/church", "church",
            "room/adv_guild", "guild", 
   "/players/baalthasar/kittalk", "KitMee",
                 });

        /* here could follow some item descriptions, like ...*/
        items=({ 
            "air","It's very thin up here",
            "floor","The floor is dirty",
              });
     }
}
