inherit "/obj/monster";

void reset(int arg)
 {
 ::reset(arg);
if (arg) return;
set_name("snow man");
set_alias("man");
set_race("snowman");
set_short("Snowman");
set_long(
"This large snowman seems to have been made from fresh snow.  Someone has "+
"put pieces of coal on its face to make eyes and a mouth.  A carrot was used "+
"to make its nose.  It appears that this snowman has somehow come to life.\n");
set_level(60);
set_wc(65);
set_ac(10);
set_size(3);
set_hp(query_hp()+1200);
}

string query_plural(){ return "snowmen"; }
