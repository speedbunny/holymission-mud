/* QUEST_OBJ.C - Programmed by Herp, this is an inherit/clone file. DO NOT
                 COPY! */
/* 150492: Herp: Started programming */
/* 291092: Moonchild: hints and compulsory added */
/* 090893: Moonchild: adding kill-factor and creator */

#define QR "room/quest_room"

/* USERDOC:
general
This object is used to make quests. A clone of this object should be moved
to /room/quest_room.c. This is done by calling add_quest. The weight of the 
object determines its difficulty. Configure it the way you want. Generally 
defined functions:
set_weight, query_weight, set_name, query_name, set_killing, set_creator.
*/

string hint_string, short_hint_string, name, creator, killing;
int level,guild;
int weight,compulsory;

int no_clean_up() { return( 1 ); }

reset(arg) {
  if(arg) return;
  creator=creator(this_object()) ? capitalize(creator(this_object())) : "Root";
  killing="";
}

/* USERDOC:
set_hint
Format: set_hint(s)
Example: set_hint("Kill everything in the forbidden forest.\n"
                + "Try not to kill yourself though...\n")
See also: hint, set_short_hint.
This is the long description of the quest. \n's are needed.
*/
set_hint(h) { 
  hint_string = h; 
}

/* USERDOC:
set_short_hint
Format: set_short_hint(s)
Example: set_short_hint("Empty the forbidden forest.")
See also: set_hint, short_hint.
This sets the short description of the quest. Do not use a \n.
*/
set_short_hint(h) { 
  short_hint_string=h; 
}

/* USERDOC:
set_compulsory
Format: set_compulsory(i)
Example: set_compulsory(1)
See also: compulsory.
This makes the quest a quest you HAVE to do before a player can become wizard
if i is not equal to 0.
*/
set_compulsory(i) { 
  compulsory=i; 
}

set_name(n) { 
  name = n; 
}

/* USERDOC:
set_level
Format: set_level(i)
Example: set_level(5)
See also: query_level.
This sets the level of the quest.
*/
set_level(lvl) { 
  level = lvl; 
}

/* USERDOC:
set_guild
Format: set_guild(i)
Example: set_guild(6)
See also: query_guild.
This makes the quest for one kind of guild only. I'm not sure wether it's
implemented though.
*/
set_guild(gd) { 
  guild = gd; 
}

/* USERDOC:
set_weight
Format: set_weight(i)
Example: set_weight(10)
See also: query_weight
This sets the value of the quest
*/
set_weight(i) { 
  weight=i; 
}

/* USERDOC:
set_killing
Format: set_killing(i)
Example: set_killing(10)
This sets the killing difficulty of the quest from 1-10
*/
set_killing(i) {
  killing="**********"[0..i-1];
}

set_creator(str) {
  creator=capitalize(str);
}

id(str) { return str == name || str == "quest"; }

short() {
  return name;
}

long() {
    write("This is the quest '" + name + "':\n");
    write(hint_string);
}

/* USERDOC:
hint
Format: s=hint()
See also: set_hint, short_hint.
This returns the hint set with set_hint(). There are \n's in the result.
*/
hint() { 
  return hint_string; 
}

/* USERDOC:
short_hint
Format: s=short_hint()
See also: set_short_hint, hint.
This returns the short hint set with set_short_hint(). There are no \n's in
the result.
*/
short_hint() {
  return sprintf("%-47s%-11s(%s)", short_hint_string, killing, creator);
}

/* USERDOC:
compulsory
Format: i=compulsory()
See also: set_compulsory.
This returns a value unequal to zero if this quest is compulsory.
*/
compulsory() { 
  return compulsory; 
}

/* USERDOC:
add_quest
Format: add_quest()
This function adds the quest to the quests in the game. Only call this
function when all parameters are set.
*/
add_quest() {
  QR->enter_inventory(this_object());
}

query_name() { 
  return name; 
}

/* USERDOC:
query_level
Format: i=query_level()
See also: set_level()
This returns the level of the quest.
*/
query_level() { 
  return level; 
}

/* USERDOC:
query_guild
Format: i=query_guild()
See also: set_guild()
This returns the guild for which this quest was meant.
*/
query_guild() { 
  return guild; 
}

query_weight() { 
  return weight; 
}
