/* Item Trader */

inherit "obj/npc";

reset(arg) {
    ::reset(arg);
    if(arg) return;
    set_name("voyeur");
    set_short("Voyeur");
    set_long("Voyeur is the items trader for the tournament. She is very\n"
      +"quiet and does everything to keep her little shop nice and neat.\n"
      +"She feels the nicer the place looks, the more people will come.\n"
      +"Voyeur is a very beautiful woman but is also strong willed and\n"
      +"knows how to sell items.\n");
    set_level( 60 + random(20) );
    set_gender(2);
    set_race("Lin Kuei");
    set_ac(10);
    set_wc(50);
    set_dodge(60);
    set_attacks(5);
    set_attacks_change(55);
    load_chat(20,({
	("Voyeur says: What do you wish to buy ?\n"),
	("Voyeur cleans off her items behind the counter.\n"),
	("Voyeur whistles a happy tune.\n"),
	("Voyeur says: Hello and welcome to my little shop.\n"),
      }));
    load_a_chat (22,({
	("Voyeur jumps back and stands in attack form !\n"),
	("Voyeur yells: Fuck off and die !\n"),
	("Voyeur yells: Don't mess with me, asshole !\n"),
      }));
}
