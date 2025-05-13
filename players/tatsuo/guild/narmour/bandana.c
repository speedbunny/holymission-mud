
/* Bandana for Ninja Guild */
/* Coded and Created: Gambit */
/* Original Code by Whisky for Monks */
/* Guild - Head Bands */

#define FILE "/players/tatsuo/guild/narmour/bandana"

inherit "/obj/armour";

void reset(int flag)
{
    ::reset(flag);
    if (flag == 0)
    {
	set_name("hachamaka");
	set_alias("bandana");
	set_weight(0);
	set_size(0);
	set_value(15);
        set_long(
            "The famous hachamaka of the Ninjas of the Lin Kuei clan.\n" +
            "The Hachamaka is a long cloth, that is wrapped around the top\n" +
            "part of the head and is tied off in the back.\n" +
            "'Hachamaka' is the japanese word for 'Bandana'.\n");
	set_type("helmet");
	set_ac(1);
    }
}

int query_ninja_wear()
{
    return 1;
}

void init()
{
    int lev;

    ::init();

    if (interactive(this_player()) && this_player()->query_guild()!=8)
    {
        write("Your bandana vanishes.");
	destruct(this_object());
    }
}

string short()
{
    int lev;
    string col;

    lev = 0;

    if ( objectp(environment()) && living(environment()) )
	lev = environment()->query_level();

    if (lev < 5)        
	col = "white";
    else if (lev < 10)
	col = "yellow";
    else if (lev < 15)
	col = "orange";
    else if (lev < 20) 
	col = "blue";
    else if (lev < 23)
	col = "green";
    else  if (lev < 26) 
	col = "brown";
    else if (lev < 28)
	col = "black";
    else if (lev < 29)
	col = "red";
    else
	col = "red and white";

    if (query_worn())
	return col + " "+query_name()+" (worn on head)";
    return col + " "+query_name();
}

drop()
{
    /*
     if (objectp(this_player()) && interactive(this_player()) )
    {
      call_out("dest_me",0,this_object());
     return 0;
     */
    write("If you want to dishonor your clan type 'junk bandana'.");
    return 1;
}

void dest_me(object mob)
{
    if ( !environment() || !living(environment()) )
    {
        write("Your bandana magically vanishes.");
	destruct(this_object());
    }
}

string query_auto_load()
{
    return FILE+":";
}
