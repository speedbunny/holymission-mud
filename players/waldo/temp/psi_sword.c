inherit "obj/weapon";
#include "/players/turbo/weapon/defs.h"

int i;
int currenthp; // Current hitpoints of person wielding object
int currentsp; // As per spellpoints

reset(arg) 
{
    ::reset(arg);
    if(arg) return;
    set_name("psi sword");
    set_alias("psi blade");
    set_read("This is the psi-sword of Mishra.  Urza and I alone may wield"+
             " this supreme weapon.  All others shall be cursed!\n");
    set_alt_name("sword");
    set_short("The Psi-sword of Mishra");
    set_long(
      "This is the Psi-sword of Mishra, one of the greatest artificers ever."+
      " It is said that only the twins could wield this weapon safely. "+
      " To all others, it is cursed!\n");
    set_class(25);
    set_light(1);
    set_hit_func(TO);
    set_weight(0);
    set_value(0);
}

weapon_hit(attacker) 
{
    int i, dam;
    string tothem;
    i=random(10);
     switch(i) 
    {
      case 0: tothem=TPN+" slashes you with the psi-sword!";
              dam=55; break;
      case 1: tothem=TPN+" makes a quick triple slash!";
              dam=60; break;
      case 2: tothem=TPN+" hits 3 times and says ' will die!'";
	dam=65; break;
      case 3: tothem=TPN+" hits 3 times, while a voice screams in your mind 'MAY YOU ROT IN HELL!'";
	dam=70; break;
      case 4: tothem="As "+TPN+" swings 3 times, you hear a voice chanting 'BLOOD AND GUTS!'";
	dam=75; break;
      case 5: tothem=TPN+" releases the blade as it pummels its foe, a voice screams 'HACK!'";
	dam=80; break;
      case 6: tothem="The blade leaps away, a voice screams 'MEET YOUR MAKER!'";
 	dam=85; break;
      case 7: tothem="The blade leaps away, a voice screams 'DEATH TO THE INFIDEL!'";
	dam=90; break;
      case 8: tothem="The blade leaps away, a voice screams 'I WILL KILL YOU!'";
	dam=95; break;
      case 9: tothem="The blade leaps away, a voice screams 'NIH!'";
	dam=100; break;
    default:
	return 0; break;
    }
    say(tothem+"\n");
    if (TPWIZ) write("Al-Akbar whispers: "+dam+" damage!\n");
    return dam;
}

wield (str) {
    ::wield(str);
    if(id(str)) 
    {
	currenthp = TP->query_hp(); // Store current hp
	currentsp = TP->query_sp(); // Store current sp
	TP->reduce_hit_points( (TP->query_hp()-1) );  // So they dont
	TP->restore_spell_points( - (TP->query_sp()-1) ); // die
	if (TP->query_immortal())
	{
		write("CHP : "+currenthp+" CSP : "+currentsp+"\n");
		}
        write("You are now cursed!\n");
           say(TPN+" tries to wield a psi-sword.\n");
	return 1;
    }
}

un_wield(str)
{
  if (id(str))
  {
    // Restore hp and sp
    TP->reduce_hit_points( - (currenthp - TP->query_hp()) );
    TP->restore_spell_points( currentsp - TP->query_sp());
    }
  ::un_wield(str);
  return 1;
}
     
