#define PPATH "/players/tatsuo/ezo/cave/"

inherit "/players/tatsuo/ezo/cave/genCave";
reset(arg) {
   set_caltrops_chance( 5 );
   set_monster( 10, "shikome" );
   ::reset( arg );
if(arg) return;
   dest_dir=({
	PPATH + "cave11","north",
	PPATH + "cave17","southeast",
	PPATH + "cave10","northwest",
   });
}
