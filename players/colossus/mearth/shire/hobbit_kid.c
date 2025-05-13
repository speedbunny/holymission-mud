inherit "obj/monster";

void reset(int arg){
    ::reset(arg);
    if(arg) return;
    set_name("child");
    set_short("A hobbit child");
    set_long(
      "A playful hobbit child who's here enjoying the festivities under the\n"+
      "party tree. He is a tiny and lovable thing you dances around and laughs.\n"+
      "Without doubt he is having the time of his life.\n");
    set_level(3);
    set_hp(35);
    set_al(50);
    add_money(10);
    set_race("hobbit");
    set_gender(1);
    set_size(2);
    set_wc(2);
}
