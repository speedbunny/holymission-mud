#define PPATH "/players/tatsuo/ezo/cave/"

inherit "/players/tatsuo/ezo/cave/genCave";
reset(arg) {
   set_caltrops_chance( 10 );
   set_monster( 30, "mukade" );
   ::reset( arg );
if(arg) return;
   dest_dir=({
	PPATH + "cave8","north",
	PPATH + "cave9","northeast",
	PPATH + "cave15","southwest",
   });
}
