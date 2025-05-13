#define NAME "beardy"
/* DEF_WORKROOM.C */
/* 300693: Ethereal Cashimor: Removed double define for NAME */
inherit "room/room";
#define CNAME   capitalize(NAME)
object besh;


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
            "You are in a big bubble made of soap. Around this you see the\n" +
            "open sea and smell the fresh air. Some seagulls are flying around\n" +
	    "and a big fish jumps out of the water trying to catch your toe...\n"+
            "\nHope you do not lose your balance and fall.....\n\n";

        /* we need some exits too ... lets set the destination directions */
        dest_dir=({
            "room/post", "post",
	    "room/church", "church",
            "/players/beardy/workarea/barber2", "barber",
            "/players/beardy/workarea/battlebubble", "battle",
            "room/adv_guild", "guild", 
"/players/llort/shadowplane/rooms/valley1", "valley",
"/players/llort/guild/tower/summon1", "summon",
"/players/llort/guild/tower/inner_chamber", "chamber",
                 });

        /* here could follow some item descriptions, like ...*/
        items=({ 
            "air","It's very thin up here",
	    "fish","It looks dangerous",
	    "bubble","It has got a blue soft glowing aura." +
		     " You feel save here",
              });
        /* Properties can be set like the following */
                     "no_sneak","no_steal",
        property = ({
                    });
        /* Smell is set like this... */
        smell = "This place is a bit dusty";
    }
}

init()
{
  ::init();
add_action("scroll", "scroll");
  add_action( "start", "start" );
  add_action( "stop", "stop" );
}

int start() {
  besh = clone_object( "/players/beardy/shadow.c" );
  besh -> start_shadow();
  write( "started" );
  return( 1 );
}
int scroll() {
  object scrl;
  scrl = clone_object("/players/llort/secure/lwscroll");
  move_object(scrl, this_player());
  return 1;
}


int stop() {
  destruct( besh );
  write( "stopped" );
  return( 1 );
}
