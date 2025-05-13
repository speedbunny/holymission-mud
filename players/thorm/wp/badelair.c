// badelair.c  ( Length: 0.5m; Mass: 1.2kg; Origin: European 16th century )
// (c) by Thorm in 01.05.1995

#include <std.h>
inherit WEAPON;

create() {
  ::create();
  set_name("badelaire");
  set_id( ({ "badelaire" }) );
  set_short("a badelaire");
  set_long("The sword has a very heavy, curved blade with well\n " +
           "crafted S-shape quillons above the short handle.\n" +
           "It weighs more than a kilogram and is about a half\n" +
           "meter in length." );
  set_ac(0);
  set_wc(15);
  set_hit( (: this_object(), "weapon_hit" :) );
  set_value(175);
  set_weight(650);
  set_type("blade");
  set_wield( "This fine blade really suits you!" );
}

int weapon_hit(object ob) {
    int i;

    i=random(100);
    if ( i > 75 ) {
      tell_object(this_player(),"The thick blade of your sword makes a strange sound as you aim\n"+
                  "a heavy blow at "+ ob->query_name() + ".");
      say (this_player()->query_cap_name()+"'s badelaire strikes down cleaving the air."
           ,this_player());
      return random(25);
    }
    else return (0);
}
