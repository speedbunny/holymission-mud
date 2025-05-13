/*
 * This is the race master.
 *
 * This object is NOT designed for cloning or inheriting.
 * Use it by calling the functions listed below.
 * You can assume that the object is loaded in room/init_file,
 * so don't load it yourself but refer to the funtions in a style like:
 *
 * value = "race/master"->query_function_value(params);
 *
 * These are the functions defined in the race/master:
 * ===================================================
 *
 * query_size           ... returns the size of a race 
 * query_basic_stat     ... returns the basic stat of a race
 * query_max_stat       ... returns the maximal stat of a race
 * query_language       ... returns the language of a race
 * query_soul           ... returns the filename of the soul
 * query_room           ... returns the filename of the room
 * query_start_room     ... returns the start room of each race
 * race_list            ... returns a list of all races
 *
 */

#define NAME_OF_SIZE    "obj/armour"->query_size_name
#include "/sys/defs.h"
#include "/guild/guild_defs.h"
#include <damage.h>
#include <stats.h>

#define AVG_STAT            18
#define MAX_STAT            30
#define MIN_STAT            3
#define MIN_REARRANGE_STAT  8
#define REARRANGE_AVG       10
#define MAX_REARRANGE_STAT  25
#define REARRANGE_PTS       50
#define REGEN_SPEEDS ({"N/A","Very slow","Slow","Moderate","Fast","Very Fast"})
#define MAX_NUMBER_OF_RESISTANCE  10
#define NUM_OF_RACES       16

mapping race_info;
string resistances_info;
string race_defines;
string *race_list;

string short() { return "The Race Master"; }

void long() { 
  write(short()+"\n"+
        "This room contains all information about races.\n"+
        "For information about races type 'dump [<race>]'.\n"+
        "No obvious exits.\n");
}

void init() { 
  add_action("_dump","dump"); 
}

status _dump(string str) {
  string *rcs, tmp;
  int    i, j, sz, extra_sz;
  mixed  *info, extra;

  if(!str) {
    printf("%-24s %23s %32s\n", " ",
           "Basic Start Attributes", "Natural Resistances");
    printf("%-10s %6s %2s %2s %3s %3s %3s %3s %3s %3s %2s %2s "
           "%2s %2s %2s %2s %2s %2s %2s %2s %2s\n",
           "Race Name", " Size ", "Nw", "Na", "Str", "Dex", "Con",
           "Int", "Wis", "Chr", "Ph", "Ma", "Fi", "Co", "Ac", "El",
           "Po", "Bw", "Me", "Dm", "Ex");

    rcs = m_indices(race_info);
    for(i=0, sz=sizeof(rcs); i<sz; i++) {
      info = race_info[rcs[i]];
      printf("%-10s %6s %2s %2s %3s %3s %3s %3s %3s %3s %2s %2s "
             "%2s %2s %2s %2s %2s %2s %2s %2s %2s\n",
             rcs[i], NAME_OF_SIZE((int)info[0]),
             (int)info[4], (int)info[5],
             (18+(int)info[1][0]), (18+(int)info[1][1]),
             (18+(int)info[1][2]), (18+(int)info[1][3]),
             (18+(int)info[1][4]), (18+(int)info[1][5]),
             (int)info[6][0], (int)info[6][1], (int)info[6][2],
             (int)info[6][3], (int)info[6][4], (int)info[6][5],
             (int)info[6][6], (int)info[6][7], (int)info[6][8],
             (int)info[6][9], (int)info[6][10]);
    }
    return 1;
  }

  if(!member(race_info, str)) {    
    say("No such race!\n");
    return 1;
  }

  info = race_info[str];

  printf("Race             -> %-10s Size       -> %-6s\n",
         str, NAME_OF_SIZE((int)info[0]));
  printf("Natural WC       -> %2d   Natural AC -> %2d\n",
         (int)info[4], (int)info[5]);
  printf("Avg. Start Stats -> Str: %2d  Dex: %2d  Con: %2d\n",
         (18+(int)info[1][0]), (18+(int)info[1][1]), (18+(int)info[1][2]));
  printf("                    Int: %2d  Wis: %2d  Chr: %2d\n",
         (18+(int)info[1][3]), (18+(int)info[1][4]), (18+(int)info[1][5]));
  printf("Resistances      -> Ph: %2d  Ma: %2d  Fi: %2d  Co: %2d  "
         "Ac: %2d  El: %2d\n",
         (int)info[6][0], (int)info[6][1], (int)info[6][2],
         (int)info[6][3], (int)info[6][4], (int)info[6][5]);
  printf("                    Po: %2d  Bw: %2d  Me: %2d  Dm: %2d  "
         "Ex: %2d\n",
         (int)info[6][6], (int)info[6][7], (int)info[6][8],
         (int)info[6][9], (int)info[6][10]);
  printf("# subgds allowed -> %1d\n", (int)info[7]);
  switch((int)info[7]) {
    case 1 :
      printf("Lvl to get subguild -> 1st: %3d\n", (int)info[8]);
      break;
    case 2 :
      printf("Lvl to get subguild -> 1st: %3d  2nd: %3d\n",
             (int)info[8], (int)info[8]*2);
      break;
    case 3 :
      printf("Lvl to get subguild -> 1st: %3d  2nd: %3d  3rd: %3d\n",
             (int)info[8], (int)info[8]*2, (int)info[8]*4);
      break;
    case 4 :
      printf("Lvl to get subguild -> 1st: %3d  2nd: %3d  3rd: %3d\n",
             (int)info[8], (int)info[8]*2, (int)info[8]*4);
      printf("                       4th: %3d\n", (int)info[8]*8);
      break;
    case 5 :
      printf("Lvl to get subguild -> 1st: %3d  2nd: %3d  3rd: %3d\n",
             (int)info[8], (int)info[8]*2, (int)info[8]*4);
      printf("                       4th: %3d  5th: %3d\n",
             (int)info[8]*8, (int)info[8]*16);
      break;
  }

  sz = sizeof(info[10]);
  if(!sz)
    tmp = "None";
  else
    for(i=0, tmp=""; i<sz; i++)
      tmp += ", " + (string)info[10][i];
  write(lw("Guild restricts  -> " + tmp + "\n")); 

  for(i=0, sz=sizeof(info[3]); i<sz; i++) {
    if(i == 0)
      tmp = (string)info[3][i];
    else
      tmp += ", " + (string)info[3][i];
  }
  write(lw("Language(s)         -> " + tmp + "\n"));

  if(!info[9])
    printf("Abilities           -> None\n\n");
  else {
    if((int)info[9][0] != 0)
      printf("Abilities           -> Parry Modifier: %2d%\n",
            (int)info[9][0]);
    sz = sizeof(info[9]);
    if(sz > 1)
      if((int)info[9][1] != 0)
        printf("                       Dodge Modifier: %2d%\n",
               (int)info[9][1]);
    if(sz > 2)
      if((int)info[9][2] != 0)
        printf("                       HP Bonus: %2d per 10 lvls\n",
               (int)info[9][2]);
    if(sz > 3)
      if((int)info[9][3] != 0)
        printf("                       SP bonus: %2d per 10 lvls\n",
               (int)info[9][3]);
    if(sz > 4)
      if((int)info[9][4] != 0)
        printf("                       Regeneration: %s\n",
               REGEN_SPEEDS[(int)info[9][4]]);
    if(sz > 5)
      if((int)info[9][5] != 0)
        printf("                       Encumbrance: %2d\n",
               (int)info[9][5]);
    if(sz > 6)
      if((int)info[9][6] != 0)
        printf("                       Infravision: YES\n");
    if(sz > 7) {
      extra = info[9][7];
      if(extra) {
        extra_sz = sizeof(extra);
        if(extra_sz > 0) {
          for(i=0, tmp=""; i<extra_sz; i++) {
            if(i > 0)
              tmp += ", ";
            switch((string)extra[i]) {
              case "TAIL" :
                tmp += "tail attack(automatic)";
                break;
              case "SPIT" :
                tmp += "spit posion(manual)";
                break;
              case "EXTRA-ARM" :
                tmp += "extra arm";
                break;
            } // end of switch
          } // end of for loop
          write(lw("                       Extra Attacks: " + tmp + "\n"));
        } // end of if
      }
    }
    if(sz > 8) {
      extra_sz = sz - 8;
      for(i=0, tmp=""; i<extra_sz; i++) {
        if(i > 0)
          tmp += ", ";
        extra = info[9][8+i];
        switch((string)extra[1]) {
          case "FEAR" :
            tmp += "causes fear";
            break;
          case "NO-FEAR" :
            tmp += "resistant to fear";
            break;
        } // end of switch
      } // end of for loop
      write("                       Special Abilities: " + tmp + "\n");
    } // end of if
  } // end of else

  return 1;
} /* dump */

void reset(int arg) {
  if(arg) return;	/* Allocate not needed anymore */
  set_light(1); 	/* Oh well :-) */
  if(!mappingp(race_info))
    race_info = ([]);

// Name, Size, Stat mods (S,D,C,I,W,Ch), Balance, Languages,
// Natural WC, Natural AC, Resistances, # of guilds, Lvl to multi-guild,
// Ability modifiers, Plural, Adverb, Start room
// Balance is the modifier to their point total when they wish
//   to rearrange their stats
// Resistances = Phys, Mag, Fir, Col, Acid, Elec, Pois, BW, Ment, DM
// Ability Mods = parry, dodge, hp bonus, sp bonus, regeneration,
//   encumbrance, infravision, extra attacks

  race_info = (["human":
    ({ 3, ({ 0, 0, 0, 0, 0, 0,}) ,  0, ({"westron",}),
       0,  0, ({ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,}), 4, 35,
       0, "humans", "human", "/room/church",}) ]);
  race_info = (["half-elf":
    ({ 3, ({ 0, 0, 0, 0,-1, 1,}) ,  0, ({"westron","sindarin",}),
       0,  0, ({ 0, 1, 0, 0, 0, 0, 0, 0, 2, 0, 0,}), 3, 40,
       ({ 0, 0, 0, 0, 0, 0, 1,}), "half-elves", "half-elvish",
       "/room/church",}) ]);
  race_info = (["half-orc":
    ({ 3, ({ 2, 0, 2,-2, 0,-2,}) ,  0, ({"westron","orcish",}),
       0,  0, ({ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,}), 3, 45,
       ({ 0, 0, 5, 0, 0, 2,}), "half-orcs", "half-orcish",
       "/room/church",}) ]);
  race_info = (["half-ogre":
    ({ 4, ({ 3,-1, 3,-3, 0,-3,}) ,  1, ({"westron","ogrish",}),
       0,  1, ({ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,}), 2, 50,
       ({ 0, 0, 10, 0, 0, 4,}), "ogres", "half-ogrish",
       "/room/church",}) ]);
  race_info = (["elf":
    ({ 3, ({-2, 1,-2, 5,-1, 4,}) , -5, ({"sindarin",}),
       0,  0, ({ 0, 3, 0, 0, 0, 0, 0, 0, 5, 0, 0,}), 3, 45,
       ({ 0, 1, 0, 0, 0, 0, 1,}), "elves", "elvish",
       "/room/church",}) ]);
  race_info = (["hobbit":
    ({ 2, ({-4, 4,-3,-1, 0,-1,}) ,  5, ({"kuduk",}),
       0,  0, ({ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,}), 2, 50,
       ({ 0, 3, 0, 0, 0,-2, 1,}), "hobbits", "hobbit",
       "/room/church",}) ]);
  race_info = (["gnome":
    ({ 2, ({-1, 2,-2, 3, 2,-2,}) , -2, ({"gnomish",}),
       0,  0, ({ 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0,}), 3, 50,
       ({ 0, 2,  0, 0, 0,-2, 1,}), "gnomes", "gnomish",
       "/room/church",}) ]);
  race_info = (["dwarf":
    ({ 2, ({ 2,-1, 3, 0, 3,-1,}) , -6, ({"khuzdul",}),
       0,  0, ({ 0, 2, 0, 0, 0, 0, 3, 0, 0, 0, 0,}), 3, 50,
       ({ 0, 0,  2, 0, 0, 2, 1,}), "dwarves", "dwarvish",
       "/room/church",}) ]);
  race_info = (["orc":
    ({ 3, ({ 3,-1, 3,-3,-3,-3,}) ,  4, ({"orcish",}),
       1,  0, ({ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,}), 2, 60,
       ({ 0, 0, 10, 0, 0, 4, 1,}), "orcs", "orcish",
       "/room/church",}) ]);
  race_info = (["troll":
    ({ 4, ({ 4,-1, 5,-3,-3,-5,}) ,  3, ({"trollish",}),
       5,  0, ({ 4, 0,-5, 0, 0, 0, 0, 0, 0, 0, 0,}), 2, 70,
       ({ 0, 0, 30, 0, 3, 6, 0, 0, ({"FEAR", 10}),}), "trolls",
       "trollish", "/room/church",}) ]);
  race_info = (["ogre":
    ({ 4, ({ 5,-2, 4,-5,-3,-5,}) ,  6, ({"ogrish",}),
       2,  3, ({ 5, 0, 0, 0, 0, 0, 0, 0,-2, 0, 0,}), 2, 65,
       ({ 0, 0, 20, 0, 0, 8,}), "ogres", "ogrish",
       "/room/church",}) ]);
  race_info = (["sekreh":
    ({ 3, ({ 1, 2, 2,-2,-1,-4,}) ,  2, ({"slarthen",}),
       8,  0, ({ 0, 0, 5,-5, 0, 0, 5, 0, 0, 0, 0,}), 2, 55,
       ({ 1, 0, 0, 0, 1, 0, 0, ({"TAIL", "SPIT"}),}), "sekreh",
       "sekreh", "/room/church",}) ]);
  race_info = (["rakasta":
    ({ 3, ({ 0, 5, 0,-1, 1, 1,}) , -6, ({"rakastan",}),
       5,  0, ({ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,}), 2, 55,
       ({ 0, 5, 0, 0, 0, 0, 1,}), "rakastas", "rakastan",
       "/room/church",}) ]);
  race_info = (["skaven":
    ({ 2, ({-2, 3,-1, 1,-3,-2,}) ,  4, ({"skaven",}),
       3,  0, ({ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,}), 2, 55,
       ({ 0, 2, 0, 0, 0,-1, 1,}), "skaven", "skaven",
       "/room/church",}) ]);
  race_info = (["gronnar":
    ({ 4, ({ 5,-5, 5,-5,-5,-5,}) , 10, ({"westron",}),
       10,  8, ({ 0, 5, 0,-3, 0,-5, 0, 0,-4, 3, 0,}), 2, 75,
       ({ 5,-8, 15, 0, 0, 5, 0, ({}),
         ({"FEAR", 10}), ({"NO-FEAR", 0}),}),
       "gronnar", "gronnarian", "/room/church",}) ]);
  race_info = (["dracol":
    ({ 3, ({-1, 0,-1, 2, 5,-2,}) , -3, ({"dracolean",}),
       0,  0, ({-2, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0,}), 2, 60,
       ({ 0, 0, 0, 20,}), "dracol", "dracolien", "/room/church",}) ]);
  race_list = m_indices(race_info);
} /* reset */

/* USERDOC:
query_valid_race
Function : i=query_valid_race(s)
This function returns one if the race, s,  is a valid one for a player,
else 0 is returned.
*/
nomask status query_valid_race(string str) {
  if(member_array(str, race_list) != -1)
    return 1;
  return 0;
}

/* USERDOC:
query_ability

This function returns 0 if the race doesn't exist or the race has
no abilities. Otherwise, it returns a mixed array of the abilities
for the specified race.
*/
nomask mixed query_ability(string str, int val) {
  mixed *tmp;

  if(!member(race_info, str))
    return 0;
  tmp = (race_info[str])[9];
  if(!tmp) return 0;
  return tmp[val];
}

/* USERDOC:
query_size

This function returns the numerical value of the size of the race,
or 0 if the race does not exist.
*/
nomask int query_size(string str) {
  if(!member(race_info, str))
    return 0;
  return ((race_info[str])[0]);
}

/* USERDOC:
query_stat_adjustments

This function return the array of integers containing all the stat
adjustments for the race, or 0 if the race doesn't exist.
*/
nomask int query_stat_adjustments(string str) {
  if(!member(race_info, str))
    return 0;
  return ((race_info[str])[2]);
}

/* USERDOC:
query_natural_wc

This function returns the natural weapon class of the race, or 0
if the race doesn't exist.
*/
nomask int query_natural_wc(string str) {
  if(!member(race_info, str))
    return 0;
  return ((race_info[str])[4]);
}

/* USERDOC:
query_natural_ac

This function returns the natural weapon class of the race, or 0
if the race doesn't exist.
*/
nomask int query_natural_ac(string str) {
  if(!member(race_info, str))
    return 0;
  return ((race_info[str])[5]);
}

/* USERDOC:
query_resistance_modifier

This function returns the individual resistance modifier (as an int)
if it is specified, or the array of modifiers if unspecified. A 0 is
returned if the resistance doesn't exist or the race doesn't exist.
*/
nomask varargs mixed query_resistance_modifier(string str, int val) {
  if(!member(race_info, str))
    return 0;
  if(!val)
    return ((race_info[str])[6]);
  if(val<0 || val>= NO_OF_DAMAGE_TYPES)
    return 0;
  return ((race_info[str])[6][val]);
}

/* USERDOC:
query_number_of_guilds_allowed

This function returns the maximum number of guilds allowed to the race,
or 0 if the race doesn't exist.
*/
nomask int query_number_of_guilds_allowed(string str) {
  if(!member(race_info, str))
    return 0;
  return ((race_info[str])[7]);
}

/* USERDOC:
query_level_to_multi_guild

This function returns the level needed to get a second guild, or 0
if the race doesn't exist.
*/
nomask int query_level_to_multi_guild(string str, int val) {
  if(!member(race_info, str))
    return 0;
  return ((race_info[str])[8]);
}

/* USERDOC:
query_level to multi_subguild

This function returns the level needed to get a subguild in the guild
you have, or 0 if the race doesn't exist.
*/
nomask int query_level_to_multi_subguild(string str, int val) {
  if(!member(race_info, str))
    return 0;
  return ((race_info[str])[8] - 10);
}

/* USERDOC:
query_stat_modifier

This function returns the modifier for a stat, or 0 if the stat or
race doesn't exist.
*/
nomask int query_stat_modifier(string str, int val) {
  if(!member(race_info, str))
    return 0;
  if(val<0 || val>5)
    return 0;
  return ((race_info[str])[1][val]);
}

/* USERDOC:
query_number_of_special_abilities

This function returns the number of special abilities that the
race has, or 0 if the race doesn't exist.
*/
nomask int query_number_of_special_abilities(string str) {
  mixed *tmp;
  int   how_many;

  if(!member(race_info, str))
    return 0;
  tmp = (race_info[str])[9];
  if(!tmp) return 0;
  how_many = sizeof(tmp);
  if((how_many - 7) < 0)
    return 0;
  return how_many;
}

/* USERDOC:
query_special_ability

This function returns a special ability of a race, based on which one
is wanted, as a mixed array. 0 is returned if the race doesn't exist
or it has no special abilities.
*/
nomask varargs mixed query_special_ability(string str, int val) {
  mixed *tmp;
 
  if(!member(race_info, str))
    return 0;
  tmp = (race_info[str])[9];
  if(!tmp) return 0;
  if(!val)
    val = 1;
  return (tmp[5+val]);
}

/* USERDOC:
query_start_room

This function returns the room which the player will start in based
on their race, or 0 if the races doesn't exist.
*/
nomask string query_start_room(string str) {
  if(!member(race_info, str))
    return 0;
  return ((race_info[str])[12]);
}

/* USERDOC:
query_plural

This function returns the plural form of the race, or 0 if the race
doesn't exist.
*/
nomask string query_plural(string str) {
  if(!member(race_info, str))
    return 0;
  return ((race_info[str])[10]);
}

/* USERDOC:
query_adverb

This function returns the adverb form of the race, or 0 if the race
doesn't exist.
*/
nomask string query_adverb(string str) {
  if(!member(race_info, str))
    return 0;
  return ((race_info[str])[11]);
}

/* USERDOC:
query_basic_stats

This function returns an integer array containing the basic start
stats for the race, or 0 if the race doesn't exist.
*/
nomask int *query_basic_stats(string str) {
  int i, *tmp;

  if(!member(race_info, str))
    return 0;
  tmp = allocate(NO_OF_STATS);
  for(i=0; i<NO_OF_STATS; i++)
    tmp[i] = AVG_STAT + (race_info[str])[1][i];
  return tmp;
}

#if 0
query_soul() { return SOUL; }

query_room() { return ROOM; }
#endif

int query_number(string str) {  
  int j;

  for(j=0; j<NUM_OF_RACES; j++)
    if(race_info[j][0] == str)
      return j;
  return -1;
}

void race_list() {
  string *str;
  int    i, sz, tmp;
  
  str = m_indices(race_info);
  for(i=0, sz=sizeof(str); i<sz; i++) {
    tmp = (race_info[str[i]])[0];
    printf("%-15s %6s\n", str[i], NAME_OF_SIZE(tmp));
  }
}
