#define PPATH "/players/tatsuo/ezo/cave/"

inherit "/players/tatsuo/ezo/cave/genCave";
object mujina;
reset(arg) {
   set_caltrops_chance( 80 );
   if ( !mujina || !(present("mujina", this_object())) ) {
      mujina = clone_object( "/players/tatsuo/eastMonst/mujina" );
      transfer( mujina, this_object() );
   }
   ::reset( arg );
   if ( arg ) return;
   set_light(1);
   dest_dir=({
	PPATH + "cave17","south",
	PPATH + "cave11","northwest",
   });
}
