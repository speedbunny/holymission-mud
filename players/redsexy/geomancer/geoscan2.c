#include "/players/redsexy/defs.h"
inherit "obj/thing";

string *geoenv;
int i;

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
	      geoscan(arg);
	      return 1;
}

geoscan(arg) {
geoenv= E(TO)->query_long_desc();
for(i = 0; i < sizeof(geoenv); i++)
geoenv = explode(arg, " ");
if(TP->query_ghost()) {
    write("You scan your environment, but feel no purpose to it.\n");
    return 0;
  }

if (sscanf(long_desc,"chair")){
    write ("Geoenvironment Found!\n"+geoenv+"Test\n");
    return 1;
}
    write ("Not Found!\n"+geoenv+"Test\n");
}