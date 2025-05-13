#define PPATH     "/players/tatsuo/ezo/ryuworld/"

inherit PPATH+"genCave";

string fall_down;

reset( arg )
{
   ::reset( arg );

   fall_down = "";

   if ( arg )
      return;

   dest_dir = ({ 
                 PPATH + "cb", "east"
              });
}

init( )
{
   string *ppl;

   ::init();

   if ( fall_down && !(this_player()->query_npc()) ) {
      ppl = explode( fall_down, "#" );
      if ( member_array( this_player()->query_real_name(), ppl ) >= 0 ) {
         write( "As you enter the room, you remind the hidden trapdoor and" +
                "\ncan avoid to fall into it !!!\n" );
         return( 1 );
      }
   }

   fall_down += (this_player()->query_real_name() + "#");
   write("As you enter the room, a trapdoor opens under your feets !!!\n"+
         "You fall down one floor !\n" );
   this_player()->move_player( "into the trapdoor#" + PPATH + "c10" );
}
