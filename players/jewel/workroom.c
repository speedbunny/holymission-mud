#define NAME "DUNGEON MASTER JEWEL"
/* DEF_WORKROOM.C */
/* 300693: Ethereal Cashimor: Removed double define for NAME */

#define NAME "DUNGEON MASTER JEWEL"
#define CNAME   NAME

inherit "room/room";
int closed;


int smell_flowers(string str) {

     if (str == "flowers")
       tell_object(this_player(),"You smell the sweet fragrance of a spring bouquet.\n");
     else
       tell_object(this_player(),"It smells a bit musty in here.\n");

return 1;
}
int listen () {

  tell_object(this_player(),"You hear the roar of alligators munching on trash\n" + 
                             "that Jewel throws into the opening.\n");
  return 1;
}

 int peer_cage(string str) {


      if (str == "cage")
        tell_object(this_player(),"You see a wild-eyed creature hungrily peering back at you.\n");
   return 1; }





/* This procedure is called every hour at the mom. The first time it
   is call with the arg==0, after that arg is always 1. */
reset(arg) {
    /* do the following block only the first time !! */

   if(!arg) 
   {
        transfer( clone_object("/boards/private_boards/jewel"),this_object() );
        /* first we need some light in here */
        closed = 0;
        set_light(1);

        /* then lets set a short description in case we are in brief-mode */
        short_desc=CNAME + "'s workroom";

        /* now the long standard room description */
        /* change this to fit your style *grin* */
        long_desc=
            "This is the workroom of "+CNAME+".\n" +
       "You are graced with the honor of viewing Jewel hard at work in her\n" +
       "dungeon.  On the whole the room is dim, except for a blinding white\n" +
       "light emitted from a large diamond.  Below the diamond Jewel works\n" +
       "at her mighty oak desk.  Her toolbox is to her right, and a long row\n"+
       "of jars are to her left.  You notice a square opening under her desk to\n" +
       "the left.  What IS that sound you hear?  The eastern boundary consists\n" +
       "entirely of huge wrought-iron bars, beyond which you notice a cage.  The\n" +
       "only point of beauty, besides Jewel herself, is a small simple vase,\n"+
       "filled with flowers, at the center of her desk.\n";


        /* we need some exits too ... lets set the destination directions */
        dest_dir=({
            "room/post", "post",
            "room/church", "church",
            "players/dice/guild/room", "guild",
            "players/jewel/caverns/rooms/entrance", "cav",
            "players/jewel/rooms/cage","cage",
            "players/jewel/poe/badlands","poe",
                  });

        /* here could follow some item descriptions, like ...*/
        items=({
            "air","It's very musty in here",

            "floor","The floor is stone gray littered with blood and body parts.\n" +
                    "Have you seen Mangla lately?",

            "light","A light so bright and pure.  It hurts you to looks at it.You look away",
            "diamond","A mighty diamond with many facets.  The light it emits is blinding.\n" +
                      "You look away",
           "desk","A mighty desk made from the oldest and wisest oak in the druid forest",
            "toolbox","A well-used toolbox.  Inside you see several curious anduseful tools.\n" +
                               "Monster Glue\n" +
                               "Tooth Extracter\n" + "Soul Ripper\n" + "Player Poop-N-Scoop\n" +
                               "Mud Maker\n" + "Corpse Cutter\n" + "The Drill of Insanity\n" +
                               "...truncated..",
            "row","A long row of 12 jars",
            "jars","Clear glass jars with cork tops.  They are neatly labeled",
            "tops", "Jar tops made of the finest cork",
            "label", "A white square of paper pasted to the jar.\n" +
                      "There is clear black lettering on each jar",
            "jar 1","This jar is labeled 'Monster Fangs, extra long, #8492'",
            "jar 2","This jar is labeled 'Fish Guts, slimey, #0046'",
            "jar 3","This jar is labeled 'Tiny Jewels, green, #6035'",
            "jar 4","This jar is labeled 'swords, two-sided, #7042'",
            "jar 5","This jar is labeled 'Milk, fresh, Mabel'",
            "jar 6","This jar is labeled 'Muesli, enriched, 9 essential vitamins'",
            "jar 7","This jar is labeled 'Light Sources, jewels, white #1000'",
            "jar 8","This jar is labeled 'Haunter Slime #0666'",
            "jar 9","This jar is labeled 'Maze Walls, annoying, #8372'",
            "jar 10","This jar is labeled 'Dragon Claws, silver, #2005'",
            "jar 11","This jar is labeled 'Giant toes, large, #4924'",
            "jar 12","This jar is labeled 'Smoke, black,#3951'",
            "opening","As you peer inside you catch a quick glimpse flashing white fangs",
            "vase","A simple, yet strikingly beautiful glass face with a high index of reflection",
            "flowers","A lovely arrangement of irises, carnations, and roses",
            "wall","It is too hard to see past the blinding light to the walls",
            "ceiling","It is too hard to see past the blinding light to the ceiling",
            "bars","Very thick, strong wrought-iron bars",
            "boundary","The eastern side of the room, marked totally by the wrought-iron bars",
            "cage","A large cage with wrought-iron bars.  Since you are close,\n" +
                    "maybe you can peer into the cage"
              });
        /* Properties can be set like the following */
        property = ({
                     "no_teleport","no_sneak","no_steal",
                    });
        /* Smell is set like this... */


    }
}

int VALID()
{
    if (this_player()->query_real_name()!="jewel") 
       return 0;
    return 1;
}
void move_out(object tp)
{
   tp->move_player("out of jewels workroom#room/church");
}

init()
{
  ::init();
  if (this_player()->query_real_name() != "jewel" && closed == 1)
      call_out("move_out",1,this_player());
  add_action ("smell_flowers", "smell");
  add_action ("listen","listen");
  add_action ("peer_cage","peer");
  if (this_player()->query_real_name() == "jewel")
  {  
     add_action("do_open","open");
     add_action("do_close","close");
  }
}

int do_open()
{
    if (!VALID()) return 0;
    closed = 0;
    write("Ok\n");
  return 1;
}

int do_close()
{
    if (!VALID()) return 0;
    closed = 1;
    write("Ok\n");
   return 1;
}

