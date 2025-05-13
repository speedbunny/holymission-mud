inherit "obj/container";

reset(arg) {

  ::reset(arg);
  if (arg) return;
    set_name("rucksack");
    set_alias("sack");
    set_max_weight(30);
    set_short("A rucksack");
    set_long("A nice little bag, with two belts to carry it over your back.\n")
;
    set_value(75);
    set_weight(1);
}
int no_clear()
{
    return 1;
}
