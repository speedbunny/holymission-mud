#define PPATH "/players/tatsuo/ezo/cave/"

inherit "/players/tatsuo/ezo/cave/genCave";
reset(arg) {
   set_caltrops_chance( 50 );
   set_monster( 10, "shikome" );
   ::reset( arg );
   if(arg) return;
   dest_dir=({
	PPATH + "cave5","east",
	PPATH + "cave3","west",
   });
}
