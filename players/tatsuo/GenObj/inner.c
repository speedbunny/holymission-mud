#define SHARE "obj/share"

inherit "/room/room";
/*
 * This is a proposal of a replacement to std.h. It is used with
 * 'inherit "room/room";'.
 * All global variables below are supposed to be setup by the reset()
 * in the function that inherits this file.
 */
 
#ifndef TRUE
#define TRUE   (1)
#endif
#ifndef FALSE
#define FALSE  (0)
#endif


/* --- Which kind of tree it is */
string kindOfTree;

/* --- door */
string otherDoor;

string numbers;

init() {
    int i;
    ::init();    
    add_action( "smell_it", "smell"   );
    add_action( "search",   "search"  );
    add_action( "open",     "open"    );
    add_action( "close",    "close"   );
   
}

reset(arg) { ::reset(arg); if (arg) return; }

/* ----- Add-Actions -------------------------------------------------------------- */
smell_it(str)
{
  say(this_player()->query_name() + " tastes the air.\n");
  if( !smell )
  {
    if ( !str )
       write( "You smell the flavour of " + kindOfTree +".\n" );
    else 
       write( "You the flavour of the " + kindOfTree + " is do dominant, that only can smell this.\n" );
    return( 1 );
  }
  
  write(smell+"\n");
  
  return( 1 );
}


search( arg )
{
   if ( !arg )
      return;
      
   write("You search and search, but find nothing.\n");
   say(this_player()->query_name()+" searches around.\n");
   return 1;
}

close(str)
{
   return( otherDoor->close( str ) );
}
     
open( str )
{
   return( otherDoor->open( str ) );
}

query_door_closed()
{
   return( otherDoor->query_door_closed() );
}

query_door_locked()
{
   return( otherDoor->query_door_locked() );
}

/* ----- */

set_other_dside( str )
{
   otherDoor = str;
}

set_tree( str )
{
   if ( !str ) {
      if ( otherDoor )
         kindOfTree = otherDoor->query_kindOfTree();
      else
         kindOfTree = "oak";
   }
   else
      kindOfTree = str;
}

set_door_state( state )
{
   return( 0 );
}

set_short_desc( str )
{
   if ( !str )
      short_desc = "Inside a " + kindOfTree +"-tree";
   else
      short_desc = str;
      
   long_desc = short_desc + ".\n";
   
   items = ({ "door","The door is made of " + kindOfTree + "-wood. It is " +
                     "@@_door_state1@@.",
              "wooden door","The door is made of " + kindOfTree + "-wood. It is " +
                            "@@_door_state1@@.",
              "tree","It is a very huge and massive " + kindOfTree + "-tree.",
              kindOfTree,"It is a very huge and massive " + kindOfTree + "-tree.",
              kindOfTree+"-tree","It is a very huge and massive " + kindOfTree + "-tree.",
              "wall","You're inside a " + kindOfTree + "-tree. Of what do you think, " +
                     "the walls are made???",
              "walls","You're inside a " + kindOfTree + "-tree. Of what do you think, " +
                      "the walls are made???",
              "wood","Which kind of wood do you expect in this tree???",
           });
}

set_long_desc( str )
{
   if ( !str )
      long_desc = "You are standing inside a huge " + kindOfTree + "-tree.\n" +
                  "You can see @@_door_state2@@, wooden door in the wall.\n";
   else
      long_desc = str;
}

cat_long_desc( str )
{
   long_desc += str;
}

set_items( array )
{
   if ( items )
      items += array;
   else
      items = array;
}

set_dest_dir( array )
{
   if ( otherDoor ) {
      if ( array )
         dest_dir = ({otherDoor, "out",}) + array;
      else
         dest_dir = ({otherDoor, "out",});
   }
   else {
      if ( array )
         dest_dir = array;
   }
}

_door_state1( )
{
   if ( otherDoor->query_door_closed() )
      return( "closed" );
   else
      return( "open" );
}

_door_state2( )
{
   if ( otherDoor->query_door_closed() )
      return( "a closed" );
   else
      return( "an open" );
}
