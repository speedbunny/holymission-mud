inherit "room/room.c";
#define PPATH  "/players/tatsuo/ezo/coast/"
#define NINJA 8
#define TP     (this_player())
#define RLM "/religion/master"
#define RELIGION "Amaterasu"
#include "/players/tatsuo/guild/skill_id.h"
reset(arg) {
   ::reset( arg );
if(arg) return;
   set_light( 1 );
   short_desc = "Inside a jingu";
   long_desc =
      "You are inside a strange looking stone. The walls are shimmering in\n"+
      "a faint yellow color. Beside the opening, a place is set aside for\n" +
      "purifucation rituals and near the south wall is a place for meditation"+
      ".\nA small stream of water flowing down the northern wall.\n" +
      "    There is one obvious exit: out\n";
   items=({
	"walls","They are a shimmering faint yellow color",
	"wall","It is shimmering faintly yellow",
         "opening", "The opening faces east",
        "stream", "It is a small stream of water",
        "water", "It flows down the northern wall",
   });
   property = ({"no_teleport"});
}

init() {
   ::init();
   add_action( "do_out", "out" );
   add_action( "do_wash", "wash" );
   add_action( "do_rinse", "rinse" );
   add_action( "do_meditate", "meditate" );
   add_action( "do_sacri", "sacrifice" );
}

long(str) {
   if(!str)
      write( process_string( long_desc ) );
   else
      return( ::long( str ) );
   return( 1 );
}

do_out(arg) {
   object *obj;
   if(arg) return;
   obj = present( "puri_check", TP );
   if ( obj )
      destruct( obj );
   this_player()->move_player( "out#"+PPATH+"rf6" );
   return( 1 );
}

do_wash(arg) {
   object *puri_check;
   if ( !arg ) {
      write( "What do you want to wash?\n" );
      return( 1 );
   }
   else if ( TP->query_ghost() ) {
      write( "As a ghost ?\n" );
      return( 1 );
   }
   if ( arg == "hands" ) {
      puri_check = present( "puri_check", TP );
      if ( !puri_check ) {
         puri_check = clone_object( PPATH + "puri_check" );
         move_object( puri_check, TP );
      }
      puri_check->set_hands_washed();
      write( "You wash your hands. You feel the deities appreciating it.\n" );
   }
   else if ( arg == "hand" ) {
      write( "Only one ?\n" );
   }
   else
      write( "You wash your " + arg + ".\n" );
   say( TP->query_name() + " washes " + TP->query_possessive() + 
        " " + arg + ".\n" );
   return( 1 );
}

do_rinse(arg) {
   object *puri_check;
   if ( !arg ) {
      write( "What do you want to rinse?\n" );
      return( 1 );
   }
   else if ( TP->query_ghost() ) {
      write( "As a ghost ?\n" );
      return( 1 );
   }
   if ( arg == "mouth" ) {
      puri_check = present( "puri_check", TP );
      if ( !puri_check ) {
         puri_check = clone_object( PPATH + "puri_check" );
         move_object( puri_check, TP );
      }
      puri_check->set_mouth_rinsed();
      write( "You rinse your mouth. You feel the deities appreciating it.\n" );
   }
   else
      write( "You rinse your " + arg + ".\n" );
   say( TP->query_name() + " rinses " + TP->query_possessive() + 
        " " + arg + ".\n" );

   return( 1 );
}

do_meditate(arg) {
   object *obj;
   if ( TP->query_ghost() && TP->query_religion() == "Amaterasu" ) {
      obj = clone_object( PPATH + "puri_check" );
      move_object( obj, TP );
   }
   else {
      obj = present( "puri_check", TP );
      if ( !obj || !(obj->query_hands_washed()) ||
           !(obj->query_mouth_rinsed()) )
      {
         write( "The deities won't show. Have you done the purification?\n" );
         say( TP->query_name() + " tries to meditate but fails.\n" );
         return( 1 );
      }
   }
   write( "You kneel down and begin to meditate.\n" );
   say( TP->query_name() + " kneels down and begins to meditate.\n" );
   obj->start_meditate();
   return( 1 );
}

do_sacri(arg) {
   int almondCount, i;
   object *inv;
   string preli;
   almondCount = 0;
   if ( !arg ) {
      write( "What do you want to sacrifice.\n" );
      return( 1 );
   }
   else if ( TP->query_religion() == "Amaterasu" ) {
      write( "You are already a follower of Amaterasu, so there is no need to\n"
             + "sacrifice something.\n" );
      return( 1 );
   }
    else if (TP->query_guild() != NINJA && TP->query_level() > 10)
    {
      write("Amaterasu tells you: I only accept ninjas as followers !\n");
      return 1;
    }
   if ( arg == "almond" || arg == "almonds" ) {
      inv = all_inventory( TP );
      for ( i = 0; i < sizeof( inv ); i++ )
         if ( inv[i]->id("almond") )
            almondCount++; 
      if ( almondCount < 7 ) {
         write( "You try to sacrifice " + arg + ", but nothing happens.\n" );
         return( 1 );
      }
      preli = TP->query_religion();
      if(RLM->query_church(preli)->leave_religion(preli)) {
         inv = all_inventory( TP );
         for ( i = 0; i < sizeof( inv ); i++ )
            if ( inv[i]->id("almond") )
               destruct( inv[i] ); 
         write( "You sacrifice your almonds ...\n" +
                "You feel Amaterasu looking at you and accept your sacrifiction.\n"
                + "You now believe in Amaterasu.\n" );
         say( TP->query_name() + " sacrificed some almonds.\n" );
         TP->set_religion( "Amaterasu" );
      }
   }
   else
      write( "You try to sacrifice " + arg + ", but nothing happens.\n" );
   return( 1 );
}
