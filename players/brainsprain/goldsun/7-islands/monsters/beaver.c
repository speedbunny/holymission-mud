inherit "/obj/monster";

void reset(int arg)
 {

 ::reset(arg);
if (arg) return;
set_name("beaver");
set_race("animal");
set_short("A beaver");
set_long(
"This big, brown beaver wriggles its nose as you enter the area.  It's "+
"sleek fur is wet and plastered to its body, making it look as if it is "+
"wearing armour.  Its tail wavers as it wonders if any enemies are about.\n");
set_level(9);
set_wc(12);
set_ac(5);
set_size(2);
set_aggressive(1);
set_al(-30);
}

