/* Uglymouth 940117: Put 'ring' to right (2nd) position in arm_types.
      One could wear only one ring, but 8 robes, instead of v.v. */
/* Matt JUN-25-94: Changed "boot" to "boots" as legal type due to
   incompatibility with existing items. */
/* Matt JUN-26-94: Added "boot" as well since some items use each */

string sizes;         /* sizes of armours */
string types;
int max_ac;
string numbers;

reset(arg) {
  if(arg) return;
  sizes = ({ "any", "tiny", "small", "medium", "large", "x-large" });
  types = ({ "other", "ring", "cloak", "robe", "helmet", "amulet",
    "armour", "arm", "glove", "shield", "leg", "boot", "guild",
    "glasses","neck","ear","belt","bracelet"});
  max_ac = ({ 3, 2, 2, 2, 3, 2, 8, 3, 2, 6, 3, 3, 15, 2, 2, 2, 2, 2 });
  numbers = ({ "no", "one", "two", "three", "four", "five", "six",
               "seven", "eight", "nine" });
}

share_armour_sizes() { return sizes; }
share_armour_types() { return types; }
share_armour_max_ac() { return max_ac; }
share_room_numbers() { return numbers; }
