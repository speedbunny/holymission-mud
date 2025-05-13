
inherit "/obj/armour";

void reset(int flag)
{
     ::reset(flag);
     if (flag == 0)
     {
	set_name("Taoist priest's robe");
	set_alias("robe");
        set_short(query_name());
        set_long(
	"A blue silk robe worn by Taoist priests. It has runes drawn all"+
" over the collar. there's a yin-yang symbol on the back of the robe.\n");
	set_type("cloak");
	set_ac(1);
	set_weight(1);
	set_value(500);
     }
}
int query_mage_wear() { return 1; }
int query_ninja_wear() { return 1; }
int query_monk_wear() { return 1; }
int query_summoner_wear() { return 1; }

