#define HOME "/players/silver/"
#define ROOM "/players/silver/rooms/"
#define OBJ  "/players/silver/obj/"
#define MONSTER "/players/silver/monsters/"

inherit "room/room";

object waitres;
int counter;

/*------- ADD_COMMAND FUNCTIONS ---------*/

 tell_me()
  {
    if(present("beer",this_player())) return 1;
    tell_room(this_object(),"You should drink more.\n");
    if(counter>1) call_out("tell_me",20);
    return 1;
  }
call_waitress()
 {
  if (!waitres)
   {
    waitres = clone_object(MONSTER + "waitress");
    move_object(waitres,this_object());
   }
 return 1;
}

/*--------------------------------------------------------------------*

/* This procedure is called every hour at the mom. The first time it
   is call with the arg==0, after that arg is always 1. */

reset(arg)
  {
    if(!arg)    /* do the following block only the first time */
     {
       set_light(1);        /* first we need some light in here */

        /* then lets set descriptions */
        short_desc="Silver's testroom";
        long_desc=
  "This is the testroom of Silver.\n" +
 "You entered dark room  with gray stony walls. That's  the place where Silver\n" +
 "runs all his dirty experiments  he  doesn't  dare  to do even in his private\n" +
 "workroom  west  from  here. Beware  all  these new creatures which can enter\n" +
 "the  room  anytime. Fireplace makes  that  place warmer  but you still dream\n" +
 "about Silver's bar you saw in his workroom. There is a sign on the wall next\n" +
 "to fireplace.\n";

       /* lets set the destination directions */
        dest_dir=
          ({
            "room/church", "church",
            HOME + "workroom","west",
            ROOM + "1desert1","desert",
            ROOM  + "pit","pit"
          });

        /* here could follow some item descriptions, like ...*/
        items=
          ({
            "air","It's very thin up here",
            "floor","The floor is dirty",
            "sign","\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n" +
                         "     If you want to get some beer     \n"+
                         "    snap your fingers without fear.    \n\n"+
                        "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~",
           "fireplace","It's lighted firplace. You enjoy light and warm it gives",
           "walls","Gray cold stony walls"
          });

        /* Properties can be set like the following */
        property =
          ({
            "no_sneak","no_steal","has_fire"    /* no_teleport */
          });

         /* Smell is set like this... */
        smell = "This place is a bit dusty";
    }
 }

init()
 {
  ::init();
     counter=10;
    call_out("tell_me",10);
  add_action("call_waitress","snap");
 }
