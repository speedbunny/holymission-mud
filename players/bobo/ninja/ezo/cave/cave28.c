#define PPATH "/players/tatsuo/ezo/cave/"

inherit "/players/tatsuo/ezo/cave/genCave";
reset(arg) {
   set_caltrops_chance( 40 );
   ::reset( arg );
   if(arg) return;
   dest_dir=({
	PPATH + "cave23","north",
	PPATH + "cave33","south",
	PPATH + "cave27","west",
	PPATH + "cave22","northwest",
   });
}
