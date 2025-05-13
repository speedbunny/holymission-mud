inherit "room/room";

#include "/players/tamina/defs.h"

object mammoth, tusk;

void reset(int arg) 
{
    mammoth = clone_object("obj/monster");

    mammoth->set_name("wooly mammoth");
    mammoth->set_race("mammoth");
    mammoth->set_gender(1);
    mammoth->set_long("A big hairy Mammoth.\n");
    mammoth->set_level(13);
    mammoth->set_wc(30);
    mammoth->set_ac(5);
    mammoth->set_aggressive(1);
    mammoth->set_whimpy(25);

    tusk = clone_object("obj/weapon");

    tusk->set_name("sharp tusk");
    tusk->set_alias("tusk");
    tusk->set_short("A Sharp Tusk");
    tusk->set_long("A very sharp Mammoth's tusk.  It is about 2 feet long.\n");
    tusk->set_class(14);
    tusk->set_weight(3);
    tusk->set_value(750);

    transfer(tusk, mammoth);
    command("wield tusk", mammoth);

    if (!present("wooly mammoth"))
      move_object(mammoth, this_object());

    if (arg) return 0;

    set_light(1);
    short_desc = "Frozen Wasteland";
    long_desc =
"There is nothing as far as the eye can see\n"+
"except snow and ice.\n";

    dest_dir = ({
  TCOLD + "snow", "north"
    });

}
