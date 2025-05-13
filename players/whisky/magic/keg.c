#include "/lw.h"
  /*

This object is made for inheritance. Configure to your tastes.

Functions are:

  set_name(string)           - Sets the name
  set_alias(string)          - Sets an alias
  set_alt_name(string)       - Sets another name
  set_short(string)          - Sets short description
  set_long(string)           - Sets long description
  set_weight(int)            - Sets base weight
  set_value(int)             - Sets base value
  set_strength(int)          - Sets alcohol strength
  set_taps(int)              - Sets max number of taps
  set_consumer_mess(string)  - Sets message owner sees when he taps
  set_consuming_mess(string) - Sets message room sees when owner taps

  query_name()               - Returns name
  query_weight()             - Returns calculated weight
  query_value()              - Returns calculated value
  query_strength()           - Returns alcohol strength
  query_taps()               - Returns number of taps left
  query_keg()                - Returns 1

*/


#define TP   this_player()
#define TO   this_object()
#define NAME query_name()

int weight, value, maxtaps, taps, strength;
string name, short, long, alias, alt_name, consumer_mess, consuming_mess;
  
id(arg) { return arg == name || arg == alias || arg == alt_name; }
get() { return 1; }
short() { return short; }
long() {
  write(lw(long));
  if(taps > (7 * maxtaps) / 8)
    write("The keg full.\n");
  else if(taps > (3 * maxtaps) / 4)
    write("The keg is nearly full.\n");
  else if(taps > (5 * maxtaps) / 8)
    write("The keg is more than half-filled.\n");
  else if(taps > maxtaps / 2)
    write("The keg is half full.\n");
  else if(taps > (3 * maxtaps) / 8)
    write("The keg is half empty.\n");
  else if(taps > maxtaps / 4)
    write("There is still a little left in the keg.\n");
  else if(taps > maxtaps / 8)
    write("The keg is nearly empty.\n");
  else if(taps) write("There are still a few drops in the keg.\n");
  else write("The keg is empty.\n");
  if(TP->query_immortal())
    write("Wiz Info: Taps left = " + taps + ".\n");
  if(taps) write("Just \"tap keg\" to drink from it.\n");
}

reset(arg) {
  if (arg)
  {
  if (!objectp(environment(environment())))
   destruct(this_object());
  return;
 }
  if (arg) return;
  name = "keg";
  short = "Keg";
  long = "A keg.\n";
  weight = 1;
  strength = 1;
  taps = 1;
  maxtaps = 1;
}

init() {
  add_action("tap", "tap");
}

tap(arg) {
  int missed;
  if(id(arg)) {
    if(taps) {
      if(TP->drink_alcohol(strength)) {
	TP->heal_self(strength*3);
	if(consumer_mess) {
	  write(lw(consumer_mess + "\n"));
          say(TP->NAME+" "+consuming_mess+"\n");
	}
	else {
	  write("You tap from " + short() + ".\n");
	  say(TP->NAME + " taps from " + short() + ".\n");
	}
      }
      else {
	write(lw("You tap from " + short() + ", but you are too drunk and " +
		 "spill the contents out onto the ground.\n"));
	say(lw(TP->NAME + " taps from " + short() + ", but is too drunk " +
	       "and spills the contents out onto the ground.\n"));
      }
      taps--;
      return 1;
   }
    write("There is nothing left in the keg.\n");
    return 1;
  }
}

set_name(arg) { name = arg; }
set_short(arg) { short = arg; }
set_long(arg) { long = arg; }
set_alias(arg) { alias = arg; }
set_alt_name(arg) { alt_name = arg; }
set_weight(arg) { weight = arg; }
set_value(arg) { value = arg; }
set_strength(arg) { strength = arg; }
set_consuming_mess(arg) { consuming_mess = arg; }
set_consumer_mess(arg) { consumer_mess = arg; }
set_taps(arg) {
  maxtaps = arg;
  taps = arg;
}

query_name() { return name; }
query_weight() { return weight; }
query_value() { return (20 + (value * taps) / maxtaps); }
query_strength() { return strength; }
query_taps() { return taps; }
query_keg() { return 1; }
