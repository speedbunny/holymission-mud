/* Axlrose - Barbarian Guild */
/* Barbarian Trader - Severance */
inherit "obj/mon";
object armour, weapon;

string spell_mess() {
    return "Suddenly Severance seems to dodge and disappear into the shadows before \n"
    " "+query_attacker()->query_name()+" gurgles blood as "+query_attacker()->query_possessive()+" throat gets slashed open!\n";
}

void reset(int arg) {
    ::reset(arg);
    if(arg) return;
    set_name("severance the Half-Orc");
    set_alt_name("severance");
    set_alias("trader");
    set_short("Severance the Half-Orc Barbarian Trader");
    set_long
    ("Severance the Half-Orc barbarian trader glares at you menacingly with \n"
      +"pitch black eyes.  His disfigured leathery face soon grins mischievous- \n"
      +"ly towards you while his acid burnt left hand delicately rolls a coin \n"
      +"around and through his slender fingers.  Soon a cool aura of sneaki- \n"
      +"ness surrounds him as he plans to con another helpless victim.\n");
    set_gender(1);
    set_race("half-orc");
    set_level( 35 + random(5) );
    set_int(20);
    set_wis(20);
    set_dex(50);
    set_chr(10);
    set_aggressive(0);
    set_al(-250);
    set_hp(3000);
    set_sp(1000);
    set_chance(25);
    set_spell_dam(75);
    set_spell_mess1("@@spell_mess@@");
    set_spell_mess2
    ("Quickly dodging to one side and vanishing into the shadows, Severance \n" 
      +"slides behind you and cleanly slices at your throat - drawing blood.\n");
    set_ac(25);
    set_wc(15);

    add_money( 1250 + random(250) );
    armour = clone_object("/players/axlrose/armours/dragon_scales");
    transfer(armour,this_object());
    weapon = clone_object("/players/axlrose/weapons/acid_sword");
    transfer(weapon,this_object());
    init_command ("powerup"); 

    load_chat(5, ({
	"With a hint of a tear in his eyes, Severance stares at his acid scarred \n"
	+"arms and hands, mumbling obscenities about some damned black dragon.  \n",
	"Severance whispers 'Have any loot you want to fence bub?' \n",
	"'You want that lover's locket?  Or that taliesin tag?' Severance asks \n"
	+"as he quietly looks you and your equipment over.  \n",
	"Slowly poking inside the mechanism, Severance smiles to himself as he \n"
	+"(*click*) (*click*) (*pop*) picks open another lock.  \n",
	"'Ask me something you might want to know,' Severance says slyly, 'and \n"
	+"maybe I just might know it...for the right price...'  *grins evilly*  \n",
      }));

    load_a_chat(20, ({
	"Severance screams 'You shall now pay for that you bastard!!!!!'\n",
	"Flying into a mad rage while lunging towards you, Severance blasts 'I \n"
	+"killed a fucking dragon - so you're nothing to me wimp!!!'\n",
	"'Give me your best shot!' Severance growls.  'But watch the burns!' \n",
      }));
}
