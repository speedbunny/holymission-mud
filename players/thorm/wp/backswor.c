// backswor.c  ( Length: 0.6m; Mass: 0.7kg; Origin: European )
// (c) by Thorm in 01.05.1995

#include <std.h>
inherit WEAPON;

create() {
  ::create();
  set_name("backsword");
  set_id( ({ "backsword" }) );
  set_short("A Backsword");
  set_long("The steel sword consists of a slithly curved blade\n" +
           "and a knuckle guard.\n" +
           "It's about a half meter long and weighs more than a\n" +
           "half kilogram." );
  set_ac(0);
  set_wc(13);
  set_value(140);
  set_weight(400);
  set_type("blade");
  set_wield( "This fine blade really suits you!" );
}
