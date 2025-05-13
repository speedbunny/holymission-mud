#define PPATH "/players/tatsuo/ezo/island_link/"
#define TP  this_player()
#define TPN TP->query_name()
#define TPOBJ  TP->query_objective()
#define TPPOS  TP->query_possessive()
#define TO     this_object()

inherit "/room/room";

int cor, ttc;

reset( arg )
{
   ttc = 0;

   if ( arg )
      return;
      
   set_light(1);
   short_desc = "A neatly chamber";
   long_desc = 
        "This chamber is clearly made by human hands. It lookes more like\n"+
        "a room of a house and not at all like a chamber of a cave. A table\n"+
        "is standing in the middle of the room, with chairs places around it\n"+
        "and a rack is standing in the corner.\n";

   items = ({ "rack", "An old weapon-rack. It is empty",
              "table", "Never seen a table before ?",
              "chair", "Never seen a chair before ?",
              "chairs", "Never seen a chair before ?",
           });

	dest_dir = ({ PPATH + "link11", "west", });

   cor = 0;
}

init()
{
   ::init();

   if ( !present( "cave fisher", this_object() ) && !cor && !ttc ) {
      call_out( "gimme_cf", 15, 0 );
      cor = 1;
   }
}

gimme_cf()
{
   object cc;
   cor = 0;
   ttc = 1;

   cc= clone_object( PPATH+"cave_fisher" );
   if ( cc && !transfer( cc, this_object() ) ) {
      tell_room( TO,"Suddenly a cave-fisher appears out of the ground !!!!\n" );
      tell_room( TO, "The cave-fisher entangled you !!!!\n" );
   }
}
