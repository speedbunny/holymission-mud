#define PPATH "/players/tatsuo/ezo/cave/"

inherit "/players/tatsuo/ezo/cave/genCave";
object mob;
reset(arg) {
   set_caltrops_chance( 10 );
   ::reset( arg );
   if(!mob) {
      mob = clone_object("/players/tatsuo/eastMonst/yokai");
      move_object(mob,this_object());
   }
   if(arg) return;
   dest_dir=({
	PPATH + "cave23","east",
	PPATH + "cave28","southeast",
	PPATH + "cave21","west",
   });
}
