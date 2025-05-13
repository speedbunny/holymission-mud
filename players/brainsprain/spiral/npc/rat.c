
inherit "obj/monster";
void reset(int arg) {
    ::reset(arg);
    set_name("rat");
    set_race("rat");
    set_alt_name("small rat");
    set_alias("small rat");
    set_short("A small rat");
    set_long(
"This small rat has beady eyes and floppy ears.  His gray fur is matted and "+
"dull. His tail slithers along the floor behind him like a snake as he "+
"searches for something to eat.  His pointy teeth gleam as he snarls at "+
"every perceived threat.\n");
    set_level(1);
    set_hp(50);
    set_al(-10);
    set_ac(0);
    set_wc(5);
    }
