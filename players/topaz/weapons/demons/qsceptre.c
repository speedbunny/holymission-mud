inherit "obj/weapon";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("The Demon Queen's Sceptre");
  set_short("The Demon Queen's Sceptre");
  set_long("This sceptre is beautiful!  There are jewels inlaid all along\n" +
           "its elegantly carved handle.  It is rather heavy and seems\n" +
           "like it would be a good weapon.\n");
  set_alias("sceptre");
  set_alt_name("demon queen's sceptre");
  set_class(19);
  set_value(3500);
  set_weight(5);
}
