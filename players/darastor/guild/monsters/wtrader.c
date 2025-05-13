
/* Weapon Trader */

inherit "obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) return;

    set_name("stormlord");
    set_short("Stormlord");
    set_long("Stormlord is the weapon trader for the barbarian camp. He used\n"
    +"to be the top leader of the barbarians until he was hit by lightning in\n"
    +"a battle. This is were he got the nickname 'Stormlord'.\n");

    set_level( 60 + random(20) );
    set_hp(3000);
    set_gender(1);
    set_ac(10);
    set_wc(50);
    set_number_of_arms(3);
    set_race("crom");

    load_chat(20,({
	("Stormlord stacks weapons up on the tables and racks.\n"),
	("Stormlord says: What can me sell to you ?\n"),
	("Stormlord cleans some weapons with spit to make them shine.\n"),
	("Stormlord growls at you.\n"),
      }));

    load_a_chat (22,({
	("Stormlord growls and starts bashing you hard !\n"),
	("Stormlord cracks his knuckles on your face !\n"),
	("Stormlord growls: This is fucken easy !\n"),
      }));

}
