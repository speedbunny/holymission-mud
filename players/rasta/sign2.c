id(str) {
	return	str == "sign";
	}

short() {
return "A wooden sign with a map of Trench Town";
	}

long() {
write("The map of Trench Town is mostly white space in the\n"
    + "middle, denoting the dense mountain jungle and steep\n"
    + "limestone terrain of the interior of the parish.\n"
    + "Rasta's country is off the narrow lane that cuts\n"
    + "through the hills between the woods of Alexandria and\n"
    + "the Rocks of Claremont, 2 miles to the east. At\n"
    + "Alexandria, you turn east and toward Alvia and start\n"
    + "searching for the tiny settlements on dirt roads\n"
    + "where Rasta wandered as a barefoot little boy driving\n"
    + "his grandfather's goats before him. If you come to the\n"
    + "village of Albion, you've gone too far. Turn back and\n"
    + "start looking again. Most likey, anyone along the road\n"
    + "will be happy to tell you where you want to go.\n"

	}

reset(arg) {
  if (arg) return 1;
  return 1;
}

init() {
	add_action("read_sign", "read");
}

read_sign(str) {
	if (!id(str)) return 0;

	long();
	return 1;
}
