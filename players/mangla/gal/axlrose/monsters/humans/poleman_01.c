/* Axlrose - Human Army */
/* Polearm Soldier - Stationary */
inherit "obj/monster";
object armour, dagger, helmet, weapon;

reset(arg) {
    ::reset(arg);
    if(arg) return;
    set_name("polearm wielding peasant");
    set_alt_name("soldier");
    set_alias("peasant");
    set_short("A proud peasant soldier");
    set_long
    ("A honorable, proud, and supportive peasant from the local lands that \n"
      +"has taken up arms to defend his country and property.  Years of working \n"
      +"the lands have firmed his body, yet the elements have prematurely aged \n"
      +"his exposed arms, face, and hands.\n");
    set_gender(1);
    set_race("human");
    set_level( 10 + random(5) );
    set_str(15);
    set_int(7);
    set_wis(7);
    set_con(15);
    set_aggressive(0);
    set_al(250);
    set_hp( 250 + random(50) );
    set_sp(100);
    set_chance(5);
    set_spell_dam(15);
    set_spell_mess1
    ("Twirling his glaive, the peasant slices into his opponent's weak point.  \n");
    set_spell_mess2
    ("With a quick flick of his wrists, the peasant soldier slices into one \n"
      +"of your exposed weak defensive points - ouch!  \n");
    set_ac(10);
    set_wc(5);
    set_number_of_arms(2);

    add_money( 20 + random(10) );
    armour = clone_object("/players/axlrose/armours/ringed_01");
    transfer(armour,this_object());
    dagger = clone_object("/players/axlrose/weapons/dagger_01");
    transfer(dagger,this_object());
    helmet = clone_object("/players/axlrose/armours/helmet_01");
    transfer(helmet,this_object());
    weapon = clone_object("/players/axlrose/weapons/glaive_01");
    transfer(weapon,this_object());
    init_command ("powerup");

    load_chat(3, ({
	"'Hopefully the war will be over soon,' a soldier whispers, 'so I can \n"
	+"return to my lands to plant my crops for next year.'  \n",
	"'Saw an elf once, a dwarf too!!!' says an excited peasant.  \n",
	"Looking upon the devastation while checking the soil content, the \n"
	+"peasant farmer shakes his head sadly.  \n",
	"'Take over my lands they think...' exclaims a peasant as he grips his \n"
	+"sharp glaive polearm tighter.  \n",
	"Grumbling to himself, a peasant murmurs, 'Lousy wages in the people's \n"
	+"army.' as he jingles a nearly empty money pouch.  \n",
      }));

    load_a_chat(5, ({
	"'Come on lads!' a boastful peasant screams.  'Let's get this bastard!!'  \n",
	"'I have fought tougher crops than..., hey watch it with that weapon!!!'  \n",
	"With some precision, the peasant wields his glaive polearm menacingly.  \n",
      }));
}
