
inherit "obj/alco_drink";

reset(arg) {
  ::reset(arg);
  name="coffee";
  alias="cup";
  short_desc="A cup of coffee";
  long_desc="A nice cup of coffee, you can drink it.\n";
  drinker_mess = "Wow....that tastes great, there is some alcohol mixed in it....\n";
  strength=2;
}
