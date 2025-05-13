

/* filename: jungle.c 
   just inherit this file instead of "/room/room" and do a ::reset(arg)
   after the reset(arg) {     */

inherit "/room/room";

#define SAY(x) tell_room(this_object(),x)

object pl;  /* one objectvar is enough */

void reset(int arg)
{
    if (arg) return;
    enable_commands();
}

void init()
{
    ::init();
    if (interactive(this_player()))
    {
	pl = this_player();

	switch(random(5))
	{
	case 0:
	    SAY("Something behind you screams.\n");
	    break;
	case 1:
	    SAY("Something scurries through the undergrowth.\n");
	    break;
	case 2:
	    SAY("Something growls at you !\n");
	    break;
	case 3:
	    SAY("You hear birds chirp echo all through the jungle.\n");
	    break;
	default:
	    SAY("You feel as something is watching you.\n");
	    break;
	}
	set_heart_beat(1);
    }
}   

void heart_beat()
{
    if (present(pl,this_object()) && interactive(pl))
    {
	if (!random(4))
	{
	    switch(random(5))
	    {
	    case 0:
		SAY("Something behind you screams.\n");
		break;
	    case 1:
		SAY("Something scurries through the undergrowth.\n");
		break;
	    case 2:
		SAY("Something growls at you !\n");
		break;
	    case 3:
		SAY("You hear birds chirp echo all through the jungle.\n");
		break;
	    default:
		SAY("You feel as something is watching you.\n");
		break;
	    }
	}
    }
    else 
	set_heart_beat(0);
}



