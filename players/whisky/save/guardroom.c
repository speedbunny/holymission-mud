#define PPATH "/players/patience/smilequest/"
#define TP  this_player()
#define TPN TP->query_name()
#define TPOBJ  TP->query_objective()
#define TPPOS  TP->query_possessive()

inherit "room/room";

int courtainMoved;

object guard;

reset( arg )
{
   if ( !guard ) {
      guard = clone_object( PPATH + "guard" );
      move_object( guard, this_object() );
   }

   if ( arg )
      return;
  
   set_light(1);
   short_desc = "In front of the castle";
   long_desc = "You are standing in front of the castle of sadness.\n" +
               "Large trees standing to your left and to your right,\n" +
               "but most of the trees are withered. An aura of sadness lingers\n" +
               "about here. To the south you see the entrance of the castle.\n";
   
   items = ({ "ground","A lot of mud covers it",
              "floor","A lot of mud covers it",
              "trees","They are withered or nearly rotten. It is a very sad view",
              "castle","You think that the people in this castle are very sad",
           });
   
   dest_dir = ({ "/room/south/sforst45", "north",
              });
}


init( )
{
   ::init( );
   add_action("search","search");
   add_action("enter","enter");
   add_action("south","south");
}


search( arg )
{
   write("You search and search, but find nothing.\n");
   say(this_player()->query_name()+" searches around.\n");
   return 1;
} 

enter( arg )
{
   object inv;
   int    i;
   
   if ( arg != "castle" )
      return;
  
   if ( present( "guard", this_object() ) ) {
      inv = all_inventory( TP );
      i = 0;
      while ( i < sizeof(inv) ) {
         if ( inv[i]->query_weapon() ) {
            write( "The human growls: Do you really think," +
                   "you can go to the king with your weapons?\n" );
            write( "The human laughs at you.\n" );
            return( 1 );
         }
         i++;
      }
   }
   
   this_player()->move_player( "south#players/patience/smilequest/entrance" );

   return( 1 );
}    

south( )
{
   object inv;
   int    i;
   
   if ( present( "guard", this_object() ) ) {
      inv = all_inventory( TP );
      i = 0;
      while ( i < sizeof(inv) ) {
         if ( inv[i]->query_weapon() ) {
            write( "The human growls: Do you really think," +
                   "you can go to the king with your weapons?\n" );
            write( "The human laughs about you.\n" );
            return( 1 );
         }
         i++;
      }
   }
   
   this_player()->move_player( "south#players/patience/smilequest/entrance" );

   return( 1 );
}    
