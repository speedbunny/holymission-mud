#include "/players/redsexy/defs.h"
inherit "obj/thing";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("geoscanner");
  set_alias("scanner");
  set_short("Test Geoscanner");
  set_long("Scans the Geoenv");
}

init() {
   geoscan();
   add_action("_doit", "doit");
  ::init();
}

_doit(arg) {
	      geoscan();
	      return 1;
}

geoscan() {
string geoenv;

geoenv= E(TP)->long_desc();

if(TP->query_ghost()) {
    write("You scan your environment, but feel no purpose to it.\n");
    return 0;
  }

if (sscanf(E(TP)->long_desc(),"chair")){
    write ("Geoenvironment Found!\n");
    return 1;
}
    write ("Not Found!\n");
}