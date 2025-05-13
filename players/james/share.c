string sizes;         /* sizes of armours */
string types;
int max_ac;
string numbers;

reset(arg) {
  if(arg) return;
  sizes = ({ "any", "tiny", "small", "medium", "large", "x-large" });
  types = ({ "other", "robe", "cloak", "ring", "helmet", "amulet",
    "armour", "arm", "glove", "shield", "leg", "boot", "guild" });
  max_ac = ({ 2, 1, 1, 2, 2, 2, 6, 2, 2, 2, 2, 2, 30 });
  numbers = ({ "no", "one", "two", "three", "four", "five", "six",
               "seven", "eight", "nine" });
}

share_armour_sizes() { return sizes; }
share_armour_types() { return types; }
share_armour_max_ac() { return max_ac; }
share_room_numbers() { return numbers; }
