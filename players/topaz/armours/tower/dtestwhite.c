inherit "obj/armour";

#include "/players/topaz/defs.h"

int _wear(string arg) {
  val=query_alignment()
    if(!arg) {
        notify_fail("Wear what?\n");
    }
    if(arg=="crown"||arg=="white crown"||arg=="helmet") {
        if(val>-100) {
            write("The crown is displeased with you!\n" +
                  "You are not evil enough.\n");
            return;
        }
        else {
            write("The crown is pleased with you.\n" +
            command("wear crown");
        }
    }
reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("the White Crown");
  set_short("The White Crown");
  set_long("This is the infamous White Crown!\n" +
           "It is rumoured to grant it's wearer extra strength if\n" +
           "it is pleased by its wearer's actions!\n" +
           "Maybe you could try it on?\n");
  set_alias("crown");
  set_alt_name("white crown");
  set_type("helmet");
  set_ac(1);
  set_weight(2);
  set_value(10000);
}

init() {
  ::init();

    add_action("_wear","wear");
}
