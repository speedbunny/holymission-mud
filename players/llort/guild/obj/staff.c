

/* 
   Whisky: 12.04.94 uni-linz.ac.at

   * recoded the wield bug
   * gave the magic staff a magic hit, because its no normal weapon
   * recoded the regeneration in heart_beat
   * put in strict types
								*/

#define TP       this_player()
#define TPN      this_player()->query_name()
#define TPRN     this_player()->query_real_name()
#define TO       this_object()

inherit "obj/weapon"; 
#include "/players/llort/guild/tune.h" /* include after inherit */

int quiet;               /* flag: turn off regeneration message */
object owner;		 /* who carries the wand ? (for heart_beat */
string true_desc;
int heal_count;

/* prototyping */
void set_true_desc(string str);
string query_true_desc();

void reset(int arg) 
{

    ::reset(arg);

    if (arg == 0) 
    {
	owner = TP;
	set_name("staff");
	set_short("A staff with magic runes");
	set_long("It seems to be an interesting wand with lots of runes graved"
	  +" into its surface.\n");
	set_class(4);
	set_value(0);
	set_weight(1);
	set_alias("mage staff");
	set_alt_name("llort_guild_staff");
	set_read("The strange runes seem to shiver before your eyes.\n" +
	  "You can't even say what they look like.\n");
	set_true_desc("A regeneration wand");
	set_hit_func(this_object()); /* magic hit */
	enable_commands();
	quiet=1; 
	heal_count=0;
    }
}

void init() 
{
    ::init();
    /*   add_action("identify","identify"); */
    add_action("shutup","quiet");
}

int wield(string str) 
{
    if ( id(str) && (!query_wielded()) && TP->query_guild()==5 && 
      TP->query_hands_free())
    {
	write("The power of the wand pulses through your body.\n");
	say(TPN + " emits a soft blue glow.\n");
	owner=TP;
	set_heart_beat(1);
    }
    return ::wield(str);
}

int un_wield() 
{
    if (TP->query_guild()==5)
    {
	write("A foreign energy seems to leave your body.\n");
	say(TPN + " stops glowing.\n");
    }
    set_heart_beat(0);
    return ::un_wield();
}

void heart_beat() 
{
    if (owner && objectp(wielded_by) && wielded_by==owner)   /* security check */
    {

	if (!heal_count) 
	{
	    owner->heal_self(STAFF_RATE*2);
	    if(!quiet)
		tell_object(owner,"You feel regenerating.\n");
	}
	if (heal_count==STAFF_TIME) heal_count=0;
	else 
	    heal_count++; 
    }
}

int throw_out_transfer() 
{ 
    return 1; 
}

int identify(string str) 
{
    if(!str) 
    {
	notify_fail("try identify <obj>\n");
	return 0;
    }
    if(id(str)) 
    {
	short_desc=query_true_desc();
	write("After a closer look, you decide it to be " + query_true_desc() +
	  ".\n");
	set_read(read_msg+" (try 'quiet' to toggle the message printout)\n");
    } else 
	write("You cant identify "+str+".\n");
    return 1;
}

int shutup() 
{
    quiet=!quiet;
    write("KLICK!\n");
    return 1;
}

void set_true_desc(string str) 
{
    true_desc=str; 
}

string query_true_desc() 
{ 
    return true_desc; 
}

int drop() 
{
    this_player()->stop_wielding();
    write("As you drop the staff it starts to fade.\n");
    call_out("dest_wand",1);
    return 1;
}

int dest_wand() 
{
    destruct(this_object());
    return 1;
}

int weapon_hit(object victim)
{
    int power;

    power = TP->query_int()/3;
    if (TP->query_guild()==5)
    {
	return power;
    }
    else
	return 0;
}
