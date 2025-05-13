
inherit "obj/monster";
void reset(int arg) {
    ::reset(arg);
    set_name("slug");
    set_race("slug");
    set_alt_name("giant slug");
    set_gender(1);
    set_alias("slug");
    set_short("A slug");
    set_long(
"This baby giant slug is about three feet long and is clinging to the "+
"wall.  A slime trail leads from the center of the room to were it rests. "+
"Its eye stalks bob back and forth as it looks around the room.\n");
    set_level(3);
    set_hp(75);
    set_al(-15);
    set_ac(1);
    set_wc(6);
    }
