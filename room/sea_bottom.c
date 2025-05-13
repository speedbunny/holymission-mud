inherit "players/cashimor/inherit/water";

object octopus;

reset(arg) {
  ::reset(arg);
  if(!arg) {
    short_desc="Sea bottom";
    long_desc="You are on the bottom of the sea.\n";
    dest_dir=({"room/sea","up"});
    items=({"sea","It's vibrating with green life"});   
    set_light(1);
  }
  extra_reset();
}

extra_reset() {
    if (!octopus || !living(octopus)) {
	object chest;
	object money;
	octopus = clone_object("obj/monster");
	octopus->set_name("octopus");
	octopus->set_level(9);
	octopus->set_race("fish");  /* grin */
	octopus->set_size(4);
	octopus->set_hp(100);
	octopus->set_wc(12);
	octopus->set_al(-20);
	octopus->set_short("An octopus");
	octopus->set_long("A very big octopus with long arms, reaching for you.\n");
	octopus->set_spell_mess1("The octopus says: Mumble");
	octopus->set_spell_mess2("The octopus says: I will convert you to a pulp!");
	octopus->set_chance(20);
        octopus->set_has_gills();
	move_object(octopus, this_object());
	chest = clone_object("obj/chest");
	move_object(chest, octopus);
        money = clone_object("obj/money");
        money->set_money(random(500));
        move_object(money, chest);
    }
}
