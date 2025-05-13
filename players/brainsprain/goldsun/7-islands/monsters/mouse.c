inherit "/obj/monster";

void reset(int arg)
 {

 ::reset(arg);
if (arg) return;
set_name("mouse");
set_race("animal");
set_short("A white mouse");
set_long(
"A small white mouse scurries around the room.  Its little pink nose "+
"wrinkles as it constantly smells for enemies or food.  Its tail drags "+
"behind it leaving a strange trail which is meant to confuse predators.\n");
set_level(2);
set_gender(2);
set_wc(5);
set_ac(1);
set_size(2);
}

