#define PPATH "/players/tatsuo/ezo/cave/"

inherit "/players/tatsuo/ezo/cave/genCave";
reset(arg) {
   set_caltrops_chance( 80 );
   set_monster( 100, "mukade" );
   ::reset( arg );
if(arg) return;
   dest_dir=({
	PPATH + "cave14","southeast",
	PPATH + "cave13","south",
   });
}
