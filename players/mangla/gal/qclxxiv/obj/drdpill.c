inherit "obj/treasure";
/* only people not having dreadlocks should be given a herb like this
 * if and only if Rasta Or Qclxxiv decide they should have them.
*/

object dreadlocks;

reset(arg) {
  if(arg) return;
    set_short("Some Very Special Ital Herbs");
    set_long("Very Special Ital Herbs, appearing to be genuine Lambsbread\n"+
             "this one is so hot maybe you should eat it.\n");
set_id("herbs");
  set_value(0);
  set_weight(0);
}
init() {
 ::init();
 add_action("eat","eat");
 
 }
eat(str) {
  if (str!="herbs")  return; 
   write("Mjammmie  that was Iterly Ital, you feel Most Irie\n");
  write("Now you have DreadLocks, and can Iversate on the Rasta Channel.\n");
  say(this_player()->query_name()
			+" eats some Ital Herbs, and gets DreadLocks.\n");
  dreadlocks = clone_object("players/qclxxiv/obj/drdlcks");
  move_object(dreadlocks, this_player());
  destruct(this_object());
 return 1;
 }

