// babanga.c ( Length: 0.6m; Mass: 1.2kg; Origin: African )
// (c) by Thorm in 01.05.1995

#include <std.h>
inherit WEAPON;

create() {
  ::create();
  set_name("babanga");
  set_id( ({ "babanga" }) );
  set_short("A Babanga");
  set_long("This average length sword consists of a metal\n " +
           "leaf-shaped blade fitted onto a wooden hilt.\n" +
           "It seems to weigh a bit more than one kilogram." );
  set_ac(0);
  set_wc(13);
  set_hit( (: this_object(), "weapon_hit" :) );
  set_value(100);
  set_weight(390);
  set_type("blade");
  set_wield( "You feel the pure power of nature as you wield the weapon." );
}

int weapon_hit(object ob) {
    int i;

    i=random(100);
    if ( i > 75 ) {
      tell_object(this_player(),"You let the ancient rhythm of tin-pans " +
                  "swirgling in your mind lead your hand.\n");
      say (this_player()->query_cap_name()+"'s babanga seems to take control "+
           "over its owner's body for a second."
           ,this_player());
      return random(20);
    }
    else return (0);
}
 