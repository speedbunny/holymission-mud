#define PPATH  "/players/tatsuo/ezo/forest/"
#define TP     this_player()

inherit "room/room";

reset( arg )
{
   if ( arg )
      return;
      
   set_light(1);
   short_desc = "In a valley";
   long_desc = "You are now at the southern end of the valley. You get more and more\n" +
               "feared. The walls join at the south and the scratches in the wall are\n" +
               "very deep here. The ground has changed from grass to plain stone and\n" +
               "is now stained with blood.\n";
   items = ({ "ground", "It is stoney and blood is on the grass",
              "blood", "The blood is dried",
              "stones", "They are grey, and often red, because of the blood",
              "scratches", "They are very deep and bloody",
              "wall", "There are very deep scratches at the wall.\n" +
                      "But wait ... To the south is a small cave",
              "cave", "The cave has a very narrow opening. It is dark inside the cave",
              "opening", "It is very narrow",
              "stone", "They are grey, and often red, because of the blood",
              });
              
   dest_dir = ({ PPATH + "valley3", "northwest",
                 PPATH + "valley1", "northeast",
                 PPATH + "valley2", "north"
              });
   
   smell = "You smell the odor of blood and destruction.";
}


init( )
{
   ::init( );
   
   add_action( "search", "search" );
   
   add_action( "enter_it", "enter" );
}

search( arg )
{
   if ( !arg )
      return;
         
   write("You search and search, but find nothing special.\n");
   say(this_player()->query_name()+" searches around.\n");
   
   return( 1 );
}

enter_it( arg )
{
   if ( !arg )
      return;
      
   if ( arg == "cave" || arg == "the cave" ) {
      write( "You squeeze yourself through the narrow opening.\n" );
      TP->move_player( "into the wall", PPATH + "cave1" );
      return( 1 );
   }

   return( 0 );
}
