#define PPATH "/players/tatsuo/ezo/cave/"
inherit "/players/tatsuo/ezo/cave/genCave";
reset(arg) {
   set_caltrops_chance( 100 );
   ::reset( arg );
   if(arg) return;
   dest_dir=({
	PPATH + "cave16","north",
	PPATH + "cave18","west",
   });
}
