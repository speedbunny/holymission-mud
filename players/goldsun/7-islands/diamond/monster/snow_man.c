inherit "/obj/monster";

void reset(int arg)
 {
 ::reset(arg);
if (arg) return;
set_name("snow man");
set_alias("man");
set_race("snowman");
set_short("A white snow man");
set_long("A snow man built by Sighart. It is 10 feet high.\n");
set_level(60);
set_wc(65);
set_ac(10);
set_size(3);
set_hp(query_hp()+1200);
add_money(12000);   /* money are hidden in the snow 'giggle' */
}

string query_plural(){ return "snow men"; }
