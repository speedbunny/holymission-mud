
/* secret_police/backroom.c */
// whisky to room/room

inherit "/room/room";

void reset(int arg) 
{
    closure call;
    object mob, ob;

    call = #'call_other;
    ::reset(arg);

    if (!present("sp2"))
    {
	mob = clone_object("obj/monster");
	apply(call,mob,"set_name","policeman");
	apply(call,mob,"set_alias","secret policeman");
	apply(call,mob,"set_alt_name","sp2");
	apply(call,mob,"set_short","A policeman");
	apply(call,mob,"set_long","There is something odd about this policeman that you "
	  +"just can't put your finger on.\n");
	apply(call,mob,"set_level",2);
	apply(call,mob,"set_al",80);
	apply(call,mob,"set_male");
	apply(call,mob,"set_spell_mess1","The secret policeman kicks his opponent very hard.");
	apply(call,mob,"set_chance",10);
	apply(call,mob,"set_spell_dam",10);

	move_object(mob, this_object());

	ob = clone_object("players/padrone/secret_police/membership");
	move_object(ob, mob);
	apply(call,ob,"set_name","policeman");

	ob = clone_object("obj/weapon");
	apply(call,ob,"set_name","dagger");
	apply(call,ob,"set_class",6);
	apply(call,ob,"set_value",10);
	apply(call,ob,"set_weight",1);
	apply(call,ob,"set_short","A dagger");
	move_object(ob, mob);
	apply(call,mob,"init_command","wield dagger");
    }

    if (!present("sp1"))
    {      
	mob = clone_object("obj/monster");
	apply(call,mob,"set_name","policeman");
	apply(call,mob,"set_alias","secret policeman");
	apply(call,mob,"set_alt_name","sp1");
	apply(call,mob,"set_short","A policeman");
	apply(call,mob,"set_long","There is something odd about this policeman that you "
	  +"just can't put your finger on.\n");
	apply(call,mob,"set_level",1);
	apply(call,mob,"set_al",60);
	apply(call,mob,"set_male");
	apply(call,mob,"set_spell_mess1","The secret policeman kicks his opponent very hard.");
	apply(call,mob,"set_spell_mess2","The secret policeman kicks you very hard.");
	apply(call,mob,"set_chance",10);
	apply(call,mob,"set_spell_dam",10);

	move_object(mob, this_object());

	ob = clone_object("players/padrone/secret_police/membership");
	move_object(ob, mob);
	apply(call,ob,"set_name","policeman");

	ob = clone_object("obj/weapon");
	apply(call,ob,"set_name","dagger");
	apply(call,ob,"set_class",6);
	apply(call,ob,"set_value",10);
	apply(call,ob,"set_weight",1);
	apply(call,ob,"set_short","A dagger");
	move_object(ob, mob);
	apply(call,mob,"init_command","wield dagger");
    }

    if (!arg)
    {
	set_light(1);
	dest_dir =
	({
	  "players/padrone/secret_police/hall", "north",
	  "players/padrone/secret_police/shop", "south",
	  "players/padrone/secret_police/kitchen", "east",
	  "players/padrone/secret_police/store", "west",
	});
	short_desc ="The back room behind the shop";
	long_desc =
	"You are in the back room behind the shop.  "
	+ "The smells of cooking food drift in from the east.  A door to the west leads to the "
	+ "shop's store room, and to the south is the shop itself.\n";
    }
}

