/* Colossus 081494: Removed the cloning of the key as it */
/* was a nonexistent file and was causing bugs in the room */

inherit"room/room";
int num;
object app,key;
reset (arg) {
    if (!random(3) && !app) {
	app=clone_object("obj/monster");
	app->set_name("apparition");
	app->set_short("Apparition");
	app->set_long("This is a soul which is at unrest\n");
	app->set_level(17);
	/*
			key=clone_object("players/warlord/drac/key");
			transfer(key,app);
		*/
	app->set_whimpy(1);
	transfer(app,this_object());
    }
    if (arg) return;
    set_light(1);
    short_desc="Spooky room\n";
    long_desc="You have entered a spooky room. You can feel a presence somewhere\n"+
    "near you.\n";
    dest_dir=({
      "players/warlord/drac/a6","west",
      "players/warlord/drac/a4","south",
      "players/warlord/drac/a12","north",
    });
}
