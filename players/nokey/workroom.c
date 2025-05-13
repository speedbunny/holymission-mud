#define NAME "nokey"
/* DEF_WORKROOM.C */
/* 300693: Ethereal Cashimor: Removed double define for NAME */
#pragma strict_types
#pragma save_types
inherit "room/room";
#define CNAME   capitalize(NAME)

int id(string str)
  { return str=="clock"; }

int connected_to_center() { return 1; }

varargs void long(string str)
  {
  if(str == "clock")
    {
    write("You are struck by a sudden shock as it says:\n");
    "obj/tick"->qry_timer();
    return;
    }
  ::long(str);
  }

/* This procedure is called every hour at the mom. The first time it
   is call with the arg==0, after that arg is always 1. */
void reset(int arg) {
    /* do the following block only the first time !! */
    if(!arg) {
        "/players/nokey/board"->move(this_object());
        /* first we need some light in here */
        set_light(1);

        /* then lets set a short description in case we are in brief-mode */
        short_desc=CNAME + "'s workroom";

        /* now the long standard room description */
        /* change this to fit your style *grin* */
        long_desc=
            "This is the workroom of "+CNAME+".\n" +
    "It looks empty, except for a rather forbidding looking clock.\n";

        /* we need some exits too ... lets set the destination directions */
        dest_dir=({
            "room/post", "post",
	    "room/church", "church",
            "room/adv_guild", "guild", 
            "/players/nokey/centralroom","central",
            "/players/mangla/guild/room","jediguild",
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
        "/players/nokey/castle"->short();
    }
}

void init()
{
  ::init();
}
