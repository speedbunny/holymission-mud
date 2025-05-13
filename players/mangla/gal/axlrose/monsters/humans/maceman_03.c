/* Axlrose - Human Army */
/* Maceman Soldier - Patrolling */
inherit "/players/axlrose/monsters/patrol_mon";
object armour, helmet, weapon;

reset(arg) {
    ::reset(arg);
    if(arg) return;
    set_name("club wielding peasant");
    set_alt_name("soldier");
    set_alias("peasant");
    set_short("A boastful peasant soldier");
    set_long
    ("A honorable, proud, and supportive peasant from the local lands that \n" 
      +"has taken up arms to defend his country and property.  Besides the \n"
      +"years of working the lands, past dealings with brigands and other \n"
      +"tribes have strengthen his body and skills while also scarring him.\n");
    set_gender(1);
    set_race("human");
    set_level( 15 + random(5) );
    set_str(20);
    set_int(7);
    set_wis(7);
    set_con(20);
    set_aggressive(0);
    set_al(250);
    set_hp( 600 + random(50) );
    set_sp(100);
    set_chance(10);
    set_spell_dam(20);
    set_spell_mess1
    ("With a quick downward swing, the peasant smashes into an opponent's \n"
      +"head, sending forth a vicious spray of blood and tissue everywhere.\n");
    set_spell_mess2
    ("Raising his footman's mace, the peasant soldier slams down onto your \n"
      +"head, rattling your remaining teeth loose.\n");
    set_ac(10);
    set_wc(5);
    set_number_of_arms(2);

    add_money( 30 + random(15) );
    armour = clone_object("/players/axlrose/armours/scale_01");
    transfer(armour,this_object());
    helmet = clone_object("/players/axlrose/armours/helmet_01");
    transfer(helmet,this_object());
    weapon = clone_object("/players/axlrose/weapons/mace_01");
    transfer(weapon,this_object());
    init_command ("powerup");

    load_chat(3, ({
	"'The damn war has ruined this year's harvest of corn and wheat.' says a \n"
	+"peasant as he stares over his burnt and destroyed fields.  \n",
	"'Village to the north, tower to the east, swamps to the south, forests \n"
	+"to the west, and I am in the middle.' exclaims a cornered peasant.  \n",
	"Standing elevated and proud, a peasant smiles and bursts forth, 'I have \n"
	+"seen a dwarf, an elf, and a gnome once!!!'  \n",
	"'We have to defend the village and fields from the hordes.' growls a \n"
	+"peasant as he tightens his grip on his footman's mace.  \n",
	"Grumbling to himself, a peasant murmurs, 'Lousy pay in the people's \n"
	+"army.' as he rattles a nearly empty money pouch.  \n",
      }));

    load_a_chat(5, ({
	"With boastful pride, the peasant rushes forth into the thick of battle, \n"
	+"yelling 'No problem gov'n!!!'  \n",
	"'My cow herds - my wife even - hit harder unarmed than you wimpy!!!'  \n",
	"With some precision, the peasant wields his spiked club threateningly.  \n", 
      }));
}
