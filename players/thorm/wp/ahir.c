// ahir.c ( Length: 1.0m; Mass: 1.4kg; Origin: Mahrattan sword )
// (c) by Thorm in 01.05.1995

#include <std.h>
inherit WEAPON;

create() {
  ::create();
  set_name("ahir");
  set_id( ({ "ahir" }) );
  set_short("An Ahir");
  set_long("This sword is curved and has a padded hilt.\n" +
           "Its length is close to one meter and the blade\n" +
           "itself is made of fine steel." );
  set_ac(1);
  set_wc(15);
  set_hit( (: this_object(), "weapon_hit" :) );
  set_value(160);
  set_weight(700);
  set_type("blade");
  set_wield( "You proudly grab the ahir." );
}

int weapon_hit(object ob) {
    int i;

    i=random(100);
    if ( i > 75 ) {
      tell_object(this_player(),"Your opponent groans with pain as the cold steel of the ahir\n"+
                                "cuts into its muscles.");
      say (ob->query_cap_name()+" groans painfully as " +
           this_player()->query_cap_name() + "'s ahir cuts into its flesh."
           ,this_player());
      return random(20);
    }
    else return (0);
}
