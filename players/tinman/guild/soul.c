/* Coded by Tinman */
/* Initial Base on Mangla's Jedi Soul */
/* Original Monk guild by Whisky */

/* all defines files goes here */
#define PARTNER        "/players/tinman/guild/room"
#define TEST "/players/tinman/guild/TEST/"

/* all includes files goes here */
#include "/players/tinman/defs.h"
#include "/players/tinman/guild/includes/protectors.h"

inherit "/obj/armour";

/* all global variables goes here */
int guild, level, legend_level, dex, str;
int aikido,blinking,g_status,first_init;
object thispl;

/* Include for the extra_look */
#include "/players/tinman/guild/includes/extra_look.h"
#include "/spells/spell.h"

int id(string str) {
  return (str=="belt" || str=="monksoul");
}

int drop ( string arg) {
  return 1;
}

int get() {
  return 1;
}

int remove(string arg)
{
    if(id(arg))
    {
        write("You can't remove your belt !\n");
           return 1;
    }
    return 0;
}

int query_aikido() {
  return aikido;
}

int query_blinking() {
  return blinking;
}

int query_g_status() {
  return g_status;
}

int _actions_(string strSpell, string strArgs, int intTestDir) {

  switch(intTestDir) {
  case 0:
    return (BIN + strSpell)->main(strArgs);
    break;
  case 1:
    return (TEST + strSpell)->main(strArgs);
    break;
  }
  return 0;
}

int _actions(string strArgs) {

  int     intDelay;
  string  theverb;

  intDelay = 0;
  theverb = (string)query_verb();

  // 39 is '   and   46 is .
  if(theverb[0] == 39 || theverb[0] == 46)
    return 0;

  if(theverb[strlen(theverb)-1] == '.')
    return 0;

  if(theverb == "quit" || theverb == "dest")
    return 0;
  if(TP->query_immortal() || TP->query_testchar()) {
    if(file_size(TEST + theverb + ".c") > 0) {
      intDelay = (TEST + theverb)->query_delay();
      if(intDelay == 0) {
        return (TEST + theverb)->main(strArgs);
      }
      else {
        if(find_call_out("_actions_") != -1) {
          write("You are already casting.\n");
          return 1;
        }
        call_out("_actions_", 1, theverb, strArgs, 1);
        return 1;
      }
    }
  }

  if(file_size(BIN + theverb + ".c") > 0) {
    intDelay = (BIN + theverb)->query_delay();
    if(intDelay == 0) {
      return (BIN + theverb)->main(strArgs);
    }
    else {
      if(find_call_out("_actions_") != -1) {
        write("You are already casting.\n");
        return 1;
      }
      call_out("_actions_", 1, theverb, strArgs, 0);
      return 1;
    }
  }
  if(theverb == "monk/" || theverb == "m/") {
    return (BIN + "monk")->main(strArgs);
  }
  return 0;
}

void reset(int arg) {

  ::reset(arg);
  if(arg)
    return;

    first_init = 1;
    level = TPL;
    dex = TP->DEX;
    str = TP->STR;
    guild = GM->query_number(GUILDNUM);
    aikido = 0;
    blinking = 0;
    thispl = ENV();

  set_name("belt");
  set_type("guild");
	set_ac(1);
  set_long("The belt of the Monks.\n");
  set_weight(0);
}

void init() {
  string col;
  int mod_wis;

  ::init();

    if (environment()!=TP)
             return;

    if (first_init)
    {
    switch(TP->query_level())
        {
              case 1..10:    col = "white";         break;
              case 11..20:   col = "brown";         break;
              case 21..30:   col = "green";         break;
              case 31..50:   col = "yellow";        break;
              case 51..70:   col = "blue";          break;
              case 71..80:   col = "red";           break;
              case 81..90:   col = "silver";        break;
              case 91..100:  col = "golden";        break;
	      default:       col = "multi-colored"; break;
         }
         set_alias(col+" belt");
         set_short("A strong "+col+" belt");

  if (member(PROTECTORS,TP->query_real_name()) == 1)
                  g_status =  PROTECTORS[TP->query_real_name()];
         else
                  g_status = 0;
    mod_wis =  1 + TP->query_query_wis() / 3;

// against nature, and not against acid !
         modify_resistance(FIRE, mod_wis );
         modify_resistance(COLD, mod_wis );
         modify_resistance(POISON, mod_wis );
         modify_resistance(ELECTRICITY, mod_wis );

// against mindeffectives
         modify_resistance(MINDEFFECTIVE, mod_wis);
         modify_resistance(ILLUSION, mod_wis);
         modify_resistance(PETRIFICATION, mod_wis);
    }


  add_action("_actions","",1);

  TELL(TP,"You feel a surge of holyness going through your body.\n");
  if(TP->RNAME!="tinman" && !TP->query_invis() && !TP->query_immortal())
      CD->do_chat(guild,"[*MONK*] "+CAP(TP->RNAME)+
                        ", has return to Holy Mission.\n");

  /* Force player to wear the belt */
  if (this_player() && interactive(this_player()))
              command("wear belt",this_player());
}
