#define PPATH "/players/patience/smilequest/"
#define TP  this_player()
#define TPN TP->query_name()
#define TPOBJ  TP->query_objective()
#define TPPOS  TP->query_possessive()

inherit "room/room";

int    hookIsHere, cbIsHere;
object clown;

reset( arg )
{
   if ( !clown ) {
      clown = clone_object( PPATH + "clown" );
      move_object( clown, this_object() );
   }

   hookIsHere = 1; cbIsHere = 1;

   if ( arg )
      return;
  
   set_light(1);
   short_desc = "In the kitchen";
   long_desc = "You are in the kitchen of the castle of sadness.\n" +
               "All the things in here haven't been used for a long time and\n" +
               "they are all covered with dust. The table is nearly rotten and\n" +
               "the oven wasn't lighted for a long time. @@desc_cb@@\n"+
               "To the south is the bathroom, and to the west is the foreroom.\n";
   
   items = ({ "ground","It is a wooden floor",
              "floor","It is a wooden floor",
              "door","You can't see a door here",
              "walls","They are made of massive stone",
              "wall","They are made of massive stone",
              "things","They are all covered with dust",
              "dust","You see dust. Dust, and nothing else then dust",
              "table","It doesn't look very stable",
              "oven","It is burnt out and only ashes is left",
              "ashes","You see ashes. Ashes, and nothing else then ashes",
              "cupboard","@@l_cb@@",
           });
   
   dest_dir = ({ PPATH + "foreroom", "west",
                 PPATH + "bath", "south",
              });
}


init( )
{
   ::init( );
   add_action("search","search");
   add_action("push","move" );
   add_action("push","push" );
   add_action("destroy","break" );
   add_action("destroy","destroy" );
   add_action("destroy","smash" );
   add_action("get_it","get" );
   add_action("get_it","take" );
   add_action("get_it","pick" );
   add_action("open","open" );
   add_action("close","close");
}

destroy( str )
{
   if ( !str )
      return;
   if ( str == "table" ) {      
      write( "You look at the table but then you decide, that it isn't worse to destroy it.\n" );
      return( 1 );
   }

   return( 0 );      
}

push( str )
{
   if ( !str )
      return;
      
   if ( str == "table" ) {
      write( "You think that the table would crumble to dust if you'd try moving it.\n" +
             "So you decide, to give up your attempt.\n" );
      return( 1 );
   }

   return( 0 );      
}

search( arg )
{
   object hook;

   if ( !arg )
      return;
      
   if ( arg == "ashes" ) {
      if ( hookIsHere ) {
         write( "You find a hook!!!\n" );
         say( this_player()->query_name()+" found a hook.\n" );
         hook = clone_object(PPATH + "hook");
         if (transfer(hook,this_player())) {
            write( "But you can't carry that much.\n" );
            destruct( hook );
            return( 1 );
         }
         hookIsHere = 0;
         return( 1 );
      }
   }
   
   write("You search and search, but find nothing.\n");
   say(this_player()->query_name()+" searches around.\n");
   return 1;
}

get_it( str )
{
   if ( !str )
      return;
      
   if ( str == "ashes" || str == "dust" ) {
      write( "You try to get some " + str + ", but it slips through your fingers.\n" );
      say( TPN + " tries to get some " + str + ".\n" );
      return( 1 );
   }
   return( 0 );
}

open( str )
{
   if ( str == "cupboard" ) {
      if ( cbIsHere ) {
         write( "As you try to open the rotten cupboard, it crashes down and crumbles to dust!\n" );
         say( TPN + " destroyed the rotten cupboard.\n" );
         cbIsHere = 0;
      }
      else
         write( "But there is no cupboard here!\n" );
      return( 1 );
   }
      
   return( 0 );
}

close( str )
{
   if ( str == "cupboard" ) {
      if ( cbIsHere )
         write( "You can't close a closed cupboard!\n" );
      else
         write( "But there is no cupboard here!\n" );
      return( 1 );
   }
      
   return( 0 );
}

desc_cb( )
{
   if ( cbIsHere )
      return( "Also you can see a cupboard." );
   else
      return( "" );
}

l_cb( )
{
   if ( cbIsHere )
      return( "The cupboard is as rotten as the other things in this room and it's closed" );
   else
      return( "But you can't see a cupboard here" );
}

