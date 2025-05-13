inherit "/obj/monster";

void reset(int arg)
 {
 load_chat(25,({"Toad says: Hribit. Hribit.\n"}));

 ::reset(arg);
if (arg) return;
set_name("toad");
set_race("frog");
set_short("An ugly toad");
set_long(
"An ugly little toad is covered in muck and contently croaks.  He occasionally "+
"sticks out his tongue snagging an errant fly.  One would expect that he hops "+
"around, at least once in a while, yet he looks like he has been here forever.\n");
set_level(5);
set_frog(1);
set_wc(3);
set_ac(1);
set_al(-30);
set_size(1);          
}
