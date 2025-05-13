
#pragma strict_types
/* secret_police/cell.c */
// whisky  to room/room 
// Kasgaroth: strict_types, closure for speed, etc. still don't like it

inherit "/room/room";

closure call;
object spy;
string *function, *type, *match;

void reset(int arg)
{
    call = #'call_other;
    function = allocate(2);
    type = allocate(2);
    match = allocate(2);

    function[0] = "handle_say";
    type[0] = "says";
    match[0] = "";
    type[1] = "tells you:";
    match[1] = " ";

    if (!spy) 
    {
	spy = clone_object("obj/monster");
	apply(call,spy,"set_name","spy");
	apply(call,spy,"set_alias","enemy spy");
	apply(call,spy,"set_short","An enemy spy");
	apply(call,spy,"set_long","This is enemy spy has been arrested by the Secret Police." +
	  "  His shifty, devious eyes dart about quickly.\n");
	apply(call,spy,"set_level",3);
	apply(call,spy,"set_hp",100);
	apply(call,spy,"set_al",-300);
	apply(call,spy,"set_male");      
	apply(call,spy,"set_spell_mess1","As the spy kicks at his opponent, you notice a tiny dagger in his boot tip.");
	apply(call,spy,"set_spell_mess2","The spy kicks you with a dagger-tipped boot.");
	apply(call,spy,"set_chance",20);
	apply(call,spy,"set_spell_dam",20);
	apply(call,spy,"load_chat",({10,
	    ({
	      "The enemy spy glares at you.\n",
	      "The enemy spy says nothing.\n",      
	    })
	  }));
	apply(call,spy,"set_match",this_object(),({function,type,match}));

	move_object(spy, this_object());
    }

    if (!arg)
    {
	set_light(1);
	dest_dir = 
	({
	  "players/padrone/secret_police/interrogation_room", "east",
	});
	short_desc = "A barren cell";
	long_desc =
	"Shackles and chains cover the walls and ceiling.  "
	"This small room appears to be used by the Secret Police to " +
	"hold spies and dangerous criminals.\n";
    }
}

void handle_say(string str)
{
    string who, junk;
    object client;

    if ((sscanf(str, "%s say%s\n", who, junk) != 2)
      && (sscanf(str, "%s tell%s\n", who, junk) != 2))
	return 0;

    else 
    {      
	client = present(lower_case(who), environment(spy));
	if (client)  
	{
	    say("The spy says: You lying dog!\n");
	    apply(call,spy,"attacked_by",client);
	}
    }
}

