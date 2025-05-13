

/* amulet2 */

inherit "obj/armour";

void reset(int arg) 
{
    ::reset(arg);
    if (arg!=0) return;
    set_name("amulet of protection");
    set_alias("amulet");
    set_type("amulet");
    set_short("Amulet of Protection");
    set_long("This is a amulet of protection.  You look into the \n" +
      "amulet and see a swirling grey image.\n");
    set_ac(1);
    set_weight(2);
    set_size(0);
    set_value(6000);
}

// overwriting the wear function * hehe *

int wear(object ob) 
{
    object shad;

    if (::wear(ob))
    {
	shad = clone_object("/players/gambit/armour/amulet_shad");
	shad->start_shadow(this_player(),0,"amulet_shad");
	write("You feel your body become less solid !\n");
    }
    return 1;
}

// overwriting the remove function 

int remove(string arg)
{
    if (::remove(arg))
    {
	if (this_player()->amulet_shad())
	    destruct(this_player()->amulet_object());
	write("You feel your body become more solid again !\n");
    }
    return 1;
}

// calling the remove function 

int drop(string arg)
{
    if (this_player()->amulet_shad())
	destruct(this_player()->amulet_object());
    write("You feel your body become more solid again !\n");
    return ::drop();
}
// its magic so anyone can wear it 

int query_mage_wear()
{
    return 1;
}

int query_monk_wear()
{
    return 1;
}

int query_ninja_wear()
{
    return 1;
}
