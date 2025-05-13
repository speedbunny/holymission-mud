// alamani.c ( Length: 0.6m; Mass: 0.8kg; Origin: Indian )
// (c) by Thorm in 01.05.1995

#include <std.h>
inherit WEAPON;

create() {
  ::create();
  set_name("alamani");
  set_id( ({ "alamani" }) );
  set_short("An Alamani");
  set_long("This sword must have Indian origin.\n" +
           "It's about a half meter long with curved\n" +
           "blade and a gilt handle." );
  set_ac(0);
  set_wc(10);
  set_hit( (: this_object(), "weapon_hit" :) );
  set_value(100);
  set_weight(450);
  set_type("blade");
  set_wield( "The sword gently slides into your palm." );
}

int weapon_hit(object ob) {
    int i;

    i=random(100);
    if ( i > 75 ) {
      tell_object(this_player(),"You bring the alamani into the Ho-Ra position with a brilliantly \n"+
                                "quick flick of your wrist." );
      say (ob->query_cap_name()+ " tries to cover its torso against " +
           this_player()->query_cap_name() + "'s heavy blows."
           ,this_player());
      return random(20);
    }
    else return (0);
}
