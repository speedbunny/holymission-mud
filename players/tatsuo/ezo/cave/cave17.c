#define PPATH "/players/tatsuo/ezo/cave/"

inherit "/players/tatsuo/ezo/cave/genCave";
reset(arg) {
   set_caltrops_chance( 5 );
   ::reset( arg );
   set_monster( 20, "mukade" );
   if(arg) return;
   dest_dir=({
	PPATH + "cave14","north",
	PPATH + "cave21","south",
	PPATH + "cave13","northwest",
   });
}
