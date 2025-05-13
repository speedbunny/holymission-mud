
/* secret_police/interrogation_room.c */

inherit "/room/room";
#include "/obj/door.h"

closure call;           /* Pointer to call_other for speed */
object obj_1, obj_2;    /* Used by the MAKE_DOORS macro */
object spm, sps;

void reset(int arg)
{
    object obj, key;
    if(!arg)
    {
	call = #'call_other;
	set_light(1);
	dest_dir =
	({
	  "players/padrone/secret_police/cell", "west",
	  "players/padrone/secret_police/hall", "east",
	});
	short_desc = "The Police Interrogation Room";
	long_desc =
	"The Police Interrogation Room.\n"
	+ "A dim and barren, gray square cubicle, lacking any windows,\n"
	+ "ideal for its purpose.\n";
	MAKE_DOORS("players/padrone/secret_police/interrogation_room", "west", "players/padrone/secret_police/cell", "east", "cell", "celldoor", "This is a thickand solid door with iron hinges.\n", 1, 1, 1)
    }
    else
    {
	if (!obj_1)
	    obj_1 = present("door",this_object());
	if (obj_1)
	{
	    apply(call,obj_1,"set_closed",1);
	    apply(call,obj_1,"set_locked",1);
	    apply(call,obj_1,"set_both_status");
	}
    }

    if (!sps)
    {
	sps = clone_object("obj/monster");
	apply(call,sps,"set_name","police sergeant");
	apply(call,sps,"set_alias","sergeant");
	apply(call,sps,"set_short","A police sergeant");
	apply(call,sps,"set_long",
	  "This ugly brute makes you glad you are not a prisoner.\n");
	apply(call,sps,"set_level",5);
	apply(call,sps,"set_hp",200);
	apply(call,sps,"set_al",50);
	apply(call,sps,"set_male");
	apply(call,sps,"set_spell_mess1",
	  "The police sergeant kicks his opponent with a dagger-tipped boot");      apply(call,sps,"set_spell_mess2",
	  "The police sergeant kicks you with a dagger-tipped boot");
	apply(call,sps,"set_chance",20);
	apply(call,sps,"set_spell_dam",10);
	apply(call,sps,"set_aggressive",1);

	move_object(sps, this_object());

	obj = clone_object("players/padrone/secret_police/membership");
	move_object(obj, sps);

	obj = clone_object("obj/weapon");
	apply(call,obj,"set_name","short sword");
	apply(call,obj,"set_alias","shortsword");
	apply(call,obj,"set_alt_name","sword");
	apply(call,obj,"set_class",15);
	apply(call,obj,"set_value",700);
	apply(call,obj,"set_weight",2);
	apply(call,obj,"set_short","A short sword");
	move_object(obj, sps);
	apply(call,sps,"init_command","wield short sword");

	MAKE_KEY(key, "cell", "celldoor")
	move_object(key, sps);
    }

    if (!spm)
    {
	spm = clone_object("obj/monster");
	apply(call,spm,"set_name","policeman");
	apply(call,spm,"set_alias","secret policeman");
	apply(call,spm,"set_short","A policeman");
	apply(call,spm,"set_long","The policeman stands alert upon inspection.\n")      ;
	apply(call,spm,"set_level",1);
	apply(call,spm,"set_al",60);
	apply(call,spm,"set_male");
	apply(call,spm,"set_spell_mess1","The policeman throws a quick punch\n");
	apply(call,spm,"set_spell_mess2","The policeman punches you");
	apply(call,spm,"set_chance",10);
	apply(call,spm,"set_spell_dam",10);
	apply(call,spm,"set_spell_mess1","The policeman throws a quick punch\n");
	apply(call,spm,"set_spell_mess2","The policeman punches you");
	apply(call,spm,"set_chance",10);
	apply(call,spm,"set_spell_dam",10);
	apply(call,spm,"set_aggressive",1);

	move_object(spm, this_object());

	obj = clone_object("players/padrone/secret_police/membership");
	move_object(obj, spm);
	apply(call,obj,"set_name","policeman");

	obj = clone_object("obj/weapon");
	apply(call,obj,"set_name","club");
	apply(call,obj,"set_alias","billy club");
	apply(call,obj,"set_class",5);
	apply(call,obj,"set_value",10);
	apply(call,obj,"set_weight",2);
	apply(call,obj,"set_short","A billy club");
	move_object(obj, spm);
	apply(call,spm,"init_command","wield club");
    }
}

