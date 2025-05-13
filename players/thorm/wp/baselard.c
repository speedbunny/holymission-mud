// baselard.c  ( Length: 0.5m; Mass: 0.6kg; Origin: European 13th century )
// (c) by Thorm in 01.05.1995

#include <std.h>
inherit WEAPON;

create() {
  ::create();
  set_name("baselard");
  set_id( ({ "baselard" }) );
  set_short("A Baselard");
  set_long("It's a thrusting sword with a straight diamond-shaped\n" +
           "blade. It seems rather powerful.\n" +
           "Its not more than a half meter in length and it seems\n" +
           "to be a considerably light weapon." );
  set_ac(0);
  set_wc(13);
  set_hit( (: this_object(), "weapon_hit" :) );
  set_value(187);
  set_weight(400);
  set_type("blade");
  set_wield( "You feel an ancient touch of another time and plane on your hand." );
}

int weapon_hit(object ob) {
    int i;

    i=random(100);
    if ( i > 75 ) {
      tell_object(this_player(),"You thurst towards your enemy with the baselard.");
      say (this_player()->query_cap_name()+" powerfully thrusts at " +
           ob->query_cap_name() + "with the baselard.",this_player());
      return random(35);
    }
    else return (0);
}
