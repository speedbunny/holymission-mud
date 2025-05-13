inherit "obj/thing";

int count,durability;

reset(arg) {
  ::reset(arg);
  if(!arg) {
    set_name("flint and iron");
    set_alias("flint");
    set_alt_name("iron");
    set_weight(1);
    set_value(10);
    set_short("A flint and iron");
    set_long("This is a flint and iron, and can be used to light torches. They won't\n"
           + "last forever, but could be very useful.\n");
  }
}

id(str) {
  if(str=="lighted_torch") {
    if(value--<1) {
      write("The flint crumbles to dust.\n");
      destruct(this_object());
      return 0;
    }
    return 1;
  }
  return ::id(str);
}

out() {
  write("The iron of the flint rusts away!\n");
  destruct(this_object());
}
