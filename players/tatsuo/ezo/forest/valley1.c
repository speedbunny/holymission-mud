#define PPATH  "/players/tatsuo/ezo/forest/"
#define TP     this_player()

inherit "room/room";

reset( arg )
{
   if ( arg )
      return;
      
   set_light(1);
   short_desc = "In a valley";
   long_desc = "You are standing in a big valley. The ground here is grassy and a wall\n" +
               "zooms up at your eastern side. There is blood on the grass and deep\n" +
               "scratches at the wall. Blood is also on the ground. You feel feard!\n" +
               "The valley narrow to the south.\n";
   items = ({ "ground", "It is grassy and some blood is on the grass",
              "wall", "It zooms up almost to eternity",
              "blood", "The blood is dried",
              "grass", "Green, and sometimes red, because of the blood",
              });
              
   dest_dir = ({ PPATH + "valley4", "southwest",
                 PPATH + "rl4",     "down",
                 PPATH + "valley2", "west",
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
