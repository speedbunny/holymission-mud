#define PPATH "/players/tatsuo/ezo/cave/"

inherit "/players/tatsuo/ezo/cave/genCave";
reset(arg) {
   set_caltrops_chance( 10 );
   set_monster( 10, "shikome" );
   ::reset( arg );
  if(arg) return;
   dest_dir=({
	PPATH + "cave28","south",
	PPATH + "cave22","west",
	PPATH + "cave18","northwest",
   });
}
