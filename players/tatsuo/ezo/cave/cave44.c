#define PPATH "/players/tatsuo/ezo/cave/"

inherit "/players/tatsuo/ezo/cave/genCave";
reset(arg) {
   set_caltrops_chance( 20 );
   set_monster( 10, "shikome" );
   ::reset( arg );
   if(arg) return;
   dest_dir=({
	PPATH + "cave40","north",
	PPATH + "cave41","northeast",
	PPATH + "cave45","east",
   });
}
