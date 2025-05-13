inherit "/obj/monster";

void reset(int arg)
 {

 ::reset(arg);
if (arg) return;
set_name("turtle");
set_race("animal");
set_short("A sea turtle");
set_long(
"A medium sized sea turtle sits at your feet sunning himself.  Little chips "+
"in his shell are all that mars its shine, polished by the waves of the sea.  "+
"As you look at it in clamps its jaw done hard, making you wary of its strength.\n");
set_level(15);
set_wc(15);
set_ac(13);
set_size(3);
set_gender(2);
set_al(10);
}

