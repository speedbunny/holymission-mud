inherit "obj/keg";

reset(arg) {
  ::reset(arg);
	set_name("guinness");
	set_alias("keg");
	set_alt_name("keg of guinness");
	set_short("A keg of guinness");
	set_long(
"A keg of Guinness. It's the 8 % vol. special export version.\n" );
  set_strength(8);
  set_taps(12);
  set_value(384);
}
