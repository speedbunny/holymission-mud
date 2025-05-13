/* CELLAR.C - Programmed by Ethereal Cashimor */
/* 210793: Added toilet */

inherit "players/cashimor/inherit/water";

reset(arg) {
object bucket;

  ::reset(arg);
  if(!arg) {
    set_light(1);
    short_desc="Cellar";
    long_desc="You are in the cellar of a house. There is a well here. Light "
            + "streams down from the stairs.\n";
    items=({"cellar","It's damp here",
            "house","Not clearly visible from this spot",
            "well","A large pool of clear water",
            "stairs","Made of wood, but still sturdy"});
    smell="It's rather fresh here, for a cellar";
    dest_dir=({"players/cashimor/extend/corridor","up",
               "players/cashimor/extend/toilet","east"});
    nodanger=1;
  }
  if(!present("bucket",this_object())) {
    bucket=clone_object("players/cashimor/objects/bucket");
    move_object(bucket,this_object());
  }
}

door_knock() {
  tell_room(this_object(),"You hear someone knocking on the front door.\n");
}
