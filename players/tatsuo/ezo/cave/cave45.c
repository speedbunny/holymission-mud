#define PPATH "/players/tatsuo/ezo/cave/"

inherit "/players/tatsuo/ezo/cave/genCave";
reset(arg) {
   set_caltrops_chance( 30 );
   set_monster( 10, "shikome" );
   ::reset( arg );
   if(arg) return;
   dest_dir=({
	PPATH + "cave46","east",
	PPATH + "cave44","west",
   });
}
