inherit "/obj/monster";

void reset(int arg)
 {

 ::reset(arg);
if (arg) return;
set_name("eel");
set_race("fish");
set_short("A river eel");
set_long(
"A long river eel.  Its snakelike body weaves through the water near your "+
"feet and its head bobs back and forth seeking for something to attach to.  "+
"It lets out a keening scream that shakes the surface of the water.\n");
set_level(7);
set_wc(9);
set_ac(2);
set_size(2);
set_al(-50);
}

