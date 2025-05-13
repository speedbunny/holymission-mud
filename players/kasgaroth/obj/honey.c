inherit "obj/food";

reset(str) {
    ::reset(str);
    if(str) return;
    set_name("honey");
    set_short("A honey portion");
    set_long("A small portion of thick, sweet honey, which you seem to "
      +"recall is the\ngardener's favorite.\n");
    set_eater_mess("Yummm, that tastes fine.\n");
    set_eating_mess(" schlabbers a delicious honey\n");
    set_strength(1);
    set_value(5);
    set_weight(1);
}
