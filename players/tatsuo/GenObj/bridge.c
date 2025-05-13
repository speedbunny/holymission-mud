
#define SHARE "obj/share"

inherit "/room/room";
#include "/players/patience/GenObj/globMonst.h"

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



/* --- monster of this room */
object roomMonster;

string numbers;

init() 
{
    int i;
    
    add_action( "smell_it", "smell"   );
    add_action( "search",   "search"  );
    add_action( "look_at",  "look"    );
    add_action( "look_at",  "examine" );
    ::init();

}

reset(arg)
{
   ::reset(arg);
   if ( monstChange > 0 ) {
      if ( !roomMonster ) {
         if ( random(100) < monstChange ) {
            roomMonster = get_rnd_monster();
            if ( roomMonster )
               transfer( roomMonster, this_object() );
         }
      }
   }
   if (!arg) return;
}

/* ----- Add-Actions -------------------------------------------------------------- */
smell_it(str)
{
  say(this_player()->query_name() + " tastes the air.\n");
  if( !smell )
  {
    if ( !str )
       write( "You smell the flavour of wood.\n" );
    else  
       write( "You the flavour of the wood is do dominant, that only can smell this.\n" );
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

look_at( arg )
{
    int    i;
    string treeKind;
    
    if ( !arg )
       return;
       
    i = 0;
    while(i < sizeof(dest_dir)) {
       treeKind = (dest_dir[i])->query_kindOfTree();
       if ( arg == treeKind || arg == treeKind+" tree" || arg == treeKind+"-tree" ||
            arg == "at "+treeKind || arg == "at "+treeKind+" tree" ||
            arg == "at "+treeKind+"-tree" )
       {
           write(dest_dir[i]->query_long());
           return( 1 );
       }
      
       i += 2;
    }
    
    return;
}

id(str)
{
   int i;
   
   if (!items)
     return;
   
   while (i < sizeof(items) ) {
     if (items[i] == str)
        return 1;
     i += 2;
   }
    
   return 0;
}

long(str)
{
   int i;
   
   if (!str)
   {
      write(process_string(long_desc));
      if (!dest_dir)
         write("There is no obvious exit here.\n");
      else {
         i = 0;
         if ( !pointerp(numbers) ) 
            numbers=SHARE->share_room_numbers();
            
         write( "There is " );

         while(i < sizeof(dest_dir)) {
            write( "a " + dest_dir[i]->query_kindOfTree() + 
                   "-tree to the " + dest_dir[i+1] );
            i += 2;
            if (i == sizeof(dest_dir) - 2)
               write(" and ");
            else
               if (i < sizeof(dest_dir)) write(", ");
         }
         write( ".\n" );
       }
       return;
   }
  
   if (!items)
      return;
   i = 0;
   while(i < sizeof(items)) {
      if (items[i] == str) {
         write(process_string(items[i+1]) + "\n");
         return;
      }
      i += 2;
   }
}

query_long()
{
   return long_desc;
}
 
query_drop_castle()
{
   return no_castle_flag;
}

/* ----- */

set_tree( str )
{
   return;
}

set_short_desc( str )
{
   if ( !str )
      short_desc = "On a ropebridge";
   else
      short_desc = str;
      
   long_desc = short_desc + ".\n";
   
   items = ({ "ropebridge", "The ropebridge is made of maple and rope.",
              "maria wichteldorf", "Walk around and you'll see it.",
              "tree","Which kind of tree do you mean?",
              "trees","You can see different kind of trees.",
              "wood","It lookes like wood normaly lookes.",
              "bridge","The ropebridge is made of maple and rope.",
              "door","It is a wooden door. Maybe you should go to the tree to have better sight.",
              "wooden door","It is a wooden door. Maybe you should go to the tree to have better sight.",
           });
}

set_long_desc( str )
{
   if ( !str )
      long_desc = "You are standing on a ropebridge in Maria Wichteldorf.\n";
   else
      long_desc = str;
}

set_dest_dir( array )
{
   dest_dir = array;
}

set_rope( state )
{
   return( 1 );
}

