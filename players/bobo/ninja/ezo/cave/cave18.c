#define PPATH "/players/tatsuo/ezo/cave/"

inherit "/players/tatsuo/ezo/cave/genCave";
reset(arg) {
   set_caltrops_chance( 30 );
   ::reset( arg );
   if(arg) return;
   dest_dir=({
	PPATH + "cave15","north",
	PPATH + "cave19","east",
	PPATH + "cave23","southeast",
   });
}
