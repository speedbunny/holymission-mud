
inherit "room/room";

void reset(int arg) {
    ::reset(arg);
    if (arg)
	return;
    set_light(1);
    short_desc = "End of Bridge";
    long_desc = 
    "The view from up here is breath-taking.\n";
    items = ({
      "bridge","This crystal bridge shimmers with all the colors of the "
      +"rainbow and\nleads to the seashore below",
      "sign","It glows with a magical white radiance and invites you "
      +"'read' it",
    });
    dest_dir = ({
      "/room/vill_shore2", "down",
    });
}


void init() {
    ::init();
    call_out( "bye",1,this_player() );
}


void bye( object player )
{
    tell_room( this_object(), "You feel a bit dizzy and wisely step down from the bridge.\n" );
    player->move_player( "down#room/vill_shore2" );
}
