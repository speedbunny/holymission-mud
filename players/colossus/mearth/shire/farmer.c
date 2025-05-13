inherit "obj/monster";
object hoe;

void reset(int arg){
    ::reset(arg);
    hoe=clone_object("obj/weapon");
    hoe->set_name("hoe");
    hoe->set_short("A hoe");
    hoe->set_long("A hoe used for tilling the land\n");
    hoe->class(11);
    hoe->set_weight(2);
    hoe->set_value(350);
    move_object(hoe, this_object());
    if(arg) return;
    set_name("farmer");
    set_short("A hobbit farmer");
    set_long(
      "Here's a hobbit farmer who's stopping by after a hard day's work\n"+
      "to watch and enjoy the festivities that take place daily at the\n"+
      "party tree. He looks well-built for a hobbit.\n");
    set_level(5);
    set_ac(5);
    set_race("hobbit");
    set_gender(1);
    set_size(2);
    add_money(75);
    set_wc(10);
    command("wield hoe", this_object());
}
