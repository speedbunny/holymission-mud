#define PPATH "/players/tatsuo/ezo/cave/"

inherit "/players/tatsuo/ezo/cave/genCave";
reset(arg) {
   set_caltrops_chance( 50 );
   set_monster( 10, "mukade" );
   ::reset( arg );
   if(arg) return;
   dest_dir=({
	PPATH + "cave45","west",
	PPATH + "cave41","northwest",
   });
}
