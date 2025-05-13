inherit "/obj/monster";
#include "/spells/spell.h"
#include "/sys/vt100.h"


int power;
object owner;
int level;

void reset(int arg)
{
	::reset(arg);
	if(arg) return;

	set_long("A horde of all-consuming maggots is moving towards you.\n"+
		VT_TA_B+"Run for your Life,"+VT_TA_AO+" or no even your bones will\n"+
		"stay in one piece.\n");
	set_short(VT_TA_B+"A creeping DOOM"+VT_TA_AO);
	set_name(VT_TA_B+"creeping doom"+VT_TA_AO);
	set_alias("doom");
	power = 1000;
    level = 20;
    owner = this_player();
}

query_show_short() { return short(); }

void set_power(int i)
{
	power = i;
	return;
}

int power() { return power; }

void set_owner(object o)
{
	owner = o;
}

object owner() { return owner; }


void do_hit()
{
object *env,oppo;
int i,dam;
string oppo_name;

	env = all_inventory(environment(this_object()));

  for (i=sizeof(env)-1; i>=0; i-- )
  {
	WINFO("INDEX: "+i+"\n");
     if ( living( env[i] ) )
     {
         oppo=env[i];
		 dam = roll_dice(level,40,200);	
         power -= dam;
         switch( oppo->do_save(AGGRESSIVE,DEATHMAGIC,0,0,this_object()))
         {
             case IMMUNE:      dam = 0; break;
             case SAVED:       dam /= 2; break;
             case SAVE_FAILED: break;
             default:          dam = 0;
         }
         oppo_name = oppo->query_name();

		 if(dam > oppo->query_hp())
         {
            write("A horde of maggots and other insects is eating your body\n"+
				"and you are simply DEAD.\n");
          say("\n"+capitalize(oppo_name)+" has been consumed by the Creeping DOOM.\n", oppo);
		  oppo->hit_by_spell(dam);
		  if(present("corpse",environment(this_object())))
			destruct(present("corpse",environment(this_object())));
		 }
		else
		{
			write("\nA horde of maggots is attacking you with brutal strength!\n");
			oppo->hit_by_spell(dam);
		}
		WINFO("DAM: "+dam+"\n");
		if(power < 0) break;
	}
}
}
		
		 

 



