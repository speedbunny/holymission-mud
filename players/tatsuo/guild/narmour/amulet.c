/* amulet : creator Gambit */

inherit "obj/armour";

void reset( int flag )
{
    ::reset( flag );
    if (flag) return;

    set_name("amulet of amaterasu");
    set_alias("amulet");
    set_short("An amulet of Amaterasu");
    set_long("This is the ancient amulet of Amaterasu. It is rumored "+
      "to protect the followers of Amaterasu wearing the amulet.\n");
    set_type("amulet");
    set_arm_light(1);
    set_ac(1);
    set_size(0);
    set_value(300);
    set_weight(1);
}
query_ninja_wear() { return 1; }

int wear(string arg)
{
    if (this_player()->query_religion()!= "Amaterasu") {
      write("Sorry, but you are not a follower of Amaterasu.\n");
	return 1;
    }
    return::wear(arg);
}
