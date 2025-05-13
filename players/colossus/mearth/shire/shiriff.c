inherit "obj/monster";
object sword;

reset(arg) {
    ::reset(arg);
    if(arg) return;
    set_name("shiriff");
    set_race("hobbit");
    set_gender(1);
    set_size(2);
    set_level(4);
    set_short("A sheriff");
    set_long(
      "This is a sheriff who's duty is to keep law and order in the Shire\n"+
      "and also here to enjoy the festivities while he's at it.\n"+
      "He wear a Robin Hood style cap with a red feather in it and\n"+
      "looks at you with slight suspicion.\n");
    add_money(25);
    set_hp(60);
    move_object(clone_object("/players/colossus/mearth/shire/sword"), this_object());
    init_command("wield sword");
}
