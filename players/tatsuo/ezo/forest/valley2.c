#define PPATH  "/players/tatsuo/ezo/forest/"
#define TP     this_player()

inherit "room/room";

reset( arg )
{
   if ( arg )
      return;
      
   set_light(1);
   short_desc = "In a valley";
   long_desc = "You are standing in the middle of a big valley. The ground here is grassy.\n" +
               "The valley narrows to the south, but you feel, that you do not want to go\n" +
               "south. You have a very uneasy feeling, that soon can grow to fear !\n";
   items = ({ "ground", "It is grassy and some blood is on the grass",
              "blood", "The blood is dried",
              "grass", "Green, and sometimes red, because of the blood",
              });
              
   dest_dir = ({ PPATH + "valley3", "west",
                 PPATH + "valley1", "east",
                 PPATH + "rl3",     "down",
                 PPATH + "valley4", "south",
              });
   
   smell = "You smell the odor of blood and destruction.";
}


init( )
{
   ::init( );
   
   add_action( "search", "search" );
}

search( arg )
{
   if ( !arg )
      return;
         
   write("You search and search, but find nothing special.\n");
   say(this_player()->query_name()+" searches around.\n");
   
   return( 1 );
}
