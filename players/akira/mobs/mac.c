inherit "obj/monster";
reset(arg){
    ::reset(arg);

    set_name("MAC II");
    set_short("MAC II");
    set_alias("mac");
    set_long("This is some kind of metal giant. It stands over 80 feet\n"+
      "tall, and looks like it could step on you. Judging from the\n"+
      "size of the projectile lunchers on it, you can image that it\n"+
      "could hti a target from miles away. It doesn't appear to be\n"+
      "moving, although you can here a faint hum comeing from it.\n");
    set_level(40);
    set_number_of_arms(2);
    set_wc(40);
    set_ac(40);
}
