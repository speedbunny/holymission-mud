// the room behind the shadow door
// used for the shadow door - spell
// patience: 050295
// -------------------------------------------------------------------------

inherit "room/deathtrap";

object door;                  // my connection to the outer plane

reset( tick )
{
   ::reset(tick);

   if ( tick ) return;

   set_light( 1 );
   short_desc = "A shadowy chamber";
   long_desc =
      "This is a shadow-filled chamber. You cannot actually decide where\n"+
      "they came from, they are simply here. The room also seems to have\n"+
      "no extensions as you know them from the prime material plane.\n"+
      "But at least you feel safe here and a shadowy door leads back to\n"+
      "where you have come from.\n";

   items = ({ "shadow", "Dark gray or black, nothing really exciting",
              "shadows", "Dark gray or black, nothing really exciting",
              "door","@@check_door@@"
           });

   set_time_to_trigger( 600 );
   set_dt_msg( "Suddenly the shadows turn dark black and vanishes.\n"+
               "You are thrown into the void and TORN APART ....\n" );
}

check_door()
{
   write( "Looking through the door you can see:\n\n" );
   environment(door)->long();
   return( "" );
}

init_room( d )
{
   door = d;
   ::init();
   dest_dir = ({ file_name(environment(door)), "out" });
}

void process_dt()
{
   ::process_dt();

   if ( door ) door->dest_door();
   destruct( this_object() );
}
