inherit "room/deathtrap";

void reset(int tick)
{ 
  ::reset(tick);
  set_light(0);
  short_desc=
	"A well.",
  long_desc=
	"A well.\n"+
	"	Now you have reached the bottom of the well and\n" +
	"are swimming in a sort of slime. As you try to step onto\n"+
	"the ground you feel that this room has no bottom at all\n"+
	"and therefore you fall and fall and fall ...\n" +
	"Perhaps you should quickly go up.\n";
  
  if ( tick > 0 )  return;

  dest_dir=({ "/players/beardy/valhalla/room/well004","up"});
  
  set_time_to_trigger( 10 );
  set_dt_msg( "Suddenly the ceiling collapses and buries you ...\n" );
}
