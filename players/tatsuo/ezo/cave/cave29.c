#define PPATH "/players/tatsuo/ezo/cave/"

inherit "/players/tatsuo/ezo/cave/genCave";
reset(arg) {
   set_caltrops_chance( 20 );
   set_monster( 100, "mukade" );
   ::reset( arg );
   if(arg) return;
   dest_dir=({  PPATH + "cave34","south",  });
}
