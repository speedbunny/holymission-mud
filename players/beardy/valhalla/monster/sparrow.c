inherit "/obj/monster";
#include "../valhalla.h"

reset(arg) 
{ ::reset(arg);

 set_name("sparrow");
 set_level(7);
 set_size(2);
 set_short("A little sparrow");
 set_long("A cute little bird with brown feathers.\n");
 CO("sparrow_claw");
 init_command("wield claw");

}
