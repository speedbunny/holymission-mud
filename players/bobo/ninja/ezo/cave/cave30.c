#define PPATH "/players/tatsuo/ezo/cave/"

inherit "/players/tatsuo/ezo/cave/genCave";
reset(arg) {
   set_caltrops_chance( 20 );
   set_monster( 60, "mukade" );
   ::reset( arg );
   if(arg) return;
   dest_dir=({
	PPATH + "cave24","northeast",
	PPATH + "cave31","east",
	PPATH + "cave36","southwest",
   });
}
