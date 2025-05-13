inherit "room/room";

#include "/players/skeeve/area.h"

reset(arg) {
  if (!arg)  {
    set_light(1);
    short_desc = "pasture";
    long_desc = 
         "A green pasture with some fine food for animals.\n"
        +"The path goes across the pasture.\n";
    smell = "You smell the aroma of cows";
    dest_dir = ({
        LAND + "meadow1", "east",
        LAND + "path3", "north",
        LAND + "forest1", "west",
       });
    items = ({
      "forest", "Birds are singing and the wind plays in the trees",
      "shore",  "Behind the shore beginns the sea",
      "path",   "The path continues to south and west"
    });
  }
  create_cow();
  create_bull();
  CASTLE->add_sphinx_obj("horseshoe",this_object());
}

create_cow() {
  int i;
  if (!present("cow",this_object()))
    for (i=0;i<2;i++) {
      transfer(clone_object(MONSTERS + "cow"),this_object());
} }

create_bull() {
  object bull;
  if (!present("bull",this_object())) {
    bull= clone_object("obj/monster");
    bull->set_name("bull");
    bull->set_short("A big and aggressive bull");
    bull->set_long("The bull guards his cows!\n");
    bull->set_level(7);
    bull->set_hp(200);
    bull->set_sp(0);
    bull->set_al(-0);
    bull->set_wc(8);
    bull->set_ac(5); 
    bull->set_aggressive(1);
    bull->set_wimpy(-1);
    bull->set_size(3);
    bull->set_gender(1);
    transfer(bull,this_object());
} }
