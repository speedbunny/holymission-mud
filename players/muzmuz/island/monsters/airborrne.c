inherit "obj/monster";
#include "/players/sourcer/special/block.c"

reset(arg) {
    ::reset(arg);
    if (arg) return;
    block_reset();
    set_name ("Airborne");
    set_alias ("Airborne");
    set_alt_name ("Airborne");
    set_level (23);
    set_wimpy (-1);
    set_gender (0);
    set_short ("A huge sandworm");
    set_long ("A huge brown sandworm. It is aggressive and it looks tough.\n");
    set_chance(10);
    set_spell_mess1("The sandworm winds itself around you and takes your breath !");
    set_spell_mess2("The sandworm spills sand on you ! \n" +
                    "You are hurt seriously !\n");
    set_spell_dam(10+random(10));
    add_money(500+random (500));
}
int do_block()
{
TELL("The Sandworm doesn`t let you go there !\n");
return 1;
}

init() {
  add_action("do_block","hole");
      block_init();
    ::init();
}

