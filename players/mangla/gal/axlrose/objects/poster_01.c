/* Axlrose - Guns N' Roses Poster */
inherit "obj/treasure";

reset(arg) {
    if (arg) return;
    set_name("poster");
    set_alias("G N'R poster");
    set_short("A Guns N' Roses poster");
    set_long("A Guns N' Roses poster of Axl Rose sitting on stage content.  \n"
      +"There is also something written on it.\n");
    set_read("The poster is signed on the bottom : \n"
      +"'To whoever this is...\n"
      +"Loose your Illusions.....\n"
      +"  Love, W. Axl Rose '94 '\n");
    set_value(500);
    set_weight(1);
}
