id(str) {
	return	str == "sign";
	}

short() {
return "A red-gold-green sign with important ganja quest hints";
	}

long() {
write("Lee has moved. You better find him soon - Rasta.\n");
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
