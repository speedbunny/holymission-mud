#define TP this_player()
inherit "obj/treasure";
     int num;

  reset(arg) {
    if (arg) return;
     
    set_id("keg");
    set_short("A keg of whine");
    set_long("A little barrel of red whine.\n"+
             "There are "+num+" tabs left.\n");
