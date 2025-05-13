inherit "/players/qclxxiv/leaf3/q_alco";

reset(arg) {
  ::reset(arg);
  name="corn";
  alias="wine";
  alt_name = "corn wine";
  short_desc="A glass of corn wine";
  long_desc=
	"A glass of corn wine. A crystal-clear liquid smelling very strong.\n";
  drinker_mess ="Pfew...you throw the heavy drink down your throat and jump.\n";
  drinking_mess = " jumps after throwing down the corn wine in one gulp.\n";
  strength=23;
  value = 150;
  empty_container = "glass";
}
