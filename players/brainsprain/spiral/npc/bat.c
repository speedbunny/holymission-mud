
inherit "obj/monster";
void reset(int arg) {
    ::reset();
    set_name("bat");
    set_race("bat");
    set_gender(1);
    set_alt_name("fruit bat");
    set_alias("bat");
    set_short("Fruit bat");
    set_long(
"A small fruit bat.  His thin wings beat soundlessly as he flies across "+
"the room.  He opens his mouth and screams silently as he navigates his "+
"way sightlessly past all obstacles.  His furry, little head bobs back and "+
"forth as he grabs insects out of the air.\n");
    set_level(1);
    set_hp(50);
    set_al(10);
    set_ac(0);
    set_wc(5);
    }
