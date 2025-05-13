inherit "obj/monster";
object sword;

void reset(int arg){
    ::reset(arg);
    if(arg) return;
    set_name("shiriff");
    set_race("hobbit");
    set_gender(1);
    set_size(2);
    set_level(4);
    set_short("A shiriff");
    set_long(
      "The shiriff is a hobbit of average height who stands\n"+
      "about looking important and trying to give the impression\n"+
      "of being someone of importance who is busy. The short little\n"+
      "fellow carries around a sword which looks more like a large\n"+
      "dagger which he wields almost awkardly.\n");
    add_money(35);
    set_hp(60);
    move_object(clone_object("/players/colossus/mearth/shire/sword"), this_object());
    init_command("wield sword");
}
