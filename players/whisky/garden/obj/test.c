inherit "obj/weapon";

reset(arg) {
if (arg) return;
  set_id("teeth");
  set_alias("wolf teeth");
  set_short("A wolf teeth");
  set_long("The weapon from the dangerous wolf.\n");
  set_class(10);
  set_weight(1);
  set_value(200);
 }
void set_class(int class)
{
  class_of_weapon = 60;
}
destruct() { tell_room(environment(environment()),"Ohh Ohhh NO.\n"); return 1; }
