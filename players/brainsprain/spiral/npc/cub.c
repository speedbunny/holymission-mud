inherit "obj/monster";
void reset(int arg) {
    ::reset(arg);
    set_name("cub");
    set_race("bear");
    set_alt_name("bear");
    set_gender(1);
    set_alias("bear cub");
    set_short("A bear cub");
    set_long(
"This small bear cub rolls around attempting to catch his stubbly "+
"tail.  Despite his size, he could be deadly, after all his teeth are "+
"almost an inch long.  His thick brown fur gleams and and his wet nose "+
"sniffs the air trying to catch an illusive scent.\n");
    set_level(1);
    set_hp(50);
    set_al(10);
    set_ac(0);
    set_wc(5);
    }
