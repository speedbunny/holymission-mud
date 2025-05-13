#include "../monkway.h"
inherit "obj/armour";


init() {
  ::init();
  add_action("read","read");
}
remove(arg) {
  if (!id(arg)) return 0;
  write("You try and try, but the ring won't slip from your finger.\n");
  return 1; 
 }
     

read(str) {
  if (str=="inscription") {
     if (TP->query_wis() < 25) {
       write("T %h is m & %m a ic s al Y. I{ $as St3 g  e!$ght.\n");
     }
     else {
       write("This is a magic ring. It has a strange weight.\n");
      }
    }
  return 1;
}
     
reset(arg) {
  ::reset(arg);
  if (!arg) {
     set_id("mring");
     set_alias("ring");
     set_type("ring");
     set_short("A small, strange light ring");
     set_long("A strange ring with an inscription on it.\n");
     set_ac(0);      
     set_value(200);
  }
}
drop() { 
  if (worn) {
   write("You try and try, but the ring won't slip from your finger.\n");
  return 1;
   }
 return;
 }
query_quest_item() { return 1; }
