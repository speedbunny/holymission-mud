#define NAME "topaz"
/* DEF_WORKROOM.C */
/* 300693: Ethereal Cashimor: Removed double define for NAME */
inherit "room/room";

#define CNAME   capitalize(NAME)

object board;
object stereo;

int connected_to_center() { return 1; }

/* This procedure is called every hour at the mom. The first time it
   is call with the arg==0, after that arg is always 1. */
reset(arg) {
    if(!board) {
    board = clone_object("players/topaz/obj/board");
    move_object(board,this_object());
    }
    if(!stereo) {
    stereo = clone_object("players/topaz/obj/stereo");
    move_object(stereo,this_object());
    }
    /* do the following block only the first time !! */
    if(!arg) {
        /* first we need some light in here */
        set_light(1);

        /* then lets set a short description in case we are in brief-mode */
        short_desc=CNAME + "' workroom",

        /* now the long standard room description */
        /* change this to fit your style *grin* */
        long_desc=
            "Topaz likes to relax here and get away from the pressures of\n" +
            "everyday life here.  If he's sleeping, please don't wake him.  :)\n" +
            "You look around and see that he keeps it pretty neat here.\n" +
            "(unlike his room in real life)\n" +
            "\n" +
            "On the walls you notice posters of comic book heroes.\n" +
            "Topaz likes comic books, but they're pretty expensive nowadays.\n" +
            "On his desk you also notice stacks of comic books in plastic\n" +
            "bags.  Please try not to knock them over.\n";

        /* we need some exits too ... lets set the destination directions */
        dest_dir=({
            "room/post", "post",
	    "room/church", "church",
            "room/adv_guild", "guild", 
            "players/topaz/rooms/demons/entrance", "demons",
            "players/topaz/rooms/testpit", "down",
            "players/topaz/rooms/attach/field1","fields",
            "players/nokey/centralroom","central",
                 });

    hidden_dir=({
        "players/topaz/rooms/cont/town_hall","townhall",
        "players/matt/newworld/city/rooms/votebooth","votebooth",
    });

        /* here could follow some item descriptions, like ...*/
        items=({ 
            "air","It's very thin up here",
            "floor","The floor is spotless",
            "desk","Stacks of comic books are all over it",
            "comics","Please be careful as you look at them",
            "comic books","Please be careful as you look at them",
            "books","Nothing but comic books",
            "wall","You see Spiderman, The X-Men and Groo???  Whatever",
            "walls","You see Spiderman, The X-Men and Groo???  Whatever",
            "groo","Yep.  That mendicant of a barbarian, Groo",
            "posters","You recognize most of the heroes on them",
            "plastic bags","To protect the comic books.  Naturally",
            "bags","To protect the comic books.  Naturally",
            "poster","There's LOTS of them",
            "stacks","Most of the popular titles and some obscure ones also",
              });
        /* Properties can be set like the following */
        property = ({
                     "no_teleport","no_sneak","no_steal",
                    });
        /* Smell is set like this... */
        smell = "This place is a bit dusty";

    }
}
