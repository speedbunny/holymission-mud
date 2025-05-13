
/* secret_police/sleeping_room.c */

inherit "/room/room"; // whisky 

void reset(int arg)
{
    object spm;
    closure call;

    call = #'call_other;
    if (!spm)
    {
	spm = clone_object("obj/monster");
	apply(call,spm,"set_name","policeman");
	apply(call,spm,"set_alias","secret policeman");
	apply(call,spm,"set_short","A groggy policeman");
	apply(call,spm,"set_long","This policeman, dressed in his pajamas, looks very tired.\n");
	apply(call,spm,"set_level",1);
	apply(call,spm,"set_al",100);
	apply(call,spm,"set_male");
	apply(call,spm,"load_chat",({10,
	    ({ "The officer yawns mightily.\n" })
	  }));

	move_object(spm, this_object());

	move_object(clone_object("players/padrone/secret_police/membership"), spm);
    }
    if (!arg)
    {
	set_light(1);
	dest_dir = ({   "players/padrone/secret_police/hall", "west"  });
	short_desc = "The Barracks";
	long_desc =
	"Efficiency and functionality is the impression you get from the "
	+ "police headquarters.  Narrow bunks arranged in neat rows along "
	+ "the spartan barrack walls and a lack of any ornamentation attest to this "
	+ "observation.\n";  
    }
}

