#define PPATH "/players/tatsuo/ezo/cave/"

inherit "/players/tatsuo/ezo/cave/genCave";
reset(arg) {
   set_caltrops_chance( 10 );
   ::reset( arg );
   if(arg) return;
   dest_dir=({
	PPATH + "cave28","east",
	PPATH + "cave26","west",
   });
}
