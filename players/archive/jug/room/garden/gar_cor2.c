/*Room description corrected by Silas*/
inherit "room/room";

object mole1;
int i;

reset(arg) {

    if( !mole1 ) {
	for(i = 0;i < 2;i++) {
	    mole1 = clone_object("players/jug/monster/mole");
	    transfer(mole1, this_object());
	}
    }

    if(arg) return;
    set_light(1);
    short_desc = "Garden corridor";
    long_desc = 
    "You are on the path leading into the garden. Before you you can see a\n"+
    "passage entering the hedge to your left. Could this be a way into the\n"+
    "garden? Here you can see some strange heaps of earth on both sides of the\n"+
    "path. These could have been made by the moles the gardener was speaking about.\n"+
    "Perhaps you could catch one or two of them, helping the gardener to keep\n"+
    "them out of his garden.\n";
    dest_dir = ({
      "/players/jug/room/garden/gar_cor3", "west",
      "/players/jug/room/garden/gar_cor1", "east",
    });
}
