/* Edited by kryll to work. Was bugged to hell. */
#define PATH "/players/whisky/seaworld/room/"
inherit "/room/room";

reset(arg) {
    if (arg) return;
    set_light( 1);
    short_desc= "In Dimpfelmosers bar";
    long_desc =
      "You have entered what used to be the inn of the cider "+
      "landlord Alois Dimpflmoser. The friendly fat man is still "+
      "here, but no longer serves anything, as business was bad. "+
      "There are some garden benches with which to sit upon, and "+
      "some wooden tables too. You can see a little sign hanging "+
      "on the house wall.\n";
    dest_dir =({PATH+"sea_way2","south"});
    items = ({
      "sign","A metallic sign, with the menu written on it", 
      "benches","Brown garden benches, inviting you to sit down",
      "alois","Alois the fat cider landlord seving you drinks"
    });

    clone_list=({
    1,1,"galonhel","/players/whisky/seaworld/monster/galonhel",0,
    2,1,"box","/players/whisky/seaworld/obj/slot_machine",0,
    3,1,"letter","/players/whisky/quest/obj/letter",0,
    });
    ::reset();
}
init() {
    ::init();
    add_action("read","read");
    add_action("sit","sit");
}
read(str) {
    if (str=="sign" || str=="menu") {
      write("Out of business. Nothing sold here!\n");
	return 1;
    }
    notify_fail("Read what?\n");
  return 0;
}
sit(str) {
    if (str=="bench") {
	write("You sit down comfortably on the garden bench.\n");
	say(this_player()->query_name()+" sits confortable down the bench.\n");
	return 1;
    }
    notify_fail("Sit where?\n");
    return 0;
}





query_property()
{
    return "no_clean_up";
}
