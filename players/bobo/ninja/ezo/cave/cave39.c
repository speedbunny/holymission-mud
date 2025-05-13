#define PPATH "/players/tatsuo/ezo/cave/"

inherit "/players/tatsuo/ezo/cave/genCave";
object mob;
reset(arg) {
   set_caltrops_chance( 100 );
   ::reset( arg );
   if(!mob) {
       mob = clone_object("/players/tatsuo/eastMonst/yokai2");
      move_object(mob,this_object());
    }
   if(arg) return;
   dest_dir=({  PPATH + "cave38","west",  });
}
