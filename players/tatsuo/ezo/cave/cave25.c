#define PPATH "/players/tatsuo/ezo/cave/"

inherit "/players/tatsuo/ezo/cave/genCave";
reset(arg) {
   set_caltrops_chance( 60 );
   set_monster( 50, "shikome" );
   ::reset( arg );
   if(arg) return;
   dest_dir=({  PPATH + "cave31","southwest",  });
}
