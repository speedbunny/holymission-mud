#define PPATH "/players/tatsuo/ezo/cave/"

inherit "/players/tatsuo/ezo/cave/genCave";
reset(arg) {
   set_caltrops_chance( 0 );
   set_monster( 80, "mukade" );
   ::reset( arg );
   if(arg) return;
   dest_dir=({  PPATH + "cave6","west",  });
}
