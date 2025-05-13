// amagoike.c ( Length: 0.4m; Mass: 0.6kg; Origin: Japanese )
// (c) by Thorm in 01.05.1995

#include <std.h>
inherit WEAPON;

create() {
  ::create();
  set_name("ama-goi-ken");
  set_id( ({ "ama-goi-ken","ama" }) );
  set_short("An Ama-Goi-Ken");
  set_long("This Japanese style, less than a half meter\n" +
           "long temple sword represents the rain dragon.\n" +
           "It's a straight bladed sword with double edge." );
  set_ac(0);
  set_wc(12);
  set_value(100);
  set_weight(390);
  set_type("blade");
  set_wield( "As you wield the sword you realize that it's extremly light." );
}
