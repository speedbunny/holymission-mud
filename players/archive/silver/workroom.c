#define room_Sid "workroom"
#define ROOM "/players/silver/rooms/"
#define MONSTER "/players/silver/monsters/"
#define HOME "/players/silver/"

inherit "room/room";

object board;
object waitres,bea;

/*---------- ADD_COMMAND FUNCTIONS ----------*/

 chair(str)
   {
   if ( !str || str != "on armchair") return 0;
   this_player()->move_player("throught the chair#/room/church");
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


  call_bea()
    {
       bea = clone_object(MONSTER + "beatrice");
       move_object(bea,this_object());
     return 1;
   }
/*---------------------------------------------------------------*/

/* This procedure is called every hour at the mom. The first time it
   is call with the arg==0, after that arg is always 1. */

reset(arg)
  {
    if(!arg)    /* do the following block only the first time */
     {
       set_light(1);        /* first we need some light in here */

        /* then lets set descriptions */
        short_desc="Void";
        long_desc=
            "This is the workroom of Silver.\n" +
"It's nice a bit dusty room furnished in old fashion. Wooden table already\n" +
"all covered with maps  and  books stands  in the middle of the room. Next\n" +
"to fireplace you  see  soft armchair and pillow.  Several shelves full of\n" +
"ancient books and scrolls are  just small piece of  information comparing\n" +
"with a heap  of  the books in the corner. Short look at the glass of wine\n" +
"and the bottle  on  the  bar tells you what Silver likes to drink when he\n" +
"feels alone and depressed. But as  it  is  already empty you can guess he\n" +
"runs happily somewhere around here.\n";

       /* lets set the destination directions */
        dest_dir=
          ({
            "/room/purgatory","purgatory",
           "/room/church","church",
            "/players/silver/MOB/rooms/tr1","mob",
           "/room/post","post",
             HOME + "testroom","east"
          });
           board = clone_object("/boards/private_boards/silver");
           board->set_name("Silver's IQ raising");
         move_object(board,this_object());


        /* here could follow some item descriptions, like ...*/
        items=
          ({
            "air",          "It's fresh and clear",
            "floor",       "The floor is covered with thick red carpet",

            "bar",        "An old wooden bar used for storing alcohol drinks",
            "glass",     "Well there is more glass then wine as you see it",
            "bottle",     "An empty bottle of red wine. You need to be faster next time",

       "fireplace", "You have seen several fireplaces before but that one is a real masterpiece",
       "armchair","You see old comfortable armchair but you can bet Silver would be angry\n" +
                            "if someone else would sit there. Better to don't even try to sit on that",
         "pillow","It seems its used to be under Silvers legs when he sits next to fireplace",

            "table",     "An old massive wooden table full of maps and books",
            "shelves", "All of them are full of books and scrolls. Nice look",

            "books",   "Books are mostly about programming",
            "maps",    "Most of maps shows different parts of large desert.\n" +
                           "You wonder who can use such maps",
            "scrolls",  "It's written in the language you don't understand.\n" +
                           "Ask Silver to teach you proper Czech",

         "heap","What you want to see on the heap of books ? You can examine your own \n" +
                          "one if you can't live without it",
          });

        /* Properties can be set like the following */
        property =
          ({
            "no_sneak","no_steal","has_fire"
          });

         /* Smell is set like this... */
        smell = "You smell the fine aroma of a good tabacco.\n";
    }
 }

init()
 {
  ::init();
  add_action("call_bea","bea");
  add_action("chair","sit");
  add_action("call_waitress","snap");
 }

